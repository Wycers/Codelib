### Exercise 1

(Simple LR): Consider the following grammar G:

$$
S → aB \\
B → S + B | ϵ
$$

1. Construct the SLR(1) parsing table for G. Please put down the detailed steps, including
    the calculation of LR(0) item sets. [20 points]
    
    With：
    $$
    \begin{eqnarray*}
    \tag{0} S' \rightarrow S \\
    \tag{1} S \rightarrow a B  \\
    \tag{2} B \rightarrow S + B \\
    \tag{3} B \rightarrow \epsilon
    \end{eqnarray*}
    $$
    "sn" means "shift by rule n", "rn" means "reduce by rule n" .

| State | ACTION: a | ACTION: + | ACTION: $ | GOTO: S | GOTO: B |
| ----- | --------- | --------- | --------- | ------- | ------- |
| 0     | s2        |           |           | 1       |         |
| 1     |           |           | acc       |         |         |
| 2     | s2        | r3        | r3        | 4       | 3       |
| 3     |           | r1        | r1        |         |         |
| 4     |           | s5        |           |         |         |
| 5     | s2        | r3        | r3        | 4       | 6       |
| 6     |           | r2        | r2        |         |         |

2. Is the grammar SLR(1)? [10 points]

   yes.

3. Can the SLR(1) parser accept the input string aaaa+++? If yes, please list the moves
    made by the parser; otherwise, state the reason. Before parsing, please resolve conflicts
    if any. [10 points]
    
    Yes
    
    | Step | Stack                     | Input           | Action |
    | ---- | ------------------------- | --------------- | ------ |
    | 1    | 0                         | a a a a + + + $ | s2     |
    | 2    | 0 a 2                     | a a a + + + $   | s2     |
    | 3    | 0 a 2 a 2                 | a a + + + $     | s2     |
    | 4    | 0 a 2 a 2 a 2             | a + + + $       | s2     |
    | 5    | 0 a 2 a 2 a 2 a 2         | + + + $         | r3     |
    | 6    | 0 a 2 a 2 a 2 a 2 B       | + + + $         | 3      |
    | 7    | 0 a 2 a 2 a 2 a 2 B 3     | + + + $         | r1     |
    | 8    | 0 a 2 a 2 a 2 S           | + + + $         | 4      |
    | 9    | 0 a 2 a 2 a 2 S 4         | + + + $         | s5     |
    | 10   | 0 a 2 a 2 a 2 S 4 + 5     | + + $           | r3     |
    | 11   | 0 a 2 a 2 a 2 S 4 + 5 B   | + + $           | 6      |
    | 12   | 0 a 2 a 2 a 2 S 4 + 5 B 6 | + + $           | r2     |
    | 13   | 0 a 2 a 2 a 2 B           | + + $           | 3      |
    | 14   | 0 a 2 a 2 a 2 B 3         | + + $           | r1     |
    | 15   | 0 a 2 a 2 S               | + + $           | 4      |
    | 16   | 0 a 2 a 2 S 4             | + + $           | s5     |
    | 17   | 0 a 2 a 2 S 4 + 5         | + $             | r3     |
    | 18   | 0 a 2 a 2 S 4 + 5 B       | + $             | 6      |
    | 19   | 0 a 2 a 2 S 4 + 5 B 6     | + $             | r2     |
    | 20   | 0 a 2 a 2 B               | + $             | 3      |
    | 21   | 0 a 2 a 2 B 3             | + $             | r1     |
    | 22   | 0 a 2 S                   | + $             | 4      |
    | 23   | 0 a 2 S 4                 | + $             | s5     |
    | 24   | 0 a 2 S 4 + 5             | $               | r3     |
    | 25   | 0 a 2 S 4 + 5 B           | $               | 6      |
    | 26   | 0 a 2 S 4 + 5 B 6         | $               | r2     |
    | 27   | 0 a 2 B                   | $               | 3      |
    | 28   | 0 a 2 B 3                 | $               | r1     |
    | 29   | 0 S                       | $               | 1      |
    | 30   | 0 S 1                     | $               | acc    |



