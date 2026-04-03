int main()
{
    printf("Bem-vindo ao teste de geometria!\n");
    printf("Este programa é para testar as funções de geometria.\n");
    printf("Escolha a operação:\n");
    printf("a) Testar área do círculo\n");
    printf("b) Testar perímetro do círculo\n");
    printf("c) Testar área do retângulo\n");
    printf("d) Testar perímetro do retângulo\n");
    printf("e) Testar área do triângulo\n");
    printf("f) Testar perímetro do triângulo\n");
    printf("g) Testar área do quadrado\n");
    printf("h) Testar perímetro do quadrado\n");
    printf("i) Sair\n");

    char option;
    scanf(" %c", &option); // espaço para consumir whitespaces pendentes

    switch (option)
    {
    case 'a':
        // Código para testar área do círculo
        break;
    case 'b':
        // Código para testar perímetro do círculo
        break;
    case 'c':
        // Código para testar área do retângulo
        break;
    case 'd':
        // Código para testar perímetro do retângulo
        break;
    case 'e':
        // Código para testar área do triângulo
        break;
    case 'f':
        // Código para testar perímetro do triângulo
        break;
    case 'g':
        // Código para testar área do quadrado
        break;
    case 'h':
        // Código para testar perímetro do quadrado
        break;
    case 'i':
        printf("Exiting the geometry test. Goodbye!\n");
        break;
    default:
        fprintf(stderr, "Opção inválida.\n");
        break;
    }

    return 0;
}