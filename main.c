// Declaracao de Bibliotecas para linguagem C
#include <stdio.h>
#include <stdlib.h>

int main()//Comeco do programa
{
    float forma = 7.50, centeio = 8.69, broa = 5.00, sonho = 4.50, tubaina = 3.25, valorUnitario, subtotal, valorTroco, parcelas, valorParcela; // Atribuicao de Valores para os produtos.
    int opcao, quantidade; // Variavel para guardar o codigo do produto que o usuario vai comprar.
    char troco; // Variavel para demonstrar qual será o troco do cliente, se necessário.

    // Printando a tabela de produtos no Terminal
    printf("--------------------------------------------------------------------------------\n");
    printf("\t\t\t\tBem Vindo ao Mercadinho da Berenice!\t\t\n");
    printf("\t\t\tSiga a tabela com os produtos comercializados neste local:\n");
    printf("\n\t\t\t\tCodigo\t\tItem\t\tPreco\n");
    printf("\t\t\t\t1\t\tPao de Forma\tR$7.50\n");
    printf("\t\t\t\t2\t\tPao de Centeio\tR$8.69\n");
    printf("\t\t\t\t3\t\tBroa de Milho\tR$5.00\n");
    printf("\t\t\t\t4\t\tSonho\t\tR$4.50\n");
    printf("\t\t\t\t5\t\tTubaina\t\tR$3.25\n\n\n");
    printf("--------------------------------------------------------------------------------\n");

    // Pergunta para o usuario qual o codigo do produto para realizar a compra
    printf("\nDigite um numero referente ao codigo de 1 a 5 para selecionar um dos produtos: \n");
    scanf("%d", &opcao);
    getchar();

    if(opcao < 1 || opcao > 5)//Caso o usuario digite um numero menor que 1 ou maior que 5, Printa mensagem de erro
    {
        printf("\nOpcao invalida, reinicie o programa e tente novamente\n");
        return 0;
    }
    //Esse switch serviu como um coringa para cada variavel com o valor armazenado
    switch(opcao)
    {
    case 1:
        valorUnitario = forma;//Atribui dentro do case 1 o valor atruibuido a variavel forma para a variavel coringa valor unitario
        break;//Comando para impedir que o proximo case seja executado na sequencia do codigo
    case 2:
        valorUnitario = centeio;//Atribui dentro do case 2 o valor atruibuido a variavel centeio para a variavel coringa valor unitario
        break;//Comando para impedir que o proximo case seja executado na sequencia do codigo
    case 3:
        valorUnitario = broa;//Atribui dentro do case 3 o valor atruibuido a variavel broa para a variavel coringa valor unitario
        break;//Comando para impedir que o proximo case seja executado na sequencia do codigo
    case 4:
        valorUnitario = sonho;//Atribui dentro do case 4 o valor atruibuido a variavel sonho para a variavel coringa valor unitario
        break;//Comando para impedir que o proximo case seja executado na sequencia do codigo
    case 5:
        valorUnitario = tubaina;//Atribui dentro do case 5 o valor atruibuido a variavel tubaina para a variavel coringa valor unitario
        break;//Comando para impedir que o proximo case seja executado na sequencia do codigo
    default:
        break;//Comando para impedir que o proximo case seja executado na sequencia do codigo
    }
    //Apos o switch case o codigo prossegue solicitando a quantidade e em seguida indo para o pagamento e troco
    printf("\nAgora, digite a quantidade desejada: \n"); // Selecionar a quantidade desejada do produto, que foi anteriormente escolhida pelo cliente.
    scanf("%i", &quantidade);
    getchar();

    if(quantidade < 1)//Se a quantidade for menor do que 1 unidade, mensagem de erro
    {
        printf("\nQuantidade invalida, reinicie o programa e tente novamente\n");
        return 0;
    }

    subtotal = quantidade * valorUnitario;//Aqui ele vai calcular a quantidade * o valor unitario do produto que o usuario selecionou no case

    printf("\nO subtotal e: R$ %.2f\n", subtotal);

    printf("\n\nQual seria a forma de pagamento?\n");
    printf("\n\t\t\t\tCodigo\t\tForma\t\tVariacao (%%)\n");
    printf("\t\t\t\t1\t\tA vista\t\t- 10%\n");
    printf("\t\t\t\t2\t\tA prazo\t\t+ 5%\n");

    printf("\nDigite a forma desejada: \n");//Selecione a forma de pagamento para proseguir com a compra
    scanf("%i", &opcao);
    getchar();

    if(opcao == 1)//Se o usuario selecionar 1 sera o pagamento a vista
    {
        subtotal -= subtotal * 0.1;//O subtotal vai subtrair o valor de desconto do subtotal da compra
        printf("\nO total e R$ %.2f", subtotal);// E vai ser printado o valor para o usuario
        printf("\n\nVoce precisa de troco? (S/N)\n");//Apos isso vai ser printar se o usuario necessitara de troco
        scanf("\n%c", &troco);//A depender da tecla selecionada o codigo seguira para a parte de calculo do troco
        getchar();

        if(troco == 'S' || troco == 's')//Se o usuario digitar S ou s, Vai pedir quanto de troco ele vai precisar
        {
            printf("\nTroco para quanto?\n");//
            scanf("\n%f", &valorTroco);
            getchar();

            float volta = valorTroco - subtotal;//Aqui vai ser feito o calculo do troco

            printf("Aqui vai o seu troco: R$ %.2f", volta);
        }
        else if(troco == 'N' || troco == 'n')//Se o usuario digitar N ou n vai printar que ele nao precisa de troco
        {
            printf("Troco nao e necessario.");
        }
        else
        {
            printf("\nOpcao invalida, reinicie o programa e tente novamente\n");
            return 0;
        }
    }
    else if(opcao == 2)//Se o usuario digitar a opcao 2 vai entrar no pagamento parcelado
    {
        subtotal += subtotal * 0.05;//E o subtotal vai subtrair o valor de desconto no valor subtotal da compra
        printf("\nO total e R$ %.2f", subtotal);//Apos isso vai ser printado quanto ficou com o desconto
        printf("\n\nEm quantas parcelas gostaria de pagar? \n"); //Após selecionar a forma de pagamento 2 que seria a prazo, pergunta para o usuário o numero de parcelas desejado.
        scanf("%f", &parcelas);

        valorParcela = subtotal / parcelas;//O valor da parcela vai ser dividido entre a quantidade de parcelas

        printf("\nO valor de cada parcela sera de: R$ %.2f\n", valorParcela); //Valor de cada parcela printado para o usuario
    }
    else//Se o usuario teclar algo diferente de 1 ou 2 vai ser printado uma mensagem de erro
    {
        printf("\nOpcao invalida, reinicie o programa e tente novamente\n");
        return 0;
    }

    printf("\n\nObrigado pela sua compra, tenha um otimo dia!\n");//Mensagem final para quando a compra for finalizada

    return 0;//Fim do programa
}

