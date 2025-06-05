# Coletor de Lixo

**Primeiro Trabalho de Implementação da disciplina de Paradigmas de Programação**

  Implementação de coletor de lixo automático utilizando a linguagem C e a técnica de contagem de referências.

## Técnica de Contagem de Referências
  A contagem de referências é uma técnica de gerenciamento de memória que visa liberar automaticamente os objetos que não estão mais em uso pelo programa.

  Cada objeto na memória possui um contador que registra quantas referências (ou ponteiros) apontam para ele. Esse contador é atualizado sempre que:

  uma nova referência ao objeto é criada (o contador é incrementado);

  uma referência é removida ou sobrescrita (o contador é decrementado).

  Quando o contador de referências de um objeto chega a zero, isso significa que ele não é mais acessível por nenhuma parte do programa, e portanto pode ser automaticamente liberado da memória.

### Vantagens
  Simples de implementar.

  Liberação imediata da memória, sem pausas longas como em outros métodos.

### Limitações
  Incapaz de detectar referências circulares (dois ou mais objetos referenciando-se mutuamente, mas inacessíveis pelo restante do programa).

## Membros
  Matheus Oliveira Monteiro

  Rodolfo Maia Filho


## 👨‍💻 Como compilar e executar


### 1. Compile a biblioteca estática

```bash
gcc -c cont_ref.c -o cont_ref.o
ar rcs libcontref.a cont_ref.o
```

### 2. Compile e linke o programa principal
```bash
gcc main.c -L. -lcontref -o programa
```

### 3. Execute
```bash
./programa
```
