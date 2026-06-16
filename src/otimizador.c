#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "otimizador.h"

void otimizarCarteira(Acao acoes[], int quantidade, float capital, int escolhidas[]) {
    int cap = (int)(capital + 0.5f);

    int **dp = malloc((quantidade + 1) * sizeof(int *));
    for (int i = 0; i <= quantidade; i++) {
        dp[i] = calloc(cap + 1, sizeof(int));
    }

    for (int i = 1; i <= quantidade; i++) {
        int custo = (int)(acoes[i - 1].custo + 0.5f);
        int retorno = (int)(acoes[i - 1].retorno * 10 + 0.5f);

        for (int w = 0; w <= cap; w++) {
            dp[i][w] = dp[i - 1][w];

            if (custo <= w && retorno + dp[i - 1][w - custo] > dp[i][w]) {
                dp[i][w] = retorno + dp[i - 1][w - custo];
            }
        }
    }

    int w = cap;
    for (int i = quantidade; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            escolhidas[i - 1] = 1;
            w = w - (int)(acoes[i - 1].custo + 0.5f);
        } else {
            escolhidas[i - 1] = 0;
        }
    }

    for (int i = 0; i <= quantidade; i++) {
        free(dp[i]);
    }
    free(dp);
}