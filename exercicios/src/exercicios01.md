# Exercícios

1. Prove por indução que $5^n + 2\times11^n$ é divisível por 3 para todo $n \geq 0$ e que $6^n + 4$ é divisível por 5 para todo $n \geq 0$
2. Prove por indução que $\sum_{i = 1}^{n} \frac{1}{i(i+1)} = \frac{n}{n+1}$, para todo $n \geq 1$
3. Um algoritmo de ordenação leva 1 segundo para ordenar $n_1 = 1.000$ itens no seu computador. Quanto tempo ele vai levar para ordenar $n_2 = 10.000$ itens se o algoritmo tem um tempo de execução proporcional a $\log{n}$?
4. Para cada par de funções $f(n)$ e $g(n)$, encontre uma constante $c$ de forma que $f(n) \leq c\times g(n)$ para todo $n \gt 1$
   1. $f(n) = n^2+ n + 1, g(n) = 2n^3$
   2. $f(n) = n \sqrt n + n^2, g(n) = n^2$
5. Verdadeiro ou falso
   1. $2n^2 + 1 = O(n^2)$
   2. $\sqrt{n} = O(\log{n})$
   3. $\log{n} = O(\sqrt{n})$
   4. $n^2(1+\sqrt{n}) = O(n^2\log{n})$
   5. $3n^2+\sqrt{n} = O(n^2)$
   6. $\sqrt{n}\log{n} = O(n)$
   7. $\log{n} = O(n^{−1/2})$
6. Expresse a quantidade de vezes que a palavra `thiago` é impressa no código a seguir como um somatório e simplifique até achar a fórmula

```c
for i=1 to n/2 do
  for j=i to n-i do
    for k=1 to j do
      print "thiago"
```
