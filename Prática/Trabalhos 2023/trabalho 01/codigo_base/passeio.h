#ifndef _H_PASSEIO
#define _H_PASSEIO

// Implementar qualquer struct que for necessária aqui
// Estrutura para representar uma posição no tabuleiro
typedef struct pos_ {
    int x, y;
} pos;

// Estrutura para representar o estado de um movimento na pilha
typedef struct pilhas {
    pos casa;          // Posição atual
    int marcados;      // Número de casas visitadas
    int movimento;     // Último movimento tentado (0-7)
} PILHA;


bool **ler_instancia(int instancia_num);
void computa_passeios(bool **tabuleiro);

int empilha(PILHA p[], int *N, int M, PILHA novo);
PILHA* desempilha(PILHA p[], int *N);
int posicaoValida(int x, int y, int n, int m, bool **tabuleiro);
int ePercursoFechado(pos inicial, pos atual, int movimentos[8][2]);


#endif // _H_PASSEIO