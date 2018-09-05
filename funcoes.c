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

void trocapalavra(Tipo_Lista *Lista, char palavra[30])
{
	strcpy(Lista->palavra, palavra);	
}

void imprimelista(Tipo_Lista *Lista, Tipo_Lista *InicioL)
{
	Lista = InicioL;
	while(Lista != NULL)
	{
		printf("%s ", Lista->palavra);
		Lista = Lista->prox;
	}
}

void learquivo(Tipo_Lista *Lista,Tipo_Lista *InicioL)
{
	Lista = InicioL;
	FILE *fp;
	fp = fopen("texto.txt","rt");
	if(fp == NULL){return;}

	while(!feof(fp))
	{
		fscanf(fp,"%s",Lista->palavra);

		if(!feof(fp))
		{
			Lista->prox = crialistas();
			Lista->prox->ant = Lista;
			Lista = Lista->prox;
		}
	}
}