#include <stdio.h>
#include "jogo.h"

int main(){
    int qtdTabuleiro, check, contador = 0;
    char *jogo;
    char **Mjogo;
    TADTabuleiro *tab;
    //numero de tabuleiros a ser analisado
    scanf("%d", &qtdTabuleiro);
    //main loop
    while (contador < qtdTabuleiro){
        alocaTADTabuleiro(&tab);
        contador++;
        Mjogo = alocaVetor();
        alocaTabuleiro(&tab);
        entrada(jogo);
        
        //Checa se o jogo é válido
        check = validar(Mjogo, tab);
        if(check == 1){
            printf("Tabuleiro %d invalido\n", contador);
            continue;
        }
        //função que analisa e da o resultado
        //analisar(MJogo, contador, jogadores);
        
        liberaMemoria(&jogo);
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
