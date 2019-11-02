package net.mooctest;

import java.util.Iterator;
import java.util.NoSuchElementException;


public class TernaryTree<T> implements TernaryTreeInterface<T> {
    private TernaryNode<T> root;

    public TernaryTree() {
        root = null;
    }

    public TernaryTree(T rootData) {
        root = new TernaryNode<>(rootData);
    }

    public TernaryTree(T rootData, TernaryTree<T> leftTree, TernaryTree<T> middleTree,
                       TernaryTree<T> rightTree) {
        privateSetTree(rootData, leftTree, middleTree, rightTree);
    }

    public void setTree(T rootData) {
        root = new TernaryNode<>(rootData);
    }

    public void setTree(T rootData, TernaryTreeInterface<T> leftTree,
                        TernaryTreeInterface<T> middleTree,
                        TernaryTreeInterface<T> rightTree) {
        privateSetTree(rootData, (TernaryTree<T>) leftTree, (TernaryTree<T>) middleTree, (TernaryTree<T>) rightTree);
    }

    private void privateSetTree(T rootData, TernaryTree<T> leftTree, TernaryTree<T> middleTree,
                                TernaryTree<T> rightTree) {
        root = new TernaryNode<>(rootData);

        if ((leftTree != null) && !leftTree.isEmpty()) {
            root.setLeftChild(leftTree.root);
        }

        if ((rightTree != null) && !rightTree.isEmpty()) {
            if (rightTree != leftTree && rightTree != leftTree) {
                root.setRightChild(rightTree.root);
            } else {
                root.setRightChild(rightTree.root.copy());
            }
        }
        if ((middleTree != null) && !middleTree.isEmpty()) {
            if (middleTree != leftTree && middleTree != rightTree) {
                root.setMiddleChild(middleTree.root);
            } else {
                root.setMiddleChild(middleTree.root.copy());
            }
        }

        if ((leftTree != null) && (leftTree != this)) {
            leftTree.clear();
        }
        if ((middleTree != null) && (middleTree != this)) {
            middleTree.clear();
        }
        if ((rightTree != null) && (rightTree != this)) {
            rightTree.clear();
        }
    }

    public T getRootData() {
        if (isEmpty()) {
            throw new EmptyTreeException();
        } else {
            return root.getData();
        }
    }

    protected void setRootData(T rootData) {
        root.setData(rootData);
    }

    protected void setRootNode(TernaryNode<T> rootNode) {
        root = rootNode;
    }

    protected TernaryNode<T> getRootNode() {
        return root;
    }

    @Override
    public int getHeight() {
        // TODO Auto-generated method stub
        return root.getHeight();
    }

    @Override
    public int getNumberOfNodes() {
        // TODO Auto-generated method stub
        return root.getNumberOfNodes();
    }

    @Override
    public boolean isEmpty() {
        // TODO Auto-generated method stub
        return root == null;
    }

    @Override
    public void clear() {
        // TODO Auto-generated method stub
        root = null;
    }

    @Override
    public Iterator<T> getPreorderIterator() {
        // TODO Auto-generated method stub
        return new PreorderIterator();
    }

    @Override
    public Iterator<T> getPostorderIterator() {
        return new PostorderIterator();
    }

    /*
     * Inorder Iteration not supported. This is due to the iterator needing to access the parent node after evaluating the left child node.
     * This is not doable with the addition of a middle child, which cuts off access to the parent.
     */
    @Override
    public Iterator<T> getInorderIterator() {
        // TODO Auto-generated method stub
        throw new java.lang.UnsupportedOperationException();
    }

    @Override
    public Iterator<T> getLevelOrderIterator() {
        return new LevelOrderIterator();
    }

    private class PreorderIterator implements Iterator<T> {
        private StackInterface<TernaryNode<T>> nodeStack;

        public PreorderIterator() {
            nodeStack = new LinkedStack<>();
            if (root != null) {
                nodeStack.push(root);
            }
        }

        public boolean hasNext() {
            return !nodeStack.isEmpty();
        }

