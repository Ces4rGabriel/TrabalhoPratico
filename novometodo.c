#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int quantX;
    int quantO;
}Jogadas;

char *alocaTabuleiro(){
    char *Tabuleiro;
    Tabuleiro = (char *) malloc(9 * sizeof(char));
    return Tabuleiro;
}

void entrada(char *jogo){
    for(int i = 0; i < 9; i++){
        scanf("%c", &jogo[i]);
    }
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

void imprimir(char *jogo){
    for(int i = 0; i < 9; i++){
        printf("%c ", jogo[i]);
    }
    printf("\n");
}
char vitoria(char *jogo){
    int vitorias[8][3] = {{0,1,2},{3,4,5},{6,7,8},{0,3,6},{1,4,7},{2,5,8},{0,4,8},{2,4,6}};
    for (int i = 0; i < 8; i++){
        if(jogo[vitorias[i][0]] != 'V' && jogo[vitorias[i][0]] == jogo[vitorias[i][1]] && jogo[vitorias[i][0]] == jogo[vitorias[i][2]])
            return jogo[vitorias[i][2]];
    }
    return 0;
}


int main(){
    char check;
    char *jogo;
    int tabuleiroVal;
    Jogadas *jogadas = (Jogadas *) malloc(sizeof(Jogadas));
    jogo = alocaTabuleiro();
    entrada(jogo);
    tabuleiroVal =  validarEntrada(jogo, jogadas);
    if(tabuleiroVal == 1){
        printf("Tabuleiro Inválido\n");
    }
    check = vitoria(jogo);
    printf("jogadas X: %d\n jogadas O: %d\n", jogadas->quantX, jogadas->quantO);
    printf("check: %c\n", check);
    return 0;
}

