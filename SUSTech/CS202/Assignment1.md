# Assignment1

- Course: Computer Organization
- Student: 11711918 吴烨昌

## 1.6

### Description

<§1.6> Consider two diff erent implementations of the same instruction set architecture.  Th e instructions can be divided into four classes according to their CPI (class A, B, C, and D). P1 with a clock rate of 2.5 GHz and CPIs of 1, 2, 3, and 3, and P2 with a clock rate of 3 GHz and CPIs of 2, 2, 2, and 2. Given a program with a dynamic instruction count of 1.0E6 instructions divided into classes as follows: 10% class A, 20% class B, 50% class C, and 20% class D, which implementation is faster? 

a. What is the global CPI for each implementation? 

b. Find the clock cycles required in both cases.

### Solution

$$ CPI_{Global} = \dfrac{\sum{CPI_i\times I_i}}{\sum{I_i}} ​$$

for first implementation, $$CPI_{Global1} = \dfrac{1 * 10\% \times \sum{I_i} + 2 * 20\% \times \sum{I_i} + 3 * 50\% \times \sum{I_i} +3 * 20\% \times \sum{I_i} }{\sum{I_i}}$$

$$CPI_{Global1}=0.1+0.4+1.5+0.6=2.6​$$

for second implementation,$$CPI_{Global2} = \dfrac{2 * 10\% \times \sum{I_i} + 2 * 20\% \times \sum{I_i} + 2 * 50\% \times \sum{I_i} +2 * 20\% \times \sum{I_i} }{\sum{I_i}}$$

$$CPI_{Global2}=0.1+0.4+1.5+0.6=2$$




$$Cycles_1=2.6\times 10^6$$

$$Cycles_2=2 \times 10^6$$



$$Period_1=\dfrac{1}{Rate_1}=\dfrac{1}{2.5 \times 10^9}=4\times 10^{-10}s​$$

$$Period_2=\dfrac{1}{Rate_2}=\dfrac{1}{3 \times 10^9}=3.33\times 10^{-10}s​$$

## 1.8

### Description

The Pentium 4 Prescott processor, released in 2004, had a clock rate of 3.6 GHz and voltage of 1.25 V.  Assume that, on average, it consumed 10 W of static power and 90 W of dynamic power. The Core i5 Ivy Bridge, released in 2012, had a clock rate of 3.4 GHz and voltage of 0.9 V.  Assume that, on average, it consumed 30 W of static power and 40 W of dynamic power. 

1. [5] <§1.7> For each processor find the average capacitive loads. 
2. [5] <§1.7> Find the percentage of the total dissipated power comprised by static power and the ratio of static power to dynamic power for each technology. 
3. [15] <§1.7> If the total dissipated power is to be reduced by 10%, how much should the voltage be reduced to maintain the same leakage current?  Note:  power is defined as the product of voltage and current.

### Solution

$$P =  C * V^2 * f​$$，$$C = \dfrac{2P}{V^2f}​$$

for Pentium 4 Prescott, $$C = \dfrac{2P}{V^2 *f}= \dfrac{2 \times 90W}{(1.25V)^2*3.6GHz}=3.2\times 10^{-8}F$$

for Core i5 Ivy Bridge, $$C = \dfrac{2P}{V^2 *f}= \dfrac{2 \times 40W}{(0.9V)^2*3.4GHz}=2.90\times 10^{-8}F​$$



for Pentium 4 Prescott, static/dissipated = $$\dfrac{10W}{100W}=10\%​$$,static/dynamic = $$\dfrac{10W}{90W}=11.11\%​$$

for Core i5 Ivy Bridge, static/dissipated = $$\dfrac{30W}{70W}=43.86\%​$$,static/dynamic = $$\dfrac{30W}{40W}=75\%​$$



for Pentium 4 Prescott, leakage current $I_1 = \dfrac{10W}{1.25V}=8A$,$P=U' \times I_1+C_1U'^2f=0.9*100W$

$$U' = 1.18V​$$, reduced by $$0.07V​$$

for Core i5 Ivy Bridge, leakage current $I_2 = \dfrac{30W}{0.9V}=33.3A$,$P=U' \times I_2+C_2U'^2f=0.9*70W$

$$U' = 0.84V$$, reduced by $$0.06V$$



## 1.15

### Description

[5] <§1.8> When a program is adapted to run on multiple processors in a multiprocessor system, the execution time on each processor is comprised of computing time and the overhead time required for locked critical sections and/or to send data from one processor to another. Assume a program requires t = 100 s of execution time on one processor.  When run p processors, each processor requires t/p s, as well as an additional 4 s of overhead, irrespective of the number of processors.  Compute the per-processor execution time for 2, 4, 8, 16, 32, 64, and 128 processors.  For each case, list the corresponding speedup relative to a single processor and the ratio between actual speedup versus ideal speedup (speedup if there was no overhead).

### Solution

corresponding speedup relative to a single processor$S_0= \dfrac{ t_0}{\dfrac{t_0}{p}+4}=\dfrac{t_0p}{t_0+4p}​$

 ratio between actual speedup versus ideal speedup $$R_0 = \dfrac{t_0p}{t_0+4p}/\dfrac{t_0}{t_0/p}=\dfrac{t_0}{t_0+4p}​$$

when $t_0 = 100s​$

|  $p$  |  2   |  4   |  8   |  16  |  32   |  64   |  128  |
| :---: | :--: | :--: | :--: | :--: | :---: | :---: | :---: |
| $S_0$ | 1.85 | 4.45 | 6.06 | 9.76 | 14.04 | 17.98 | 20.91 |
| $R_0$ | 0.93 | 0.86 | 0.76 | 0.61 | 0.44  | 0.28  | 0.16  |

