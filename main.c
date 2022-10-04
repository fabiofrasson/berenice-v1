// Comandos pré-processamento
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>

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
#define precoProduto3 5.0
#define precoProduto4 4.5
#define precoProduto5 3.25

// Constante de valor zerado
#define valorZerado 0.0

// Constante string Subtotal
const char subtotalSt[] = "Subtotal";

// Constante do tamanho dos arrays
#define tamanhoArray 5

// Constante de parâmetro da função de transição
#define segundos 750

// Métodos
void saudacao();
void mostrarMenu();
int escolherItemMenu();
int chamaMenu();
void visualizarItens();
void visualizarItensCadastrarEstoque();
void visualizarItensVisualizarEstoque();
void cadastrarEstoque();
bool verificarEstoque(int codProduto, int quant);
void realizarVenda(); // ?
void exibeSubtotalOrdenado(float arraySubtotal[]);
void ordenaItensSubtotal(float arraySubtotal[]);
int verificarParcelasPagtoPrazo();
void calculaTotalPorFormaPagamento(int opcao);
void gerarRelatorio();
void delay(int milliseconds);
void limparTela();
void transicao();

// Variáveis globais
bool retornaInicio = true;
float subtotal;
char troco;
float valorTroco;

// Arrays globais
int estoqueItens[] = {10, 10, 10, 10, 10};
int quantVendida[tamanhoArray];
int ordemProdutos[] = {1, 2, 3, 4, 5};
int arrayOrdenacaoProdutos[] = {1, 2, 3, 4, 5};
float subtotalUnitario[tamanhoArray];

