#include <stdio.h>
#include "tarefas.h"
#include <string.h>

int criar(Tarefa tarefas[], int *pos){
  if(*pos >= TOTAL)
    return 1;

  printf("Entre com a prioridade: ");
  scanf("%d", &tarefas[*pos].prioridade);
  clearBuffer();
  printf("Entre com a categoria: ");
  fgets(tarefas[*pos].categoria, 100, stdin);
  printf("Entre com a descrição: ");
  fgets(tarefas[*pos].descricao, 300, stdin);
  

  *pos += 1;

  return 0;
}

int deletar(Tarefa tarefas[], int *pos){
  
  return 0;
}

int listar(Tarefa tarefas[], int pos){
  if(pos == 0)
    return 1;
  
  for (int i=0; i<pos; i++){
    printf("Pos: %d\t", i+1);
    printf("Prioridade: %d\t", tarefas[i].prioridade);
    printf("Categoia: %s\t", tarefas[i].categoria);
    printf("Descricao: %s\n", tarefas[i].descricao);
  }

  return 0;
}

int salvar(Tarefa tarefas[], int total, int pos){
  FILE *f = fopen("tarefas", "wb");
  if (f == NULL)
    return 1;

  int e = fwrite(tarefas, total, sizeof(Tarefa), f);
  if (e <= 0)
    return 2;

  e = fwrite(&pos, 1, sizeof(int), f);
  if (e <=0)
    return 2;

  e = fclose(f);
  if (e != 0)
    return 3;
  
  return 0;
}

int carregar(Tarefa tarefas[], int total, int *pos){
  FILE *f = fopen("tarefas", "rb");
  if(f == NULL)
    return 1;

  int e = fread(tarefas, total, sizeof(Tarefa), f);
  if(e <= 0)
    return 2;

  e = fread(pos, 1, sizeof(int), f);
  if(e <= 0)
    return 2;

  e = fclose(f);
  if(e != 0)
    return 3;

  return 0;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}