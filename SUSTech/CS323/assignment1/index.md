### Exercise 1

When a C compiler compiles the following statement, how many tokens will it generate? [5 points]

```c
int a3 = a * 3;
```

Answer:

7 tokens.

### Exercise 2

In a string of length $n$ ($n > 0$), how many of the following are there?

1. Prefixes [5 points]
   $ n + 1 $
2. Proper prefixes [5 points]
   $n  - 1$
3. Prefixes of length m (0 < m ≤ n) [5 points]
   $1$
4. Suffixes of length m (0 < m ≤ n) [5 points]
   $1$
5. Proper prefixes of length m (0 < m ≤ n) [10 points]
   $$f(x)= \begin{cases} 0& m = n\\ 1& m \neq n \end{cases}$$
6. Substrings [10 points]
   $$\frac{n(n-1)}{2}+1$$
7. Subsequences [10 points]
   $2^{n}$

### Exercise 3

Describe the languages denoted by the following regular expressions:

1. $\text{((}\epsilon\text{|a)*b*)*}$ [5 points]

   All strings of a's and b's.

2. $\text{(a|b)*a(a|b)(a|b) }$[5 points]

   All strings of a's and b's ending with one of 'aaa', 'aab', 'aba', 'abb'.

3. $\text{a*ba*ba*ba*}$ [5 points]

   All strings of a's and b's having exactly 3 'b'.

### Exercise 4

Write regular definitions or regular expressions for the following languages

1. All strings representing valid telephone numbers in Shenzhen. A valid telephone number contains the country code ($86$), a hyphen, the area code 0755, another hyphen, and eight digits where the first one cannot be zero (e.g., $\text{86-0755-88015159}$). [10 points]

   `^86-0755-[1-9][0-9]{7}$`

2. All strings of $a$’s and $b$’s that start with $a$ and end with $b$. [10 points]

   `^a(a*b*)*b$`

3. All strings of lowercase letters that contain the five vowels in order. [10 points]

   `^[b-df-hj-np-tv-z]*a[a-df-hj-np-tv-z]*e[b-hj-np-tv-z]*i[b-df-np-tv-z]*o[b-df-hj-tv-z]*u[b-df-hj-np-z]*$`

### Bonus

### Exercise 1

Suppose we have a alphabet Σ = {a, b, c}, write regular definitions to describe all strings over Σ without repeated letters. [Hint: You may draw an NFA for the language and convert the NFA to regular definitions.]

#### If "without repeated letters" means no letters occurs before

`a|b|c|(ab)|(ac)|(ba)|(bc)|(ca)|(cb)|(abc)|(acb)|(bac)|(bca)|(cab)|(cba)`

#### If "without repeated letters" means no adjacent letters are the same

DFA (or a special NFA)

<svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="301.5" rx="30" ry="30"/>
	<text x="326.5" y="307.5" font-family="Times New Roman" font-size="20">S</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="301.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="122.5" rx="30" ry="30"/>
	<text x="326.5" y="128.5" font-family="Times New Roman" font-size="20">A</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="122.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="30" ry="30"/>
	<text x="490.5" y="403.5" font-family="Times New Roman" font-size="20">B</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="172.5" cy="397.5" rx="30" ry="30"/>
	<text x="167.5" y="403.5" font-family="Times New Roman" font-size="20">C</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="172.5" cy="397.5" rx="24" ry="24"/>
	<polygon stroke="black" stroke-width="1" points="331.5,271.5 331.5,152.5"/>
	<polygon fill="black" stroke-width="1" points="331.5,152.5 326.5,160.5 336.5,160.5"/>
	<text x="336.5" y="218.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon stroke="black" stroke-width="1" points="305.818,317.006 198.182,381.994"/>
	<polygon fill="black" stroke-width="1" points="198.182,381.994 207.615,382.139 202.446,373.579"/>
	<text x="237.5" y="340.5" font-family="Times New Roman" font-size="20">c</text>
	<polygon stroke="black" stroke-width="1" points="357.39,316.655 469.61,382.345"/>
	<polygon fill="black" stroke-width="1" points="469.61,382.345 465.231,373.988 460.18,382.618"/>
	<text x="398.5" y="370.5" font-family="Times New Roman" font-size="20">b</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 183.538,369.606 A 980.316,980.316 0 0 1 312.832,145.983"/>
	<polygon fill="black" stroke-width="1" points="312.832,145.983 303.989,149.269 311.911,155.372"/>
	<text x="224.5" y="247.5" font-family="Times New Roman" font-size="20">a</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 320.825,150.535 A 901.897,901.897 0 0 1 191.47,374.261"/>
	<polygon fill="black" stroke-width="1" points="191.47,374.261 200.351,371.078 192.5,364.884"/>
	<text x="270.5" y="285.5" font-family="Times New Roman" font-size="20">c</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 465.767,401.483 A 1104.471,1104.471 0 0 1 202.233,401.483"/>
	<polygon fill="black" stroke-width="1" points="202.233,401.483 209.58,407.402 210.773,397.473"/>
	<text x="328.5" y="430.5" font-family="Times New Roman" font-size="20">c</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 202.427,395.409 A 2102.196,2102.196 0 0 1 465.573,395.409"/>
	<polygon fill="black" stroke-width="1" points="465.573,395.409 457.902,389.918 457.276,399.898"/>
	<text x="329.5" y="382.5" font-family="Times New Roman" font-size="20">b</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 476.694,374.128 A 1042.202,1042.202 0 0 1 343.124,150.155"/>
	<polygon fill="black" stroke-width="1" points="343.124,150.155 341.749,159.488 350.911,155.481"/>
	<text x="386.5" y="284.5" font-family="Times New Roman" font-size="20">a</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 349.724,146.329 A 1263.672,1263.672 0 0 1 483.197,370.14"/>
	<polygon fill="black" stroke-width="1" points="483.197,370.14 484.365,360.778 475.294,364.987"/>
	<text x="428.5" y="248.5" font-family="Times New Roman" font-size="20">b</text>
