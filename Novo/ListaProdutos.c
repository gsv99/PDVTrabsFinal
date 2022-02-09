#include "lib.h"

ListaBlocos* criarListaBlocos(void)
{
	ListaBlocos* novalista = (ListaBlocos*)malloc(sizeof(ListaBlocos));
	
	novalista->prim = NULL;
	novalista->ult = NULL;
	novalista->tamanho = 0;
	
	return novalista;
}

int inserirBloco(ListaBlocos* l)
{
	produto* novobloco = (produto*)malloc(sizeof(produto));
	
	if( novobloco == NULL)
		return 1;

	novobloco->nome = (char*)malloc(sizeof(char*)* 25);
	novobloco->nome = NULL;
	novobloco->id = 0;
	novobloco->cod_barra = 0;
	novobloco->qntd = 0;
	novobloco->valorcompra = 0;
	novobloco->valorvenda = 0;

	novobloco->prox = NULL;
	
	
	if( l->prim == NULL)
		l->prim = l->ult = novobloco;
	else
	{
		l->ult->prox = novobloco;
		l->ult = novobloco;
	}
	
	l->tamanho +=1;
	
	return 0;
	
}

int quantidadeBlocos(ListaBlocos* l){
	return l->tamanho;
}
