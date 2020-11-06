### Exercise 1

(Simple LR): Consider the following grammar G:

$$
S → aB \\
B → S + B | ϵ
$$

1. Construct the SLR(1) parsing table for G. Please put down the detailed steps, including
the calculation of LR(0) item sets. [20 points]
2. Is the grammar SLR(1)? [10 points]
3. Can the SLR(1) parser accept the input string aaaa+++? If yes, please list the moves
made by the parser; otherwise, state the reason. Before parsing, please resolve conflicts
if any. [10 points]

### Exercise 2

(Canonical LR): Consider the grammar G in Exercise 1:

1. Construct the CLR(1) parsing table for G. Please put down the detailed steps, including the calculation of LR(1) item sets. [20 points]
2. Can the CLR(1) parser accept the input string `aaaa+++`? If yes, please list the moves
made by the parser; otherwise, state the reason. Before parsing, please resolve conflicts
if any. [10 points]


### Exercise 3

(Lookahead LR): Consider the grammar G in Exercise 1:

1. Construct the LALR(1) parsing table for G. Please put down the detailed steps,
including the merging of LR(1) item sets. [20 points]
2. Can the LALR(1) parser accept the input string aaaa+++? If yes, please list the
moves made by the parser; otherwise, state the reason. Before parsing, please resolve
conflicts if any. [10 points]
