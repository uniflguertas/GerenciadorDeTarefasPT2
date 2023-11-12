#include <stdio.h>
#include "proj.h"

// Função para cadastro de novas tarefas:
void cadastrarTarefa(Tarefa tarefas[], int *numTarefas) {
    if (*numTarefas < 100) {
        Tarefa novaTarefa;
        printf("======================================================\n");
        printf("\nCadastrar Nova Tarefa:\n");

     // Prioridade
        printf("\nPrioridade (0 a 10): ");
        scanf("%d", &novaTarefa.prioridade);
        if (novaTarefa.prioridade < 0) {
            novaTarefa.prioridade = 0;
            printf("(Prioridade menor que 0: A prioridade será automaticamente definida para a menor possível)\n");
        } else if (novaTarefa.prioridade > 10) {
            novaTarefa.prioridade = 10;
            printf("(Prioridade maior que 10: A prioridade será automaticamente definida para a maior possível)\n");
        }
     // Descrição
        printf("Descricao (ate 300 letras): ");
        scanf(" %s[^\n]", novaTarefa.descricao);
     // Categoria
        printf("Categoria (ate 100 letras): ");
        scanf(" %s[^\n]", novaTarefa.categoria);
     // Estado
        printf("Estado (Digite apenas o algarismo): \n 1. nao iniciado, 2. em andamento, 3. completo: ");
        scanf("%d[^\n]", &novaTarefa.estado);

        tarefas[*numTarefas] = novaTarefa;
        (*numTarefas)++;

        printf("\nTarefa cadastrada com sucesso!");
        printf("\n======================================================\n");
    } else {
        printf("O limite de tarefas atingido. Não eh possível cadastrar mais tarefas.\n");
    }
}

