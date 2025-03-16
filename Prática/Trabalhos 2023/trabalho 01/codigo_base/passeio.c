#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "passeio.h"

// Função para empilhar
int empilha(PILHA p[], int *N, int M, PILHA novo) {
    if (*N < M) {
        p[*N] = novo;
        (*N)++;
        return 1;
    }
    return 0;
}

// Função para desempilhar
PILHA* desempilha(PILHA p[], int *N) {
    if (*N > 0) {
        (*N)--;
        return &p[*N];
    }
    return NULL;
}

// Função para verificar se uma posição é válida
int posicaoValida(int x, int y, int n, int m, bool **tabuleiro) {
    return (x >= 0 && x < n && y >= 0 && y < m && !tabuleiro[x][y]);
}

// Função para verificar se o percurso é fechado
int ePercursoFechado(pos inicial, pos atual, int movimentos[8][2]) {
    for (int i = 0; i < 8; i++) {
        if (atual.x + movimentos[i][0] == inicial.x && atual.y + movimentos[i][1] == inicial.y) {
            return 1;
        }
    }
    return 0;
}

void computa_passeios(bool **tabuleiro) {
    int instancia_num;
    
    // Solicita ao usuário o número da instância
    printf("Digite o número da instância (1 a 10): ");
    scanf("%d", &instancia_num);

    // Verifica se o número da instância é válido
    if (instancia_num < 1 || instancia_num > 10) {
        printf("Número de instância inválido. Deve ser entre 1 e 10.\n");
        return;
    }

    int fechados = 0, abertos = 0, n, m;

    // Montando o caminho para a instância
    char arquivo_instancia[50];
    snprintf(arquivo_instancia, sizeof(arquivo_instancia), "./instancias/%d", instancia_num);

    FILE *file = fopen(arquivo_instancia, "r");

    if (file != NULL) {
        fscanf(file, "%d %d", &n, &m);
        fclose(file);
    } else 
        printf("Arquivo de instância %d não encontrado.\n", instancia_num);
        return;
    
    int M = n * m, N = 0;
    PILHA* pilha = (PILHA*)malloc(M * sizeof(PILHA)); 

    // Movimentos possíveis do cavalo
    int movimentos[8][2] = {
        {-2, -1}, {-1, -2}, {1, -2}, {2, -1},
        {2, 1}, {1, 2}, {-1, 2}, {-2, 1}
    };

    pos inicial = {n-1, 0};
    tabuleiro[inicial.x][inicial.y] = true;

    PILHA primeiroMovimento = {inicial, 1, -1};
    empilha(pilha, &N, M, primeiroMovimento);

    while(N > 0) {
        PILHA *estadoAtual = desempilha(pilha, &N);
        int movido = 0;

        for (int i = estadoAtual->movimento + 1; i < 8; i++) {
            int proxX = estadoAtual->casa.x + movimentos[i][0];
            int proxY = estadoAtual->casa.y + movimentos[i][1];

            if(posicaoValida(proxX, proxY, n, m, tabuleiro)) {
                estadoAtual->movimento = i;
                empilha(pilha, &N, M, *estadoAtual);

                PILHA novoEstado = {{proxX, proxY}, estadoAtual->marcados + 1, -1};
                empilha(pilha, &N, M, novoEstado);
                tabuleiro[proxX][proxY] = true;

                movido = 1;
                break;
            }
        }

        if(!movido) {
            if (estadoAtual->marcados == n * m) {
                if(ePercursoFechado(inicial, estadoAtual->casa, movimentos)) {
                    fechados++;
                } else 
                    abertos++;
            }
            tabuleiro[estadoAtual->casa.x][estadoAtual->casa.y] = false;
        }
    }

    free(pilha);
    printf("%d\n%d\n", fechados, abertos);
    return;
}

int main(int argc, char* argv[]) {
    ///////////////////////////////////////////////////////////
    /////////////////// Leitor de instâncias //////////////////
    ///////////////// Não deve ser modificado /////////////////
    ///////////////////////////////////////////////////////////
    int instancia_num = -1;
    instancia_num = atoi(argv[1]);
    if (instancia_num <= 0 || instancia_num > 20) {
        printf("Para executar o código, digite ./passeio x\nonde x é um número entre 1 e 20 que simboliza a instância utilizada\n");
        exit(0);
    }
    
    // Tabuleiro do jogo
    bool **tabuleiro = ler_instancia(instancia_num);

    computa_passeios(tabuleiro);

    return (1);
}

bool **ler_instancia(int instancia_num) {
    int n, m;
    int i;
    
    // Montando o caminho para a instancia
    char *arquivo_instancia = "./instancias/";
    asprintf(&arquivo_instancia, "%s%d", arquivo_instancia, instancia_num);
    
    // Ponteiro para a instância
    FILE* file;
 
    // Abrindo a instância em modo leitura
    file = fopen(arquivo_instancia, "r");
 
    if (NULL == file) {
        printf("Arquivo de instância não encontrado. Verifique se sua estrutura de diretórios está EXATAMENTE igual ao do Github\n");
        exit(0);
    }

    // Lendo o arquivo da instância
    fscanf (file, "%d", &n);
    fscanf (file, "%d", &m);

    // Alocando o tabuleiro dinamicamente
    // Usando calloc ao invés de malloc para inicializar todo o tabuleiro com zeros
    bool** tabuleiro = (bool**)calloc(n, sizeof(bool*));
    for (i = 0; i < n; i++) {
        tabuleiro[i] = (bool*)calloc(m, sizeof(bool));
    }

    return tabuleiro;
}