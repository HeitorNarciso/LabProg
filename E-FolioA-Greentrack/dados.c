/* dados.c */
/* Implementação do módulo de dados */
/* Responsável por guardar e carregar dados dos ficheiros CSV */

#include <stdio.h>
#include <string.h>
#include "dados.h"
#include "plantas.h"
#include "regas.h"
#include "tarefas.h"

/* ── Funções públicas ───────────────────────────────────── */

void carregar_dados()
{
    /* ── Carregar plantas ───────────────────────────────── */
    FILE *f_plantas = fopen("plantas.csv", "r");
    if (f_plantas == NULL)
    {
        printf("Ficheiro plantas.csv nao encontrado.\n");
    }
    else
    {
        char nome[50], especie[50], data_plantio[12];
        int id, intervalo, ultima_rega;

        /* Corrigido: usar retorno do fscanf em vez de !feof() */
        while (fscanf(f_plantas, "%d,%49[^,],%49[^,],%10[^,],%d,%d\n",
                      &id, nome, especie, data_plantio,
                      &intervalo, &ultima_rega) == 6)
        {
            adicionar_planta(nome, especie, data_plantio, intervalo);
            /* Atualiza a ultima rega carregada do ficheiro */
            atualizar_ultima_rega(id, ultima_rega);
        }
        fclose(f_plantas);
    }

    /* ── Carregar regas ─────────────────────────────────── */
    /* Corrigido: verificação de NULL adicionada */
    FILE *f_regas = fopen("regas.csv", "r");
    if (f_regas == NULL)
    {
        printf("Ficheiro regas.csv nao encontrado.\n");
    }
    else
    {
        int id_rega, id_planta, data_rega, quantidade;

        /* Corrigido: usar retorno do fscanf em vez de !feof() */
        while (fscanf(f_regas, "%d,%d,%d,%d\n",
                      &id_rega, &id_planta,
                      &data_rega, &quantidade) == 4)
        {
            registar_rega(id_planta, data_rega, quantidade);
        }
        fclose(f_regas);
    }

    /* ── Carregar tarefas ───────────────────────────────── */
    /* Corrigido: verificação de NULL adicionada */
    FILE *f_tarefas = fopen("tarefas.csv", "r");
    if (f_tarefas == NULL)
    {
        printf("Ficheiro tarefas.csv nao encontrado.\n");
    }
    else
    {
        int id_tarefa, data_prevista, concluida;
        char descricao[100];

        /* Corrigido: usar retorno do fscanf em vez de !feof() */
        while (fscanf(f_tarefas, "%d,%99[^,],%d,%d\n",
                      &id_tarefa, descricao,
                      &data_prevista, &concluida) == 4)
        {
            criar_tarefa(descricao, data_prevista);
            /* Se a tarefa estava concluida, conclui-a */
            if (concluida == 1)
            {
                concluir_tarefa(id_tarefa);
            }
        }
        fclose(f_tarefas);
    }
}

void guardar_dados()
{
    /* ── Guardar plantas ────────────────────────────────── */
    FILE *f_plantas = fopen("plantas.csv", "w");
    if (f_plantas == NULL)
    {
        printf("Erro ao abrir plantas.csv\n");
        return;
    }
    for (int i = 0; i < get_total_plantas(); i++)
    {
        Planta *p = get_planta(i);
        fprintf(f_plantas, "%d,%s,%s,%s,%d,%d\n",
                p->id, p->nome, p->especie,
                p->data_plantio, p->intervalo_rega,
                p->ultima_rega);
    }
    fclose(f_plantas);

    /* ── Guardar regas ──────────────────────────────────── */
    FILE *f_regas = fopen("regas.csv", "w");
    if (f_regas == NULL)
    {
        printf("Erro ao abrir regas.csv\n");
        return;
    }
    for (int i = 0; i < get_total_regas(); i++)
    {
        Rega *r = get_rega(i);
        fprintf(f_regas, "%d,%d,%d,%d\n",
                r->id_rega, r->id_planta,
                r->data_rega, r->quantidade_agua);
    }
    fclose(f_regas);

    /* ── Guardar tarefas ────────────────────────────────── */
    FILE *f_tarefas = fopen("tarefas.csv", "w");
    if (f_tarefas == NULL)
    {
        printf("Erro ao abrir tarefas.csv\n");
        return;
    }
    for (int i = 0; i < get_total_tarefas(); i++)
    {
        Tarefa *t = get_tarefa(i);
        fprintf(f_tarefas, "%d,%s,%d,%d\n",
                t->id_tarefa, t->descricao,
                t->data_prevista, t->concluida);
    }
    fclose(f_tarefas);
}