// Função de listagem das tarefas cadastradas:
void listarTarefas(Tarefa tarefa[], int numTarefas) {
    char realizarFiltragem[2];
    int opcaoFiltro, prioridadeFiltro, estadoFiltro;
    char categoriaFiltro[100];
 // Se número de tarefas cadastradas > 0, mostrar lista.
    if (numTarefas > 0) {
        printf("======================================================\n");
        printf("Lista de Tarefas:\n");
        printf("======================================================\n");
     // Formato de amostragem das tarefas.
        for (int i = 0; i < numTarefas; i++) {
            printf("\nTarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefa[i].prioridade);
            printf("Descricao: %s\n", tarefa[i].descricao);
            printf("Categoria: %s\n", tarefa[i].categoria);
            if(tarefa[i].estado == 1){
                printf("Estado: nao iniciada\n");
            }
            else if(tarefa[i].estado == 2){
                printf("Estado: em andamento\n");
            }
            else if(tarefa[i].estado == 3){
                printf("Estado: completa\n");
            }
            printf("\n======================================================\n");
        }

        printf("\nFiltrar listagem? (s/n): ");
        scanf("%s", realizarFiltragem);

        if(strcmp("s", realizarFiltragem) == 0){
            printf("\nTipo de filtragem (digite apenas o algarismo respectivo):\n");
            printf("1. Filtrar por prioridade\n");
            printf("2. Filtrar por estado\n");
            printf("3. Filtrar por categoria\n");
            printf("4. Filtrar por prioridade e categoria\n");
            printf("Digite aqui: ");
            scanf("%d", &opcaoFiltro);

            if(opcaoFiltro == 1){
                printf("\nDigite a prioridade desejada: ");
                scanf("%d", &prioridadeFiltro);
                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                for (int i = 0; i < numTarefas; i++) {
                    if(tarefa[i].prioridade == prioridadeFiltro) {
                        printf("\nTarefa %d:\n", i + 1);
                        printf("Prioridade: %d\n", tarefa[i].prioridade);
                        printf("Descricao: %s\n", tarefa[i].descricao);
                        printf("Categoria: %s\n", tarefa[i].categoria);
                        if(tarefa[i].estado == 1){
                            printf("Estado: nao iniciada\n");
                        }
                        else if(tarefa[i].estado == 2){
                            printf("Estado: em andamento\n");
                        }
                        else if(tarefa[i].estado == 3){
                            printf("Estado: completa\n");
                        }
                        printf("\n======================================================\n");
                    }
                }
            }

            else if(opcaoFiltro == 2){
                printf("\nDigite o estado desejado: ");
                scanf("%d", &estadoFiltro);
                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                for (int i = 0; i < numTarefas; i++) {
                    if(tarefa[i].estado == estadoFiltro) {
                        printf("\nTarefa %d:\n", i + 1);
                        printf("Prioridade: %d\n", tarefa[i].prioridade);
                        printf("Descricao: %s\n", tarefa[i].descricao);
                        printf("Categoria: %s\n", tarefa[i].categoria);
                        if(tarefa[i].estado == 1){
                            printf("Estado: nao iniciada\n");
                        }
                        else if(tarefa[i].estado == 2){
                            printf("Estado: em andamento\n");
                        }
                        else if(tarefa[i].estado == 3){
                            printf("Estado: completa\n");
                        }
                        printf("\n======================================================\n");
                    }
                }
            }

            else if(opcaoFiltro == 3){
                printf("\nDigite a categoria desejada: ");
                scanf("%s", categoriaFiltro);
                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                for (int i = 0; i < numTarefas; i++) {
                    if(strcmp(tarefa[i].categoria, categoriaFiltro) == 0) {
                        printf("\nTarefa %d:\n", i + 1);
                        printf("Prioridade: %d\n", tarefa[i].prioridade);
                        printf("Descricao: %s\n", tarefa[i].descricao);
                        printf("Categoria: %s\n", tarefa[i].categoria);
                        if(tarefa[i].estado == 1){
                            printf("Estado: nao iniciada\n");
                        }
                        else if(tarefa[i].estado == 2){
                            printf("Estado: em andamento\n");
                        }
                        else if(tarefa[i].estado == 3){
                            printf("Estado: completa\n");
                        }
                        printf("\n======================================================\n");
                    }
                }
            }
            else if(opcaoFiltro == 4){
                printf("\nDigite a prioridade desejada: ");
                scanf("%d", &prioridadeFiltro);
                printf("\nDigite categoria desejada: ");
                scanf("%s", categoriaFiltro);
                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                for (int i = 0; i < numTarefas; i++) {
                    if (tarefa[i].prioridade == prioridadeFiltro && strcmp(tarefa[i].categoria, categoriaFiltro) == 0) {
                        printf("\nTarefa %d:\n", i + 1);
                        printf("Prioridade: %d\n", tarefa[i].prioridade);
                        printf("Descricao: %s\n", tarefa[i].descricao);
                        printf("Categoria: %s\n", tarefa[i].categoria);
                        if(tarefa[i].estado == 1){
                            printf("Estado: nao iniciada\n");
                        }
                        else if(tarefa[i].estado == 2){
                            printf("Estado: em andamento\n");
                        }
                        else if(tarefa[i].estado == 3){
                            printf("Estado: completa\n");
                        }
                        printf("\n======================================================\n");
                    }
                }
            }
        }

        else if(strcmp("n", realizarFiltragem) == 0){
            printf("\n======================================================\n");
        }
    }
 // Se não ouver tarefas cadastradas, retornar mensagem.
    else {
        printf("\n======================================================\n");
        printf("Nenhuma tarefa cadastrada.");
        printf("\n======================================================\n");

    }
}

// Função para deleção de tarefas existentes:
void deletarTarefa(Tarefa tarefas[], int *numTarefas) {
 // Se o número de tarefas cadastradas > 0, executar a deleção.
    if (*numTarefas > 0) {
     // Variável "número" para distinguir as tarefas cadastradas
        int numero;
        printf("======================================================\n");
     // Pede o número associado a tarefa desejada para deleção.
        printf("\nDigite o número da tarefa a ser deletada: ");
        scanf("%d", &numero);
     // Se "número" >= 1 e "número" <= endereço de numTarefas, atribuir nova numeração a respectiva tarefa de acordo com a ocorrência de deleções.
        if (numero >= 1 && numero <= *numTarefas) {
            for (int i = numero - 1; i < *numTarefas - 1; i++) {
                tarefas[i] = tarefas[i + 1];
            }
         // Deleta tarefa em seu respectivo endereço atribuído.
            (*numTarefas)--;
            printf("\nTarefa deletada com sucesso!\n");
            printf("============================\n");
        }
     // Se o número da tarefa desejada para deleção for inválido, retorna erro.
        else {
            printf("Erro: Número inválido. Tarefa não encontrada.\n");
        }
    }
    // Se não houver nenhuma tarefa para deleção, retorna mensagem.
    else {
        printf("\nNenhuma tarefa cadastrada para deletar!\n");
        printf("=========================================\n");

    }
}

void alterarTarefa(Tarefa tarefas[], int numTarefas) {
    int numero, opcao;
    printf("======================================================\n");
    printf("\nEditar tarefa existente:\n");
    printf("\nDigite o numero da tarefa a ser alterada: ");
    scanf("%d", &numero);

    if (numero < 1 || numero > numTarefas) {
        printf("\nErro: Numero invalido. Tarefa nao encontrada.\n");
        printf("\n======================================================\n");
        return;
    }

    Tarefa *tarefa = &tarefas[numero - 1];
    printf("\nEscolha o campo a ser alterado:\n");
    printf("1. Prioridade\n2. Descricao\n3. Categoria\n4. Estado\n");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            printf("Nova Prioridade: ");
            scanf("%d", &tarefa->prioridade);
            break;
        case 2:
            printf("Nova Descricao: ");
            scanf(" %[^\n]s", tarefa->descricao);
            break;
        case 3:
            printf("Nova Categoria: ");
            scanf(" %[^\n]s", tarefa->categoria);
            break;
        case 4:
            printf("Novo Estado (Digite apenas o algarismo): \n 1. nao iniciado, 2. em andamento, 3. completo: ");
            scanf("%d", (int *)&tarefa->estado);
            break;
        default:
            printf("Erro: Numero invalido. Campo da tarefa nao encontrado.\n");
    }
}
