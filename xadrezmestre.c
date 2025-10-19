
// Código do nível Mestre
#include <stdio.h>

#define TAM 8


    int tabuleiro[TAM][TAM];
    int x = 3, y = 3; // Posição inicial da peça (linha 4, coluna D)

void limparTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

void moverBispoRec(int tabuleiro[TAM][TAM], int x, int y, int dx, int dy) {
    int nx = x + dx;
    int ny = y + dy;

    if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM)
        return;

    tabuleiro[nx][ny] = 1;
    moverBispoRec(tabuleiro, nx, ny, dx, dy); // recursão
}

void moverBispo(int tabuleiro[TAM][TAM], int x, int y) {
    moverBispoRec(tabuleiro, x, y, 1, 1);
    moverBispoRec(tabuleiro, x, y, 1, -1);
    moverBispoRec(tabuleiro, x, y, -1, 1);
    moverBispoRec(tabuleiro, x, y, -1, -1);
}

void moverCavaloAvancado(int tabuleiro[TAM][TAM], int x, int y) {
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if (dx == 0 || dy == 0) continue;
            if (dx * dx + dy * dy != 5) continue;

            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM)
                continue;

            tabuleiro[nx][ny] = 3;
        }
    }
}

void imprimirTabuleiro(int tabuleiro[TAM][TAM], int x, int y) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == x && j == y) printf("Q ");
            else if (tabuleiro[i][j] == 1) printf("B ");
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
    moverBispo(tabuleiro, x, y);
    moverCavaloAvancado(tabuleiro, x, y);
    imprimirTabuleiro(tabuleiro, x, y);

    return 0;
}

