#include <stdio.h>
#include "jogo.h"

int main(){
    int qtdTabuleiro, resultado, check, contador = 0;
    Jogadas *jogadores;
    char **jogo;
    //numero de tabuleiros a ser analisado
    scanf("%d", &qtdTabuleiro);
    //main loop
    while (contador < qtdTabuleiro){
       jogo = alocaTabuleiro();
        entrada(jogo);
        check = validar(jogo);

        if(check == 1)
            return 0;
        //função que o resultado
        resultado = analisar(jogo, contador);
        //função que recebe jogo, v, contador, quantX e quantO e imprime o resultado   
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
