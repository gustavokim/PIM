Definição de Estruturas:
O código começa definindo estruturas para representar os dados de cada entidade:
cadastro_produtos: Armazena informações como código de identificação, nome do produto, forma de venda, valor e validade.
dados_vendas: Guarda dados sobre as vendas, incluindo produto, forma de venda, quantidade, valor, data, forma de pagamento e código de identificação da venda.
dados_estoque: Armazena informações sobre o estoque, como código de identificação, produto, forma de venda, quantidade, fornecedor, data de entrada, local de armazenamento, quantidade mínima e quantidade máxima.
baixa_estoque: Registra as saídas do estoque, incluindo código de identificação do produto, quantidade e data da baixa.
Menu Principal:
A função main apresenta um menu principal com as seguintes opções:
Visualizar Dados: Permite visualizar os dados de produtos, vendas, estoque e baixa de estoque.
Cadastro de Produtos: Permite cadastrar novos produtos ou alterar os dados de produtos existentes.
Exibir Relatórios: Exibe relatórios de vendas e estoque.
Sair do Programa: Encerra a execução do programa.
Funções:
O código utiliza várias funções para organizar o código e facilitar a reutilização.
visualizar_dados: Lê os dados de um arquivo CSV e exibe na tela as informações de acordo com a opção escolhida (produtos, vendas, estoque ou baixa de estoque).
inserir_dados: Permite inserir novos dados de produtos no arquivo "cadastro_produtos.csv".
alterar_cadastro: Permite alterar os dados de um produto existente no arquivo "cadastro_produtos.csv".
exibir_relatorios: Exibe relatórios de vendas e estoque, lendo os dados dos arquivos "vendas.csv" e "estoque.csv".
gerar_codigo_identificacao: Gera um código de identificação único para cada produto, incrementando o último código encontrado no arquivo.
consulta_produtos: Permite consultar produtos por código ou por nome, lendo o arquivo "cadastro_produtos.csv".
Gerenciamento de Arquivos:
O código utiliza arquivos CSV para armazenar os dados.
As funções fopen, fgets, fprintf, fclose e remove são usadas para abrir, ler, escrever e fechar os arquivos.