</svg>
$A = \epsilon+a+Ba+Ca$

$B = \epsilon+Ab+b+Cb$

$C = \epsilon+Ac+Bc+c$

...

~~Sorry, I'm out.~~

According to `nfa_to_reg.pdf`：

1. original：

<svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="301.5" rx="30" ry="30"/>
	<text x="326.5" y="307.5" font-family="Times New Roman" font-size="20">S</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="301.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="122.5" rx="30" ry="30"/>
	<text x="326.5" y="128.5" font-family="Times New Roman" font-size="20">A</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="122.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="30" ry="30"/>
	<text x="490.5" y="403.5" font-family="Times New Roman" font-size="20">B</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="24" ry="24"/>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="172.5" cy="397.5" rx="30" ry="30"/>
	<text x="167.5" y="403.5" font-family="Times New Roman" font-size="20">C</text>
	<ellipse stroke="black" stroke-width="1" fill="none" cx="172.5" cy="397.5" rx="24" ry="24"/>
	<polygon stroke="black" stroke-width="1" points="331.5,271.5 331.5,152.5"/>
	<polygon fill="black" stroke-width="1" points="331.5,152.5 326.5,160.5 336.5,160.5"/>
	<text x="336.5" y="218.5" font-family="Times New Roman" font-size="20">a</text>
	<polygon stroke="black" stroke-width="1" points="305.818,317.006 198.182,381.994"/>
	<polygon fill="black" stroke-width="1" points="198.182,381.994 207.615,382.139 202.446,373.579"/>
	<text x="237.5" y="340.5" font-family="Times New Roman" font-size="20">c</text>
	<polygon stroke="black" stroke-width="1" points="357.39,316.655 469.61,382.345"/>
	<polygon fill="black" stroke-width="1" points="469.61,382.345 465.231,373.988 460.18,382.618"/>
	<text x="398.5" y="370.5" font-family="Times New Roman" font-size="20">b</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 183.538,369.606 A 980.316,980.316 0 0 1 312.832,145.983"/>
	<polygon fill="black" stroke-width="1" points="312.832,145.983 303.989,149.269 311.911,155.372"/>
	<text x="224.5" y="247.5" font-family="Times New Roman" font-size="20">a</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 320.825,150.535 A 901.897,901.897 0 0 1 191.47,374.261"/>
	<polygon fill="black" stroke-width="1" points="191.47,374.261 200.351,371.078 192.5,364.884"/>
	<text x="270.5" y="285.5" font-family="Times New Roman" font-size="20">c</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 465.767,401.483 A 1104.471,1104.471 0 0 1 202.233,401.483"/>
	<polygon fill="black" stroke-width="1" points="202.233,401.483 209.58,407.402 210.773,397.473"/>
	<text x="328.5" y="430.5" font-family="Times New Roman" font-size="20">c</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 202.427,395.409 A 2102.196,2102.196 0 0 1 465.573,395.409"/>
	<polygon fill="black" stroke-width="1" points="465.573,395.409 457.902,389.918 457.276,399.898"/>
	<text x="329.5" y="382.5" font-family="Times New Roman" font-size="20">b</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 476.694,374.128 A 1042.202,1042.202 0 0 1 343.124,150.155"/>
	<polygon fill="black" stroke-width="1" points="343.124,150.155 341.749,159.488 350.911,155.481"/>
	<text x="386.5" y="284.5" font-family="Times New Roman" font-size="20">a</text>
	<path stroke="black" stroke-width="1" fill="none" d="M 349.724,146.329 A 1263.672,1263.672 0 0 1 483.197,370.14"/>
	<polygon fill="black" stroke-width="1" points="483.197,370.14 484.365,360.778 475.294,364.987"/>
	<text x="428.5" y="248.5" font-family="Times New Roman" font-size="20">b</text>
