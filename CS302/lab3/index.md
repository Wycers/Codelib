## Question 1

What is a process? What is a program? And what is the difference?

- A process is an execution instance of a computer program that is being executed by one or many threads with CPU, memory and other resouces. It contains the program code and its activity. (With Runtime data and context)

- A program, a program is a collection of instructions that can be executed by a computer to perform a specific task. (With static data.)

- Difference:

  1. A program is static, but a program is dynamic.
  2. A program can be stored in hard disk alone without a operating system, but a process has a life cycle which corresponding to a (specific) operating system.
  3. A program only consume storage resouces, but a program will consume CPU \& memory resouces.

## Question 2

What is job? And what is the difference between process and job?

A job is a unit of work or unit of execution. A component of a job (as a unit of work) is called a task or a step (if sequential, as in a job stream). As a unit of execution, a job may be concretely identified with a single process, which may in turn have subprocesses (child processes; the process corresponding to the job being the parent process) which perform the tasks or steps that comprise the work of the job; or with a process group; or with an abstract reference to a process or process group, as in Unix job control.

## Question 3

What are the differences between job scheduling and process scheduling?

- Job scheduling is to select jobs from external job backup queues to be transferred to memory according to certain principles, allocate resources to them, create corresponding processes, and enter the ready queue.
- Process scheduling is to select a process from the ready queue and assign a processor to it according to some strategy or method.

## Question 4

What are the similarities and differences among structures, classes, and unions?

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

According to task request, adding NAME, CURPRI, DEFPRI fileds as follows:

```c
printf("JID\tPID\tOWNER\tRUNTIME\tWAITTIME\tNAME\tCURPRI\tDEFPRI\tCREATTIME\t\t\tSTATE\n");

// Add NAME, CURPRI, DEFPRI
// Double \t after CRAETTIME because time is longer.
```

Make corresponding modify (add `job->cmdarg[0]`, `job->curpri`, `job->defpri`) to output statements as follows:

```
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

Sometimes simple loop will be optimized by compiler, I think timer is a good choice.

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
   1. When a `RUNNING` process exits, the status of the corresponding job will be changed to `DONE`, and be imediately removed.

And in every interval, the current priority and wait time of each job will be updaetd to support the scheduling strategy.

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

2. Enq program: Generate cmd message; Result: Parse an ENQ command with owner_id and arguments of the program will be executed.

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

3. Enq program: Send it through FIFO. Result: Abort when get error to FIFO. Otherwise, put the ENQ command in the FIFO file.

```c
	if ((fd = open(FIFO, O_WRONLY)) < 0)
		error_sys("enq open fifo failed");

	if (write(fd, &enqcmd, DATALEN) < 0)
		error_sys("enq write failed");

	close(fd);
```

## Question 13

Understand the process of job scheduling——End of job execution (Execution results and corresponding code)?

There are two kinds of end of job execution: 1. A job is finished 2. A job is requested to be dequeued (deq).

1. Finished
2. Dequeued

## Question 14

Understand the process of job scheduling——job scheduling due to Priority(Execution results and corresponding code)?

When select next job to execute, scheduler will select the most highest priority job

## Question 15

Understand the process of job scheduling——Job scheduling due to time slice (Execution results and corresponding code)?

In every time slice, scheduler add 100ms to the job in `READY` status. When a job waits for 100ms, scheduler will upgrade the priority of the job.

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
		if ((++p->job->curpri) > 3)         // <== upgrade current priority
			p->job->curpri = 3;             // <== priority's upper bound is 3
	}
}
```

And when do job selection,

## Conclusion

Fixing bugs is so funny!
