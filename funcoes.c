#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"
#define COMUM 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'

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
		if(Lista->prox == NULL)
		{
			printf("%s", Lista->palavra);
			Lista = Lista->prox;
		}else{
			if(Lista->prox->palavra[0] == COMUM)
			{
				printf("%s ", Lista->palavra);
				Lista = Lista->prox;
			}
		}
	}
}

void learquivo(Tipo_Lista *Lista,Tipo_Lista *InicioL)
{
	Lista = InicioL;
	FILE *fp;
	char *ent = calloc(1,sizeof(char));

	scanf("%s", ent);
	strcat(ent,".ext");

	fp = fopen(ent,"rt");
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

void buscapalavra(Tipo_Lista *Lista, char palavra[30])
{
	while(Lista != NULL)
	{
		if(!strcmp(Lista->palavra, palavra))
		{
			printf("%p\n", Lista);
			break;
		}else{
			Lista = Lista->prox;
		}
	}
}

Tipo_Lista * deletapalavra(Tipo_Lista *Lista)
{
	Tipo_Lista *Aux = Lista;

	if(Lista->prox != NULL && Lista->ant != NULL)
	{
		Lista->prox->ant = Lista->ant;
		Lista->ant->prox = Lista->prox;
		Lista = Lista->ant;
		free(Aux);
		return Lista;
	}

	if(Lista->prox == NULL && Lista->ant == NULL)
	{
		Lista = NULL;
		free(Aux);
		return Lista;
	}

	if(Lista->prox == NULL)
	{
		Lista->ant->prox = NULL;
		Lista = Lista->ant;
		free(Aux);
		return Lista;
	}

	if(Lista->ant == NULL)
	{
		Lista->prox->ant = NULL;
		Lista = Lista->prox;
		free(Aux);
		return Lista;
	}

    return Lista;
}

Tipo_Lista * avancaum(Tipo_Lista *Lista)
{
	if(Lista->prox != NULL)
	{Lista = Lista->prox;}

	return Lista;
}

Tipo_Lista * voltaum(Tipo_Lista *Lista)
{
	if(Lista->ant != NULL)
	{Lista = Lista->ant;}

	return Lista;
}

Tipo_Lista * setinicio(Tipo_Lista *Lista, Tipo_Lista *InicioL)
{
	Lista = InicioL;
	return Lista;
}

Tipo_Lista * setfinal(Tipo_Lista *Lista)
{
	while(Lista->prox != NULL)
	{
		Lista = Lista->prox;
	}

	return Lista;
}

Tipo_Lista * movecursor(Tipo_Lista *Lista, int num)
{
	int i;

	if(num >= 0)
	{
		for(i = 0; i < num; i++)
		{
			if(Lista->prox != NULL)
			{Lista = Lista->prox;}
		}
	}

	if(num < 0)
	{
		for(i = 0; i > num; i--)
		{
			if(Lista->ant != NULL)
			{Lista = Lista->ant;}
		}
	}

	return Lista;
}
