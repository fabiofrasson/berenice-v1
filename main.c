#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

void saudacao();
void mostraMenu();
float *escolheItemMenu();
float *ordenaItensSubtotal(float *arraySubtotal);
float *subtotal;
float *subtotalOrdenado;
void mostraSubtotal(float *arraySubtotalOrdenado);
int selecionaFormaPagamento();
// void calculaTotalPorFormaPagamento(int opcao);
int ordemProdutos[] = {1, 2, 3, 4, 5};

void limpaTela();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    float valorTroco, parcelas, valorParcela;
    char troco;
    int formaPagamento;

    saudacao();
    // Mostrar o menu
    mostraMenu();

    // C�lculo do subtotal
    subtotal = escolheItemMenu();

    if(subtotal[0] != 0.0 || subtotal[1] != 0.0 || subtotal[2] != 0.0 || subtotal[3] != 0.0 || subtotal[4] != 0.0)
    {
        // Ordena��o dos itens do subtotal
        subtotalOrdenado = ordenaItensSubtotal(subtotal);

        // Mostrar o subtotal
        mostraSubtotal(subtotalOrdenado);

        // Oferecer as op��es de pagamento
        formaPagamento = selecionaFormaPagamento();
    }

    // calculaTotalPorFormaPagamento(formaPagamento);

    /*

        printf("\n\nVoce precisa de troco? (S/N)\n");
        scanf("\n%c", &troco);
        getchar();

        if(troco == 'S' || troco == 's') // Valida��o caso a resposta seja S ou s para troco
        {
            printf("\nTroco para quanto?\n");
            scanf("\n%f", &valorTroco);
            getchar();

            float volta = valorTroco - subtotal;

            printf("\nAqui vai o seu troco: R$ %.2f", volta);
        }
        else if(troco == 'N' || troco == 'n') // Valida��o caso a resposta seja N ou n para troco
        {
            printf("Troco nao e necessario.");
        }
        else
        {
            printf("\nOpcao invalida, reinicie o programa e tente novamente\n");
            return 0;
        }
    }
    else if(opcao == 2)// Se pagamento parcelado for selecionado
    {
        printf("\n\nEm quantas parcelas gostaria de pagar? \n"); //Ap�s selecionar a forma de pagamento 2 que seria a prazo, pergunta para o usu�rio o numero de parcelas desejado.
        scanf("%f", &parcelas);

        if(parcelas < 1)// Se a quantidade de parcelas for menor que 1
        {
            printf("\nQuantidade invalida, reinicie o programa e tente novamente\n");//Printa mensagem de erro
            return 0;//E finaliza o programa
        }
        else if(parcelas >= 1 && parcelas < 3)//Se a quantidade de parcelas for entre 1 e 3
        {
            subtotal += subtotal * 0.05;// Acrescimo no subtotal de 5%
        }
        else // Se a quantidade de parcelas for maior que 3
        {
            subtotal += subtotal * 0.08;// Acrescimo no subtotal de 8%
        }

        valorParcela = subtotal / parcelas;// Valor da parcela eh igual ao subtotal dividido pela quantidade de parcelas (considerando o acr�scimo)

        printf("\nSelecionado: %.0f parcela(s).", parcelas);
        printf("\nO valor de cada parcela sera de: R$ %.2f\n", valorParcela); //Valor de cada parcela.
    }
    else
    {
        printf("\nOpcao invalida, reinicie o programa e tente novamente\n"); // Mensagem de erro
        return 0;
    }

    printf("\n\nObrigado pela sua compra, tenha um otimo dia!\n"); // Mensagem do fim do programa
    */

    printf("\nFim do programa");
    return 0;
}

void saudacao()
{
    printf("\t\t\t\t\tBem-vindo(a) ao...\n");
    printf("\n\t\t\t\t\t +-+-+-+-+-+-+-+ +-+-+  ");
    printf("\n\t\t\t\t\t |M|e|r|c|a|d|o| |d|a|  ");
    printf("\n\t\t\t\t\t +-+-+-+-+-+-+-+-+-+-+-+");
    printf("\n\t\t\t\t\t       |B|e|r|e|n|i|c|e|");
    printf("\n\t\t\t\t\t       +-+-+-+-+-+-+-+-+");
}

void mostraMenu()
{
    printf("\n\n\t\t\tSelecione uma opc�o:\n");
    printf("\n\t\t\t\tC�digo\t\tA��o\n");
    printf("\t\t\t\t1\t\tCadastrar estoque\n");
    printf("\t\t\t\t2\t\tVisualizar estoque\n");
    printf("\t\t\t\t3\t\tRealizar venda\n");
    printf("\t\t\t\t4\t\tSair\n\n\n");
}

/*
menu produtos

printf("\n\n\t\t\tSegue a tabela com os produtos comercializados neste local:\n");
    printf("\n\t\t\t\tCodigo\t\tItem\t\tPreco\n");
    printf("\t\t\t\t1\t\tPao de Forma\tR$ 7.50\n");
    printf("\t\t\t\t2\t\tPao de Centeio\tR$ 8.69\n");
    printf("\t\t\t\t3\t\tBroa de Milho\tR$ 5.00\n");
    printf("\t\t\t\t4\t\tSonho\t\tR$ 4.50\n");
    printf("\t\t\t\t5\t\tTubaina\t\tR$ 3.25\n\n\n");
*/

