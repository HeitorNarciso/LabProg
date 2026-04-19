# 📚 Laboratório de Programação (C) - UAb

![C](https://img.shields.io/badge/C-00599C?style=flat&logo=c&logoColor=white)

Este repositório é o meu diário de bordo na aprendizagem de C. Aqui guardo a lógica, 
os desafios e as soluções encontradas durante o curso na **Universidade Aberta**.

---

## ⚙️ Configuração do Ambiente
* **Compilador:** GCC via MSYS2 (UCRT64)
* **Automatização:** `tasks.json` configurado com flags de rigor:
  * `-Wall -Wextra -Wpedantic`: Para garantir que nenhum aviso de erro passa despercebido.
  * `-g`: Permite o uso do debugger para encontrar erros de memória.

---

## 📂 Estrutura do Repositório
```
01 - Conversor de Numerais Romanos/
02 - Detetor de Palindromos (Base)/
03 - Detetor Avançado de Palindromos/
04 - Gestor de Estudantes/
05 - Calculadora Modularizada/
06 - Geometria/
07 - GreenTrack/
├── tipos.h
├── plantas.h / plantas.c
├── regas.h / regas.c
├── tarefas.h / tarefas.c
├── dados.h / dados.c
└── main.c
```

---

## 📁 Detalhes dos Projetos

### 1. Conversor de Numerais Romanos 🏛️
**O que faz:** Converte uma string (ex: "MCMXCIV") no seu valor inteiro (1994).
* **Lógica:** Valida repetições proibidas (V, L, D) e aplica a regra de subtração ou 
  soma conforme a posição dos símbolos.

---

### 2. Detetor de Palíndromos (Base) 🔄
**O que faz:** Identifica palavras simples (3-10 caracteres) que se leem igual nos dois sentidos.
* **Lógica:** Uso de dois índices (início e fim) que caminham para o centro da palavra 
  comparando os caracteres.

---

### 3. Detetor Avançado de Palíndromos (Ficheiros e Acentos) 🚀
**O que faz:** Processa ficheiros reais (até 500KB), ignorando acentos, espaços e pontuação.
* **Normalização ISO-8859-1:** Filtro manual que converte caracteres acentuados para a 
  base ASCII (ex: `á` → `a`).
* **Mapeamento `origIdx`:** Técnica de preservação de contexto. Um array auxiliar liga o 
  texto limpo à sua posição original no ficheiro, permitindo imprimir o palíndromo com a 
  formatação original (espaços e acentos preservados).
* **Algoritmo de Expansão Central:** Estratégia de busca $O(n^2)$ que deteta simetria a 
  partir de cada centro possível (casos ímpares e pares).
* **Filtragem de Sub-palíndromos:** Ordenação por comprimento e validação de contenção 
  para garantir que apenas os palíndromos mais abrangentes são exibidos.

---

### 4. Correção e Refatoração de Gestor de Estudantes 📘
**O que faz:** Interface textual para adicionar estudantes, calcular média das notas e 
listar registos, com gestão dinâmica de memória.
* **Deteção de bugs:** Identifica erros de compilação (`scanf`), inicialização não feita 
  e divisão por zero.
* **Gestão de memória:** `malloc` inicial para 10 estudantes, `realloc` ao ultrapassar 
  10 e `free` ao terminar.
* **Validação de entrada:** Notas obrigatoriamente no intervalo 0-20; tratamento de 
  input inválido.
* **Boas práticas:** Elimina globals na versão refatorada, funções puras 
  (`calcularMedia`, `listarEstudantes`), passing de parâmetros e documentação interna.

---

## ⚠️ Resolução de Problemas (Troubleshooting)

### Erro: `warning: case label value is less than minimum value for type`
Este aviso ocorria porque o `char` padrão no GCC é assinado (`-128` a `127`). Valores 
hexadecimais como `0xC0` (192) eram interpretados como negativos ou fora de alcance.
* **Solução Implementada:** Alteração da assinatura da função para 
  `static char removerAcento(unsigned char c)` e uso de literais numéricos no `switch`. 
  Isto garante que o valor seja tratado no intervalo de `0` a `255`.

---

### 5. Calculadora Modularizada com Header e Implementação Separada ➗
**Objetivo do enunciado:** Modularizar um pequeno programa em C, organizando interface 
e implementação.

#### Ficheiros criados
* `calculator.h` - interface com protótipos.
* `calculator.c` - implementação das operações.
* `main.c` - programa principal que utiliza `calculator.h`.

#### Requisitos da `calculator.h`
* Header guard único e coerente: `CALCULATOR_H`.
* Funções declaradas:
  - `double add(double a, double b);`
  - `double subtract(double a, double b);`
  - `double multiply(double a, double b);`
  - `double divide(double a, double b);`
* Não há implementação no `.h` (só protótipos).
* Formatação consistente e comentários técnicos ao estilo C.

#### Ajuste ao enunciado original
O enunciado pedia funções `int multiplicar(int a, int b)` e `int subtrair(int a, int b)`; 
adaptámos para as versões `double` no projeto porque a calculadora principal trabalha 
com `double` e inclui divisão com ponto flutuante.

#### Justificação do nome do header guard
Escolhi `CALCULATOR_H` porque:
1. É consistente com o nome do ficheiro (`calculator.h`);
2. Usa maiúsculas e underscore, padrão de header guards em C;
3. É único no projeto e evita colisões com outros headers da workspace;
4. Mantém semântica clara: identifica precisamente o módulo de calculadora.

---

### 6. Geometria 🧮
**Objetivo:** Biblioteca geométrica modular com 3 ficheiros (`geometria.h`, `geometria.c`, 
`teste.c`), seguindo separação interface/implementação e teste de integração.

#### Componentes
* `geometria.h` - header guard `GEOMETRIA_H`; declarações de:
  - `double area_circle(double radius);`
  - `double perimetro_circle(double radius);`
  - `double area_rectangle(double length, double width);`
  - `double perimetro_rectangle(double length, double width);`
  - `double area_triangle(double base, double height);`
  - `double perimetro_triangle(double side1, double side2, double side3);`
  - `double area_square(double side);`
  - `double perimetro_square(double side);`

* `geometria.c` - implementações com `PI` local:
  - `static const double PI = 3.14159;`
  - Operações de área/perímetro de círculo, retângulo, triângulo e quadrado.

* `teste.c` - menu em português e validação de input:
  - Chamadas: `area_circle`, `perimetro_circle`, etc.
  - Resultado formatado com `%.2f`.
  - Usa `setlocale(LC_ALL, "");` para acentos.

#### Como testar
```bash
cd "06 - Geometria"
chcp 65001      # no Windows para UTF-8
gcc -Wall -Wextra -Wpedantic -g *.c -o teste.exe
./teste.exe
```

#### Saída exemplo
```
Área do círculo (r=5.00): 78.54
Área do retângulo (3.00 x 4.00): 12.00
```

---

### 7. E-Fólio A - GreenTrack: Correção e Modularização 🌱
**O que faz:** Plataforma de gestão de jardins comunitários que permite registar plantas, 
controlar regas e gerir tarefas de manutenção, com persistência de dados em ficheiros CSV.

#### Objetivo do trabalho
* **Módulo 1:** Identificar e corrigir erros num programa monolítico em C (14 erros encontrados).
* **Módulo 2:** Reorganizar o código numa arquitetura modular com encapsulamento adequado.

#### Erros corrigidos (principais categorias)
* **Gestão de ficheiros:** Uso incorreto de `!feof()` substituído por verificação do retorno 
  do `fscanf`; ficheiros sem verificação de `NULL`; dados não persistidos após operações 
  de escrita.
* **Lógica incorreta:** Condição `<=` em vez de `<` em ciclos; função `void` sem valor 
  de retorno útil.
* **Violação de pré-condições:** Arrays sem verificação de limites (`MAX_REGAS`, 
  `MAX_TAREFAS`); IDs geridos manualmente em vez de automaticamente.
* **Atribuição vs comparação:** `=` em vez de `==` em condições `if` — erro clássico em C.
* **Leitura de input:** `scanf("%s")` substituído por `fgets()` + `strcspn()` para suportar 
  espaços.

#### Arquitetura modular
| Ficheiro | Tipo | Responsabilidade |
|----------|------|-----------------|
| `tipos.h` | Header partilhado | Estruturas `Planta`, `Rega`, `Tarefa` e constantes |
| `plantas.h/.c` | Módulo | Gestão de plantas e verificação de rega |
| `regas.h/.c` | Módulo | Registo e listagem de regas |
| `tarefas.h/.c` | Módulo | Criação, conclusão e listagem de tarefas |
| `dados.h/.c` | Módulo | Persistência em ficheiros CSV |
| `main.c` | Entrada | Menu interativo e interação com o utilizador |

#### Técnicas e padrões aplicados
* **Encapsulamento:** Arrays declarados como `static` em cada `.c` — inacessíveis externamente.
* **Funções de acesso:** `get_planta()`, `get_rega()`, `get_tarefa()` para acesso controlado.
* **Include guards:** `#ifndef / #define / #endif` em todos os headers.
* **Funções privadas:** `static void limpar_buffer()`, `ler_string()`, `mostrar_menu()` 
  no `main.c`.
* **Persistência imediata:** `guardar_dados()` chamado após cada operação de escrita.

#### Como compilar
```bash
cd "07 - GreenTrack"
gcc -Wall -Wextra -Wpedantic -g *.c -o greentrack.exe
./greentrack.exe
```

#### Aprendizagens
* Diferença entre `=` (atribuição) e `==` (comparação) em condições.
* Porque `!feof()` é um antipadrão em C e como usar `fscanf` corretamente.
* Como garantir encapsulamento em C sem orientação a objetos.
* Comunicação entre módulos através de interfaces bem definidas (`.h`).

---

## 🚀 Como Compilar e Gerir

### No VS Code
* **Build:** `Ctrl + Shift + B`
* **Debug:** `F5` para inspecionar variáveis e ponteiros.

### Fluxo Git (Simplificado)
```bash
# Configurar upstream apenas na primeira vez:
git push -u origin main

git add .
git commit -m "feat: greentrack modularizado com correcao de 14 erros"
git push
```

---

## 🚀 Padrão de Commits (Conventional Commits)

Neste repositório, utilizo prefixos em minúsculas para manter o histórico limpo:
* `feat:` Novas funcionalidades (ex: suporte a maiúsculas).
* `fix:` Correções de bugs ou warnings de compilação.
* `docs:` Alterações no README ou comentários.
* `refactor:` Melhorias na estrutura do código.

---
*Atualizado em: Abril de 2026*
