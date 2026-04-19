/* tarefas.h */
/* Interface pública do módulo de tarefas.
   Outros módulos incluem este ficheiro para
   aceder às funções de gestão de tarefas */

#ifndef TAREFAS_H
#define TAREFAS_H

#include "tipos.h"

/* ── Funções públicas ───────────────────────────────────── */

/* Cria uma nova tarefa no sistema */
/* devolve 1 se sucesso, 0 se erro */
int criar_tarefa(char* descricao, int data_prevista);

/* Conclui uma tarefa pelo seu id */
/* devolve 1 se sucesso, 0 se nao encontrada */
int concluir_tarefa(int id);

/* Lista todas as tarefas pendentes */
void listar_tarefas_pendentes();

/* Lista todas as tarefas */
void listar_tarefas();

/* Devolve o total de tarefas registadas */
int get_total_tarefas();

/* Devolve um ponteiro para a tarefa no indice dado */
Tarefa* get_tarefa(int index);

#endif /* TAREFAS_H */