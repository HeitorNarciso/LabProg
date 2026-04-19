/* dados.h */
/* Interface pública do módulo de dados.
   Responsável por guardar e carregar dados
   dos ficheiros CSV */

#ifndef DADOS_H
#define DADOS_H

#include "tipos.h"

/* ── Funções públicas ───────────────────────────────────── */

/* Carrega os dados dos ficheiros CSV para os arrays */
void carregar_dados();

/* Guarda os dados dos arrays nos ficheiros CSV */
void guardar_dados();

#endif /* DADOS_H */