        public T next() {
            TernaryNode<T> nextNode;

            if (hasNext()) {
                nextNode = nodeStack.pop();
                TernaryNode<T> leftChild = nextNode.getLeftChild();
                TernaryNode<T> middleChild = nextNode.getMiddleChild();
                TernaryNode<T> rightChild = nextNode.getRightChild();

                // Push into stack in reverse order of recursive calls
                if (rightChild != null) {
                    nodeStack.push(rightChild);
                }
                if (middleChild != null) {
                    nodeStack.push(middleChild);
                }

                if (leftChild != null) {
                    nodeStack.push(leftChild);
                }
            } else {
                throw new NoSuchElementException();
            }

            return nextNode.getData();
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    public void iterativePreorderTraverse() {
        StackInterface<TernaryNode<T>> nodeStack = new LinkedStack<>();
        if (root != null) {
            nodeStack.push(root);
        }
        TernaryNode<T> nextNode;
        while (!nodeStack.isEmpty()) {
            nextNode = nodeStack.pop();
            TernaryNode<T> leftChild = nextNode.getLeftChild();
            TernaryNode<T> middleChild = nextNode.getMiddleChild();
            TernaryNode<T> rightChild = nextNode.getRightChild();

            // Push into stack in reverse order of recursive calls
            if (rightChild != null) {
                nodeStack.push(rightChild);
            }
            if (middleChild != null) {
                nodeStack.push(middleChild);
            }
            if (leftChild != null) {
                nodeStack.push(leftChild);
            }

            System.out.print(nextNode.getData() + " ");
        }
    }

    private class PostorderIterator implements Iterator<T> {
        private StackInterface<TernaryNode<T>> nodeStack;
        private TernaryNode<T> currentNode;

        public PostorderIterator() {
            nodeStack = new LinkedStack<>();
            currentNode = root;
        }

        public boolean hasNext() {
            return !nodeStack.isEmpty() || (currentNode != null);
        }

        public T next() {
            boolean foundNext = false;
            TernaryNode<T> leftChild, middleChild, rightChild, nextNode = null;

            // Find leftmost leaf
            while (currentNode != null) {
                nodeStack.push(currentNode);
                leftChild = currentNode.getLeftChild();
                if (leftChild == null) {
                    middleChild = currentNode.getMiddleChild();
                    if (middleChild == null) {
                        currentNode = currentNode.getRightChild();
                    } else {
                        currentNode = middleChild;
                    }
                } else {
                    currentNode = leftChild;
                }
            }

            // Stack is not empty either because we just pushed a node, or
            // it wasn't empty to begin with since hasNext() is true.
            // But Iterator specifies an exception for next() in case
            // hasNext() is false.

            if (!nodeStack.isEmpty()) {
                nextNode = nodeStack.pop();
                // nextNode != null since stack was not empty before pop

                TernaryNode<T> parent = null;
                if (!nodeStack.isEmpty()) {
                    parent = nodeStack.peek();
                    if (nextNode == parent.getLeftChild() && parent.getMiddleChild() != null) {
                        currentNode = parent.getMiddleChild();
                    } else if (nextNode != parent.getRightChild()) {
                        currentNode = parent.getRightChild();
                    } else {
                        currentNode = null;
                    }
                } else {
                    currentNode = null;
                }
            } else {
                throw new NoSuchElementException();
            }

            return nextNode.getData();
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    private class LevelOrderIterator implements Iterator<T> {
        private QueueInterface<TernaryNode<T>> nodeQueue;

        public LevelOrderIterator() {
            nodeQueue = new LinkedQueue<>();
            if (root != null) {
                nodeQueue.enqueue(root);
            }
        }

        public boolean hasNext() {
            return !nodeQueue.isEmpty();
        }

        public T next() {
            TernaryNode<T> nextNode;

            if (hasNext()) {
                nextNode = nodeQueue.dequeue();
                TernaryNode<T> leftChild = nextNode.getLeftChild();
                TernaryNode<T> middleChild = nextNode.getMiddleChild();
                TernaryNode<T> rightChild = nextNode.getRightChild();

                // Add to queue in order of recursive calls
                if (leftChild != null) {
                    nodeQueue.enqueue(leftChild);
                }
                if (middleChild != null) {
                    nodeQueue.enqueue(middleChild);
                }
                if (rightChild != null) {
                    nodeQueue.enqueue(rightChild);
                }
            } else {
                throw new NoSuchElementException();
            }

            return nextNode.getData();
        }

        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

}
