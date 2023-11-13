#include <stdio.h>
#include "proj.h"
#include "string.h"
#include "search.h"

// Função para salvar tarefas em um arquivo binário.
void salvarTarefas(Tarefa tarefas[], int numTarefas) {
    FILE *file = fopen("tarefas.bin", "wb");  // Abre o arquivo tarefas.bin em modo de escrita binária.
    if (file) {
        fwrite(tarefas, sizeof(Tarefa), numTarefas, file); // Escreve as tarefas no arquivo.
        fclose(file); // Fecha o arquivo.
    } else {
        printf("Erro ao salvar tarefa. Tente novamente ou reinicie o programa.\n"); // Mensagem de erro se o arquivo não puder ser aberto.
    }
}

// Função para cadastrar uma nova tarefa.
void cadastrarTarefa(Tarefa tarefas[], int *numTarefas) {
    if (*numTarefas < 100) { // Verifica se o número de tarefas é menor que 100.
        Tarefa novaTarefa;
     // Solicita informações sobre a tarefa.
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

        tarefas[*numTarefas] = novaTarefa; // Adiciona a nova tarefa ao array.
        (*numTarefas)++; // Incrementa o contador de tarefas.


        printf("\nTarefa cadastrada com sucesso!");
        printf("\n======================================================\n");
    } else {
     // Mensagem de erro se o limite de tarefas for atingido.
        printf("O limite de tarefas atingido. Não eh possível cadastrar mais tarefas.\n");
    }
}

// Função para comparar prioridades de tarefas (usada em qsort).
int compararPrioridade(const void *a, const void *b) {
    Tarefa *tarefaA = (Tarefa *)a;
    Tarefa *tarefaB = (Tarefa *)b;
    return tarefaB->prioridade - tarefaA->prioridade; // Ordem decrescente.
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

            else if(opcaoFiltro == 3) {
                printf("\nDigite a categoria desejada: ");
                scanf("%s", categoriaFiltro);

                Tarefa tarefasFiltradas[100]; // Ajuste o tamanho conforme necessário
                int contagemFiltrada = 0;

                for (int i = 0; i < numTarefas; i++) {
                    if (strcmp(tarefa[i].categoria, categoriaFiltro) == 0) {
                        tarefasFiltradas[contagemFiltrada++] = tarefa[i];
                    }
                }

                qsort(tarefasFiltradas, contagemFiltrada, sizeof(Tarefa), compararPrioridade);

                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                for (int i = 0; i < contagemFiltrada; i++) {
                    printf("\nTarefa %d:\n", i + 1);
                    printf("Prioridade: %d\n", tarefasFiltradas[i].prioridade);
                    printf("Descricao: %s\n", tarefasFiltradas[i].descricao);
                    printf("Categoria: %s\n", tarefasFiltradas[i].categoria);
                    if(tarefasFiltradas[i].estado == 1){
                        printf("Estado: nao iniciada\n");
                    }
                    else if(tarefasFiltradas[i].estado == 2){
                        printf("Estado: em andamento\n");
                    }
                    else if(tarefasFiltradas[i].estado == 3){
                        printf("Estado: completa\n");
                    }
                    printf("\n======================================================\n");
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
        printf("\nDigite o numero da tarefa a ser deletada: ");
        scanf("%d", &numero);
     // Se "número" >= 1 e "número" <= endereço de numTarefas, atribuir nova numeração a respectiva tarefa de acordo com a ocorrência de deleções.
        if (numero >= 1 && numero <= *numTarefas) {
            for (int i = numero - 1; i < *numTarefas - 1; i++) {
                tarefas[i] = tarefas[i + 1];
            }
         // Deleta tarefa em seu respectivo endereço atribuído.
            (*numTarefas)--;
            printf("\nTarefa deletada com sucesso!\n");
            printf("\n======================================================\n");
        }
     // Se o número da tarefa desejada para deleção for inválido, retorna erro.
        else {
            printf("Erro: Numero invalido. Tarefa nao encontrada.\n");
        }
    }
 // Se não houver nenhuma tarefa para deleção, retorna mensagem.
    else {
        printf("\nNenhuma tarefa cadastrada para deletar!\n");
        printf("\n======================================================\n");

    }
}

// Função para alterar uma tarefa existente.
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

    salvarTarefas(tarefas, numTarefas); // Salva as alterações no arquivo.
}

// Funções para exportar tarefas por prioridade, categoria ou ambas.
void exportarTarefasPorPrioridade(Tarefa tarefas[], int numTarefas, int prioridade) {
    FILE *file = fopen("tarefas_por_prioridade.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade) {
            fwrite(&tarefas[i], sizeof(Tarefa), 1, file);
        }
    }

    fclose(file);
}

void exportarTarefasPorCategoria(Tarefa tarefas[], int numTarefas, char *categoria) {
    FILE *file = fopen("tarefas_por_categoria.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        if (strcmp(tarefas[i].categoria, categoria) == 0) {
            fwrite(&tarefas[i], sizeof(Tarefa), 1, file);
        }
    }

    fclose(file);
}

void exportarTarefasPorPrioridadeCategoria(Tarefa tarefas[], int numTarefas, int prioridade, char *categoria) {
    FILE *file = fopen("tarefas_por_prioridade_categoria.bin", "wb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    for (int i = 0; i < numTarefas; i++) {
        if (tarefas[i].prioridade == prioridade && strcmp(tarefas[i].categoria, categoria) == 0) {
            fwrite(&tarefas[i], sizeof(Tarefa), 1, file);
        }
    }

    fclose(file);
}

// Função principal para exportar tarefas.
int exportarTarefas(Tarefa tarefas[], int numTarefas) {
    int escolha;
    int prioridade;
    char categoria[100];

    printf("======================================================\n");
    printf("\nExportar tarefas:\n");
    printf("\nSelecione como deseja exportar as tarefas: \n");
    printf("1. Por Prioridade\n");
    printf("2. Por Categoria\n");
    printf("3. Por Prioridade e Categoria\n");
    printf("\nDigite aqui: ");
    scanf("%d", &escolha);

    switch (escolha) {
        case 1:
            printf("Digite a prioridade desejada:");
            scanf("%d", &prioridade);
            exportarTarefasPorPrioridade(tarefas, numTarefas, prioridade);
            printf("==================================================\n");
            break;
        case 2:
            printf("Digite a categoria desejada:");
            scanf("%100s", categoria);
            categoria[strcspn(categoria, "\n")] = 0; // Remove o newline lido por fgets
            exportarTarefasPorCategoria(tarefas, numTarefas, categoria);
            printf("==================================================\n");
            break;
        case 3:
            printf("Digite a categoria desejada:");
            scanf("%100s", categoria);
            categoria[strcspn(categoria, "\n")] = 0;
            printf("Digite a Prioridade desejada:");
            scanf("%d", &prioridade);
            exportarTarefasPorPrioridadeCategoria(tarefas, numTarefas, prioridade, categoria);
            printf("==================================================\n");
            break;
        default:
            printf("\nErro: Numero invalido. Tarefa nao encontrada.\n");
            return 1;
    }

    return 0;
}
