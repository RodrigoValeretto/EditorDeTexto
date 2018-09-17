#include <stdio.h>		//Bibliotecas utilizadas
#include <stdlib.h>
#include <string.h>		//Biblioteca necessária para a manipulação de strings
#include "headers.h"

Tipo_Lista * liberamemoria(Tipo_Lista *Lista, Tipo_Lista *InicioL)  //Função que libera a memória alocada durante o programa
{
    Tipo_Lista *Aux = InicioL;  //Aponta uma variável auxiliar para o inicio da lista
    Lista = InicioL;            //Aponta o cursor para a propria Lista

    while(Lista != NULL)    //Laço que roda até o cursor apontar para NULL
    {
        Lista = Lista->prox;//Avança o cursor em uma posição
        free(Aux);      //Libera a memoria da posição que aux está
        Aux = Lista;    //Atribui a posição do cursor para Aux
    }

    return InicioL; //Retorna o Inicio da lista vazia
}

Tipo_Lista *crialistas()	//Função para criar Listas
{
	Tipo_Lista *Lista;

	Lista = (Tipo_Lista*)calloc(1,sizeof(Tipo_Lista));	//Alocação dinamica da lista
	if(Lista == NULL){return 0;}	//Verifica se não retornou NULL

	return Lista;	//Retorna o ponteiro alocado
}

char * recebepalavra()	//Função responsável por receber uma palavra em funções que necessitam
{
	int cont = 0;	//Declaração de Variáveis
	char *palavra = (char *)calloc(30,sizeof(char));
	char *inicio = palavra;
	for(int i=0; i<30; i++)	//Laço responsável por receber char a char a palavra desejada
	{
		scanf("%c", &palavra[i]);
		if(*inicio == ' ' || *inicio == '\0')	//Condicional que evita que a palavra inicie com espaço caso esse seja puxado pelo buffer
		{inicio++;}

		if(palavra[i] == '\n')	//Condicional para o caso ENTER
			{
				if(cont >= 2){palavra[i] = '\0';}
				break;
			}

		cont++;	//incremento de contador
	}

	if(!strcmp(inicio,"<ENTER>"))	//Condicional que adiciona \n caso a string digitada seja <ENTER>
    {
        strcpy(inicio,"\n");
    }
	return inicio;
}

int encontraincomum(Tipo_Lista *Lista)	//Função que encontra caracteres incomuns numa string
{
	for(int i = 0; i<30; i++)	//Constituida desse for que realiza varios casos conferindo se os caracteres são comuns ou não
	{
		if((Lista->palavra[i]>='a' && Lista->palavra[i]<='z') || (Lista->palavra[i]>='A' && Lista->palavra[i]<='Z') || (Lista->palavra[i]>='0' && Lista->palavra[i]<='9'))
		{}else{
			return i;	//Retorna o indice do caracter incomum se ele for encontrado
		}
	}
	return 0; //Retorna 0 caso o caracter não seja encontrado
}

int verificapalavra(Tipo_Lista *Lista)	//Função responsável por verifiar se uma palavra é comum ou incomum
{
	for(int i = 0; i<30; i++)	//Laço que verifica char a char se alguma das letras da palavra é comum ou incomum
	{
		if((Lista->palavra[i]>='a' && Lista->palavra[i]<='z') || (Lista->palavra[i]>='A' && Lista->palavra[i]<='Z') || (Lista->palavra[i]>='0' && Lista->palavra[i]<='9') || (Lista->palavra[i] == '\0'))
			{}
		else{return 0;}	//Retorna 0 se for incomum
	}
	return 1; //Retorna 1 se for comum
}

int verificachar(char letra)	//Função que verifica se apenas um caracter é comum ou incomum
{
	if((letra>='a' && letra<='z') || (letra>='A' && letra<='Z') || (letra>='0' && letra<='9'))	//Condicional para verificar se é comum ou não
	{return 1;}		//Retorna 1 se for comum
	else{return 0;}	//Retorna 0 se for incomum
}