### Exercise 2

(Canonical LR): Consider the grammar G in Exercise 1:

1. Construct the CLR(1) parsing table for G. Please put down the detailed steps, including the calculation of LR(1) item sets. [20 points]

With：
$$
\begin{eqnarray*}
    \tag{0} S' \rightarrow S \\
    \tag{1} S \rightarrow a B  \\
    \tag{2} B \rightarrow S + B \\
    \tag{3} B \rightarrow \epsilon
    \end{eqnarray*}
$$
​    "sn" means "shift by rule n", "rn" means "reduce by rule n" .

| State | ACTION:  a | ACTION:  + | ACTION:  $ | GOTO:  S | GOTO:  B |
| ----- | ---------- | ---------- | ---------- | -------- | -------- |
| 0     | s2         |            |            | 1        |          |
| 1     |            |            | accept     |          |          |
| 2     | s5         |            | r3         | 3        | 4        |
| 3     |            | s6         |            |          |          |
| 4     |            |            | r1         |          |          |
| 5     | s5         | r3         |            | 7        | 8        |
| 6     | s5         |            | r3         | 3        | 9        |
| 7     |            | s10        |            |          |          |
| 8     |            | r1         |            |          |          |
| 9     |            |            | r2         |          |          |
| 10    | s5         | r3         |            | 7        | 11       |
| 11    |            | r2         |            |          |          |

2. Can the CLR(1) parser accept the input string `aaaa+++`? If yes, please list the moves
    made by the parser; otherwise, state the reason. Before parsing, please resolve conflicts
    if any. [10 points]
    
    | step | Stack                       | Input           | Action |
    | ---- | --------------------------- | --------------- | ------ |
    | 1    | 0                           | a a a a + + + $ | s2     |
    | 2    | 0 a 2                       | a a a + + + $   | s5     |
    | 3    | 0 a 2 a 5                   | a a + + + $     | s5     |
    | 4    | 0 a 2 a 5 a 5               | a + + + $       | s5     |
    | 5    | 0 a 2 a 5 a 5 a 5           | + + + $         | r3     |
    | 6    | 0 a 2 a 5 a 5 a 5 B         | + + + $         | 8      |
    | 7    | 0 a 2 a 5 a 5 a 5 B 8       | + + + $         | r1     |
    | 8    | 0 a 2 a 5 a 5 S             | + + + $         | 7      |
    | 9    | 0 a 2 a 5 a 5 S 7           | + + + $         | s10    |
    | 10   | 0 a 2 a 5 a 5 S 7 + 10      | + + $           | r3     |
    | 11   | 0 a 2 a 5 a 5 S 7 + 10 B    | + + $           | 11     |
    | 12   | 0 a 2 a 5 a 5 S 7 + 10 B 11 | + + $           | r2     |
    | 13   | 0 a 2 a 5 a 5 B             | + + $           | 8      |
    | 14   | 0 a 2 a 5 a 5 B 8           | + + $           | r1     |
    | 15   | 0 a 2 a 5 S                 | + + $           | 7      |
    | 16   | 0 a 2 a 5 S 7               | + + $           | s10    |
    | 17   | 0 a 2 a 5 S 7 + 10          | + $             | r3     |
    | 18   | 0 a 2 a 5 S 7 + 10 B        | + $             | 11     |
    | 19   | 0 a 2 a 5 S 7 + 10 B 11     | + $             | r2     |
    | 20   | 0 a 2 a 5 B                 | + $             | 8      |
    | 21   | 0 a 2 a 5 B 8               | + $             | r1     |
    | 22   | 0 a 2 S                     | + $             | 3      |
    | 23   | 0 a 2 S 3                   | + $             | s6     |
    | 24   | 0 a 2 S 3 + 6               | $               | r3     |
    | 25   | 0 a 2 S 3 + 6 B             | $               | 9      |
    | 26   | 0 a 2 S 3 + 6 B 9           | $               | r2     |
    | 27   | 0 a 2 B                     | $               | 4      |
    | 28   | 0 a 2 B 4                   | $               | r1     |
    | 29   | 0 S                         | $               | 1      |
    | 30   | 0 S 1                       | $               | acc    |


