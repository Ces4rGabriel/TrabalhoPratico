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

//char vitoriaM(char *);

void analisar(int contador, TADTabuleiro*);

#endif //jogo_da_velha_h
