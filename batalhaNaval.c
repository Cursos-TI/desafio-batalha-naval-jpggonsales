#include <stdio.h>

int main() {

    // Navios (3 células cada)
    int naviohori[3] = {3,3,3};     // Horizontal
    int naviovert[3] = {3,3,3};     // Vertical
    int naviodiag1[3] = {3,3,3};    // Diagonal 
    int naviodiag2[3] = {3,3,3};    // Diagonal 

    // Tabuleiro 10x10 inicializado com água
    int tabuleiro[10][10] = {0};

    // Coordenadas dos navios
    int linhaH = 4, colunaH = 2;  // Horizontal
    int linhaV = 1, colunaV = 7;  // Vertical
    int linhaD1 = 0, colunaD1 = 0;  // Diagonal 
    int linhaD2 = 9, colunaD2 = 0;  // Diagonal 


    // Posicionar navio horizontal

    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaH][colunaH + i] = naviohori[i];
    }

  
    // Posicionar navio vertical
  
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaV + i][colunaV] = naviovert[i];
    }

  
    // Posicionar navio diagonal 
    
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD1 + i][colunaD1 + i] = naviodiag1[i];
    }

   
    // Posicionar navio diagonal 
    
    for (int i = 0; i < 3; i++) {
        tabuleiro[linhaD2 - i][colunaD2 + i] = naviodiag2[i];
    }

    
    // Impressão do tabuleiro
    
    printf("\n     TABULEIRO\n");
    printf("   0 1 2 3 4 5 6 7 8 9\n");

    for (int i = 0; i < 10; i++) {
        printf("%d  ", i);
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}