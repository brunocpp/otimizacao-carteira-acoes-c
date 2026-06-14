#ifndef ACAO_H
#define ACAO_H

typedef struct {
    char id[10];
    char ticker[50];
    int custo;
    int retorno;
} Acao;

Acao *criarListaAcoes(int quantidade);

void liberarListaAcoes(Acao *acoes);

int lerAcoesTeclado(Acao **acoes, int *quantidade, int *capital);

int lerAcoesArquivo(char nomeArquivo[], Acao **acoes, int *quantidade, int *capital);

void exibirAcoesDisponiveis(Acao *acoes, int quantidade);

#endif