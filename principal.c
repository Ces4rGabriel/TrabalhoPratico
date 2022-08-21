#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main(){
    int qtdTabuleiro, contador = 0, check;
    char valor;
    char jogo[9];
    TADTabuleiro *tab;
    //numero de tabuleiros a ser analisado
    scanf("%d", &qtdTabuleiro);
    //main loop
    while (contador < qtdTabuleiro){
        alocaTadTabuleiro(&tab);
        contador++;
        alocaTabuleiro(&tab);
        entrada(jogo, &tab);
        mostraJogo(tab);
        check = validar(tab);
        if(check == 1){
            printf("jogo %d invalido\n", contador);
        }else{
           //valor = vitoria(tab);
           //printf("Tabuleiro %d ganhador: %c\n",contador, valor); 
           analisar(contador, tab);
        }
    }
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
