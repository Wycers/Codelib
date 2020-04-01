## Question 1

What is a process? What is a program? And what is the difference?

- A process is an execution instance of a computer program that is being executed by one or many threads with CPU, memory and other resources. It contains the program code and its activity. (With Runtime data and context)

- A program, a program is a collection of instructions that can be executed by a computer to perform a specific task. (With static data.)

- Difference:

  1. A program is static, but a program is dynamic.
  2. A program can be stored in hard disk alone without a operating system, but a process has a life cycle which corresponding to a (specific) operating system.
  3. A program only consume storage resources, but a program will consume CPU \& memory resources.

## Question 2

What is job? And what is the difference between process and job?

A job is a unit of work or unit of execution. A component of a job (as a unit of work) is called a task or a step (if sequential, as in a job stream). As a unit of execution, a job may be concretely identified with a single process, which may in turn have subprocesses (child processes; the process corresponding to the job being the parent process) which perform the tasks or steps that comprise the work of the job; or with a process group; or with an abstract reference to a process or process group, as in Unix job control.

## Question 3

What are the differences between job scheduling and process scheduling?

- Job scheduling is to select jobs from external job backup queues to be transferred to memory according to certain principles, allocate resources to them, create corresponding processes, and enter the ready queue.
- Process scheduling is to select a process from the ready queue and assign a processor to it according to some strategy or method.

## Question 4

What are the similarities and differences among structures, classes, and unions?

Similarities:

They all can have their own member variables.

Differences:

1. Between structures and classes: Structure does not support inheritance, that is, a structure cannot inherit from another structure or class, and cannot be used as the base class of a class.

2. Between structures and unions: At any one time, only one selected member is stored in the union, and all members of the struct exist. In the struct, each member occupies its own memory space, they exist at the same time. The total length of a struct variable is equal to the sum of all member lengths. In Union, all members cannot occupy its memory space at the same time, they cannot exist at the same time. The length of the Union variable is equal to the length of the longest member.

## Question 5

How many statuses are in a job? And what are they?

- `READY`: The job is ready to be executed.
- `RUNNING`: The job is running.
- `DONE`: The job is finished. (Which will be imediately removed)

## Question 6

What programs for job control are used in this experiment? And their function?

1.  `scheduler`

    1.  Create a process for a new job. Set its state to READY and put it in the waiting
        queue.

    2.  Handle `ENQ` requests:

        - assigns a unique jid to each job;
        - create a process for it and set its status to READY;
        - put this process into the waiting queue.

    3.  Handle `DEQ` requests:

        - A job will dequeue when receive dequeue request, and the relevant data
          structure will be cleared. (If the job is currently running, it will first stop running and then dequeue.)

    4.  Handle `STAT` requests:

        - If status request, it outputs information about the currently running job and
          all jobs in the waiting queue.
        - `pid, user name, execution time, waiting time, create time, job status` and `job_name, curpri, defpri` will be printed.

2.  `enq`:

    - **Usage**: `enq [-p num] e_file args`
    - **Function**: Send a enqueue request to the scheduler and submit the job for running.

3.  `deq`:

    - **Usage**: `deq job_id`
    - **Function**: Send a dequeue request to the scheduler.

4.  `stat`:

- **Usage**: `stat`
  - **Function**: Send a stat request to the scheduler.

## Question 7

What is used for inter-process communication in this experiment? And its function?

FIFO, its function are:

1. The scheduler creates a FIFO file.

2. The rest program (`enq, deq, stat`) write the command in `struct jobcmd` format to the FIFO file.

3. The scheduler reads the commands from FIFO file.

## Question 8

What should be noted when printing out the job name?

According to task request, adding NAME, CURPRI, DEFPRI fields as follows:

```c
printf("JID\tPID\tOWNER\tRUNTIME\tWAITTIME\tNAME\tCURPRI\tDEFPRI\tCREATTIME\t\t\tSTATE\n");

// Add NAME, CURPRI, DEFPRI
// Double \t after CRAETTIME because time is longer.
```

Make corresponding modify (add `job->cmdarg[0]`, `job->curpri`, `job->defpri`) to output statements as follows:

```c
// for current running job:
...
    printf("%d\t%d\t%d\t%d\t%d\t%s\t%d\t%d\t%s\t%s\n",
           ...
           current->job->cmdarg[0],
           current->job->curpri,
           current->job->defpri,
           timebuf,
           "RUNNING");
...

// for other jobs:
...
    printf("%d\t%d\t%d\t%d\t%d\t%s\t%d\t%d\t%s\t%s\n",
           ...
           p->job->cmdarg[0],
           p->job->curpri,
           p->job->defpri,
           timebuf,
           "READY");

```

## Question 9

Submit a job that takes more than 100 milliseconds to run（pleas paste your code?

