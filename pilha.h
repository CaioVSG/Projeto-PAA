#ifndef PILHA_H /* Evita incluir este cabecalho duas vezes. */
#define PILHA_H /* Marca o cabecalho como incluido. */

/* Cada no guarda um inteiro e o endereco do no seguinte. */
typedef struct NoPilha { /* Define a estrutura de um no da pilha. */
    int valor; /* Guarda o numero inteiro deste no. */
    struct NoPilha *proximo; /* Aponta para o no logo abaixo. */
} NoPilha; /* Da o nome NoPilha a estrutura. */

/* O topo aponta para o ultimo valor empilhado. */
typedef struct { /* Define a estrutura que controla a pilha. */
    NoPilha *topo; /* Guarda o endereco do no do topo. */
    int tamanho; /* Conta quantos nos existem. */
} Pilha; /* Da o nome Pilha a estrutura. */

/* Passe sempre o endereco de uma Pilha existente.
   Inicialize antes do primeiro uso. Para esvaziar, use liberarPilha. */
void InicializarPilha(Pilha *pilha); /* Declara a funcao de inicializacao. */

/* Retorna 1 se inseriu e 0 se faltou memoria. */
int empilhar(Pilha *pilha, int valor); /* Declara a funcao de insercao. */

/* Copia o topo para *valor e remove o no. Retorna 1 no sucesso.
   Retorna 0 se a pilha estiver vazia ou valor for NULL, sem altera-la. */
int desempilhar(Pilha *pilha, int *valor); /* Declara a funcao de retirada. */

/* Retorna 1 se estiver vazia e 0 caso contrario. */
int pilhaVazia(const Pilha *pilha); /* Declara a consulta de pilha vazia. */

/* Libera todos os nos e deixa a pilha vazia para reutilizacao. */
void liberarPilha(Pilha *pilha); /* Declara a liberacao de memoria. */

#endif /* Encerra a protecao do cabecalho. */

