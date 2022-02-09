#include "lib.h"

//-----------------------------------------TODOS-----------------------------------------
int fazer_login(user_dados* lg, char *str, char *psw){
    user* aux = lg->prim;

    for(int i = 0; i < lg->user_qntd; i++){
        do{
            if(strcmp(str, aux->login) == 0){
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
    printf("Login ou Senha incorreta:\n");
    return -1;
}
//-----------------------------------------ADMIN-----------------------------------------

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

void FazerVenda(ListaBlocos* l, cesta_dados* c){
    produto* aux = l->prim;
    carrinho* help = c->prim;
    int contador = 0;

    int choice; 
    /*if(aut != 1) Futuro Caixa
        return;*/
    while(1){
        int sair=-1, id = 0, qnt; 
        float total=0, pago = 0;

        MostraCarrinho(c, contador);
        printf("\n*----------------------- Caixa -----------------------*\n");
        printf("* 1-| Adicionar ao carrinho:                            *\n");
        printf("* 2-| Remover produto do carrinho:                      *\n");
        printf("* 3-| Finalizar venda:                                  *\n");
        printf("*-------------------------------------------------------*\n");
        printf("Opção: ");
        scanf("%d", &choice);
        getchar();
        if(choice == 3)
            break;
        switch (choice){
        case 1:
            if(contador==0)
                c->total_carrinho = 0;
            inserirCesta(c);
            printf("Id produto para adicionar ao carrinho\n");
            scanf("%d", &id);
            for(int i=0; i < id; i++){
                if(aux == NULL){
                    printf("ERRO:\n");
                    return;
                }
                aux = aux->prox;
            }
            printf("ID: %d   |Nome: %s   |Quantidade: %d| Valor(UND): %2.f\n", aux->id, aux->nome, aux->qntd, aux->valorvenda);
            if(aux->qntd == 0){
                printf("Produto %s indisponivel\n", aux->nome);
                FazerVenda(l,c);
            }
            printf("Digite a quantidade do produto\n");
            scanf("%d", &qnt);
            getchar();
            aux->qntd -= qnt;
            total = total + (qnt * aux->valorvenda);
            contador++;
            fazerCesta(c, aux->nome, id, qnt, total);            
            break;
        case 2:
            printf("Id produto para remover do carrinho\n");
            scanf("%d", &id);
            for(int i=0; i < id; i++){
                help = help->prox;
                if(help == NULL)
                    return;
                if(help->id_produto != id){
                    printf("Produto nao encontrado\n");
                    return;
                }
            }
            removerCesta(c, id);
            contador--;
            printf("Produto removido com sucesso\n");
            break;
        default:
            break;
        }
    }
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

//--------------------------------------------------Carrinho--------------------------------------------------
void fazerCesta(cesta_dados* c, char*  str, int id_prod, int qnt_prod, float total_prod){
	
	c->ult->nome_produto = (char*)malloc(sizeof(char) * strlen(str)+1 );
	strcpy( c->ult->nome_produto, str);
                                               
	c->ult->id_produto= id_prod;
	c->ult->qnt_produto= qnt_prod;

    c->ult->total_produto += total_prod;
    c->total_carrinho += c->ult->total_produto;
    
}

void MostraCarrinho(cesta_dados* c, int tam){
	carrinho* aux = c->prim;
    if(tam == 0){
		printf("*** Carrinho Vazio ***\n");
		return;
	}
    printf("\n*--------------------- Carrinho ----------------------*\n");
    printf("Codico |Produto            |Quantidade              |Total \n");      
    do{
        if(aux->nome_produto != NULL)
            printf("%d      |%s                  |%d                |%.2f\n", aux->id_produto, aux->nome_produto, aux->qnt_produto, aux->total_produto);
        aux = aux->prox;
    }while(aux != NULL);
    printf("                                                  |%.2f\n", c->total_carrinho);
    printf("*-------------------------------------------------------*\n");
}