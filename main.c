// Declaracao de Bibliotecas para linguagem C
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float forma = 7.50, centeio = 8.69, broa = 5.00, sonho = 4.50, tubaina = 3.25, valorUnitario, subtotal, valorTroco, parcelas, valorParcela; // Atribuicao de Valores para os produtos
    int opcao, quantidade; // Variavel para guardar o codigo do produto que o usuario vai comprar
    char troco;

    // Printando a tabela de produtos no Terminal
    printf("--------------------------------------------------------------------------------\n");
    printf("\t\tBem Vindo ao Mercadinho da Berenice!\t\t\n");
    printf("\t\tSegue a tabela com os produtos comercializados neste local:\n");
    printf("\n\t\t\t\tCodigo\t\tItem\t\tPreco\n");
    printf("\t\t\t\t1\t\tPao de Forma\tR$7.50\n");
    printf("\t\t\t\t2\t\tPao de Centeio\tR$8.69\n");
    printf("\t\t\t\t3\t\tBroa de Milho\tR$5.00\n");
    printf("\t\t\t\t4\t\tSonho\t\tR$4.50\n");
    printf("\t\t\t\t5\t\tTubaina\t\tR$3.25\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    // Pergunta para o usuario qual o codigo do produto para realizar a compra
    printf("\nDigite um numero referente ao codigo de 1 a 6 para selecionar um dos produtos: \n");
    scanf("%d", &opcao);
    getchar();

    printf("\nAgora, digite a quantidade desejada: \n");
    scanf("%i", &quantidade);
    getchar();

    switch(opcao)
    {
    case 1:
        valorUnitario = forma;
        break;
    case 2:
        valorUnitario = centeio;
        break;
    case 3:
        valorUnitario = broa;
        break;
    case 4:
        valorUnitario = sonho;
        break;
    case 5:
        valorUnitario = tubaina;
        break;
    default:
        break;
    }

    subtotal = quantidade * valorUnitario;

    printf("\nO subtotal e: R$ %.2f\n", subtotal);

    printf("\n\nQual seria a forma de pagamento?\n");
    printf("\n\t\t\t\tCodigo\t\tForma\t\tVariacao\n");
    printf("\t\t\t\t1\t\tA vista\t\t-10%\n");
    printf("\t\t\t\t2\t\tA prazo\t\t+ 5%\n");

    printf("\nDigite a forma desejada: \n");
    scanf("%i", &opcao);
    getchar();

    if(opcao == 'S' || opcao =='s')
    {
        subtotal -= subtotal * 0.1;
    }
    else if(opcao =='N' || opcao =='n')
    {
        subtotal += subtotal * 0.05;
    }

    printf("\nO total e R$ %.2f", subtotal);

    if(opcao == 1)
    {
        printf("\n\nVoce precisa de troco? (S/N)\n");
        scanf("\n%c", &troco);
        getchar();

        if(troco == 'S')
        {
            printf("\nTroco para quanto?\n");
            scanf("\n%f", &valorTroco);
            getchar();

            float volta = valorTroco - subtotal;

            printf("Aqui vai o seu troco: R$ %.2f", volta);
        }
        else if(troco == 'N')
        {
            printf("Troco nao e necessario.");
        }
    }
    else if(opcao == 2)
    {
        printf("\n\nEm quantas parcelas gostaria de pagar? \n");
        scanf("%f", &parcelas);

        valorParcela = subtotal / parcelas;

        printf("\nO valor de cada parcela sera de: R$ %.2f\n", valorParcela);
    }

    printf("\n\nObrigado pela sua compra, tenha um otimo dia!\n");

    return 0;
}
