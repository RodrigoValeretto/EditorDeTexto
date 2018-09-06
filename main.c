#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main()
{
	printf("Editor de Textos em C\n");
	Tipo_Lista *Lista;
	Tipo_Lista *InicioL;
	int num = 0;
	char ent;
	char palavra[30];

	Lista = crialistas();
	InicioL = Lista;

	learquivo(Lista, InicioL);

	while(1)
	{
		scanf("%c", &ent);

		switch(ent)
		{
			case 'r':
			scanf("%s", palavra);
			trocapalavra(Lista, palavra);
			break;

			case 'f':
			scanf("%s", palavra);
			buscapalavra(Lista, palavra);
			break;

			case 'd':
			Lista = deletapalavra(Lista);
			if(Lista == NULL){return 0;}
			break;

			case 'n':
			Lista = avancaum(Lista);
			if(Lista == NULL){return 0;}
			break;

			case 'p':
			Lista = voltaum(Lista);
			if(Lista == NULL){return 0;}
			break;

			case 'b':
			Lista = setinicio(Lista, InicioL);
			if(Lista == NULL){return 0;}
			break;

			case 'e':
			Lista = setfinal(Lista);
			if(Lista == NULL){return 0;}
			break;

			case 'g':
			scanf("%d", &num);
			Lista = movecursor(Lista, num);
			if(Lista == NULL){return 0;}
			break;

			case 's':
			imprimelista(Lista, InicioL);
			return 0;

		}
	}

	return 0;
}
