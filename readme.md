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

![image](https://user-images.githubusercontent.com/102706840/233863299-062dfeeb-ba5e-45a3-b2e3-ea8f515450de.png)

CASO 1- PRIMEIRA COLUNA E PRIMEIRA LINHA 

O  caso 2 é uma exceção, depois voltaremos nele.

![image](https://user-images.githubusercontent.com/102706840/233863386-2c756d65-b888-4e67-b6f1-af730bede6cf.png)

CASO 3- ÚLTIMA LINHA E PRIMEIRA COLUNA

![image](https://user-images.githubusercontent.com/102706840/233863461-6296211c-936b-49c5-a19e-923ceff263c8.png)

CASO 4- PRIMEIRA COLUNA E QUALQUER LINHA

![image](https://user-images.githubusercontent.com/102706840/233863551-ab65b0f2-10ca-42d0-97b4-7f7960728daa.png)

CASO 5- PRIMEIRA LINHA E ÚLTIMA COLUNA 

![image](https://user-images.githubusercontent.com/102706840/233863637-217d98cc-cf32-406a-984f-10f298e8bfcf.png)

CASO 6- ÚLTIMA COLUNA E QUALQUER LINHA

![image](https://user-images.githubusercontent.com/102706840/233863720-083ba7af-3685-4af9-ae40-a2cb46554a54.png)

CASO 7- ÚLTIMA LINHA E QUALQUER COLUNA

![image](https://user-images.githubusercontent.com/102706840/233864027-71ebcaa6-04b7-4eb6-86b6-5a18e0d9b2b2.png)

CASO 8- PRIMEIRA LINHA E QUALQUER COLUNA

![image](https://user-images.githubusercontent.com/102706840/233863950-b9b066d7-beaa-45c0-88c5-e52246ecfb39.png)

CASO 9- QUALQUER LINHA E QUALQUER COLUNA

O programa irá escolher de forma aleatória qualquer uma das posições indicadas pelas setas tendo como base a posição do viajante.
Nessas posições terão os perigos * que tirarão uma vida do viajante. Também há o obstáculo que é uma parede # que não haverá como passar por ela. E existem as posições em que terá números inteiros de 0-9. Quando esse número for maior que zero, o viajante ganhará um item na sua mochila e a cada 4 itens pegos, ganhará uma vida. E o número inteiro terá um item subtraído por causa que o viajante pegou um quando o visitou. Se a posição tiver o número 0, ele apenas passará por ela, sem acontecer nada com ele e não terá nenhum item adicionado na mochila.

O viajante poderá se teletransportar para outra matriz. As condições adotadas são se a posição é a última linha e última coluna ou se o viajante já andou dentro de uma matriz pelo menos 20 vezes.O teletransporte é feito para próxima matriz em uma posição aleatória. E isso é verificado no caso que é exceção, o caso 2. 

![image](https://user-images.githubusercontent.com/102706840/233864228-6bcfff50-fec9-4d2d-acfe-056c60adcf48.png)

CASO 2 - ÚLTIMA LINHA E ÚLTIMA COLUNA DA MATRIZ

OU 

![image](https://user-images.githubusercontent.com/102706840/233864471-24d9383b-5418-4a0a-ac39-d2b0c9033689.png)

Caso 2- A CADA 20 MOVIMENTAÇÕES

O teletransporte ocorre como no exemplo abaixo: 

![image](https://user-images.githubusercontent.com/102706840/233865041-725b4f63-85b2-4653-8b27-882ab11965f6.png)


E por último existe o critério para vencer e para perder.
| CASOS |                  COMO           |
| -----------------------| ------------------------------------------------------------------------------------------------- |
| Perder | O viajante visitou muitas casas, muitas delas eram perigos e ele perdeu todas as suas 10 vidas|
| Ganhar | O viajante visitou muitas casas, sem pegar nenhum item e nem ganhar vida, e conseguiu chegar no ponto de partida na primeira matriz|

## Entrada

A entrada é um arquivo input.data que foi fornecido por um programa feito pelo professor da disciplina , Michel Pires. Esse arquivo fornece a quantidade de linhas, colunas , quantidade de matriz(es) na primeira linha do arquivo e a(s) matriz(es) que sera(o) percorrida(s) no resto. Como no exemplo a seguir:

![image](https://user-images.githubusercontent.com/102706840/233865107-5508c1b2-bf35-4aba-982f-1b91d7e24b0a.png)


## Implementação 
 
Na implementação é usada a linguagem c++ por terem muitas vantagens na manipulação de arquivos. 
O primeiro passo da implementação é a abertura do arquivo para haver a manipulação do mesmo no programa. Depois se cria um arquivo para cada matriz e também se cria um arquivo com as mesmas dimensões para cada uma só que preenchidos por 0 para quando for feita a movimentação , cada casa que o viajante visitar se tornar 1 e assim fazer o controle de quantas casas não foram visitadas. Como no exemplo abaixo:

![image](https://user-images.githubusercontent.com/102706840/233865172-3344dbbc-f960-46ee-8ca8-fa48b43a444a.png)


Após isso, há um "do while" que tratará da movimentação do viajante nas matrizes. Nele, há as condições de cada movimentação. Por exemplo, se está na primeira casa da matriz (0,0) irá para uma função em que apenas poderá se movimentar para direita, baixo e diagonal inferior direita e essa movimentação será decidida de forma aleatória. Quando for decidida a direção que o viajante irá, o programa verifica se é perigo, parede ou item(s) e aplica as regras referente a cada um como o exemplo abaixo.

![image](https://user-images.githubusercontent.com/102706840/233865206-ef8f889f-e2f9-449c-b813-de698126e850.png)


## Saída 

A saída do programa apresenta se você ganhou ou perdeu, depois o número de casas visitadas, quantos itens foram pegos no total , quantos perigos o viajante enfretou , quantas casas não foram visitadas em cada matriz e o tempo de execução do programa.
Veja a seguir no teste:

![image](https://user-images.githubusercontent.com/102706840/233876573-7c52c0d9-3621-4c54-97de-0279c15762bc.png)



## Informações adicionais

O viajante começa com 10 vidas, com a sacola vazia e da posição (0,0) na primeira matriz.
O algoritmo não foi tratado para o caso em que a matriz é toda de paredes, se ele for testado com um input.data dessa maneira ,provavelmente , ficará compilando por um bom tempo sem nenhuma saída, será imprevisível visto que não foi testado e nem tratado para essa condição.

## Conclusão

Logo, uma estratégia randômica é uma abordagem que usa uma fonte de aleatoriedade para fazer escolhas em um processo de tomada de decisão. Em muitos casos, essa abordagem pode ser difícil de se calcular o custo computacional como acontece na minha, mas existe a noção de que quanto maior o espaço de busca e a quantidade de aleatoriedade necessária, maior será o custo computacional do programa. 

O meu programa está funcionando , mas não posso dizer que essa é a forma mais eficiente para se fazê-lo. Por isso, é importante avaliar cuidadosamente os prós e contras da abordagem randômica e sua aleatriedade em um programa.

# Compilação e Execução

O labirinto recorrente disponibilizado possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |

É recomendado executar um `make clean` antes do `make` e também excluir os arquivos ".data", exceto o "input.data".