</svg>

2. normalizing：

   <svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="303.5" rx="30" ry="30"/>
   	<text x="326.5" y="309.5" font-family="Times New Roman" font-size="20">S</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="127.5" rx="30" ry="30"/>
   	<text x="326.5" y="133.5" font-family="Times New Roman" font-size="20">A</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="30" ry="30"/>
   	<text x="490.5" y="403.5" font-family="Times New Roman" font-size="20">B</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="172.5" cy="397.5" rx="30" ry="30"/>
   	<text x="167.5" y="403.5" font-family="Times New Roman" font-size="20">C</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="79.5" cy="209.5" rx="30" ry="30"/>
   	<text x="59.5" y="215.5" font-family="Times New Roman" font-size="20">init</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="30" ry="30"/>
   	<text x="622.5" y="215.5" font-family="Times New Roman" font-size="20">end</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="331.5,273.5 331.5,157.5"/>
   	<polygon fill="black" stroke-width="1" points="331.5,157.5 326.5,165.5 336.5,165.5"/>
   	<text x="336.5" y="221.5" font-family="Times New Roman" font-size="20">a</text>
   	<polygon stroke="black" stroke-width="1" points="305.675,318.767 198.325,382.233"/>
   	<polygon fill="black" stroke-width="1" points="198.325,382.233 207.756,382.465 202.667,373.857"/>
   	<text x="237.5" y="341.5" font-family="Times New Roman" font-size="20">c</text>
   	<polygon stroke="black" stroke-width="1" points="357.528,318.418 469.472,382.582"/>
   	<polygon fill="black" stroke-width="1" points="469.472,382.582 465.018,374.265 460.045,382.941"/>
   	<text x="398.5" y="371.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 183.71,369.674 A 954.017,954.017 0 0 1 312.603,150.799"/>
   	<polygon fill="black" stroke-width="1" points="312.603,150.799 303.73,154.002 311.594,160.179"/>
   	<text x="224.5" y="249.5" font-family="Times New Roman" font-size="20">a</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 320.656,155.47 A 877.732,877.732 0 0 1 191.701,374.451"/>
   	<polygon fill="black" stroke-width="1" points="191.701,374.451 200.611,371.352 192.82,365.084"/>
   	<text x="270.5" y="288.5" font-family="Times New Roman" font-size="20">c</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 465.767,401.483 A 1104.471,1104.471 0 0 1 202.233,401.483"/>
   	<polygon fill="black" stroke-width="1" points="202.233,401.483 209.58,407.402 210.773,397.473"/>
   	<text x="328.5" y="430.5" font-family="Times New Roman" font-size="20">c</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 202.427,395.409 A 2102.196,2102.196 0 0 1 465.573,395.409"/>
   	<polygon fill="black" stroke-width="1" points="465.573,395.409 457.902,389.918 457.276,399.898"/>
   	<text x="329.5" y="382.5" font-family="Times New Roman" font-size="20">b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 476.465,374.313 A 1014.668,1014.668 0 0 1 343.302,155.08"/>
   	<polygon fill="black" stroke-width="1" points="343.302,155.08 341.99,164.422 351.124,160.353"/>
   	<text x="386.5" y="287.5" font-family="Times New Roman" font-size="20">a</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 349.95,151.155 A 1230.221,1230.221 0 0 1 483.013,370.223"/>
   	<polygon fill="black" stroke-width="1" points="483.013,370.223 484.116,360.854 475.075,365.126"/>
   	<text x="428.5" y="250.5" font-family="Times New Roman" font-size="20">b</text>
   	<polygon stroke="black" stroke-width="1" points="0.5,209.5 49.5,209.5"/>
   	<polygon fill="black" stroke-width="1" points="49.5,209.5 41.5,204.5 41.5,214.5"/>
   	<polygon stroke="black" stroke-width="1" points="107.608,219.985 303.392,293.015"/>
   	<polygon fill="black" stroke-width="1" points="303.392,293.015 297.644,285.535 294.149,294.904"/>
   	<text x="181.5" y="277.5" font-family="Times New Roman" font-size="20">&#949;</text>
   	<polygon stroke="black" stroke-width="1" points="360.478,135.265 608.522,201.735"/>
   	<polygon fill="black" stroke-width="1" points="608.522,201.735 602.089,194.834 599.501,204.494"/>
   	<text x="462.5" y="190.5" font-family="Times New Roman" font-size="20">&#949;</text>
   	<polygon stroke="black" stroke-width="1" points="360.177,294.691 608.823,218.309"/>
   	<polygon fill="black" stroke-width="1" points="608.823,218.309 599.707,215.879 602.644,225.438"/>
   	<text x="487.5" y="278.5" font-family="Times New Roman" font-size="20">&#949;</text>
   	<polygon stroke="black" stroke-width="1" points="200.313,386.255 609.687,220.745"/>
   	<polygon fill="black" stroke-width="1" points="609.687,220.745 600.396,219.108 604.145,228.379"/>
   	<text x="409.5" y="324.5" font-family="Times New Roman" font-size="20">&#949;</text>
   	<polygon stroke="black" stroke-width="1" points="513.581,373.561 619.419,233.439"/>
   	<polygon fill="black" stroke-width="1" points="619.419,233.439 610.607,236.809 618.587,242.836"/>
   	<text x="572.5" y="323.5" font-family="Times New Roman" font-size="20">&#949;</text>
   </svg>

