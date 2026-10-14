#include <stdio.h>
#include <stdlib.h>

void preencherTabuleiro(char tabuleiro[3][3]);
void exibirTabuleiro(char tabuleiro[3][3]);
int tabuleiroCheio(char tabuleiro[3][3]);
int verificarGanhador(char tabuleiro[3][3]);

int main() {
    char tabuleiro[3][3];
    preencherTabuleiro(tabuleiro);
    
    int jogador = 1;
    
    while (1) {
        exibirTabuleiro(tabuleiro);
        
        int jogadaValida = 0;
        char linha;
        int coluna;
        int i = -1, j = -1;
        
        while (!jogadaValida) {
            printf("Jogador %d, informe sua jogada: ", jogador);
            
            if (scanf("%c %d", &linha, &coluna) != 2) {
                printf("Jogada invalida!\n");
                while (getchar() != '\n');
                continue;
            }
            
            while (getchar() != '\n');
            
            if (linha == 'A' || linha == 'a') {
                i = 0;
            } else if (linha == 'B' || linha == 'b') {
                i = 1;
            } else if (linha == 'C' || linha == 'c') {
                i = 2;
            } else {
                i = -1;
            }
            
            j = coluna - 1;
            
            if (i >= 0 && i < 3 && j >= 0 && j < 3 && tabuleiro[i][j] == ' ') {
                jogadaValida = 1;
            } else {
                printf("Jogada invalida!\n");
            }
        }
        
        if (jogador == 1) {
            tabuleiro[i][j] = 'X';
        } else {
            tabuleiro[i][j] = '0';
        }
        
        if (verificarGanhador(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("O Jogador %d venceu!\n", jogador);
            break;
        }
        
        if (tabuleiroCheio(tabuleiro)) {
            exibirTabuleiro(tabuleiro);
            printf("Empate!\n");
            break;
        }
        
        if (jogador == 1) {
            jogador = 2;
        } else {
            jogador = 1;
        }
    }
    return 0;
}

void preencherTabuleiro(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

void exibirTabuleiro(char tabuleiro[3][3]) {
    printf("\n    1   2   3\n");
    printf(" A  %c | %c | %c \n", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("   ---|---|---\n");
    printf(" B  %c | %c | %c \n", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("   ---|---|---\n");
    printf(" C  %c | %c | %c \n\n", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

int tabuleiroCheio(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 0;
            }
        }
    }
    return 1;
}

int verificarGanhador(char tabuleiro[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][1] == tabuleiro[i][2]) {
            return 1;
        }
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[1][i] == tabuleiro[2][i]) {
            return 1;
        }
    }
    
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][2]) {
        return 1;
    }
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[1][1] == tabuleiro[2][0]) {
        return 1;
    }
    
    return 0;
}