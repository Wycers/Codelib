package net.mooctest;

/**
 * An interface of basic methods for the ADT tree.
 * @author Frank M. Carrano
 * @author Timothy M. Henry
 * @author William C. Garrison
 * @version 4.5
 */
public interface TreeInterface<T> {
    /** Gets the data in the root node
     *  @return  the data from the root node
     *  @throws EmptyTreeException  if the tree is empty */
    public T getRootData();

    /** Gets the height of the tree (i.e., the maximum number of nodes passed
     *  through from root to leaf, inclusive)
     *  @return  the height of the tree */
    public int getHeight();

    /** Counts the total number of nodes in the tree
     *  @return  the number of nodes in the tree */
    public int getNumberOfNodes();

    /** Determines whether the tree is empty (i.e., has no nodes)
     *  @return  true if the tree is empty, false otherwise */
    public boolean isEmpty();

    /** Removes all data and nodes from the tree */
    public void clear();
}