3. remove state `S`

<svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
    <ellipse stroke="black" stroke-width="1" fill="none" cx="331.5" cy="127.5" rx="30" ry="30"/>
    <text x="326.5" y="133.5" font-family="Times New Roman" font-size="20">A</text>
    <ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="30" ry="30"/>
    <text x="490.5" y="403.5" font-family="Times New Roman" font-size="20">B</text>
    <ellipse stroke="black" stroke-width="1" fill="none" cx="172.5" cy="397.5" rx="30" ry="30"/>
    <text x="167.5" y="403.5" font-family="Times New Roman" font-size="20">C</text>
    <ellipse stroke="black" stroke-width="1" fill="none" cx="74.5" cy="209.5" rx="30" ry="30"/>
    <text x="54.5" y="215.5" font-family="Times New Roman" font-size="20">init</text>
    <ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="30" ry="30"/>
    <text x="622.5" y="215.5" font-family="Times New Roman" font-size="20">end</text>
    <ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="24" ry="24"/>
    <path stroke="black" stroke-width="1" fill="none" d="M 183.71,369.674 A 954.017,954.017 0 0 1 312.603,150.799"/>
    <polygon fill="black" stroke-width="1" points="312.603,150.799 303.73,154.002 311.594,160.179"/>
    <text x="224.5" y="249.5" font-family="Times New Roman" font-size="20">a</text>
    <path stroke="black" stroke-width="1" fill="none" d="M 320.656,155.47 A 877.732,877.732 0 0 1 191.701,374.451"/>
    <polygon fill="black" stroke-width="1" points="191.701,374.451 200.611,371.352 192.82,365.084"/>
    <text x="270.5" y="288.5" font-family="Times New Roman" font-size="20">c</text>
    <path stroke="black" stroke-width="1" fill="none" d="M 465.767,401.483 A 1104.471,1104.471 0 0 1 202.233,401.483"/>
    <polygon fill="black" stroke-width="1" points="202.233,401.483 209.58,407.402 210.773,397.473"/>
    <text x="328.5" y="430.5" font-family="Times New Roman" font-size="20">c</text>
    <path stroke="black" stroke-width="1" fill="none" d="M 202.427,395.409 A 2102.196,2102.196 0 0 1 465.573,395.409"/>
    <polygon fill="black" stroke-width="1" points="465.573,395.409 457.902,389.918 457.276,399.898"/>
    <text x="329.5" y="382.5" font-family="Times New Roman" font-size="20">b</text>
    <path stroke="black" stroke-width="1" fill="none" d="M 476.465,374.313 A 1014.668,1014.668 0 0 1 343.302,155.08"/>
    <polygon fill="black" stroke-width="1" points="343.302,155.08 341.99,164.422 351.124,160.353"/>
    <text x="386.5" y="287.5" font-family="Times New Roman" font-size="20">a</text>
    <path stroke="black" stroke-width="1" fill="none" d="M 349.95,151.155 A 1230.221,1230.221 0 0 1 483.013,370.223"/>
    <polygon fill="black" stroke-width="1" points="483.013,370.223 484.116,360.854 475.075,365.126"/>
    <text x="428.5" y="250.5" font-family="Times New Roman" font-size="20">b</text>
    <polygon stroke="black" stroke-width="1" points="-4.5,209.5 44.5,209.5"/>
    <polygon fill="black" stroke-width="1" points="44.5,209.5 36.5,204.5 36.5,214.5"/>
    <polygon stroke="black" stroke-width="1" points="360.478,135.265 608.522,201.735"/>
    <polygon fill="black" stroke-width="1" points="608.522,201.735 602.089,194.834 599.501,204.494"/>
    <text x="462.5" y="190.5" font-family="Times New Roman" font-size="20">&#949;</text>
    <polygon stroke="black" stroke-width="1" points="200.313,386.255 609.687,220.745"/>
    <polygon fill="black" stroke-width="1" points="609.687,220.745 600.396,219.108 604.145,228.379"/>
    <text x="409.5" y="324.5" font-family="Times New Roman" font-size="20">&#949;</text>
    <polygon stroke="black" stroke-width="1" points="513.581,373.561 619.419,233.439"/>
    <polygon fill="black" stroke-width="1" points="619.419,233.439 610.607,236.809 618.587,242.836"/>
    <text x="572.5" y="323.5" font-family="Times New Roman" font-size="20">&#949;</text>
    <polygon stroke="black" stroke-width="1" points="103.08,200.381 302.92,136.619"/>
    <polygon fill="black" stroke-width="1" points="302.92,136.619 293.778,134.287 296.818,143.814"/>
    <text x="206.5" y="189.5" font-family="Times New Roman" font-size="20">a</text>
    <polygon stroke="black" stroke-width="1" points="88.367,236.103 158.633,370.897"/>
    <polygon fill="black" stroke-width="1" points="158.633,370.897 159.369,361.492 150.501,366.115"/>
    <text x="106.5" y="320.5" font-family="Times New Roman" font-size="20">c</text>
    <polygon stroke="black" stroke-width="1" points="101.893,221.732 468.107,385.268"/>
    <polygon fill="black" stroke-width="1" points="468.107,385.268 462.841,377.44 458.764,386.571"/>
    <text x="270.5" y="324.5" font-family="Times New Roman" font-size="20">b</text>
    <polygon stroke="black" stroke-width="1" points="104.5,209.5 607.5,209.5"/>
    <polygon fill="black" stroke-width="1" points="607.5,209.5 599.5,204.5 599.5,214.5"/>
    <text x="346.5" y="230.5" font-family="Times New Roman" font-size="20">&#949;</text>
