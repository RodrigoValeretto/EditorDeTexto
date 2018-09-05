#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

Tipo_Lista *crialistas()
{
	Tipo_Lista *Lista;

	Lista = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));
	if(Lista == NULL){return 0;}
	
	return Lista;
}

void insereentrada(Tipo_Lista *Lista)
{
	char *aux = (char*)calloc(30,sizeof(char));
	
	printf("Digite a palavra a ser guardada\n");
	scanf("%s", aux);
	strcpy(Lista->palavra, aux);		
}

void imprimelista(Tipo_Lista *Lista, Tipo_Lista *InicioL)
{
	Lista = InicioL;
	while(Lista != NULL)
	{
		printf("%s", Lista->palavra);
		Lista = Lista->prox;
	}
}

void learquivo(Tipo_Lista *Lista,Tipo_Lista *InicioL)
{
	Lista = InicioL;
	FILE *fp;
	fp = fopen("texto.txt","rt");

	while(!feof(fp))
	{
		fscanf(fp,"%s",Lista->palavra);

		Lista->prox = crialistas();
		Lista = Lista->prox;
	}
}