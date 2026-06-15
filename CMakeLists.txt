cmake_minimum_required(VERSION 3.20)
project(carteira C)

set(CMAKE_C_STANDARD 11)

include_directories(src)

add_executable(carteira
        src/main.c
        src/acao.c
        src/otimizador.c
        src/relatorio.c
)