typedef struct lista 	//Estrutura utilizada em todo o programa (Lista duplamente encadeada)
{
	char palavra[30];
	struct lista *prox;
	struct lista *ant;
}Tipo_Lista;
//Declaração de todas as funções e as variaveis utilizadas nas mesmas do programa
Tipo_Lista *crialistas();

char * recebepalavra();

int encontraincomum(Tipo_Lista *);

int verificapalavra(Tipo_Lista *);

int verificachar(char);

void trocapalavra(Tipo_Lista *, char *);

void imprimelista(Tipo_Lista *, Tipo_Lista *);

void learquivo(Tipo_Lista *,Tipo_Lista *);

void buscapalavra(Tipo_Lista *, char *);

Tipo_Lista * deletapalavra(Tipo_Lista *);

Tipo_Lista * avancaum(Tipo_Lista *);

Tipo_Lista * voltaum(Tipo_Lista *);

Tipo_Lista * setinicio(Tipo_Lista *, Tipo_Lista *);

Tipo_Lista * setfinal(Tipo_Lista *);

Tipo_Lista * movecursor(Tipo_Lista *, int);