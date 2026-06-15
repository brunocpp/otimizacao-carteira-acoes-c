#include <stdio.h>
#include <stdlib.h>
#include "acao.h"

void lerAcoesTeclado(Acao acoes[], int *quantidade, float *capital) {
    printf("Quantidade de acoes: ");
    scanf("%d", quantidade);

    printf("Capital disponivel: ");
    scanf("%f", capital);

    for (int i = 0; i < *quantidade; i++) {
        printf("Acao %d - ID Custo Retorno Ticker: ", i + 1);
        scanf("%s %f %f %s", acoes[i].id, &acoes[i].custo, &acoes[i].retorno, acoes[i].ticker);
    }
}

void lerAcoesArquivo(char nomeArquivo[], Acao acoes[], int *quantidade, float *capital) {
    FILE *arquivo = fopen(nomeArquivo, "r");

    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo.\n");
        exit(1);
    }

    fscanf(arquivo, "%d %f", quantidade, capital);

    for (int i = 0; i < *quantidade; i++) {
        if (fscanf(arquivo, "%s %f %f %s", acoes[i].id, &acoes[i].custo, &acoes[i].retorno, acoes[i].ticker) != 4) {
            printf("Arquivo malformado.\n");
            fclose(arquivo);
            exit(1);
        }
    }

    fclose(arquivo);
}

void exibirAcoesDisponiveis(Acao acoes[], int quantidade) {
    printf("\nAcoes disponiveis:\n");

    for (int i = 0; i < quantidade; i++) {
        printf("%s | Ticker: %s | Custo: R$ %.2f | Retorno: %.1f%%\n",
               acoes[i].id, acoes[i].ticker, acoes[i].custo, acoes[i].retorno);
    }
}