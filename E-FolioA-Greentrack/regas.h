/* regas.h */
/* Interface pública do módulo de regas.
   Outros módulos incluem este ficheiro para
   aceder às funções de gestão de regas */

#ifndef REGAS_H
#define REGAS_H

#include "tipos.h"

/* ── Funções públicas ───────────────────────────────────── */

/* Regista uma nova rega no sistema */
/* devolve 1 se sucesso, 0 se erro */
int registar_rega(int id_planta, int data, int quantidade);

/* Lista todas as regas registadas */
void listar_regas();

/* Devolve o total de regas registadas */
int get_total_regas();

/* Devolve um ponteiro para a rega no indice dado */
Rega* get_rega(int index);

#endif /* REGAS_H */