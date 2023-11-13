#include <stdio.h>
#include "proj.h"

int main(){


//  Limite do número de tarefas cadastráveis:
    Tarefa tarefas[100];
//  Variável que determina o número de tarefas cadastradas:
    int numTarefas = 0;
//  Variável usada para detectar qual opção será utilizada:
    int opcao;

    // Algoritmo de escolha de opções:
    // Neste trecho está armazenado o algoritmo onde o computador irá executar suas funcionalidades de acordo com a atividade do usuário.
    do {
     // Menu Principal:
        printf("\nBem-vindo ao Gerenciador de Tarefas!\n");
        printf("\n");
        printf("Qual funcionalidade gostaria de performar hoje?\n");
        printf("1. Criar Tarefa\n");
        printf("2. Deletar Tarefa\n");
        printf("3. Listar Tarefas\n");
        printf("4. Alterar Tarefa\n");
        printf("5. Exportar Tarefas\n");
        printf("Lembre-se: A quantidade maxima de tarefas eh 100!\n");
        printf("\nDigite aqui o algarismo da funcionalidade desejada: ");
        scanf("%d", &opcao);

     // Se o input = 0, encerra o programa.
        if(opcao == 0){
            printf("\n");
            printf("Encerrando Gerenciador...\n");
        }

     // Se o input do usuário = 1, cadastra uma nova tarefa.
        else if(opcao == 1){
            cadastrarTarefa(tarefas, &numTarefas);
        }

     // Se o input do usuário = 2, deleta uma tarefa de acordo com seu respectivo número.
        else if(opcao == 2){
            deletarTarefa(tarefas, &numTarefas);
        }

     // Se o input do usuário = 3, listar as tarefas cadastradas.
        else if(opcao == 3){
            listarTarefas(tarefas, numTarefas);
        }
     // Se o input do usuário = 4, alterar uma tarefa existente.
        else if(opcao == 4){
            alterarTarefa(tarefas, numTarefas);
        }
     // Se o input do usuário = 5, exportar tarefas.
        else if(opcao == 5){
            exportarTarefas(tarefas, numTarefas);
        }

     // Se o input do usuário não for nenhuma das opções acima, retorna erro.
        else{
            printf("\n");
            printf("ERRO: Funcionalidade inexistente.\n");
            printf("==================================\n");
        }

    } while (opcao != 0);
//     ^ manter o loop enquanto opção != 0.

 // Comando de acréscimo/deleção e listagem dentro do arquivo binário:
    FILE *file = fopen("tarefas.bin", "wb");
    if (file) {
        fwrite(tarefas, sizeof(Tarefa), numTarefas, file);
        fclose(file);
    } else {
        printf("Erro ao salvar tarefa. Tente novamente ou reinicie o programa.\n");
    }

    return 0;
}
