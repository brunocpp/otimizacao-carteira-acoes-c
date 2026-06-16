#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

    char linha[200];
    *quantidade = 0;
    *capital = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        if (linha[0] == '#') continue;

        if (strstr(linha, "CAPITAL_DISPONIVEL_R$:")) {
            sscanf(linha, "CAPITAL_DISPONIVEL_R$: %f", capital);
            continue;
        }

        if (strstr(linha, "ACOES:")) continue;

        if (linha[0] == '\n' || linha[0] == '\r') continue;

        if (sscanf(linha, "%s %f %f %s",
                   acoes[*quantidade].id,
                   &acoes[*quantidade].custo,
                   &acoes[*quantidade].retorno,
                   acoes[*quantidade].ticker) == 4) {
            (*quantidade)++;
                   }
    }

    fclose(arquivo);

    if (*capital == 0 || *quantidade == 0) {
        printf("Arquivo malformado.\n");
        exit(1);
    }
}

void exibirAcoesDisponiveis(Acao acoes[], int quantidade) {
    printf("\nAcoes disponiveis:\n");

    for (int i = 0; i < quantidade; i++) {
        printf("%s | Ticker: %s | Custo: R$ %.2f | Retorno: %.1f%%\n",
               acoes[i].id, acoes[i].ticker, acoes[i].custo, acoes[i].retorno);
    }
}