# ifndef jogo_da_velha_h
# define jogo_da_velha_h

char **alocaTabuleiro();

void liberaMemoria(char ***jogo);

void entrada(char **jogo);

int validar(char **jogo);

int vitoria (char **jogo);

#endif //jogo_da_velha_h
