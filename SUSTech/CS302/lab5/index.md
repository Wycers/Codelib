## Question 1

What is deadlock?

If a process is unable to change its state indefinitely because the resources requested by it are being used by another waiting process, then the system is said to be in a deadlock.

## Question 2

What are the requirements of deadlock?

1. **Mutual exclusion**: At least one resource must be held in a non-shareable mode. Otherwise, the processes would not be prevented from using the resource when necessary. Only one process can use the resource at any given instant of time.
2. **Hold and wait or resource holding**: a process is currently holding at least one resource and requesting additional resources which are being held by other processes.
3. **No preemption**: a resource can be released only voluntarily by the process holding it.
4. **Circular wait**: each process must be waiting for a resource which is being held by another process, which in turn is waiting for the first process to release the resource.

## Question 3

What's different between deadlock prevention and deadlock avoidance?

- **Deadlock prevention**: Works by preventing some of the four requirements of deadlock conditions from occurring.
- **Deadlock avoidance**: Works by refusing resources requirements which may lead to a deadlock.
  - If starting a process may cause a deadlock, the process will not be started.
  - If an increased resource request by a process nay cause a deadlock, this allocation will not be allowed.

## Question 4

How to prevent deadlock? Give at least two examples.

1. Prevent **Mutual Exclusion**: Shared resources such as read-only files can be accessed concurrently.
2. Prevent **Hold and Wait**: Require that all processes request all resources at one time. This can be wasteful of system resources if a process needs one resource early in its execution and doesn't need some other resource until much later.
3. Prevent **No Preemption**:
   1. When a process is requiring resources, block it and release its resources implicitly.
   2. When a process is requiring resources, blcok the process that has the required resources and release its resources implicitly to the requiring process.
4. Prevent **Circular Wait**
   One way to avoid circular wait is to number all resources, and to require that processes request resources only in strictly ( increasing or decreasing ) order.

## Question 5

Which way does recent UNIX OS choose to deal with deadlock problem, why?

Nothing, because the probability of deadlock is very low, the overhead of dealing with deadlock is expensive.

## Question 6

What data structures you use in your implementation of Banker's algorithms?

1. Map

```c++
#include <map>
using namespace std;
map<string, node*> mp;
```

2. Linked List

```c++
struct node {
    vint *used, *max;
    node *prev, *next;
    bool dealt = false;

    node(const string &name, vint *vec) {
        this->max = vec;
        this->used = new vector<int>(n);
        for (int i = 0; i < n; ++i) {
            this->used->at(i) = 0;
        }

        this->prev = this->next = nullptr;
    }

    ~node() {
        delete (used);
        delete (max);
    }
}
```

Where and why you use them?

1. Map: be used to map name of process to its instance (pointer). It can get the instance by name in `O(logn)`, which is faster than finding by iterator `O(n)`.

2. Linked list: be used to store all living processes. It supports insert and remove operations, which helps to save memory when running for a long time.

Are they optimal for your purpose?

Yes, they are helpful for saving memory and cpu resources.

- Memory: Array and linked-list are both `O(n)`, but linked-list can release memory of terminated process.
- Time: `O(n)` for array and `O(logn)` for map.
