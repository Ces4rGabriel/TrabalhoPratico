#include <stdio.h>
#include <stdlib.h>



int main(){
    char T[3][3] = {'V', 'V', 'V', 'X', 'X', 'X', 'X', 'X', 'X'};
    int QuantX = 0, QuantO = 0, QuantV = 0;
    int v;
    v = vitoria(T);
    printf("%d\n", v);
    return 0;
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