</svg>

4. remove state `A`:

   ```mermaid
   stateDiagram-v2
   init --> q_A : a
   q_C --> q_A : a
   q_B --> q_A : a
   q_A --> r_C : c
   q_A --> r_B : b
   q_A --> end :ε
   ```

   So:

   ```mermaid
   stateDiagram-v2
   init --> r_C : ac
   init --> r_B : ab
   init --> end : a
   q_C --> r_C : ac
   q_C --> r_B : ab
   q_C --> end : a
   q_B --> r_C : ac
   q_B --> r_B : ab
   q_B --> end : a
   ```

    <svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
        <ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="30" ry="30"/>
        <text x="490.5" y="403.5" font-family="Times New Roman" font-size="20">B</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="147.5" cy="397.5" rx="30" ry="30"/>
        <text x="142.5" y="403.5" font-family="Times New Roman" font-size="20">C</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="77.5" cy="209.5" rx="30" ry="30"/>
        <text x="57.5" y="215.5" font-family="Times New Roman" font-size="20">init</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="30" ry="30"/>
        <text x="622.5" y="215.5" font-family="Times New Roman" font-size="20">end</text>
        <ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="24" ry="24"/>
        <path stroke="black" stroke-width="1" fill="none" d="M 468.669,410.901 A 359.711,359.711 0 0 1 174.331,410.901"/>
        <polygon fill="black" stroke-width="1" points="174.331,410.901 179.585,418.736 183.676,409.611"/>
        <text x="316.5" y="463.5" font-family="Times New Roman" font-size="20">c</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 177.437,395.554 A 2451.184,2451.184 0 0 1 465.563,395.554"/>
        <polygon fill="black" stroke-width="1" points="465.563,395.554 457.871,390.092 457.283,400.075"/>
        <text x="316.5" y="382.5" font-family="Times New Roman" font-size="20">b</text>
        <polygon stroke="black" stroke-width="1" points="-1.5,209.5 47.5,209.5"/>
        <polygon fill="black" stroke-width="1" points="47.5,209.5 39.5,204.5 39.5,214.5"/>
        <path stroke="black" stroke-width="1" fill="none" d="M 174.579,384.588 A 3152.809,3152.809 0 0 1 608.734,218.015"/>
        <polygon fill="black" stroke-width="1" points="608.734,218.015 599.632,215.534 602.516,225.109"/>
        <text x="364.5" y="283.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 508.994,370.71 A 574.888,574.888 0 0 1 615.422,229.806"/>
        <polygon fill="black" stroke-width="1" points="615.422,229.806 606.197,231.783 613.157,238.964"/>
        <text x="531.5" y="288.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 94.374,234.294 A 359.384,359.384 0 0 1 144.049,367.708"/>
        <polygon fill="black" stroke-width="1" points="144.049,367.708 147.736,359.024 137.859,360.588"/>
        <text x="133.5" y="296.5" font-family="Times New Roman" font-size="20">c</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 106.335,217.777 A 1502.717,1502.717 0 0 1 470.175,381.418"/>
        <polygon fill="black" stroke-width="1" points="470.175,381.418 466.017,372.95 460.741,381.445"/>
        <text x="298.5" y="278.5" font-family="Times New Roman" font-size="20">b</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 107.443,207.649 A 4295.968,4295.968 0 0 1 607.557,207.649"/>
        <polygon fill="black" stroke-width="1" points="607.557,207.649 599.862,202.192 599.28,212.175"/>
        <text x="347.5" y="191.5" font-family="Times New Roman" font-size="20">&#949;</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 131.733,371.985 A 437.419,437.419 0 0 1 82.26,239.114"/>
        <polygon fill="black" stroke-width="1" points="131.733,371.985 132.104,362.558 123.422,367.52"/>
        <text x="74.5" y="321.5" font-family="Times New Roman" font-size="20">ac</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 467.501,386.727 A 3870.945,3870.945 0 0 1 104.137,223.301"/>
        <polygon fill="black" stroke-width="1" points="467.501,386.727 461.859,379.166 458.232,388.485"/>
        <text x="259.5" y="330.5" font-family="Times New Roman" font-size="20">ab</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 607.535,210.94 A 5521.033,5521.033 0 0 1 107.465,210.94"/>
        <polygon fill="black" stroke-width="1" points="607.535,210.94 599.316,206.307 599.769,216.297"/>
        <text x="352.5" y="237.5" font-family="Times New Roman" font-size="20">a</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 120.703,410.725 A 22.5,22.5 0 1 1 120.703,384.275"/>
        <text x="55.5" y="403.5" font-family="Times New Roman" font-size="20">ac</text>
        <polygon fill="black" stroke-width="1" points="120.703,384.275 117.17,375.527 111.292,383.618"/>
        <path stroke="black" stroke-width="1" fill="none" d="M 465.707,401.013 A 1358.921,1358.921 0 0 1 177.293,401.013"/>
        <polygon fill="black" stroke-width="1" points="465.707,401.013 457.222,396.89 458.283,406.833"/>
        <text x="311.5" y="429.5" font-family="Times New Roman" font-size="20">ab</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 610.528,222.634 A 2854.53,2854.53 0 0 1 176.335,389.222"/>
        <polygon fill="black" stroke-width="1" points="610.528,222.634 601.152,221.592 605.483,230.606"/>
        <text x="401.5" y="335.5" font-family="Times New Roman" font-size="20">a</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 525.376,396.848 A 22.5,22.5 0 1 1 514.19,420.817"/>
        <text x="563.5" y="442.5" font-family="Times New Roman" font-size="20">ab</text>
        <polygon fill="black" stroke-width="1" points="514.19,420.817 513.693,430.237 522.441,425.392"/>
        <path stroke="black" stroke-width="1" fill="none" d="M 473.764,418.148 A 237.338,237.338 0 0 1 169.236,418.148"/>
        <polygon fill="black" stroke-width="1" points="169.236,418.148 172.165,427.116 178.581,419.445"/>
        <text x="311.5" y="494.5" font-family="Times New Roman" font-size="20">ac</text>
        <path stroke="black" stroke-width="1" fill="none" d="M 623.78,236.175 A 602.695,602.695 0 0 1 517.406,377.008"/>
        <polygon fill="black" stroke-width="1" points="623.78,236.175 615.557,240.799 624.333,245.593"/>
        <text x="581.5" y="330.5" font-family="Times New Roman" font-size="20">a</text>
    </svg>

