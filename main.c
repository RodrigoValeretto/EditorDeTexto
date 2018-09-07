#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

int main()
{
	printf("Editor de Textos em C\n");
	Tipo_Lista *Lista;			//Declaração de variáveis
	Tipo_Lista *InicioL;
	int num = 0;
	char ent;
	char palavra[30];

	Lista = crialistas();		//Criação de lista e atribuição ao ponteiro Lista
	InicioL = Lista;			//Salva o inicio da Lista

	learquivo(Lista, InicioL);	//Função para ler o arquivo inicial

	while(1)					//Looping que mantem o programa rodando enquanto comandos são feitos
	{
		scanf("%c", &ent);		//Recebe o comando do usuario

		switch(ent)				//Função switch que permite realizar uma ação de acordo com o comando do usuario
		{
			case 'r':				//Caso o usuario digite r, ele pode trocar a palavra que a lista está apontando
			scanf("%s", palavra);
			trocapalavra(Lista, palavra);	//Função de trocar palavra
			break;

			case 'f':				//Caso o usuario digite f, ele pode buscar a proxima palavra após o local que a lista aponta
			scanf("%s", palavra);
			buscapalavra(Lista, palavra);	//Função de buscar a palavra
			break;

			case 'd':				//Caso o usuario digite d, ele pode deletar a palavra que a lista aponta
			Lista = deletapalavra(Lista);	//Função para deletar palavra que retorna o ponteiro para outra palavra(anterior ou proxima)
			if(Lista == NULL){return 0;}	//Verifica se a função não retornou NULL e se ela o fizer,
			break;							//finaliza o programa pois houve algum erro ou a pessoa deletou todo o texto

			case 'n':				//Caso o usuario digite n, avança o ponteiro da lista em uma posição
			Lista = avancaum(Lista);		//Função que avança o ponteiro e retorna a posição do mesmo avançado
			if(Lista == NULL){return 0;}	//Verifica se a função não retornou NUll
			break;

			case 'p':				//Caso o usuario digite p, a função retrocede uma posição na lista
			Lista = voltaum(Lista);	//Função que volta uma posição e retorna o ponteiro retrocedido
			if(Lista == NULL){return 0;}	//Verifica se a função não retornou NULL
			break;

			case 'b':				//Caso o usuario digite b, a função aponta o ponteiro para o inicio da lista
			Lista = setinicio(Lista, InicioL);	//Função que aponta para o inicio da linha e retorna o ponteiro já alterado
			if(Lista == NULL){return 0;}	//Verifica se a função não retornou NULL
			break;

			case 'e':				//Caso o usuario digite e, a função aponta o ponteiro para o final da lista
			Lista = setfinal(Lista);	//Função que aponta para o final da lista e retorna o ponteiro já modificado
			if(Lista == NULL){return 0;}//Verifica se a função não retornou NULL
			break;

			case 'g':				//Caso o usuario digite g, a função move o cursor para frente se o numero digitado for positivo e para trás se negativo
			scanf("%d", &num);		//Recebe o numero de posições que deseja avançar ou retroceder
			Lista = movecursor(Lista, num);	//Função para mover o cursor
			if(Lista == NULL){return 0;}	//Verifica se a função não retornou NULL
			break;

			case 's':				//Caso o usuario digite s, a função imprime todo o texto contido na memória e finaliza o programa;
			imprimelista(Lista, InicioL);	//Função que imprime o conteudo da lista
			return 0;						//Finaliza o programa

		}
	}

	return 0;
}
