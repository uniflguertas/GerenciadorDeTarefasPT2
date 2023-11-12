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
 // Se número de tarefas cadastradas > 0, mostrar lista.
    if (numTarefas > 0) {
        printf("======================================================\n");
        printf("\nLista de Tarefas:\n");
        printf("\n=================\n");
     // Formato de amostragem das tarefas.
        for (int i = 0; i < numTarefas; i++) {
            printf("\nTarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefa[i].prioridade);
            printf("Descrição: %s\n", tarefa[i].descricao);
            printf("Categoria: %s\n", tarefa[i].categoria);
            printf("\n");
        }
        printf("=================\n");
        printf("\n(Arraste para cima para vizualisar as tarefas cadastradas)\n");
        printf("==========================================================\n");
    }
 // Se não ouver tarefas cadastradas, retornar mensagem.
    else {
        printf("\n");
        printf("Nenhuma tarefa cadastrada.\n");
        printf("==========================\n");

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