5. Simplify：

   <svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="30" ry="30"/>
   	<text x="490.5" y="403.5" font-family="Times New Roman" font-size="20">B</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="147.5" cy="397.5" rx="30" ry="30"/>
   	<text x="142.5" y="403.5" font-family="Times New Roman" font-size="20">C</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="77.5" cy="209.5" rx="30" ry="30"/>
   	<text x="57.5" y="215.5" font-family="Times New Roman" font-size="20">init</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="30" ry="30"/>
   	<text x="622.5" y="215.5" font-family="Times New Roman" font-size="20">end</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="177.5,397.5 465.5,397.5"/>
   	<polygon fill="black" stroke-width="1" points="465.5,397.5 457.5,392.5 457.5,402.5"/>
   	<text x="306.5" y="388.5" font-family="Times New Roman" font-size="20">a?b</text>
   	<polygon stroke="black" stroke-width="1" points="-1.5,209.5 47.5,209.5"/>
   	<polygon fill="black" stroke-width="1" points="47.5,209.5 39.5,204.5 39.5,214.5"/>
   	<polygon stroke="black" stroke-width="1" points="87.968,237.614 137.032,369.386"/>
   	<polygon fill="black" stroke-width="1" points="137.032,369.386 138.926,360.144 129.555,363.633"/>
   	<text x="74.5" y="317.5" font-family="Times New Roman" font-size="20">a?c</text>
   	<polygon stroke="black" stroke-width="1" points="104.86,221.805 468.14,385.195"/>
   	<polygon fill="black" stroke-width="1" points="468.14,385.195 462.895,377.353 458.793,386.473"/>
   	<text x="251.5" y="324.5" font-family="Times New Roman" font-size="20">a?b</text>
   	<polygon stroke="black" stroke-width="1" points="107.5,209.5 607.5,209.5"/>
   	<polygon fill="black" stroke-width="1" points="607.5,209.5 599.5,204.5 599.5,214.5"/>
   	<text x="347.5" y="230.5" font-family="Times New Roman" font-size="20">a?</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 120.703,410.725 A 22.5,22.5 0 1 1 120.703,384.275"/>
   	<text x="55.5" y="403.5" font-family="Times New Roman" font-size="20">ac</text>
   	<polygon fill="black" stroke-width="1" points="120.703,384.275 117.17,375.527 111.292,383.618"/>
   	<polygon stroke="black" stroke-width="1" points="175.509,386.754 609.491,220.246"/>
   	<polygon fill="black" stroke-width="1" points="609.491,220.246 600.231,218.444 603.813,227.78"/>
   	<text x="396.5" y="324.5" font-family="Times New Roman" font-size="20">a?</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 525.376,396.848 A 22.5,22.5 0 1 1 514.19,420.817"/>
   	<text x="563.5" y="442.5" font-family="Times New Roman" font-size="20">ab</text>
   	<polygon fill="black" stroke-width="1" points="514.19,420.817 513.693,430.237 522.441,425.392"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 466.109,403.505 A 795.962,795.962 0 0 1 176.891,403.505"/>
   	<polygon fill="black" stroke-width="1" points="176.891,403.505 183.85,409.875 185.666,400.042"/>
   	<text x="306.5" y="437.5" font-family="Times New Roman" font-size="20">a?c</text>
   	<polygon stroke="black" stroke-width="1" points="513.581,373.561 619.419,233.439"/>
   	<polygon fill="black" stroke-width="1" points="619.419,233.439 610.607,236.809 618.587,242.836"/>
   	<text x="572.5" y="323.5" font-family="Times New Roman" font-size="20">a?</text>
   </svg>

