## Question 1

Briefly describe the FIFO page-replacement algorithm and analyze its algorithm complexity

FIFO

Behavior:

Hit: return the page in the cache.

Miss: If the cache is not full, simply put the required page in the cache. If the cache is full, the earliest page put in the cache will be removed and the required page will be put into the cache. 


## Question 2

Briefly describe the MIN page-replacement algorithm and analyze its algorithm complexity.

MIN page-replacement algorithm is a ideal algorithm that needs future information of page required.

In this lab, we can only use an offline approach to implement the algorithm.

Behavior:

## Question 3

Briefly describe the LRU page-replacement algorithm and analyze its algorithm complexity

Hit: move the hit page to the top of the cache and return the hit page.

Miss: If the cache is not full, put the required page to the top of the cache. If the cache is full, remove the most bottom page in the cache and put it at the top of the cache.

## Question 4

Briefly describe the clock algorithm and analyze its algorithm complexity

Hit: 

## Question 5

Briefly describe the second-chance algorithm and analyze its algorithm complexity
