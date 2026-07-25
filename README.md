# ⚙️ Teoria da Computação, Linguagens e Compiladores

Bem-vindo ao repositório de **Teoria da Computação, Linguagens e Compiladores**!
Este repositório contém o trabalho final da disciplina: um compilador para uma linguagem imperativa simples, gerando código para uma Máquina Virtual Simples (MVS).

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white) ![Lex/Yacc](https://img.shields.io/badge/Lex%2FYacc-Flex%20%2B%20Bison-blue?style=for-the-badge)

---

## 🏗️ Estrutura do Projeto

| Arquivo | Descrição |
|---|---|
| `lexico.l` | Analisador léxico (Flex) |
| `sintatico.y` | Analisador sintático e geração de código (Bison) |
| `tree.c` | Construção e manipulação da árvore sintática |
| `utils.c` | Funções auxiliares |
| `mvs.c` | Simulador da Máquina Virtual Simples (MVS), que executa o código objeto gerado pelo compilador |
| `teste1.simples` | Programa de exemplo na linguagem-fonte (`.simples`) |
| `trabalho.pdf` | Enunciado do trabalho |
| `makefile` | Script de build |

---

## 🖥️ Como funciona

O compilador lê um programa escrito na linguagem-fonte (arquivos `.simples`, uma linguagem imperativa com variáveis inteiras, estruturas condicionais e de repetição), realiza análise léxica e sintática, e gera código objeto para a MVS — uma máquina virtual de pilha com instruções como `CRVG`, `SOMA`, `DSVF`, `ESCR`, entre outras. O simulador (`mvs.c`) executa esse código objeto.

## 🔧 Compilar e rodar

```bash
make
./compilador teste1.simples
```

---

## 🎯 Objetivo do Repositório

Este repositório documenta o trabalho final da disciplina de Teoria da Computação, Linguagens e Compiladores, aplicando conceitos de análise léxica, sintática e geração de código.

---

## 👤 Autor

Este repositório foi desenvolvido por **[Jeann Victor](https://github.com/JeannVictor)** como parte da disciplina de **Teoria da Computação, Linguagens e Compiladores**.

---

## 📜 Licença

Este projeto está licenciado sob a [MIT License](./LICENSE). Consulte o arquivo LICENSE para mais detalhes.

---

☮️ **Paz, Amor e Empatia!**
