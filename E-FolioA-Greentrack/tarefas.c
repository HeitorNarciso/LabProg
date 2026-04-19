/* tarefas.c */
/* Implementação do módulo de tarefas */

#include <stdio.h>
#include <string.h>
#include "tarefas.h"

/* ── Array privado ──────────────────────────────────────── */
/* Este array é privado — só acessível dentro deste ficheiro */
static Tarefa tarefas[MAX_TAREFAS];
static int total_tarefas = 0;

/* ── Funções públicas ───────────────────────────────────── */

int criar_tarefa(char* descricao, int data_prevista) {
    /* Verifica se o limite foi atingido */
    if (total_tarefas >= MAX_TAREFAS) {
        printf("Limite de tarefas atingido.\n");
        return 0;
    }
    /* Gera o id automaticamente */
    tarefas[total_tarefas].id_tarefa = total_tarefas + 1;
    strcpy(tarefas[total_tarefas].descricao, descricao);
    tarefas[total_tarefas].data_prevista = data_prevista;
    tarefas[total_tarefas].concluida = 0;
    total_tarefas++;
    return 1;
}

int concluir_tarefa(int id) {
    for (int i = 0; i < total_tarefas; i++) {
        /* Corrigido: == em vez de = */
        if (tarefas[i].id_tarefa == id) {
            tarefas[i].concluida = 1;
            printf("Tarefa %d concluida com sucesso.\n", id);
            return 1;
        }
    }
    printf("Tarefa com ID %d nao encontrada.\n", id);
    return 0;
}

void listar_tarefas_pendentes() {
    printf("=== TAREFAS PENDENTES ===\n");
    int encontradas = 0;
    for (int i = 0; i < total_tarefas; i++) {
        /* Corrigido: == em vez de = */
        if (tarefas[i].concluida == 0) {
            printf("ID: %d | Descricao: %s | Data prevista: %d\n",
                   tarefas[i].id_tarefa, tarefas[i].descricao,
                   tarefas[i].data_prevista);
            encontradas++;
        }
    }
    if (encontradas == 0) {
        printf("Nao existem tarefas pendentes.\n");
    }
}

void listar_tarefas() {
    printf("=== TAREFAS ===\n");
    if (total_tarefas == 0) {
        printf("Nao existem tarefas registadas.\n");
        return;
    }
    for (int i = 0; i < total_tarefas; i++) {
        printf("ID: %d | Descricao: %s | Data prevista: %d | %s\n",
               tarefas[i].id_tarefa, tarefas[i].descricao,
               tarefas[i].data_prevista,
               tarefas[i].concluida ? "Concluida" : "Pendente");
    }
}

int get_total_tarefas() {
    return total_tarefas;
}

Tarefa* get_tarefa(int index) {
    /* Verifica se o indice é válido */
    if (index < 0 || index >= total_tarefas) return NULL;
    return &tarefas[index];
}