#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main()
{
	printf("Editor de Textos em C\n");	
	Tipo_Lista *Lista;
	Tipo_Lista *InicioL;

	Lista = crialistas(Lista);
	InicioL = Lista;

	insereentrada(Lista);
	
	imprimelista(Lista, InicioL);

	return 0;
}