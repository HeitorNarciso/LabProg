// Detetor de palindromos AF 1.1
// Implementa palindromos de frase completa:
// - ignora espaços e pontuação
// - normaliza acentos para letras base
// - case-insensitive
// - encontra parcialmente palindromos dentro de maiores e seleciona os mais abrangentes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_TEXTO 500000      // limite máximo de ficheiro em bytes
#define MAX_PALINDROMOS 50000 // limite para lista de candidatos (protegido)

// Converte letra acentuada em versão sem acento (ISO-8859-1)
// Usamos unsigned char para evitar avisos com valores >= 0x80 em sistemas com char signed.
static char removerAcento(unsigned char c)
{
    switch (c)
    {
    case 0xC0:
    case 0xC1:
    case 0xC2:
    case 0xC3:
    case 0xC4:
    case 0xC5:
    case 0xE0:
    case 0xE1:
    case 0xE2:
    case 0xE3:
    case 0xE4:
    case 0xE5:
        return 'a';
    case 0xC7:
    case 0xE7:
        return 'c';
    case 0xC8:
    case 0xC9:
    case 0xCA:
    case 0xCB:
    case 0xE8:
    case 0xE9:
    case 0xEA:
    case 0xEB:
        return 'e';
    case 0xCC:
    case 0xCD:
    case 0xCE:
    case 0xCF:
    case 0xEC:
    case 0xED:
    case 0xEE:
    case 0xEF:
        return 'i';
    case 0xD1:
    case 0xF1:
        return 'n';
    case 0xD2:
    case 0xD3:
    case 0xD4:
    case 0xD5:
    case 0xD6:
    case 0xD8:
    case 0xF2:
    case 0xF3:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0xF8:
        return 'o';
    case 0xD9:
    case 0xDA:
    case 0xDB:
    case 0xDC:
    case 0xF9:
    case 0xFA:
    case 0xFB:
    case 0xFC:
        return 'u';
    case 0xDD:
    case 0xFD:
    case 0xFF:
        return 'y';
    default:
        return c;
    }
}

static bool ehLetraDigito(char c)
{
    return isalpha((unsigned char)c) || isdigit((unsigned char)c);
}

