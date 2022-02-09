#include "lib.h"

void FazerVenda(ListaBlocos* l, cesta_dados* c){
    produto* aux = l->prim;
    carrinho* help = c->prim;
    int tam = 1;
    inserirCesta(c);
    int choice; 
    /*if(aut != 1) Futuro Caixa
        return;*/
    while(1){
        int sair=-1, id = 0, qnt, contador = 0; 
        float total=0, pago = 0;

        MostraCarrinho(c, tam);
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
            fazerCesta(c, aux->nome, aux->id, aux->qntd, total, contador);
            contador++;
            break;
        case 2:
            printf("Id produto para remover do carrinho\n");
            scanf("%d", &id);
            for(int i=0; i < id; i++){
                help = help->prox;
                if(help == NULL)
                    return;
            }
            if(help->id_produto != id){
                printf("Produto nao encontrado\n", aux->nome);
                return
            }
            //Remover()
            break;
        default:
            break;
        }
    }
}

/*void FazerVenda(ListaBlocos* l, cesta_dados* c){
    produto* aux = l->prim;
    int sair=-1, id = 0, qnt, contador = 1; 
    float total=0, pago = 0;
    if(aux == NULL){
		printf("*** Sem Produto ***\n");
        getchar();
		return;
	}
    inserirCesta(c, N);
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
        fazerCesta(c, aux->nome, aux->id, aux->qntd, total, contador)
        contador++;
        printf("Adicionar outro produto? Digite 1 para sair:");
        scanf("%d", &sair);
    }while(sair != 1);
    
    printf("Valor PAGO: ");
    scanf("%f", &pago);
    printf("Troco: %.2f", pago - total);
}*/