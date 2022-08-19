#include <stdio.h>
#include "jogo.h"

int main(){
    int qtdTabuleiro, check, contador = 0;
    Jogadas *jogadores;
    char **jogo;
    //numero de tabuleiros a ser analisado
    scanf("%d", &qtdTabuleiro);
    //main loop
    while (contador < qtdTabuleiro){
        jogo = alocaTabuleiro();
        entrada(jogo);
        //Checa se o jogo é válido
        check = validar(jogo, jogadores);
        if(check == 1){
            printf("Tabuleiro %d invalido\n", contador+1);
            return 0;
        }
        //função que analisa e da o resultado
        analisar(jogo, contador, jogadores); 
        contador++;
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
