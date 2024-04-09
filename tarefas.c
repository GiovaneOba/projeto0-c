#include <stdio.h>
#include "tarefas.h"
#include <string.h>

Erro criar(Tarefa tarefas[], int *pos){
  if(*pos >= TOTAL)
    return MAX_TAREFAS;
  do{
  printf("Entre com a prioridade (1 até 10): ");
  scanf("%d", &tarefas[*pos].prioridade);
  clearBuffer();
  printf("Entre com a categoria: ");
  fgets(tarefas[*pos].categoria, 100, stdin);
  tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = '\0';
  printf("Entre com a descrição: ");
  fgets(tarefas[*pos].descricao, 300, stdin);
  tarefas[*pos].descricao[strcspn(tarefas[*pos].descricao, "\n")] = '\0';
  

  *pos += 1;
  }while(tarefas[*pos].prioridade > 10 && tarefas[*pos].prioridade < 1);

  return OK;
}

Erro deletar(Tarefa tarefas[], int *pos){
  if(*pos == 0)
    return SEM_TAREFAS;

  int pos_d;
  printf("Entre com a posição da tarefa: ");
  scanf("%d", &pos_d);
  pos_d--;
  
  if(pos_d >= *pos){
    return NAO_EXISTE;
  }
  
  for (int i = pos_d; i < *pos; i++){
    tarefas[i].prioridade = tarefas[i + 1].prioridade;
    strcpy(tarefas[i].categoria, tarefas[i + 1].categoria);
    strcpy(tarefas[i].descricao, tarefas[i + 1].descricao);
  }

  *pos -= 1;

  return OK;
}

Erro listar(Tarefa tarefas[], int pos){
  if(pos == 0)
    return SEM_TAREFAS;
  
  for (int i=0; i<pos; i++){
    printf("Pos: %d\t", i+1);
    printf("Prioridade: %d\t", tarefas[i].prioridade);
    printf("Categoia: %s\t", tarefas[i].categoria);
    printf("Descricao: %s\n", tarefas[i].descricao);
  }

  return OK;
}

Erro salvar(Tarefa tarefas[], int total, int pos){
  FILE *f = fopen("tarefas", "wb");
  if (f == NULL)
    return NAO_ABRIU;

  int e = fwrite(tarefas, total, sizeof(Tarefa), f);
  if (e <= 0)
    return NAO_ESCREVEU;

  e = fwrite(&pos, 1, sizeof(int), f);
  if (e <=0)
    return NAO_ESCREVEU;

  e = fclose(f);
  if (e != 0)
    return NAO_FECHOU;
  
  return OK;
}

Erro carregar(Tarefa tarefas[], int total, int *pos){
  FILE *f = fopen("tarefas", "rb");
  if(f == NULL)
    return NAO_ABRIU;

  int e = fread(tarefas, total, sizeof(Tarefa), f);
  if(e <= 0)
    return NAO_LEU;

  e = fread(pos, 1, sizeof(int), f);
  if(e <= 0)
    return NAO_LEU;

  e = fclose(f);
  if(e != 0)
    return NAO_FECHOU;

  return OK;
}

void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF) {
  }
}