# ifndef jogo_da_velha_h
# define jogo_da_velha_h

typedef struct jogadas Jogadas;

char *alocaTabuleiro();

void entrada(char *jogo);

int validarEntrada(char *j, Jogadas *);

char vitoria(char **);

void analisar(char *, int, Jogadas *);
char vitoriaM(char *);
void mestre(char *, char);

void imprimirmestre(int);

#endif //jogo_da_velha_h