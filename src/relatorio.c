#include <stdio.h>
#include "relatorio.h"

void exibirResultado(Acao acoes[], int escolhidas[], int quantidade, float capital) {
    float custoTotal = 0;
    float retornoTotal = 0;
    int encontrou = 0;

    printf("\nAcoes escolhidas:\n");

    for (int i = 0; i < quantidade; i++) {
        if (escolhidas[i]) {
            printf("%s | Ticker: %s | Custo: R$ %.2f | Retorno: %.1f%%\n",
                   acoes[i].id, acoes[i].ticker, acoes[i].custo, acoes[i].retorno);
            custoTotal += acoes[i].custo;
            retornoTotal += acoes[i].retorno;
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma acao escolhida.\n");
    }

    printf("\nCusto total: R$ %.2f\n", custoTotal);
    printf("Retorno total: %.1f%%\n", retornoTotal);
    printf("Capital restante: R$ %.2f\n", capital - custoTotal);
}

void salvarResultadoArquivo(Acao acoes[], int escolhidas[], int quantidade, float capital) {
    FILE *arquivo = fopen("saidas/resultado.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao salvar resultado.\n");
        return;
    }

    float custoTotal = 0;
    float retornoTotal = 0;
    int encontrou = 0;

    fprintf(arquivo, "Acoes escolhidas:\n");

    for (int i = 0; i < quantidade; i++) {
        if (escolhidas[i]) {
            fprintf(arquivo, "%s | Ticker: %s | Custo: R$ %.2f | Retorno: %.1f%%\n",
                    acoes[i].id, acoes[i].ticker, acoes[i].custo, acoes[i].retorno);
            custoTotal += acoes[i].custo;
            retornoTotal += acoes[i].retorno;
            encontrou = 1;
        }
    }

    if (!encontrou) fprintf(arquivo, "Nenhuma acao escolhida.\n");

    fprintf(arquivo, "\nCusto total: R$ %.2f\n", custoTotal);
    fprintf(arquivo, "Retorno total: %.1f%%\n", retornoTotal);
    fprintf(arquivo, "Capital restante: R$ %.2f\n", capital - custoTotal);

    fclose(arquivo);
}