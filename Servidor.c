#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<time.h>


struct cadastro_produtos
{
     int codigo_identificacao;
     char produto[50];
     char forma_venda[20];
     int valor;
     int validade;
};

struct dados_vendas
{
     char produto[50];
     char forma_venda[20];
     int quantidade;
     int valor;
     char data[20];
     char forma_pagto[20];
     int codigo_identificacao;
};

struct dados_estoque
{
     int codigo_indentificacao;
     char produto[50];
     char forma_venda[20];
     int quantidade;
     char fornecedor[50];
     char data_entrada[20];
     char local_armazenagem[20];
     int qtd_min;
     int qtd_max;
};

struct baixa_estoque
{
    int codigo_identificacao;
    int quantidade;
    char data[20];
};





int main()
{
    setlocale(LC_ALL, "Portuguese");

    void visualizar_dados();
    void inserir_dados();
    void alterar_cadastro();
    void exibir_relatorios();

    int opcao_saida = 0, opcao = 0;
    int opcao_inserir_modificar = 0;

    while(1)
    {
        while(1)
        {
            system("cls");
            printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
            printf("\nDigite o número da opção desejada:\n");
            printf("\n[1] VISUALIZAR DADOS\n[2] CADASTRO DE PRODUTOS\n[3] EXIBIR RELATÓRIOS\n\n[4] SAIR DO PROGRAMA\n\n");
            scanf("%i", &opcao);

            if (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4)
            {
               break;

            }
            else
            {
                system("cls");
                printf("\nOpção inválida!\n");
            }
        }

        switch (opcao)
        {
        case 1:
            system("cls");
            printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
            printf("\nVISUALIZAR DADOS:\n\n\n");
            while(1)
            {
                printf("\nDigite o número da opção desejada:\n");
                printf("\n[1] CADASTRO DE PRODUTOS\n[2] VENDAS\n[3] ESTOQUE\n[4] BAIXA DO ESTOQUE\n\n[5] MENU INICIAL\n\n");
                scanf("%i", &opcao);

                if (opcao == 1 || opcao == 2 || opcao == 3 || opcao == 4 || opcao == 5)
                {
                   break;

                }
                else
                {
                    system("cls");
                    printf("\nOpção inválida!\n");
                }
            }
            if (opcao == 5)
            {
                break;
            }

            visualizar_dados(opcao);
            system("pause");
            break;

        case 2:
            system("cls");
            printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
            printf("\nCADASTRO DE PRODUTOS:\n\n\n");

            while(1)
            {
                system("cls");
                printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
                printf("\nCADASTRO DE PRODUTOS:\n\n\n");
                printf("\nDigite o número da opção desejada:\n");
                printf("\n[1] CADASTRAR NOVO PRODUTO\n[2] ALTERAR DADOS DO PRODUTO\n\n[3] MENU INICIAL\n\n");
                scanf("%i", &opcao);

                if (opcao == 1 || opcao == 2 || opcao == 3)
                {
                   break;

                }
                else
                {
                    system("cls");
                    printf("\nOpção inválida!\n");
                }
            }
            if (opcao == 3)
            {
                break;
            }
            else if (opcao == 2)
            {
                alterar_cadastro();
                system("pause");
                break;
            }
            else
            {
                inserir_dados(opcao);
                break;
            }

        case 3:
            system("cls");
            printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
            printf("\nEXIBIÇÃO DE RELATÓRIOS:\n\n\n");

            while(1)
            {
                system("cls");
                printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
                printf("\nEXIBIÇÃO DE RELATÓRIOS:\n\n\n");
                printf("\nDigite o número da opção desejada:\n");
                printf("\n[1] VENDAS\n[2] ESTOQUE\n\n[3] MENU INICIAL\n\n");
                scanf("%i", &opcao);

                if (opcao == 1 || opcao == 2 || opcao == 3)
                {
                   break;

                }
                else
                {
                    system("cls");
                    printf("\nOpção inválida!\n");
                }
            }
            if (opcao == 3)
            {
                break;
            }
            else if (opcao == 2)
            {
                exibir_relatorios(opcao);
                system("pause");
                break;
            }
            else
            {
                exibir_relatorios(opcao);
                system("pause");
                break;
            }

        case 4:
            system("cls");
            printf("\nO programa está sendo encerrado...\n\n");
            system("pause");
            return 0;
        }




        while (1)
        {
            system("cls");
            printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
            printf("\n\n[1] RETORNAR AO MENU INICIAL\n[2] SAIR DO PROGRAMA\n\n");
            scanf("%i", &opcao_saida);

            if (opcao_saida == 1)
            {
                system("cls");
                break;
            }
            else if (opcao_saida == 2)
            {
                system("cls");
                printf("\nO programa está sendo encerrado...\n\n");
                system("pause");
                return 0;
            }
            else
            {
                system("cls");
                printf("\nOpção inválida!\n");
                continue;
            }
        }

       if (opcao_saida == 1)
       {
           continue;
       }
       else
       {
           break;
       }

    }

 return 0;
}








