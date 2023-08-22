## Question 1

Nothing

## Question 2

### What is a system call?

Modern operating systems divide systems into kernel space and user space. Processes in user space can not access system resources (such as memory, hard disk... ) directly. System calls provide an essential interface between a process and the operating system (from wiki).


## Question 3

### What is fork?

Fork is an operation whereby a process creates a copy of itself as a child process. 

## Question 4

### How to realize inter-process communication?

- Shared Memory
- Pipe
- Signal
- Socket
- Remote Procedural calls (RPCs)

## Question 5

### How to realize inter-process connection?

Capture signals and call corresponding handler.

## Question 6

### Write the prototype of function "fork"?

``` c
#include <sys/types.h>
#include <unistd.h>
​
pid_t fork(void);
```

## Question 7

### Write the prototype of function "signal"?

``` c
#include <signal.h>
​
typedef void (*sighandler_t)(int);

sighandler_t signal(int signum, sighandler_t handler);
```

## Question 8

### Write the prototype of function "pipe"?

``` c
#include <unistd.h>
​
int pipe(int pipefd[2]);
​
#define _GNU_SOURCE             /* See feature_test_macros(7) */
#include <fcntl.h>              /* Obtain O_* constant definitions */
#include <unistd.h>
​
int pipe2(int pipefd[2], int flags);
```

## Question 9

### Write the prototype of function "tcsetpgrp"

``` c
#include <unistd.h>
​
pid_t tcgetpgrp(int fd);
​
int tcsetpgrp(int fd, pid_t pgrp);
```

## Question 10

### Execute "fork.c" and observe, please describe the result (not execution result)

- What: The parent process waits for the child process to output argc = 1, argv[0] = ./forktotal 580 and the result of ls -l /.
- Why: The parent process use fork() to create a child process. In the child process, it outputs the command and arguments it wants to execute. In the parent process, it waits for the child process to finish.

## Question 11

### Execute "fork.c" and observe, please describe how to distinguish between parent and child processes in a program.

Let `pid = fork();`

- If `pid = 0`, it is in the child process.
- If `pid > 0`, it is in the parent process.
- If `pid < 0`, something is wrong (failed in creating child process).

## Question 12

### Execute "pipe.c" and observe, please describe the result (not execution result)

- What: Use more to view the result of ls /etc .
- How: Create a pipe. In the child process 1, it redirects stdout to pipe in, then execute `ls` so that the result of ls goes into the pipe. In the child process 2, it redirects pipe to stdin, then execute `more`, so that the content in pipe goes into more. The parent process will give the child processes a 'signal' to do that and wait for them to finish executing.

## Question 13

### Execute "pipe.c" and observe.  Is execvp(prog2_argv[0],prog2_argv)(Line 56) executed? And why?

Yes, it is executed.

## Question 14

### Execute "signal.c" and observe, please describe the result (not execution result)：

- What: About every second, the child process and the parent process will output their pids. If the child process is terminated, the parent process will output "The child is gone!!!!", and output "Uninteresting" otherwise.
- How: Two processes are listening to signals and have a corresponding handler function.

## Question 15

### Execute "signal.c" and observe. Please answer, how to execute function ChildHandler?

Send some signals to it, for example, execute kill -1 <pid>, where <pid> is the PID of the process.

## Question 16

### Execute "process.c" and observe, please describe the result (not execution result)：

- What: VI welcome page. After quitting VI, we can input something and see the echo.
- Why: The child process uses tcsetpgrp to set itself as the foreground process, then it opens VI, which shows the VI welcome page. The parent process uses waitpid to wait the child process to quit, then uses tcsetpgrp to set itself as the foreground process, then it repeat what user inputs.
- How: execvp is only accept array pointer as parameter. So change execve("/bin/vi", "vi", NULL); to execlp("vi", "vi", NULL);; and signal(SIGTTOU, SIG_IGN); should be put at beginning of the code according to sto_tcsetpgrp

## Question 17

### Execute "process.c" and observe. Please answer, how many ./process in the process list? And what’s the difference between them?:

In fact, there is only 1 ./process from the parent process, the child process is named vi. Difference..the name, and the child process vi is on the foreground, the parent process is on the background.

## Question 18

### Execute "process.c" and observe. Please answer, what happens after killing the main process?

Vi interface disappeared and showed "killed ./process". The main process is dead and leaves vi alone. vi may exit because of `read in error`.

## Question 19

### Make a conclusion

OS is interesting.

