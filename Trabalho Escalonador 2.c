#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSO 5

enum EstadoProcesso {
    PRONTO,
    BLOQUEADO,
    EXECUCAO
};

struct Processo {
    char name;
    int prioridade;
    int tempo_explosao;
    enum EstadoProcesso estado;
};

struct Fila {
    struct Processo *items[MAX_PROCESSO];
    int inicio, fim;
};

void enfileirar(struct Fila *f, struct Processo *processo) {
    if ((f->fim + 1) % MAX_PROCESSO == f->inicio) {
        printf("Fila está cheia.Não é possivel enfileirar.\n");
        exit(1);
    }
    f->fim = (f->fim + 1) % MAX_PROCESSO;
    f->items[f->fim] = processo;
}

struct Processo *desenfileirar(struct Fila *f) {
    if (f->inicio == f->fim) {
        return NULL; // A fila está vazia
    }
    f->inicio = (f->inicio + 1) % MAX_PROCESSO;
    return f->items[f->inicio];
}

void circular_scheduler(struct Processo processos[], int n, int tempo_quantum) {
    struct Fila fila_pronta = {{NULL}, -1, -1};

    for (int i = 0; i < n; i++) {
        processos[i].estado = PRONTO;
        enfileirar(&fila_pronta, &processos[i]);
    }

    int tempo_atual = 0;

    while (fila_pronta.inicio != fila_pronta.fim) {
        struct Processo *processo_atual = desenfileirar(&fila_pronta);
        processo_atual->estado = EXECUCAO;

        printf("Tempo: %d, Processo %c em EXECUÇÃO.\n", tempo_atual, processo_atual->name);

        tempo_atual += tempo_quantum;

        if (processo_atual->estado == PRONTO) {
            enfileirar(&fila_pronta, processo_atual);
        } else {
            processo_atual->estado = BLOQUEADO;
        }
    }
}

void prioridade_scheduler(struct Processo processos[], int n) {
    struct Fila fila_pronta = {{NULL}, -1, -1};

    for (int i = 0; i < n; i++) {
        processos[i].estado = PRONTO;
        enfileirar(&fila_pronta, &processos[i]);
    }

    int tempo_atual = 0;

    while (fila_pronta.inicio != fila_pronta.fim) {
        struct Processo *processo_atual = desenfileirar(&fila_pronta);
        processo_atual->estado = EXECUCAO;

        printf("Tempo: %d, Processo %c em EXECUCAO.\n", tempo_atual, processo_atual->name);

        tempo_atual += processo_atual->prioridade;

        if (processo_atual->estado == PRONTO) {
            enfileirar(&fila_pronta, processo_atual);
        } else {
            processo_atual->estado = BLOQUEADO;
        }
    }
}

int main() {
    struct Processo processos[] = {
        {'P1', 2, 10, PRONTO},
        {'P2', 1, 5, PRONTO},
        {'P3', 3, 8, PRONTO},
        {'P4', 2, 2, PRONTO},
        {'P5', 1, 7, PRONTO}
    };

    int tempo_quantum = 3;

    printf("Circular Scheduler:\n");
    circular_scheduler(processos, sizeof(processos) / sizeof(processos[0]), tempo_quantum);

    printf("\nPriority Scheduler:\n");
    prioridade_scheduler(processos, sizeof(processos) / sizeof(processos[0]));

    return 0;
}