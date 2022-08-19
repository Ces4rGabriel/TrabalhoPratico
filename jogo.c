#include <stdio.h>
#include <stdlib.h>
#include "jogo.h" 

struct jogadas{
    int quantX;
    int quantO;
};

char **alocaTabuleiro(){
    char **Tabuleiro;
    Tabuleiro = (char **) malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
        Tabuleiro[i] = (char *) malloc(3 * sizeof(char));

    return Tabuleiro;
}

void liberaMemoria(char ***jogo){
    for (int i = 0; i < 3; i++)
        free((*jogo)[i]);
    free(*jogo);
}


void entrada(char **jogo){
    getchar();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%c", &jogo[i][j]);
        }
    }
}

int validar(char **jogo){
    int QuantX, QuantO;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            if(jogo[i][j] == 'X')
                QuantX++;

            if(jogo[i][j] == 'O')
                QuantO++;    
        }
    } 

    printf("%d\n", QuantX - QuantO);

    return 0;
}

int vitoria(char **jogo){
    // 1: X ganhou
    // 2: O ganhou
    // 3: Empate
    // 0: Jogo ainda não acabou
    //Game over - row

    for (int i = 0; i < 3; i++){
        if (jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2] && jogo[i][0] != 'V'){
            if (jogo[i][0] == 'X')
                return 1;
            else
                return 2;
        }
    }
    //Game over - col
    for (int j = 0; j < 3; j++){
        if (jogo[0][j] == jogo[1][j] && jogo[1][j] == jogo[2][j] && jogo[0][j] != 'V'){
            if (jogo[0][j] == 'X')
                return 1;
            else
                return 2;
        }
    }
    //game over - diagonal
    if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[0][0] != 'V'){
        if (jogo[0][0] == 'X')
            return 1;
        else
            return 2;
    }
    //game over - diagonal secundária
    if(jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[3][0] != 'V'){
        if(jogo[0][2] == 'X')
            return 1;
        else
            return 2;
    }
    //game over - empate
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(jogo[i][j] == 'V')
                return 0;
        }
    }
    //game over - o jogo não acabou
    return 3;
}

int analisar(char **jogo, int contador){
    int vit = vitoria(jogo);
    switch (vit)
    {
    case 1:
        printf("Tabuleiro %d com vitoria [X]", contador);
        return 1;
        break;
    case 2:
        printf("Tabuleiro %d com vitoria [O]", contador);
        return 1;
        break;
    case 3:
        printf("Tabuleiro %d deu velha", contador);
        return 0;
        break;
    case 0:
        printf("Tabuleiro %d em andamento", contador);
        return -1;
        break;
    }
    return -2;
}
