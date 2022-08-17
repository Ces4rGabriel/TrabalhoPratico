#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtdTabuleiro, QuantX = 0, QuantO = 0, vit, check, contador = 0;
    char **jogo;
    //numero de tabuleiros a ser analisado
    scanf("%d", &qtdTabuleiro);
    //main loop
    while (contador < qtdTabuleiro){
        jogo = alocaTabuleiro();
        entrada(jogo);
        check = validar(jogo, &QuantX, &QuantO);
        //função que o resultado
        vit = vitoria(jogo);
        //função que recebe jogo, v, contador, quantX e quantO e imprime o resultado   
        contador++;
        liberaMemoria(jogo);
    }
    imprimir(T);
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