void insereprox(Tipo_Lista *Lista, char *palavra)	//Função que insere uma palavra como proximo nodo da lista
{
	Tipo_Lista *Elem = crialistas();	//Criação do Elem a ser inserido

	strcpy(Elem->palavra, palavra);		//Colocando a palavra no elem
	Elem->ant = Lista;					//Faz o anterior do elem ser o cursor
	Elem->prox = Lista->prox;			//O proximo ser o proximo do cursor
	if(Lista->prox != NULL)				//Verifica se Lista->prox é NULL
    {Lista->prox->ant = Elem;}			//Se não for, atribui ao anterior do proximo elemento do cursor, o elemento criado
	Lista->prox = Elem;					//Por fim, coloca o elem como prox do cursor
}

Tipo_Lista * insereant(Tipo_Lista *Lista, Tipo_Lista *InicioL, char *palavra)	//Funcão que insere uma palavra como nodo anterior da lista
{
	Tipo_Lista *Elem = crialistas();	//Criação do elem a ser inserido

	if(Lista == InicioL)				//Condicional para caso queira inserir um nodo antes do inicio da lista
	{InicioL = Elem;}					//Nesse caso deve-se mudar o inicio para o Elem que está sendo inserido

	strcpy(Elem->palavra, palavra);		//Coloca a palavra no Elem
	Elem->prox = Lista;					//Aponta o proximo do elem para a posição atual do cursor
	Elem->ant = Lista->ant;				//Aponta o anterior do elemento para a posição anterior ao cursor
	if(Lista->ant != NULL)				//Confere se o anterior da Lista é NULL
	{Lista->ant->prox = Elem;}			//Se não for, atribui ao proximo do elemento anterior do cursor, o elemento criado
	Lista->ant = Elem;					//Por fim, coloca o elem como anterior ao cursor

	return InicioL;						//Retorna o novo inicio caso este tenha sido alterado e o antigo caso não haja alterações
}

void trocapalavra(Tipo_Lista *Lista, char palavra[30])	//Função que troca uma palavra por outra
{
	strcpy(Lista->palavra, palavra);	//Coloca a palavra digitada pelo usuario no lugar da que estava na lista
}

void imprimelista(Tipo_Lista *Lista, Tipo_Lista *InicioL)	//Função responsável por imprimir o conteudo da lista
{
	Lista = InicioL;		//Atribui o inicio da Lista para o cursor
	while(Lista != NULL)	//Laço que roda até o cursor encontrar NULL
	{
		if(Lista->prox == NULL)	//Confere se o proximo elemento da lista aponta para NULL
		{
			printf("%s", Lista->palavra);	//Se sim, ele printa uma string sem espaço em sequencia na tela
			Lista = Lista->prox;			//E avança o cursor em uma posição
		}else{
			if(verificapalavra(Lista->prox) && Lista->palavra[0] != '\n')	//Se não, ele verifica se a proxima palavra da lista é comum ou incomum
			{
				printf("%s ", Lista->palavra);		//Se for comum, ele printa a palavra contida no cursor com um espaço logo em seguida
				Lista = Lista->prox;				//E avança o cursor uma posição
			}else{
				printf("%s", Lista->palavra);		//Se for incomum, ele printa a palavra contida no cursor sem espaço em seguida
				Lista = Lista->prox;				//E avança o cursor uma posição
			}
		}
	}
}

