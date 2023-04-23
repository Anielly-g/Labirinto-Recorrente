# Labirinto Recorrente

## Exercício Proposto
Segunda atividade avaliativa da disciplina Algoritmos e Estruturas de Dados I sobre um caminho aleatório percorrido no labirinto.

- Um garoto se encontra perdido em um labirinto, o qual é compreendido por nós como sendo uma matriz cujas posição de sua localização é dada por um valor x,y dessa estrutura. Nesse labirinto há paredes que bloqueiam certos passos (#), perigos que consomem parte de sua vida (*) e trajetórias (valores positivos que devem ser subtraídos em 1 a cada passagem).

- Quanto as paredes #, não há muito o que fazer a não ser desviar e continuar a rota. Já os perigos, a cada passada, tende a subtrair 1 de vida de um total de 10. Assim, ao ficar sem pontos de vida o algoritmo deve parar e indicar fim de jogo.

- Ao decorrer do jogo, a cada passo correto sob uma estrada, o garoto consome um item, subtraindo esse do valor que compõe a posição x,y. Gravando nessa o valor resultante. A cada subtração bem sucedida é preciso, essa vai para um banco de vida que cheio (a cada 4 ações bem sucedidas) lhe retorna 1 de vida em seu contador. Contudo, pode haver partes do caminho com zero itens, esses devem continuar sendo utilizados, porém, sem computar pontuação.

- O labirinto deve ser lido do arquivo input.data, o qual apresentará várias matrizes, todas quadráticas. Sua missão é percorrer as matrizes até que todo o caminho percorrido pelo garoto se torne zero ou que ele venha a morrer devido aos perigos enfrentados. No final é preciso apresentar como resultado: (a) quantas casas foram percorridas ao todo; (b) qual a soma de itens consumidos pelo caminho; (c) quantas casas da matriz ficaram sem serem exploradas; (d) quantos perigos foram enfrentados ao decorrer do percurso.

- Para essa atividade, considere selecionar um passo de cada vez de forma aleatória, ou seja, escolha um valor x,y aleatoriamente e vá para ele se possível ou descarte caso seja uma parede. Perigos não são evitados, então, se a posição escolhida for um, enfrente-o. Por fim, a intenção global do problema não é encontrar uma saída, mas sim, tentar consumir o máximo possível de itens até chegar a zerar as possibilidades desse tipo ou morrer tentando.

Qual o custo computacional da sua estratégia randômica? Se mostrou uma boa alternativa de execução?

## Interpretação do problema 

O caminho vai ser lido a partir de um arquivo chamado input.data. Na primeira linha do arquivo terá o número de linhas e colunas que serão as dimensões da matriz e também quantas matrizes há no arquivo. 

A partir desses dados será lido cada matriz, criado um arquivo para cada uma e o programa a salvará nele. Isso se deve ao fato de ser mais fácil e simples de acessar a matriz , visto que ela poderá ser acessada várias vezes e poderá ter o conteúdo mudado. Após isso, o viajante começará a andar e qualquer movimentação será decidida de forma aleatória. Os casos de movimetação são:

FIGURA CASO 1
CASO 1- PRIMEIRA COLUNA E PRIMEIRA LINHA 

O  caso 2 é uma exceção, depois voltaremos nele.

FIGURA CASO 3
CASO 3- ÚLTIMA LINHA E ÚLTIMA COLUNA

FIGURA CASO 4
CASO 4- PRIMEIRA COLUNA E QUALQUER COLUNA

FIGURA CASO 5
CASO 5- PRIMEIRA LINHA E ÚLTIMA COLUNA 

FIGURA CASO 6
CASO 6- ÚLTIMA COLUNA E QUALQUER LINHA

FIGURA CASO 7
CASO 7- ÚLTIMA LINHA E QUALQUER COLUNA

FIGURA CASO 8
CASO 8- PRIMEIRA LINHA E QUALQUER COLUNA

FIGURA CASO 9
CASO 9- QUALQUER LINHA E QUALQUER COLUNA

O programa irá escolher de forma aleatória qualquer uma das posições indicadas pelas setas tendo como base a posição do viajante.
Nessas posições terão os perigos * que tirarão uma vida do viajante. Também há o obstáculo que é uma parede # que não haverá como passar por ela. E existem as posições em que terá números inteiros de 0-9. Quando esse número for maior que zero, o viajante ganhará um item na sua mochila e a cada 4 itens pegos ganhará uma vida. E o número inteiro terá um item subtraído por causa que o viajante pegou um. Se a posição tiver o número 0, ele apenas passará por ela, sem acontecer nada com ele e não terá nenhum item adicionado na mochila.

O viajante poderá se teletransportar para outra matriz. As condições adotadas são se a posição é a última linha e última coluna ou se o viajante já andou dentro de uma matriz pelo menos 20 vezes. E isso é verificado no caso que é exceção, o caso 2. 

FIGURA CASO 2
CASO 2 - ÚLTIMA LINHA E ÚLTIMA COLUNA DA MATRIZ OU 20 MOVIMENTAÇÕES

O teletransporte ocorre como no exemplo abaixo: 

EXEMPLO DE COMO O TELETRANSPORTE É.

E por último existe o critério para vencer e para perder.
| CASOS |                  COMO           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
| Perder | O viajante visitou muitas casas, muitas delas eram perigos e ele perdeu todas as suas 10 vidas|
| Ganhar | O viajante visitou muitas casas, sem pegar nenhum item e nem ganhar vida, e conseguiu chegoar no ponto de partida na primeira matriz|




# Compilação e Execução

O labirinto recorrente disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

É recomendado executar um `make clean` antes do `make`.
