/* main.c */
/* Ponto de entrada do programa GreenTrack */
/* Gere o menu e a interacao com o utilizador */

#include <stdio.h>
#include <string.h>
#include "plantas.h"
#include "regas.h"
#include "tarefas.h"
#include "dados.h"

/* ── Função auxiliar para limpar o buffer do teclado ────── */
static void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/* ── Função auxiliar para ler texto com espaços ─────────── */
/* Corrigido: fgets em vez de scanf para suportar espaços   */
static void ler_string(char* destino, int tamanho) {
    fgets(destino, tamanho, stdin);
    /* Remove o \n que o fgets inclui no final */
    destino[strcspn(destino, "\n")] = '\0';
}

/* ── Menu principal ─────────────────────────────────────── */
static void mostrar_menu() {
    printf("\n=== GREENTRACK - GESTAO DE JARDINS ===\n");
    printf("1. Listar plantas\n");
    printf("2. Adicionar planta\n");
    printf("3. Registar rega\n");
    printf("4. Verificar plantas que precisam de rega\n");
    printf("5. Listar regas\n");
    printf("6. Criar tarefa\n");
    printf("7. Concluir tarefa\n");
    printf("8. Listar tarefas pendentes\n");
    printf("9. Listar todas as tarefas\n");
    printf("0. Sair\n");
    printf("Opcao: ");
}

int main() {
    int opcao;

    /* Carrega os dados dos ficheiros CSV no inicio */
    carregar_dados();

    do {
        mostrar_menu();
        scanf("%d", &opcao);
        limpar_buffer(); /* limpa o \n que fica no buffer */

        switch (opcao) {
            case 1: {
                /* Listar plantas */
                listar_plantas();
                break;
            }
            case 2: {
                char nome[50], especie[50], data_plantio[12];
                int intervalo;

                printf("Nome: ");
                ler_string(nome, 50);

                printf("Especie: ");
                ler_string(especie, 50);

                printf("Data de plantio (DD/MM/AAAA): ");
                ler_string(data_plantio, 12);

                printf("Intervalo de rega (dias): ");
                scanf("%d", &intervalo);
                limpar_buffer();

                if (adicionar_planta(nome, especie, data_plantio, intervalo)) {
                printf("Planta adicionada com sucesso.\n");
                guardar_dados();
                }
                break;
            }
            case 3: {
                /* Registar rega */
                int id_planta, data, quantidade;

                printf("ID da planta: ");
                scanf("%d", &id_planta);
                limpar_buffer();

                printf("Data da rega (dias desde 01/01/2026): ");
                scanf("%d", &data);
                limpar_buffer();

                printf("Quantidade de agua (ml): ");
                scanf("%d", &quantidade);
                limpar_buffer();

                if (registar_rega(id_planta, data, quantidade)) {
                    printf("Rega registada com sucesso.\n");
                    /* Guarda imediatamente após registar */
                    guardar_dados();
                }
                break;
            }
            case 4: {
                /* Verificar plantas que precisam de rega */
                int data_atual;
                printf("Data atual (dias desde 01/01/2026): ");
                scanf("%d", &data_atual);
                limpar_buffer();

                int count = verificar_rega(data_atual);
                if (count == 0) {
                    printf("Todas as plantas estao regadas.\n");
                }
                break;
            }
            case 5: {
                /* Listar regas */
                listar_regas();
                break;
            }
            case 6: {
                /* Criar tarefa */
                char descricao[100];
                int data_prevista;

                printf("Descricao: ");
                /* Corrigido: fgets em vez de scanf */
                ler_string(descricao, 100);

                printf("Data prevista (dias desde 01/01/2026): ");
                scanf("%d", &data_prevista);
                limpar_buffer();

                if (criar_tarefa(descricao, data_prevista)) {
                    printf("Tarefa criada com sucesso.\n");
                    /* Guarda imediatamente após criar */
                    guardar_dados();
                }
                break;
            }
            case 7: {
                /* Concluir tarefa */
                int id;
                printf("ID da tarefa: ");
                scanf("%d", &id);
                limpar_buffer();

                if (concluir_tarefa(id)) {
                    /* Guarda imediatamente após concluir */
                    guardar_dados();
                }
                break;
            }
            case 8: {
                /* Listar tarefas pendentes */
                listar_tarefas_pendentes();
                break;
            }
            case 9: {
                /* Listar todas as tarefas */
                listar_tarefas();
                break;
            }
            case 0: {
                printf("A sair...\n");
                break;
            }
            default: {
                printf("Opcao invalida.\n");
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}