Sometimes simple loop will be optimized by the compiler, I think the timer is a good choice.

```c
#include <stdio.h>
#include <time.h>

int main() {
    int t = 0;
    clock_t startTime = clock();
    while (clock() - startTime < 114514);
    printf("%lfs\n", (double)(clock() - startTime) / CLOCKS_PER_SEC);
    return 0;
}
```

## Question 10

List the bugs you found and your fix (Describe the cause of bugs in detail and how to modify it)?

1. Full-width semicolon. **Fix**: Change it to half-width semicolon.
2. Time interval. The time interval of scheduler is 100 microseconds but not 100 milliseconds. **Fix**: Change it to 100 \* 1000 microseconds.

```c
	/* timer interval: 0s, 100ms */

	interval.tv_sec = 0;
	interval.tv_usec = 100 * 1000;      // 1ms = 1000us !
```

3. Improper implementation of remove. `selectprev->next = select->next;` is used to remove `select` fron link-list. But while `select == selectprev`, according to context, `select` and `selectprev` must be equal to `head`, then `selectprev->next = select->next;` is equivalent to `head->next = head->next;`, which can not remove `select` from link-list properly. **Fix**: As follows.

```c
    if (select == selectprev)
      head = select->next;                  // head is the one selected, remove head.
    else
      selectprev->next = select->next;      // select is the one selected.
```

4. Endless loop. Because it does not remove `*next` of `current`, when link it back to the end of the link-list, the `*next` will point to the job before it in the link-list. For example, `1 -> 2 -> 3 -> 4`, when **Job 2** is executed, it will link **Job 2** like `1 -> 2 -> 3 -> 4 -> 2`, and `2 -> 3`, then there is a loop like `2 -> 3 -> 4 -> 2(head)`. **Fix**: clean `*next` as follows:

```c
    /* If a job is running, set it to read*/
		kill(current->job->pid, SIGSTOP);
		current->job->curpri = current->job->defpri;
		current->job->wait_time = 0;
		current->job->state = READY;

		/* move back to the queue */

		if (head)
		{
			for (p = head; p->next != NULL; p = p->next)
				;
			p->next = current;
		}
		else
		{
			head = current;
		}

		current->next = NULL; // In counter of endless loop  <=== Look here !
```

5. Unexpected long running time when only 1 job in scheduler: different triggering sequence will cause scheduler mistakenly thinking that the job is running but not in fact. **Fix**: wait child process to STOP itself first.

   ```c
   ...
   {
       waitpid(pid, NULL, 0);  // <==== wait for child process!
       newjob->pid = pid;
       printf("\nnew job: jid=%d, pid=%d\n", newjob->jid, newjob->pid);
   }
   ```

## Question 11

Run the job scheduler program, And analyze the execution of the submitted job?

The execution of the submitted job has three life cycles: READY, RUNNING, DONE.

In every time slice, scheduler will schedule the job once with schedule strategy:

1. **No Jobs**: Do nothing.
2. **1 Job**: Always schedule the only job.
3. **2 Job or more jobs**: Job with highest priority runs first, if with same priority, the job waiting longest runs first. And

- Priority add 1 after waiting for 100ms
- Priority reset to initial priority after running

When multiple jobs are in scheduling, in every time slice, there will be a job switch. It stops current job (that change job status from `RUNNING` to `READY`) and start another one (that change job status from `READY` to `RUNNING`). Here are the details.

1. **READY -> RUNNING**:

   1. Send `SIGCONT` to the process of the next job.
   2. Set status of the current job to `RUNNING`.

2. **RUNNING -> READY**:

   1. Send `SIGSTOP` to the process of the current job.
   2. Change priority of the current job according to schedule strategy.
   3. Set status of the current job to `READY`.

3. **RUNNING -> DONE**:
   1. When a `RUNNING` process exits, the status of the corresponding job will be changed to `DONE`, and be immediately removed.

And in every interval, the current priority and wait time of each job will be updated to support the scheduling strategy.

## Question 12

Understand the process of job scheduling——Submit a new job (Execution results and corresponding code)?

1. Enq program: Process and validate job parameters; Result: Abort unrecognized parameter name and invalid parameter range

```c
  // Processing parameters
	while (--argc > 0 && (*++argv)[0] == '-')
	{

		while ((c = *++argv[0]))
			switch (c)
			{
			case 'p':
				p = atoi(*(++argv));
				argc--;
				break;
			default:
				printf("Illegal option %c\n", c);
				return 1;
			}
	}

  // Validating parameters
	if (p < 0 || p > 3)
	{
		printf("invalid priority: must between 0 and 3\n");
		return 1;
	}

```

