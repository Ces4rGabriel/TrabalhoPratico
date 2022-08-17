#include "jogo.h"

char **alocaTabuleiro(){
    int **m;
    m = (int **) malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++){
        m[i] = (int *) malloc(3 * sizeof(char));
    }
}

void liberaMemoria(char **jogo){
    for (int i = 0; i < 3; i++)
        free(jogo[i]);
    free(jogo);
}


void entrada(char jogo[][3]){
    getchar();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%c", &jogo[i][j]);
        }
    }
}

int validar(char jogo[][3], int *QuantX,int *QuantO){

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            if((jogo[i][j] != 'X') || (jogo[i][j] != 'O') || (jogo[i][j] != 'V'))
                return 1;

            if(jogo[i][j] == 'X')
                *QuantX++;

            if(jogo[i][j] == 'O')
                *QuantO++;    
        }
    } 

    if((QuantX > 5)||(QuantO > 5) (QuantX >= 5 && Quant0 < 4) || (QuantO >= 5 && QuantX < 4)){
        return -1;
    }

}

int vitoria(char jogo[][3]){
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