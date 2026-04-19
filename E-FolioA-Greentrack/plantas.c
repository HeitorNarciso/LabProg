/* plantas.c */
/* Implementação do módulo de plantas */

#include <stdio.h>
#include <string.h>
#include "plantas.h"

/* ── Array privado ──────────────────────────────────────── */
/* Este array é privado — só acessível dentro deste ficheiro */
static Planta plantas[MAX_PLANTAS];
static int total_plantas = 0;

/* ── Funções públicas ───────────────────────────────────── */

int adicionar_planta(char* nome, char* especie,
                     char* data_plantio, int intervalo) {
    /* Verifica se o limite foi atingido */
    if (total_plantas >= MAX_PLANTAS) {
        printf("Limite de plantas atingido.\n");
        return 0;
    }
    /* Gera o id automaticamente */
    plantas[total_plantas].id = total_plantas + 1;
    strcpy(plantas[total_plantas].nome, nome);
    strcpy(plantas[total_plantas].especie, especie);
    strcpy(plantas[total_plantas].data_plantio, data_plantio);
    plantas[total_plantas].intervalo_rega = intervalo;
    plantas[total_plantas].ultima_rega = 0;
    total_plantas++;
    return 1;
}

void listar_plantas() {
    printf("=== PLANTAS ===\n");
    if (total_plantas == 0) {
        printf("Nao existem plantas registadas.\n");
        return;
    }
    /* Corrigido: i < total_plantas em vez de i <= total_plantas */
    for (int i = 0; i < total_plantas; i++) {
        printf("ID: %d | Nome: %s | Especie: %s | Plantio: %s | "
               "Intervalo: %d dias | Ultima rega: %d\n",
               plantas[i].id, plantas[i].nome, plantas[i].especie,
               plantas[i].data_plantio, plantas[i].intervalo_rega,
               plantas[i].ultima_rega);
    }
}

int verificar_rega(int data_atual) {
    printf("=== PLANTAS QUE PRECISAM DE REGA ===\n");
    int count = 0;
    for (int i = 0; i < total_plantas; i++) {
        int dias = data_atual - plantas[i].ultima_rega;
        if (dias >= plantas[i].intervalo_rega) {
            printf("Planta %s (ID: %d) precisa de rega! "
                   "(ultima: %d dias atras)\n",
                   plantas[i].nome, plantas[i].id, dias);
            count++;
        }
    }
    return count;
}

int get_total_plantas() {
    return total_plantas;
}

Planta* get_planta(int index) {
    /* Verifica se o indice é válido */
    if (index < 0 || index >= total_plantas) return NULL;
    return &plantas[index];
}

int atualizar_ultima_rega(int id_planta, int data) {
    for (int i = 0; i < total_plantas; i++) {
        if (plantas[i].id == id_planta) {
            plantas[i].ultima_rega = data;
            return 1;
        }
    }
    /* Planta nao encontrada */
    return 0;
}