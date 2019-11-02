package net.mooctest;

import org.evosuite.shaded.org.springframework.expression.spel.ast.Ternary;
import org.junit.Test;

import java.util.Iterator;

import static org.junit.Assert.*;


public class TernaryTreeTest {

    @Test(timeout = 4000)
    public void test() {
        assertEquals(null, new TernaryTree<Integer>().getRootNode());
        try {
            new TernaryTree<>().getRootData();
            fail();
        } catch (Exception e) {

        }
        TernaryTree<Integer> ternaryTree = new TernaryTree<Integer>(1);
        assertEquals(1, ternaryTree.getHeight());
        assertEquals(1, ternaryTree.getNumberOfNodes());
        ternaryTree.toString();
        ternaryTree.clear();
        assertTrue(ternaryTree.isEmpty());
        try {
            ternaryTree.getInorderIterator();
            fail();
        } catch (Exception e) {

        }
        ternaryTree = new TernaryTree<Integer>(233);
        ternaryTree.setRootData(new Integer(233));
        ternaryTree.setRootNode(ternaryTree.getRootNode());
        assertEquals(new Integer(233), ternaryTree.getRootData());


        TernaryNode<Integer> gg = new TernaryNode<>();
        assertEquals(null, gg.getData());
        gg.setData(new Integer(233));
        assertEquals(new Integer(233), gg.getData());

        assertFalse(gg.hasLeftChild());
        assertFalse(gg.hasMiddleChild());
        assertFalse(gg.hasRightChild());
        assertTrue(gg.isLeaf());

        TernaryNode<Integer> t = new TernaryNode<>();
        gg.setRightChild(t);
        assertFalse(!gg.hasRightChild());
        assertTrue(!gg.isLeaf());
        assertEquals(2, gg.getNumberOfNodes());
        assertEquals(2, gg.copy().getNumberOfNodes());

        gg.setMiddleChild(t);
        assertFalse(!gg.hasMiddleChild());
        assertTrue(!gg.isLeaf());
        assertEquals(3, gg.getNumberOfNodes());
        assertEquals(3, gg.copy().getNumberOfNodes());

        gg.setLeftChild(t);
        assertFalse(!gg.hasLeftChild());
        assertTrue(!gg.isLeaf());
        assertEquals(4, gg.getNumberOfNodes());
        assertEquals(4, gg.copy().getNumberOfNodes());


    }

    @Test
    public void test2() {
        LinkedQueue<Integer> q = new LinkedQueue<Integer>();
        assertTrue(q.isEmpty());
        try {
            q.getFront();
            fail();
        } catch (Exception e) {

        }
        q.enqueue(new Integer(1));
        assertEquals(new Integer(1), q.getFront());
        assertFalse(q.isEmpty());
        q.enqueue(new Integer(2));

        q.dequeue();
        q.clear();
        assertTrue(q.isEmpty());
    }

    @Test
    public void test3() {
        LinkedStack<Integer> q = new LinkedStack<Integer>();
        assertTrue(q.isEmpty());
        try {
            q.pop();
            fail();
        } catch (Exception e) {

        }
        q.push(new Integer(1));
        assertEquals(new Integer(1), q.pop());
        assertTrue(q.isEmpty());
        q.push(new Integer(2));

        q.clear();
        assertTrue(q.isEmpty());
    }

    @Test(timeout = 4000)
    public void testTree1() {
        TernaryTree<Integer> a = new TernaryTree<Integer>(1);
        TernaryTree<Integer> b = new TernaryTree<Integer>(2);
        TernaryTree<Integer> c = new TernaryTree<Integer>(3);
        TernaryTree<Integer> ternaryTree = new TernaryTree<>();
        ternaryTree.setTree(new Integer(233), null, null, null);
        ternaryTree.setTree(new Integer(233), a, null, null);
        ternaryTree.setTree(new Integer(233), a, null, null);
        assertTrue(a.getRootNode() == null);
        assertTrue(b.getRootNode() != null);
    }

