// git pull origin 1-menu-principal
// git push origin 1-menu-principal
// git fetch origin
// git checkout 1-menu-principal
#include <stdio.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar, salvar, carregar};

    Tarefa tarefas[TOTAL];
    int pos;
    ERROS erro = fs[4](tarefas, &pos);
    if(erro != OK){
        printf("Erro ao carregar as tarefas: %d\n", erro);
        return 1;
    } else {
        printf("Tarefas carregadas com sucesso!\n");
    }

    int opcao;
    do{
        printf("\nMenu principal\n");
        printf("1 - Criar tarefa\n");
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        opcao--;
        if(opcao > 2)
            printf("Opcao invalida\n");
        else if(opcao >= 0) {
            ERROS erro = fs[opcao](tarefas, &pos);
            if(erro != OK){
                printf("Erro ao executar a operacao: %d\n", erro);
            }
        }
        else
            printf("Sair...\n");

    } while(opcao >= 0);

    ERROS erroSalvar = fs[3](tarefas, &pos);
    if(erroSalvar != OK){
        printf("Erro ao salvar as tarefas: %d\n", erroSalvar);
        return 1; 
    } else {
        printf("Tarefas salvas com sucesso!\n");
    }

    return 0;
}