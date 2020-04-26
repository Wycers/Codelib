## Question 1

1. What is Uniprogramming:

   Besides system processes, only one process is loaded into memory at a time.

2. What is the shortcoming of Uniprogramming:

   1. Low utilization: unusually, the process would not fully use the memory, which causes resources wasted.
   2. Low efficiency: high overhead of context switching.

## Question 2

1. What is Multiprogramming:

   The memory is allocated to several blocks and multiple programs use memory in different blocks at the same time.

2. What is the shortcoming of Multiprogramming:

   1. For fixed partition, internal fragmentation.
   2. For dynamic partition, internal and external fragmentation, additional overhead before accessing memory.

## Question 3

1. What is the segmentation mechanism?

   Segmentation mechanism is a memory-management mechanism that will devide memory of a process into multiple segments.

2. ... and its advantages & disadvantages:

- Advantages:

  1. Easy to program.
  2. Easy to share.
  3. Easy to protect.

- Disadvantages:

  1. More complicated.
  2. Has overhead of assessing memory.

## Question 4

What is the paging mechanism and its advantages & disadvantages:

- Advantages:

  1. Support processes to occupy discrete memory, which improved memory availability.

- Disadvantages:

  1.  Hardware overhead: Page Table Register is used for speeding up.
  2.  Software overhead: Take up more memory.
  3.  Time overhead: Processes need more time to access memory.

## Question 5

How to reduce the occurrence of internal fragmentation when allocating memory? Briefly explain why this method works.

1. For segmentation, use dynamic segmentation rather than fixed segmentation. It can only allocate the required memory.
2. For paging, decrease the size of the page. The internal fragmentation of a process will appear at the last page of its all pages. So the size of internal fragmentation is about `PAGE_SIZE - MEM_SIZE mod PAGE_SIZE` under the assumption that the page is `PAGE_SIZE` and the memory used is `MEM_SIZE`. If the `MEM_SIZE` is fixed, the smaller the `PAGE_SIZE` is, the smaller the size of internal fragmentation is.

## Question 6

How to reduce the occurrence of external fragmentation when allocating memory? Briefly explain why this method works.

1. For segmentation, use dynamic relocation partition. It will rearrange the all allocated blocks to make them compact arrangement, which cleans external fragmentation.

2. Use paging.
