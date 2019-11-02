package net.mooctest;

/**
 * An interface for the ADT stack.
 * @author Frank M. Carrano
 * @author Timothy M. Henry
 * @author William C. Garrison
 * @version 4.5
 */
public interface StackInterface<T> {
    /** Adds a new entry to the top of this stack.
     *  @param newEntry  An object to be added to the stack */
    public void push(T newEntry);

    /** Removes and returns this stack's top entry.
     *  @return  The object at the top of the stack.
     *  @throws EmptyStackException  if the stack is empty. */
    public T pop();

    /** Retrieves this stack's top entry.
     *  @return  The object at the top of the stack.
     *  @throws EmptyStackException  if the stack is empty. */
    public T peek();

    /** Detects whether this stack is empty.
     *  @return  True if the stack is empty. */
    public boolean isEmpty();

    /** Removes all entries from this stack. */
    public void clear();
}

