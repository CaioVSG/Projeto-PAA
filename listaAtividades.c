#include <stdio.h>
#include <stdlib.h>
#include "listaAtividades.h"

/* Inicializa uma lista que ainda nao possui elementos. */
void inicializarLista(ListaAtividades *lista)
{
    lista->inicio = NULL;
    lista->fim = NULL;
    lista->tamanho = 0;
}

/* Retorna 1 se estiver vazia e 0 caso contrario. */
int listaVazia(const ListaAtividades *lista)
{
    return lista->inicio == NULL;
}

NoAtividade *buscarAtividade(const ListaAtividades *lista, int id)
{
    NoAtividade *atual = lista->inicio;
    while (atual != NULL) {
        if (atual->atividade.id == id) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

/* Exige inicio nao negativo, duracao positiva e pontuacao nao negativa. */
int atividadeValida(Atividade atividade)
{
    return atividade.inicio >= 0
        && atividade.fim > atividade.inicio
        && atividade.pontuacao >= 0;
}

/* Adiciona ao final. Retorna 1 em caso de sucesso e 0 em caso de falha. */
int adicionarAtividade(ListaAtividades *lista, Atividade atividade)
{
    if (!atividadeValida(atividade)) {
        return 0;
    }
    if (buscarAtividade(lista, atividade.id) != NULL) {
        return 0; /* ID duplicado. */
    }
    NoAtividade *novo = malloc(sizeof(NoAtividade));
    if (novo == NULL) {
        return 0;
    }
    novo->atividade = atividade;
    novo->proximo = NULL;
    if (listaVazia(lista)) {
        lista->inicio = novo;
    } else {
        lista->fim->proximo = novo;
    }
    lista->fim = novo;
    lista->tamanho++;
    return 1;
}

/* Atualiza os dados mantendo o ID. Retorna 0 se nao existir ou for invalida. */
int atualizarAtividade(ListaAtividades *lista, int id, int inicio, int fim, int pontuacao)
{
    Atividade atualizada = {id, inicio, fim, pontuacao};
    if (!atividadeValida(atualizada)) {
        return 0;
    }
    NoAtividade *no = buscarAtividade(lista, id);
    if (no == NULL) {
        return 0;
    }
    no->atividade = atualizada;
    return 1;
}

/* Remove pelo ID. Retorna 1 se removeu e 0 se nao encontrou. */
int removerAtividade(ListaAtividades *lista, int id)
{
    NoAtividade *anterior = NULL;
    NoAtividade *atual = lista->inicio;
    while (atual != NULL && atual->atividade.id != id) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) {
        return 0;
    }
    if (anterior == NULL) {
        lista->inicio = atual->proximo;
    } else {
        anterior->proximo = atual->proximo;
    }
    if (atual == lista->fim) {
        lista->fim = anterior;
    }
    free(atual);
    lista->tamanho--;
    return 1;
}

/* Exibe as atividades na ordem de insercao. */
void exibirAtividades(const ListaAtividades *lista)
{
    if (listaVazia(lista)) {
        printf("Nenhuma atividade cadastrada.\n");
        return;
    }
    const NoAtividade *atual = lista->inicio;
    while (atual != NULL) {
        const Atividade *atividade = &atual->atividade;
        printf("ID: %d | Inicio: %d | Fim: %d | Pontuacao: %d\n",
               atividade->id, atividade->inicio, atividade->fim, atividade->pontuacao);
        atual = atual->proximo;
    }
    printf("Total: %d atividade(s).\n", lista->tamanho);
}

/* Libera todos os nos e deixa a lista vazia para reutilizacao. */
void liberarLista(ListaAtividades *lista)
{
    NoAtividade *atual = lista->inicio;
    while (atual != NULL) {
        NoAtividade *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    inicializarLista(lista);
}
