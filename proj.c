#include <stdio.h>
#include "proj.h"
#include "string.h"
#include "search.h"

void limpaBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
};

// Função para salvar tarefas em um arquivo binário.
void salvarTarefas(Tarefa tarefas[], int numTarefas) {
    // Abre "tarefas.bin" para escrita binária, 'file' é um ponteiro para o arquivo.
    FILE *file = fopen("tarefas.bin", "wb");

    // Verifica se o arquivo foi aberto com sucesso.
    if (file) {
        // Escreve o array 'tarefas' no arquivo, cada elemento do tamanho de 'Tarefa'.
        fwrite(tarefas, sizeof(Tarefa), numTarefas, file);

        // Fecha o arquivo, liberando recursos.
        fclose(file);
    } else {
        // Exibe mensagem de erro se o arquivo não puder ser aberto.
        printf("Erro ao salvar tarefa. Tente novamente ou reinicie o programa.\n");
    }
}

// Função para cadastrar uma nova tarefa.
void cadastrarTarefa(Tarefa tarefas[], int *numTarefas) {
    // Verifica se o número atual de tarefas é menor que 100.
    if (*numTarefas < 100) {
        Tarefa novaTarefa; // Cria uma nova variável do tipo Tarefa.

        // Exibe informações na tela para orientar o usuário no cadastramento da tarefa.
        printf("======================================================\n");
        printf("\nCadastrar Nova Tarefa:\n");

        // Solicita ao usuário a prioridade da tarefa e a armazena na variável novaTarefa.
        printf("\nPrioridade (0 a 10): ");
        scanf("%d", &novaTarefa.prioridade);
        limpaBuffer();
        // Verifica se a prioridade é menor que 0 e, se for, ajusta para 0, informando o usuário.
        if (novaTarefa.prioridade < 0) {
            novaTarefa.prioridade = 0;
            printf("(Prioridade menor que 0: A prioridade será automaticamente definida para a menor possível)\n");
        }
            // Verifica se a prioridade é maior que 10 e, se for, ajusta para 10, informando o usuário.
        else if (novaTarefa.prioridade > 10) {
            novaTarefa.prioridade = 10;
            printf("(Prioridade maior que 10: A prioridade será automaticamente definida para a maior possível)\n");
        }

        // Solicita ao usuário a descrição da tarefa e a armazena na variável novaTarefa.
        printf("Descricao (ate 300 letras): ");
        scanf(" %s[^\n]", novaTarefa.descricao);
        limpaBuffer();

        // Solicita ao usuário a categoria da tarefa e a armazena na variável novaTarefa.
        printf("Categoria (ate 100 letras): ");
        scanf(" %s[^\n]", novaTarefa.categoria);
        limpaBuffer();

        // Solicita ao usuário o estado da tarefa e o armazena na variável novaTarefa.
        printf("Estado (Digite apenas o algarismo): \n 1. nao iniciado, 2. em andamento, 3. completo: ");
        scanf("%d[^\n]", &novaTarefa.estado);
        limpaBuffer();

        // Adiciona a nova tarefa ao array de tarefas.
        tarefas[*numTarefas] = novaTarefa;

        // Incrementa o contador de tarefas.
        (*numTarefas)++;

        // Mensagem de confirmação do cadastramento da tarefa.
        printf("\nTarefa cadastrada com sucesso!");
        printf("\n======================================================\n");
    }
    else {
        // Mensagem de erro se o limite de tarefas for atingido.
        printf("O limite de tarefas atingido. Não eh possível cadastrar mais tarefas.\n");
    }
}

// Define uma função chamada compararPrioridade que recebe dois ponteiros genéricos.
int compararPrioridade(const void *a, const void *b) {
    // Converte o ponteiro genérico 'a' para um ponteiro do tipo Tarefa.
    Tarefa *tarefaA = (Tarefa *)a;
    // Converte o ponteiro genérico 'b' para um ponteiro do tipo Tarefa.
    Tarefa *tarefaB = (Tarefa *)b;
    // Retorna a diferença entre as prioridades, ordenando de forma decrescente.
    return tarefaB->prioridade - tarefaA->prioridade; // Ordem decrescente.
}

