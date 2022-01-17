# PDVTrabsFinal
Trabalho final laboratorio de programaçao em c

programa { 
    "Pode ou n ter grafico"
    autentificaçao{
        Admin
        Funcionario
    }

    Administrador {

        Cadastrar Funcionario{
            nome
            login
            senha
            id funcionario
        }

        Cadastrar produto {
            Nome
            Valor {
                Valor de compra
                Valor de Venda
            }
            ID
            Quantidade?
        }

        Estoque{
            Movimentaçao de estoque{
                "PRODUTO JA CADASTRADO"
                Data/Hora
                Qntd
            }
        }
    }

    Vendas{
        (Consultas de Produto)
        (Movimentaçao de estoque)
        (Nota Fiscal)
        (Relatorio Final)
    } 

    Funcionario {
        Consultas (Estoque)
        Vendas
        Bater ponto?
        
    }

    Fechar Caixa(Relatorio Final)
}
