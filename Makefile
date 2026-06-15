CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
EXEC = carteira
SRC = src/main.c src/acao.c src/otimizador.c src/relatorio.c

all: saidas $(EXEC)

$(EXEC):
	$(CC) $(CFLAGS) $(SRC) -o $(EXEC)

saidas:
	mkdir -p saidas

run: all
	./$(EXEC)

clean:
	rm -f $(EXEC)