int main()
{
    setlocale(LC_ALL, "Portuguese");

    while (retornaInicio == true)
    {
        saudacao();

        // Mostrar o menu
        mostrarMenu();
        int opcaoMenu = escolherItemMenu();
        transicao();

        if(opcaoMenu == 1) // Cadastrar estoque
        {
            cadastrarEstoque();
        }
        else if(opcaoMenu == 2) // Visualizar estoque
        {
            visualizarItensVisualizarEstoque();
        }
        else if(opcaoMenu == 3) // Realizar venda
        {
            realizarVenda();
        }
        else // Sair
        {

            transicao();
            return 0;
        }
    }
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

    printf("\nSelecione um código do menu acima para interagir com o sistema:\n");
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

void visualizarItens()
{
    printf("\n\t\t\t\tItem (Código)\t\tNome do item\t\tValor (unidade)\t\tEstoque\n");
    printf("\t\t\t\t1\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao1, precoProduto1, estoqueItens[0]);
    printf("\t\t\t\t2\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao2, precoProduto2, estoqueItens[1]);
    printf("\t\t\t\t3\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao3, precoProduto3, estoqueItens[2]);
    printf("\t\t\t\t4\t\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", produtoOpcao4, precoProduto4, estoqueItens[3]);
    printf("\t\t\t\t5\t\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", produtoOpcao5, precoProduto5, estoqueItens[4]);
}

void visualizarItensVisualizarEstoque()
{
    int numero;
    while(numero != 1)
    {
        printf("\n\t\t\t\tItem (Código)\t\tNome do item\t\tValor (unidade)\t\tEstoque\n");
        printf("\t\t\t\t1\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao1, precoProduto1, estoqueItens[0]);
        printf("\t\t\t\t2\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao2, precoProduto2, estoqueItens[1]);
        printf("\t\t\t\t3\t\t\t%s\t\tR$ %.2f\t\t\t%d\n", produtoOpcao3, precoProduto3, estoqueItens[2]);
        printf("\t\t\t\t4\t\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", produtoOpcao4, precoProduto4, estoqueItens[3]);
        printf("\t\t\t\t5\t\t\t%s\t\t\tR$ %.2f\t\t\t%d\n", produtoOpcao5, precoProduto5, estoqueItens[4]);

        printf("\n\nPressione 1 para voltar ao menu principal.\n");
        scanf("%d", &numero);
        getchar();

        transicao();
    }
}

void visualizarItensCadastrarEstoque()
{
    printf("\n\t\t\t\tItem (Código)\t\tNome do item\n");
    printf("\t\t\t\t1\t\t\t%s\n", produtoOpcao1);
    printf("\t\t\t\t2\t\t\t%s\n", produtoOpcao2);
    printf("\t\t\t\t3\t\t\t%s\n", produtoOpcao3);
    printf("\t\t\t\t4\t\t\t%s\n", produtoOpcao4);
    printf("\t\t\t\t5\t\t\t%s\n", produtoOpcao5);
}

void cadastrarEstoque()
{
    int opcao, quantidade;

    visualizarItensCadastrarEstoque();

    printf("\n\nDigite o código do produto que deseja atualizar estoque:\n");
    scanf("%d", &opcao);

    while(opcao != ordemProdutos[0] && opcao != ordemProdutos[1] && opcao != ordemProdutos[2] && opcao != ordemProdutos[3] && opcao != ordemProdutos[4])
    {
        printf("\nCódigo de item inválido.\n");

        transicao();

        visualizarItensCadastrarEstoque();

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

    switch(opcao)
    {
    case 1:
        printf("\nEstoque do item %s atualizado em %d unidade(s).\n", produtoOpcao1, quantidade);
        delay(1000);
        break;
    case 2:
        printf("\nEstoque do item %s atualizado em %d unidade(s).\n", produtoOpcao2, quantidade);
        delay(1000);
        break;
    case 3:
        printf("\nEstoque do item %s atualizado em %d unidade(s).\n", produtoOpcao3, quantidade);
        delay(1000);
        break;
    case 4:
        printf("\nEstoque do item %s atualizado em %d unidade(s).\n", produtoOpcao4, quantidade);
        delay(1000);
        break;
    case 5:
        printf("\nEstoque do item %s atualizado em %d unidade(s).\n", produtoOpcao5, quantidade);
        delay(1000);
        break;
    default:
        printf("\nEstoque atualizado com sucesso!\n");
        delay(1000);
        break;
    }
    transicao();
}

bool verificarEstoque(int codProd, int quant)
{
    if(quant <= estoqueItens[codProd - 1])
    {
        estoqueItens[codProd - 1] -= quant;
    }
    else
    {
        printf("\nEstoque insuficiente para venda!");
        return false;
    }
    return true;
}

void realizarVenda()
{
    int opcao, retorno = 1, contador = 0;
    float quantidade;
    char resposta = 's';

    while(retorno == 1)
    {
        while(resposta == 's' || resposta == 'S')
        {
            if(estoqueItens[0] == 0 && estoqueItens[1] == 0 && estoqueItens[2] == 0 && estoqueItens[3] == 0 && estoqueItens[4] == 0)
            {
                printf("\nQuantidade em estoque insuficiente para venda. Voltando ao menu principal.\n");
                delay(1000);
                break;
            }

            if(contador == 0)
            {
                visualizarItens();
                contador++;
            }
            else
            {
                transicao();
                visualizarItens();
            }

            printf("\nDigite um código de 1 a 5 para selecionar um produto ou 0 para sair: \n");

            scanf("%d", &opcao);
            getchar();

            while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5)
            {
                printf("\nOpção inválida!\n");

                transicao();

                visualizarItens();
                printf("\nDigite uma opção válida:\n");
                scanf("%d", &opcao);
                getchar();
            }

            if(opcao == 1 && estoqueItens[0] > 0)
            {
                printf("\nProduto escolhido: %s\n", produtoOpcao1);
                delay(1500);
                break;
            }
            else if(opcao == 2 && estoqueItens[1] > 0)
            {
                printf("\nProduto escolhido: %s\n", produtoOpcao2);
                delay(1500);
                break;
            }
            else if(opcao == 3 && estoqueItens[2] > 0)
            {
                printf("\nProduto escolhido: %s\n", produtoOpcao3);
                delay(1500);
                break;
            }
            else if(opcao == 4 && estoqueItens[3] > 0)
            {
                printf("\nProduto escolhido: %s\n", produtoOpcao4);
                delay(1500);
                break;
            }
            else if(opcao == 5 && estoqueItens[4] > 0)
            {
                printf("\nProduto escolhido: %s\n", produtoOpcao5);
                delay(1500);
                break;
            }
            else if(opcao == 0 && contador != 0)
            {
                while(opcao != 1 && opcao != 2 && opcao != 3 && opcao != 4 && opcao != 5 && opcao != 0)
                {
                    printf("\nOpção inválida!\n");

                    transicao();

                    visualizarItens();
                    printf("\nDigite uma opção válida:\n");
                    scanf("%d", &opcao);
                    getchar();
                }
            }
            else
            {
                if(estoqueItens[0] == 0 && estoqueItens[1] == 0 && estoqueItens[2] == 0 && estoqueItens[3] == 0 && estoqueItens[4] == 0)
                {
                    printf("\nQuantidade em estoque insuficiente para venda. Voltando ao menu principal.\n");
                    delay(1000);
                    break;
                }
                else
                {
                    while(opcao == 0)
                    {
                        printf("\nOpção inválida!\n");

                        transicao();

                        visualizarItens();
                        printf("\nDigite uma opção válida:\n");
                        scanf("%d", &opcao);
                        getchar();
                    }
                }
            }
        }

        if(estoqueItens[0] != 0 || estoqueItens[1]!= 0 || estoqueItens[2] != 0 || estoqueItens[3] != 0 || estoqueItens[4] != 0)
        {
            printf("\nAgora, digite a quantidade desejada: \n");
            scanf("%f", &quantidade);
            getchar();

            while(quantidade <= 0)
            {
                printf("\nQuantidade inválida ou insuficiente. Digite uma quantidade válida:\n");
                scanf("%f", &quantidade);
                getchar();
            }

            while(quantidade > estoqueItens[opcao - 1])
            {
                printf("\nQuantidade digitada é superior à quantidade em estoque. Digite uma quantidade válida:\n");
                scanf("%f", &quantidade);
                delay(1000);
            }

            bool aux = false;

            while(aux == false)
            {
                if(quantidade > 0 && quantidade <= estoqueItens[opcao - 1])
                {
                    switch(opcao)
                    {
                    case 1:
                        quantVendida[opcao - 1] += quantidade;
                        estoqueItens[opcao - 1] -= quantidade;
                        subtotalUnitario[opcao - 1] = precoProduto1 * quantidade;
                        printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[0]);
                        delay(1500);
                        aux = true;
                        break;
                    case 2:
                        quantVendida[opcao - 1] += quantidade;
                        estoqueItens[opcao - 1] -= quantidade;
                        subtotalUnitario[opcao - 1] = precoProduto2 * quantidade;
                        printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[1]);
                        delay(1500);
                        aux = true;
                        break;
                    case 3:
                        quantVendida[opcao - 1] += quantidade;
                        estoqueItens[opcao - 1] -= quantidade;
                        subtotalUnitario[opcao - 1] = precoProduto3 * quantidade;
                        printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[2]);
                        delay(1500);
                        aux = true;
                        break;
                    case 4:
                        quantVendida[opcao - 1] += quantidade;
                        estoqueItens[opcao - 1] -= quantidade;
                        subtotalUnitario[opcao - 1] = precoProduto4 * quantidade;
                        printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[3]);
                        delay(1500);
                        aux = true;
                        break;
                    case 5:
                        quantVendida[opcao - 1] += quantidade;
                        estoqueItens[opcao - 1] -= quantidade;
                        subtotalUnitario[opcao - 1] = precoProduto5 * quantidade;
                        printf("\nQuantidade: %.0f | Subtotal do item: R$ %.2f\n", quantidade, subtotalUnitario[4]);
                        delay(1500);
                        aux = true;
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    printf("\nQuantidade deve ser maior que 0. Digite uma quantidade válida:");
                    scanf("%f", &quantidade);
                    aux = false;
                }
            }

            if(estoqueItens[0] == 0 && estoqueItens[1] == 0 && estoqueItens[2] == 0 && estoqueItens[3] == 0 && estoqueItens[4] == 0)
            {
                if(quantVendida[0] == 0 && quantVendida[1] == 0 && quantVendida[2] == 0 && quantVendida[3] == 0 && quantVendida[4] == 0)
                {
                    delay(1500);
                    printf("\nTodo o estoque da loja foi vendido. Retornando ao menu principal.\n");
                    resposta = 1;
                    delay(1500);
                }
                else
                {
                    delay(1500);
                    printf("\nTodo o estoque da loja foi vendido. Finalizando venda.\n");
                }
            }
            else
            {
                // Vender outro produto ou finalizar a venda?
                printf("\nGostaria de vender outro produto(1) ou finalizar venda(2) ?\n");
                scanf("%d", &retorno);

                if(retorno == 1)
                {
                    resposta = 's';
                    delay(1500);
                }
                else if(retorno == 2)
                {
                    transicao();

                    exibeSubtotalOrdenado(subtotalUnitario);

                    int formaPagto = selecionaFormaPagamento();

                    calculaTotalPorFormaPagamento(formaPagto);

                    transicao();
                }
                else
                {
                    while(retorno != 1 && retorno != 2)
                    {
                        printf("\nOpção inválida.\n");
                        delay(1500);
                        limparTela();

                        // Vender outro produto ou finalizar a venda (caso haja itens vendidos)?
                        printf("\nGostaria de vender outro produto(1) ou voltar para o menu principal(2) ?\n");
                        scanf("%d", &retorno);

                        if(retorno == 1)
                        {
                            resposta = 's';
                            break;
                            delay(1500);
                        }
                    }
                }
            }
        }
        else
        {
            break;
        }
    }

    // Zerar as variáveis subtotal e subtotalUnitario[]
    subtotal = valorZerado;

    for(int i = 0; i < tamanhoArray; i++)
    {
        subtotalUnitario[i] = valorZerado;
    }
}

void exibeSubtotalOrdenado(float arraySubtotal[])
{
    ordenaItensSubtotal(arraySubtotal);

    for(int i = 0; i < tamanhoArray; i++)
    {
        subtotal += subtotalUnitario[i];
    }

    printf("\n\t\t\t\tNome do item\t\tValor\n");

    for(int i = 0; i < tamanhoArray; i++)
    {
        if(arraySubtotal[i] > 0.0)
        {
            switch(ordemProdutos[i])
            {
            case 1:
                printf("\t\t\t\t%s\t\tR$ %.2f\n", produtoOpcao1, arraySubtotal[i]);
                break;
            case 2:
                printf("\t\t\t\t%s\t\tR$ %.2f\n", produtoOpcao2, arraySubtotal[i]);
                break;
            case 3:
                printf("\t\t\t\t%s\t\tR$ %.2f\n", produtoOpcao3, arraySubtotal[i]);
                break;
            case 4:
                printf("\t\t\t\t%s\t\t\tR$ %.2f\n", produtoOpcao4, arraySubtotal[i]);
                break;
            case 5:
                printf("\t\t\t\t%s\t\t\tR$ %.2f\n", produtoOpcao5, arraySubtotal[i]);
                break;
            default:
                break;
            }
        }

    }
    printf("\t\t\t\t_________________________________");
    printf("\n\t\t\t\t%s\t\tR$ %.2f", subtotalSt, subtotal);
}

void ordenaItensSubtotal(float arraySubtotal[])
{
    float nroAuxiliar, nroAuxiliar2;

    for(int contador = 1; contador < tamanhoArray; contador++)
    {
        for(int i = 0; i < tamanhoArray; i++)
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
}

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
        printf("\nO total é R$ %.2f", subtotal);

        // Chama função de troco
        funcaoTroco();
    }
    else
    {
        int parcelas = verificarParcelasPagtoPrazo();

        if(parcelas <= 3)
        {
            subtotal += subtotal * 0.05;
        }
        else
        {
            subtotal += subtotal * 0.08;
        }
        printf("\nO total é R$ %.2f", subtotal);
    }
}

void gerarRelatorio() {

}

int verificarParcelasPagtoPrazo()
{

    int parcelas;

    printf("\nEm quantas parcelas gostaria de pagar? OBS: Mínimo 2 e máximo 10.\n");
    scanf("%d", &parcelas);

    while(parcelas < 0 || parcelas > 10)
    {
        printf("\nNúmero de parcelas inválido. Escolha um valor entre 2 e 10.\n");
        scanf("%d", &parcelas);
    }

    return parcelas;
}

void mostraSubtotal(float arraySubtotalOrdenado[])
{
    printf("\nO subtotal é:\n");

    for(int i = 0; i < 5; i++)
    {
        if(arraySubtotalOrdenado[i] > 0.00)
        {
            printf("\nItem %d: R$ %.2f", ordemProdutos[i], arraySubtotalOrdenado[i]);
        }
    }
}

void funcaoTroco()
{
    printf("\n\nVoce precisa de troco? (S/N)\n");
    scanf("%c", &troco);
    getchar();

    while (troco != 's' && troco != 'S' && troco != 'n' && troco != 'N')
    {
        printf("\nOpção inválida. Voce precisa de troco? (S/N)\n");
        scanf("%c", &troco);
        getchar();
    }

    if(troco == 'S' || troco == 's') // Validação caso a resposta seja S ou s para troco
    {
        float volta;

        printf("\nQual o valor pago pelo cliente?\n");
        scanf("%f", &valorTroco);
        getchar();

        if(valorTroco >= subtotal)
        {
            volta = valorTroco - subtotal;
        }
        else
        {
            while(valorTroco < subtotal)
            {
                printf("\nValor digitado insuficiente. Digite uma quantia maior.");
                scanf("%f", &valorTroco);
            }
            volta = valorTroco - subtotal;
        }
        printf("\nAqui vai o seu troco: R$ %.2f", volta);
        delay(3000);
    }
    else // Validação caso a resposta seja N ou n para troco
    {
        printf("\nTroco não é necessário.");
    }
}

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

void transicao()
{
    delay(segundos);
    limparTela();
}
