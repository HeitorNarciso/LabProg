/* plantas.h */
/* Interface pública do módulo de plantas.
   Outros módulos incluem este ficheiro para
   aceder às funções de gestão de plantas */

#ifndef PLANTAS_H
#define PLANTAS_H

#include "tipos.h"

/* ── Funções públicas ───────────────────────────────────── */

/* Adiciona uma nova planta ao sistema */
int adicionar_planta(char* nome, char* especie,
                     char* data_plantio, int intervalo);

/* Lista todas as plantas registadas */
void listar_plantas();

/* Verifica quais as plantas que precisam de rega */
/* devolve o numero de plantas que precisam de rega */
int verificar_rega(int data_atual);

/* Devolve o total de plantas registadas */
int get_total_plantas();

/* Devolve um ponteiro para a planta no indice dado */
Planta* get_planta(int index);

/* Atualiza a data da ultima rega de uma planta */
int atualizar_ultima_rega(int id_planta, int data);

#endif /* PLANTAS_H */