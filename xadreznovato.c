

// Código do nível Novato
#include <stdio.h>

#define TAM 8

int main() {
    int tabuleiro[TAM][TAM] = {0};
    int x = 3, y = 3; // Posição inicial em D4

    for (int i = 1; i < TAM; i++) {
        if (x + i < TAM && y + i < TAM) tabuleiro[x + i][y + i] = 1;
        if (x - i >= 0 && y - i >= 0) tabuleiro[x - i][y - i] = 1;
        if (x + i < TAM && y - i >= 0) tabuleiro[x + i][y - i] = 1;
        if (x - i >= 0 && y + i < TAM) tabuleiro[x - i][y + i] = 1;
    }

    for (int i = y + 1; i < TAM; i++) tabuleiro[x][i] = 2;
    for (int i = y - 1; i >= 0; i--) tabuleiro[x][i] = 3;

    printf("Tabuleiro - Nivel Novato:\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            if (i == x && j == y) printf("Q ");
            else if (tabuleiro[i][j] == 1) printf("B ");
            else if (tabuleiro[i][j] == 2) printf("T ");
            else if (tabuleiro[i][j] == 3) printf("R ");
            else printf(". ");
        }
        printf("\n");
    }

    return 0;
}




