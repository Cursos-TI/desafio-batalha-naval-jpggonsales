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


    // HABILIDADES

    // Matrizes das habilidades (5x5)
    int cone[5][5];
    int cruz[5][5];
    int octaedro[5][5];

    // Construção do CONE (formato abrindo para baixo)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            cone[i][j] = 0;

            if (i == 0 && j == 2) cone[i][j] = 1;
            if (i == 1 && (j >= 1 && j <= 3)) cone[i][j] = 1;
            if (i == 2 && (j >= 0 && j <= 4)) cone[i][j] = 1;
        }
    }

    // Construção da CRUZ (centro forte)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            cruz[i][j] = 0;

            if (i == 2) cruz[i][j] = 1;
            if (j == 2) cruz[i][j] = 1;
        }
    }

    // Construção do OCTAEDRO (losango)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            octaedro[i][j] = 0;

            // cálculo da distância absoluta

            int centro = 2;
            int distI, distJ;

            if (i - centro >= 0)
                distI = i - centro;
            else
                distI = -(i - centro);

            if (j - centro >= 0)
                distJ = j - centro;
            else
                distJ = -(j - centro);

            if (distI + distJ <= 2) {
                octaedro[i][j] = 1;
            }
        }
    }


    // SOBREPOSIÇÃO

    // Ponto de origem das habilidades
    int origemConeL = 6, origemConeC = 6;  
    int origemCruzL = 2, origemCruzC = 3;  
    int origemOctL = 5, origemOctC = 1;

    // CONE
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (cone[i][j] == 1) {

                int L = origemConeL + (i - 2);
                int C = origemConeC + (j - 2);

                if (L >= 0 && L < 10 && C >= 0 && C < 10) {
                    if (tabuleiro[L][C] == 0)
                        tabuleiro[L][C] = 5;
                }
            }
        }
    }

    // CRUZ
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (cruz[i][j] == 1) {

                int L = origemCruzL + (i - 2);
                int C = origemCruzC + (j - 2);

                if (L >= 0 && L < 10 && C >= 0 && C < 10) {
                    if (tabuleiro[L][C] == 0)
                        tabuleiro[L][C] = 5;
                }
            }
        }
    }

    // OCTAEDRO
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {

            if (octaedro[i][j] == 1) {

                int L = origemOctL + (i - 2);
                int C = origemOctC + (j - 2);

                if (L >= 0 && L < 10 && C >= 0 && C < 10) {
                    if (tabuleiro[L][C] == 0)
                        tabuleiro[L][C] = 5;
                }
            }
        }
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