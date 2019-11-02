package net.mooctest;

import java.util.EmptyStackException;

/**
 * A class of stacks whose entries are stored in a chain of nodes.
 * @author Frank M. Carrano
 * @author Timothy M. Henry
 * @author William C. Garrison
 * @version 4.5
 */
public final class LinkedStack<T> implements StackInterface<T> {
    // References the first node in the chain
    private Node topNode;

    public LinkedStack() {
        topNode = null;
    }

    public void push(T newEntry) {
        topNode = new Node(newEntry, topNode);
    }

    public T peek() {
        if (isEmpty()) {
            throw new EmptyStackException();
        } else {
            return topNode.getData();
        }
    }

    public T pop() {
        // Might throw EmptyStackException
        T top = peek();
        assert (topNode != null);
        topNode = topNode.getNextNode();

        return top;
    }

    public boolean isEmpty() {
        return topNode == null;
    }

    public void clear() {
        // Causes deallocation of nodes in the chain
        topNode = null;
    }

    private class Node {
        // Entry in stack
        private T data;
        // Link to next node
        private Node next;

        private Node(T dataPortion) {
            this(dataPortion, null);
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

