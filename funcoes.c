#include <stdio.h>		//Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>		//Biblioteca necessária para a manipulação de strings
#include "headers.h"

Tipo_Lista *crialistas()	//Função para criar Listas
{
	Tipo_Lista *Lista;

	Lista = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));	//Alocação dinamica da lista
	if(Lista == NULL){return 0;}	//Verifica se não retornou NULL

	return Lista;	//Retorna o ponteiro alocado
}

char * recebepalavra()
{
	int cont = 0;
	char *palavra = (char *)calloc(30,sizeof(char));
	char *inicio = palavra;
	for(int i=0; i<30; i++)
	{
		scanf("%c", &palavra[i]);
		if(*inicio == ' ' || *inicio == '\0')
		{inicio++;}

		if(palavra[i] == '\n')
			{
				if(cont >= 2){palavra[i] = '\0';}
				break;
			}

		cont++;
	}

	return inicio;
}

int encontraincomum(Tipo_Lista *Lista)
{
	for(int i = 0; i<30; i++)
	{
		if((Lista->palavra[i]>='a' && Lista->palavra[i]<='z') || (Lista->palavra[i]>='A' && Lista->palavra[i]<='Z') || (Lista->palavra[i]>='0' && Lista->palavra[i]<='9'))
		{}else{
			return i;
		}
	}
	return 0;
}

int verificapalavra(Tipo_Lista *Lista)
{
	for(int i = 0; i<30; i++)
	{
		if((Lista->palavra[i]>='a' && Lista->palavra[i]<='z') || (Lista->palavra[i]>='A' && Lista->palavra[i]<='Z') || (Lista->palavra[i]>='0' && Lista->palavra[i]<='9') || (Lista->palavra[i] == '\0'))
			{}
		else{return 0;}
	}
	return 1;
}

int verificachar(char letra)
{
	if((letra>='a' && letra<='z') || (letra>='A' && letra<='Z') || (letra>='0' && letra<='9'))
	{return 1;}
	else{return 0;}
}

void trocapalavra(Tipo_Lista *Lista, char palavra[30])	//Função que troca uma palavra por outra
{
	strcpy(Lista->palavra, palavra);	//Coloca a palavra digitada pelo usuario no lugar da que estava na lista
}

void imprimelista(Tipo_Lista *Lista, Tipo_Lista *InicioL)	//Função responsável por imprimir o conteudo da lista
{
	Lista = InicioL;
	while(Lista != NULL)
	{
		if(Lista->prox == NULL)
		{
			printf("%s", Lista->palavra);
			Lista = Lista->prox;
		}else{
			if(verificapalavra(Lista->prox) && Lista->palavra[0] != '\n')
			{
				printf("%s ", Lista->palavra);
				Lista = Lista->prox;
			}else{
				printf("%s", Lista->palavra);
				Lista = Lista->prox;
			}
		}
	}
}

void learquivo(Tipo_Lista *Lista,Tipo_Lista *InicioL)	//Função que le o arquivo inicial
{
	Lista = InicioL;
	int i = 0;
    int j = 0;
    int k = 0;
	FILE *fp;
	char *ent = calloc(1,sizeof(char));

	scanf("%s", ent);
	strcat(ent,".ext");

	fp = fopen(ent,"rt");
	if(fp == NULL){return;}

	while(!feof(fp))
	{
		fscanf(fp,"%s",Lista->palavra);
		while(1)
		{
			if(!verificapalavra(Lista))
			{
			    i = 0;
				while(1)
				{
					if(!verificachar(Lista->palavra[i]))
					{
						Lista->prox = crialistas();
						Lista->prox->ant = Lista;
						if(i == 0){i++;}
						k = i;
						for(j = 0; j<30; j++)
						{
						    if(Lista->prox->palavra[j] == '\0' && Lista->palavra[i] == '\0'){break;}
						    else
							{Lista->prox->palavra[j] = Lista->palavra[i];}
							i++;
						}
						for(; k<30; k++)
						{
						    if(Lista->palavra[k] == '\0'){break;}
						    else
							{Lista->palavra[k] = '\0';}
						}
						Lista = Lista->prox;
						break;
					}
					i++;
				}
			}else{break;}
		}

		if(!feof(fp) && Lista->prox==NULL)
		{
			Lista->prox = crialistas();
			Lista->prox->ant = Lista;
			Lista = Lista->prox;
		}
	}
}

void buscapalavra(Tipo_Lista *Lista, char palavra[30])	//Função que busca a proxima palavra apos o cursor
{
	int i = 0;
	while(Lista != NULL)
	{
		if(!strcmp(Lista->palavra, palavra))
		{
			printf("%d\n", i);
			break;
		}else{
			Lista = Lista->prox;
			i++;
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
		Lista = Lista->prox;
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
