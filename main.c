#include <stdio.h>
#include <stdlib.h>
#include "listaAtividades.h"

int main(void)
{
    ListaAtividades lista;
    inicializarLista(&lista);

    if (!adicionarAtividade(&lista, (Atividade){1, 0, 3, 10})
        || !adicionarAtividade(&lista, (Atividade){2, 3, 5, 20})
        || !adicionarAtividade(&lista, (Atividade){3, 5, 8, 15})) {
        fprintf(stderr, "Falha ao cadastrar as atividades.\n");
        liberarLista(&lista);
        return EXIT_FAILURE;
    }

    puts("Atividades cadastradas:");
    exibirAtividades(&lista);

    NoAtividade *encontrada = buscarAtividade(&lista, 2);
    if (encontrada != NULL) {
        printf("\nBusca: atividade %d encontrada.\n", encontrada->atividade.id);
    }

    if (!atualizarAtividade(&lista, 2, 3, 6, 25)
        || !removerAtividade(&lista, 1)) {
        fprintf(stderr, "Falha ao atualizar ou remover atividade.\n");
        liberarLista(&lista);
        return EXIT_FAILURE;
    }
    puts("\nDepois de atualizar a atividade 2 e remover a atividade 1:");
    exibirAtividades(&lista);

    liberarLista(&lista);
    return EXIT_SUCCESS;
}
