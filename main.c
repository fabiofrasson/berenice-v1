// Comandos pré-processamento
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>

// Constantes das opções do menu
#define menuOpcao1 "Cadastrar estoque"
#define menuOpcao2 "Visualizar estoque"
#define menuOpcao3 "Realizar venda"
#define menuOpcao4 "Sair"

// Constantes dos nomes dos produtos
#define produtoOpcao1 "Pão de Fôrma"
#define produtoOpcao2 "Pão de Centeio"
#define produtoOpcao3 "Broa de Milho"
#define produtoOpcao4 "Sonho"
#define produtoOpcao5 "Tubaína"

// Constantes dos preços dos produtos
#define precoProduto1 7.85
#define precoProduto2 8.69
#define precoProduto3 5.00
#define precoProduto4 4.5
#define precoProduto5 3.25

// Métodos
void saudacao();
void mostrarMenu();
int escolherItemMenu();
void mostrarItensEstoque();
void cadastrarEstoque();
void realizarVenda(); // ?
void delay(int milliseconds);

void limparTela();

// Arrays globais
int estoqueItens[] = {0, 0, 0, 0, 0};
int ordemProdutos[] = {1, 2, 3, 4, 5};

// float *escolherItemMenu();
float *ordenaItensSubtotal(float *arraySubtotal);
float *subtotal;
float *subtotalOrdenado;
void mostraSubtotal(float *arraySubtotalOrdenado);
int selecionaFormaPagamento();
// void calculaTotalPorFormaPagamento(int opcao);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    float valorTroco, parcelas, valorParcela;
    char troco;
    int formaPagamento;

    saudacao();

    // Mostrar o menu
    mostrarMenu();

    int opcaoMenu = escolherItemMenu();

    if(opcaoMenu == 1)
    {
        cadastrarEstoque();
    }
    else if(opcaoMenu == 2)
    {
        // delay(500);
        // limparTela();
        // delay(500);

        mostrarItensEstoque();
    }
    else if(opcaoMenu == 3)
    {
        //printf("\n%s", opcao3);
    }
    else
    {
        //printf("\n%s", opcao4);
    }

    // Cálculo do subtotal
    // subtotal = escolherItemMenu();

    if(subtotal[0] != 0.0 || subtotal[1] != 0.0 || subtotal[2] != 0.0 || subtotal[3] != 0.0 || subtotal[4] != 0.0)
    {
        // Ordenação dos itens do subtotal
        //subtotalOrdenado = ordenaItensSubtotal(subtotal);

        // Mostrar o subtotal
        //mostraSubtotal(subtotalOrdenado);

        // Oferecer as opções de pagamento
        formaPagamento = selecionaFormaPagamento();
    }

    // calculaTotalPorFormaPagamento(formaPagamento);

    /*

        printf("\n\nVoce precisa de troco? (S/N)\n");
        scanf("\n%c", &troco);
        getchar();

        if(troco == 'S' || troco == 's') // Validação caso a resposta seja S ou s para troco
        {
            printf("\nTroco para quanto?\n");
            scanf("\n%f", &valorTroco);
            getchar();

            float volta = valorTroco - subtotal;

            printf("\nAqui vai o seu troco: R$ %.2f", volta);
        }
        else if(troco == 'N' || troco == 'n') // Validação caso a resposta seja N ou n para troco
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
        printf("\n\nEm quantas parcelas gostaria de pagar? \n"); //Após selecionar a forma de pagamento 2 que seria a prazo, pergunta para o usuário o numero de parcelas desejado.
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

        valorParcela = subtotal / parcelas;// Valor da parcela eh igual ao subtotal dividido pela quantidade de parcelas (considerando o acréscimo)

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
    printf("\t\t\t\t\tBem-vindo(a) ao\n");
    printf("\n\t\t\t\t\t +-+-+-+-+-+-+-+ +-+-+  ");
    printf("\n\t\t\t\t\t |M|e|r|c|a|d|o| |d|a|  ");
    printf("\n\t\t\t\t\t +-+-+-+-+-+-+-+-+-+-+-+");
    printf("\n\t\t\t\t\t       |B|e|r|e|n|i|c|e|");
    printf("\n\t\t\t\t\t       +-+-+-+-+-+-+-+-+");
}

void mostrarMenu()
{
    printf("\n\n\n\t\t\t\tCódigo\t\tAção\n");
    printf("\t\t\t\t1\t\t%s\n", menuOpcao1);
    printf("\t\t\t\t2\t\t%s\n", menuOpcao2);
    printf("\t\t\t\t3\t\t%s\n", menuOpcao3);
    printf("\t\t\t\t4\t\t%s\n\n\n", menuOpcao4);
}

int escolherItemMenu()
{
    int resposta = 0;

    printf("Selecione um código do menu acima para interagir com o sistema:\n");
    scanf("%d", &resposta);

    while(resposta != 1 && resposta != 2 && resposta != 3 && resposta != 4)
    {
        limparTela();

        mostrarMenu();

        printf("Erro: Opção inválida. Por favor, digite uma opção válida:\n");
        scanf("%d", &resposta);
    }

    return resposta;
}

void mostrarItensEstoque()
{
    printf("\n\t\t\t\tItem (Código)\t\tNome do item\t\tValor (unidade)\t\tEstoque\n");
    printf("\t\t\t\t1\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao1, precoProduto1, estoqueItens[0]);
    printf("\t\t\t\t2\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao2, precoProduto2, estoqueItens[1]);
    printf("\t\t\t\t3\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao3, precoProduto3, estoqueItens[2]);
    printf("\t\t\t\t4\t\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", produtoOpcao4, precoProduto4, estoqueItens[3]);
    printf("\t\t\t\t5\t\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", produtoOpcao5, precoProduto5, estoqueItens[4]);
}

void cadastrarEstoque()
{
    int opcao, quantidade;

    mostrarItensEstoque();

    printf("\n\nDigite o código do produto que deseja atualizar estoque:\n");
    scanf("%d", &opcao);

    while(opcao != ordemProdutos[0] && opcao != ordemProdutos[1] && opcao != ordemProdutos[2] && opcao != ordemProdutos[3] && opcao != ordemProdutos[4])
    {
        printf("\nCódigo de item inválido.\n");

        mostrarItensEstoque();

        printf("\nDigite um código de item válido:\n");
        scanf("%d", &opcao);
    }
    if(opcao == ordemProdutos[0])
    {
        printf("\nItem código %d selecionado: %s\n",ordemProdutos[0], produtoOpcao1);
    }
    else if(opcao == ordemProdutos[1])
    {
        printf("\nItem código %d selecionado: %s\n",ordemProdutos[1], produtoOpcao2);;
    }
    else if(opcao == ordemProdutos[2])
    {
        printf("\nItem código %d selecionado: %s\n",ordemProdutos[2], produtoOpcao3);
    }
    else if(opcao == ordemProdutos[3])
    {
        printf("\nItem código %d selecionado: %s\n",ordemProdutos[3], produtoOpcao4);
    }
    else
    {
        printf("\nItem código %d selecionado: %s\n",ordemProdutos[4], produtoOpcao5);
    }

    printf("\nDigite a quantidade de itens para atualizar o estoque:\n");
    scanf("%d", &quantidade);

    while(quantidade <= 0)
    {
        printf("\nQuantidade inválida, a mesma deve ser maior que zero. Digite uma quantidade válida:\n");
        scanf("%d", &quantidade);
    }

    estoqueItens[opcao - 1] += quantidade;

    mostrarItensEstoque();
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

/*
float *escolherItemMenu()
{
    int resposta = 0, opcao, contador = 0;
    float quantidade;
    static float subtotalUnitario[5];
    float precosItens[] = {7.5, 8.69, 5.0, 4.5, 3.25};

    while(resposta != 1)
    {
        if(contador == 0)
        {
            printf("\nDigite um código de 1 a 5 para selecionar um dos produtos: \n");
            contador++;
        }
        else
        {
            printf("\nDigite um código de 1 a 5 para selecionar um dos produtos ou 0 para sair: \n");
        }

        scanf("%d", &opcao);
        getchar();

        if(opcao == 0)
        {
            break;
        }

        while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 0)
        {
            printf("\nOpção inválida! Digite uma opção válida:\n");
            scanf("%d", &opcao);
            getchar();

            if(opcao == 0)
            {
                break;
            }
        }

        if(opcao == 1)
        {
            printf("\nProduto escolhido: Pão de Fôrma\n");
        }
        else if(opcao == 2)
        {
            printf("\nProduto escolhido: Pão de Centeio\n");
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
            printf("\nProduto escolhido: Tubaína\n");
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
    printf("\nO subtotal é:\n");

    for(int i = 0; i < 5; i++)
    {
        if(arraySubtotalOrdenado[i] >= 0.01)
        {
            printf("\nItem %d: R$ %.2f", ordemProdutos[i], arraySubtotalOrdenado[i]);
        }

    }
}
*/

int selecionaFormaPagamento()
{
    int opcao;

    // Selecionar a forma de pagamento
    printf("\n\nQual seria a forma de pagamento?\n");
    printf("\n\t\t\t\tCódigo\t\tForma\n");
    printf("\t\t\t\t1\t\tÀ vista\n");
    printf("\t\t\t\t2\t\tÀ prazo\n");

    printf("\nDigite a forma desejada: \n");
    scanf("%i", &opcao);
    getchar();

    while(opcao != 1 && opcao != 2)
    {
        printf("\nOpção inválida; digite uma forma de pagamento válida:\n");
        printf("\n\t\t\t\tCódigo\t\tForma\n");
        printf("\t\t\t\t1\t\tÀ vista\n");
        printf("\t\t\t\t2\t\tÀ prazo\n");
        scanf("%i", &opcao);
        getchar();
    }

    return opcao;
}
/*
void calculaTotalPorFormaPagamento(int opcao)
{
    // Função para calcular o total com base na opção de pagamento
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

void delay(int milliseconds)
{
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

void limparTela()
{
#ifdef __linux__
    system.("clear");
#elif _WIN32
    system("cls");
#else

#endif
}