2.  Enq program: Generate cmd message; Result: Parse an ENQ command with owner_id and arguments of the program will be executed.

    ```c
    enqcmd.type = ENQ;
    enqcmd.defpri = p;
    enqcmd.owner = getuid();
    enqcmd.argnum = argc;
    offset = enqcmd.data;

    while (argc-- > 0)
    {
    	strcpy(offset, *argv);
    	strcat(offset, ":");
    	offset = offset + strlen(*argv) + 1;
    	argv++;
    }
    ```

3.  Enq program: Send it through FIFO. Result: Abort when get error to FIFO. Otherwise, put the ENQ command in the FIFO file.

    ```c
    if ((fd = open(FIFO, O_WRONLY)) < 0)
    	error_sys("enq open fifo failed");

    if (write(fd, &enqcmd, DATALEN) < 0)
    	error_sys("enq write failed");

    close(fd);
    ```

4.  Scheduler：When recive a `ENQ` requests, it will

    First, construct a jobinfo instance.

    ```c
    /* fill jobinfo struct */

    newjob = (struct jobinfo *)malloc(sizeof(struct jobinfo));
    newjob->jid = allocjid();
    newjob->defpri = enqcmd.defpri;
    newjob->curpri = enqcmd.defpri;
    newjob->ownerid = enqcmd.owner;
    newjob->state = READY;
    newjob->create_time = time(NULL);
    newjob->wait_time = 0;
    newjob->run_time = 0;
    arglist = (char **)malloc(sizeof(char *) * (enqcmd.argnum + 1));
    newjob->cmdarg = arglist;
    offset = enqcmd.data;
    argvec = enqcmd.data;
    while (i < enqcmd.argnum)
    {
    	if (*offset == ':')
    	{
    		*offset++ = '\0';
    		q = (char *)malloc(offset - argvec);
    		strcpy(q, argvec);
    		arglist[i++] = q;
    		argvec = offset;
    	}
    	else
    		offset++;
    }

    arglist[i] = NULL;

    ```

    Second, add the new job to end of the queue

    ```c
    /* add new job to the queue */
    newnode = (struct waitqueue *)malloc(sizeof(struct waitqueue));
    newnode->next = NULL;
    newnode->job = newjob;
    if (head)
    {
    	for (p = head; p->next != NULL; p = p->next)
    	;
    	p->next = newnode;
    }
    else
    	head = newnode;
    ```

    Finally, create a child process to execute the job. The child process will immediately stop itself to wait for the scheduler's signals.

    ```c
    /* create process for the job */

    if ((pid = fork()) < 0)
    	error_sys("enq fork failed");

    /* In child process */

    if (pid == 0)
    {

    	newjob->pid = getpid();

    	/* block the child wait for run */

    	raise(SIGSTOP);  	 	// <= Stop the job immediately!

    	/* dup the globalfile descriptor to stdout */
    	dup2(globalfd, 1);
    	if (execv(arglist[0], arglist) < 0)
    		printf("exec failed\n");

    	exit(1);
    }
    else
    {
    	waitpid(pid, NULL, 0);	// wait for child process to stop itself!
    	newjob->pid = pid;
    	printf("\nnew job: jid=%d, pid=%d\n", newjob->jid, newjob->pid);
    }

    ```

## Question 13

Understand the process of job scheduling——End of job execution (Execution results and corresponding code)?

There are two kinds of end of job execution: 1. A job is finished 2. A job is requested to be dequeued (deq).

1.  Finished

1.  System: When a job is finished, the scheduler will receive a `SIGCHLD` signal, then it can check the job's process exists or not. If the process of the job exited, the scheduler will set the status of the job instance to `DONE`.

    ```c
    void sig_handler(int sig, siginfo_t *info, void *notused)
    {
    	...
    	case SIGCHLD:
    		...
    		if (WIFEXITED(status))
    		{
    			...
    			current->job->state = DONE;					// <<===
    			printf("normal termation, exit status = %d\tjid = %d, pid = %d\n\n",
    				WEXITSTATUS(status), current->job->jid, current->job->pid);
    		}
    		...
    }

    ```

1.  Scheduler: While doing job swtich, it will automatically remove the job with status `DONE`

    ```c
    void jobswitch()
    {
    	struct waitqueue \*p;
    	int i;

    	if (current && current->job->state == DONE)
    	{ /* current job finished */

    		/* job has been done, remove it */
    		for (i = 0; (current->job->cmdarg)[i] != NULL; i++)
    		{
    			free((current->job->cmdarg)[i]);
    			(current->job->cmdarg)[i] = NULL;
    		}

    		free(current->job->cmdarg);
    		free(current->job);
    		free(current);

    		current = NULL;
    	}
    	...
    }
    ```

1.  Dequeued

1.  Deq program: Process and validate job parameters; Result: Abort unrecognized parameter name and invalid parameter range

    ```c
    // Processing and Validating parameters
    if (argc != 2)
    {
    	usage();
    	return 1;
    }

    ```

