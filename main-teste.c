#include <stdio.h>
#include <stdlib.h>


int main(){
    char T[3][3];
    int QuantX = 0, QuantO = 0, QuantV = 0;
    
    entrada(T);
    imprimir(T);


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

       //Função verifica estado do jogo
     printf("Quantidade de V: %d, X: %d, e O: %d\n", QuantV, QuantX, QuantO);

      if((QuantX > 5)|| (QuantO > 5) || (QuantX >= 5 && QuantO < 4) || (QuantO>= 5 && QuantX < 4) ){
        printf("Jogo Inválido\n");
      }

      if((T[0][0] == T[1][1])&&(T[1][1] == T[2][2]) || (T[0][2] == T[1][1])&&(T[1][1] == T[2][0]) ||((T[0][0] == T[0][1])&&(T[0][1] == T[0][2])) || ((T[1][0] == T[1][1])&&(T[1][1] == T[1][2])) || ((T[2][0] == T[2][1])&&(T[2][1] == T[2][2])) || ((T[0][0] == T[1][0])&&(T[1][0]==T[2][0])) || ((T[0][1] == T[1][1])&&(T[1][1]==T[2][1])) || ((T[0][2] == T[1][2])&&(T[1][2]==T[2][2]))){
        printf("Jogo vencido\n");
      }


}

/*
[0][0] [0][1] [0][2]
[1][0] [1][1] [1][2]
[2][0] [2][1] [2][2]

Maneiras de ganhar:
1º primeira coluna
2º segunda coluna
3º terceira coluna
4º Diagonal Principal
5º Diagonal secundária
6º primeira linha
7º segunda linha
8º terceira linha
*/
