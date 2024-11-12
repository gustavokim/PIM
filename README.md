# PIM
sistema do servidor 
Visualizar Dados: Permite visualizar os dados armazenados em diferentes arquivos CSV:
Cadastro de Produtos: Exibe informações sobre os produtos cadastrados na loja, como nome, forma de venda, valor e validade.
Vendas: Exibe informações sobre as vendas realizadas, como produto, forma de venda, forma de pagamento, quantidade, data e valor.
Estoque: Exibe informações sobre o estoque atual, incluindo quantidade, fornecedor, data de entrada, local de armazenamento, quantidade mínima e máxima.
Baixa do Estoque: Exibe informações sobre a baixa do estoque, como código do produto, quantidade e data da saída.
Cadastro de Produtos:
Cadastrar Novo Produto: Permite inserir novas informações de produtos no sistema, como nome, forma de venda, valor e validade.
Alterar Dados do Produto: Permite editar as informações de um produto já cadastrado.
Exibir Relatórios:
Vendas: Exibe um relatório com informações resumidas sobre as vendas, como quantidade total de vendas, valor total, valor médio das compras, e a frequência de cada forma de pagamento (crédito, débito, pix).
Estoque: Exibe um relatório com informações sobre o estoque, incluindo a quantidade em estoque de cada produto e seu status (situação crítica, situação não recomendada ou situação ideal).
Sair: Encerra o programa.
Observações:
O sistema é basicamente um sistema de interface de linha de comando (CLI), sem uma interface gráfica.
O sistema utiliza arquivos CSV para armazenar os dados.
O sistema possui algumas funcionalidades básicas, como gerar códigos de identificação automaticamente, converter textos para maiúsculas, e exibir informações em formato tabular.
O sistema ainda está incompleto e contém erros, como a função "readmin" não definida e falta de validação de entrada.
sistema de caixa 
#include <stdio.h>, #include <stdlib.h>, #include <string.h>, #include <time.h>: Incluem bibliotecas padrão do C para entrada/saída, alocação de memória, manipulação de strings e funções de tempo.
#define MAX_FRUITS 15: Define a quantidade máxima de frutas que podem ser cadastradas no sistema.
#define MAX_CODE_LENGTH 5: Define o tamanho máximo do código da fruta.
typedef struct { ... } Fruta;: Define a estrutura Fruta para armazenar o nome, o preço e o código de uma fruta.
typedef struct { ... } Venda;: Define a estrutura Venda para armazenar os dados de uma venda, como o número da nota fiscal, a fruta vendida, a quantidade e o valor total.
2. Funções:
int gerarNumeroNF(): Gera um número de nota fiscal aleatório de 4 dígitos.
void visualizarItens(Fruta frutas[], int numFrutas): Exibe uma lista de todas as frutas cadastradas, mostrando o código, nome e preço.
void consultarPreco(Fruta frutas[], int numFrutas): Permite que o usuário consulte o preço de uma fruta pelo código.
float calcularValorParcial(Fruta fruta, int quantidade, char tipo): Calcula o valor parcial da venda de uma fruta, considerando a quantidade e o tipo de unidade (unidades ou peso).
void efetuarVenda(Fruta frutas[], int numFrutas): Efetua a venda de uma fruta, solicitando o código, a quantidade e o tipo de unidade, calculando o valor total e registrando a venda em um arquivo "vendas.txt".
3. Fluxo Principal (main):
int main(): Função principal do programa.
Fruta frutas[MAX_FRUITS];: Declara um array de frutas para armazenar as informações sobre as frutas cadastradas.
int numFrutas = 0;: Inicializa um contador para o número de frutas cadastradas.
// Cadastrar frutas (exemplo): Cadastra algumas frutas (maçã, banana, laranja) como exemplo.
// Menu principal: Exibe um menu com as opções: Visualizar Itens, Consultar Preço, Efetuar Venda e Sair.
do { ... } while (opcao != 0);: Loop que repete o menu até que o usuário escolha a opção "Sair".
switch (opcao): Executa a função correspondente à opção escolhida pelo usuário.
4. Registro de Vendas:
*FILE arquivoVendas = fopen("vendas.txt", "a");: Abre o arquivo "vendas.txt" para anexar informações de novas vendas.
fprintf(arquivoVendas, ...);: Escreve os dados da venda no arquivo, como o número da NF, o nome da fruta, a quantidade e o valor total.
sistema de estoque 
Estrutura do Código
O código está organizado em funções que representam diferentes funcionalidades do sistema. As funções principais são:
**abrirArquivo(const char nomeArquivo, const char modo): Abre um arquivo com o nome especificado no modo especificado. Se o arquivo não puder ser aberto, é exibida uma mensagem de erro.
*lerArquivo(const char nomeArquivo): Lê o conteúdo de um arquivo linha por linha e exibe cada linha na tela.
**escreverArquivo(const char nomeArquivo, const char conteudo): Escreve o conteúdo especificado em um arquivo, adicionando-o ao final do arquivo.
cadastrarItem(): Promove o cadastro de um novo item, solicitando informações como código, descrição, validade, preço, estoque mínimo e estoque máximo. As informações são armazenadas em um arquivo CSV ("Cadastro.csv").
buscarItemPorCodigo(int codigoBusca): Busca um item no arquivo "Cadastro.csv" utilizando o código como critério de busca. Se o item for encontrado, exibe as informações do item.
alterarPrecoPorCodigo(int codigoBusca, float novoPreco): Altera o preço de um item no arquivo "Cadastro.csv" utilizando o código como critério de busca.
entradaEstoque(int codigoBusca, int quantidadeAdicionar): Atualiza o estoque de um item no arquivo "Cadastro.csv" utilizando o código como critério de busca.
main(): Função principal que apresenta o menu do sistema e controla o fluxo do programa.
Funcionalidades do Sistema
O sistema oferece as seguintes funcionalidades:
Cadastrar Item: Permite que o usuário cadastre novos itens, armazenando as informações em um arquivo CSV.
Consultar Item: Permite que o usuário busque um item pelo código e visualize as informações do item.
Alterar Preço: Permite que o usuário altere o preço de um item pelo código.
Estoque Item: Permite que o usuário atualize o estoque de um item pelo código.
Documentação
O código apresenta uma documentação básica através de comentários, explicando a função de cada função e as variáveis utilizadas. No entanto, a documentação poderia ser mais completa, incluindo informações sobre:
Formato do arquivo CSV: Especificar o formato do arquivo CSV, incluindo a ordem das colunas e os tipos de dados de cada coluna.
Validação de dados: Descrever como o sistema valida os dados inseridos pelo usuário, por exemplo, verificando se o código é único e se o preço é um número válido.
Gerenciamento de erros: Descrever como o sistema lida com erros, por exemplo, se o arquivo "Cadastro.csv" não existir ou se o usuário inserir dados inválidos.
