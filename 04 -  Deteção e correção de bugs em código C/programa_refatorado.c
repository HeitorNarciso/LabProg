#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char nome[50];
    float nota;
} Estudante;

// Cria uma lista de estudantes com capacidade inicial.
Estudante *criarLista(int capacidade)
{
    Estudante *lista = malloc((size_t)capacidade * sizeof(Estudante));
    if (!lista)
    {
        fprintf(stderr, "Erro de memória para lista inicial.\n");
        exit(1);
    }
    return lista;
}

// Se necessário, aumenta a lista, dobrando capacidade.
Estudante *garantirCapacidade(Estudante *lista, int *capacidade, int requisitada)
{
    if (requisitada <= *capacidade)
        return lista;

    int novaCap = *capacidade * 2;
    if (novaCap < requisitada)
        novaCap = requisitada;

    Estudante *tmp = realloc(lista, (size_t)novaCap * sizeof(Estudante));
    if (!tmp)
    {
        fprintf(stderr, "Erro de memória no realocamento.\n");
        free(lista);
        exit(1);
    }

    *capacidade = novaCap;
    return tmp;
}

void adicionarEstudante(Estudante **lista, int *numEstudantes, int *capacidade, const char *nome, float nota)
{
    if (nota < 0.0f || nota > 20.0f)
    {
        printf("Nota inválida (0-20).\n");
        return;
    }

    *lista = garantirCapacidade(*lista, capacidade, *numEstudantes + 1);

    strncpy((*lista)[*numEstudantes].nome, nome, sizeof((*lista)[*numEstudantes].nome) - 1);
    (*lista)[*numEstudantes].nome[sizeof((*lista)[*numEstudantes].nome) - 1] = '\0';
    (*lista)[*numEstudantes].nota = nota;
    (*numEstudantes)++;
    printf("Estudante adicionado com sucesso. Total: %d\n", *numEstudantes);
}

float calcularMedia(const Estudante *lista, int numEstudantes)
{
    if (numEstudantes == 0)
        return 0.0f;

    float soma = 0.0f;
    for (int i = 0; i < numEstudantes; i++)
        soma += lista[i].nota;

    return soma / numEstudantes;
}

void listarEstudantes(const Estudante *lista, int numEstudantes)
{
    if (numEstudantes == 0)
    {
        printf("Nenhum estudante registado.\n");
        return;
    }

    printf("\n=== Lista de Estudantes ===\n");
    for (int i = 0; i < numEstudantes; i++)
        printf("%d. %s - %.2f\n", i + 1, lista[i].nome, lista[i].nota);
}

void libertarMemoria(Estudante *lista)
{
    free(lista);
}

int main(void)
{
    setlocale(LC_ALL, "PT");

    int opcao;
    int numEstudantes = 0;
    int capacidade = 10;
    Estudante *lista = criarLista(capacidade);

    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar estudante\n");
        printf("2. Calcular média\n");
        printf("3. Listar estudantes\n");
        printf("0. Sair\n");
        printf("Opção: ");

        if (scanf("%d", &opcao) != 1)
        {
            fprintf(stderr, "Entrada inválida.\n");
            break;
        }

        if (opcao == 1)
        {
            char nome[50];
            float nota;

            printf("Nome: ");
            scanf("%49s", nome);

            printf("Nota: ");
            if (scanf("%f", &nota) != 1)
            {
                printf("Nota inválida.\n");
                while (getchar() != '\n')
                    ;
                continue;
            }

            adicionarEstudante(&lista, &numEstudantes, &capacidade, nome, nota);
        }
        else if (opcao == 2)
        {
            float media = calcularMedia(lista, numEstudantes);
            if (numEstudantes == 0)
                printf("Nenhum estudante registado.\n");
            else
                printf("Média: %.2f\n", media);
        }
        else if (opcao == 3)
        {
            listarEstudantes(lista, numEstudantes);
        }
        else if (opcao != 0)
        {
            printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    libertarMemoria(lista);
    return 0;
}
