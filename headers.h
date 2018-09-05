typedef struct lista
{
	char palavra[30];
	struct lista *prox;
	struct lista *ant;
}Tipo_Lista;

Tipo_Lista *crialistas();

void trocapalavra(Tipo_Lista *, char *);

void imprimelista(Tipo_Lista *, Tipo_Lista *);

void learquivo(Tipo_Lista *,Tipo_Lista *);