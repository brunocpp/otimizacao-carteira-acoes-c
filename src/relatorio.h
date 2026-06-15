#ifndef RELATORIO_H
#define RELATORIO_H

#include "acao.h"

void exibirResultado(Acao acoes[], int escolhidas[], int quantidade, float capital);
void salvarResultadoArquivo(Acao acoes[], int escolhidas[], int quantidade, float capital);

#endif