6. remove state `C`:

   <svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="495.5" cy="397.5" rx="30" ry="30"/>
   	<text x="490.5" y="403.5" font-family="Times New Roman" font-size="20">B</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="80.5" cy="209.5" rx="30" ry="30"/>
   	<text x="60.5" y="215.5" font-family="Times New Roman" font-size="20">init</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="30" ry="30"/>
   	<text x="622.5" y="215.5" font-family="Times New Roman" font-size="20">end</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="1.5,209.5 50.5,209.5"/>
   	<polygon fill="black" stroke-width="1" points="50.5,209.5 42.5,204.5 42.5,214.5"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 109.564,216.932 A 1223.474,1223.474 0 0 1 470.747,380.552"/>
   	<polygon fill="black" stroke-width="1" points="470.747,380.552 466.865,371.953 461.317,380.273"/>
   	<text x="301.5" y="274.5" font-family="Times New Roman" font-size="20">a?b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 110.281,205.883 A 2186.427,2186.427 0 0 1 607.719,205.883"/>
   	<polygon fill="black" stroke-width="1" points="607.719,205.883 600.34,200.005 599.202,209.94"/>
   	<text x="349.5" y="182.5" font-family="Times New Roman" font-size="20">a?</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 502.665,426.511 A 22.5,22.5 0 1 1 476.831,420.834"/>
   	<text x="461.5" y="485.5" font-family="Times New Roman" font-size="20">ab</text>
   	<polygon fill="black" stroke-width="1" points="476.831,420.834 467.529,422.407 474.169,429.884"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 506.24,369.497 A 373.569,373.569 0 0 1 613.502,227.489"/>
   	<polygon fill="black" stroke-width="1" points="613.502,227.489 604.141,228.663 610.455,236.417"/>
   	<text x="525.5" y="284.5" font-family="Times New Roman" font-size="20">a?</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 607.605,212.006 A 3155.564,3155.564 0 0 1 110.395,212.006"/>
   	<polygon fill="black" stroke-width="1" points="607.605,212.006 599.236,207.651 600.024,217.62"/>
   	<text x="309.5" y="242.5" font-family="Times New Roman" font-size="20">a?c(ac)*a?</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 466.493,389.849 A 1278.045,1278.045 0 0 1 105.381,226.261"/>
   	<polygon fill="black" stroke-width="1" points="466.493,389.849 460.114,382.898 457.45,392.537"/>
   	<text x="165.5" y="343.5" font-family="Times New Roman" font-size="20">a?c(ac)*a?b</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 627.031,237.605 A 361.634,361.634 0 0 1 519.67,379.744"/>
   	<polygon fill="black" stroke-width="1" points="627.031,237.605 619.321,243.041 628.539,246.918"/>
   	<text x="587.5" y="335.5" font-family="Times New Roman" font-size="20">a?c(ac)*a?</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 523.962,388.396 A 22.5,22.5 0 1 1 520.039,414.554"/>
   	<text x="569.5" y="415.5" font-family="Times New Roman" font-size="20">a?c(ac)*a?b</text>
   	<polygon fill="black" stroke-width="1" points="520.039,414.554 522.235,423.729 529.248,416.6"/>
   </svg>

