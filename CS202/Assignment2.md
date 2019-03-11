# Assignment2

- Course: Computer Organization
- Student: 11711918 吴烨昌

## 2.2

### Description

[5] <§2.2> For the following C statement, what is the corresponding MIPS assembly code? Assume that the variables f, g, h, and i are given and could be considered 32-bit integers as declared in a C program. Use a minimal number of MIPS assembly instructions. f = g + (h − 5);

### Solution

``` MIPS
lw      $t0, f          #$t0 = &f
lw      $t1, g          #$t1 = &g
lw      $t2, h          #$t2 = &h

subu    %t2, $t2, 5     #h' = h - 5
add     $t1, $t1, $t2   #f = g + h'

sw      $t1, $t0        #store f
```

## 2.3

### Description

[5] <§§2.2, 2.3> For the following C statement, what is the corresponding MIPS assembly code? Assume that the variables f, g, h, i, and j are assigned to registers \$s0, \$s1, \$s2, \$s3, and \$s4, respectively. Assume that the base address of the arrays A and B are in registers \$s6 and \$s7, respectively. B[8] = A[i−j];

### Solution

``` MIPS
sub     $t0, $s3, $s4   #$t0 = i - j
add     $t0, $t0, $s6   #$t0 = (i - j)(&A)
lw      $t0, $t0        #load word from (i - j)(&A)
sw      $t0, 32($s7)    #store word to B[8]
```

## 2.6

### Description

The table below shows 32-bit values of an array stored in memory.

| Address | Data |
| :-----: | :--: |
|   24    |  2   |
|   *28   |  4   |
|   32    |  3   |
|   36    |  6   |
|   40    |  1   |

1.  [5] <§§2.2, 2.3> For the memory locations in the table above, write C code to sort the data from lowest to highest, placing the lowest value in the smallest memory location shown in the figure. Assume that the data shown represents the C variable called Array, which is an array of type int, and that the first number in the array shown is the first element in the array. Assume that this particular machine is a byte-addressable machine and a word consists of four bytes.
2.  [5] <§§2.2, 2.3> For the memory locations in the table above, write MIPS code to sort the data from lowest to highest, placing the lowest value in the smallest memory location. Use a minimum number of MIPS instructions. Assume the base address of Array is stored in register $s6.

*I think that should be 28 because of continuity of array element address

### Solution

``` c 
void swap(int &p, int &q)
{
    int t = p;
    p = q;
    q = t;
}

int a[] = {2, 4, 3, 6, 1};
for (int i = 0; i < 5; ++i)
    for (int j = i + 1; j < 5; ++j)
        if (a[i] > a[j])
            	swap(a[i], a[j]);
```

``` MIPS
    addi    $s7, $s6, 5         #$s7 = &a[5], end pointer
    move    $s0, $s6            #$s0 = &a[0]
loop1:
    addi    $s1, $s0, 1         #$s1 = $s0 + 1
    beq     $s1, $s7, exit1
loop2:
    bgt     $s0, $s1, swap      #if $s0 > $s1, go to swap
done:
    addi    $s1, $s1, 1         #$s1 = $s1 + 1
    beq     $s1, $s7, exit2     #if $s1 = end, go to exit2
    j       loop2               #else go to loop2
exit2:
    addi    $s0, $s0, 1         #$s0 = $s0 + 1
    j       loop1
swap:
    lw      $t0, ($s0)
    lw      $t1, ($s1)
    sw      $t1, ($s0)
    sw      $t0, ($s1)
    j		done
exit1:
    # Print ...

```



## 2.12

### Description

Assume that registers \$s0 and \$s1 hold the values 0x80000000 and 0xD0000000, respectively. 

1. [5] <§2.4> What is the value of \$t0 for the following assembly code? `add ​$t0, $s0, $s1`
2. [5] <§2.4> Is the result in \$t0 the desired result, or has there been overflow? 
3. [5] <§2.4> For the contents of registers \$s0 and \$s1 as specified above, what is the value of \$t0 for the following assembly code? `sub $t0, $s0, $s1` 
4. [5] <§2.4> Is the result in \$t0 the desired result, or has there been overflow? 
5. [5] <§2.4> For the contents of registers \$s0 and \$s1 as specified above, what is the value of \$t0 for the following assembly code? `add $t0, $s0, $s1 add $t0, $t0, $s0`
6. [5] <§2.4> Is the result in $t0 the desired result, or has there been overflow?

### Solution

1. 0x80000000 + 0xD0000000 = 0x150000000, because of overflow, $t0 should be 0x50000000 
2. overflow
3. 0x80000000 - 0xD0000000 = 0xD0000000
4. no overflow
5. 0x80000000 + 0xD0000000 + 0x80000000 = 0xD0000000,
6. overflow

## 2.16

### Description

[5] <§2.5> Provide the type, assembly language instruction, and binary representation of instruction described by the following MIPS fi elds: op=0, rs=3, rt=2, rd=3, shamt=0, funct=34

Refer to **Figure2.14**, rs = 3 means \$v1, rt = 2 means \$v0, rd = 3 means \$v1

Refer to **Figure2.5**, funct = 34 means substract

So assembly language instruction is `sub $v1, $v1, $v0`

``` plain
op = 0, 000000
rs = 3, 00011
rt = 2, 00010
rd = 3, 00011
shamt = 0, 000000
funct = 34, 100010
```

So binary representation of instruction is `000000 00011 00010 00011 000000 100010`

