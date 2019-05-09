# Assignment5

## Author

11711918 吴烨昌

## Problem 1

### Description

1. You are interested in analyzing some hard-to-obtain data from two separate databases. Each database contains $n$ numerical values—so there are $2n$ values total—and you may assume that no two values are the same. You’d like to determine the median of this set of $2n$ values, which we will define here to be the nth smallest value. However, the only way you can access these values is through queries to the databases. In a single query, you can specify a value $k$ to one of the two databases, and the chosen database will return the $k^{th}$ smallest value that it contains. Since queries are expensive, you would like to compute the median using as few queries as possible. Give an algorithm that finds the median value using at most $O(\log n)$ queries.

### Solution

1. set `l = 0, r = n - 1`
2. cal`mid = (l + r) / 2, mid2 = n - mid - 1`，so that there are $n+1$ elements in a[0]~a[mid] and b[0]~b[mid2] because `mid - 0 + 1 + mid2 - 0 + 1 = n + 1`.
3. if `a[mid] > b[mid2]`, set`r = mid - 1;` else set`l = mid + 1; `
4. repeat step 3 until `l > r`
5. after that the median value is mean value of two maximum from 
$$
{ a[mid], a[mid - 1]\text{(if exists)}, b[n - mid - 1], b[n - mid - 2]\text{(if exists)}}
$$

## Problem 2

### Description

Recall the problem of finding the number of inversions. As in the text, we are given a sequence of $n​$ numbers $a_1,...,a_n​$, which we assume are all distinct, and we define an inversion to be a pair $i < j​$ such that $a_i > a_j​$. We motivated the problem of counting inversions as a good measure of how different two orderings are. However, one might feel that this measure is too sensitive. Let’s call a pair a significant inversion if $i < j​$ and $a_i > 2a_j​$. Give an$ O(n log n)​$ algorithm to count the number of significant inversions between two orderings.

## Solution

Use merge sort like querying for reverse order pair.

While merging two ordered parts`a[0]~a[mid]` and `a[mid + 1]~a[n]`, `p <= mid and q > mid`if we found `a[p] > 2a[q]`, we add `mid - p + 1` to `ans` because if `a[p] > 2a[q]`, `a[p], a[p + 1], ..., a[mid] > 2a[q]`