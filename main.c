// git pull origin 1-menu-principal
// git push origin 1-menu-principal
// git fetch origin
// git checkout 1-menu-principal
// #include <stdio.h>
// #include "tarefas.h"

// int main(){
//     funcao fs[] = {criar, deletar, listar, exportar, salvar, carregar};

//     Tarefa tarefas[TOTAL];
//     int pos;
//     ERROS erro = fs[5](tarefas, &pos);
//     if(erro != OK){
//         printf("Erro ao carregar as tarefas: %d\n", erro);
//         return 1; 
//     } else {
//         printf("Tarefas carregadas com sucesso!\n");
//     }

//     int opcao;
//     do{
//         printf("\nMenu principal\n");
//         printf("1 - Criar tarefa\n");
//         printf("2 - Deletar tarefa\n");
//         printf("3 - Listar tarefas\n");
//         printf("4 - Exportar tarefas para arquivo de texto\n");
//         printf("5 - Salvar tarefas em arquivo binario\n");
//         printf("6 - Carregar tarefas de arquivo binario\n");
//         printf("0 - Sair\n");
//         printf("Escolha uma opcao: ");

//         scanf("%d", &opcao);
//         opcao--;
//         if(opcao > 5)
//             printf("Opcao invalida\n");
//         else if(opcao >= 0) {
//             ERROS erro = fs[opcao](tarefas, &pos);
//             if(erro == MAX_TAREFA){
//                 printf("Erro ao executar a operacao: MAX_TAREFA - %d\n", erro);
//             }
//             else if (erro == SEM_TAREFAS){
//                 printf("Erro ao executar a operacao: SEM_TAREFAS - %d\n", erro);
//             }
//             else if (erro == NAO_ENCONTRADO){
//                 printf("Erro ao executar a operacao: NAO_ENCONTRADO - %d\n", erro);
//             }
//             else if (erro == ABRIR){
//                 printf("Erro ao executar a operacao: ABRIR - %d\n", erro);
//             }
//             else if (erro == FECHAR){
//                 printf("Erro ao executar a operacao: FECHAR - %d\n", erro);
//             }
//             else if (erro == ESCREVER){
//                 printf("Erro ao executar a operacao: ESCREVER - %d\n", erro);
//             }
//             else if (erro == LER){
//                 printf("Erro ao executar a operacao: LER - %d\n", erro);
//             }
//             else if (erro == PRIORIDADE_INVALIDA){
//                 printf("Erro ao executar a operacao: PRIORIDADE_INVALIDA - %d\n", erro);
//             }
//         }
//         else
//             printf("Sair...\n");

//     } while(opcao >= 0);

//     ERROS erroSalvar = fs[4](tarefas, &pos);
//     if(erroSalvar != OK){
//         printf("Erro ao salvar as tarefas: %d\n", erroSalvar);
//         return 1; 
//     } else {
//         printf("Tarefas salvas com sucesso!\n");
//     }

//     return 0; 
// }

#include <stdio.h>
#include "tarefas.h"

int main(){
    funcao fs[] = {criar, deletar, listar, exportar, salvar, carregar};

    Tarefa tarefas[TOTAL];
    int pos;
    // ERROS erro = carregar(tarefas, &pos); 
    // if(erro != OK)
    //     pos = 0;

    int opcao;
    do{
        printf("\nMenu principal\n");
        printf("1 - Criar tarefa\n");
        printf("2 - Deletar tarefa\n");
        printf("3 - Listar tarefas\n");
        printf("4 - Exportar tarefas para arquivo de texto\n");
        printf("5 - Salvar tarefas em arquivo binario\n");
        printf("6 - Carregar tarefas de arquivo binario\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &opcao);
        opcao--;
        if(opcao > 5)
            printf("Opcao invalida\n");
        else if(opcao >= 0) {
            ERROS erro = fs[opcao](tarefas, &pos);
            if(erro == MAX_TAREFA){
                printf("Erro ao executar a operacao: MAX_TAREFA - %d\n", erro);
            }
            else if (erro == SEM_TAREFAS){
                printf("Erro ao executar a operacao: SEM_TAREFAS - %d\n", erro);
            }
            else if (erro == NAO_ENCONTRADO){
                printf("Erro ao executar a operacao: NAO_ENCONTRADO - %d\n", erro);
            }
            else if (erro == ABRIR){
                printf("Erro ao executar a operacao: ABRIR - %d\n", erro);
            }
            else if (erro == FECHAR){
                printf("Erro ao executar a operacao: FECHAR - %d\n", erro);
            }
            else if (erro == ESCREVER){
                printf("Erro ao executar a operacao: ESCREVER - %d\n", erro);
            }
            else if (erro == LER){
                printf("Erro ao executar a operacao: LER - %d\n", erro);
            }
            else if (erro == PRIORIDADE_INVALIDA){
                printf("Erro ao executar a operacao: PRIORIDADE_INVALIDA - %d\n", erro);
            }
        }
        // else if (opcao == 5) 
        //     ERROS erro = fs[opcao](tarefas, &pos);
        // else if (opcao == 6) 
        //     ERROS erro = fs[opcao](tarefas, &pos);
        else
            printf("Sair...\n");

    } while(opcao >= 0);

    return 0;
}