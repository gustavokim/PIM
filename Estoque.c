#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LINE 1024

// Função para abrir um arquivo com um modo especificado
FILE *abrirArquivo(const char *nomeArquivo, const char *modo) {
    FILE *arquivo = fopen(nomeArquivo, modo);
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo %s.\n", nomeArquivo);
    }
    return arquivo;
}

// Função para ler um arquivo linha por linha
void lerArquivo(const char *nomeArquivo) {
    FILE *arquivo = abrirArquivo(nomeArquivo, "r");
    if (arquivo == NULL) return;

    char linha[MAX_LINE];
    while (fgets(linha, MAX_LINE, arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
}

// Função para escrever uma linha em um arquivo
void escreverArquivo(const char *nomeArquivo, const char *conteudo) {
    FILE *arquivo = abrirArquivo(nomeArquivo, "a");
    if (arquivo == NULL) return;

    fprintf(arquivo, "%s\n", conteudo);
    fclose(arquivo);
}

// Função para cadastrar um item
void cadastrarItem() {
    int codigo, validade, minimo, maximo;
    char descricao[100];
    float preco;

    printf("Codigo do item: ");
    scanf("%i", &codigo);
    printf("Descricao: ");
    scanf("%s", descricao);
    printf("Validade (em dias): ");
    scanf("%i", &validade);
    printf("Preco de venda: ");
    scanf("%f", &preco);
    printf("Estoque minimo: ");
    scanf("%i", &minimo);
    printf("Estoque maximo: ");
    scanf("%i", &maximo);

    char buffer[MAX_LINE];
    snprintf(buffer, MAX_LINE, "%i,%s,%i,%.2f,%i,%i", codigo, descricao, validade, preco, minimo, maximo);
    escreverArquivo("Cadastro.csv", buffer);
}

// Função para buscar um item pelo código
void buscarItemPorCodigo(int codigoBusca) {
    FILE *arquivo = abrirArquivo("Cadastro.csv", "r");
    if (arquivo == NULL) return;

    char linha[MAX_LINE];
    while (fgets(linha, MAX_LINE, arquivo) != NULL) {
        int codigo;
        sscanf(linha, "%i,", &codigo);
        if (codigo == codigoBusca) {
            printf("Item encontrado: %s", linha);
            fclose(arquivo);
            return;
        }
    }
    printf("Item com código %d não encontrado.\n", codigoBusca);
    fclose(arquivo);
}

// Função para alterar o preço de um item pelo código
void alterarPrecoPorCodigo(int codigoBusca, float novoPreco) {
    FILE *arquivo = abrirArquivo("Cadastro.csv", "r+");
    if (arquivo == NULL) return;

    FILE *tempArquivo = abrirArquivo("temp.csv", "w");
    if (tempArquivo == NULL) {
        fclose(arquivo);
        return;
    }

    char linha[MAX_LINE];
    while (fgets(linha, MAX_LINE, arquivo) != NULL) {
        int codigo;
        float precoAtual;
        char descricao[100];
        int validade, minimo, maximo;

        sscanf(linha, "%i,%99[^,],%i,%f,%i,%i", &codigo, descricao, &validade, &precoAtual, &minimo, &maximo);
        if (codigo == codigoBusca) {
            fprintf(tempArquivo, "%i,%s,%i,%.2f,%i,%i\n", codigo, descricao, validade, novoPreco, minimo, maximo);
            printf("Preço atualizado para o item de código %d.\n", codigoBusca);
        } else {
            fprintf(tempArquivo, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);
    remove("Cadastro.csv");
    rename("temp.csv", "Cadastro.csv");
}

// Função para atualizar o estoque de um item pelo código
void entradaEstoque(int codigoBusca, int quantidadeAdicionar) {
    FILE *arquivo = abrirArquivo("Cadastro.csv", "r+");
    if (arquivo == NULL) return;

    FILE *tempArquivo = abrirArquivo("temp.csv", "w");
    if (tempArquivo == NULL) {
        fclose(arquivo);
        return;
    }

    char linha[MAX_LINE];
    while (fgets(linha, MAX_LINE, arquivo) != NULL) {
        int codigo, validade, minimo, maximo, estoqueAtual;
        float preco;
        char descricao[100];

        sscanf(linha, "%i,%99[^,],%i,%f,%i,%i", &codigo, descricao, &validade, &preco, &minimo, &estoqueAtual);
        if (codigo == codigoBusca) {
            estoqueAtual += quantidadeAdicionar;
            fprintf(tempArquivo, "%i,%s,%i,%.2f,%i,%i\n", codigo, descricao, validade, preco, minimo, estoqueAtual);
            printf("Estoque atualizado para o item de código %d.\n", codigoBusca);
        } else {
            fprintf(tempArquivo, "%s", linha);
        }
    }

    fclose(arquivo);
    fclose(tempArquivo);
    remove("Cadastro.csv");
    rename("temp.csv", "Cadastro.csv");
}

// Menu principal do sistema
int main() {
    int opcao;

    do {
        printf("\n--- Sistema Hortifruti O Verdurão ---\n");
        printf("1. Cadastrar Item\n");
        printf("2. Consultar Item\n");
        printf("3. Alterar preco\n");
        printf("4. Estoque Item\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarItem();
                break;
            case 2:{
                int codigo;
                printf("Digite o codigo do item que deseja consultar: ");
                scanf("%d", &codigo);
                buscarItemPorCodigo(codigo);
                break;
            }
            case 3: {
                int codigo;
                float novoPreco;
                printf("Digite o codigo do item que deseja alterar: ");
                scanf("%d", &codigo);
                printf("Digite o novo preco: ");
                scanf("%f", &novoPreco);
                alterarPrecoPorCodigo(codigo, novoPreco);
                break;
            }
            case 4: {
                int codigo, quantidade;
                printf("Digite o codigo do item que deseja atualizar o estoque: ");
                scanf("%d", &codigo);
                printf("Digite a quantidade para adicionar ao estoque: ");
                scanf("%d", &quantidade);
                entradaEstoque(codigo, quantidade);
                break;
            }
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

    } while (opcao != 5);

    return 0;
}