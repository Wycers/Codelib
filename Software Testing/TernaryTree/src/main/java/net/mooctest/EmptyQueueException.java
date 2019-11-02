package net.mooctest;

/**
 * A class of runtime exceptions thrown by methods to indicate that a queue is
 * empty.
 * @author Frank M. Carrano
 * @author Timothy M. Henry
 * @author William C. Garrison
 * @version 4.5
 */
public class EmptyQueueException extends RuntimeException {
    public EmptyQueueException() {
        this(null);
    }

    public EmptyQueueException(String message) {
        super(message);
    }
}

