#include <stdio.h>
#include <stdlib.h>
#include "jogo.h" 
#include <string.h>
struct jogadas{
    int quantX;
    int quantO;
};

char *alocaTabuleiro(){
    char *Tabuleiro;
    Tabuleiro = (char *) malloc(9 * sizeof(char));
    return Tabuleiro;
}

void entrada(char *jogo){
    scanf("%s",jogo);
}
int validarEntrada(char *jogo, Jogadas *jog){
    jog->quantX = 0;
    jog->quantO = 0;
    int diferenca;

    for(int i = 0; i < 9; i++){
        if(jogo[i] == 'X')
            jog->quantX++;
        else if(jogo[i] == 'O')
            jog->quantO++;
    }
    diferenca = abs(jog->quantX - jog->quantO);
    if(diferenca > 1)
        return 1;
    else
        return 0;
}

char vitoria(char *jogo){
    int vitorias[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int cv = 0;
    char aux;
    //verificar vitoria
    for (int i = 0; i < 8; i++){
        if(jogo[vitorias[i][0]] != 'V' && jogo[vitorias[i][0]] == jogo[vitorias[i][1]] && jogo[vitorias[i][0]] == jogo[vitorias[i][2]]){
            aux = jogo[vitorias[i][2]];
            cv++;
        }
    }
    //verificar mais de um trinca
    if(cv == 1){
        return aux;
    }
    else if(cv > 1){
        return 'M';
    }
    //Verificar casas vazias
    for(int i = 0; i < 9; i++){
        if(jogo[i] == 'V')
            return 'E';
    }
    return 'V';
}

void analisar(char *jogo, int contador, Jogadas *jogadas){
    char vit = vitoria(jogo);
    switch (vit)
    {
    case 'X':
        printf("Tabuleiro %d com vitoria [X]\n", contador);
        break;
    case 'O':
        printf("Tabuleiro %d com vitoria [O]\n", contador);
        break;
    case 'V':
        printf("Tabuleiro %d deu velha\n", contador);
        break;
    case 'M':
        printf("Tabuleiro %d invalido", contador);
        break;
    case 'E':
        //para jogador indefinido x = o
        if (jogadas->quantX == jogadas->quantO){
            printf("Tabuleiro %d em andamento [proximo jogador indefinido]\n", contador);
        }
        else if (jogadas->quantX < jogadas->quantO){
            printf("Tabuleiro %d em andamento [X: ", contador);
            mestre(jogo, 'X');
            printf("]\n");
        }
        else if (jogadas->quantX > jogadas->quantO){
            printf("Tabuleiro %d em andamento [O: ", contador);
            mestre(jogo, 'O');
            printf("]\n");
        }
        break;
    }    
}
//detectar jogada mestre
void mestre(char *jogo, char jogador){
    int jm = 0;
    for(int i = 8; i >= 0; i--){
        if(jogo[i] == 'V'){
            jogo[i] = jogador;
            if (vitoria(jogo) == jogador){
                imprimirmestre(i);
                jm++;
            }
            jogo[i] = 'V';
        }
    }
    if (jm == 0)
        printf("sem jogada mestre");
}
void imprimirmestre(int i){
    switch (i)
    {
    case 0:
        printf("(1,1)");
        break;
    case 1:
        printf("(1,2)");
        break;
    case 2:
        printf("(1,3)");
        break;
    case 3:
        printf("(2,1)");
        break;
    case 4:
        printf("(2,2)");
        break;
    case 5:
        printf("(2,3)");
        break;
    case 6:
        printf("(3,1)");
        break;
    case 7:
        printf("(3,2)");
        break;
    case 8:
        printf("(3,3)");
        break;
    }
}