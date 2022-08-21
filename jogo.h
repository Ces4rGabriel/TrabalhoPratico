# ifndef jogo_da_velha_h
# define jogo_da_velha_h

typedef struct tabuleiro TADTabuleiro;

Jogadas* alocaJogadas();

char **alocaTabuleiro();

void liberaMemoria(char ***jogo);

void entrada(char **jogo);

int validar(char **jogo, tabueleiro*);

char vitoria(char **jogo);

void analisar(char **jogo, int contador, tabuleiro*);

#endif //jogo_da_velha_h
