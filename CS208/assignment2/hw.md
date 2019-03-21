# Assignment2

## Author

11711918 吴烨昌

## Problem 1

### Description

Suppose you have algorithms with the five running times listed below. (Assume these are the exact running times.) How much slower do each of these algorithms get when you (a) double the input size, or (b) increase the input size by one? 

1. $n^2$ 
2. $n^3$ 
3. $100n^2$ 
4. $nlog(n)$
5. $ 2^n$

### Solution

That double the input size means $n​$ => $2n​$

That increase the input size by one means $n$ => $n + 1$


| Complexity |   $O(...)_{2n}/O(...)_n$   |  $O(...)_{n+1}/O(...)_n$  |
| :--------: | :--: | :--: |
|     $n^2$        | $400\%$ |$1+\frac{2n+1}{n^2}$|
|      $n^3$      | $800\%$ |$1+\frac{3n^2+3n+1}{n^3}$|
|      $100n^2$      | $400\%$ |$1+\frac{2n+1}{n^2}$|
|       $nlog(n)$     | $2log_n2+1$ |$(1+\frac 1n)log_n(n+1)$|
|       $ 2^n$     | $2^n$ |$200\%$|

## Problem 5

### Description

Assume you have functions $f$ and $g$ such that $f(n)$ is $O(g(n))​$. For each of the following statements, decide whether you think it is true or false and give a proof or counterexample. 

1. $log_2 f(n)$ is $O(log_2 g(n))$. 
2. $2^{f(n)}​$ is $O(2^{g(n)})​$.
3. $f(n)^2​$ is $O(g(n)^2)​$.

## Solution

$f(n) = O(g(n))​$ <=> $0 < f(n) \leq cg(n), c > 0​$

1. False

   $log_2 f(n) \leq log_2 c + log_2 g(n)$, if $log_2 c + log_2 g(n) \leq c'log_2 g(n)$, we can say $log_2 f(n)$ is $O(log_2 g(n))$. 

   $log_2 c + log_2 g(n) \leq c'log_2 g(n)​$

   $c' \ge log_{g(n)}c + 1$

   if $g(n)$ is decreasing, there is no constant $c'​$ to hold this inequality.

2. False

   $2^{f(n)} \leq 2^{cg(n)}​$, if $2^{cg(n)} \leq c'2^{g(n)}​$, we can say $2^{f(n)}​$ is $O(2^{g(n)})​$.

   $c' \ge 2^{(c-1)g(n)}$

   There is no constant $c'$ to hold this inequality unless $c = 0$.

   An countexample is $f(n) = 2n​$ and $g(n) = n​$, $2^{f(n)} \ge 2^{g(n)}​$

3. True

   $f(n)^2 \leq c^2 g(n)^2$, if $c^2 g(n)^2 \leq c'g(n)^2$, we can say $f(n)^2$ is $O(g(n)^2)$.

   $c' = c^2$ can hold this inequality.