int main(void)
{
    // ler nome do ficheiro de entrada
    char nomeFicheiro[260];
    char *original = NULL; // armazenar texto completo
    long tamanho;
 
    printf("Introduza o nome do ficheiro (ex: palavras.txt): ");
    if (fgets(nomeFicheiro, sizeof(nomeFicheiro), stdin) == NULL)
        return 1;

    // remove \n de fim de linha
    nomeFicheiro[strcspn(nomeFicheiro, "\n")] = '\0';

    // abrir ficheiro binário para preservar acentos do modo como estão no disco
    FILE *arquivo = fopen(nomeFicheiro, "rb");
    if (!arquivo)
    {
        printf("Erro: Nao foi possivel abrir o ficheiro '%s'.\n", nomeFicheiro);
        return 1;
    }

    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    if (tamanho <= 0 || tamanho > MAX_TEXTO)
    {
        fclose(arquivo);
        printf("Erro: ficheiro vazio ou demasiado grande.\n");
        return 1;
    }

    original = malloc((size_t)tamanho + 1);
    if (!original)
    {
        fclose(arquivo);
        printf("Erro de memoria.\n");
        return 1;
    }

    fread(original, 1, (size_t)tamanho, arquivo);
    original[tamanho] = '\0';
    fclose(arquivo);

    // normalizar e filtrar texto: mantém apenas letras/dígitos sem acentos e em minúsculo
    // origIdx guarda índice no original para reportar substring exata.
    char *norm = malloc((size_t)tamanho + 1);
    int *origIdx = malloc(((size_t)tamanho + 1) * sizeof(int));
    if (!norm || !origIdx)
    {
        free(original);
        free(norm);
        free(origIdx);
        printf("Erro de memoria.\n");
        return 1;
    }

    int normLen = 0;

    for (int i = 0; i < tamanho; i++)
    {
        unsigned char c = (unsigned char)original[i];
        if (!ehLetraDigito((char)c))
            continue; // ignora espaços, pontuação, e outros caracteres não alfanuméricos

        char base = removerAcento(c);              // elimina acento
        base = (char)tolower((unsigned char)base); // normaliza case

        if (ehLetraDigito(base))
        {
            norm[normLen] = base;
            origIdx[normLen] = i; // mapa de normalizado -> original
            normLen++;
        }
    }

    if (normLen < 3)
    {
        printf("Nenhum palindromo valido encontrado.\n");
        free(original);
        free(norm);
        free(origIdx);
        return 0;
    }

    typedef struct
    {
        int l, r;
    } Range;

    Range *candidatos = malloc(MAX_PALINDROMOS * sizeof(Range));
    if (!candidatos)
    {
        free(original);
        free(norm);
        free(origIdx);
        printf("Erro de memoria.\n");
        return 1;
    }

    // encontrar todos palindromos normalizados de comprimento >= 3.
    // utiliza varredura central para obter todos os substrings palindrômicos.
    int candCnt = 0;

    for (int center = 0; center < normLen; center++)
    {
        int l = center;
        int r = center;

        // palíndromo de comprimento ímpar (centro em center)
        while (l >= 0 && r < normLen && norm[l] == norm[r])
        {
            int len = r - l + 1;
            if (len >= 3 && candCnt < MAX_PALINDROMOS)
                candidatos[candCnt++] = (Range){l, r};
            l--;
            r++;
        }

        l = center;
        r = center + 1;

        // palíndromo de comprimento par (centro entre center e center+1)
        while (l >= 0 && r < normLen && norm[l] == norm[r])
        {
            int len = r - l + 1;
            if (len >= 3 && candCnt < MAX_PALINDROMOS)
                candidatos[candCnt++] = (Range){l, r};
            l--;
            r++;
        }
    }

    if (candCnt == 0)
    {
        printf("Nenhum palindromo valido encontrado.\n");
        free(original);
        free(norm);
        free(origIdx);
        free(candidatos);
        return 0;
    }

    // ordenar candidatos por comprimento decrescente (maiores primeiro)
    // para selecionar palindromos abrangentes antes dos "sub-palindromos".
    for (int i = 0; i < candCnt - 1; i++)
    {
        for (int j = i + 1; j < candCnt; j++)
        {
            int lenI = candidatos[i].r - candidatos[i].l + 1;
            int lenJ = candidatos[j].r - candidatos[j].l + 1;
            if (lenJ > lenI)
            {
                Range tmp = candidatos[i];
                candidatos[i] = candidatos[j];
                candidatos[j] = tmp;
            }
        }
    }

    Range *selecionados = malloc(MAX_PALINDROMOS * sizeof(Range));
    if (!selecionados)
    {
        free(original);
        free(norm);
        free(origIdx);
        free(candidatos);
        printf("Erro de memoria.\n");
        return 1;
    }

    int selCnt = 0;

    // filtra para palindromos máximos: descarta contidos em palindromos já escolhidos
    for (int i = 0; i < candCnt; i++)
    {
        Range cur = candidatos[i];
        bool contained = false;

        for (int j = 0; j < selCnt; j++)
        {
            if (cur.l >= selecionados[j].l && cur.r <= selecionados[j].r)
            {
                contained = true;
                break;
            }
        }

        if (!contained)
        {
            bool duplicate = false;

            for (int j = 0; j < selCnt; j++)
            {
                if (cur.l == selecionados[j].l && cur.r == selecionados[j].r)
                {
                    duplicate = true;
                    break;
                }
            }

            if (!duplicate && selCnt < MAX_PALINDROMOS)
                selecionados[selCnt++] = cur;
        }
    }

    // impressão usando o texto original para preservar acentos/espaços/pontuação
    printf("A procurar palindromos em '%s'...\n\n", nomeFicheiro);

    if (selCnt == 0)
    {
        printf("Nenhum palindromo valido encontrado.\n");
    }
    else
    {
        for (int i = 0; i < selCnt; i++)
        {
            int origL = origIdx[selecionados[i].l];
            int origR = origIdx[selecionados[i].r];
            int tam = origR - origL + 1;
            printf("Palindromo encontrado: %.*s\n", tam, original + origL);
        }
    }

    printf("\nProcessamento concluido.\n");

    free(original);
    free(norm);
    free(origIdx);
    free(candidatos);
    free(selecionados);

    return 0;
}
