# Projeto PAA

Projeto em C para gerenciamento de atividades.

## Arquivos

- `listaAtividades.c`: implementação das funções da lista.
- `listaAtividades.h`: estruturas e declarações das funções.
- `main.c`: exemplo de cadastro, busca, atualização, remoção e liberação de memória.
-  `pilha.h`: estruturas `NoPilha` e `Pilha`, contratos e declaracoes.

## Compilar e executar

É necessário um compilador C com suporte a C11, como GCC.

No Windows (PowerShell):

```powershell
gcc -std=c11 -Wall -Wextra -Wpedantic main.c listaAtividades.c -o projeto-paa.exe
.\projeto-paa.exe
```

No Linux ou macOS:

```sh
gcc -std=c11 -Wall -Wextra -Wpedantic main.c listaAtividades.c -o projeto-paa
./projeto-paa
```

## Operacoes da pilha

| Funcao | Resultado |
| --- | --- |
| `InicializarPilha(&pilha)` | Define topo nulo e tamanho zero. |
| `empilhar(&pilha, valor)` | Insere no topo; retorna 1 no sucesso ou 0 se faltar memoria. |
| `desempilhar(&pilha, &valor)` | Copia e remove o topo; retorna 1 no sucesso ou 0 se vazia ou se a saida for nula. |
| `pilhaVazia(&pilha)` | Retorna 1 se vazia ou 0 se houver nos. |
| `liberarPilha(&pilha)` | Libera os nos restantes e permite reutilizacao. |
