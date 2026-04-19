/* regas.c */
/* Implementação do módulo de regas */

#include <stdio.h>
#include "regas.h"
#include "plantas.h"  /* necessário para atualizar ultima_rega */

/* ── Array privado ──────────────────────────────────────── */
/* Este array é privado — só acessível dentro deste ficheiro */
static Rega regas[MAX_REGAS];
static int total_regas = 0;

/* ── Funções públicas ───────────────────────────────────── */

int registar_rega(int id_planta, int data, int quantidade) {
    /* Verifica se o limite foi atingido */
    if (total_regas >= MAX_REGAS) {
        printf("Limite de regas atingido.\n");
        return 0;
    }

    /* Verifica se a planta existe e atualiza ultima_rega */
    if (atualizar_ultima_rega(id_planta, data) == 0) {
        printf("Planta com ID %d nao existe.\n", id_planta);
        return 0;
    }

    /* Regista a rega */
    regas[total_regas].id_rega = total_regas + 1;
    regas[total_regas].id_planta = id_planta;
    regas[total_regas].data_rega = data;
    regas[total_regas].quantidade_agua = quantidade;
    total_regas++;

    return 1;
}

void listar_regas() {
    printf("=== REGAS ===\n");
    if (total_regas == 0) {
        printf("Nao existem regas registadas.\n");
        return;
    }
    for (int i = 0; i < total_regas; i++) {
        printf("ID Rega: %d | ID Planta: %d | "
               "Data: %d | Quantidade: %d ml\n",
               regas[i].id_rega, regas[i].id_planta,
               regas[i].data_rega, regas[i].quantidade_agua);
    }
}

int get_total_regas() {
    return total_regas;
}

Rega* get_rega(int index) {
    /* Verifica se o indice é válido */
    if (index < 0 || index >= total_regas) return NULL;
    return &regas[index];
}