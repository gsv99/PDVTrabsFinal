#include "lib.h"

user_dados* criarListaUser(void)
{
	user_dados* novalista = (user_dados*)malloc(sizeof(user_dados));
	
	novalista->prim = NULL;
	novalista->ult = NULL;
	novalista->tamanho = 0;
	
	return novalista;
}

int inserirUser(user_dados* l)
{
	user* novobloco = (user*)malloc(sizeof(user));
	
	if( novobloco == NULL)
		return 1;

    novobloco->login = (char*)malloc(sizeof(char*)* 12);
    novobloco->senha = (char*)malloc(sizeof(char*)* 8);
	novobloco->tipo = 0;
    novobloco->usuario_qntd = 1;

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

/*int removerUser(user_dados* l, int codigo)
{
	if( l == NULL)
		return 0;

	user* ant = NULL;
	user* p = l->prim;
	
	while( p != NULL && (p->codigo != codigo) ){
		ant = p;
		p = p->prox;
	}
	
	if( p != NULL )
	{	ant->prox = p->prox;
	
		for(int i = 0; i<p->N; i++)
			free(p->tweets[i]);
		free(p->tweets);
		free(p);
		
		l->tamanho = l->tamanho - 1;
		
		return 1;
	}
	
	return 0;
}*/

/*int apagarListaUser(user_dados** l)
{
	if( l==NULL)
		return 0;
		
	user* p = (*l)->prim;
	while(p != NULL )
	{
		user* t = p->prox;
		for(int i = 0; i<p->N; i++)
			free(p->tweets[i]);
		free(p->tweets);
		free(p);
		p = t;
	}
	
	free( (*l) );
	*l = NULL;
	
	return 1;
}*/

int quantidadeUser(user_dados* l){
	return l->tamanho;
}
