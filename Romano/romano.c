/*
 * Roman Numeral to Decimal Converter
 * ====================================
 * Converts a Roman numeral string to its decimal value.
 * Example: MCMLXXIX = 1979
 *
 * Roman numeral rules:
 *   I=1, V=5, X=10, L=50, C=100, D=500, M=1000
 *
 * Valid subtractive pairs:
 *   IV=4, IX=9, XL=40, XC=90, CD=400, CM=900
 *
 * Repetition rules:
 *   - I, X, C, M can repeat at most 3 times in a row
 *   - V, L, D cannot repeat at all
 *   - Only the subtractive pairs listed above are allowed
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* ──────────────────────────────────────────────
   Constants
────────────────────────────────────────────── */
#define MAX_LEN 20

/* ──────────────────────────────────────────────
   Returns the decimal value of a Roman symbol,
   or -1 if the character is not a valid symbol.
────────────────────────────────────────────── */
int symbolValue(char c) {
    switch (c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default:  return -1;   /* invalid symbol */
    }
}

/* ──────────────────────────────────────────────
   Returns 1 if (smaller, larger) is a valid
   subtractive pair, 0 otherwise.
   Allowed pairs: IV IX XL XC CD CM
────────────────────────────────────────────── */
int isValidSubtraction(char smaller, char larger) {
    if (smaller == 'I' && (larger == 'V' || larger == 'X')) return 1;
    if (smaller == 'X' && (larger == 'L' || larger == 'C')) return 1;
    if (smaller == 'C' && (larger == 'D' || larger == 'M')) return 1;
    return 0;
}

/* ──────────────────────────────────────────────
   Validates and converts a Roman numeral string.
   Returns the decimal value on success,
   or -1 on error (error message already printed).
────────────────────────────────────────────── */
int convert(const char *roman) {
    int len = strlen(roman);
    int i, result = 0;

    /* 1. Empty string */
    if (len == 0) {
        printf("ERRO: Não introduziu nenhum numeral romano.\n");
        return -1;
    }

    /* 2. Input too long */
    if (len > MAX_LEN) {
        printf("ERRO: O numeral romano é demasiado longo (máximo %d caracteres).\n", MAX_LEN);
        return -1;
    }

    /* 3. Check for invalid characters (input already uppercased) */
    for (i = 0; i < len; i++) {
        if (symbolValue(roman[i]) == -1) {
            printf("ERRO: O caracter '%c' na posição %d não é um símbolo romano válido.\n",
                   roman[i], i + 1);
            printf("      Símbolos permitidos: I, V, X, L, C, D, M\n");
            return -1;
        }
    }

    /* 4. Check for illegal repetitions:
          V, L, D may not repeat; I, X, C, M at most 3 times in a row */
    for (i = 0; i < len; i++) {
        char c = roman[i];
        int rep = 1;
        while (i + rep < len && roman[i + rep] == c) rep++;

        if (c == 'V' || c == 'L' || c == 'D') {
            if (rep > 1) {
                printf("ERRO: O símbolo '%c' não pode repetir-se (ocorre %d vezes seguidas na posição %d).\n",
                       c, rep, i + 1);
                return -1;
            }
        } else {
            if (rep > 3) {
                printf("ERRO: O símbolo '%c' repete-se %d vezes seguidas na posição %d "
                       "(máximo permitido: 3).\n", c, rep, i + 1);
                return -1;
            }
        }
    }

    /* 5. Check for invalid subtractive pairs */
    for (i = 0; i < len - 1; i++) {
        int curVal  = symbolValue(roman[i]);
        int nextVal = symbolValue(roman[i + 1]);

        if (curVal < nextVal) {
            /* Subtractive notation detected — verify it is allowed */
            if (!isValidSubtraction(roman[i], roman[i + 1])) {
                printf("ERRO: A combinação '%c%c' (posições %d-%d) não é uma subtração romana válida.\n",
                       roman[i], roman[i + 1], i + 1, i + 2);
                printf("      Subtrações permitidas: IV, IX, XL, XC, CD, CM\n");
                return -1;
            }
        }
    }

    /* 6. Convert: subtract current value if smaller than the next symbol */
    for (i = 0; i < len; i++) {
        int curVal  = symbolValue(roman[i]);
        int nextVal = (i + 1 < len) ? symbolValue(roman[i + 1]) : 0;

        if (curVal < nextVal) {
            result -= curVal;
        } else {
            result += curVal;
        }
    }

    /* 7. Sanity check on the final value */
    if (result <= 0) {
        printf("ERRO: O numeral romano resultou num valor inválido (%d).\n", result);
        return -1;
    }
    if (result > 3999) {
        /* Not a fatal error — return the value anyway */
        printf("AVISO: O valor %d excede o intervalo clássico dos numerais romanos (1–3999).\n",
               result);
    }

    return result;
}

/* ──────────────────────────────────────────────
   Converts a string to uppercase in-place.
────────────────────────────────────────────── */
void toUpperStr(char *s) {
    for (; *s; s++) *s = toupper((unsigned char)*s);
}

/* ──────────────────────────────────────────────
   Entry point
────────────────────────────────────────────── */
int main(void) {
    char input[MAX_LEN + 10];  /* extra margin to detect oversized input */
    int  result;

    printf("===========================================\n");
    printf("  Conversor de Numerais Romanos -> Decimal  \n");
    printf("===========================================\n\n");

    printf("Introduza o numeral romano: ");

    /* Safe line read */
    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("ERRO: Falha na leitura da entrada.\n");
        return EXIT_FAILURE;
    }

    /* Strip trailing newline */
    input[strcspn(input, "\n")] = '\0';

    /* Accept lowercase input by converting to uppercase */
    toUpperStr(input);

    printf("\nNumeral introduzido: %s\n\n", input);

    result = convert(input);

    if (result != -1) {
        printf("Resultado: %s = %d\n", input, result);
    } else {
        printf("\nPor favor, corrija o erro e tente novamente.\n");
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
