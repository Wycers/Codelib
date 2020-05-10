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

Hit: return the page in the cache.

Miss: If the cache is not full, simply put the required page in the cache. If the cache is full, the page which will be use after the longest time will be removed and the required page will be put into the cache.


## Question 3

Briefly describe the LRU page-replacement algorithm and analyze its algorithm complexity

Hit: move the hit page to the top of the cache and return the hit page.

Miss: If the cache is not full, put the required page to the top of the cache. If the cache is full, remove the most bottom page in the cache and put it at the top of the cache.

## Question 4

Briefly describe the clock algorithm and analyze its algorithm complexity

Hit: return the page in the cache, and set the valid bit for that page into 1.

Miss: If the page which the hand point to have valid bit 1, then set the valid bit into 0 and move the hand to the next page and do the same thing, until the the page which the hand point to is already 0. If the page which the hand point to already have valid bit 0, then put the page here and set the valid bit into 1.

## Question 5

Briefly describe the second-chance algorithm and analyze its algorithm complexity

Hit: if hit in fifo cache, return the hit page. if hit in lru cache, then move the page into fifo, and the earliest page put in the fifo cache will be moved into lru cache.

Miss:If fifo cache is not full then, put the required page to the fifo cache. If fifo cache is full and lru cache not full, then remove the earliest page in fifo cache to lru cache, then put the required page to the fifo cache. If fifo cache is full and lru cache full, remove the most bottom page in the lru cache, and remove the earliest page in fifo cache to lru cache, then put the required page to the fifo cache. 

 algorithm complexity:
 n is the number of coming page, k is the cache size
 time : O(1) to update the cache when one page is coming ,so totally O(n)
 
 space: O(k) to store the cache of the pages
 
