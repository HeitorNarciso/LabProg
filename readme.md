# 📚 Laboratório de Programação (C) - UAb

Este repositório é o meu diário de bordo na aprendizagem de C. Aqui guardo a lógica, os desafios e as soluções encontradas durante o curso na **Universidade Aberta**.

## ⚙️ Configuração do Ambiente
* **Compilador:** GCC via MSYS2 (UCRT64)
* **Automatização:** `tasks.json` configurado com flags de rigor:
  * `-Wall -Wextra -Wpedantic`: Para garantir que nenhum aviso de erro passa despercebido.
  * `-g`: Permite o uso do debugger para encontrar erros de memória.

---

## 📁 Detalhes dos Projetos

### 1. Conversor de Numerais Romanos 🏛️
**O que faz:** Converte uma string (ex: "MCMXCIV") no seu valor inteiro (1994).

**Lógica de Pensamento:**
* **Validação:** Antes de converter, o programa verifica se o numeral é válido. Símbolos como `V, L, D` não podem repetir-se. Símbolos como `I, X, C, M` só podem repetir-se 3 vezes.
* **Algoritmo de Conversão:** * Percorre a string símbolo a símbolo.
  * Se o valor do símbolo atual for menor que o do símbolo seguinte (ex: `IV`), subtraímos o valor atual do total.
  * Caso contrário, somamos o valor ao total.
* **Segurança:** O programa converte tudo para maiúsculas automaticamente para evitar erros de escrita.

### 2. Detetor de Palíndromos 🔄
**O que faz:** Faz a triagem de um ficheiro de texto e encontra palavras que se leem igual nos dois sentidos.

**Lógica de Pensamento:**
* **Manipulação de Ficheiros:** O programa pede o nome do ficheiro, abre-o em modo de leitura (`"r"`) e valida se o ficheiro existe.
* **Filtros de Requisito:** * Ignora palavras com menos de 3 ou mais de 10 caracteres (limpeza de ruído).
  * Usa `tolower()` para que "Ana" e "ana" sejam ambas consideradas palíndromos.
* **Função Booleana:** Criei uma função dedicada que usa dois índices (início e fim) que caminham para o centro da palavra comparando os caracteres.

---

## 🚀 Como Compilar e Gerir

### No VS Code
* **Build:** `Ctrl + Shift + B` (Gera o `.exe` na pasta do ficheiro).
* **Executar:** Abre o terminal e digita `./nome_do_programa.exe`.

### Comandos Git (Terminal)
Para guardar o progresso no GitHub, utilizo sempre esta sequência:
```bash
git add .
git commit -m "tipo: descricao curta do que fiz"
git push