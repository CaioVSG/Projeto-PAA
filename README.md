# Projeto PAA

Projeto em C para gerenciamento de atividades em uma lista simplesmente encadeada, baseado no código fornecido.

## Arquivos

- `listaAtividades.c`: implementação das funções da lista.
- `listaAtividades.h`: estruturas e declarações das funções.
- `main.c`: exemplo de cadastro, busca, atualização, remoção e liberação de memória.

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

## Regras da lista

Inicialize a lista antes de usá-la e chame `liberarLista` ao terminar. Os ponteiros de lista recebidos pelas funções devem ser válidos.

Cada ID deve ser único. O início deve ser não negativo, o fim deve ser maior que o início e a pontuação deve ser não negativa. Sobreposições de horários são permitidas. As atividades são exibidas na ordem de inserção.

As operações de adicionar, atualizar e remover retornam `1` no sucesso e `0` na falha. A busca retorna um ponteiro pertencente à lista, ou `NULL` se o ID não existir. Não libere esse ponteiro nem o use depois da remoção do nó ou da liberação da lista.

Este projeto implementa a estrutura de dados fornecida; não inclui algoritmo de seleção ou otimização de atividades.
