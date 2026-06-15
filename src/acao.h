#ifndef ACAO_H
#define ACAO_H

typedef struct {
    char id[10];
    char ticker[50];
    float custo;
    float retorno;
} Acao;

void lerAcoesTeclado(Acao acoes[], int *quantidade, float *capital);
void lerAcoesArquivo(char nomeArquivo[], Acao acoes[], int *quantidade, float *capital);
void exibirAcoesDisponiveis(Acao acoes[], int quantidade);

#endif