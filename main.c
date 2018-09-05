#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main()
{
	printf("Editor de Textos em C\n");
	Tipo_Lista *Lista;
	Tipo_Lista *InicioL;
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

			case 's':
			imprimelista(Lista, InicioL);
			return 0;

		}
	}

	return 0;
}
