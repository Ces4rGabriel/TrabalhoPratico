# ifndef jogo_da_velha_h
# define jogo_da_velha_h

char **alocaTabuleiro();

void liberaMemoria(char **jogo);

void entrada(char jogo[][3]);

void validar(char jogo[][3], int *QuantX,int *QuantO);

int vitoria (char jogo[][3]);

#endif //jogo_da_velha_h
