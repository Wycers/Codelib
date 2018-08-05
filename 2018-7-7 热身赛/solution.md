[toc]
# C
## 题意
自从Lele开发了Rating系统，他的Tetris事业更是如虎添翼，不久他遍把这个游戏推向了全球。 

为了更好的符合那些爱好者的喜好，Lele又想了一个新点子：他将制作一个全球Tetris高手排行榜，定时更新，名堂要比福布斯富豪榜还响。关于如何排名，这个不用说都知道是根据Rating从高到低来排，如果两个人具有相同的Rating，那就按这几个人的RP从高到低来排。 

终于，Lele要开始行动了，对N个人进行排名。为了方便起见，每个人都已经被编号，分别从0到N-1,并且编号越大，RP就越高。 
同时Lele从狗仔队里取得一些（M个）关于Rating的信息。这些信息可能有三种情况，分别是"A > B","A = B","A < B"，分别表示A的Rating高于B,等于B,小于B。 

现在Lele并不是让你来帮他制作这个高手榜，他只是想知道，根据这些信息是否能够确定出这个高手榜，是的话就输出"OK"。否则就请你判断出错的原因，到底是因为信息不完全（输出"UNCERTAIN"），还是因为这些信息中包含冲突（输出"CONFLICT"）。 
注意，如果信息中同时包含冲突且信息不完全，就输出"CONFLICT"。 

## Input
本题目包含多组测试，请处理到文件结束。 
每组测试第一行包含两个整数N,M(0<=N<=10000,0<=M<=20000),分别表示要排名的人数以及得到的关系数。 
接下来有M行，分别表示这些关系 
## Output
对于每组测试，在一行里按题目要求输出

## Sample
### Sample Input
3 3
0 > 1
1 < 2
0 > 2
4 4
1 = 2
1 > 3
2 > 0
0 > 1
3 3
1 > 0
1 > 2
2 < 1
### Sample Output
OK
CONFLICT
UNCERTAIN

## 题解

### 思路

题意就是给出一些数的先后关系：

其中等于的部分，可以通过并查集进行压缩。

其中不等于的部分，可以通过拓扑排序进行检查。

如果出现了环，就说明存在矛盾。如果存在多种拓扑序，则说明无法确定。

# G
## 题意

A lot of battleships of evil are arranged in a line before the battle. Our commander decides to use our secret weapon to eliminate the battleships. Each of the battleships can be marked a value of endurance. For every attack of our secret weapon, it could decrease the endurance of a consecutive part of battleships by make their endurance to the square root of it original value of endurance. During the series of attack of our secret weapon, the commander wants to evaluate the effect of the weapon, so he asks you for help. 
You are asked to answer the queries that the sum of the endurance of a consecutive part of the battleship line. 

Notice that the square root operation should be rounded down to integer.

## Input
The input contains several test cases, terminated by EOF. 
  For each test case, the first line contains a single integer N, denoting there are N battleships of evil in a line. (1 <= N <= 100000) 
  The second line contains N integers Ei, indicating the endurance value of each battleship from the beginning of the line to the end. You can assume that the sum of all endurance value is less than 2 63. 
  The next line contains an integer M, denoting the number of actions and queries. (1 <= M <= 100000)
  For the following M lines, each line contains three integers T, X and Y. The T=0 denoting the action of the secret weapon, which will decrease the endurance value of the battleships between the X-th and Y-th battleship, inclusive. The T=1 denoting the query of the commander which ask for the sum of the endurance value of the battleship between X-th and Y-th, inclusive. 
## Output
For each test case, print the case number at the first line. Then print one line for each query. And remember follow a blank line after each test case.
## Sample
### Sample Input
10
1 2 3 4 5 6 7 8 9 10
5
0 1 10
1 1 10
1 1 5
0 5 8
1 4 8
### Sample Output
Case #1:
19
7
6

## 题解
### 思路

题意就是给出一个序列，每次操作使某个范围内的数变成自身的平方根，并询问范围内数字和。

反正就是一看就是线段树了，这里的主要问题是要观察到对一个数一直根号收敛到1的速度很快，所以记录一下某段区间是否全为1，如果全为1就不用更新了。
