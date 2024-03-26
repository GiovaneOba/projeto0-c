// git pull origin 1-menu-principal
// git push origin 1-menu-principal
// git fetch origin
// git checkout 1-menu-principal
#include "tarefas.h"
#include <stdio.h>

int main() {
  int pos = 0;
  Tarefa tarefas[TOTAL];

  Erro e = carregar(tarefas, TOTAL, &pos);
  if(e == ABRIR){
    pos = 0;
  }
else if(e == FECHAR){
  printf("Erro ");
}

  int opcao;
  do {
    printf("======================\n");
    printf("Menu Principal\n");
    printf("======================\n");
    printf("1 - Criar Tarefa\n");
    printf("2 - Deletar Tarefas\n");
    printf("3 - Listar Tarefas\n");
    printf("0 - Sair\n");
    printf("Entre com uma opção: \n");
    int i = scanf("%d", &opcao);
    printf("Opção escolhida: %d\n", opcao);
    printf("======================\n");

    if (opcao == 1) {
      e = criar(tarefas, &pos);
      if(e == MAX_TAREFAS)
        printf("Maximo de tarefas alcancadas\n");
    } else if (opcao == 2) {
      e = deletar(tarefas, &pos);
      if(e == SEM_TAREFAS)
        printf("Sem tarefas para deletar\n");
      else if(e == NAO_EXISTE)
        printf("Tarefa não existe\n");
    } else if (opcao == 3) {
      e = listar(tarefas, pos);
      if(e == SEM_TAREFAS)
        printf("Sem tarefas para listar\n");
    } else if (opcao == 0) {
      printf("Sair...\n");
      e = salvar(tarefas, TOTAL , pos);
      if(e == NAO_ABRIU)
        printf("Erro ao abrir o arquivo\n");
      else if(e == NAO_FECHOU)
        printf("Erro ao fechar o arquivo\n");
      else if(e == NAO_ESCREVEU)
        printf("Erro ao escrever no arquivo\n");
    } else {
      printf("Opção inválida\n");
    }

  } while (opcao != 0);
}