// Define a função listarTarefas, que recebe um array de Tarefas e um inteiro.
void listarTarefas(Tarefa tarefa[], int numTarefas) {
    // Declara variáveis para controle de filtragem.
    char realizarFiltragem[2];
    int opcaoFiltro, prioridadeFiltro, estadoFiltro;
    char categoriaFiltro[100];

    // Verifica se há tarefas para listar.
    if (numTarefas > 0) {
        // Imprime o cabeçalho da lista de tarefas.
        printf("======================================================\n");
        printf("Lista de Tarefas:\n");
        printf("======================================================\n");

        // Loop para exibir cada tarefa cadastrada.
        for (int i = 0; i < numTarefas; i++) {
            // Exibe detalhes de cada tarefa.
            printf("\nTarefa %d:\n", i + 1);
            printf("Prioridade: %d\n", tarefa[i].prioridade);
            printf("Descricao: %s\n", tarefa[i].descricao);
            printf("Categoria: %s\n", tarefa[i].categoria);
            // Condicional para exibir o estado da tarefa.
            if (tarefa[i].estado == 1) {
                printf("Estado: nao iniciada\n");
            } else if (tarefa[i].estado == 2) {
                printf("Estado: em andamento\n");
            } else if (tarefa[i].estado == 3) {
                printf("Estado: completa\n");
            }
            printf("\n======================================================\n");
        }

        // Pergunta ao usuário se deseja filtrar a listagem.
        printf("\nFiltrar listagem? (s/n): ");
        scanf("%s", realizarFiltragem);
        limpaBuffer();

        // Verifica se o usuário deseja aplicar um filtro.
        if (strcmp("s", realizarFiltragem) == 0) {
            // Apresenta opções de filtro ao usuário.
            printf("\nTipo de filtragem (digite apenas o algarismo respectivo):\n");
            // Mostra as opções de filtragem disponíveis.
            printf("1. Filtrar por prioridade\n");
            printf("2. Filtrar por estado\n");
            printf("3. Filtrar por categoria\n");
            printf("4. Filtrar por prioridade e categoria\n");
            printf("Digite aqui: ");
            scanf("%d", &opcaoFiltro);
            limpaBuffer();

            // Filtro por prioridade.
            if (opcaoFiltro == 1) {
                // Solicita a prioridade para o filtro.
                printf("\nDigite a prioridade desejada: ");
                scanf("%d", &prioridadeFiltro);
                limpaBuffer();

                // Cabeçalho para a listagem filtrada.
                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                // Loop para exibir tarefas filtradas por prioridade.
                for (int i = 0; i < numTarefas; i++) {
                    if (tarefa[i].prioridade == prioridadeFiltro) {
                        // Exibe detalhes das tarefas filtradas.
                        printf("\nTarefa %d:\n", i + 1);
                        printf("Prioridade: %d\n", tarefa[i].prioridade);
                        printf("Descricao: %s\n", tarefa[i].descricao);
                        printf("Categoria: %s\n", tarefa[i].categoria);
                        // Condicional para exibir o estado da tarefa.
                        if (tarefa[i].estado == 1) {
                            printf("Estado: nao iniciada\n");
                        } else if (tarefa[i].estado == 2) {
                            printf("Estado: em andamento\n");
                        } else if (tarefa[i].estado == 3) {
                            printf("Estado: completa\n");
                        }
                        printf("\n======================================================\n");
                    }
                }
            }

                // Filtro por estado.
            else if (opcaoFiltro == 2) {
                // Solicita o estado para o filtro.
                printf("\nDigite o estado desejado: ");
                scanf("%d", &estadoFiltro);
                limpaBuffer();

                // Cabeçalho para a listagem filtrada.
                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                // Loop para exibir tarefas filtradas por estado.
                for (int i = 0; i < numTarefas; i++) {
                    if (tarefa[i].estado == estadoFiltro) {
                        // Exibe detalhes das tarefas filtradas.
                        printf("\nTarefa %d:\n", i + 1);
                        printf("Prioridade: %d\n", tarefa[i].prioridade);
                        printf("Descricao: %s\n", tarefa[i].descricao);
                        printf("Categoria: %s\n", tarefa[i].categoria);
                        // Condicional para exibir o estado da tarefa.
                        if (tarefa[i].estado == 1) {
                            printf("Estado: nao iniciada\n");
                        } else if (tarefa[i].estado == 2) {
                            printf("Estado: em andamento\n");
                        } else if (tarefa[i].estado == 3) {
                            printf("Estado: completa\n");
                        }
                        printf("\n======================================================\n");
                    }
                }
            }

                // Filtro por categoria.
            else if (opcaoFiltro == 3) {
                // Solicita a categoria para o filtro.
                printf("\nDigite a categoria desejada: ");
                scanf("%s", categoriaFiltro);
                limpaBuffer();

                // Array temporário para armazenar tarefas filtradas.
                Tarefa tarefasFiltradas[100]; // Ajuste o tamanho conforme necessário
                int contagemFiltrada = 0;

                // Loop para filtrar tarefas por categoria.
                for (int i = 0; i < numTarefas; i++) {
                    if (strcmp(tarefa[i].categoria, categoriaFiltro) == 0) {
                        // Armazena tarefas filtradas no array temporário.
                        tarefasFiltradas[contagemFiltrada++] = tarefa[i];
                    }
                }

                // Ordena as tarefas filtradas por prioridade.
                qsort(tarefasFiltradas, contagemFiltrada, sizeof(Tarefa), compararPrioridade);

                // Cabeçalho para a listagem filtrada.
                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                // Loop para exibir tarefas filtradas e ordenadas.
                for (int i = 0; i < contagemFiltrada; i++) {
                    // Exibe detalhes das tarefas filtradas.
                    printf("\nTarefa %d:\n", i + 1);
                    printf("Prioridade: %d\n", tarefasFiltradas[i].prioridade);
                    printf("Descricao: %s\n", tarefasFiltradas[i].descricao);
                    printf("Categoria: %s\n", tarefasFiltradas[i].categoria);
                    // Condicional para exibir o estado da tarefa.
                    if (tarefasFiltradas[i].estado == 1) {
                        printf("Estado: nao iniciada\n");
                    } else if (tarefasFiltradas[i].estado == 2) {
                        printf("Estado: em andamento\n");
                    } else if (tarefasFiltradas[i].estado == 3) {
                        printf("Estado: completa\n");
                    }
                    printf("\n======================================================\n");
                }
            }

                // Filtro combinado por prioridade e categoria.
            else if (opcaoFiltro == 4) {
                // Solicita a prioridade para o filtro.
                printf("\nDigite a prioridade desejada: ");
                scanf("%d", &prioridadeFiltro);
                limpaBuffer();

                // Solicita a categoria para o filtro.
                printf("\nDigite categoria desejada: ");
                scanf("%s", categoriaFiltro);
                limpaBuffer();

                // Cabeçalho para a listagem filtrada.
                printf("======================================================\n");
                printf("Lista de Tarefas\n");
                printf("======================================================\n");
                // Loop para exibir tarefas filtradas por prioridade e categoria.
                for (int i = 0; i < numTarefas; i++) {
                    if (tarefa[i].prioridade == prioridadeFiltro && strcmp(tarefa[i].categoria, categoriaFiltro) == 0) {
                        // Exibe detalhes das tarefas filtradas.
                        printf("\nTarefa %d:\n", i + 1);
                        printf("Prioridade: %d\n", tarefa[i].prioridade);
                        printf("Descricao: %s\n", tarefa[i].descricao);
                        printf("Categoria: %s\n", tarefa[i].categoria);
                        // Condicional para exibir o estado da tarefa.
                        if (tarefa[i].estado == 1) {
                            printf("Estado: nao iniciada\n");
                        } else if (tarefa[i].estado == 2) {
                            printf("Estado: em andamento\n");
                        } else if (tarefa[i].estado == 3) {
                            printf("Estado: completa\n");
                        }
                        printf("\n======================================================\n");
                    }
                }
            }
        }
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
        limpaBuffer();

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

// Define a função para alterar uma tarefa existente no array de tarefas.
void alterarTarefa(Tarefa tarefas[], int numTarefas) {
    // Declaração de variáveis locais para armazenar o número da tarefa e a opção escolhida pelo usuário.
    int numero, opcao;

    // Exibe um cabeçalho para a seção de edição de tarefa.
    printf("======================================================\n");

    // Instrução para o usuário sobre a ação a ser realizada.
    printf("\nEditar tarefa existente:\n");

    // Solicita ao usuário que digite o número da tarefa a ser alterada.
    printf("\nDigite o numero da tarefa a ser alterada: ");
    scanf("%d", &numero);
    limpaBuffer();

    // Verifica se o número da tarefa está fora do intervalo válido.
    if (numero < 1 || numero > numTarefas) {
        // Mensagem de erro se o número da tarefa for inválido.
        printf("\nErro: Numero invalido. Tarefa nao encontrada.\n");
        printf("\n======================================================\n");

        // Encerra a função se o número da tarefa for inválido.
        return;
    }

    // Obtém um ponteiro para a tarefa selecionada.
    Tarefa *tarefa = &tarefas[numero - 1];

    // Exibe opções de campos a serem alterados na tarefa.
    printf("\nEscolha o campo a ser alterado:\n");
    printf("1. Prioridade\n2. Descricao\n3. Categoria\n4. Estado\n");
    scanf("%d", &opcao);
    limpaBuffer();

    // Estrutura switch para tratar a escolha do usuário.
    switch(opcao) {
        case 1:
            // Solicita a nova prioridade da tarefa.
            printf("Nova Prioridade: ");
            scanf("%d", &tarefa->prioridade);
            limpaBuffer();
            break;
        case 2:
            // Solicita a nova descrição da tarefa.
            printf("Nova Descricao: ");
            scanf(" %[^\n]s", tarefa->descricao);
            limpaBuffer();
            break;
        case 3:
            // Solicita a nova categoria da tarefa.
            printf("Nova Categoria: ");
            scanf(" %[^\n]s", tarefa->categoria);
            limpaBuffer();
            break;
        case 4:
            // Solicita o novo estado da tarefa.
            printf("Novo Estado (Digite apenas o algarismo): \n 1. nao iniciado, 2. em andamento, 3. completo: ");
            scanf("%d", (int *)&tarefa->estado);
            limpaBuffer();
            break;
        default:
            // Mensagem de erro se a opção escolhida for inválida.
            printf("Erro: Numero invalido. Campo da tarefa nao encontrado.\n");
    }

    // Chama a função para salvar as alterações no arquivo de tarefas.
    salvarTarefas(tarefas, numTarefas);
}

// Funções para exportar tarefas por prioridade, categoria ou ambas.
void exportarTarefasPorPrioridade(Tarefa tarefas[], int numTarefas, int prioridade) {
    // Abre ou cria um arquivo para escrita em modo binário.
    FILE *file = fopen("tarefas_por_prioridade.bin", "wb");
    // Verifica se houve erro ao abrir o arquivo.
    if (file == NULL) {
        // Imprime uma mensagem de erro.
        printf("Erro ao abrir o arquivo.\n");
        // Encerra a função se não puder abrir o arquivo.
        return;
    }

    // Percorre o array de tarefas.
    for (int i = 0; i < numTarefas; i++) {
        // Verifica se a prioridade da tarefa atual corresponde à desejada.
        if (tarefas[i].prioridade == prioridade) {
            // Escreve a tarefa no arquivo se ela atender ao critério de prioridade.
            fwrite(&tarefas[i], sizeof(Tarefa), 1, file);
        }
    }

    // Fecha o arquivo aberto.
    fclose(file);
}

void exportarTarefasPorCategoria(Tarefa tarefas[], int numTarefas, char *categoria) {
    // Abre ou cria um arquivo para escrita em modo binário.
    FILE *file = fopen("tarefas_por_categoria.bin", "wb");
    // Verifica se houve erro ao abrir o arquivo.
    if (file == NULL) {
        // Imprime uma mensagem de erro.
        printf("Erro ao abrir o arquivo.\n");
        // Encerra a função se não puder abrir o arquivo.
        return;
    }

    // Percorre o array de tarefas.
    for (int i = 0; i < numTarefas; i++) {
        // Compara a categoria da tarefa atual com a categoria desejada.
        if (strcmp(tarefas[i].categoria, categoria) == 0) {
            // Escreve a tarefa no arquivo se ela atender ao critério de categoria.
            fwrite(&tarefas[i], sizeof(Tarefa), 1, file);
        }
    }

    // Fecha o arquivo aberto.
    fclose(file);
}

void exportarTarefasPorPrioridadeCategoria(Tarefa tarefas[], int numTarefas, int prioridade, char *categoria) {
    // Abre ou cria um arquivo para escrita em modo binário.
    FILE *file = fopen("tarefas_por_prioridade_categoria.bin", "wb");
    // Verifica se houve erro ao abrir o arquivo.
    if (file == NULL) {
        // Imprime uma mensagem de erro.
        printf("Erro ao abrir o arquivo.\n");
        // Encerra a função se não puder abrir o arquivo.
        return;
    }

    // Percorre o array de tarefas.
    for (int i = 0; i < numTarefas; i++) {
        // Verifica se a tarefa atende aos critérios de prioridade e categoria.
        if (tarefas[i].prioridade == prioridade && strcmp(tarefas[i].categoria, categoria) == 0) {
            // Escreve a tarefa no arquivo se ela atender a ambos os critérios.
            fwrite(&tarefas[i], sizeof(Tarefa), 1, file);
        }
    }

    // Fecha o arquivo aberto.
    fclose(file);
}

// Define a função exportarTarefas que recebe um array de Tarefas e um inteiro numTarefas
int exportarTarefas(Tarefa tarefas[], int numTarefas) {
    // Declaração de variáveis locais
    int escolha;
    int prioridade;
    char categoria[100];

    // Imprime o cabeçalho do menu de exportação
    printf("======================================================\n");
    printf("\nExportar tarefas:\n");
    printf("\nSelecione como deseja exportar as tarefas: \n");
    printf("1. Por Prioridade\n");
    printf("2. Por Categoria\n");
    printf("3. Por Prioridade e Categoria\n");
    printf("\nDigite aqui: ");
    // Lê a escolha do usuário do teclado
    scanf("%d", &escolha);
    limpaBuffer();

    // Estrutura switch para tratar a escolha do usuário
    switch (escolha) {
        case 1:
            // Solicita ao usuário a prioridade para exportação
            printf("Digite a prioridade desejada:");
            scanf("%d", &prioridade);
            limpaBuffer();

            // Chama função para exportar tarefas por prioridade
            exportarTarefasPorPrioridade(tarefas, numTarefas, prioridade);
            // Imprime uma linha divisória
            printf("==================================================\n");
            break;
        case 2:
            // Solicita ao usuário a categoria para exportação
            printf("Digite a categoria desejada:");
            scanf("%100s", categoria);
            limpaBuffer();
            // Remove o newline lido por fgets do final da string categoria
            categoria[strcspn(categoria, "\n")] = 0;
            // Chama função para exportar tarefas por categoria
            exportarTarefasPorCategoria(tarefas, numTarefas, categoria);
            // Imprime uma linha divisória
            printf("==================================================\n");
            break;
        case 3:
            // Solicita ao usuário a categoria para exportação
            printf("Digite a categoria desejada:");
            scanf("%100s", categoria);
            limpaBuffer();

            // Remove o newline lido por fgets do final da string categoria
            categoria[strcspn(categoria, "\n")] = 0;
            // Solicita ao usuário a prioridade para exportação
            printf("Digite a Prioridade desejada:");
            scanf("%d", &prioridade);
            limpaBuffer();

            // Chama função para exportar tarefas por prioridade e categoria
            exportarTarefasPorPrioridadeCategoria(tarefas, numTarefas, prioridade, categoria);
            // Imprime uma linha divisória
            printf("==================================================\n");
            break;
        default:
            // Mensagem de erro para escolha inválida
            printf("\nErro: Numero invalido. Tarefa nao encontrada.\n");
            // Retorna 1 indicando erro
            return 1;
    }

    return 0;
}
