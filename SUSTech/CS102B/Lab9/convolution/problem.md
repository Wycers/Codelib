# Matrix Convolution

The convolution of *f* and *g* is written *f*∗*g*, using an asterisk or star. It is defined as the integral of the product of the two functions after one is reversed and shifted. As such, it is a particular kind of integral transform:

![{\displaystyle f(t)*g(t)\,\triangleq \ \underbrace {\int _{-\infty }^{\infty }f(\tau )g(t-\tau )\,d\tau } _{(f*g)(t)},}](https://wikimedia.org/api/rest_v1/media/math/render/svg/2c08e95382ff57877dd41672f4dedae7057262c0)

You can refer to [Wikipedia](https://en.wikipedia.org/wiki/Convolution)

## Description

But the things above is little relative with matrix convolution.  :smile:

Given a matrix $A$ with size $N \times N$ and a matrix $B$ with size $M * M$, guarantee that $M \leq N$ and $2 \nmid M$, please calculate the matrix convolution of $A$ and $B$.

The result of convolution $A*B$ is a matrix $C$ with

$$
\begin{equation*}

C_{i,j} = \sum_{p=-k}^k \sum_{q=-k}^k A_{i,j} \times B_{k + p, k + q} 

\end{equation*}, k = \frac{M - 1}{2}​
$$

![1555686880612](D:\Codelib\CS102B\Lab9\convolution\assets\1555686880612.png)

You can check the page from [this article from Matongxue](https://www.matongxue.com/madocs/32.html) for more information(GIF version of above image).

## Input

The first line is two integers, $N​$ and $M​$.

The following $N​$ lines, $N​$ integers per line. The $j​$ integer of $i​$ line is $A_{ij}​$.

The following $M​$ lines, $M​$ integers per line. The $j​$ integer of $i​$ line is $B_{ij}​$. 

## Output

The result matrix of $A*B​$, $*​$ is donated for convolution operation.

## Example

### Example Input

``` plain
5 3
0  0 75 80 80
0 75 80 80 80
0 75 80 80 80
0 70 75 80 80
0  0  0  0  0
-1 -2 -1
 0  0  0
 1  2  1
```

### Example Output

``` plain
0       0       0       0       0
0       155     85      5       0
0       -15     -15     -5      0
0       -230    -315    -320    0
0       0       0       0       0
```

