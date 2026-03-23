#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estrutura para armazenar dados de um estudante
typedef struct
{
    char nome[50];
    float nota;
} Estudante;

// Variáveis globais (manter na versão corrigida)
Estudante *estudantes;
int numEstudantes;

// Protótipos das funções
void adicionarEstudante(char *nome, float nota);
float calcularMedia();
void listarEstudantes();
void libertarMemoria();

// Função principal
int main(void)
{
    int opcao;
    char nome[50];
    float nota;

    setlocale(LC_ALL, "PT");
    numEstudantes = 0;
    estudantes = (Estudante *)malloc(10 * sizeof(Estudante));
    if (!estudantes)
    {
        fprintf(stderr, "Erro de memoria inicial.\n");
        return 1;
    }

    do
    {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar estudante\n");
        printf("2. Calcular média\n");
        printf("3. Listar estudantes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            printf("Nome: ");
            scanf("%49s", nome);
            printf("Nota: ");
            if (scanf("%f", &nota) != 1)
            {
                printf("Nota inválida.\n");
                while (getchar() != '\n')
                    ;
                break;
            }
            if (nota < 0 || nota > 20)
            {
                printf("Nota deve ser entre 0 e 20.\n");
                break;
            }
            adicionarEstudante(nome, nota);
            break;
        case 2:
            if (numEstudantes == 0)
            {
                printf("Nenhum estudante registado.\n");
            }
            else
            {
                printf("Média: %.2f\n", calcularMedia());
            }
            break;
        case 3:
            listarEstudantes();
            break;
        case 0:
            break;
        default:
            printf("Opção inválida.\n");
            break;
        }
    } while (opcao != 0);

    libertarMemoria();
    return 0;
}

// Adiciona um estudante à lista
void adicionarEstudante(char *nome, float nota)
{
    if (numEstudantes < 10)
    {
        strcpy(estudantes[numEstudantes].nome, nome);
        estudantes[numEstudantes].nota = nota;
        numEstudantes++;
        printf("Estudante adicionado com sucesso!\n");
    }
    else
    {
        printf("Lista cheia!\n");
    }
}

// Calcula a média das notas
float calcularMedia()
{
    float soma = 0.0f;
    int i;

    for (i = 0; i < numEstudantes; i++)
    {
        soma += estudantes[i].nota;
    }

    if (numEstudantes == 0)
        return 0.0f;

    return soma / numEstudantes;
}

// Lista todos os estudantes
void listarEstudantes()
{
    int i;

    if (numEstudantes == 0)
    {
        printf("Nenhum estudante registado.\n");
        return;
    }

    printf("\n=== Lista de Estudantes ===\n");
    for (i = 0; i < numEstudantes; i++)
    {
        printf("%d. %s - %.2f\n", i + 1, estudantes[i].nome, estudantes[i].nota);
    }
}

// Liberta a memória alocada
void libertarMemoria()
{
    printf("A libertar memória...\n");
    free(estudantes);
}
