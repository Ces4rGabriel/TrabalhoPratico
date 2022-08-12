#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

void entrada(char jogo[][3]){
    //entrada do vetor
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf("%c", &jogo[i][j]);
        }
    }
}
void validar(char jogo[][3]){
    //validar o vetor do jogo da velha
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (jogo[i][j] != 'X' && jogo[i][j] != 'O' && jogo[i][j] != 'V'){
                printf("\nJogo invalido\n");
                exit(0);
            }
        }
    }
}