void visualizar_dados(int opcao)
{
    char nome_arquivo[5][25] = {"cadastro_produtos.csv", "vendas.csv", "estoque.csv", "baixa_estoque.csv"};
    char modo_abertura[4] = "r";

    FILE *arquivo = fopen(nome_arquivo[opcao-1], modo_abertura);

    if (!arquivo)
    {
        perror("\n\nNão foi possível abrir ou criar o arquivo informado!\n\n");
    }
    else
    {
        if (opcao == 1)
        {
            struct cadastro_produtos cadastro = {0};

            char informacao[2046];

            fgets(informacao, sizeof(informacao), arquivo); //descarta a leitura da primeira linha do arquivo (cabeçalho)

            while((fgets(informacao, sizeof(informacao), arquivo)) != NULL)
            {
                char *linha = strtok(informacao, ",");

                if (linha != NULL)
                {
                    sscanf(linha, "%i", &cadastro.codigo_identificacao);

                    linha = strtok(NULL, ",");

                    if (linha != NULL)
                    {
                        sscanf(linha, "%s[^\n]", &cadastro.produto);

                        linha = strtok(NULL, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%s[^\n]", &cadastro.forma_venda);

                            linha = strtok(NULL, ",");

                            if (linha != NULL)
                            {
                                sscanf(linha, "%i", &cadastro.valor);

                                linha = strtok(NULL, ",");

                                if (linha != NULL)
                                {
                                    sscanf(linha, "%i", &cadastro.validade);
                                }
                            }
                        }
                    }
                }
                printf("\n\n");
                char simbolo1 = '-';
                for (int i = 0; i < 30; i++)
                {
                    printf("%c", simbolo1);
                }
                printf("\n");
                printf("\nCódigo de identificação: %i", cadastro.codigo_identificacao);
                printf("\nProduto: %s", cadastro.produto);
                printf("\nForma de venda: %s", cadastro.forma_venda);
                printf("\nValor: R$%.2f", (float)(cadastro.valor / 100));
                printf("\nValidade (dias): %i", cadastro.validade);
                printf("\n\n");
                char simbolo2 = '-';
                for (int i = 0; i < 30; i++)
                {
                    printf("%c", simbolo2);
                }
            }
            printf("\n\n");
        }

        if (opcao == 2)
        {
            struct dados_vendas vendas = {0};

            char informacao[2046];

            fgets(informacao, sizeof(informacao), arquivo);

            while((fgets(informacao, sizeof(informacao), arquivo)) != NULL)
            {
                char *linha = strtok(informacao, ",");

                if (linha != NULL)
                {
                    sscanf(linha, "%s[^\n]", &vendas.produto);

                    linha = strtok(NULL, ",");

                    if (linha != NULL)
                    {
                        sscanf(linha, "%s[^\n]", &vendas.forma_venda);

                        linha = strtok(NULL, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%s[^\n]", &vendas.forma_pagto);

                            linha = strtok(NULL, ",");

                            if (linha != NULL)
                            {
                                sscanf(linha, "%i", &vendas.quantidade);

                                linha = strtok(NULL, ",");

                                if (linha != NULL)
                                {
                                    sscanf(linha, "%s[^\n]", &vendas.data);

                                    linha = strtok(NULL, ",");

                                    if (linha != NULL)
                                    {
                                        sscanf(linha, "%i", &vendas.valor);

                                        linha = strtok(NULL, ",");

                                        if (linha != NULL)
                                        {
                                            sscanf(linha, "%i", &vendas.codigo_identificacao);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                printf("\nProduto: %s", vendas.produto);
                printf("\nForma de venda: %s", vendas.forma_venda);
                printf("\nForma de Pagamento: %s", vendas.forma_pagto);
                printf("\nQuantidade: %i", vendas.quantidade);
                printf("\nData: %s", vendas.data);
                printf("\nValor: R$%.2f", (float)(vendas.valor / 100));
                printf("\nCódigo Identificação venda: %i", vendas.codigo_identificacao);
                printf("\n\n");
                char simbolo = '-';
                for (int i = 0; i < 30; i++)
                {
                    printf("%c", simbolo);
                }
                printf("\n\n");
            }
        }

        if (opcao == 3)
        {
            struct dados_estoque estoque = {0};

            char informacao[2046];

            fgets(informacao, sizeof(informacao), arquivo);

            while((fgets(informacao, sizeof(informacao), arquivo)) != NULL)
            {
                char *linha = strtok(informacao, ",");

                if (linha != NULL)
                {
                    sscanf(linha, "%i", &estoque.codigo_indentificacao);

                    linha = strtok(NULL, ",");

                    if (linha != NULL)
                    {
                        sscanf(linha, "%s[^\n]", &estoque.produto);

                        linha = strtok(NULL, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%s[^\n]", &estoque.forma_venda);

                            linha = strtok(NULL, ",");

                            if (linha != NULL)
                            {
                                sscanf(linha, "%i", &estoque.quantidade);

                                linha = strtok(NULL, ",");

                                if (linha != NULL)
                                {
                                    sscanf(linha, "%s[^\n]", &estoque.fornecedor);

                                    linha = strtok(NULL, ",");

                                    if (linha != NULL)
                                    {
                                        sscanf(linha, "%s[^\n]", &estoque.data_entrada);

                                        linha = strtok(NULL, ",");

                                        if (linha != NULL)
                                        {
                                            sscanf(linha, "%s[^\n]", &estoque.local_armazenagem);

                                            linha = strtok(NULL, ",");

                                                if (linha != NULL)
                                                {
                                                    sscanf(linha, "%i", &estoque.qtd_min);

                                                    linha = strtok(NULL, ",");

                                                    if (linha != NULL)
                                                    {
                                                        sscanf(linha, "%i", &estoque.qtd_max);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    printf("\n");
                    printf("\nCódigo do Produto: %i", estoque.codigo_indentificacao);
                    printf("\nProduto: %s", estoque.produto);
                    printf("\nForma de venda: %s", estoque.forma_venda);
                    printf("\nQuantidade: %i", estoque.quantidade);
                    printf("\nFornecedor: %s", estoque.fornecedor);
                    printf("\nData de entrada: %s", estoque.data_entrada);
                    printf("\nLocal de armazenagem: %s", estoque.local_armazenagem);
                    printf("\nQuantidade miníma: %i", estoque.qtd_min);
                    printf("\nQuantidade máxima: %i", estoque.qtd_max);
                    printf("\n\n");
                    char simbolo = '-';
                    for (int i = 0; i < 30; i++)
                    {
                        printf("%c", simbolo);
                    }
                }
                printf("\n\n");
            }
        }

        if (opcao == 4)
        {
            struct baixa_estoque baixa = {0};

            char informacao[2046];

            fgets(informacao, sizeof(informacao), arquivo); //descarta a leitura da primeira linha do arquivo (cabeçalho)

            while((fgets(informacao, sizeof(informacao), arquivo)) != NULL)
            {
                char *linha = strtok(informacao, ",");

                if (linha != NULL)
                {
                    sscanf(linha, "%i", &baixa.codigo_identificacao);

                    linha = strtok(NULL, ",");

                    if (linha != NULL)
                    {
                        sscanf(linha, "%i", &baixa.quantidade);

                        linha = strtok(NULL, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%s[^\n]", &baixa.data);
                        }
                    }
                }
                printf("\n\n");
                char simbolo1 = '-';
                for (int i = 0; i < 30; i++)
                {
                    printf("%c", simbolo1);
                }
                printf("\n");
                printf("\nCódigo de identificação: %i", baixa.codigo_identificacao);
                printf("\nQuantidade: %i", baixa.quantidade);
                printf("\nData de saída: %s", baixa.data);
                printf("\n\n");
                char simbolo2 = '-';
                for (int i = 0; i < 30; i++)
                {
                    printf("%c", simbolo2);
                }
            }
            printf("\n\n");
        }
        if (fclose(arquivo) != 0)
        {
            perror("\n\nErro ao fechar arquivo!\n\n");
        }
}







void inserir_dados(int opcao)
{
    opcao = 1;

    int codigo_identificacao = 0;

    struct cadastro_produtos cadastro = {0};

    int gerar_codigo_identificacao(int opcao);


    FILE *arquivo = fopen("cadastro_produtos.csv", "a");

    if (!arquivo)
    {
        perror("\n\nNão foi possível abrir ou criar o arquivo informado!\n\n");
    }
    else
    {
        while(1)
        {
            printf("\nVocê está inserindo dados no CADASTRO DE PRODUTOS:\n\n");

            printf("\nDigite o nome do produto:\n");
            fflush(stdin); //limpa o buffer de memória da última entrada do teclado para evitar erros
            scanf("%[^\n]", &cadastro.produto);

            for (int cont = 0; cadastro.produto[cont] != '\0'; cont++)
            {
                cadastro.produto[cont] = toupper(cadastro.produto[cont]);
            }


            printf("\nDigite a forma de venda (kg | unidade):\n");
            fflush(stdin);
            scanf("%[^\n]", &cadastro.forma_venda);

            for (int cont = 0; cadastro.forma_venda[cont] != '\0'; cont++)
            {
                cadastro.forma_venda[cont] = toupper(cadastro.forma_venda[cont]);
            }

            printf("\nDigite o valor do produto:\n");
            scanf("%i", &cadastro.valor);

            printf("\nDigite a validade do produto em dias:\n");
            scanf("%i", &cadastro.validade);

            codigo_identificacao = gerar_codigo_identificacao(opcao);

            int verificador = 0;

            verificador = fprintf(arquivo, "%i, %s, %s, %i, %i\n", codigo_identificacao, cadastro.produto, cadastro.forma_venda, cadastro.valor, cadastro.validade);

            printf("\n\nVerificador: %i\n\n", verificador);

            if (verificador > 0)
            {
                printf("\nInformação inserida com sucesso!\n\n");
            }
            else
            {
                printf("\nErro ao tentar inserir dados! Tente novamente!\n\n");
            }

            system("pause");


            int opcao_saida = 0;

            system("cls");
            printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
            printf("\n\nDeseja inserir mais dados no arquivo?\n[1] INSERIR\n[2] SAIR\n\n");
            scanf("%i", &opcao_saida);
            while(1)
            {
                if (opcao_saida == 1 || opcao_saida == 2)
                {
                    break;
                }
                else
                {
                    system("cls");
                    printf("\nOpção inválida!\n");
                    continue;
                }
             }
             if (opcao_saida == 2)
             {
                 break;
             }
             else
             {
                 continue;
             }
        }
        if (fclose(arquivo) != 0)
        {
            perror("\n\nErro ao fechar arquivo!\n\n");
        }
    }
}



int gerar_codigo_identificacao(int opcao)
{
    int codigo_identificacao = 0;

    char nome_arquivo[2][25] = {"cadastro_produtos.csv", "estoque.csv"};

    FILE *arquivo = fopen(nome_arquivo[opcao-1], "r");

    if (!arquivo)
    {
        perror("\n\nNão foi possível abrir o arquivo informado!\n\n");
    }
    else
    {
        char informacao[2046];

        fgets(informacao, sizeof(informacao), arquivo); //descarta a leitura da primeira linha do arquivo (cabeçalho)

        while((fgets(informacao, sizeof(informacao), arquivo)) != NULL)
        {
            char linha_temporaria;
            char *linha = strtok(informacao, ",");

            if (linha != NULL)
            {
                sscanf(linha, "%i", &linha_temporaria);
            }
            codigo_identificacao = linha_temporaria + 1;
        }
    }

    return codigo_identificacao;
}




void consulta_produtos()
{
    int opcao = 0;

    struct cadastro_produtos cadastro = {0};

    while(1)
    {
        system("cls");
        printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
        printf("\nCONSULTA DE PRODUTOS:\n\n\n");
        printf("\nDigite o número da opção desejada:\n");
        printf("\n[1] CONSULTA POR CÓDIGO\n[2] CONSULTA POR NOME\n\n[3] MENU INICIAL\n\n");
        scanf("%i", &opcao);

        if (opcao == 1 || opcao == 2 || opcao == 3)
        {
            break;

        }
        else
        {
            system("cls");
            printf("\nOpção inválida!\n");
        }
    }

    if (opcao == 1 || opcao == 2)
    {
        if (opcao == 1)
        {
            printf("\n\nDigite  código do produto que deseja consultar:\n\n");

            int codigo_busca = 0;

            scanf("%i", &codigo_busca);


            FILE *arquivo = fopen("cadastro_produtos.csv", "r");
            if (arquivo == NULL)
            {
                if (fclose(arquivo) != 0)
                {
                    perror("\n\nErro ao fechar arquivo!\n\n");
                }
            }

            char informacao[2046] = {0};

            while (1)
            {
                if (fgets(informacao, sizeof(informacao), arquivo) != NULL)
                {
                    int codigo = 0;

                    sscanf(informacao, "%i", &codigo);

                    if (codigo == codigo_busca)
                    {

                        system("cls");
                        printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
                        printf("\nCONSULTA DE PRODUTOS:\n\n\n");

                        char *linha = strtok(informacao, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%i", &cadastro.codigo_identificacao);

                            linha = strtok(NULL, ",");

                            if (linha != NULL)
                            {
                                sscanf(linha, "%s[^\n]", &cadastro.produto);

                                linha = strtok(NULL, ",");

                                if (linha != NULL)
                                {
                                    sscanf(linha, "%s[^\n]", &cadastro.forma_venda);

                                    linha = strtok(NULL, ",");

                                    if (linha != NULL)
                                    {
                                        sscanf(linha, "%i", &cadastro.valor);

                                        linha = strtok(NULL, ",");

                                        if (linha != NULL)
                                        {
                                            sscanf(linha, "%i", &cadastro.validade);
                                        }
                                    }
                                }
                            }
                        }
                        printf("\n\nItem encontrado:\n\n");
                        char simbolo1 = '-';
                        for (int i = 0; i < 30; i++)
                        {
                            printf("%c", simbolo1);
                        }
                        printf("\n");
                        printf("\nCódigo de identificação: %i", cadastro.codigo_identificacao);
                        printf("\nProduto: %s", cadastro.produto);
                        printf("\nForma de venda: %s", cadastro.forma_venda);
                        printf("\nValor (centavos): %i", cadastro.valor);
                        printf("\nValidade (dias): %i", cadastro.validade);
                        printf("\n\n");
                        char simbolo2 = '-';
                        for (int i = 0; i < 30; i++)
                        {
                            printf("%c", simbolo2);
                        }
                        break;
                    }
                    else if(informacao == EOF)
                    {
                        printf("Item com código %i não encontrado.\n", codigo_busca);
                    }
                }
            }
            if (fclose(arquivo) != 0)
            {
                perror("\n\nErro ao fechar arquivo!\n\n");
            }
        }
        else
        {
            printf("\n\nDigite o nome do produto que deseja consultar:\n\n");

            char produto[256] = {0};

            scanf("%s", &produto);

            FILE *arquivo = fopen("cadastro_produtos.csv", "r");

            if (arquivo == NULL)
            {
                if (fclose(arquivo) != 0)
                {
                    perror("\n\nErro ao fechar arquivo!\n\n");
                }
            }

            char informacao[2046] = {0};

            fgets(informacao, sizeof(informacao), arquivo); //descarta a leitura da primeira linha do arquivo (cabeçalho)

            while (fgets(informacao, sizeof(informacao), arquivo) != NULL)
            {
                char* linha = strtok(informacao, ",");

                    if (linha != NULL)
                    {
                        sscanf(linha, "%i", &cadastro.codigo_identificacao);

                        linha = strtok(NULL, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%s[^\n]", &cadastro.produto);

                            linha = strtok(NULL, ",");

                            if (strcasecmp(produto, cadastro.produto) != 0)
                            {
                                break;
                            }
                            else
                            {
                                if (linha != NULL)
                                {
                                    sscanf(linha, "%s[^\n]", &cadastro.forma_venda);

                                    linha = strtok(NULL, ",");

                                    if (linha != NULL)
                                    {
                                        sscanf(linha, "%i", &cadastro.valor);

                                        linha = strtok(NULL, ",");

                                        if (linha != NULL)
                                        {
                                            sscanf(linha, "%i", &cadastro.validade);
                                        }
                                    }
                                }
                                system("cls");
                                printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
                                printf("\nCONSULTA DE PRODUTOS:\n\n\n");
                                printf("\n\nItem encontrado:\n\n");
                                char simbolo1 = '-';
                                for (int i = 0; i < 30; i++)
                                {
                                    printf("%c", simbolo1);
                                }
                                printf("\n");
                                printf("\nCódigo de identificação: %i", cadastro.codigo_identificacao);
                                printf("\nProduto: %s", cadastro.produto);
                                printf("\nForma de venda: %s", cadastro.forma_venda);
                                printf("\nValor (centavos): %i", cadastro.valor);
                                printf("\nValidade (dias): %i", cadastro.validade);
                                printf("\n\n");
                                char simbolo2 = '-';
                                for (int i = 0; i < 30; i++)
                                {
                                    printf("%c", simbolo2);
                                }
                                break;
                            }
                        }
                    }
            }
            printf("\nProduto %s não encontrado!\n\n", produto);

            if (fclose(arquivo) != 0)
            {
                perror("\n\nErro ao fechar arquivo!\n\n");
            }
        }
    }
}




void alterar_cadastro()
{

    visualizar_dados(1);

    printf("\n\nDigite o código do produto que deseja alterar:\n\n");

    int codigo_busca = 0;

    scanf("%i", &codigo_busca);


    struct cadastro_produtos cadastro = {0};

    FILE *arquivo = fopen("cadastro_produtos.csv", "r+");
    if (arquivo == NULL)
    {
        if (fclose(arquivo) != 0)
        {
            perror("\n\nErro ao fechar arquivo!\n\n");
        }
    }

    FILE *tempArquivo = fopen("temp.csv", "w");
    if (tempArquivo == NULL)
    {
        if (fclose(tempArquivo) != 0)
        {
            perror("\n\nErro ao fechar arquivo!\n\n");
        }
    }

    char linha[1024];
    while (fgets(linha, sizeof(linha), arquivo) != NULL)
    {

        int codigo = 0;

        sscanf(linha, "%i,%99s[^,],%i,%f,%i,%i", &cadastro.codigo_identificacao, &cadastro.produto, &cadastro.forma_venda, &cadastro.valor, &cadastro.validade);

        if (codigo_busca == cadastro.codigo_identificacao)
        {

            codigo = codigo_busca;

            printf("\nDigite o nome do produto:\n\n");
            fflush(stdin);
            scanf("%s[^\n]", &cadastro.produto);

            for (int cont = 0; cadastro.produto[cont] != '\0'; cont++)
            {
                cadastro.produto[cont] = toupper(cadastro.produto[cont]);
            }

            printf("\nDigite a forma de venda (kg | unidade):\n\n");
            fflush(stdin);
            scanf("%s[^\n]", &cadastro.forma_venda);

            for (int cont = 0; cadastro.forma_venda[cont] != '\0'; cont++)
            {
                cadastro.forma_venda[cont] = toupper(cadastro.forma_venda[cont]);
            }

            printf("\nDigite o valor do produto:\n\n");
            scanf("%i", &cadastro.valor);

            printf("\nDigite a validade do produto em dias:\n\n");
            scanf("%i", &cadastro.validade);


            fprintf(tempArquivo, "%i,%s,%s,%i,%i\n", codigo, cadastro.produto, cadastro.forma_venda, cadastro.valor, cadastro.validade);

            system("cls");
            printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
            printf("\nALTERAR CADASTRO DE PRODUTOS:\n\n\n");
            printf("\nO item de código %i foi atualizado com sucesso!\n\n", codigo);
        }
        else
        {
            fprintf(tempArquivo, "%s", linha);
        }
    }

    if (fclose(arquivo) != 0 || fclose(tempArquivo) != 0)
    {
        perror("\n\nErro ao fechar arquivo!\n\n");
    }
    else
    {
        remove("cadastro_produtos.csv");
        rename("temp.csv", "cadastro_produtos.csv");
    }
}




void exibir_relatorios(int opcao)
{
    if (opcao == 1)
    {
        char produto[4096][50] = {0};
        char forma_venda[4096][50] = {0};
        char forma_pagamento[4096][50] = {0};
        int quantidade[4096] = {0};
        char data[4096][50] = {0};
        int valor[4096] = {0};
        int codigo_venda[4096] = {0};

        int cont = 0;

        char informacao[2046];

        FILE *arquivo = fopen("vendas.csv", "r");

        if (!arquivo)
        {
            perror("\n\nNão foi possível abrir ou criar o arquivo informado!\n\n");
        }
        else
        {
            fgets(informacao, sizeof(informacao), arquivo); //descarta a leitura da primeira linha do arquivo (cabeçalho)

            while((fgets(informacao, sizeof(informacao), arquivo)) != NULL)
            {
                char *linha = strtok(informacao, ",");

                if (linha != NULL)
                {
                    sscanf(linha, "%s[^\n]", &produto[cont]);

                    linha = strtok(NULL, ",");

                    if (linha != NULL)
                    {
                        sscanf(linha, "%s[^\n]", &forma_venda[cont]);

                        linha = strtok(NULL, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%s[^\n]", &forma_pagamento[cont]);

                            linha = strtok(NULL, ",");

                            if (linha != NULL)
                            {
                                sscanf(linha, "%i", &quantidade[cont]);

                                linha = strtok(NULL, ",");

                                if (linha != NULL)
                                {
                                    sscanf(linha, "%s[^\n]", &data[cont]);

                                    linha = strtok(NULL, ",");

                                    if (linha != NULL)
                                    {
                                        sscanf(linha, "%i", &valor[cont]);

                                        linha = strtok(NULL, ",");

                                        if (linha != NULL)
                                        {
                                            sscanf(linha, "%i", &codigo_venda[cont]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                cont++;
            }
            system("cls");
            printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
            printf("\nEXIBIÇÃO DE RELATÓRIOS: VENDAS\n\n");


            printf("\n\n");
            char simbolo1 = '-';
            for (int i = 0; i < 55; i++)
            {
                printf("%c", simbolo1);
            }
            printf("\n\n");

            //---------------------------------------------

            printf("\n * Vendas efetuadas entre: %s e %s\n\n", data[0], data[cont-1]);



            int quantidade_vendas = 0;

            for (int aux = 0; aux < cont; aux++)
            {
                if (quantidade_vendas != codigo_venda[aux])
                {
                    quantidade_vendas++;
                }
            }

            printf("\n * Quantidade de vendas: %i\n\n", quantidade_vendas);


            float valor_total = 0;

            for (int aux = 0; aux < cont; aux++)
            {
                valor_total += valor[aux];
            }

            printf("\n * Valor total das vendas: R$ %.2f\n\n", (valor_total / 100));


            printf("\n * Valor médio das compras: R$ %.2f\n\n", ((valor_total / 100) / quantidade_vendas));


            int qtd_forma_de_pagamento = 0;
            float credito = 0, debito = 0, pix = 0;

            for (int aux = 0; aux < cont; aux++)
            {

                if (qtd_forma_de_pagamento != codigo_venda[aux])
                {
                    qtd_forma_de_pagamento++;

                    if (strcmp(forma_pagamento[aux], "CREDITO") == 0)
                    {
                        credito++;
                    }
                    else if (strcmp(forma_pagamento[aux], "DEBITO") == 0)
                    {
                        debito++;
                    }
                    else if (strcmp(forma_pagamento[aux], "PIX") == 0)
                    {
                        pix++;
                    }
                }
            }

            printf("\n * Formas de pagamento utilizadas:\n\n");
            printf("\n  - Cartão de Crédito: %.0f vezes ou %.2f %% das vendas\n", credito, ((credito * 100) / quantidade_vendas));
            printf("\n  - Cartão de Débito: %.0f vezes ou %.2f %% das vendas\n", debito, ((debito * 100) / quantidade_vendas));
            printf("\n  - PIX: %.0f vezes ou %.2f %% das vendas\n", pix, ((pix * 100) / quantidade_vendas));



            //---------------------------------------------

            printf("\n\n");
            char simbolo2 = '-';
            for (int i = 0; i < 55; i++)
            {
                printf("%c", simbolo2);
            }

            printf("\n\n");
        }
        if (fclose(arquivo) != 0)
        {
            perror("\n\nErro ao fechar arquivo!\n\n");
        }
    }
    else
    {
        int codigo_identificacao[4096] = {0};
        char produto[4096][50] = {0};
        char forma_venda[4096][50] = {0};
        int quantidade[4096] = {0};
        char data_entrada[4096][50] = {0};
        int qtd_min[4096] = {0};
        int qtd_max[4096] = {0};

        int cont = 0;

        FILE *arquivo = fopen("estoque.csv", "r");

        if (!arquivo)
        {
            perror("\n\nNão foi possível abrir ou criar o arquivo informado!\n\n");
        }
        else
        {
            char informacao[2046];

            fgets(informacao, sizeof(informacao), arquivo); //descarta a leitura da primeira linha do arquivo (cabeçalho)

            while((fgets(informacao, sizeof(informacao), arquivo)) != NULL)
            {
                char *linha = strtok(informacao, ",");

                if (linha != NULL)
                {
                    sscanf(linha, "%i", &codigo_identificacao[cont]);

                    linha = strtok(NULL, ",");

                    if (linha != NULL)
                    {
                        sscanf(linha, "%s[^\n]", &produto[cont]);

                        linha = strtok(NULL, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%s[^\n]", &forma_venda[cont]);

                            linha = strtok(NULL, ",");

                            if (linha != NULL)
                            {
                                sscanf(linha, "%i", &quantidade[cont]);

                                linha = strtok(NULL, ",");

                                if (linha != NULL)
                                {
                                    sscanf(linha, "%s[^\n]", &data_entrada[cont]);

                                    linha = strtok(NULL, ",");

                                    if (linha != NULL)
                                    {
                                        sscanf(linha, "%i", &qtd_min[cont]);

                                        linha = strtok(NULL, ",");

                                        if (linha != NULL)
                                        {
                                            sscanf(linha, "%i", &qtd_max[cont]);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                cont++;
            }
            if (fclose(arquivo) != 0)
            {
                perror("\n\nErro ao fechar arquivo!\n\n");
            }
        }

        int codigo_identificacao_saida[4096] = {0};
        int quantidade_saida[4096] = {0};
        char data_saida[4096][50] = {0};

        int contar = 0;

        FILE *arquivo_saida = fopen("baixa_estoque.csv", "r");

        if (!arquivo)
        {
            perror("\n\nNão foi possível abrir ou criar o arquivo informado!\n\n");
        }
        else
        {
            char informacao[2046];

            fgets(informacao, sizeof(informacao), arquivo_saida); //descarta a leitura da primeira linha do arquivo (cabeçalho)


            while((fgets(informacao, sizeof(informacao), arquivo_saida)) != NULL)
            {
                char *linha = strtok(informacao, ",");

                if (linha != NULL)
                {
                    sscanf(linha, "%i", &codigo_identificacao_saida[cont]);

                    linha = strtok(NULL, ",");

                    if (linha != NULL)
                    {
                        sscanf(linha, "%i", &quantidade_saida[cont]);

                        linha = strtok(NULL, ",");

                        if (linha != NULL)
                        {
                            sscanf(linha, "%s[^\n]", &data_saida[cont]);
                        }
                    }
                }
                contar++;
            }

        }
        system("cls");
        printf("\n\nVERDURÃO HORTIFRUTI | SERVIDOR\n\n");
        printf("\nEXIBIÇÃO DE RELATÓRIOS: ESTOQUE\n\n");

        //---------------------------------------------

        char status[50] = {0};

        for (int aux = 0; aux < cont; aux++)
        {
            if ((quantidade[aux] - quantidade_saida[aux]) < qtd_min)
            {
                strcpy(status, "SITUAÇÃO CRÍTCA - EFETUAR PEDIDO DE COMPRA DO PRODUTO COM URGÊNCIA");
            }
            else if ((quantidade[aux] - quantidade_saida[aux]) > qtd_max)
            {
                strcpy(status, "SITUAÇÃO NÃO RECOMENDADA - PAUSAR PEDIDOS DE COMPRA DO PRODUTO");
            }
            else
            {
                strcpy(status, "SITUAÇÃO IDEAL - FLUXO DE ENTRADA E SAÍDA ESTÁ CORRETO");
            }

            printf("\n\n");
            char simbolo1 = '-';
            for (int i = 0; i < 90; i++)
            {
                printf("%c", simbolo1);
            }
            printf("\n");

            printf("\nCódigo: %i  |  Produto: %s  |  Forma de venda: %s  |  Quantidade em estoque: %i\n",
              codigo_identificacao[aux], produto[aux], forma_venda[aux],(quantidade[aux] - quantidade_saida[aux]));

            printf("\n");
            char simbolo2 = '-';
            for (int i = 0; i < 90; i++)
            {
                printf("%c", simbolo2);
            }
            printf("\n");
         }
         printf("\n");

         //---------------------------------------------



         if (fclose(arquivo_saida) != 0)
         {
             perror("\n\nErro ao fechar arquivo!\n\n");
         }
    }
}