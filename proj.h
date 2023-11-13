// struct "Tarefa" que define o formato da tarefa e seus componentes:
typedef struct {
    int prioridade;
    char categoria[100];
    char descricao[300];
        int estado;
} Tarefa;

// Declaração das funções do "proj.c":
void cadastrarTarefa(Tarefa tarefas[], int *numTarefas);
void deletarTarefa(Tarefa tarefas[], int *numTarefas);
void listarTarefas(Tarefa tarefas[], int numTarefas);
void alterarTarefa(Tarefa tarefas[], int numTarefas);
int exportarTarefas(Tarefa tarefas[], int numTarefas);
int compararPrioridade(const void *a, const void *b);