### Exercise 3

(Lookahead LR): Consider the grammar G in Exercise 1:

1. Construct the LALR(1) parsing table for G. Please put down the detailed steps,
    including the merging of LR(1) item sets. [20 points]

    | State | ACTION: a | ACTION: + | ACTION: $ | GOTO: S | GOTO: B |
    | ----- | --------- | --------- | --------- | ------- | ------- |
    | 0     | s2        |           |           | 1       |         |
    | 1     |           |           | acc       |         |         |
    | 2     | s2        | r3        | r3        | 4       | 3       |
    | 3     |           | r1        | r1        |         |         |
    | 4     |           | s5        |           |         |         |
    | 5     | s2        | r3        | r3        | 4       | 6       |
    | 6     |           | r2        | r2        |         |         |

2. Can the LALR(1) parser accept the input string aaaa+++? If yes, please list the
    moves made by the parser; otherwise, state the reason. Before parsing, please resolve
    conflicts if any. [10 points]
  
   | Step | Stack                     | Input           | Action |
   | ---- | ------------------------- | --------------- | ------ |
   | 1    | 0                         | a a a a + + + $ | s2     |
   | 2    | 0 a 2                     | a a a + + + $   | s2     |
   | 3    | 0 a 2 a 2                 | a a + + + $     | s2     |
   | 4    | 0 a 2 a 2 a 2             | a + + + $       | s2     |
   | 5    | 0 a 2 a 2 a 2 a 2         | + + + $         | r3     |
   | 6    | 0 a 2 a 2 a 2 a 2 B       | + + + $         | 3      |
   | 7    | 0 a 2 a 2 a 2 a 2 B 3     | + + + $         | r1     |
   | 8    | 0 a 2 a 2 a 2 S           | + + + $         | 4      |
   | 9    | 0 a 2 a 2 a 2 S 4         | + + + $         | s5     |
   | 10   | 0 a 2 a 2 a 2 S 4 + 5     | + + $           | r3     |
   | 11   | 0 a 2 a 2 a 2 S 4 + 5 B   | + + $           | 6      |
   | 12   | 0 a 2 a 2 a 2 S 4 + 5 B 6 | + + $           | r2     |
   | 13   | 0 a 2 a 2 a 2 B           | + + $           | 3      |
   | 14   | 0 a 2 a 2 a 2 B 3         | + + $           | r1     |
   | 15   | 0 a 2 a 2 S               | + + $           | 4      |
   | 16   | 0 a 2 a 2 S 4             | + + $           | s5     |
   | 17   | 0 a 2 a 2 S 4 + 5         | + $             | r3     |
   | 18   | 0 a 2 a 2 S 4 + 5 B       | + $             | 6      |
   | 19   | 0 a 2 a 2 S 4 + 5 B 6     | + $             | r2     |
   | 20   | 0 a 2 a 2 B               | + $             | 3      |
   | 21   | 0 a 2 a 2 B 3             | + $             | r1     |
   | 22   | 0 a 2 S                   | + $             | 4      |
   | 23   | 0 a 2 S 4                 | + $             | s5     |
   | 24   | 0 a 2 S 4 + 5             | $               | r3     |
   | 25   | 0 a 2 S 4 + 5 B           | $               | 6      |
   | 26   | 0 a 2 S 4 + 5 B 6         | $               | r2     |
   | 27   | 0 a 2 B                   | $               | 3      |
   | 28   | 0 a 2 B 3                 | $               | r1     |
   | 29   | 0 S                       | $               | 1      |
   | 30   | 0 S 1                     | $               | acc    |

