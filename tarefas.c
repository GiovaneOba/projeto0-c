#include <stdio.h>
#include <string.h>
#include "tarefas.h"

ERROS criar(Tarefa tarefas[], int *pos){
    if(*pos >= TOTAL)
        return MAX_TAREFA;

    printf("Entre com a prioridade (entre 1 e 10): ");
    scanf("%d", &tarefas[*pos].prioridade);
    clearBuffer();
    if(tarefas[*pos].prioridade < 1 || tarefas[*pos].prioridade > 10)
        return PRIORIDADE_INVALIDA;

    printf("Entre com a categoria: ");
    fgets(tarefas[*pos].categoria, TAMANHO_CATEGORIA, stdin);
    tarefas[*pos].categoria[strcspn(tarefas[*pos].categoria, "\n")] = '\0';
    printf("Entre com a descricao: ");
    fgets(tarefas[*pos].descricao, TAMANHO_DESCRICAO, stdin);
    tarefas[*pos].descricao[strcspn(tarefas[*pos].descricao, "\n")] = '\0'; 
    
    *pos = *pos + 1;

    return OK;
}

ERROS deletar(Tarefa tarefas[], int *pos){
    if(*pos == 0)
        return SEM_TAREFAS;

    int pos_deletar;
    printf("Entre com a posicao da tarefa a ser deletada: ");
    scanf("%d", &pos_deletar);

    pos_deletar--; 

    if(pos_deletar >= *pos || pos_deletar < 0)
        return NAO_ENCONTRADO;

    for(int i = pos_deletar; i < *pos; i++){
        tarefas[i].prioridade = tarefas[i+1].prioridade;
        strcpy(tarefas[i].categoria, tarefas[i+1].categoria);
        strcpy(tarefas[i].descricao,  tarefas[i+1].descricao);
    }
  
    *pos = *pos - 1;

    return OK;
}

ERROS listar(Tarefa tarefas[], int *pos){
    char categoria[TAMANHO_CATEGORIA];
    clearBuffer();
    printf("Entre com a categoria (deixe em branco para listar todas): ");
    fgets(categoria, TAMANHO_CATEGORIA, stdin);
    categoria[strcspn(categoria, "\n")] = '\0'; 

    if(*pos == 0)
        return SEM_TAREFAS;

    int encontradas = 0;
    for(int i = 0; i < *pos; i++){
        if(categoria[0] == '\0' || strcmp(tarefas[i].categoria, categoria) == 0){
            printf("Pos: %d\t", i+1);
            printf("Prioridade: %d\t", tarefas[i].prioridade);
            printf("Categoria: %s\t", tarefas[i].categoria);
            printf("Descricao: %s\n", tarefas[i].descricao);
            encontradas++;
        }
    }

    if(encontradas == 0){
        if(categoria[0] != '\0')
            printf("Nenhuma tarefa encontrada para a categoria '%s'\n", categoria);
        else
            printf("Nenhuma tarefa cadastrada\n");

    }

    return OK;
}

ERROS exportar(Tarefa tarefas[], int *pos) {
    char nome_arquivo_texto[50];
    FILE *arquivo_binario;
    FILE *arquivo_texto;

    arquivo_binario = fopen("tarefas", "rb");
    if (arquivo_binario == NULL)
        return ABRIR;

    clearBuffer();
    printf("Digite o nome do arquivo de texto de saída: ");
    fgets(nome_arquivo_texto, 50, stdin);
    nome_arquivo_texto[strcspn(nome_arquivo_texto, "\n")] = '\0';

    arquivo_texto = fopen(nome_arquivo_texto, "w");
    if (arquivo_texto == NULL) {
        fclose(arquivo_binario);
        return ABRIR;
    }


    for (int i = 0; i < *pos; i++) {
        fread(&tarefas[i], sizeof(Tarefa), 1, arquivo_binario);
        fprintf(arquivo_texto, "Prioridade: %d, Categoria: %s, Descricao: %s\n", tarefas[i].prioridade, tarefas[i].categoria, tarefas[i].descricao);
    }

    fclose(arquivo_binario);
    fclose(arquivo_texto);

    return OK;
}

ERROS salvar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas", "wb");
    if(f == NULL)
        return ABRIR;

    int qtd = fwrite(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return ESCREVER;

    qtd = fwrite(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return ESCREVER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

ERROS carregar(Tarefa tarefas[], int *pos){
    FILE *f = fopen("tarefas", "rb");

    if(f == NULL)
        return ABRIR;

    int qtd = fread(tarefas, TOTAL, sizeof(Tarefa), f);
    if(qtd == 0)
        return LER;

    qtd = fread(pos, 1, sizeof(int), f);
    if(qtd == 0)
        return LER;

    if(fclose(f))
        return FECHAR;

    return OK;
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
