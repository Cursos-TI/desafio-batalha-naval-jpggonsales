#include <stdio.h>

int main(){
//Vetor unidimensional para os navios
    int naviohori[3] = {3,3,3};   // Navio horizontal (3 células)
    int naviovert[3] = {3,3,3};   // Navio vertical   (3 células)
//Matriz para o tabuleiro
    int tabuleiro[10][10] = {
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };

    //Posicionamento dos navios

    // Coordenadas escolhidas 
    int linhaH = 4, colunaH = 2;  // Navio horizontal
    int linhaV = 1, colunaV = 7;  // Navio vertical

    // Colocar navio horizontal
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = naviohori[i];
    }

    // Colocar navio vertical
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = naviovert[i];
    }

    //Impressão do tabuleiro

    printf("\n     TABULEIRO\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");

    for (int i = 0; i < 10; i++) {
        printf("%d  ", i);  // Número da linha
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}