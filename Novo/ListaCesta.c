#include "lib.h"

cesta_dados* criarListaCesta(void)
{
	cesta_dados* novalista = (cesta_dados*)malloc(sizeof(cesta_dados));
	
	novalista->prim = NULL;
	novalista->ult = NULL;
	novalista->tamanho = 0;
	
	return novalista;
}

int inserirCesta(cesta_dados * c){
	carrinho* novacesta = (carrinho*)malloc(sizeof(carrinho));
	
	if( novacesta == NULL)
		return 1;

	novacesta->total_produto = 0;
	novacesta->id_produto = 0;
	novacesta->qnt_produto = 0;

	novacesta->prox = NULL;
	novacesta->ant = NULL;
		
	if( c->prim == NULL)
		c->prim = c->ult = novacesta;

	else{
		c->ult->prox = novacesta;
		c->ult->ant = novacesta;
		c->ult = novacesta;
	}
	
	c->tamanho +=1;
	
	return 0;
	
}

int removerCesta(cesta_dados* l, int id)
{
	if( l == NULL)
		return 0;

	carrinho* ant = NULL;
	carrinho* p = l->prim;
	
	while( p != NULL && (p->id_produto != id) ){
		ant = p;
		p = p->prox;
	}
	
	if( p != NULL ){	
		l->total_carrinho = l->total_carrinho - ant->total_produto;

		ant->prox = p->prox;
		
		free(p->nome_produto);
		free(p);
		
		l->tamanho = l->tamanho - 1;
		
		return 1;
	}
	
	return 0;
}

int quantidadeCesta(cesta_dados* c){
	return c->tamanho;
}
