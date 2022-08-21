#include <stdio.h>
#include <stdlib.h>
#include "jogo.h" 

struct tabuleiro{
    char **TabuleiroJogo;
    int quantX;
    int quantO;
};
//criei essa função mas nem sei se precisa
/*TADTabuleiro* alocaTADTabuleiro() {
    TADTabuleiro * Tabuleiro = malloc (sizeof(TADTabuleiro));
    return Tabuleiro;
}*/

void alocaTabuleiro(TADTabuleiro **Tabuleiro){
    //char **Tabuleiro;
    (*Tabuleiro)->TabuleiroJogo = (char **) malloc(3 * sizeof(char *));
    for (int i = 0; i < 3; i++)
        (*Tabuleiro)->TabuleiroJogo[i] = (char *) malloc(3 * sizeof(char));
    //return Tabuleiro;
}

void liberaMemoria(TADTabuleiro **Tabuleiro){
    for (int i = 0; i < 3; i++)
        free(((*Tabuleiro)->TabuleiroJogo)[i]);
    free((*Tabuleiro)->TabuleiroJogo);
}


void entrada(char **jogo){
    getchar();
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%c", &jogo[i][j]);
        }
    }
}

int validar(char **jogo, TADTabuleiro *Tabuleiro){
    Tabuleiro->quantO = 0;
    Tabuleiro->quantX = 0;
    int diferenca;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            if(jogo[i][j] == 'X')
                Tabuleiro->quantX++;
            else if(jogo[i][j] == 'O')
                Tabuleiro->quantO++;  
        }
    } 
    //diferença de quantidade de X e O
    diferenca = abs( Tabuleiro->quantX - Tabuleiro->quantO );
    //se a diferença for maior que 1, não é possível ganhar
    if( diferenca > 1 )
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

char vitoriaM(char *jogo){
    int vitorias[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    int cv = 0;
    char aux;
    //verificar vitoria
    for (int i = 0; i < 8; i++){
        if(jogo[vitorias[i][0]] != 'V' && jogo[vitorias[i][0]] == jogo[vitorias[i][1]] && jogo[vitorias[i][0]] == jogo[vitorias[i][2]]){
            return jogo[vitorias[i][2]];
        }
    }
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
