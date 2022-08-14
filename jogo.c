#include "jogo.h"

void entrada(char jogo[][3]){
    //entrada do vetor
    printf("Entrando com dados\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            scanf("%c", &jogo[i][j]);
        }
    }
}

void imprimir(char jogo[][3]){
    //impressão do vetor
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf("%c ", jogo[i][j]);
        }
        printf("\n");
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
    //Função verifica quantidade de X
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(T[i][j] == 120 || T[i][j] == 88){
                QuantX++;
            }
        }
     }

    //Função verifica quantidade de O
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(T[i][j] == 79 || T[i][j] == 111){
                QuantO++;
            }
        }
     }

    //Função verifica quantidade de V
     for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(T[i][j] == 86 || T[i][j] == 118){
                QuantV++;
            }
        }
     }
    printf("Quantidade de V: %d, X: %d, e O: %d\n", QuantV, QuantX, QuantO);

    if((QuantX > 5)|| (QuantO > 5) || (QuantX >= 5 && QuantO < 4) || (QuantO>= 5 && QuantX < 4) ){
        printf("Jogo Inválido\n");
    }
}

int vitoria(char jogo[][3]){
    /*
    if((T[0][0] == T[1][1])&&(T[1][1] == T[2][2]) || (T[0][2] == T[1][1])&&(T[1][1] == T[2][0]) ||((T[0][0] == T[0][1])&&(T[0][1] == T[0][2])) || ((T[1][0] == T[1][1])&&(T[1][1] == T[1][2])) || ((T[2][0] == T[2][1])&&(T[2][1] == T[2][2])) || ((T[0][0] == T[1][0])&&(T[1][0]==T[2][0])) || ((T[0][1] == T[1][1])&&(T[1][1]==T[2][1])) || ((T[0][2] == T[1][2])&&(T[1][2]==T[2][2]))){
        printf("Jogo vencido\n");
    }
    */
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
        return -1;  //uma vitoria
    //Game over - col
    for (int j = 0; j < 3; j++){
        if (jogo[0][j] == jogo[1][j] && jogo[1][j] == jogo[2][j] && jogo[0][j] != 'V'){
            vcol++;
        }
    }
    //verificar mais de uma vitoria na coluna
    if(vcol > 1)
        return -1;  //uma vitoria
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