# ifndef jogo_da_velha_h
# define jogo_da_velha_h

typedef struct tabuleiro TADTabuleiro;

void alocaTadTabuleiro(TADTabuleiro**);

void alocaTabuleiro(TADTabuleiro**);

void liberaMemoria(TADTabuleiro**);

void entrada(char jogo[9], TADTabuleiro**);

int validar(TADTabuleiro*);

char vitoria(TADTabuleiro*);

void mostraJogo(TADTabuleiro*);

char vitoriaM(char jogo[9]);

int mestre(char jogo[9], char jogador);

void analisar(char jogo[9],int contador, TADTabuleiro*);

#endif //jogo_da_velha_h
