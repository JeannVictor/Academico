# Trabalho — Missionários e Canibais

![Prolog](https://img.shields.io/badge/Prolog-blue)

Trabalho de Programação Lógica (Prof. Luiz Eduardo da Silva). Generalização do problema clássico dos Missionários e Canibais: dado um número configurável de missionários e canibais e uma capacidade de barco configurável, encontra (por busca em largura) a sequência de travessias que leva todos de uma margem a outra sem que, em nenhum momento, canibais fiquem em maioria numa margem.

Arquivo único: `trabalho_prolog_jeann.pl`.

---

## Configuração

Os parâmetros do problema são definidos no topo do arquivo:

```prolog
total(3,3).          % número de missionários e canibais
capacidade_barco(2). % capacidade do barco
```

---

## Como rodar

Com SWI-Prolog instalado:

```bash
swipl trabalho_prolog_jeann.pl
```

No interpretador, execute a busca com:

```prolog
?- resolva.
```
