# MAC0422 - EP3

## Integrantes 
| Nome                	| NUSP      |
|---------------------	|---------- |
| Daniel Martinez     	| 10297709  |
| Pedro Paulo Bambace 	| 10297668  |
|                     	|           |


## Arquivos criados/modificados
+ `/usr/src/servers/pm/alloc.c`
+ `/root/memstat.c`
+ `/root/memstat`
+ `/root/makefile`

Além disso, adicionamos a ferramenta de testes disponibilizada pelo professor em `/root/memuse/`

## Detalhes de implementação

### Algoritmo de alocação _worst fit_

Na função `alloc_mem()` do Process Manager, substituimos o algoritmo que escolhe o _buraco_ na memória onde um novo espaço será alocado pelo _worst fit_. Para isso, iteramos todos os _buracos_ disponíveis e escolhemos o maior para alocação da memoria.

### Estatísticas sobre _buracos_ na memória

Criamos o programa especificado no enunciado que utiliza a chamada de sistema `getsysinfo()` para coletar informações sobre os _buracos_ presentes na memória, que nos retorna um vetor de _buracos_. Com essa informação, criamos um vetor com o tamanho dos _buracos_ existentes e sua quantidade, para o cálculo da média, desvio padrão e mediana. 

### Arquivo de build
Para compilar o executável do `memstat`, basta executar `make` no diretório `/root/`, como exemplificado no enunciado.


