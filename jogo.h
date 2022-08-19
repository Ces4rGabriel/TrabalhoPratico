# ifndef jogo_da_velha_h
# define jogo_da_velha_h

typedef struct jogadas Jogadas;

Jogadas* alocaJogadas();

char **alocaTabuleiro();

void liberaMemoria(char ***jogo);

void entrada(char **jogo);

int validar(char **jogo, Jogadas*);

int vitoria (char **jogo);

void analisar(char **jogo, int contador, Jogadas*);

#endif //jogo_da_velha_h