void learquivo(Tipo_Lista *Lista,Tipo_Lista *InicioL)	//Função que le o arquivo inicial
{
    Tipo_Lista *Aux;		//Declaração de variáveis
	Lista = InicioL;
	int i = 0;
    int j = 0;
    int k = 0;
	FILE *fp;
	char *ent = calloc(1,sizeof(char));

	scanf("%s", ent);	//Recebe o numero do arquivo que deverá ser lido
	strcat(ent,".ext");	//Adiciona o final ".ext" na string recebida

	fp = fopen(ent,"rt");	//Abre o arquivo de nome desejado
	if(fp == NULL){exit(0);}//Verifica se foi possivel abrir e caso não, finaliza o programa

	while(!feof(fp))	//Laço que roda enquanto o programa não atingir o final do mesmo
	{
		for(i = 0; i<30; i++)	//For que recebe a palavra do arquivo
		{
			fscanf(fp,"%c",&Lista->palavra[i]);	//Le uma string do arquivo até o espaço ou \0 pegando char a char
			if(Lista->palavra[i] == ' ' || Lista->palavra[i] == '\0')	//Verifica se o char é espaço ou \0
				{
					Lista->palavra[i] = '\0';	//Atribui um \0 se ele for um dos dois
					break;	//Finaliza o Laço
				}
		}
		while(1)	//Laço infinito
		{
			if(!verificapalavra(Lista))	//Verifica se a palavra apontada pelo cursor é comum ou incomum e entra no laço se for incomum
			{
			    i = 0;	//Atribui 0 a i
				while(1)	//Outro laço infinito
				{
					if(!verificachar(Lista->palavra[i]))	//Verifica char a char para encontrar elementos incomuns na palavra
					{
						Lista->prox = crialistas();		//Cria um proximo para atribuir o elemento especial
						Lista->prox->ant = Lista;		//Aponta o anterior do elemento criado para o cursor
						if(i == 0){i++;}				//Se i for 0 incrementa ele para pegar a partir do segundo char da string
						k = i;	//Atribui-se o valor de i para k
						for(j = 0; j<30; j++)	//Laço que copia para o proximo elemento da lista o conteudo a partir do char especial
						{
						    if(Lista->prox->palavra[j] == '\0' && Lista->palavra[i] == '\0'){break;}	//Verificação que finaliza o laço caso os chars cheguem em '\0'
						    else
							{Lista->prox->palavra[j] = Lista->palavra[i];}	//Atribuindo o char do cursor para o char do proximo
							i++;	//Incrementa i
						}
						for(; k<30; k++)	//Laço responsável por atribuir \0 aos outros elementos após o char incomum
						{
						    if(Lista->palavra[k] == '\0'){break;}	//Condicional que finaliza o laço caso este encontre \0
						    else
							{Lista->palavra[k] = '\0';}	//Do contrario vai atribuindo \0 aos chars restantes
						}
						Lista = Lista->prox;	//Avança para o proximo elemento da lista
						break;	//Finaliza o Laço infinito
					}
					i++; //Incrementa i
				}
			}else{break;} //Caso a apalavra seja comum, finaliza o laço
		}
        if(!feof(fp) && Lista->prox==NULL) //Condicional que aloca memoria para o proximo elemento caso ele exista
        {
            Lista->prox = crialistas();	//Aloca memoria para o proximo elemento
            Lista->prox->ant = Lista;	//Atribui ao anterior do proximo elemento a posição atual do cursor
            Lista = Lista->prox;		//Avança para o proximo elemento
        }
	}
	Lista = InicioL;	//Atribui o inicio da lista para o cursor
    while(Lista != NULL)//Laço que elimina possiveis "\0" alocados como elementos
    {
        if(Lista == NULL){break;}//Se a lista apontar para NULL, finaliza a função
        if(!strcmp(Lista->palavra,"\0"))//Compara a palavra contida na lista com a string "\0"
        {
            if(Lista != NULL)	//Verifica se lista é diferente de NULL
            {Aux = Lista->ant;}	//Se ela for, aponta o Aux para o elemento anterior ao cursor
            if(Lista == NULL){Aux->prox = NULL;}	//Se Lista for NULL atribui NULL ao auxilia também
            else{
                Aux->prox = Lista->prox;	//Do contrario, aponta o proximo do auxiliar para o proximo do cursor
                if(Lista->prox != NULL)		//Se o proximo do cursor não for NULL
                {Lista->prox->ant = Aux;}	//Aponta o anterior do proximo do cursor para Aux
            }
            free(Lista);	//Libera a memoria que tem a string "\0"
            Lista = Aux;	//Faz lista receber Aux
        }
        Lista = Lista->prox;//Avança o cursor em uma posição
    }
	fclose(fp); //Fecha o arquivo
}

void buscapalavra(Tipo_Lista *Lista, char palavra[30], Tipo_Lista *InicioL)	//Função que busca a proxima palavra apos o cursor
{
    Tipo_Lista *Aux = Lista;	//Declaração de variáveis
    Lista = InicioL;
	int i = 0;
	while(Lista != Aux)	//Laço que avança o cursor até ele encontrar o auxiliar
    {
        Lista = Lista->prox;	//Avança o cursor para o proximo elemento
        i++;					//Incrementa i
    }
	while(Lista != NULL)	//Enquanto a lista for diferente de NULL
	{
		if(!strcmp(Lista->palavra, palavra))	//Compara a palavra contida no cursor com a palavra que deseja encontrar
		{
			printf("%d\n", i);	//Printa i caso a palavra seja encontrada
			break;	//Finaliza o laço
		}else{
			Lista = Lista->prox;	//Se não for igual a palavra o cursor é avançado
			i++;					//E o i é incrementado
		}
	}
}

