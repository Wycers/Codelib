**mkdir**

Function: make a directory.

Usage: `mkdir <dir>`  create a directory named `dir` . In common, use`mkdir <dir> -p` to make parent directories if needed.

So, `mkdir ~/11711918` will make the directory `~/11711918`.



**ls**

Function: list entries.

Usage: `ls <dir>` to list all files and directories in `<dir>`. Parameter `<dir>` is optional, which is default to be now working directory. Add `-l` flag to use a long list format, add `-a` flag to do not ignore entries starting with `.` (usually hidden). 

So `ls -la ~` will list all entries in `~` directory.



**cd**

Function: change directory.

Usage: `cd <dir>` to change now working directory to `<dir>`.

So, `cd ~/11711918` will change working directory to `~/11711918`.





**man**

Function: view the manual.

Usage: `man <command>` to view the manual of `<command>`

So, `man grep` will give out the manual of `grep`, such as NAME, SYNOPSIS, DESCRIPTION, OPTIONS of `grep`.



**mv**

Function: mv a file or directory to another directory.

Usage: `mv <file/dir> <Dir>` will move `<file>/<dir>` to <Dir>.

So, `mv ~/11711918 /home` will move `~/11711918` to `/home/11711918`, now `ls /home` will show the files and directories in `/home` (only `11711918` here) 



**rm**

Function: remove a file or directory.

Usage: `rm <file>` will remove a file named `<file>` . With `-r` flag,`rm -r <dir>` can remove the directory `<dir>`.

So, `rm -r /home/11711918` will remove the directory `/home/11711918`



**cp**

Function: copy a file or directory.

Usage: `cp <file> <FILE>` will copy from `<file>` to `<FILE>` . With `-r` flag, `cp -r <dir> <DIR>` can copy the directory `<dir>` to `<DIR>`.

So, `cp /etc/apt/sources.list /etc/apt/sources.list.bak` will copy `/etc/apt/sources.list` to `/etc/apt/sources.list.bak`. After that, there will be a new file named `sources.list.bak` with same content as `sources.list` in `/etc/apt`.



**cat**

Function: concatenate files and print on the stdout.

Usage: `cat <file>` will print the content of `<file>` to stdout.

So, `cat /etc/shells` will print the content in `/etc/shells` which record the full pathnames of valid login shells.

Here is my result:

```
# /etc/shells: valid login shells
/bin/sh
/bin/bash
/bin/rbash
/bin/dash
/usr/bin/tmux
/usr/bin/screen
```



**| (pipe command)**

Function: Mash-up two or more commands such that output of one command serves as input to the next.

Usage: `<command1> | <command2>` will redirect the output of `<command1>` to the input of `<command2>`



**grep**

Function: print lines matching a pattern.

Usage: `grep <pattern>` will input from standard input and print out the lines matching `<pattern>`.



So, `cat /etc/shells | grep bash` will print out all lines matching `bash` in content of `/etc/shells`.

Here is my result:

```
/bin/bash
/bin/rbash
```



My environment is wsl, so I have no terminal application in wsl. I will use bash in instead.

First, run `ps -a` :

```
wycer@WYCER:~$ ps -a
  PID TTY          TIME CMD
   84 tty1     00:00:00 bash
  442 tty1     00:00:00 ps  
```

Second, open a new terminal, run `ps -a` again:

``` 
wycer@WYCER:~$ ps -a
  PID TTY          TIME CMD
   84 tty1     00:00:00 bash
  444 tty2     00:00:00 bash
  497 tty1     00:00:00 ps
```

The pid of the second shell is `444`

Third, run `kill 444` , the second terminal is closed and run `ps -a` again:

```
wycer@WYCER:~$ kill 444
wycer@WYCER:~$ ps -a
  PID TTY          TIME CMD
   84 tty1     00:00:00 bash
  499 tty1     00:00:00 ps
```

RIP for process `444`.



1. Program **opt.c**

   ``` c
   #include "stdio.h"
   int main() {
       int x = 0;
       x += 1;
       x += 1;
       x += 1;
       printf("%d\n", x);
       return 0;
   }
   ```

2. ``` bash
   gcc -S opt.c -O0 -o opt0.s # Generate assembly file opt0.s under O0
   gcc -S opt.c -O1 -o opt1.s # Generate assembly file opt1.s under O1
   diff opt1.s opt0.s -y --suppress-common-lines # Compare opt0.s and opt1.s  side-by-side (-y) without common lines (--suppres-common-lines)
   ```

3. Under O0, three additions are compiled as three instructions.

   ``` 
           movq    %rsp, %rbp
           .cfi_def_cfa_register 6
           subq    $16, %rsp
           movl    $0, -4(%rbp)
           addl    $1, -4(%rbp)
           addl    $1, -4(%rbp)
           addl    $1, -4(%rbp)
   ```

   But under O1, three additions are compiled as one instructions. It can clearly be seen that O1 has better optimization.

   ``` 
   		subq    $8, %rsp
           .cfi_def_cfa_offset 16
           movl    $3, %edx
   ```

   

   





# Conclusion





