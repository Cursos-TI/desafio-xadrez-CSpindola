#include <stdio.h>

#define TAM 8 // Definição do tamanho do tabuleiro (8x8 ; 64 casas)

// Função para imprimir o tabuleiro com marcação dos movimentos
void imprimirTabuleiro(int tabuleiro[TAM][TAM]) {
    printf("  A B C D E F G H\n");
    for (int i = 0; i < TAM; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < TAM; j++) {
            if (tabuleiro[i][j] == 1)
                printf("* ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("\n");
}

// Função para limpar o tabuleiro (zerar todas as casas)
void limparTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++)
        for (int j = 0; j < TAM; j++)
            tabuleiro[i][j] = 0;
}

// -----------------------------
// Movimentação do Bispo (diagonais)
// -----------------------------
void moverBispoRecursivo(int tabuleiro[TAM][TAM], int x, int y, int dx, int dy) {
    int nx = x + dx;
    int ny = y + dy;
    if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
        tabuleiro[nx][ny] = 1;
        moverBispoRecursivo(tabuleiro, nx, ny, dx, dy); // chamada recursiva
    }
}

void moverBispo(int tabuleiro[TAM][TAM], int x, int y) {
    // Marca a posição inicial
    tabuleiro[x][y] = 1;
    // Chama recursivamente para cada diagonal
    moverBispoRecursivo(tabuleiro, x, y, 1, 1);   // baixo-direita
    moverBispoRecursivo(tabuleiro, x, y, 1, -1);  // baixo-esquerda
    moverBispoRecursivo(tabuleiro, x, y, -1, 1);  // cima-direita
    moverBispoRecursivo(tabuleiro, x, y, -1, -1); // cima-esquerda
}

// -----------------------------
// Movimentação da Torre (linhas e colunas)
// -----------------------------
void moverTorre(int tabuleiro[TAM][TAM], int x, int y) {
    // Marca a posição inicial
    tabuleiro[x][y] = 1;

    // Movimento na vertical
    for (int i = 0; i < TAM; i++)
        if (i != x) tabuleiro[i][y] = 1;

    // Movimento na horizontal
    for (int j = 0; j < TAM; j++)
        if (j != y) tabuleiro[x][j] = 1;
}

// -----------------------------
// Movimentação da Rainha (torre + bispo)
// -----------------------------
void moverRainha(int tabuleiro[TAM][TAM], int x, int y) {
    moverTorre(tabuleiro, x, y);
    moverBispo(tabuleiro, x, y);
}

// -----------------------------
// Movimentação do Cavalo
// -----------------------------
void moverCavalo(int tabuleiro[TAM][TAM], int x, int y) {
    tabuleiro[x][y] = 1;

    // Possíveis movimentos em L (8 direções)
    int dx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
    int dy[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

    for (int i = 0; i < 8; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < TAM && ny >= 0 && ny < TAM) {
            if (tabuleiro[nx][ny] == 1) continue; // já marcado
            tabuleiro[nx][ny] = 1;
        }
    }
}

// -----------------------------
// Função principal
// -----------------------------
int main() {
    int tabuleiro[TAM][TAM];
    int x = 3, y = 3; // Posição inicial da peça (linha 4, coluna D)

    // B I S P O
    printf("Movimentos do Bispo a partir de D4:\n");
    limparTabuleiro(tabuleiro);
    moverBispo(tabuleiro, x, y);
    imprimirTabuleiro(tabuleiro);

    // T O R R E
    printf("Movimentos da Torre a partir de D4:\n");
    limparTabuleiro(tabuleiro);
    moverTorre(tabuleiro, x, y);
    imprimirTabuleiro(tabuleiro);

    // R A I N H A
    printf("Movimentos da Rainha a partir de D4:\n");
    limparTabuleiro(tabuleiro);
    moverRainha(tabuleiro, x, y);
    imprimirTabuleiro(tabuleiro);

    // C A V A L O
    printf("Movimentos do Cavalo a partir de D4:\n");
    limparTabuleiro(tabuleiro);
    moverCavalo(tabuleiro, x, y);
    imprimirTabuleiro(tabuleiro);

    return 0;
}
