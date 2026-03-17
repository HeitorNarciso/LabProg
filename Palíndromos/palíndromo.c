#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Função para verificar se uma palavra é palíndromo
bool ehPalindromo(char *str) {
    int inicio = 0;
    int fim = strlen(str) - 1;

    while (inicio < fim) {
        if (tolower(str[inicio]) != tolower(str[fim])) {
            return false;
        }
        inicio++;
        fim--;
    }
    return true;
}

int main() {
    char nomeFicheiro[100];
    char palavra[50];

    printf("Introduza o nome do ficheiro (ex: palavras.txt): ");
    
    // fgets para ler o nome do ficheiro com segurança
    if (fgets(nomeFicheiro, sizeof(nomeFicheiro), stdin) != NULL) {
        
        // Truncamento: remove o '\n' lido pelo fgets
        nomeFicheiro[strcspn(nomeFicheiro, "\n")] = 0;

        FILE *arquivo = fopen(nomeFicheiro, "r");
        
        if (arquivo == NULL) {
            printf("Erro: Nao foi possivel abrir o ficheiro '%s'.\n", nomeFicheiro);
            return 1;
        }

        printf("A procurar palindromos em '%s'...\n\n", nomeFicheiro);

        // Processamento: lê palavra a palavra e filtra por tamanho
        while (fscanf(arquivo, "%49s", palavra) != EOF) {
            int tam = strlen(palavra);

            if (tam >= 3 && tam <= 10) {
                if (ehPalindromo(palavra)) {
                    printf("Palindromo encontrado: %s\n", palavra);
                }
            }
        }

        fclose(arquivo);
        printf("\nProcessamento concluido.\n");
    }

    return 0;
}