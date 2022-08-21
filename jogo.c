#include <stdio.h>
#include <stdlib.h>
#include "jogo.h" 

struct tabuleiro{
    char **TabuleiroJogo;
    int quantX;
    int quantO;
};
//criei essa função mas nem sei se precisa
void alocaTadTabuleiro(TADTabuleiro **tab){
    *tab = malloc (sizeof(TADTabuleiro));
}


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

    free(*Tabuleiro);
}


void entrada(char jogo[9], TADTabuleiro **tab){
    //Lendo o Vetor com Jogadas
    scanf("%s", jogo);
    //Transpondo Vetor Para Matriz
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            (*tab)->TabuleiroJogo[i][j] = jogo[i*3 + j];
        }
    }
}

void mostraJogo(TADTabuleiro* tab){
    for (int i = 0; i < 3; i++)
    {   
        for (int j = 0; j < 3; j++)
        {
            printf("%c", tab->TabuleiroJogo[i][j]);
        }
        printf("\n");
    }
    
}

int validar(TADTabuleiro *Tabuleiro){
    Tabuleiro->quantO = 0;
    Tabuleiro->quantX = 0;
    int diferenca;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++){
            if(Tabuleiro->TabuleiroJogo[i][j] == 'X')
                Tabuleiro->quantX++;
            else if(Tabuleiro->TabuleiroJogo[i][j] == 'O')
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

char vitoria(TADTabuleiro *tab){
    for (int i = 0; i < 3; i++){
        if (tab->TabuleiroJogo[i][0] == tab->TabuleiroJogo[i][1] && tab->TabuleiroJogo[i][1] == tab->TabuleiroJogo[i][2] && tab->TabuleiroJogo[i][0] != 'V'){
            if (tab->TabuleiroJogo[i][0] == 'X')
                return 'X';
            else
                return 'O';
        }
    }
    //Game over - col
    for (int j = 0; j < 3; j++){
        if (tab->TabuleiroJogo[0][j] == tab->TabuleiroJogo[1][j] && tab->TabuleiroJogo[1][j] == tab->TabuleiroJogo[2][j] && tab->TabuleiroJogo[0][j] != 'V'){
            if (tab->TabuleiroJogo[0][j] == 'X')
                return 'X';
            else
                return 'O';
        }
    }
    //game over - diagonal
    if (tab->TabuleiroJogo[0][0] == tab->TabuleiroJogo[1][1] && tab->TabuleiroJogo[1][1] == tab->TabuleiroJogo[2][2] && tab->TabuleiroJogo[0][0] != 'V'){
        if (tab->TabuleiroJogo[0][0] == 'X')
            return 'X';
        else
            return 'O';
    }
    //game over - diagonal secundária
    if(tab->TabuleiroJogo[0][2] == tab->TabuleiroJogo[1][1] && tab->TabuleiroJogo[1][1] == tab->TabuleiroJogo[2][0] && tab->TabuleiroJogo[3][0] != 'V'){
        if(tab->TabuleiroJogo[0][2] == 'X')
            return 'X';
        else
            return 'O';
    }
    //game over - empate
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tab->TabuleiroJogo[i][j] == 'V')
                return 'E';
        }
    }
    //game over - o jogo não acabou
    return 'V';
}

char vitoriaM(char jogo[9]){
    printf("ksdakd\n");
    int vitorias[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};

    //verificar vitoria
    for (int i = 0; i < 8; i++){
        if(jogo[vitorias[i][0]] != 'V' && jogo[vitorias[i][0]] == jogo[vitorias[i][1]] && jogo[vitorias[i][0]] == jogo[vitorias[i][2]]){
            return jogo[vitorias[i][2]];
        }
    }
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


//detectar jogada mestre
int mestre(char jogo[9], char jogador){
    int jm = 0;
    printf("opa cheguei");
    for(int i = 8; i >= 0; i--){
        printf("%d\n", i);
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

    return 0;
}

void analisar(char jogo[9], int contador, TADTabuleiro *Tab){
    char vit = vitoria(Tab);
    switch (vit)
    {
    case 'X':
        printf("Tabuleiro %d com vitoria [X]\n", contador);
        break;
    case 'O':
        printf("Tabuleiro %d com vitoria [O]\n", contador);
        break;
    case 'E':
        printf("Tabuleiro %d deu velha\n", contador);
        break;
    case 'M':
        printf("Tabuleiro %d invalido", contador);
        break;
    case 'V':
        //para jogador indefinido x = o
        if (Tab->quantX == Tab->quantO){
            printf("Tabuleiro %d em andamento [proximo jogador indefinido]\n", contador);
        }
        else if (Tab->quantX < Tab->quantO){
            printf("Tabuleiro %d em andamento [X: ", contador);
            //mestre(jogo, 'X');
            mostraJogo(Tab);
            printf("ah\n");
            printf("]\n");
        }
        else if (Tab->quantX > Tab->quantO){
            mestre(jogo, 'O');
            mostraJogo(Tab);
            printf("Tabuleiro %d em andamento [O: ", contador);
            //mestre(jogo, 'O');
            printf("ah\n");
            printf("]\n");
            mostraJogo(Tab);
        }
        break;
    }   
     
}




