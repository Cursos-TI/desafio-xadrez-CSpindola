
// Código do nível Aventureiro
#include <stdio.h>

#define TAM 8



    int tabuleiro[TAM][TAM];
    int x = 3, y = 3; // Posição inicial da peça (linha 4, coluna D)
void limparTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void moverBispo(int tabuleiro[TAM][TAM], int x, int y) {
    for (int i = 1; i < TAM; i++) {
        if (x + i < TAM && y + i < TAM) tabuleiro[x + i][y + i] = 1;
        if (x - i >= 0 && y - i >= 0) tabuleiro[x - i][y - i] = 1;
        if (x + i < TAM && y - i >= 0) tabuleiro[x + i][y - i] = 1;
        if (x - i >= 0 && y + i < TAM) tabuleiro[x - i][y + i] = 1;
    }
}

void moverTorre(int tabuleiro[TAM][TAM], int x, int y) {
    for (int i = 0; i < TAM; i++) {
        if (i != x) tabuleiro[i][y] = 2;
        if (i != y) tabuleiro[x][i] = 2;
    }
}

void moverRainha(int tabuleiro[TAM][TAM], int x, int y) {
    moverBispo(tabuleiro, x, y);
    moverTorre(tabuleiro, x, y);
}

void moverCavalo(int tabuleiro[TAM][TAM], int x, int y) {
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM)
            tabuleiro[nx][ny] = 3;
    }
}

void imprimirTabuleiro(int tabuleiro[TAM][TAM], int x, int y) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == x && j == y) printf("Q ");
            else if (tabuleiro[i][j] == 1) printf("B ");
            else if (tabuleiro[i][j] == 2) printf("T ");
            else if (tabuleiro[i][j] == 3) printf("C ");
            else printf(". ");
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int x = 3, y = 3;

    limparTabuleiro(tabuleiro);
    moverRainha(tabuleiro, x, y);
    moverCavalo(tabuleiro, x, y);
    imprimirTabuleiro(tabuleiro, x, y);

    return 0;
}
