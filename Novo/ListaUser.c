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

int quantidadeUser(user_dados* l){
	return l->tamanho;
}
