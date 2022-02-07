#include "lib.h"

//-----------------------------------------TODOS-----------------------------------------
void adduser(user_dados* l, char*  str, char *psw, int tipo){
    user* aux = l->prim;
	if(aux == NULL){
        inserirUser(l);
        strcpy(l->ult->login, str);
        strcpy(l->ult->senha, psw);
        l->ult->tipo = tipo;
        l->user_qntd = l->ult->usuario_qntd;
    }
    else if(aux != NULL){
        inserirUser(l);
        strcpy(l->ult->login, str);
        strcpy(l->ult->senha, psw);
        l->ult->tipo = tipo;
        l->ult->usuario_qntd = l->user_qntd + 1;
        l->user_qntd =  l->ult->usuario_qntd;
    }
}

void ListarContas(user_dados* l){
	user* aux = l->prim;

    if(aux == NULL){
		printf("*** Sem Conta ***\n");
        getchar();
		return;
	}
    printf("\n*--------------------Contas[%d]--------------------*\n", l->user_qntd);
    printf("Conta |Senha  |Tipo\n");      
    do{
        printf("%s |%s      |%d\n", aux->login, aux->senha, aux->tipo);
        aux = aux->prox;
    } while(aux != NULL);
    printf("*------------------------------------------------*\n");
    getchar();
}

int fazer_login(user_dados* lg, char *str, char *psw){
    user* aux = lg->prim;

    for(int i = 0; i < lg->user_qntd; i++){
        do{
            if(strcmp(str, aux->login) == 0){
                printf("Entrou1\n");
                if(strcmp(aux->senha, psw) == 0 && aux->tipo == 1){
                    printf("Administrador autenticado com sucesso!\n");
                    return 1;
                }else if(strcmp(aux->senha, psw) == 0 && aux->tipo == 0){
                    printf("Funcionario autenticado com sucesso!\n");
                    return 0;
                }else{
                    printf("Senha incorreta!\n");
                    return 2;
                }
            }
            aux = aux->prox;
        }while(aux != NULL);
    }
    return -1;
}
//-----------------------------------------ADMIN-----------------------------------------


void addproduto(ListaBlocos* l, char*  str, int barra, float vcompra, float vvenda){
    produto* aux = l->prim;
	if(aux == NULL){
        inserirBloco(l);
        l->ult->nome = (char*)malloc(sizeof(char) * strlen(str)+1 );
	    strcpy( l->ult->nome, str);
        l->ult->cod_barra = barra;
        l->ult->valorcompra = vcompra;
        l->ult->valorvenda = vvenda;
        l->id_p = l->ult->id;
	}
    else if(aux != NULL){
        inserirBloco(l);
        l->ult->nome = (char*)malloc(sizeof(char) * strlen(str)+1 );
	    strcpy( l->ult->nome, str);
        l->ult->cod_barra = barra;
        l->ult->valorcompra = vcompra;
        l->ult->valorvenda = vvenda;
        l->ult->id = l->id_p + 1;
        l->id_p =  l->ult->id;
    }

}

void AdicionarEstoque(ListaBlocos* l, int id){
    produto* aux = l->prim;
    int qnt;
    if(aux == NULL){
		printf("*** Sem Produto ***\n");
        getchar();
		return;
	}

    for(int i=0; i < id; i++){
        aux = aux->prox;
        if(aux == NULL){
            return;
        }
    }
    printf("ID: %d   |Nome: %s   |Quantidade: %d\n", aux->id, aux->nome, aux->qntd);
    printf("Digite a quatidade que vai ser adicionada (UND)\n");
    scanf("%d", &qnt);
    aux->qntd += qnt;
}

//--------------------------------------------------Funcionario--------------------------------------------------
void FazerVenda(ListaBlocos* l){
    produto* aux = l->prim;
    int sair=-1, id = 0, qnt; 
    float total=0, pago = 0;
    if(aux == NULL){
		printf("*** Sem Produto ***\n");
        getchar();
		return;
	}
    
    do{
        printf("Id produto para adicionar ao carrinho\n");
        scanf("%d", &id);
        for(int i=0; i < id; i++){
            aux = aux->prox;
            if(aux == NULL)
                return;
        }
        printf("ID: %d   |Nome: %s   |Quantidade: %d| Valor(UND): %2.f\n", aux->id, aux->nome, aux->qntd, aux->valorvenda);
        if(aux->qntd == 0){
            printf("Produto %s indisponivel\n", aux->nome);
            FazerVenda(l);
        }
        printf("Digite a quantidade do produto\n");
        scanf("%d", &qnt);
        aux->qntd -= qnt;
        total += qnt * aux->valorvenda;
        printf("Total do carrinho: %2.f\n", total);
        printf("Adicionar outro produto? Digite 1 para sair:");
        scanf("%d", &sair);
    }while(sair != 1);
    printf("Valor PAGO: ");
    scanf("%2.f", &pago);
    printf("Troco: %2.f", pago - total);
}

void ListarProdutos(ListaBlocos* l, int aut){
	produto* aux = l->prim;

    if(aux == NULL){
		printf("*** Sem Produto ***\n");
        getchar();
		return;
	}
	if(aut == 0){
        printf("\n*--------------------Produtos--------------------*\n");
        printf("Codico |Produto                |Codico Barra                |Quantidade                |Valor \n");      
        do{
            printf("%d      |%s                       |%d                           |%d                |%2.f\n", aux->id, aux->nome, aux->cod_barra, aux->qntd, aux->valorvenda);
            aux = aux->prox;
        } while(aux != NULL);
        printf("*------------------------------------------------*\n");
    }
    else if(aut == 1){
        printf("\n*--------------------Produtos--------------------*\n");
        printf("Codico |Produto       |Codico Barra |Quantidade     |Valor de Venda       |Valor de Compra\n");      
        do{
            printf("%d      |%s       |%d        |%d          |%2.f            |%2.f\n", aux->id, aux->nome, aux->cod_barra, aux->qntd, aux->valorvenda, aux->valorcompra);
            aux = aux->prox;
        } while(aux != NULL);
        printf("*------------------------------------------------*\n");
    }
    getchar();
}