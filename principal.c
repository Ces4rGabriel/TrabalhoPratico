#include <stdio.h>
#include <stdlib.h>
#include "jogo.h"

int main(){
    char *jogo;
    int qtdTabuleiro, tabuleiroVal, contador = 0;
    //ENTRADA DO NUMERO DE TABULEIROS
    scanf("%d ", &qtdTabuleiro);
    //MAIN LOOP
    while (contador < qtdTabuleiro){
        contador++; //INCREMENTA O CONTADOR

        //ALOCA STRUCT DE JOGADAS
        Jogadas *jogadas = (Jogadas *) malloc(sizeof(Jogadas*));
        
        //ALOCA TABULEIRO
        jogo = alocaTabuleiro();

        //ENTRADA DO TABULEIRO
        entrada(jogo);

        //VALIDAR ENTRADA
        tabuleiroVal = 0;
        tabuleiroVal =  validarEntrada(jogo, jogadas);
        if(tabuleiroVal == 1){
            printf("Tabuleiro %d invalido\n", contador);
        }else{
            //ANALISAR O TABULEIRO E DA A RESPOSTA
            analisar(jogo, contador, jogadas);
        }
        //LIBERAR MEMORIA
        free(jogo);
        free(jogadas);
    }   
    return 0;
}