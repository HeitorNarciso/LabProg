/* tipos.h */
/* Este ficheiro define as estruturas de dados e constantes
   partilhadas por todos os módulos do programa */

#ifndef TIPOS_H   /* Evita que o ficheiro seja incluido mais do que uma vez */
#define TIPOS_H

/* ── Limites dos arrays ─────────────────────────────────── */
#define MAX_PLANTAS 100
#define MAX_REGAS   500
#define MAX_TAREFAS 200

/* ── Estrutura de uma Planta ────────────────────────────── */
typedef struct {
    int id;
    char nome[50];
    char especie[50];
    char data_plantio[12]; /* formato DD/MM/AAAA */
    int intervalo_rega;    /* em dias */
    int ultima_rega;       /* dias desde 01/01/2026 */
} Planta;

/* ── Estrutura de uma Rega ──────────────────────────────── */
typedef struct {
    int id_rega;
    int id_planta;
    int data_rega;         /* dias desde 01/01/2026 */
    int quantidade_agua;   /* em ml */
} Rega;

/* ── Estrutura de uma Tarefa ────────────────────────────── */
typedef struct {
    int id_tarefa;
    char descricao[100];
    int data_prevista;     /* dias desde 01/01/2026 */
    int concluida;         /* 0 = pendente | 1 = concluida */
} Tarefa;

#endif /* TIPOS_H */