# 📚 Laboratório de Programação (C) - UAb

Este repositório é o meu diário de bordo na aprendizagem de C. Aqui guardo a lógica, os desafios e as soluções encontradas durante o curso na **Universidade Aberta**.

---

## ⚙️ Configuração do Ambiente
* **Compilador:** GCC via MSYS2 (UCRT64)
* **Automatização:** `tasks.json` configurado com flags de rigor:
  * `-Wall -Wextra -Wpedantic`: Para garantir que nenhum aviso de erro passa despercebido.
  * `-g`: Permite o uso do debugger para encontrar erros de memória.

---

## 📁 Detalhes dos Projetos

### 1. Conversor de Numerais Romanos 🏛️
**O que faz:** Converte uma string (ex: "MCMXCIV") no seu valor inteiro (1994).
* **Lógica:** Valida repetições proibidas (V, L, D) e aplica a regra de subtração ou soma conforme a posição dos símbolos.

### 2. Detetor de Palíndromos (Base) 🔄
**O que faz:** Identifica palavras simples (3-10 caracteres) que se leem igual nos dois sentidos.
* **Lógica:** Uso de dois índices (início e fim) que caminham para o centro da palavra comparando os caracteres.

### 3. Detetor Avançado de Palíndromos (Ficheiros e Acentos) 🚀
**O que faz:** Processa ficheiros reais (até 500KB), ignorando acentos, espaços e pontuação.
* **Normalização ISO-8859-1:** Filtro manual que converte caracteres acentuados para a base ASCII (ex: `á` → `a`).
* **Mapeamento `origIdx`:** Técnica de preservação de contexto. Um array auxiliar liga o texto limpo à sua posição original no ficheiro, permitindo imprimir o palíndromo com a formatação original (espaços e acentos preservados).
* **Algoritmo de Expansão Central:** Estratégia de busca $O(n^2)$ que deteta simetria a partir de cada centro possível (casos ímpares e pares).
* **Filtragem de Sub-palíndromos:** Ordenação por comprimento e validação de contenção para garantir que apenas os palíndromos mais abrangentes são exibidos.

---

## 4. Correção e Refatoração de Gestor de Estudantes 📘
**O que faz:** Interface textual para adicionar estudantes, calcular média das notas e listar registos, com gestão dinâmica de memória.
* **Deteção de bugs:** identifica erros de compilação (`scanf`), inicialização não feita e divisão por zero.
* **Gestão de memória:** `malloc` inicial para 10 estudantes, `realloc` ao ultrapassar 10 e `free` ao terminar.
* **Validação de entrada:** notas obrigatoriamente no intervalo 0-20; tratamento de input inválido.
* **Boas práticas:** elimina globals na versão refatorada, funções puras (`calcularMedia`, `listarEstudantes`), passing de parâmetros e documentação interna.

---

## ⚠️ Resolução de Problemas (Troubleshooting)

### Erro: `warning: case label value is less than minimum value for type`
Este aviso ocorria porque o `char` padrão no GCC é assinado (`-128` a `127`). Valores hexadecimais como `0xC0` (192) eram interpretados como negativos ou fora de alcance.
* **Solução Implementada:** Alteração da assinatura da função para `static char removerAcento(unsigned char c)` e uso de literais numéricos no `switch`. Isto garante que o valor seja tratado no intervalo de `0` a `255`.

---

## 5. Calculadora modularizada com header e implementação separada ➗
**Objetivo do enunciado:** Modularizar um pequeno programa em C, organizando interface e implementação.

### Ficheiros criados
* `calculator.h` - interface com protótipos.
* `calculator.c` - implementação das operações.
* `main.c` - programa principal que utiliza `calculator.h`.

### Requisitos da `calculator.h`
* Header guard único e coerente: `CALCULATOR_H`.
* Funções declaradas:
  - `double add(double a, double b);`
  - `double subtract(double a, double b);`
  - `double multiply(double a, double b);`
  - `double divide(double a, double b);`
* Não há implementação no `.h` (só protótipos).
* Formatação consistente e comentários técnicos ao estilo C.

### Ajuste ao enunciado original
O enunciado pedia funções `int multiplicar(int a, int b)` e `int subtrair(int a, int b)`; adaptámos para as versões `double` no projeto porque a calculadora principal trabalha com `double` e inclui divisão com ponto flutuante.

### Justificação do nome do header guard
Escolhi `CALCULATOR_H` porque:
1) é consistente com o nome do ficheiro (`calculator.h`);
2) usa maiúsculas e underscore, padrão de header guards em C;
3) é único no projeto e evita colisões com outros headers da workspace;
4) mantém semântica clara: identifica precisamente o módulo de calculadora.

### Resultado esperado
* `main.c` lê opção e dois números;
* operações são feitas por chamadas a `add/subtract/multiply/divide` via `calculator.h`;
* a compilação pela task genérica se certifica de incluir todos os `*.c` do diretório e evitar `undefined reference`.

---

## 🚀 Como Compilar e Gerir

### No VS Code
* **Build:** `Ctrl + Shift + B`
* **Debug:** `F5` para inspecionar variáveis e ponteiros.

### Fluxo Git (Simplificado)
```bash
# Configurar upstream apenas na primeira vez: git push -u origin main
git add .
git commit -m "feat: detetor de palindromos 2.0 com suporte total a ISO-8859-1"
git push

## 🚀 Padrão de Commits (Conventional Commits)

Neste repositório, utilizo prefixos em minúsculas para manter o histórico limpo:
* `feat:` Novas funcionalidades (ex: suporte a maiúsculas).
* `fix:` Correções de bugs ou warnings de compilação.
* `docs:` Alterações no README ou comentários.
* `refactor:` Melhorias na estrutura do código.

---
*Atualizado em: Março de 2026*