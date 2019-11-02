package net.mooctest;

import java.util.Iterator;

/**
 * An interface of iterators for the ADT tree.
 * @author Frank M. Carrano
 * @author Timothy M. Henry
 * @author William C. Garrison
 * @version 4.5
 */
public interface TreeIteratorInterface<T> {
   /** Creates an iterator to traverse the tree in preorder fashion
    *  @return  the iterator */
    public Iterator<T> getPreorderIterator();

   /** Creates an iterator to traverse the tree in postorder fashion
    *  @return  the iterator */
    public Iterator<T> getPostorderIterator();

   /** Creates an iterator to traverse the tree in inorder fashion
    *  @return  the iterator */
    public Iterator<T> getInorderIterator();

   /** Creates an iterator to traverse the tree in level-order fashion
    *  @return  the iterator */
    public Iterator<T> getLevelOrderIterator();
}

