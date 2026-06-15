#include <stdio.h>
#include "acao.h"
#include "otimizador.h"
#include "relatorio.h"

#define MAX_ACOES 100

int main() {
    Acao acoes[MAX_ACOES];
    int escolhidas[MAX_ACOES];
    int quantidade = 0;
    float capital = 0;
    int opcao;
    char nomeArquivo[100];

    printf("Otimizacao de Carteira de Acoes\n");
    printf("1. Ler dados por arquivo\n");
    printf("2. Ler dados pelo teclado\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    if (opcao == 1) {
        printf("Nome do arquivo: ");
        scanf("%s", nomeArquivo);
        printf("Tentando abrir: %s\n", nomeArquivo);
        lerAcoesArquivo(nomeArquivo, acoes, &quantidade, &capital);
        printf("Leu %d acoes, capital %.2f\n", quantidade, capital);
    } else {
        lerAcoesTeclado(acoes, &quantidade, &capital);
    }

    exibirAcoesDisponiveis(acoes, quantidade);

    otimizarCarteira(acoes, quantidade, capital, escolhidas);

    exibirResultado(acoes, escolhidas, quantidade, capital);

    salvarResultadoArquivo(acoes, escolhidas, quantidade, capital);
    printf("\nResultado salvo em saidas/resultado.txt\n");

    return 0;
}