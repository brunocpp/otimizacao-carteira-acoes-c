#include <stdio.h>
#include <string.h>
#include "otimizador.h"

#define MAX_ACOES 100
#define MAX_CAPITAL 10000

int dp[MAX_ACOES + 1][MAX_CAPITAL + 1];

void otimizarCarteira(Acao acoes[], int quantidade, float capital, int escolhidas[]) {
    int cap = (int)(capital + 0.5f);

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= quantidade; i++) {
        int custo = (int)(acoes[i - 1].custo + 0.5f);
        int retorno = (int)(acoes[i - 1].retorno + 0.5f);

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
}