#include "jogo.h"

void entrada(char jogo[][3]){
    //entrada do vetor
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
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
    // -2 = velha
    // -1 = muitas vitorias
    // 1 = vitoria

    char temp;
    int vrow = 0, vcol = 0, vdiag1 = 0, vdiag2 = 0;
    int vitoria = -2;//velha
    //Game over - row
    for (int i = 0; i < 3; i++){
        if (jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2] && jogo[i][0] != 'V'){
            vrow++;
        }
    }
    //verificar mais de uma vitoria na linha
    if(vrow > 1)
        return -1;  //mais de uma vitoria
    //Game over - col
    for (int j = 0; j < 3; j++){
        if (jogo[0][j] == jogo[1][j] && jogo[1][j] == jogo[2][j] && jogo[0][j] != 'V'){
            vcol++;
        }
    }
    //verificar mais de uma vitoria na coluna
    if(vcol > 1)
        return -1;  //mais de uma vitoria
    //game over - diagonal
    for (int i = 0; i < 3; i++){
        if (jogo[i][i] == jogo[i][i+1] && jogo[i][i+1] == jogo[i][i+2] && jogo[i][i] != 'V'){
            vdiag1++;
        }
    }
    //game over - diagonal secundária
    for(int i = 0; i < 3; i++){
        if(jogo[i][2-i] == jogo[i][1-i] && jogo[i][1-i] == jogo[i][0-i] && jogo[i][2-i] != 'V'){
            vdiag2++;
        }
    }
    //verificar se existe mais de uma vitoria
    if (vdiag2+vdiag1+vrow+vcol == 1)
        return 1;   //uma vitoria
    else
        return -1;  //mais de uma vitoria
    
    return vitoria;
}