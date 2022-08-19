# ifndef jogo_da_velha_h
# define jogo_da_velha_h

typedef struct jogadas Jogadas;

char **alocaTabuleiro();

void liberaMemoria(char ***jogo);

void entrada(char **jogo);

int validar(char **jogo);

int vitoria (char **jogo);

int analisar(char **jogo, int contador);

#endif //jogo_da_velha_h