    @Test(timeout = 4000)
    public void testTree2() {
        TernaryTree<Integer> a = new TernaryTree<Integer>(1);
        TernaryTree<Integer> b = new TernaryTree<Integer>(2);
        TernaryTree<Integer> c = new TernaryTree<Integer>(3);
        TernaryTree<Integer> ternaryTree = new TernaryTree<>();
        ternaryTree.setTree(new Integer(233), a, null, null);
        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, null, c);
        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, null, c);

        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, null, a);
        assertTrue(a.getRootNode() == null);
        assertTrue(b.getRootNode() != null);
        assertTrue(c.getRootNode() == null);
    }

    @Test(timeout = 4000)
    public void testTree3() {
        TernaryTree<Integer> a = new TernaryTree<Integer>(1);
        TernaryTree<Integer> b = new TernaryTree<Integer>(2);
        TernaryTree<Integer> c = new TernaryTree<Integer>(3);
        TernaryTree<Integer> ternaryTree = new TernaryTree<>();
        ternaryTree.setTree(new Integer(233), a, null, null);
        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, b, null);
        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, b, null);

        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, a, null);

        a = new TernaryTree<Integer>(1);
        b = new TernaryTree<Integer>(2);
        ternaryTree.setTree(new Integer(233), a, b, a);

        a = new TernaryTree<Integer>(1);
        b = new TernaryTree<Integer>(2);
        ternaryTree.setTree(new Integer(233), a, b, b);

        assertTrue(a.getRootNode() == null);
        assertTrue(b.getRootNode() == null);
    }

    @Test(timeout = 4000)
    public void testTree4() {
        TernaryTree<Integer> a = new TernaryTree<Integer>(1);
        TernaryTree<Integer> b = new TernaryTree<Integer>();
        b.setTree(2);
        assertEquals(new Integer(2), b.getRootData());

        TernaryTree<Integer> ee = new TernaryTree<>(3, a, b, a);
        TernaryTree<Integer> d = new TernaryTree<>(3, a, b, ee);
        TernaryTree<Integer> c = new TernaryTree<Integer>(3, ee, d, b);
        assertTrue(a.getRootNode() == null);
        assertTrue(b.getRootNode() == null);
        Iterator<Integer> itr = c.getPreorderIterator();
        String res = "";
        while (itr.hasNext()) {
            res += itr.next() + " ";
        }
        try {
            itr.next();
            fail();
        } catch (Exception e) {

        }
        try {
            itr.remove();
            fail();
        } catch (Exception e) {

        }
        assertEquals("3 3 3 1 2 1 ", res);
        a.iterativePreorderTraverse();
        b.iterativePreorderTraverse();
        c.iterativePreorderTraverse();
        d.iterativePreorderTraverse();
        ee.iterativePreorderTraverse();


        itr = c.getPostorderIterator();
        res = "";
        while (itr.hasNext()) {
            res += itr.next() + " ";
        }
        try {
            itr.next();
            fail();
        } catch (Exception e) {

        }
        try {
            itr.remove();
            fail();
        } catch (Exception e) {

        }
        assertEquals("1 2 1 3 3 3 ", res);

        itr = c.getLevelOrderIterator();
        res = "";
        while (itr.hasNext()) {
            res += itr.next() + " ";
        }
        try {
            itr.next();
            fail();
        } catch (Exception e) {

        }
        try {
            itr.remove();
            fail();
        } catch (Exception e) {

        }
        assertEquals("3 3 3 1 2 1 ", res);
    }

    @Test(timeout = 4000)
    public void testTree6() {
        TernaryTree<Integer> a = new TernaryTree<Integer>(1);
        TernaryTree<Integer> b = new TernaryTree<Integer>(2);
        TernaryTree<Integer> c = new TernaryTree<Integer>(3);
        TernaryTree<Integer> ternaryTree = new TernaryTree<>();
        ternaryTree.setTree(new Integer(233), null, null, null);
        ternaryTree.setTree(new Integer(233), a, null, null);
        ternaryTree.setTree(new Integer(233), a, null, null);

    }

    @Test(timeout = 4000)
    public void testTree8() {
        TernaryTree<Integer> a = new TernaryTree<Integer>(1);
        TernaryTree<Integer> b = new TernaryTree<Integer>(2);
        TernaryTree<Integer> c = new TernaryTree<Integer>(3);
        TernaryTree<Integer> ternaryTree = new TernaryTree<>();
        ternaryTree.setTree(new Integer(233), a, null, null);
        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, null, c);
        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, null, c);

        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, null, a);
        assertTrue(a.getRootNode() == null);
        assertTrue(b.getRootNode() != null);
        assertTrue(c.getRootNode() == null);
    }

    @Test(timeout = 4000)
    public void testTree7() {
        TernaryTree<Integer> a = new TernaryTree<Integer>(1);
        TernaryTree<Integer> b = new TernaryTree<Integer>(2);
        TernaryTree<Integer> c = new TernaryTree<Integer>(3);
        TernaryTree<Integer> ternaryTree = new TernaryTree<>();
        ternaryTree.setTree(new Integer(233), a, null, null);
        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, b, null);
        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, b, null);

        a = new TernaryTree<Integer>(1);
        ternaryTree.setTree(new Integer(233), a, a, null);

        a = new TernaryTree<Integer>(1);
        b = new TernaryTree<Integer>(2);
        ternaryTree.setTree(new Integer(233), a, b, a);

        a = new TernaryTree<Integer>(1);
        b = new TernaryTree<Integer>(2);
        ternaryTree.setTree(new Integer(233), a, b, b);

        assertTrue(a.getRootNode() == null);
        assertTrue(b.getRootNode() == null);
    }

}