Tipo_Lista * deletapalavra(Tipo_Lista *Lista)	//Função responsável por deletar um elemento da lista
{
	Tipo_Lista *Aux = Lista;	//Declaração de variavel auxiliar

	if(Lista->prox != NULL && Lista->ant != NULL)	//Condicional para caso o proximo da lista e o anterior não apontarem pra NULL
	{
		Lista->prox->ant = Lista->ant; 	//Nesse caso, o anterior do proximo elemento do cursor recebe o anterior do cursor
		Lista->ant->prox = Lista->prox;	//O proximo do anterior recebe o proximo do cursor
		Lista = Lista->prox;	//E o cursor avança uma posição
		free(Aux);		//Memoria que foi deletada é liberada
		return Lista;	//Retorna a posição nova do cursor
	}

	if(Lista->prox == NULL && Lista->ant == NULL)	//Caso em que tanto o prox quanto o anterior apontam para NULL
	{
		Lista = NULL;	//Nesse caso Lista aponta para NULL
		free(Aux);		//E a memoria é liberada
		return Lista;	//Retorna nova posição do cursor
	}

	if(Lista->prox == NULL)	//Caso em que apenas o proximo aponta para NULL
	{
		Lista->ant->prox = NULL;	//O proximo do anterior é apontado para NULL
		Lista = Lista->ant;			//O cursor retrocede uma posição
		free(Aux);					//Memoria é liberada
		return Lista;				//Retorna nova posição do cursor
	}

	if(Lista->ant == NULL)	//Caso em que apenas o anterior aponta para NULL
	{
		Lista->prox->ant = NULL;	//O anterior do proximo elemeento recebe NULL
		Lista = Lista->prox;		//O cursor é avançado em Uma posição
		free(Aux);					//A memoria correspondente a palavra excluida é liberada
		return Lista;				//A nova posição do cursor é retornada
	}

    return Lista;	//A posição do cursor é retornada caso nenhum dos condicionais seja satisfeito
}

Tipo_Lista * avancaum(Tipo_Lista *Lista)	//Avança uma posição do cursor
{
	if(Lista->prox != NULL)	//Se o proximo do cursor for diferente de NULL
	{Lista = Lista->prox;}	//Avança o cursor em uma posição

	return Lista;	//Retorna a nova posição do cursor
}

Tipo_Lista * voltaum(Tipo_Lista *Lista)		//Retrocede uma posição do cursor
{
	if(Lista->ant != NULL)	//Se o anterior do cursor for diferente de NULL
	{Lista = Lista->ant;}	//Retrocede uma posição do cursor

	return Lista;	//Retorna a nova posição do cursor
}

Tipo_Lista * setinicio(Tipo_Lista *Lista, Tipo_Lista *InicioL)	//Aponta o cursor para o inicio do texto
{
	Lista = InicioL;	//Cursor recebe o inicio do texto
	return Lista;		//Retorna nova posição do cursor
}

Tipo_Lista * setfinal(Tipo_Lista *Lista)	//Aponta o cursor para o final do texto
{
	while(Lista->prox != NULL)	//While que roda até que o proximo elemento seja NULL
	{
		Lista = Lista->prox;	//Avança o cursor em uma posição
	}

	return Lista;	//Retorna nova posição do cursor
}

Tipo_Lista * movecursor(Tipo_Lista *Lista, int num)	//Move o cursor a quantidade de vezes digitada para frente se positivo e para trás se negativo
{
	int i;	//Declaração de contador

	if(num >= 0)	//Caso em que o numero é positivo
	{
		for(i = 0; i < num; i++)	//For que roda até alcançar a posição desejada
		{
			if(Lista->prox != NULL)	//Se o proximo do cursor for diferente de NULL
			{Lista = Lista->prox;}	//Avança uma posição do cursor
		}
	}

	if(num < 0)		//Caso em que o numero é negativo
	{
		for(i = 0; i > num; i--)	//For que roda até alcançar a posição desejada
		{
			if(Lista->ant != NULL)	//Caso a posição anterior não seja NULL
			{Lista = Lista->ant;}	//Retrocede uma posição no cursor
		}
	}

	return Lista;	//Retorna nova posição do cursor
}