float *escolheItemMenu()
{
    int resposta = 0, opcao, contador = 0;
    float quantidade;
    static float subtotalUnitario[5];
    float precosItens[] = {7.5, 8.69, 5.0, 4.5, 3.25};

    while(resposta != 1)
    {
        if(contador == 0)
        {
            printf("\nDigite um c�digo de 1 a 5 para selecionar um dos produtos: \n");
            contador++;
        }
        else
        {
            printf("\nDigite um c�digo de 1 a 5 para selecionar um dos produtos ou 0 para sair: \n");
        }

        scanf("%d", &opcao);
        getchar();

        if(opcao == 0)
        {
            break;
        }

        while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 0)
        {
            printf("\nOp��o inv�lida! Digite uma op��o v�lida:\n");
            scanf("%d", &opcao);
            getchar();

            if(opcao == 0)
            {
                break;
            }
        }

        if(opcao == 1)
        {
            printf("\nProduto escolhido: P�o de F�rma\n");
        }
        else if(opcao == 2)
        {
            printf("\nProduto escolhido: P�o de Centeio\n");
        }
        else if(opcao == 3)
        {
            printf("\nProduto escolhido: Broa de Milho\n");
        }
        else if(opcao == 4)
        {
            printf("\nProduto escolhido: Sonho\n");
        }
        else if(opcao == 5)
        {
            printf("\nProduto escolhido: Tuba�na\n");
        }

        if(opcao != 0)
        {
            printf("\nAgora, digite a quantidade desejada: \n");
            scanf("%f", &quantidade);
            getchar();

            while(quantidade <= 0)
            {
                printf("\nDigite uma quantidade maior que 0:\n");
                scanf("%f", &quantidade);
                getchar();
            }

            switch(opcao)
            {
            case 1:
                subtotalUnitario[0] = precosItens[0] * quantidade;
                printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[0]);
                break;
            case 2:
                subtotalUnitario[1] = precosItens[1] * quantidade;
                printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[1]);
                break;
            case 3:
                subtotalUnitario[2] = precosItens[2] * quantidade;
                printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[2]);
                break;
            case 4:
                subtotalUnitario[3] = precosItens[3] * quantidade;
                printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[3]);
                break;
            case 5:
                subtotalUnitario[4] = precosItens[4] * quantidade;
                printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[4]);
                break;
            default:
                break;
            }
        }
    }

    return subtotalUnitario;
}

float  * ordenaItensSubtotal(float * arraySubtotal)
{
    float nroAuxiliar, nroAuxiliar2;
    int contador;

    for(contador = 1; contador < 5; contador++)
    {
        for(int i = 0; i < 5; i++)
        {
            if(arraySubtotal[i] < arraySubtotal[i + 1])
            {
                nroAuxiliar = arraySubtotal[i];
                nroAuxiliar2 = ordemProdutos[i];

                arraySubtotal[i] = arraySubtotal[i + 1];
                ordemProdutos[i] = ordemProdutos[i + 1];

                arraySubtotal[i + 1] = nroAuxiliar;
                ordemProdutos[i + 1] = nroAuxiliar2;
            }
        }
    }

    return arraySubtotal;
}

void mostraSubtotal(float *arraySubtotalOrdenado)
{
    printf("\nO subtotal �:\n");

    for(int i = 0; i < 5; i++)
    {
        if(arraySubtotalOrdenado[i] >= 0.01)
        {
            printf("\nItem %d: R$ %.2f", ordemProdutos[i], arraySubtotalOrdenado[i]);
        }

    }
}

int selecionaFormaPagamento()
{
    int opcao;

    // Selecionar a forma de pagamento
    printf("\n\nQual seria a forma de pagamento?\n");
    printf("\n\t\t\t\tC�digo\t\tForma\n");
    printf("\t\t\t\t1\t\t� vista\n");
    printf("\t\t\t\t2\t\t� prazo\n");

    printf("\nDigite a forma desejada: \n");
    scanf("%i", &opcao);
    getchar();

    while(opcao != 1 && opcao != 2)
    {
        printf("\nOp��o inv�lida; digite uma forma de pagamento v�lida:\n");
        printf("\n\t\t\t\tC�digo\t\tForma\n");
        printf("\t\t\t\t1\t\t� vista\n");
        printf("\t\t\t\t2\t\t� prazo\n");
        scanf("%i", &opcao);
        getchar();
    }

    return opcao;
}
/*
void calculaTotalPorFormaPagamento(int opcao)
{
    // Fun��o para calcular o total com base na op��o de pagamento
    if(opcao == 1)// Se o pagamento for a vista
    {
        if(subtotal > 0 && subtotal <= 50) // Se subtotal for entre 0 e 50
        {
            subtotal -= subtotal * 0.05; //Desconto de 5% aplicado ao valor final
        }
        else if(subtotal > 50 && subtotal < 100)//Se o subtotal for entre 50 e 100
        {
            subtotal -= subtotal * 0.1;//Desconto de 10% aplicado ao valor final
        }
        else
        {
            subtotal -= subtotal * 0.18;// Desconto de 18% aplicado ao valor final
        }
        printf("\nO total e R$ %.2f", subtotal);
    }
*/

void limpaTela()
{
#ifdef __linux__
    system.("clear");
#elif _WIN32
    system("cls");
#else

#endif
}
