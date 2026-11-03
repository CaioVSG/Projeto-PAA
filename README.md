# Projeto PAA

Projeto em C para gerenciamento de atividades.

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

