# Producer/Consumer Problem

```
Um problema bastante conhecido para trabalhar com semaforos, o objetivo dele é
fazer 2 listas de threads para que uma seja do consumidor e outra do produtor
o produtor nesse caso consome o dado e o consumidor consome, com isso em mente para essa solução
precisamos fazer com que os semaforos avisem para os produtores quando o buffer estiver cheio que eles não
vão poder produzir, terá que esperar o consumidor consumir algum dado ou avisar para o consumidor que o buffer
está vázio e ele só poderá mexer quando estiver pelo menos um dado no buffer.
```

## Project Clone

```
$ git clone https://github.com/marcomansomm/Atividade06.git
$ cd Atividade06

```

## Compile

```
$ make 
(Compila o código e cria um código binário)
```

## Run

```
$ make run
(Executa o código Binário)
```

## Clean

```
$ make clean
(Exclui o código Binário)