1.  Deq program: Generate cmd message; Result: Parse an `DEQ` command with owner_id and arguments of the program will be executed.

    ```c
    deqcmd.type = DEQ;
    deqcmd.defpri = 0;
    deqcmd.owner = getuid();
    deqcmd.argnum = 1;

    strcpy(deqcmd.data, *++argv);
    ```

1.  Deq program: Send it through FIFO. Result: Abort when get error to FIFO. Otherwise, put the ENQ command in the FIFO file.

    ```c
    if ((fd = open(FIFO, O_WRONLY)) < 0)
    	error_sys("deq open fifo failed");

    if (write(fd, &deqcmd, DATALEN) < 0)
    	error_sys("deq write failed");

    close(fd);
    ```

1.  Scheduler:

    If the current job will be dequeued, the scheduler will stop it and remove it.

    ```c
    /* current jodid == deqid, terminate current job */
    if (current && current->job->jid == deqid)
    {

    	printf("terminate job: %d\n", current->job->jid);
    	kill(SIGTERM, current->job->pid);		// <=Terminate it!

    	/* free the job */
    	for (i = 0; (current->job->cmdarg)[i] != NULL; i++)
    	{

    		free((current->job->cmdarg)[i]);
    		(current->job->cmdarg)[i] = NULL;
    	}

    	free(current->job->cmdarg);
    	free(current->job);
    	free(current);

    	current = NULL;
    }
    ```

    If a waiting job will be dequeued, the scheduler will remove it.

    ```c
    else
    { /* maybe in waitqueue, search it */
    	select = NULL;
    	selectprev = NULL;

    	if (head)
    	{
    		for (prev = head, p = head; p != NULL; prev = p, p = p->next)
    		{
    			if (p->job->jid == deqid)
    			{
    				select = p;
    				selectprev = prev;
    				break;
    			}
    		}

    		if (select == selectprev)
    			head = select->next;
    		else
    			selectprev->next = select->next;
    	}

    	if (select)
    	{
    		/* free the job */
    		for (i = 0; (select->job->cmdarg)[i] != NULL; i++)
    		{
    			free((select->job->cmdarg)[i]);
    			(select->job->cmdarg)[i] = NULL;
    		}

    		free(select->job->cmdarg);
    		free(select->job);
    		free(select);

    		select = NULL;
    	}
    }
    ```

## Question 14

Understand the process of job scheduling——job scheduling due to Priority(Execution results and corresponding code)?

Frist, every job has a default priority, which can be specified by argument `p` in `enq` program.

And every 100ms, the scheduler will upgrade the priority of waiting jobs by 1, but the priority will not exceed 3.

```c
void updateall()
{
struct waitqueue *p;

/* update running job's run_time */
if (current)
current->job->run_time += 1;

/* update ready job's wait_time */
for (p = head; p != NULL; p = p->next)  // <== for all (waiting) jobs
{
p->job->wait_time += 1;
if ((++p->job->curpri) > 3)         // <== upgrade current priority
p->job->curpri = 3;             // <== priority's upper bound is 3
}
}
```

And when do job selection, scheduler will use **priority** as the first keyword and **wait_time** as the second keyword to select the job.

```c
for (prev = head, p = head; p != NULL; prev = p, p = p->next)
{

	//  ↓ First keyword: Priority
	if (p->job->curpri > highest || (p->job->curpri == highest && p->job->wait_time > select->job->wait_time))
	{
		select = p;
		selectprev = prev;
		highest = p->job->curpri;
	}
}
```

## Question 15

Understand the process of job scheduling——Job scheduling due to time slice (Execution results and corresponding code)?

In every time slice, scheduler add 100ms to the waittime of all jobs in `READY` status.When a job waits for every 100ms, scheduler will upgrade the priority of the job.

```c
void updateall()
{
	struct waitqueue *p;

	/* update running job's run_time */
	if (current)
		current->job->run_time += 1;

	/* update ready job's wait_time */
	for (p = head; p != NULL; p = p->next)  // <== for all (waiting) jobs
	{
		p->job->wait_time += 1;             // <== update wait time
		if ((++p->job->curpri) > 3)
			p->job->curpri = 3;
	}
}
```

And when do job selection, scheduler will use **priority** as the first keyword and **wait_time** as the second keyword to select the job.

```c
for (prev = head, p = head; p != NULL; prev = p, p = p->next)
{

	//                                      Second keyword: Wait_time ↓
	if (p->job->curpri > highest || (p->job->curpri == highest && p->job->wait_time > select->job->wait_time))
	{
		select = p;
		selectprev = prev;
		highest = p->job->curpri;
	}
}
```

## Conclusion

Fixing bugs is so funny!