7. simplify:

   <svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="338.5" cy="364.5" rx="30" ry="30"/>
   	<text x="333.5" y="370.5" font-family="Times New Roman" font-size="20">B</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="80.5" cy="209.5" rx="30" ry="30"/>
   	<text x="60.5" y="215.5" font-family="Times New Roman" font-size="20">init</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="30" ry="30"/>
   	<text x="622.5" y="215.5" font-family="Times New Roman" font-size="20">end</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="1.5,209.5 50.5,209.5"/>
   	<polygon fill="black" stroke-width="1" points="50.5,209.5 42.5,204.5 42.5,214.5"/>
   	<polygon stroke="black" stroke-width="1" points="106.216,224.95 312.784,349.05"/>
   	<polygon fill="black" stroke-width="1" points="312.784,349.05 308.501,340.645 303.351,349.217"/>
   	<text x="214.5" y="277.5" font-family="Times New Roman" font-size="20">(a?c(ac)*)?a?b</text>
   	<polygon stroke="black" stroke-width="1" points="110.5,209.5 607.5,209.5"/>
   	<polygon fill="black" stroke-width="1" points="607.5,209.5 599.5,204.5 599.5,214.5"/>
   	<text x="284.5" y="200.5" font-family="Times New Roman" font-size="20">(a?c(ac)*)?a?</text>
   	<polygon stroke="black" stroke-width="1" points="365.134,350.693 610.866,223.307"/>
   	<polygon fill="black" stroke-width="1" points="610.866,223.307 601.462,222.55 606.065,231.428"/>
   	<text x="492.5" y="308.5" font-family="Times New Roman" font-size="20">(a?c(ac)*)?a?</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 351.725,391.297 A 22.5,22.5 0 1 1 325.275,391.297"/>
   	<text x="268.5" y="453.5" font-family="Times New Roman" font-size="20">a?c(ac)*a?b|ab</text>
   	<polygon fill="black" stroke-width="1" points="325.275,391.297 316.527,394.83 324.618,400.708"/>
   </svg>

8. remove state `B` :

   <svg width="800" height="600" version="1.1" xmlns="http://www.w3.org/2000/svg">
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="80.5" cy="209.5" rx="30" ry="30"/>
   	<text x="60.5" y="215.5" font-family="Times New Roman" font-size="20">init</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="30" ry="30"/>
   	<text x="622.5" y="215.5" font-family="Times New Roman" font-size="20">end</text>
   	<ellipse stroke="black" stroke-width="1" fill="none" cx="637.5" cy="209.5" rx="24" ry="24"/>
   	<polygon stroke="black" stroke-width="1" points="1.5,209.5 50.5,209.5"/>
   	<polygon fill="black" stroke-width="1" points="50.5,209.5 42.5,204.5 42.5,214.5"/>
   	<path stroke="black" stroke-width="1" fill="none" d="M 110.294,205.993 A 2254.999,2254.999 0 0 1 607.706,205.993"/>
   	<polygon fill="black" stroke-width="1" points="607.706,205.993 600.306,200.141 599.203,210.08"/>
   	<text x="284.5" y="183.5" font-family="Times New Roman" font-size="20">(a?c(ac)*)?a?</text>
   	<path stroke="black" stroke-width="1" fill="none" d="M 607.918,214.49 A 1585.403,1585.403 0 0 1 110.082,214.49"/>
   	<polygon fill="black" stroke-width="1" points="607.918,214.49 599.233,210.808 600.803,220.684"/>
   	<text x="124.5" y="255.5" font-family="Times New Roman" font-size="20">(a?c(ac)*)?a?b(a?c(ac)*a?b|ab)*(a?c(ac)*)?a?</text>
   </svg>

9. Result:

   ```regex
   ^(a?c(ac)*)?a?(b(a?c(ac)*a?b|ab)*(a?c(ac)*)?a?)?$
   ```
