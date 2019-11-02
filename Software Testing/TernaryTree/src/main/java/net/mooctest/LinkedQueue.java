package net.mooctest;

/**
 * A class that implements the ADT queue by using a chain of nodes that has both
 * head and tail references.
 * @author Frank M. Carrano
 * @author Timothy M. Henry
 * @author William C. Garrison
 * @version 4.5
 */
public final class LinkedQueue<T> implements QueueInterface<T> {
    // References node at front of queue
    private Node firstNode;
    // References node at back of queue
    private Node lastNode;

    public LinkedQueue() {
        firstNode = null;
        lastNode = null;
    }

    public void enqueue(T newEntry) {
        Node newNode = new Node(newEntry, null);

        if (isEmpty()) {
            firstNode = newNode;
        } else {
            lastNode.setNextNode(newNode);
        }

        lastNode = newNode;
    }

    public T getFront() {
        if (isEmpty()) {
            throw new EmptyQueueException();
        } else {
            return firstNode.getData();
        }
    }

    public T dequeue() {
        // Might throw EmptyQueueException
        T front = getFront();

        assert firstNode != null;
        firstNode.setData(null);
        firstNode = firstNode.getNextNode();

        if (firstNode == null) {
            lastNode = null;
        }

        return front;
    }

    public boolean isEmpty() {
        return (firstNode == null) && (lastNode == null);
    }

    public void clear() {
        firstNode = null;
        lastNode = null;
    }

    private class Node {
        // Entry in queue
        private T data;
        // Link to next node
        private Node next;

        private Node(T dataPortion) {
            data = dataPortion;
            next = null;
        }

        private Node(T dataPortion, Node linkPortion) {
            data = dataPortion;
            next = linkPortion;
        }

        private T getData() {
            return data;
        }

        private void setData(T newData) {
            data = newData;
        }

        private Node getNextNode() {
            return next;
        }

        private void setNextNode(Node nextNode) {
            next = nextNode;
        }
    }
}

