# matrizes
Rotinas com Matrizes em linguagem C e C++
  Este projeto tenta implementar uma matriz de frações com denominador e numerador inteiros. Primeiro são definidas as operações a serem feitas com as frações usando sobrecarca de operadores. Como a fração é um registro (struct), e é possível retornar um registro bem como atribuir um registro a outro registro na linguagem C/C++, então não foi preciso criar uma classe separada de frações; apenas foi preciso sobrecarregar os operadores '<<', '+', '-', '*', '>', '<', '==' e '/ '. 
  Definidas as operações com frações, cria-se uma matriz de frações com a classe Matriz, e implementa-se os métodos usando aquelas operações.
   Vale lembrar que em fração, o zero é o valor inteiro de zero dividido por qualquer valor diferente de zero, exemplo: 0/1, e a unidade (1) vale 1,1. Ao atribuir uma fração constante  a uma célula de matriz basta fazer M(linha,coluna) = (frac) {3,4} por exemplo. 
   Já consigo calcular a inversa, o determinante e resolver sistemas de equações usando o método da magtriz inversa apenas com frações. 
