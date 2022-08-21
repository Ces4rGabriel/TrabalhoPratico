# ifndef jogo_da_velha_h
# define jogo_da_velha_h

typedef struct tabuleiro TADTabuleiro;

void alocaTabuleiro(TADTabuleiro **);

void liberaMemoria(TADTabuleiro **);

void entrada(char **jogo);

int validar(char **jogo, TADTabuleiro*);

char vitoria(char **jogo);

char vitoriaM(char *);

void analisar(char **jogo, int contador, TADTabuleiro*);

#endif //jogo_da_velha_h
