# Estudo de caso projeto 2: Sistema da Berenice - Vendendo +

**Introdução**: As informações aqui contidas fazem parte do processo de desenvolvimento do projeto mensal intitulado, **Implementação e Manipulação de Sistema em Linguagem C**.

Portanto, devem ser analisadas e utilizadas como fonte de dados para planejamento e implementação do mesmo.

**Período de execução**: 06/09/2022 a 29/09/2022

Berenice quer uma continuação do sistema anterior que possua agora as seguintes funcionalidades:

1.  Implementar um menu para a escolha das seguintes opções através de funções:
    
	a. Cadastrar estoque;
    
	b. Visualizar estoque;
    
	c. Realizar Venda;
    
	d. Sair.
    

2.  Ao selecionar a opção de “Cadastrar estoque”, exibir a seguinte lista de produtos para que Berenice diga qual seu estoque do dia, esta informação deverá ser armazenada em um vetor de inteiros com 5 posições:

| Posição no vetor | Código do Item |Item |
|:-:|:-:|:-:|
|0  | 1 |Pão de forma |
|1  | 2 |Pão de centeio |
|2  | 3 |Broa de milho |
|3  | 4 |Sonho |
|4  | 5 |Tubaína |

	a. Após exibir a lista acima de produtos, solicitar que seja digitado o código do item a qual se deseja alterar o estoque.
    
	b. Validar se o código do item é válido, ou seja, se o código digitado está entre 1 e 5 (conforme tabela acima para código do item);
    
	c. Se o código não for válido, imprima a mensagem “Código inválido” e repita novamente os subitens acima;
    
	d. Se o código for válido solicitar a quantidade em estoque referente ao item previamente selecionado;
    
	e. Validar se a quantidade é válida, ou seja, maior ou igual a zero;
    
	f. Se a quantidade não for válida, imprima a mensagem “Quantidade inválida, a mesma deve ser maior ou igual a zero.” e repita novamente os subitens acima;
    
	g. Se ela for válida, alterar no vetor referente ao código do item a respectiva posição com a nova quantidade;
    
	h. Retornar ao menu inicial;
    
	i. Observação o vetor com estoque deve ser obrigatoriamente inicializado com zeros no início do programa;
    

3.  Ao selecionar a opção de “Visualizar Estoque” você deverá imprimir a lista de produtos com seus respectivos preços e quantidades em estoque, como no exemplo abaixo:

| Item (código) | Nome do Item |Valor (Unidade)  |Estoque  | 
| :-: | :-: | :-: | :-: |
|1  |Pão de forma  |R$ 7,50  | 0 | 
| 2 | Pão de centeio | R$ 8,69 | 5 | 
|  3|Broa de milho  |R$ 5,00  | 2 | 
|  4|Sonho  | R$ 4,50 | 3 | 
|  5| Tubaína |R$ 3,25  | 0 | 








	Dica: Você pode usar a função implementada para exibir o estoque como passo inicial para a venda, e em seguida solicitar o respectivo código do item para realizar a venda.

5.  Ao selecionar a opção “Realizar Venda”, fazer a venda de modo a continuar a implementação já realizada anteriormente agora com as seguintes informações adicionais:
    

	a. Se o item selecionado for inválido em vez de sair do programa como antes, agora você deverá voltar a exibir a lista de produtos e permitir selecionar novamente outro produto;
    
	b. Realizar a venda somente dos itens com estoque suficiente;
    
	c. Se a quantidade for inválida, exibir a mensagem “Quantidade inválida ou insuficiente” e voltar a tentar realizar a venda novamente se o usuário desejar;
    
	d. Se a quantidade for válida, somar a quantidade de itens vendidos em outro vetor do mesmo tipo e tamanho da quantidade em estoque bem como descontar do vetor estoque a nova quantidade vendida, bem como somar ao total da venda;
    
	e. Perguntar se berenice deseja vender outro produto ainda ou finalizar; Se optar por realizar outra venda, repetir os passos acima (exibir novamente a visualização do estoque), etc…;
    
	f. Se não optar por realizar outra venda, finalizar a venda exibindo a lista de produtos vendidos do maior sub-total para o menor e finalizar com as mesmas opções de pagamento já implementadas com as seguintes adições:
    
		i. Ofertar duas possibilidades de pagamento para o cliente;
    
		ii. À vista:    

			1. Até (incluindo)R$ 50,00, 5% de desconto;
    
			2. Acima de R$ 50,00 e abaixo de R$100,00, 10% desconto;
    
			3. Acima (incluindo) de R$100,00, 18% de desconto.

		iii. À prazo:    

			1. Em até (incluindo) 3 parcelas: 5% de acréscimo;
    
			2. Acima de 3 parcelas: 8% de acréscimo;
    
			3. Se digitar um número de parcelas abaixo de 1, imprimir a mensagem “Número de parcelas inválido, digite um valor acima de 1.” e tentar novamente ler o número de parcelas.

		iv. Se a opção for inválida, exibir a mensagem “Opção de pagamento inválida” e retornar novamente a escolha.
    

	g. Voltar ao menu inicial;
    

6.  Ao selecionar a opção “Sair” finalizar o programa;
    
7.  Desafios (5 pontos adicionais para cada):
    

	a. Perguntar se precisa de troco ou não para pagamentos a vista, se sim solicitar o valor pago e validar o mesmo, voltando a solicitar novamente se o mesmo for inválido ou insuficiente;
    
	b. Exibir um relatório de itens vendidos e sua quantidade ao selecionar a opção sair;
    
	c. Atualização do fluxograma anterior com as novas implementações;
    
	d. Atualização do Trello com as novas tarefas.
