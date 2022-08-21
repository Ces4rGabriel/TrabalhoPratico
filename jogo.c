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



char vitoria(char **jogo){
    for (int i = 0; i < 3; i++){
        if (jogo[i][0] == jogo[i][1] && jogo[i][1] == jogo[i][2] && jogo[i][0] != 'V'){
            if (jogo[i][0] == 'X')
                return 'X';
            else
                return 'O';
        }
    }
    //Game over - col
    for (int j = 0; j < 3; j++){
        if (jogo[0][j] == jogo[1][j] && jogo[1][j] == jogo[2][j] && jogo[0][j] != 'V'){
            if (jogo[0][j] == 'X')
                return 'X';
            else
                return 'O';
        }
    }
    //game over - diagonal
    if (jogo[0][0] == jogo[1][1] && jogo[1][1] == jogo[2][2] && jogo[0][0] != 'V'){
        if (jogo[0][0] == 'X')
            return 'X';
        else
            return 'O';
    }
    //game over - diagonal secundária
    if(jogo[0][2] == jogo[1][1] && jogo[1][1] == jogo[2][0] && jogo[3][0] != 'V'){
        if(jogo[0][2] == 'X')
            return 'X';
        else
            return 'O';
    }
    //game over - empate
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(jogo[i][j] == 'V')
                return 'E';
        }
    }
    //game over - o jogo não acabou
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
char vitoriaM(char *jogo){
    int vitorias[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    //verificar vitoria
    for (int i = 0; i < 8; i++){
        if(jogo[vitorias[i][0]] != 'V' && jogo[vitorias[i][0]] == jogo[vitorias[i][1]] && jogo[vitorias[i][0]] == jogo[vitorias[i][2]]){
            return jogo[vitorias[i][2]];
        }
    }
}

//detectar jogada mestre
void mestre(char *jogo, char jogador){
    int jm = 0;
    for(int i = 8; i >= 0; i--){
        if(jogo[i] == 'V'){
            jogo[i] = jogador;
            if (vitoriaM(jogo) == jogador){
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