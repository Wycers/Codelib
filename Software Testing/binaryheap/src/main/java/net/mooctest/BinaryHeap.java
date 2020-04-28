package net.mooctest;

// BinaryHeap class
//
// CONSTRUCTION: with optional capacity (that defaults to 100)
//
// ******************PUBLIC OPERATIONS*********************
// void insert( x )       --> Insert x
// int deleteMin( )--> Return and remove smallest item
// int findMin( )  --> Return smallest item
// boolean isEmpty( )     --> Return true if empty; else false
// boolean isFull( )      --> Return true if full; else false
// void makeEmpty( )      --> Remove all items
// ******************ERRORS********************************
// Throws Overflow if capacity exceeded

/**
 * Implements a binary heap.
 * Note that all "matching" is based on the compareTo method.
 *
 * @author Mark Allen Weiss
 */
public class BinaryHeap {
    //@ invariant wellFormed();

    /**
     * Construct the binary heap.
     */
    public BinaryHeap() {
        this(DEFAULT_CAPACITY);
    }

    /**
     * Construct the binary heap.
     *
     * @param capacity the capacity of the binary heap.
     */
    //@ requires capacity > 0;
    //@ ensures isEmpty();
    public BinaryHeap(int capacity) {
        currentSize = 0;
        array = new int[capacity + 1];
    }

    /**
     * Insert into the priority queue, maintaining heap order.
     * Duplicates are allowed.
     *
     * @param x the item to insert.
     * @throws Overflow if container is full.
     */
    public void insert(int x) throws Overflow {
        if (isFull())
            throw new Overflow();

        // Percolate up
        int hole = ++currentSize;
        for (; hole > 1 && x < array[hole / 2]; hole /= 2)
            array[hole] = array[hole / 2];
        array[hole] = x;
    }

    /**
     * Find the smallest item in the priority queue.
     *
     * @return the smallest item, or null, if empty.
     */
    public int findMin() {
        if (isEmpty())
            return -1;
        return array[1];
    }

    boolean wellFormed() {
        if (array == null) {//array!=null
            return false;
        }
        if (currentSize < 0 || currentSize >= array.length) {//currentSize>=0; currentSize<array.length;
            return false;
        }
        for (int i = 1; i < currentSize; i++) {
            if (i * 2 <= currentSize && array[i] > array[2 * i]) {
                return false;
            }
            if (i * 2 + 1 <= currentSize && array[i] > array[2 * i + 1]) {
                return false;
            }
        }
        return true;
    }

    /**
     * Remove the smallest item from the priority queue.
     *
     * @return the smallest item, or null, if empty.
     */
    public int deleteMin() {
        if (isEmpty())
            return -1;

        int minItem = findMin();
        array[1] = array[currentSize--];
        percolateDown(1);

        return minItem;
    }

    /**
     * Establish heap order property from an arbitrary
     * arrangement of items. Runs in linear time.
     */
    public void buildHeap() {
        for (int i = currentSize / 2; i > 0; i--)
            percolateDown(i);
    }

    /**
     * Test if the priority queue is logically empty.
     *
     * @return true if empty, false otherwise.
     */
    public boolean isEmpty() {
        return currentSize == 0;
    }

    /**
     * Test if the priority queue is logically full.
     *
     * @return true if full, false otherwise.
     */
    public boolean isFull() {
        return currentSize == array.length - 1;
    }

    /**
     * Make the priority queue logically empty.
     */
    //@ ensures isEmpty();
    public void makeEmpty() {
        currentSize = 0;
    }

    private static final int DEFAULT_CAPACITY = 100;

    private int currentSize;      // Number of elements in heap
    private int[] array; // The heap array

    /**
     * Internal method to percolate down in the heap.
     *
     * @param hole the index at which the percolate begins.
     */
    private void percolateDown(int hole) {
        int child;
        int tmp = array[hole];

        for (; hole * 2 <= currentSize; hole = child) {
            child = hole * 2;

            if (child != currentSize &&
                    array[child + 1] < array[child])
                child++;
            if (array[child] < tmp)
                array[hole] = array[child];
            else
                break;
        }
        array[hole] = tmp;
    }


}
