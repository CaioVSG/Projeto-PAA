#ifndef LISTA_ATIVIDADES_H
#define LISTA_ATIVIDADES_H

typedef struct {
    int id;
    int inicio;
    int fim;
    int pontuacao;
} Atividade;

typedef struct NoAtividade {
    Atividade atividade;
    struct NoAtividade *proximo;
} NoAtividade;

typedef struct {
    NoAtividade *inicio;
    NoAtividade *fim;
    int tamanho;
} ListaAtividades;

/* Inicialize a lista antes de usar as demais operacoes. */
void inicializarLista(ListaAtividades *lista);
int listaVazia(const ListaAtividades *lista);
/* O no retornado pertence a lista e nao deve ser liberado pelo chamador.
   Nao use o ponteiro depois da remocao do no ou da liberacao da lista. */
NoAtividade *buscarAtividade(const ListaAtividades *lista, int id);
int atividadeValida(Atividade atividade);
int adicionarAtividade(ListaAtividades *lista, Atividade atividade);
int atualizarAtividade(ListaAtividades *lista, int id, int inicio, int fim, int pontuacao);
int removerAtividade(ListaAtividades *lista, int id);
void exibirAtividades(const ListaAtividades *lista);
void liberarLista(ListaAtividades *lista);

#endif
