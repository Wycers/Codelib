# Assignment3

## Author

11711918 吴烨昌

## Problem 1

### Description

Consider the directed acyclic graph G in Figure 3.10. How many topological orderings does it have?

### Solution

6 topological orderings in total, they are:

1. A - B - C - D - E - F
2. A - B - D - C - E - F
3. A - B - D - E - C - F
4. A - D - E - B - C - F
5. A - D - B - E - C - F
6. A - D - B - C - E - F

## Problem 2

### Description

The algorithm described in Section 3.6 for computing a topological ordering of a DAG repeatedly finds a node with no incoming edges and deletes it. This will eventually produce a topological ordering, provided that the input graph really is a DAG. But suppose that we’re given an arbitrary graph that may or may not be a DAG. Extend the topological ordering algorithm so that, given an input directed graph G, it outputs one of two things: (a) a topological ordering, thus establishing that G is a DAG; or (b) a cycle in G, thus establishing that G is not a DAG. The running time of your algorithm should be O(m+n) for a directed graph with n nodes and m edges.

## Solution

1. for all vertex $i$ in graph $G$, calculate $d_i$ which noted how many edges target it. This part is $O(m)$.
2. for all vertex $i$, if $d_i$ is $0$ which means no edge target it, push i to a queue q. This part is $O(n)$.
3. while q is not empty, pop a vertex $u$ from queue, move $u$ to a output buffer, for every vertex $v$ which there is a edge from $u$ to $v$, decrease $d_v$ by $1$. Meaning that vertex $u$ is removed. If $d_v$ is $0$, push $v$ to $q$. Since every vertex will only be removed once at most and every edge will be used once so the total complexity is $O(n + m)$. 



After that, if the number of vertexes in output buffer is not $n$, there is cycle in $G$($G$ is not a DAG), for vertexes not in output buffer, they must be in a cycle(or cycles), we can use DFS to find the cycle and output them to get a cycle.

Otherwise we just output vertexes in output buffer to get a topological ordering.



And the total complexity is $O(m + n)​$

