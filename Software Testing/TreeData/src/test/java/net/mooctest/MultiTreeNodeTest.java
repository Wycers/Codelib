package net.mooctest;


import java.util.*;

import org.evosuite.runtime.mock.java.lang.MockThrowable;
import org.junit.Before;
import org.junit.Test;

import org.evosuite.runtime.ViolatedAssumptionAnswer;
import org.junit.Test;

import java.util.function.BiFunction;
import java.util.function.Consumer;
import java.util.stream.Stream;

import static org.evosuite.runtime.EvoAssertions.verifyException;
import static org.evosuite.shaded.org.mockito.Mockito.*;
import static org.junit.Assert.*;


public class MultiTreeNodeTest {


    @Test(timeout = 4000)
    public void xd() throws Throwable {

        LinkedList<LinkedMultiTreeNode<Integer>> linkedList = new LinkedList<LinkedMultiTreeNode<Integer>>();

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode = new LinkedMultiTreeNode<Integer>((Integer) null);

        linkedMultiTreeNode.addSubtrees(linkedList);
    }


    @Test(timeout = 4000)
    public void array_multi_tree_node_test00() throws Throwable {
        Integer integer0 = new Integer(2832);
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0, 1804);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>("yIu!#[md4A");
        arrayMultiTreeNode0.parent = (TreeNode<Object>) arrayMultiTreeNode1;
        // Undeclared exception!
        try {
            arrayMultiTreeNode0.siblings();
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Illegal initial capacity: -1
            //
            verifyException("java.util.HashMap", e);
        }
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test01() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg", 2672);
        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg");
        arrayMultiTreeNode1.add(arrayMultiTreeNode0);
        arrayMultiTreeNode0.siblings();
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test02() throws Throwable {
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>((Object) null);
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode1, 1985);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode2);
        arrayMultiTreeNode0.add(linkedMultiTreeNode0);
        boolean boolean0 = arrayMultiTreeNode0.hasSubtree(linkedMultiTreeNode0);
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test03() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("The specified tree node %1$s was not found in the current tree node %2$s", 1);
        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode0);
        assertFalse(arrayMultiTreeNode0.isRoot());
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test04() throws Throwable {
        Integer integer0 = new Integer(0);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 146);
        // Undeclared exception!
        try {
            arrayMultiTreeNode0.traversePreOrder((TraversalAction<TreeNode<Integer>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test05() throws Throwable {
        Integer integer0 = new Integer(1135);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(integer0, 1);
        // Undeclared exception!
        try {
            arrayMultiTreeNode0.traversePostOrder((TraversalAction<TreeNode<Object>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

//    @Test(timeout = 4000)
//    public void array_multi_tree_node_test06() throws Throwable {
//        Integer integer0 = new Integer(0);
//        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 0);
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode0);
//        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<TreeNode<Object>>(arrayMultiTreeNode1, 0);
//        LinkedList<ArrayMultiTreeNode<Integer>> linkedList0 = new LinkedList<ArrayMultiTreeNode<Integer>>();
//        linkedList0.add(arrayMultiTreeNode0);
//        arrayMultiTreeNode0.addSubtrees(linkedList0);
//        // Undeclared exception!
//        arrayMultiTreeNode2.siblings();
//    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test07() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg", 2672);
        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg");
        arrayMultiTreeNode1.add(arrayMultiTreeNode1);
        boolean boolean0 = arrayMultiTreeNode1.contains(arrayMultiTreeNode0);
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test08() throws Throwable {
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>((Object) null);
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode1, 1985);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode2);
        arrayMultiTreeNode0.add(linkedMultiTreeNode0);
        assertEquals(1, linkedMultiTreeNode0.level());

        boolean boolean0 = arrayMultiTreeNode0.isLeaf();
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test09() throws Throwable {
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode0, 1985);
        boolean boolean0 = arrayMultiTreeNode1.isLeaf();
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test10() throws Throwable {
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode0, 1985);
        arrayMultiTreeNode1.add(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode1.isRoot());

        boolean boolean0 = arrayMultiTreeNode1.dropSubtree(arrayMultiTreeNode1);
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test11() throws Throwable {
        Integer integer0 = new Integer(0);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode0);
        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<TreeNode<Object>>(arrayMultiTreeNode1, 0);
        arrayMultiTreeNode2.iterator();
        assertTrue(arrayMultiTreeNode2.isLeaf());
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test12() throws Throwable {
        Integer integer0 = new Integer(0);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode0);
        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<TreeNode<Object>>(arrayMultiTreeNode1, 0);
        // Undeclared exception!
        try {
            arrayMultiTreeNode2.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +-
            // +-
            // +- 0
            //
            //
            //  is root
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test13() throws Throwable {
        Integer integer0 = new Integer(2672);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 2672);
        LinkedList<MultiTreeNode<Integer>> linkedList0 = new LinkedList<MultiTreeNode<Integer>>();
        boolean boolean0 = arrayMultiTreeNode0.addSubtrees(linkedList0);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test14() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("\n+- 1985\n");
        int int0 = arrayMultiTreeNode0.height();
        assertEquals(0, int0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test15() throws Throwable {
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>((Object) null);
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode1, 1985);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode2);
        arrayMultiTreeNode0.add(linkedMultiTreeNode0);
        assertFalse(linkedMultiTreeNode0.isRoot());

        int int0 = arrayMultiTreeNode0.height();
        assertEquals(1, int0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test16() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("rcGJ%;~s#,=Hdi", 0);
        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("O");
        arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        assertEquals(1, arrayMultiTreeNode1.level());

        arrayMultiTreeNode0.postOrdered();
        assertFalse(arrayMultiTreeNode0.isLeaf());
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test17() throws Throwable {
        Integer integer0 = new Integer(2656);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 2656);
        LinkedList<MultiTreeNode<Integer>> linkedList0 = new LinkedList<MultiTreeNode<Integer>>();
        linkedList0.add((MultiTreeNode<Integer>) arrayMultiTreeNode0);
        arrayMultiTreeNode0.addSubtrees(linkedList0);
        arrayMultiTreeNode0.find(integer0);
        assertFalse(arrayMultiTreeNode0.isRoot());
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test18() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg", 2672);
        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg");
        arrayMultiTreeNode1.add(arrayMultiTreeNode1);
        boolean boolean0 = arrayMultiTreeNode1.remove(arrayMultiTreeNode0);
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test19() throws Throwable {
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode0, 1985);
        boolean boolean0 = arrayMultiTreeNode1.remove(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test20() throws Throwable {
        Integer integer0 = new Integer((-2003));
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode0);
        boolean boolean0 = arrayMultiTreeNode1.remove((TreeNode<MultiTreeNode<Integer>>) null);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test21() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg");
        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("PD1ssrk");
        arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        TreeNode.unlinkParent((TreeNode<String>) arrayMultiTreeNode1);
        // Undeclared exception!
        try {
            arrayMultiTreeNode0.commonAncestor(arrayMultiTreeNode1);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- PD1ssrk
            //  was not found in the current tree node
            // +- $Qk|iiMK1cKJg
            // +- PD1ssrk
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test22() throws Throwable {
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>((Object) null);
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode1, 1985);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode2);
        arrayMultiTreeNode0.add(linkedMultiTreeNode0);
        boolean boolean0 = arrayMultiTreeNode0.contains(linkedMultiTreeNode0);
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test23() throws Throwable {
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>((Object) null);
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode1, 1985);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode2);
        boolean boolean0 = arrayMultiTreeNode0.contains(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test24() throws Throwable {
        Integer integer0 = new Integer((-1));
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 1);
        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>(linkedMultiTreeNode0);
        ArrayMultiTreeNode<ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>>(arrayMultiTreeNode1);
        boolean boolean0 = arrayMultiTreeNode2.contains((TreeNode<ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>>) null);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test25() throws Throwable {
        Integer integer0 = new Integer(2656);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        LinkedList<MultiTreeNode<Integer>> linkedList0 = new LinkedList<MultiTreeNode<Integer>>();
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        linkedList0.add((MultiTreeNode<Integer>) linkedMultiTreeNode0);
        linkedList0.add((MultiTreeNode<Integer>) arrayMultiTreeNode0);
        arrayMultiTreeNode0.addSubtrees(linkedList0);
        boolean boolean0 = arrayMultiTreeNode0.hasSubtree(arrayMultiTreeNode0);
        assertFalse(arrayMultiTreeNode0.isRoot());
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test26() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg", 2672);
        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("$Qk|iiMK1cKJg");
        arrayMultiTreeNode1.add(arrayMultiTreeNode1);
        boolean boolean0 = arrayMultiTreeNode1.hasSubtree(arrayMultiTreeNode0);
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test27() throws Throwable {
        Integer integer0 = new Integer(0);
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(linkedMultiTreeNode0, 0);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode1);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode0);
        boolean boolean0 = arrayMultiTreeNode2.hasSubtree(linkedMultiTreeNode1);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test28() throws Throwable {
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>((Integer) null);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0, 2);
        boolean boolean0 = arrayMultiTreeNode0.hasSubtree((TreeNode<Object>) null);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test29() throws Throwable {
        Integer integer0 = new Integer(2656);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        LinkedList<MultiTreeNode<Integer>> linkedList0 = new LinkedList<MultiTreeNode<Integer>>();
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        linkedList0.add((MultiTreeNode<Integer>) linkedMultiTreeNode0);
        arrayMultiTreeNode0.addSubtrees(linkedList0);
        assertFalse(arrayMultiTreeNode0.isLeaf());

        arrayMultiTreeNode0.clear();
        assertTrue(arrayMultiTreeNode0.isLeaf());
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test30() throws Throwable {
        Integer integer0 = new Integer(0);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode0);
        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<TreeNode<Object>>(arrayMultiTreeNode1, 0);
        arrayMultiTreeNode2.clear();
        assertTrue(arrayMultiTreeNode2.isLeaf());
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test31() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("rcGJ%;~s#,=Hdi", 0);
        arrayMultiTreeNode0.add(arrayMultiTreeNode0);
        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("rcGJ%;~s#,=Hdi");
        arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        boolean boolean0 = arrayMultiTreeNode0.remove(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode0.isRoot());
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test32() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("rcGJ%;~s#,=Hdi", 0);
        arrayMultiTreeNode0.add(arrayMultiTreeNode0);
        arrayMultiTreeNode0.add(arrayMultiTreeNode0);
        assertFalse(arrayMultiTreeNode0.isRoot());

        boolean boolean0 = arrayMultiTreeNode0.remove(arrayMultiTreeNode0);
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test33() throws Throwable {
        Integer integer0 = new Integer(2672);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 2672);
        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>(arrayMultiTreeNode1);
        ArrayMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>>(linkedMultiTreeNode0, 10);
        arrayMultiTreeNode2.add(arrayMultiTreeNode2);
        ArrayMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>> arrayMultiTreeNode3 = new ArrayMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>>(linkedMultiTreeNode0, 10);
        boolean boolean0 = arrayMultiTreeNode2.dropSubtree(arrayMultiTreeNode3);
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test34() throws Throwable {
        Integer integer0 = new Integer(2672);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 2672);
        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>(arrayMultiTreeNode1);
        ArrayMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<Integer>>>>(linkedMultiTreeNode0, 10);
        boolean boolean0 = arrayMultiTreeNode2.dropSubtree(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test35() throws Throwable {
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>("$YdZNu7q/", 0);
        boolean boolean0 = arrayMultiTreeNode0.dropSubtree((TreeNode<Object>) null);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test36() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("rcGJ%;~s#,=Hdi", 0);
        arrayMultiTreeNode0.add(arrayMultiTreeNode0);
        arrayMultiTreeNode0.add(arrayMultiTreeNode0);
        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode0);
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test37() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("3m{G:1p");
        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0);
        boolean boolean0 = arrayMultiTreeNode0.add((TreeNode<LinkedMultiTreeNode<String>>) null);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test38() throws Throwable {
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>((Integer) null);
        arrayMultiTreeNode0.subtrees();
        assertTrue(arrayMultiTreeNode0.isLeaf());
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test39() throws Throwable {
        Integer integer0 = new Integer(2656);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertTrue(arrayMultiTreeNode0.isLeaf());

        LinkedList<MultiTreeNode<Integer>> linkedList0 = new LinkedList<MultiTreeNode<Integer>>();
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        linkedList0.add((MultiTreeNode<Integer>) linkedMultiTreeNode0);
        arrayMultiTreeNode0.addSubtrees(linkedList0);
        arrayMultiTreeNode0.subtrees();
        assertFalse(arrayMultiTreeNode0.isLeaf());
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test40() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = null;
        try {
            arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("", (-14));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void array_multi_tree_node_test41() throws Throwable {
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>((Object) null);
        Integer integer0 = new Integer(1985);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer0);
        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode1, 1985);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode2);
        arrayMultiTreeNode0.add(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode2.isLeaf());

        Consumer<Object> consumer0 = (Consumer<Object>) mock(Consumer.class, new ViolatedAssumptionAnswer());
        arrayMultiTreeNode0.forEach(consumer0);
        assertFalse(arrayMultiTreeNode0.isLeaf());
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test00() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("getkmooct<st.MultiTreeNode");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
        linkedMultiTreeNode0.addSubtrees(linkedList0);
        Collection<? extends MultiTreeNode<Object>> collection0 = linkedMultiTreeNode0.siblings();
        assertNotNull(collection0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test01() throws Throwable {
        Integer integer0 = new Integer(0);
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        // Undeclared exception!
        try {
            linkedMultiTreeNode0.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +- 0
            //  is root
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

//    @Test(timeout = 4000)
//    public void multi_tree_node_test02() throws Throwable {
//        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("net.mooctest.cultiTreeNode");
//        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
//        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
//        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
//        linkedMultiTreeNode0.addSubtrees(linkedList0);
//        // Undeclared exception!
//        linkedMultiTreeNode0.siblings();
//    }

    @Test(timeout = 4000)
    public void multi_tree_node_test03() throws Throwable {
        Object object0 = new Object();
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(object0);
        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(linkedMultiTreeNode0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode0);
        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode1, 1);
        arrayMultiTreeNode2.parent = (TreeNode<MultiTreeNode<Object>>) arrayMultiTreeNode0;
        // Undeclared exception!
        try {
            arrayMultiTreeNode2.siblings();
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Illegal initial capacity: -1
            //
            verifyException("java.util.HashMap", e);
        }
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test04() throws Throwable {
        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>((ArrayMultiTreeNode<String>) null);
        ArrayMultiTreeNode<ArrayMultiTreeNode<String>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<ArrayMultiTreeNode<String>>((ArrayMultiTreeNode<String>) null);
        linkedMultiTreeNode0.parent = (TreeNode<ArrayMultiTreeNode<String>>) arrayMultiTreeNode0;
        // Undeclared exception!
        try {
            linkedMultiTreeNode0.siblings();
            fail("Expecting exception: ClassCastException");

        } catch (ClassCastException e) {
            //
            // no message in exception (getMessage() returned null)
            //
        }
    }

//    @Test(timeout = 4000)
//    public void multi_tree_node_test05() throws Throwable {
//        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("-nKNU*@@WXwEP3)O3");
//        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
//        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
//        LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>(linkedMultiTreeNode0);
//        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode1);
//        linkedList0.addLast(linkedMultiTreeNode0);
//        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
//        linkedMultiTreeNode0.addSubtrees(linkedList0);
//        // Undeclared exception!
//        linkedMultiTreeNode0.hasSubtrees(linkedList0);
//    }

    @Test(timeout = 4000)
    public void multi_tree_node_test06() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("net.mooctest.MultiTreeNode");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedList0);
        linkedList0.add((MultiTreeNode<Object>) arrayMultiTreeNode0);
        // Undeclared exception!
        try {
            linkedMultiTreeNode0.addSubtrees(linkedList0);
            fail("Expecting exception: ClassCastException");

        } catch (ClassCastException e) {
            //
            // net.mooctest.ArrayMultiTreeNode cannot be cast to net.mooctest.LinkedMultiTreeNode
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test07() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("t>");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
        linkedMultiTreeNode0.addSubtrees(linkedList0);
        LinkedList<MultiTreeNode<Object>> linkedList1 = new LinkedList<MultiTreeNode<Object>>();
        LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>(linkedList0);
        linkedList1.add((MultiTreeNode<Object>) linkedMultiTreeNode1);
        boolean boolean0 = linkedMultiTreeNode0.dropSubtrees(linkedList1);
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test08() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("NU@@W&SwEP)yPb3:");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
        linkedList0.addLast(linkedMultiTreeNode0);
        linkedMultiTreeNode0.addSubtrees(linkedList0);
        boolean boolean0 = linkedMultiTreeNode0.dropSubtrees(linkedList0);
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test09() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
        linkedMultiTreeNode0.addSubtrees(linkedList0);
        LinkedList<MultiTreeNode<Object>> linkedList1 = new LinkedList<MultiTreeNode<Object>>();
        boolean boolean0 = linkedMultiTreeNode0.dropSubtrees(linkedList1);
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test10() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("getkmooct<st.MultiTreeNode");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        boolean boolean0 = linkedMultiTreeNode0.dropSubtrees(linkedList0);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test11() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("t>");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
        linkedMultiTreeNode0.addSubtrees(linkedList0);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>(linkedList0);
        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode1);
        boolean boolean0 = linkedMultiTreeNode0.hasSubtrees(linkedList0);
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test12() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
        linkedMultiTreeNode0.addSubtrees(linkedList0);
        LinkedList<MultiTreeNode<Object>> linkedList1 = new LinkedList<MultiTreeNode<Object>>();
        boolean boolean0 = linkedMultiTreeNode0.hasSubtrees(linkedList1);
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test13() throws Throwable {
        Integer integer0 = new Integer(3638);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(integer0);
        boolean boolean0 = linkedMultiTreeNode0.hasSubtrees((Collection<? extends MultiTreeNode<Object>>) null);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test14() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        linkedList0.add((MultiTreeNode<Object>) null);
        linkedList0.addLast(linkedMultiTreeNode0);
        boolean boolean0 = linkedMultiTreeNode0.addSubtrees(linkedList0);
        assertFalse(boolean0);
        assertTrue(linkedMultiTreeNode0.isRoot());
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test15() throws Throwable {
        Integer integer0 = new Integer(3638);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(integer0);
        boolean boolean0 = linkedMultiTreeNode0.addSubtrees((Collection<? extends MultiTreeNode<Object>>) null);
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void multi_tree_node_test16() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
        LinkedList<MultiTreeNode<Object>> linkedList0 = new LinkedList<MultiTreeNode<Object>>();
        linkedList0.add((MultiTreeNode<Object>) linkedMultiTreeNode0);
        linkedMultiTreeNode0.addSubtrees(linkedList0);
        boolean boolean0 = linkedMultiTreeNode0.hasSubtrees(linkedList0);
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertTrue(boolean0);
    }


//    @Test(timeout = 4000)
//    public void tree_node_test000() throws Throwable {
//        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("<\"<tZ");
//        assertNotNull(linkedMultiTreeNode0);
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        Consumer<Object> consumer0 = (Consumer<Object>) mock(Consumer.class, new ViolatedAssumptionAnswer());
//        linkedMultiTreeNode0.forEach(consumer0);
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
//        assertNotNull(arrayMultiTreeNode0);
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
//        assertNotNull(arrayMultiTreeNode1);
//        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//
//        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.root();
//        assertNotNull(treeNode0);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//
//        TreeNode<Object> treeNode1 = arrayMultiTreeNode0.root();
//        assertNotNull(treeNode1);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode1.level());
//        assertTrue(treeNode1.isRoot());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertSame(treeNode1, treeNode0);
//
//        TreeNode.unlinkParent(treeNode1);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode1.level());
//        assertTrue(treeNode1.isRoot());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertSame(treeNode1, treeNode0);
//
//        Spliterator<TreeNode<Object>> spliterator0 = arrayMultiTreeNode0.spliterator();
//        assertNotNull(spliterator0);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//
//        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode1);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertFalse(arrayMultiTreeNode0.isLeaf());
//        assertFalse(arrayMultiTreeNode1.isRoot());
//        assertEquals(1, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
//        assertTrue(boolean0);
//
//        TreeNode<Object> treeNode2 = arrayMultiTreeNode0.find(spliterator0);
//        assertNull(treeNode2);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertFalse(arrayMultiTreeNode0.isLeaf());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//
//        ArrayMultiTreeNode<String> arrayMultiTreeNode2 = new ArrayMultiTreeNode<String>("", 1431655765);
//    }
//
//    @Test(timeout = 4000)
//    public void tree_node_test001() throws Throwable {
//        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("");
//        assertNotNull(arrayMultiTreeNode0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//
//        LinkedList<TreeNode<String>> linkedList0 = new LinkedList<TreeNode<String>>();
//        assertNotNull(linkedList0);
//        assertEquals(0, linkedList0.size());
//
//        boolean boolean0 = arrayMultiTreeNode0.removeAll(linkedList0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedList0.size());
//        assertFalse(boolean0);
//
//        LinkedList<TreeNode<String>> linkedList1 = new LinkedList<TreeNode<String>>();
//        assertNotNull(linkedList1);
//        assertTrue(linkedList1.equals((Object) linkedList0));
//        assertEquals(0, linkedList1.size());
//
//        boolean boolean1 = linkedList1.add((TreeNode<String>) arrayMultiTreeNode0);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertFalse(boolean1 == boolean0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(1, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//        assertTrue(boolean1);
//
//        linkedList1.add(0, (TreeNode<String>) arrayMultiTreeNode0);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(2, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//
//        boolean boolean2 = linkedList1.add((TreeNode<String>) arrayMultiTreeNode0);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertFalse(boolean2 == boolean0);
//        assertTrue(boolean2 == boolean1);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(3, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//        assertTrue(boolean2);
//
//        Stream<TreeNode<String>> stream0 = linkedList1.parallelStream();
//        assertNotNull(stream0);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertEquals(3, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//
//        boolean boolean3 = arrayMultiTreeNode0.containsAll(linkedList1);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertFalse(boolean3 == boolean1);
//        assertTrue(boolean3 == boolean0);
//        assertFalse(boolean3 == boolean2);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(3, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//        assertFalse(boolean3);
//
//        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
//        assertNotNull(linkedMultiTreeNode0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
//        assertNotNull(treeNode_TreeNodeIterator0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = treeNode_TreeNodeIterator0.next();
//        assertNotNull(treeNode0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//
//        Spliterator<TreeNode<ArrayMultiTreeNode<String>>> spliterator0 = treeNode0.spliterator();
//        assertNotNull(spliterator0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//
//        ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode0, 3682);
//        assertNotNull(arrayMultiTreeNode1);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//
//        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode0);
//        assertNotNull(linkedMultiTreeNode1);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode1.isRoot());
//        assertEquals(0, linkedMultiTreeNode1.level());
//        assertTrue(linkedMultiTreeNode1.isLeaf());
//        assertEquals(0, linkedMultiTreeNode1.height());
//
//        boolean boolean4 = linkedMultiTreeNode1.isRoot();
//        assertFalse(boolean4 == boolean3);
//        assertTrue(boolean4 == boolean1);
//        assertFalse(boolean4 == boolean0);
//        assertTrue(boolean4 == boolean2);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode1.isRoot());
//        assertEquals(0, linkedMultiTreeNode1.level());
//        assertTrue(linkedMultiTreeNode1.isLeaf());
//        assertEquals(0, linkedMultiTreeNode1.height());
//        assertTrue(boolean4);
//
//        LinkedList<LinkedMultiTreeNode<String>> linkedList2 = new LinkedList<LinkedMultiTreeNode<String>>();
//        assertNotNull(linkedList2);
//        assertEquals(0, linkedList2.size());
//
//        LinkedMultiTreeNode<String> linkedMultiTreeNode2 = new LinkedMultiTreeNode<String>("");
//        assertNotNull(linkedMultiTreeNode2);
//        assertTrue(linkedMultiTreeNode2.isLeaf());
//        assertEquals(0, linkedMultiTreeNode2.level());
//        assertEquals(0, linkedMultiTreeNode2.height());
//        assertTrue(linkedMultiTreeNode2.isRoot());
//
//        boolean boolean5 = linkedList2.add(linkedMultiTreeNode2);
//        assertTrue(linkedList2.contains(linkedMultiTreeNode2));
//        assertTrue(boolean5 == boolean2);
//        assertFalse(boolean5 == boolean3);
//        assertTrue(boolean5 == boolean4);
//        assertTrue(boolean5 == boolean1);
//        assertFalse(boolean5 == boolean0);
//        assertEquals(1, linkedList2.size());
//        assertTrue(linkedMultiTreeNode2.isLeaf());
//        assertEquals(0, linkedMultiTreeNode2.level());
//        assertEquals(0, linkedMultiTreeNode2.height());
//        assertTrue(linkedMultiTreeNode2.isRoot());
//        assertTrue(boolean5);
//
//        boolean boolean6 = linkedList2.remove((Object) linkedMultiTreeNode1);
//        assertTrue(linkedList2.contains(linkedMultiTreeNode2));
//        assertFalse(boolean6 == boolean1);
//        assertFalse(boolean6 == boolean4);
//        assertTrue(boolean6 == boolean0);
//        assertFalse(boolean6 == boolean2);
//        assertFalse(boolean6 == boolean5);
//        assertTrue(boolean6 == boolean3);
//        assertEquals(1, linkedList2.size());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode1.isRoot());
//        assertEquals(0, linkedMultiTreeNode1.level());
//        assertTrue(linkedMultiTreeNode1.isLeaf());
//        assertEquals(0, linkedMultiTreeNode1.height());
//        assertFalse(boolean6);
//
//        boolean boolean7 = TreeNode.isAnyNotNull((Collection<LinkedMultiTreeNode<String>>) linkedList2);
//        assertTrue(linkedList2.contains(linkedMultiTreeNode2));
//        assertTrue(boolean7 == boolean1);
//        assertFalse(boolean7 == boolean3);
//        assertTrue(boolean7 == boolean5);
//        assertTrue(boolean7 == boolean2);
//        assertFalse(boolean7 == boolean0);
//        assertTrue(boolean7 == boolean4);
//        assertFalse(boolean7 == boolean6);
//        assertEquals(1, linkedList2.size());
//        assertTrue(boolean7);
//
//        LinkedMultiTreeNode<String> linkedMultiTreeNode3 = new LinkedMultiTreeNode<String>("Mr;xJ~X(i");
//        assertNotNull(linkedMultiTreeNode3);
//        assertFalse(linkedMultiTreeNode3.equals((Object) linkedMultiTreeNode2));
//        assertEquals(0, linkedMultiTreeNode3.level());
//        assertTrue(linkedMultiTreeNode3.isRoot());
//        assertTrue(linkedMultiTreeNode3.isLeaf());
//        assertEquals(0, linkedMultiTreeNode3.height());
//
//        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode3);
//        assertNotNull(arrayMultiTreeNode2);
//        assertFalse(linkedMultiTreeNode3.equals((Object) linkedMultiTreeNode2));
//        assertEquals(0, linkedMultiTreeNode3.level());
//        assertTrue(linkedMultiTreeNode3.isRoot());
//        assertTrue(linkedMultiTreeNode3.isLeaf());
//        assertEquals(0, linkedMultiTreeNode3.height());
//        assertTrue(arrayMultiTreeNode2.isLeaf());
//        assertTrue(arrayMultiTreeNode2.isRoot());
//        assertEquals(0, arrayMultiTreeNode2.level());
//
//        Collection<TreeNode<LinkedMultiTreeNode<String>>> collection0 = arrayMultiTreeNode2.postOrdered();
//        assertNotNull(collection0);
//        assertFalse(linkedMultiTreeNode3.equals((Object) linkedMultiTreeNode2));
//        assertEquals(0, linkedMultiTreeNode3.level());
//        assertTrue(linkedMultiTreeNode3.isRoot());
//        assertTrue(linkedMultiTreeNode3.isLeaf());
//        assertEquals(0, linkedMultiTreeNode3.height());
//        assertTrue(arrayMultiTreeNode2.isLeaf());
//        assertTrue(arrayMultiTreeNode2.isRoot());
//        assertEquals(0, arrayMultiTreeNode2.level());
//        assertNotSame(linkedMultiTreeNode3, linkedMultiTreeNode2);
//
//        ArrayMultiTreeNode<ArrayMultiTreeNode<String>> arrayMultiTreeNode3 = new ArrayMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
//        assertNotNull(arrayMultiTreeNode3);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode3.isLeaf());
//        assertTrue(arrayMultiTreeNode3.isRoot());
//        assertEquals(0, arrayMultiTreeNode3.level());
//
//        boolean boolean8 = arrayMultiTreeNode3.add(linkedMultiTreeNode0);
//        assertTrue(boolean8 == boolean1);
//        assertTrue(boolean8 == boolean7);
//        assertFalse(boolean8 == boolean0);
//        assertTrue(boolean8 == boolean5);
//        assertFalse(boolean8 == boolean6);
//        assertTrue(boolean8 == boolean2);
//        assertFalse(boolean8 == boolean3);
//        assertTrue(boolean8 == boolean4);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode3.isRoot());
//        assertEquals(0, arrayMultiTreeNode3.level());
//        assertFalse(arrayMultiTreeNode3.isLeaf());
//        assertFalse(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(1, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(boolean8);
//
//        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = arrayMultiTreeNode3.find(arrayMultiTreeNode0);
//        assertNotNull(treeNode1);
//        assertFalse(treeNode1.equals((Object) treeNode0));
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode3.isRoot());
//        assertEquals(0, arrayMultiTreeNode3.level());
//        assertFalse(arrayMultiTreeNode3.isLeaf());
//        assertEquals(0, treeNode1.level());
//        assertTrue(treeNode1.isRoot());
//
//        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = arrayMultiTreeNode3.iterator();
//        assertNotNull(treeNode_TreeNodeIterator1);
//        assertFalse(treeNode_TreeNodeIterator1.equals((Object) treeNode_TreeNodeIterator0));
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode3.isRoot());
//        assertEquals(0, arrayMultiTreeNode3.level());
//        assertFalse(arrayMultiTreeNode3.isLeaf());
//
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode4 = new ArrayMultiTreeNode<Object>(spliterator0, 1073741824);
//    }
//
//    @Test(timeout = 4000)
//    public void tree_node_test002() throws Throwable {
//        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("<\"<tZ");
//        assertNotNull(linkedMultiTreeNode0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        Consumer<Object> consumer0 = (Consumer<Object>) mock(Consumer.class, new ViolatedAssumptionAnswer());
//        linkedMultiTreeNode0.forEach(consumer0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
//        assertNotNull(arrayMultiTreeNode0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
//        assertNotNull(arrayMultiTreeNode1);
//        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//
//        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.root();
//        assertNotNull(treeNode0);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//
//        TreeNode<Object> treeNode1 = arrayMultiTreeNode0.root();
//        assertNotNull(treeNode1);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode1.level());
//        assertTrue(treeNode1.isRoot());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertSame(treeNode1, treeNode0);
//
//        TreeNode.unlinkParent(treeNode1);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode1.level());
//        assertTrue(treeNode1.isRoot());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertSame(treeNode1, treeNode0);
//
//        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode1);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertFalse(arrayMultiTreeNode0.isLeaf());
//        assertFalse(arrayMultiTreeNode1.isRoot());
//        assertEquals(1, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
//        assertTrue(boolean0);
//
//        long long0 = arrayMultiTreeNode0.size();
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertFalse(arrayMultiTreeNode0.isLeaf());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertEquals(2L, long0);
//
//        Collection<TreeNode<Object>> collection0 = treeNode0.postOrdered();
//        assertTrue(collection0.contains(treeNode0));
//        assertNotNull(collection0);
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertFalse(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertSame(treeNode0, treeNode1);
//
//        boolean boolean1 = arrayMultiTreeNode1.removeAll(collection0);
//        assertTrue(collection0.contains(treeNode0));
//        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
//        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
//        assertFalse(boolean1 == boolean0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertFalse(arrayMultiTreeNode0.isLeaf());
//        assertFalse(arrayMultiTreeNode1.isRoot());
//        assertEquals(1, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
//        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
//        assertSame(treeNode0, treeNode1);
//        assertFalse(boolean1);
//
//        ArrayMultiTreeNode<String> arrayMultiTreeNode2 = new ArrayMultiTreeNode<String>("", 1431655765);
//    }

    @Test(timeout = 4000)
    public void tree_node_test003() throws Throwable {
        int int0 = 0;
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        Collection<? extends TreeNode<Integer>> collection0 = linkedMultiTreeNode0.path((TreeNode<Integer>) null);
        assertNotNull(collection0);
        assertTrue(integer0.equals((Object) int0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        int int1 = linkedMultiTreeNode0.height();
        assertTrue(integer0.equals((Object) int0));
        assertTrue(int1 == int0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, int1);

        LinkedMultiTreeNode<LinkedMultiTreeNode<MultiTreeNode<TreeNode<Object>>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<LinkedMultiTreeNode<MultiTreeNode<TreeNode<Object>>>>((LinkedMultiTreeNode<MultiTreeNode<TreeNode<Object>>>) null);
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());

        TreeNode<LinkedMultiTreeNode<MultiTreeNode<TreeNode<Object>>>> treeNode0 = linkedMultiTreeNode1.clone();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean0 = treeNode0.isLeaf();
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(boolean0);

        treeNode0.clear();
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean1 = linkedMultiTreeNode1.contains(treeNode0);
        assertFalse(boolean1 == boolean0);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertFalse(boolean1);

        boolean boolean2 = linkedMultiTreeNode0.isSiblingOf((TreeNode<Integer>) null);
        assertTrue(integer0.equals((Object) int1));
        assertTrue(integer0.equals((Object) int0));
        assertTrue(boolean2 == boolean1);
        assertFalse(boolean2 == boolean0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertFalse(boolean2);

        TreeNode<Integer> treeNode1 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode1);
        assertTrue(integer0.equals((Object) int1));
        assertTrue(integer0.equals((Object) int0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        boolean boolean3 = treeNode1.add((TreeNode<Integer>) null);
        assertTrue(integer0.equals((Object) int1));
        assertTrue(integer0.equals((Object) int0));
        assertFalse(boolean3 == boolean0);
        assertTrue(boolean3 == boolean1);
        assertTrue(boolean3 == boolean2);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertFalse(boolean3);

        long long0 = linkedMultiTreeNode0.size();
        assertTrue(integer0.equals((Object) int1));
        assertTrue(integer0.equals((Object) int0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1L, long0);

        LinkedMultiTreeNode<String> linkedMultiTreeNode2 = new LinkedMultiTreeNode<String>(")JHj8i0wYX cA~J");
        assertNotNull(linkedMultiTreeNode2);
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());

        LinkedMultiTreeNode<String> linkedMultiTreeNode3 = new LinkedMultiTreeNode<String>(")JHj8i0wYX cA~J");
        assertNotNull(linkedMultiTreeNode3);
        assertFalse(linkedMultiTreeNode3.equals((Object) linkedMultiTreeNode2));
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());

        // Undeclared exception!
        try {
            linkedMultiTreeNode2.commonAncestor(linkedMultiTreeNode3);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- )JHj8i0wYX cA~J
            //  was not found in the current tree node
            // +- )JHj8i0wYX cA~J
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test004() throws Throwable {
        Integer integer0 = new Integer(2);
        assertNotNull(integer0);
        assertEquals(2, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        int int0 = linkedMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, int0);

        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());

        boolean boolean0 = arrayMultiTreeNode0.isLeaf();
        assertFalse(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(boolean0);

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertFalse(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        assertFalse(linkedList0.contains(2));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = arrayMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator1);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(treeNode_TreeNodeIterator1.equals((Object) treeNode_TreeNodeIterator0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());

        boolean boolean1 = TreeNode.areAllNulls((Collection<Object>) linkedList0);
        assertFalse(linkedList0.contains(2));
        assertTrue(boolean1 == boolean0);
        assertEquals(0, linkedList0.size());
        assertTrue(boolean1);

        boolean boolean2 = linkedMultiTreeNode0.contains(arrayMultiTreeNode1);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(boolean2 == boolean0);
        assertFalse(boolean2 == boolean1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertFalse(boolean2);

        TreeNode<ArrayMultiTreeNode<Integer>> treeNode0 = linkedMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertFalse(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Integer>(integer0, 277);
        assertNotNull(arrayMultiTreeNode2);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());

        boolean boolean3 = arrayMultiTreeNode2.contains(arrayMultiTreeNode0);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertFalse(boolean3 == boolean1);
        assertTrue(boolean3 == boolean2);
        assertFalse(boolean3 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode0);
        assertFalse(boolean3);

        boolean boolean4 = arrayMultiTreeNode0.add(arrayMultiTreeNode2);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertFalse(boolean4 == boolean3);
        assertTrue(boolean4 == boolean1);
        assertFalse(boolean4 == boolean2);
        assertTrue(boolean4 == boolean0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertEquals(1, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode0);
        assertTrue(boolean4);

        boolean boolean5 = linkedMultiTreeNode0.hasSubtree(treeNode0);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertFalse(boolean5 == boolean0);
        assertFalse(boolean5 == boolean1);
        assertTrue(boolean5 == boolean3);
        assertFalse(boolean5 == boolean4);
        assertTrue(boolean5 == boolean2);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
        assertFalse(boolean5);

        ArrayMultiTreeNode<String> arrayMultiTreeNode3 = new ArrayMultiTreeNode<String>("an.g^A8LC/3:Q!F", 0);
        assertNotNull(arrayMultiTreeNode3);
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.level());

        ArrayMultiTreeNode<String> arrayMultiTreeNode4 = new ArrayMultiTreeNode<String>("an.g^A8LC/3:Q!F");
        assertNotNull(arrayMultiTreeNode4);
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode3));
        assertEquals(0, arrayMultiTreeNode4.level());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertTrue(arrayMultiTreeNode4.isLeaf());

        arrayMultiTreeNode3.parent = (TreeNode<String>) arrayMultiTreeNode4;
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(1, arrayMultiTreeNode3.level());
        assertFalse(arrayMultiTreeNode3.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.parent.level());
        assertTrue(arrayMultiTreeNode3.parent.isRoot());

        Collection<? extends TreeNode<Integer>> collection0 = arrayMultiTreeNode0.path(arrayMultiTreeNode2);
        assertNotNull(collection0);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertEquals(1, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode0);

        TreeNode<String> treeNode1 = arrayMultiTreeNode3.clone();
        assertNotNull(treeNode1);
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode4));
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(1, arrayMultiTreeNode3.level());
        assertFalse(arrayMultiTreeNode3.isRoot());
        assertFalse(treeNode1.isRoot());
        assertEquals(1, treeNode1.level());
        assertNotSame(arrayMultiTreeNode3, arrayMultiTreeNode4);

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator2 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator2);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);

        Collection<? extends TreeNode<String>> collection1 = arrayMultiTreeNode3.parent.path(arrayMultiTreeNode4);
        assertNotNull(collection1);
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode4));
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode3));
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(1, arrayMultiTreeNode3.level());
        assertFalse(arrayMultiTreeNode3.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertNotSame(arrayMultiTreeNode3, arrayMultiTreeNode4);
        assertNotSame(arrayMultiTreeNode4, arrayMultiTreeNode3);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode5 = new ArrayMultiTreeNode<Object>(linkedList0, 1321);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertNotNull(arrayMultiTreeNode5);
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, linkedList0.size());

        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode6 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode5);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertNotNull(arrayMultiTreeNode6);
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, linkedList0.size());
        assertTrue(arrayMultiTreeNode6.isLeaf());
        assertTrue(arrayMultiTreeNode6.isRoot());
        assertEquals(0, arrayMultiTreeNode6.level());

        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode7 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode5);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertNotNull(arrayMultiTreeNode7);
        assertFalse(arrayMultiTreeNode7.equals((Object) arrayMultiTreeNode6));
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, linkedList0.size());
        assertTrue(arrayMultiTreeNode7.isRoot());
        assertEquals(0, arrayMultiTreeNode7.level());
        assertTrue(arrayMultiTreeNode7.isLeaf());

        boolean boolean6 = arrayMultiTreeNode6.contains(arrayMultiTreeNode7);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertFalse(arrayMultiTreeNode6.equals((Object) arrayMultiTreeNode7));
        assertFalse(arrayMultiTreeNode7.equals((Object) arrayMultiTreeNode6));
        assertTrue(boolean6 == boolean3);
        assertFalse(boolean6 == boolean4);
        assertTrue(boolean6 == boolean2);
        assertFalse(boolean6 == boolean0);
        assertTrue(boolean6 == boolean5);
        assertFalse(boolean6 == boolean1);
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, linkedList0.size());
        assertTrue(arrayMultiTreeNode6.isLeaf());
        assertTrue(arrayMultiTreeNode6.isRoot());
        assertEquals(0, arrayMultiTreeNode6.level());
        assertTrue(arrayMultiTreeNode7.isRoot());
        assertEquals(0, arrayMultiTreeNode7.level());
        assertTrue(arrayMultiTreeNode7.isLeaf());
        assertNotSame(arrayMultiTreeNode6, arrayMultiTreeNode7);
        assertNotSame(arrayMultiTreeNode7, arrayMultiTreeNode6);
        assertFalse(boolean6);

        ArrayMultiTreeNode<ArrayMultiTreeNode<Object>> arrayMultiTreeNode8 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Object>>(arrayMultiTreeNode5, 1321);
        assertFalse(linkedList0.contains(1321));
        assertNotNull(arrayMultiTreeNode8);
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, linkedList0.size());
        assertTrue(arrayMultiTreeNode8.isLeaf());
        assertEquals(0, arrayMultiTreeNode8.level());
        assertTrue(arrayMultiTreeNode8.isRoot());

        int int1 = treeNode1.level();
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode4));
        assertFalse(int1 == int0);
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(1, arrayMultiTreeNode3.level());
        assertFalse(arrayMultiTreeNode3.isRoot());
        assertFalse(treeNode1.isRoot());
        assertEquals(1, treeNode1.level());
        assertNotSame(arrayMultiTreeNode3, arrayMultiTreeNode4);
        assertEquals(1, int1);

        Collection<TreeNode<Integer>> collection2 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection2);
        assertFalse(integer0.equals((Object) int1));
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
    }

    @Test(timeout = 4000)
    public void tree_node_test005() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("<\"<tZ");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());

        Consumer<Object> consumer0 = (Consumer<Object>) mock(Consumer.class, new ViolatedAssumptionAnswer());
        linkedMultiTreeNode0.forEach(consumer0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
        assertTrue(boolean0);

        TreeNode<Object> treeNode0 = arrayMultiTreeNode1.commonAncestor(arrayMultiTreeNode1);
        assertNotNull(treeNode0);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
    }

    @Test(timeout = 4000)
    public void tree_node_test006() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("KlLjDTWfi,yoAsUm~Z");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        TreeNode<String> treeNode0 = linkedMultiTreeNode0.find("KlLjDTWfi,yoAsUm~Z");
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        treeNode0.clear();
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>((Integer) null, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        boolean boolean0 = arrayMultiTreeNode0.isLeaf();
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(boolean0);

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<Integer> treeNode1 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode1);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        Integer integer1 = new Integer(0);
        assertNotNull(integer1);
        assertTrue(integer1.equals((Object) integer0));
        assertEquals(0, (int) integer1);

        Collection<? extends TreeNode<Integer>> collection0 = treeNode1.findAll(integer1);
        assertNotNull(collection0);
        assertTrue(integer1.equals((Object) integer0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Failed to remove the tree node. The tree node
            // +- null
            //  is root
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test007() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("net.mooctest.MultiTreeNode");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<LinkedMultiTreeNode<String>> treeNode0 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean0 = arrayMultiTreeNode0.remove(treeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertFalse(boolean0);

        TreeNode<LinkedMultiTreeNode<String>> treeNode1 = arrayMultiTreeNode0.root();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode1, treeNode0);

        ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>((TreeNode<ArrayMultiTreeNode<String>>) null);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        TreeNode<TreeNode<ArrayMultiTreeNode<String>>> treeNode2 = arrayMultiTreeNode1.root();
        assertNotNull(treeNode2);
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());

        TreeNode<TreeNode<ArrayMultiTreeNode<String>>> treeNode3 = treeNode2.parent;
        assertNull(treeNode3);

        TreeNode.linkParent((TreeNode<TreeNode<ArrayMultiTreeNode<String>>>) null, (TreeNode<TreeNode<ArrayMultiTreeNode<String>>>) null);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Object>(treeNode0);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());

        TreeNode.linkParent((TreeNode<Object>) arrayMultiTreeNode2, (TreeNode<Object>) arrayMultiTreeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertNotSame(treeNode0, treeNode1);
    }

    @Test(timeout = 4000)
    public void tree_node_test008() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("<\"<tZ");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        TreeNode.linkParent((TreeNode<LinkedMultiTreeNode<TreeNode<Object>>>) null, (TreeNode<LinkedMultiTreeNode<TreeNode<Object>>>) null);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());

        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
        assertTrue(boolean0);

        // Undeclared exception!
        try {
            arrayMultiTreeNode0.commonAncestor(arrayMultiTreeNode1);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The tree node
            // +-
            // +- <\"<tZ
            //
            // |  +-
            // +- <\"<tZ
            //
            //  is root
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test009() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("");
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        LinkedList<TreeNode<String>> linkedList0 = new LinkedList<TreeNode<String>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean0 = arrayMultiTreeNode0.removeAll(linkedList0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedList0.size());
        assertFalse(boolean0);

        LinkedList<TreeNode<String>> linkedList1 = new LinkedList<TreeNode<String>>();
        assertNotNull(linkedList1);
        assertTrue(linkedList1.equals((Object) linkedList0));
        assertEquals(0, linkedList1.size());

        boolean boolean1 = linkedList1.add((TreeNode<String>) arrayMultiTreeNode0);
        assertFalse(linkedList1.equals((Object) linkedList0));
        assertFalse(boolean1 == boolean0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(1, linkedList1.size());
        assertNotSame(linkedList1, linkedList0);
        assertTrue(boolean1);

        boolean boolean2 = linkedList1.add((TreeNode<String>) arrayMultiTreeNode0);
        assertFalse(linkedList1.equals((Object) linkedList0));
        assertTrue(boolean2 == boolean1);
        assertFalse(boolean2 == boolean0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(2, linkedList1.size());
        assertNotSame(linkedList1, linkedList0);
        assertTrue(boolean2);

        Stream<TreeNode<String>> stream0 = linkedList1.parallelStream();
        assertNotNull(stream0);
        assertFalse(linkedList1.equals((Object) linkedList0));
        assertEquals(2, linkedList1.size());
        assertNotSame(linkedList1, linkedList0);

        boolean boolean3 = arrayMultiTreeNode0.containsAll(linkedList1);
        assertFalse(linkedList1.equals((Object) linkedList0));
        assertTrue(boolean3 == boolean0);
        assertFalse(boolean3 == boolean1);
        assertFalse(boolean3 == boolean2);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(2, linkedList1.size());
        assertNotSame(linkedList1, linkedList0);
        assertFalse(boolean3);

        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        Spliterator<TreeNode<ArrayMultiTreeNode<String>>> spliterator0 = treeNode0.spliterator();
        assertNotNull(spliterator0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode0, 3682);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        TreeNode<TreeNode<ArrayMultiTreeNode<String>>> treeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode0);
        assertNotNull(treeNode1);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());

        boolean boolean4 = treeNode1.isRoot();
        assertTrue(boolean4 == boolean2);
        assertFalse(boolean4 == boolean0);
        assertTrue(boolean4 == boolean1);
        assertFalse(boolean4 == boolean3);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(boolean4);

        LinkedList<LinkedMultiTreeNode<String>> linkedList2 = new LinkedList<LinkedMultiTreeNode<String>>();
        assertNotNull(linkedList2);
        assertEquals(0, linkedList2.size());

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("");
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());

        boolean boolean5 = linkedList2.add(linkedMultiTreeNode1);
        assertTrue(linkedList2.contains(linkedMultiTreeNode1));
        assertTrue(boolean5 == boolean2);
        assertFalse(boolean5 == boolean3);
        assertTrue(boolean5 == boolean1);
        assertTrue(boolean5 == boolean4);
        assertFalse(boolean5 == boolean0);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(1, linkedList2.size());
        assertTrue(boolean5);

        boolean boolean6 = linkedList2.remove((Object) treeNode1);
        assertTrue(linkedList2.contains(linkedMultiTreeNode1));
        assertFalse(boolean6 == boolean2);
        assertTrue(boolean6 == boolean0);
        assertFalse(boolean6 == boolean5);
        assertTrue(boolean6 == boolean3);
        assertFalse(boolean6 == boolean1);
        assertFalse(boolean6 == boolean4);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertEquals(1, linkedList2.size());
        assertFalse(boolean6);

        boolean boolean7 = TreeNode.isAnyNotNull((Collection<LinkedMultiTreeNode<String>>) linkedList2);
        assertTrue(linkedList2.contains(linkedMultiTreeNode1));
        assertFalse(boolean7 == boolean6);
        assertFalse(boolean7 == boolean3);
        assertFalse(boolean7 == boolean0);
        assertTrue(boolean7 == boolean5);
        assertTrue(boolean7 == boolean1);
        assertTrue(boolean7 == boolean4);
        assertTrue(boolean7 == boolean2);
        assertEquals(1, linkedList2.size());
        assertTrue(boolean7);

        LinkedMultiTreeNode<String> linkedMultiTreeNode2 = new LinkedMultiTreeNode<String>("Mr;xJ~X(i");
        assertNotNull(linkedMultiTreeNode2);
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode2);
        assertNotNull(arrayMultiTreeNode2);
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());

        Collection<TreeNode<LinkedMultiTreeNode<String>>> collection0 = arrayMultiTreeNode2.postOrdered();
        assertNotNull(collection0);
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertNotSame(linkedMultiTreeNode2, linkedMultiTreeNode1);

        ArrayMultiTreeNode<ArrayMultiTreeNode<String>> arrayMultiTreeNode3 = new ArrayMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode3);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());

        TreeNode<ArrayMultiTreeNode<String>> treeNode2 = arrayMultiTreeNode3.find(arrayMultiTreeNode0);
        assertNotNull(treeNode2);
        assertFalse(treeNode2.equals((Object) treeNode0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = arrayMultiTreeNode3.iterator();
        assertNotNull(treeNode_TreeNodeIterator1);
        assertFalse(treeNode_TreeNodeIterator1.equals((Object) treeNode_TreeNodeIterator0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
    }

    @Test(timeout = 4000)
    public void tree_node_test010() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>((Object) null);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode<Object> treeNode0 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean0 = treeNode0.dropSubtree(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertFalse(boolean0);

        LinkedList<String> linkedList0 = new LinkedList<String>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean1 = linkedList0.add((String) null);
        assertFalse(boolean1 == boolean0);
        assertEquals(1, linkedList0.size());
        assertTrue(boolean1);

        boolean boolean2 = TreeNode.areAllNulls((Collection<String>) linkedList0);
        assertTrue(boolean2 == boolean1);
        assertFalse(boolean2 == boolean0);
        assertEquals(1, linkedList0.size());
        assertTrue(boolean2);

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = null;
        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>((ArrayMultiTreeNode<String>) null);
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        LinkedList<TreeNode<LinkedMultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<LinkedMultiTreeNode<Integer>>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        TraversalAction<TreeNode<LinkedMultiTreeNode<Integer>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<LinkedMultiTreeNode<Integer>>>) linkedList1);
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList1.size());

        ArrayMultiTreeNode<MultiTreeNode<String>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<String>>((MultiTreeNode<String>) null);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        TreeNode<MultiTreeNode<String>> treeNode1 = arrayMultiTreeNode1.root();
        assertNotNull(treeNode1);
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        // Undeclared exception!
        try {
            treeNode1.commonAncestor(arrayMultiTreeNode1);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- null
            //  was not found in the current tree node
            // +- null
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test011() throws Throwable {
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>((Integer) null);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());

        long long0 = arrayMultiTreeNode0.size();
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(1L, long0);

        Integer integer0 = new Integer(2);
        assertNotNull(integer0);
        assertEquals(2, (int) integer0);

        TreeNode<Integer> treeNode0 = arrayMultiTreeNode0.find(integer0);
        assertNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());

        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0, 1174);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Integer>((Integer) null);
        assertNotNull(arrayMultiTreeNode2);
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());

        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode2);
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertEquals(1, arrayMultiTreeNode2.level());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode0);
        assertTrue(boolean0);

        // Undeclared exception!
        try {
            arrayMultiTreeNode2.commonAncestor(arrayMultiTreeNode0);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- null
            // |  +- null
            //  was not found in the current tree node
            // +- null
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test012() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("_`");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("_`", 1);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        linkedMultiTreeNode0.parent = (TreeNode<String>) arrayMultiTreeNode0;
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.parent.level());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode<String> treeNode0 = linkedMultiTreeNode0.find("_`");
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1, treeNode0.level());
        assertFalse(treeNode0.isRoot());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // Failed to remove the tree node. The iteration has not been performed yet
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test013() throws Throwable {
        Object object0 = new Object();
        assertNotNull(object0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(object0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        boolean boolean0 = treeNode0.hasSubtree(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertFalse(boolean0);

        TreeNode<Object> treeNode1 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode1, treeNode0);

        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<TreeNode<Object>>(treeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());

        Spliterator<TreeNode<Object>> spliterator0 = arrayMultiTreeNode0.spliterator();
        assertNotNull(spliterator0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        Integer integer0 = new Integer(4930);
        assertNotNull(integer0);
        assertEquals(4930, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Integer>(integer0, 4930);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());

        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode3 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode2);
        assertNotNull(arrayMultiTreeNode3);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());

        TreeNode<TreeNode<Object>> treeNode2 = linkedMultiTreeNode0.find(treeNode1);
        assertNotNull(treeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        Collection<? extends TreeNode<TreeNode<Object>>> collection0 = linkedMultiTreeNode0.path(treeNode2);
        assertNotNull(collection0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode4 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode4);
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode2));
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());

        boolean boolean1 = arrayMultiTreeNode2.isSiblingOf(arrayMultiTreeNode4);
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode4));
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode2));
        assertTrue(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode4);
        assertNotSame(arrayMultiTreeNode4, arrayMultiTreeNode2);
        assertFalse(boolean1);

        int int0 = arrayMultiTreeNode1.height();
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertEquals(0, int0);

        TreeNode<Object> treeNode3 = arrayMultiTreeNode0.find(treeNode0);
        assertNull(treeNode3);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertNotSame(treeNode0, treeNode1);

        // Undeclared exception!
        try {
            arrayMultiTreeNode0.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +- java.lang.Object@37a42cf1
            //  is root
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test014() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("_`");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("_`", 1);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        linkedMultiTreeNode0.parent = (TreeNode<String>) arrayMultiTreeNode0;
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());
        assertEquals(0, linkedMultiTreeNode0.parent.level());

        boolean boolean0 = linkedMultiTreeNode0.isDescendantOf(arrayMultiTreeNode0);
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(boolean0);

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode<String> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertFalse(treeNode0.isRoot());
        assertEquals(1, treeNode0.level());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Failed to remove the tree node. The starting node can't be removed
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test015() throws Throwable {
        String string0 = "pd#^qY/QTs cE>&";
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("pd#^qY/QTs cE>&");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        Collection<? extends TreeNode<Integer>> collection0 = arrayMultiTreeNode0.subtrees();
        assertNotNull(collection0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        int int0 = arrayMultiTreeNode0.height();
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, int0);

        TreeNode<String> treeNode0 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        boolean boolean0 = linkedMultiTreeNode0.isSiblingOf(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertFalse(boolean0);

        LinkedList<TreeNode<String>> linkedList0 = new LinkedList<TreeNode<String>>();
        assertFalse(linkedList0.contains(treeNode0));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean1 = treeNode0.removeAll(linkedList0);
        assertFalse(linkedList0.contains(treeNode0));
        assertTrue(boolean1 == boolean0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, linkedList0.size());
        assertFalse(boolean1);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(treeNode0, 1816);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        ArrayMultiTreeNode<Object> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode2);
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode1));
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());

        boolean boolean2 = arrayMultiTreeNode2.add(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode1));
        assertFalse(boolean2 == boolean0);
        assertFalse(boolean2 == boolean1);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertFalse(arrayMultiTreeNode2.isLeaf());
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode2);
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode1);
        assertTrue(boolean2);

        boolean boolean3 = arrayMultiTreeNode1.isAncestorOf(arrayMultiTreeNode2);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode1));
        assertTrue(boolean3 == boolean1);
        assertTrue(boolean3 == boolean0);
        assertFalse(boolean3 == boolean2);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertFalse(arrayMultiTreeNode2.isLeaf());
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode2);
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode1);
        assertFalse(boolean3);

        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<Object>>(arrayMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode1);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode2));
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = linkedMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator1);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode2));
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode2);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode3 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode1);
        assertNotNull(arrayMultiTreeNode3);
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode1));
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode2));
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());

        LinkedList<TreeNode<Integer>> linkedList1 = new LinkedList<TreeNode<Integer>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        boolean boolean4 = arrayMultiTreeNode0.removeAll(linkedList1);
        assertTrue(boolean4 == boolean1);
        assertTrue(boolean4 == boolean3);
        assertFalse(boolean4 == boolean2);
        assertTrue(boolean4 == boolean0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, linkedList1.size());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(boolean4);

        // Undeclared exception!
        try {
            arrayMultiTreeNode3.commonAncestor(arrayMultiTreeNode1);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +-
            // +- pd#^qY/QTs cE>&
            //
            //  was not found in the current tree node
            // +-
            // +-
            // +-
            // +- pd#^qY/QTs cE>&
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test016() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("SY~Z{W", 1130);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = treeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        boolean boolean0 = treeNode1.dropSubtree(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean0);

        boolean boolean1 = treeNode0.isAncestorOf(treeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean1);

        boolean boolean2 = linkedMultiTreeNode0.isAncestorOf(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(boolean2 == boolean0);
        assertTrue(boolean2 == boolean1);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertNotSame(treeNode0, treeNode1);
        assertFalse(boolean2);

        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode1);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int0);

        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        assertFalse(linkedList0.contains(1130));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean3 = linkedMultiTreeNode1.hasSubtree((TreeNode<TreeNode<ArrayMultiTreeNode<String>>>) null);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(boolean3 == boolean2);
        assertTrue(boolean3 == boolean1);
        assertTrue(boolean3 == boolean0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean3);

        LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        TraversalAction<TreeNode<ArrayMultiTreeNode<Integer>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<ArrayMultiTreeNode<Integer>>>) linkedList1);
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList1.size());

        LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertTrue(linkedMultiTreeNode2.isLeaf());

        boolean boolean4 = linkedMultiTreeNode2.isLeaf();
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(boolean4 == boolean0);
        assertFalse(boolean4 == boolean1);
        assertFalse(boolean4 == boolean2);
        assertFalse(boolean4 == boolean3);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertTrue(boolean4);

        LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode3 = new LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode3);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        boolean boolean5 = linkedMultiTreeNode3.isAncestorOf((TreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>) null);
        assertFalse(boolean5 == boolean4);
        assertTrue(boolean5 == boolean1);
        assertTrue(boolean5 == boolean0);
        assertTrue(boolean5 == boolean2);
        assertTrue(boolean5 == boolean3);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean5);

        boolean boolean6 = linkedMultiTreeNode3.equals(treeNode1);
        assertFalse(boolean6 == boolean4);
        assertTrue(boolean6 == boolean5);
        assertTrue(boolean6 == boolean3);
        assertTrue(boolean6 == boolean0);
        assertTrue(boolean6 == boolean1);
        assertTrue(boolean6 == boolean2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean6);

        boolean boolean7 = treeNode0.dropSubtree(linkedMultiTreeNode0);
        assertTrue(boolean7 == boolean1);
        assertTrue(boolean7 == boolean6);
        assertFalse(boolean7 == boolean4);
        assertTrue(boolean7 == boolean5);
        assertTrue(boolean7 == boolean0);
        assertTrue(boolean7 == boolean3);
        assertTrue(boolean7 == boolean2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertNotSame(treeNode0, treeNode1);
        assertFalse(boolean7);

        LinkedList<TreeNode<String>> linkedList2 = new LinkedList<TreeNode<String>>();
        assertNotNull(linkedList2);
        assertEquals(0, linkedList2.size());

        boolean boolean8 = linkedList2.add((TreeNode<String>) arrayMultiTreeNode0);
        assertFalse(boolean8 == boolean0);
        assertFalse(boolean8 == boolean3);
        assertTrue(boolean8 == boolean4);
        assertFalse(boolean8 == boolean2);
        assertFalse(boolean8 == boolean1);
        assertFalse(boolean8 == boolean6);
        assertFalse(boolean8 == boolean5);
        assertFalse(boolean8 == boolean7);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(1, linkedList2.size());
        assertTrue(boolean8);

        TraversalAction<TreeNode<String>> traversalAction1 = TreeNode.populateAction((Collection<TreeNode<String>>) linkedList2);
        assertNotNull(traversalAction1);
        assertEquals(1, linkedList2.size());

        int int1 = arrayMultiTreeNode0.height();
        assertTrue(int1 == int0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int1);

        Collection<TreeNode<String>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
    }

    @Test(timeout = 4000)
    public void tree_node_test017() throws Throwable {
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode<Object> treeNode0 = linkedMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<TreeNode<Object>>(treeNode0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(arrayMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());

        LinkedMultiTreeNode<MultiTreeNode<Object>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<MultiTreeNode<Object>>(linkedMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());

        TreeNode<MultiTreeNode<Object>> treeNode1 = linkedMultiTreeNode1.parent();
        assertNull(treeNode1);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());

        boolean boolean0 = linkedMultiTreeNode1.isAncestorOf((TreeNode<MultiTreeNode<Object>>) null);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertFalse(boolean0);

        ArrayMultiTreeNode<String> arrayMultiTreeNode2 = new ArrayMultiTreeNode<String>("The specified tree node %1$s was not found in the current tree node %2$s", 0);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());

        ArrayMultiTreeNode<Object> arrayMultiTreeNode3 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode2);
        assertNotNull(arrayMultiTreeNode3);
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());

        LinkedMultiTreeNode<ArrayMultiTreeNode<Object>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Object>>(arrayMultiTreeNode3);
        assertNotNull(linkedMultiTreeNode2);
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());

        boolean boolean1 = linkedMultiTreeNode2.isLeaf();
        assertFalse(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(boolean1);
    }

    @Test(timeout = 4000)
    public void tree_node_test018() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("_`");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("_`");
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        linkedMultiTreeNode0.parent = (TreeNode<String>) arrayMultiTreeNode0;
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.parent.level());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());

        TreeNode<String> treeNode0 = linkedMultiTreeNode0.parent();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // Failed to remove the tree node. The iteration has not been performed yet
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

//    @Test(timeout = 4000)
//    public void tree_node_test019() throws Throwable {
//        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("1Wa&{");
//        assertNotNull(arrayMultiTreeNode0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//
//        LinkedList<TreeNode<String>> linkedList0 = new LinkedList<TreeNode<String>>();
//        assertNotNull(linkedList0);
//        assertEquals(0, linkedList0.size());
//
//        boolean boolean0 = arrayMultiTreeNode0.removeAll(linkedList0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedList0.size());
//        assertFalse(boolean0);
//
//        LinkedList<TreeNode<String>> linkedList1 = new LinkedList<TreeNode<String>>();
//        assertNotNull(linkedList1);
//        assertTrue(linkedList1.equals((Object) linkedList0));
//        assertEquals(0, linkedList1.size());
//
//        boolean boolean1 = linkedList1.add((TreeNode<String>) arrayMultiTreeNode0);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertFalse(boolean1 == boolean0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(1, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//        assertTrue(boolean1);
//
//        boolean boolean2 = linkedList1.add((TreeNode<String>) arrayMultiTreeNode0);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertFalse(boolean2 == boolean0);
//        assertTrue(boolean2 == boolean1);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(2, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//        assertTrue(boolean2);
//
//        Stream<TreeNode<String>> stream0 = linkedList1.parallelStream();
//        assertNotNull(stream0);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertEquals(2, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//
//        boolean boolean3 = arrayMultiTreeNode0.containsAll(linkedList1);
//        assertFalse(linkedList1.equals((Object) linkedList0));
//        assertTrue(boolean3 == boolean0);
//        assertFalse(boolean3 == boolean2);
//        assertFalse(boolean3 == boolean1);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(2, linkedList1.size());
//        assertNotSame(linkedList1, linkedList0);
//        assertFalse(boolean3);
//
//        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
//        assertNotNull(linkedMultiTreeNode0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//
//        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
//        assertNotNull(treeNode_TreeNodeIterator0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//
//        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = treeNode_TreeNodeIterator0.next();
//        assertNotNull(treeNode0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//
//        Spliterator<TreeNode<ArrayMultiTreeNode<String>>> spliterator0 = treeNode0.spliterator();
//        assertNotNull(spliterator0);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//
//        ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode0, 3682);
//        assertNotNull(arrayMultiTreeNode1);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//
//        TreeNode<TreeNode<ArrayMultiTreeNode<String>>> treeNode1 = arrayMultiTreeNode1.clone();
//        assertNotNull(treeNode1);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertEquals(0, treeNode1.level());
//        assertTrue(treeNode1.isRoot());
//
//        treeNode1.parent = (TreeNode<TreeNode<ArrayMultiTreeNode<String>>>) arrayMultiTreeNode1;
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertEquals(1, treeNode1.level());
//        assertFalse(treeNode1.isRoot());
//        assertTrue(treeNode1.parent.isRoot());
//        assertEquals(0, treeNode1.parent.level());
//
//        boolean boolean4 = treeNode1.isRoot();
//        assertFalse(boolean4 == boolean2);
//        assertTrue(boolean4 == boolean0);
//        assertFalse(boolean4 == boolean1);
//        assertTrue(boolean4 == boolean3);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertEquals(1, treeNode1.level());
//        assertFalse(treeNode1.isRoot());
//        assertFalse(boolean4);
//
//        LinkedList<LinkedMultiTreeNode<String>> linkedList2 = new LinkedList<LinkedMultiTreeNode<String>>();
//        assertNotNull(linkedList2);
//        assertEquals(0, linkedList2.size());
//
//        boolean boolean5 = linkedList2.remove((Object) treeNode1);
//        assertFalse(boolean5 == boolean2);
//        assertTrue(boolean5 == boolean4);
//        assertTrue(boolean5 == boolean0);
//        assertTrue(boolean5 == boolean3);
//        assertFalse(boolean5 == boolean1);
//        assertEquals(0, linkedList2.size());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertEquals(1, treeNode1.level());
//        assertFalse(treeNode1.isRoot());
//        assertFalse(boolean5);
//
//        boolean boolean6 = TreeNode.isAnyNotNull((Collection<LinkedMultiTreeNode<String>>) linkedList2);
//        assertFalse(boolean6 == boolean1);
//        assertTrue(boolean6 == boolean4);
//        assertFalse(boolean6 == boolean2);
//        assertTrue(boolean6 == boolean5);
//        assertTrue(boolean6 == boolean3);
//        assertTrue(boolean6 == boolean0);
//        assertEquals(0, linkedList2.size());
//        assertFalse(boolean6);
//
//        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("Mr;xJ~X(i");
//        assertNotNull(linkedMultiTreeNode1);
//        assertEquals(0, linkedMultiTreeNode1.level());
//        assertTrue(linkedMultiTreeNode1.isRoot());
//        assertTrue(linkedMultiTreeNode1.isLeaf());
//        assertEquals(0, linkedMultiTreeNode1.height());
//
//        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode1);
//        assertNotNull(arrayMultiTreeNode2);
//        assertEquals(0, linkedMultiTreeNode1.level());
//        assertTrue(linkedMultiTreeNode1.isRoot());
//        assertTrue(linkedMultiTreeNode1.isLeaf());
//        assertEquals(0, linkedMultiTreeNode1.height());
//        assertTrue(arrayMultiTreeNode2.isLeaf());
//        assertTrue(arrayMultiTreeNode2.isRoot());
//        assertEquals(0, arrayMultiTreeNode2.level());
//
//        Collection<TreeNode<LinkedMultiTreeNode<String>>> collection0 = arrayMultiTreeNode2.postOrdered();
//        assertNotNull(collection0);
//        assertEquals(0, linkedMultiTreeNode1.level());
//        assertTrue(linkedMultiTreeNode1.isRoot());
//        assertTrue(linkedMultiTreeNode1.isLeaf());
//        assertEquals(0, linkedMultiTreeNode1.height());
//        assertTrue(arrayMultiTreeNode2.isLeaf());
//        assertTrue(arrayMultiTreeNode2.isRoot());
//        assertEquals(0, arrayMultiTreeNode2.level());
//
//        ArrayMultiTreeNode<ArrayMultiTreeNode<String>> arrayMultiTreeNode3 = new ArrayMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
//        assertNotNull(arrayMultiTreeNode3);
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode3.isLeaf());
//        assertTrue(arrayMultiTreeNode3.isRoot());
//        assertEquals(0, arrayMultiTreeNode3.level());
//
//        TreeNode<ArrayMultiTreeNode<String>> treeNode2 = arrayMultiTreeNode3.find(arrayMultiTreeNode0);
//        assertNotNull(treeNode2);
//        assertFalse(treeNode2.equals((Object) treeNode0));
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode3.isLeaf());
//        assertTrue(arrayMultiTreeNode3.isRoot());
//        assertEquals(0, arrayMultiTreeNode3.level());
//        assertTrue(treeNode2.isRoot());
//        assertEquals(0, treeNode2.level());
//
//        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = arrayMultiTreeNode3.iterator();
//        assertNotNull(treeNode_TreeNodeIterator1);
//        assertFalse(treeNode_TreeNodeIterator1.equals((Object) treeNode_TreeNodeIterator0));
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode3.isLeaf());
//        assertTrue(arrayMultiTreeNode3.isRoot());
//        assertEquals(0, arrayMultiTreeNode3.level());
//
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode4 = new ArrayMultiTreeNode<Object>("", 2147483645);
//    }

    @Test(timeout = 4000)
    public void tree_node_test020() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("SY~Z{W", 1080);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = treeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        boolean boolean0 = linkedMultiTreeNode0.add(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertTrue(boolean0);

        boolean boolean1 = treeNode0.isAncestorOf(treeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean1);

        boolean boolean2 = linkedMultiTreeNode0.isAncestorOf(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(boolean2 == boolean1);
        assertFalse(boolean2 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertFalse(boolean2);

        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode1);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int0);

        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        assertFalse(linkedList0.contains(1080));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean3 = linkedMultiTreeNode1.hasSubtree((TreeNode<TreeNode<ArrayMultiTreeNode<String>>>) null);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(boolean3 == boolean1);
        assertFalse(boolean3 == boolean0);
        assertTrue(boolean3 == boolean2);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean3);

        LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        TraversalAction<TreeNode<ArrayMultiTreeNode<Integer>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<ArrayMultiTreeNode<Integer>>>) linkedList1);
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList1.size());

        LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isLeaf());

        boolean boolean4 = linkedMultiTreeNode2.isLeaf();
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(boolean4 == boolean0);
        assertFalse(boolean4 == boolean2);
        assertFalse(boolean4 == boolean3);
        assertFalse(boolean4 == boolean1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertTrue(boolean4);

        LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode3 = new LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode3);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());

        boolean boolean5 = linkedMultiTreeNode3.equals(treeNode1);
        assertTrue(boolean5 == boolean2);
        assertTrue(boolean5 == boolean1);
        assertTrue(boolean5 == boolean3);
        assertFalse(boolean5 == boolean0);
        assertFalse(boolean5 == boolean4);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean5);

        boolean boolean6 = treeNode0.dropSubtree(linkedMultiTreeNode0);
        assertFalse(boolean6 == boolean2);
        assertTrue(boolean6 == boolean4);
        assertFalse(boolean6 == boolean5);
        assertFalse(boolean6 == boolean3);
        assertFalse(boolean6 == boolean1);
        assertTrue(boolean6 == boolean0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertNotSame(treeNode0, treeNode1);
        assertTrue(boolean6);

        LinkedList<TreeNode<String>> linkedList2 = new LinkedList<TreeNode<String>>();
        assertNotNull(linkedList2);
        assertEquals(0, linkedList2.size());

        boolean boolean7 = linkedList2.add((TreeNode<String>) arrayMultiTreeNode0);
        assertTrue(boolean7 == boolean6);
        assertTrue(boolean7 == boolean0);
        assertFalse(boolean7 == boolean1);
        assertFalse(boolean7 == boolean2);
        assertFalse(boolean7 == boolean3);
        assertTrue(boolean7 == boolean4);
        assertFalse(boolean7 == boolean5);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(1, linkedList2.size());
        assertTrue(boolean7);

        TraversalAction<TreeNode<String>> traversalAction1 = TreeNode.populateAction((Collection<TreeNode<String>>) linkedList2);
        assertNotNull(traversalAction1);
        assertEquals(1, linkedList2.size());

        int int1 = arrayMultiTreeNode0.height();
        assertTrue(int1 == int0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int1);

        Collection<TreeNode<String>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
    }

    @Test(timeout = 4000)
    public void tree_node_test021() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("SY~Z{W", 1130);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = treeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        boolean boolean0 = treeNode1.dropSubtree(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean0);

        boolean boolean1 = treeNode0.isAncestorOf(treeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean1);

        boolean boolean2 = treeNode0.add(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertFalse(boolean2 == boolean1);
        assertFalse(boolean2 == boolean0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertTrue(boolean2);

        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode1);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, int0);

        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        assertFalse(linkedList0.contains("SY~Z{W"));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        TraversalAction<TreeNode<ArrayMultiTreeNode<Integer>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<ArrayMultiTreeNode<Integer>>>) linkedList1);
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList1.size());

        LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.level());

        LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode3 = new LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode3);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(linkedMultiTreeNode3.equals((Object) linkedMultiTreeNode2));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.height());

        boolean boolean3 = linkedMultiTreeNode2.dropSubtree(linkedMultiTreeNode3);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode3));
        assertFalse(linkedMultiTreeNode3.equals((Object) linkedMultiTreeNode2));
        assertFalse(boolean3 == boolean2);
        assertTrue(boolean3 == boolean0);
        assertTrue(boolean3 == boolean1);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertNotSame(linkedMultiTreeNode2, linkedMultiTreeNode3);
        assertNotSame(linkedMultiTreeNode3, linkedMultiTreeNode2);
        assertFalse(boolean3);

        boolean boolean4 = linkedMultiTreeNode2.isLeaf();
        assertFalse(boolean4 == boolean3);
        assertTrue(boolean4 == boolean2);
        assertFalse(boolean4 == boolean1);
        assertFalse(boolean4 == boolean0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode3));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertNotSame(linkedMultiTreeNode2, linkedMultiTreeNode3);
        assertTrue(boolean4);

        LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode4 = new LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode4);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode4.level());
        assertTrue(linkedMultiTreeNode4.isRoot());
        assertEquals(0, linkedMultiTreeNode4.height());
        assertTrue(linkedMultiTreeNode4.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());

        boolean boolean5 = linkedMultiTreeNode4.equals(treeNode1);
        assertTrue(boolean5 == boolean3);
        assertFalse(boolean5 == boolean2);
        assertTrue(boolean5 == boolean1);
        assertTrue(boolean5 == boolean0);
        assertFalse(boolean5 == boolean4);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode4.level());
        assertTrue(linkedMultiTreeNode4.isRoot());
        assertEquals(0, linkedMultiTreeNode4.height());
        assertTrue(linkedMultiTreeNode4.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean5);

        boolean boolean6 = treeNode0.dropSubtree(linkedMultiTreeNode0);
        assertTrue(boolean6 == boolean4);
        assertFalse(boolean6 == boolean1);
        assertFalse(boolean6 == boolean5);
        assertFalse(boolean6 == boolean3);
        assertTrue(boolean6 == boolean2);
        assertFalse(boolean6 == boolean0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertNotSame(treeNode0, treeNode1);
        assertTrue(boolean6);

        LinkedList<TreeNode<String>> linkedList2 = new LinkedList<TreeNode<String>>();
        assertNotNull(linkedList2);
        assertEquals(0, linkedList2.size());

        boolean boolean7 = linkedList2.add((TreeNode<String>) arrayMultiTreeNode0);
        assertTrue(boolean7 == boolean6);
        assertFalse(boolean7 == boolean1);
        assertTrue(boolean7 == boolean4);
        assertFalse(boolean7 == boolean5);
        assertTrue(boolean7 == boolean2);
        assertFalse(boolean7 == boolean0);
        assertFalse(boolean7 == boolean3);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(1, linkedList2.size());
        assertTrue(boolean7);

        TraversalAction<TreeNode<String>> traversalAction1 = TreeNode.populateAction((Collection<TreeNode<String>>) linkedList2);
        assertNotNull(traversalAction1);
        assertEquals(1, linkedList2.size());

        int int1 = arrayMultiTreeNode0.height();
        assertTrue(int1 == int0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, int1);

        Collection<TreeNode<String>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
    }

    @Test(timeout = 4000)
    public void tree_node_test022() throws Throwable {
        int int0 = (-1792);
        Integer integer0 = new Integer((-1792));
        assertNotNull(integer0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals((-1792), (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        boolean boolean0 = linkedMultiTreeNode0.hasSubtree(arrayMultiTreeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(boolean0);

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("");
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        Collection<TreeNode<Integer>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertTrue(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        boolean boolean1 = TreeNode.isAnyNotNull(collection0);
        assertTrue(integer0.equals((Object) int0));
        assertFalse(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(boolean1);

        boolean boolean2 = arrayMultiTreeNode0.remove(linkedMultiTreeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertFalse(boolean2 == boolean1);
        assertTrue(boolean2 == boolean0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(boolean2);

        boolean boolean3 = linkedMultiTreeNode1.remove((TreeNode<String>) null);
        assertTrue(boolean3 == boolean0);
        assertFalse(boolean3 == boolean1);
        assertTrue(boolean3 == boolean2);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertFalse(boolean3);

        LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>> linkedList0 = new LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        TreeNode<ArrayMultiTreeNode<Integer>> treeNode0 = arrayMultiTreeNode1.root();
        assertNotNull(treeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        // Undeclared exception!
        try {
            linkedList0.add((-1792), treeNode0);
            fail("Expecting exception: IndexOutOfBoundsException");

        } catch (IndexOutOfBoundsException e) {
            //
            // Index: -1792, Size: 0
            //
            verifyException("java.util.LinkedList", e);
        }
    }

//    @Test(timeout = 4000)
//    public void tree_node_test023() throws Throwable {
//        Integer integer0 = new Integer(1304);
//        assertNotNull(integer0);
//        assertEquals(1304, (int) integer0);
//
//        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 1304);
//        assertNotNull(arrayMultiTreeNode0);
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//
//        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
//        assertNotNull(arrayMultiTreeNode1);
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//
//        arrayMultiTreeNode1.clear();
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//
//        boolean boolean0 = arrayMultiTreeNode0.equals(integer0);
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertFalse(boolean0);
//
//        ArrayMultiTreeNode<String> arrayMultiTreeNode2 = new ArrayMultiTreeNode<String>("");
//        assertNotNull(arrayMultiTreeNode2);
//        assertTrue(arrayMultiTreeNode2.isLeaf());
//        assertTrue(arrayMultiTreeNode2.isRoot());
//        assertEquals(0, arrayMultiTreeNode2.level());
//
//        ArrayMultiTreeNode<String> arrayMultiTreeNode3 = new ArrayMultiTreeNode<String>("");
//        assertNotNull(arrayMultiTreeNode3);
//        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode2));
//        assertTrue(arrayMultiTreeNode3.isRoot());
//        assertTrue(arrayMultiTreeNode3.isLeaf());
//        assertEquals(0, arrayMultiTreeNode3.level());
//
//        boolean boolean1 = arrayMultiTreeNode2.isLeaf();
//        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode3));
//        assertFalse(boolean1 == boolean0);
//        assertTrue(arrayMultiTreeNode2.isLeaf());
//        assertTrue(arrayMultiTreeNode2.isRoot());
//        assertEquals(0, arrayMultiTreeNode2.level());
//        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode3);
//        assertTrue(boolean1);
//
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode4 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode1, 1304);
//        assertNotNull(arrayMultiTreeNode4);
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode4.isLeaf());
//        assertTrue(arrayMultiTreeNode4.isRoot());
//        assertEquals(0, arrayMultiTreeNode4.level());
//
//        ArrayMultiTreeNode<ArrayMultiTreeNode<Object>> arrayMultiTreeNode5 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Object>>(arrayMultiTreeNode4);
//        assertNotNull(arrayMultiTreeNode5);
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode4.isLeaf());
//        assertTrue(arrayMultiTreeNode4.isRoot());
//        assertEquals(0, arrayMultiTreeNode4.level());
//        assertTrue(arrayMultiTreeNode5.isLeaf());
//        assertTrue(arrayMultiTreeNode5.isRoot());
//        assertEquals(0, arrayMultiTreeNode5.level());
//
//        String string0 = arrayMultiTreeNode5.toString();
//        assertNotNull(string0);
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode4.isLeaf());
//        assertTrue(arrayMultiTreeNode4.isRoot());
//        assertEquals(0, arrayMultiTreeNode4.level());
//        assertTrue(arrayMultiTreeNode5.isLeaf());
//        assertTrue(arrayMultiTreeNode5.isRoot());
//        assertEquals(0, arrayMultiTreeNode5.level());
//        assertEquals("\n+- \n+- \n+- \n+- 1304\n\n\n\n", string0);
//
//        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("\n+- \n+- \n+- \n+- 1304\n\n\n\n");
//        assertNotNull(linkedMultiTreeNode0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//
//        TreeNode<String> treeNode0 = arrayMultiTreeNode2.root();
//        assertNotNull(treeNode0);
//        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode3));
//        assertTrue(arrayMultiTreeNode2.isLeaf());
//        assertTrue(arrayMultiTreeNode2.isRoot());
//        assertEquals(0, arrayMultiTreeNode2.level());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode3);
//
//        boolean boolean2 = linkedMultiTreeNode0.dropSubtree(treeNode0);
//        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode3));
//        assertFalse(boolean2 == boolean1);
//        assertTrue(boolean2 == boolean0);
//        assertTrue(arrayMultiTreeNode2.isLeaf());
//        assertTrue(arrayMultiTreeNode2.isRoot());
//        assertEquals(0, arrayMultiTreeNode2.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, treeNode0.level());
//        assertTrue(treeNode0.isRoot());
//        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode3);
//        assertFalse(boolean2);
//
//        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode6 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>((MultiTreeNode<TreeNode<Object>>) null, 2147483645);
//    }

    @Test(timeout = 4000)
    public void tree_node_test024() throws Throwable {
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>((Integer) null);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0, 1094);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        LinkedList<TreeNode<LinkedMultiTreeNode<Integer>>> linkedList0 = new LinkedList<TreeNode<LinkedMultiTreeNode<Integer>>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = null;
        ArrayMultiTreeNode<LinkedMultiTreeNode<Integer>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<Integer>>((LinkedMultiTreeNode<Integer>) null, 1094);
        assertNotNull(arrayMultiTreeNode2);
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());

        TreeNode<LinkedMultiTreeNode<Integer>> treeNode0 = arrayMultiTreeNode2.root();
        assertNotNull(treeNode0);
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        TreeNode<LinkedMultiTreeNode<Integer>> treeNode1 = arrayMultiTreeNode2.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode1, treeNode0);

        boolean boolean0 = treeNode1.isAncestorOf(arrayMultiTreeNode2);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean0);

        boolean boolean1 = treeNode1.add(arrayMultiTreeNode2);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(boolean1 == boolean0);
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertEquals(1, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode1, treeNode0);
        assertTrue(boolean1);

        TreeNode<LinkedMultiTreeNode<Integer>> treeNode2 = treeNode0.clone();
        assertNotNull(treeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode2.equals((Object) treeNode1));
        assertTrue(treeNode2.equals((Object) treeNode0));
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertEquals(1, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(1, treeNode0.level());
        assertEquals(1, treeNode2.level());
        assertFalse(treeNode2.isRoot());
        assertNotSame(treeNode0, treeNode2);
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode2, treeNode0);
        assertNotSame(treeNode2, treeNode1);

        boolean boolean2 = linkedList0.add(treeNode2);
        assertTrue(linkedList0.contains(treeNode2));
        assertTrue(treeNode0.equals((Object) treeNode2));
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode2.equals((Object) treeNode1));
        assertTrue(treeNode2.equals((Object) treeNode0));
        assertTrue(boolean2 == boolean1);
        assertFalse(boolean2 == boolean0);
        assertEquals(1, linkedList0.size());
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertEquals(1, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertEquals(1, treeNode0.level());
        assertEquals(1, treeNode2.level());
        assertFalse(treeNode2.isRoot());
        assertNotSame(treeNode0, treeNode2);
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode2, treeNode0);
        assertNotSame(treeNode2, treeNode1);
        assertTrue(boolean2);

        TraversalAction<TreeNode<LinkedMultiTreeNode<Integer>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<LinkedMultiTreeNode<Integer>>>) linkedList0);
        assertTrue(linkedList0.contains(treeNode2));
        assertNotNull(traversalAction0);
        assertEquals(1, linkedList0.size());

        Collection<? extends TreeNode<Integer>> collection0 = arrayMultiTreeNode0.subtrees();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        // Undeclared exception!
        try {
            arrayMultiTreeNode0.traversePostOrder((TraversalAction<TreeNode<Integer>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test025() throws Throwable {
        Integer integer0 = new Integer(1);
        assertNotNull(integer0);
        assertEquals(1, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode<Integer> treeNode0 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean0 = treeNode0.isRoot();
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(boolean0);

        ArrayMultiTreeNode<LinkedMultiTreeNode<Integer>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<LinkedMultiTreeNode<Integer>>(linkedMultiTreeNode0, 32);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, int0);

        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("o?UJymKu.=", 32);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());

        ArrayMultiTreeNode<ArrayMultiTreeNode<String>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode1);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());

        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = arrayMultiTreeNode2.find(arrayMultiTreeNode1);
        assertNotNull(treeNode1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        boolean boolean1 = treeNode1.isRoot();
        assertTrue(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(boolean1);
    }

    @Test(timeout = 4000)
    public void tree_node_test026() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("Unable to build the path between tree nodes. ", 1848);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        int int0 = arrayMultiTreeNode0.level();
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, int0);
    }

    @Test(timeout = 4000)
    public void tree_node_test027() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("", 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        Collection<TreeNode<String>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        String string0 = arrayMultiTreeNode0.toString();
        assertNotNull(string0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals("\n+- \n", string0);

        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("net.mooctest.ArrayMultiTreeNode");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0, 0);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        Collection<? extends TreeNode<String>> collection1 = linkedMultiTreeNode0.findAll("net.mooctest.ArrayMultiTreeNode");
        assertNotNull(collection1);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        linkedMultiTreeNode0.setData("");
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        int int0 = arrayMultiTreeNode1.height();
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, int0);

        boolean boolean0 = arrayMultiTreeNode1.add(arrayMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertFalse(arrayMultiTreeNode1.isLeaf());
        assertTrue(boolean0);

        TreeNode<LinkedMultiTreeNode<String>> treeNode0 = arrayMultiTreeNode1.clone();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertFalse(arrayMultiTreeNode1.isLeaf());
        assertFalse(treeNode0.isRoot());

        boolean boolean1 = treeNode0.hasSubtree(arrayMultiTreeNode1);
        assertTrue(boolean1 == boolean0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertFalse(arrayMultiTreeNode1.isLeaf());
        assertFalse(treeNode0.isRoot());
        assertTrue(boolean1);
    }

    @Test(timeout = 4000)
    public void tree_node_test028() throws Throwable {
        String string0 = "_`";
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("_`");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("_`", 1);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        linkedMultiTreeNode0.parent = (TreeNode<String>) arrayMultiTreeNode0;
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());
        assertEquals(0, linkedMultiTreeNode0.parent.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());

        TreeNode<String> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(1, treeNode0.level());
        assertFalse(treeNode0.isRoot());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Failed to remove the tree node. The starting node can't be removed
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test029() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>(":g,");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        TreeNode<String> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        Object object0 = treeNode0.data();
        assertNotNull(object0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(":g,", object0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = null;
        try {
            arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(":g,", (-1083));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test030() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("net.mooctest.MultiTreeNode");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        TreeNode<String> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        TreeNode<String> treeNode1 = treeNode0.find("net.mooctest.MultiTreeNode");
        assertNotNull(treeNode1);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertSame(treeNode0, treeNode1);
        assertSame(treeNode1, treeNode0);

        // Undeclared exception!
        try {
            treeNode1.traversePostOrder((TraversalAction<TreeNode<String>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test031() throws Throwable {
        Integer integer0 = new Integer((-5));
        assertNotNull(integer0);
        assertEquals((-5), (int) integer0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        Collection<TreeNode<Object>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.find(integer0);
        assertNotNull(treeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        TreeNode<Object> treeNode1 = arrayMultiTreeNode0.parent;
        assertNull(treeNode1);

        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<Object>>(treeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        boolean boolean0 = arrayMultiTreeNode0.containsAll(collection0);
        assertTrue(collection0.contains(treeNode0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(boolean0);

        TraversalAction<TreeNode<Object>> traversalAction0 = TreeNode.populateAction(collection0);
        assertTrue(collection0.contains(treeNode0));
        assertNotNull(traversalAction0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
    }

    @Test(timeout = 4000)
    public void tree_node_test032() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("Uh;rzOfNEm~eU~x3");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        boolean boolean0 = linkedMultiTreeNode0.isDescendantOf((TreeNode<Object>) null);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean0);

        TreeNode<Object> treeNode0 = linkedMultiTreeNode0.find("Uh;rzOfNEm~eU~x3");
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        TreeNode<Object> treeNode1 = treeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        treeNode0.parent = null;
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        Collection<TreeNode<Object>> collection0 = treeNode1.preOrdered();
        assertTrue(collection0.contains(treeNode0));
        assertNotNull(collection0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        linkedMultiTreeNode0.clear();
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        Collection<? extends TreeNode<Object>> collection1 = linkedMultiTreeNode0.subtrees();
        assertNotNull(collection1);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        // Undeclared exception!
        try {
            treeNode1.traversePreOrder((TraversalAction<TreeNode<Object>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test033() throws Throwable {
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        Integer integer1 = new Integer(0);
        assertNotNull(integer1);
        assertTrue(integer1.equals((Object) integer0));
        assertEquals(0, (int) integer1);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer1);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(integer1.equals((Object) integer0));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        Collection<TreeNode<Integer>> collection0 = linkedMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertTrue(integer1.equals((Object) integer0));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        boolean boolean0 = arrayMultiTreeNode0.remove(linkedMultiTreeNode0);
        assertTrue(integer0.equals((Object) integer1));
        assertTrue(integer1.equals((Object) integer0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertFalse(boolean0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer1);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(integer1.equals((Object) integer0));
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());

        boolean boolean1 = arrayMultiTreeNode0.isSiblingOf(arrayMultiTreeNode1);
        assertTrue(integer0.equals((Object) integer1));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
        assertTrue(integer1.equals((Object) integer0));
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(boolean1 == boolean0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
        assertFalse(boolean1);

        Object object0 = new Object();
        assertNotNull(object0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Object>(object0);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode2.parent();
        assertNull(treeNode0);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());

        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<Object>>((TreeNode<Object>) null);
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        String string0 = linkedMultiTreeNode1.toString();
        assertNotNull(string0);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals("\n+- null\n", string0);

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode3 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(linkedMultiTreeNode1, 0);
        assertNotNull(arrayMultiTreeNode3);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());

        LinkedList<TreeNode<MultiTreeNode<TreeNode<Object>>>> linkedList0 = new LinkedList<TreeNode<MultiTreeNode<TreeNode<Object>>>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        TraversalAction<TreeNode<MultiTreeNode<TreeNode<Object>>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<MultiTreeNode<TreeNode<Object>>>>) linkedList0);
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList0.size());

        ArrayMultiTreeNode<String> arrayMultiTreeNode4 = null;
        try {
            arrayMultiTreeNode4 = new ArrayMultiTreeNode<String>("\n+- null\n", (-580));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test034() throws Throwable {
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(integer0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean0 = arrayMultiTreeNode0.hasSubtree(treeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertFalse(boolean0);

        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<TreeNode<Object>>(treeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());

        ArrayMultiTreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>>(arrayMultiTreeNode1, 0);
        assertNotNull(arrayMultiTreeNode2);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());

        TreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>> treeNode1 = arrayMultiTreeNode2.root();
        assertNotNull(treeNode1);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        boolean boolean1 = treeNode1.isDescendantOf(arrayMultiTreeNode2);
        assertTrue(boolean1 == boolean0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertFalse(boolean1);

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("net.mooctest.TreeNode$2");
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode3 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode1, 2);
        assertNotNull(arrayMultiTreeNode3);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode4 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode1, 0);
        assertNotNull(arrayMultiTreeNode4);
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode3));
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());

        Collection<? extends TreeNode<LinkedMultiTreeNode<String>>> collection0 = arrayMultiTreeNode3.path(arrayMultiTreeNode4);
        assertNotNull(collection0);
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode4));
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode3));
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertNotSame(arrayMultiTreeNode3, arrayMultiTreeNode4);
        assertNotSame(arrayMultiTreeNode4, arrayMultiTreeNode3);
    }

    @Test(timeout = 4000)
    public void tree_node_test035() throws Throwable {
        LinkedList<String> linkedList0 = new LinkedList<String>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean0 = linkedList0.add("6n7g=!('<l/P@M");
        assertTrue(linkedList0.contains("6n7g=!('<l/P@M"));
        assertEquals(1, linkedList0.size());
        assertTrue(boolean0);

        boolean boolean1 = TreeNode.areAllNulls((Collection<String>) linkedList0);
        assertTrue(linkedList0.contains("6n7g=!('<l/P@M"));
        assertFalse(boolean1 == boolean0);
        assertEquals(1, linkedList0.size());
        assertFalse(boolean1);

        Integer integer0 = new Integer((-1460));
        assertNotNull(integer0);
        assertEquals((-1460), (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<MultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        LinkedList<TreeNode<MultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<MultiTreeNode<Integer>>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        Collection<TreeNode<MultiTreeNode<Integer>>> collection0 = linkedMultiTreeNode0.postOrdered();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        boolean boolean2 = linkedMultiTreeNode0.removeAll(linkedList1);
        assertFalse(boolean2 == boolean0);
        assertTrue(boolean2 == boolean1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedList1.size());
        assertFalse(boolean2);

        linkedMultiTreeNode0.clear();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("net.mooctest.ArrayMultiTreeNode$1");
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        boolean boolean3 = treeNode_TreeNodeIterator0.hasNext();
        assertTrue(boolean3 == boolean0);
        assertFalse(boolean3 == boolean2);
        assertFalse(boolean3 == boolean1);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(boolean3);

        LinkedMultiTreeNode<String> linkedMultiTreeNode2 = new LinkedMultiTreeNode<String>("net.mooctest.ArrayMultiTreeNode$1");
        assertNotNull(linkedMultiTreeNode2);
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode2, 2861);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        arrayMultiTreeNode1.clear();
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertNotSame(linkedMultiTreeNode2, linkedMultiTreeNode1);

        LinkedMultiTreeNode<Object> linkedMultiTreeNode3 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode3);
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        // Undeclared exception!
        try {
            linkedMultiTreeNode3.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +-
            // +- -1460
            //
            //  is root
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test036() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("SY~Z{W", 1130);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = treeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        boolean boolean0 = treeNode1.dropSubtree(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean0);

        boolean boolean1 = treeNode0.isAncestorOf(treeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean1);

        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode1);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int0);

        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        assertFalse(linkedList0.contains(1130));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean2 = linkedMultiTreeNode1.hasSubtree((TreeNode<TreeNode<ArrayMultiTreeNode<String>>>) null);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(boolean2 == boolean1);
        assertTrue(boolean2 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean2);

        LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        TraversalAction<TreeNode<ArrayMultiTreeNode<Integer>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<ArrayMultiTreeNode<Integer>>>) linkedList1);
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList1.size());

        LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isRoot());

        boolean boolean3 = linkedMultiTreeNode2.isLeaf();
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(boolean3 == boolean0);
        assertFalse(boolean3 == boolean1);
        assertFalse(boolean3 == boolean2);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertTrue(boolean3);

        LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode3 = new LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode3);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());

        boolean boolean4 = linkedMultiTreeNode3.equals(treeNode1);
        assertTrue(boolean4 == boolean1);
        assertTrue(boolean4 == boolean0);
        assertFalse(boolean4 == boolean3);
        assertTrue(boolean4 == boolean2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean4);

        boolean boolean5 = treeNode0.dropSubtree(linkedMultiTreeNode0);
        assertTrue(boolean5 == boolean0);
        assertTrue(boolean5 == boolean2);
        assertFalse(boolean5 == boolean3);
        assertTrue(boolean5 == boolean4);
        assertTrue(boolean5 == boolean1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertFalse(boolean5);

        LinkedList<TreeNode<String>> linkedList2 = new LinkedList<TreeNode<String>>();
        assertNotNull(linkedList2);
        assertEquals(0, linkedList2.size());

        TraversalAction<TreeNode<String>> traversalAction1 = TreeNode.populateAction((Collection<TreeNode<String>>) linkedList2);
        assertNotNull(traversalAction1);
        assertEquals(0, linkedList2.size());

        int int1 = arrayMultiTreeNode0.height();
        assertTrue(int1 == int0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int1);

        Collection<TreeNode<String>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
    }

    @Test(timeout = 4000)
    public void tree_node_test037() throws Throwable {
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(integer0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean0 = arrayMultiTreeNode0.hasSubtree(treeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertFalse(boolean0);

        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<TreeNode<Object>>(treeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());

        ArrayMultiTreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>>(arrayMultiTreeNode1, 0);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());

        TreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>> treeNode1 = arrayMultiTreeNode2.root();
        assertNotNull(treeNode1);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        boolean boolean1 = treeNode1.isDescendantOf(arrayMultiTreeNode2);
        assertTrue(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertFalse(boolean1);

        String string0 = "net.mooctest.TreeNode$2";
        ArrayMultiTreeNode<String> arrayMultiTreeNode3 = new ArrayMultiTreeNode<String>("net.mooctest.TreeNode$2", 0);
        assertNotNull(arrayMultiTreeNode3);
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());

        TreeNode<String> treeNode2 = arrayMultiTreeNode3.clone();
        assertNotNull(treeNode2);
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());

        boolean boolean2 = treeNode2.isAncestorOf(arrayMultiTreeNode3);
        assertTrue(boolean2 == boolean1);
        assertTrue(boolean2 == boolean0);
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());
        assertFalse(boolean2);

        // Undeclared exception!
        try {
            treeNode2.commonAncestor(arrayMultiTreeNode3);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- net.mooctest.TreeNode$2
            //  was not found in the current tree node
            // +- net.mooctest.TreeNode$2
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test038() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("RCykuc.~tzjM$?y");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        long long0 = linkedMultiTreeNode0.size();
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(1L, long0);

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, int0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>("RCykuc.~tzjM$?y", 0);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        int int1 = arrayMultiTreeNode1.height();
        assertTrue(int1 == int0);
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, int1);

        boolean boolean0 = arrayMultiTreeNode1.isLeaf();
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(boolean0);

        ArrayMultiTreeNode<String> arrayMultiTreeNode2 = new ArrayMultiTreeNode<String>("RCykuc.~tzjM$?y", 0);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());

        boolean boolean1 = arrayMultiTreeNode2.add(linkedMultiTreeNode0);
        assertTrue(boolean1 == boolean0);
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertFalse(arrayMultiTreeNode2.isLeaf());
        assertTrue(boolean1);

        Integer integer0 = new Integer(2607);
        assertNotNull(integer0);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(integer0.equals((Object) int1));
        assertEquals(2607, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode3 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        assertNotNull(arrayMultiTreeNode3);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(integer0.equals((Object) int1));
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(arrayMultiTreeNode3.isRoot());

        Integer integer1 = new Integer(0);
        assertNotNull(integer1);
        assertFalse(integer1.equals((Object) integer0));
        assertTrue(integer1.equals((Object) int1));
        assertTrue(integer1.equals((Object) int0));
        assertEquals(0, (int) integer1);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode4 = new ArrayMultiTreeNode<Integer>(integer1);
        assertNotNull(arrayMultiTreeNode4);
        assertFalse(integer1.equals((Object) integer0));
        assertTrue(integer1.equals((Object) int1));
        assertTrue(integer1.equals((Object) int0));
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode3));
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertTrue(arrayMultiTreeNode4.isLeaf());

        // Undeclared exception!
        try {
            arrayMultiTreeNode3.commonAncestor(arrayMultiTreeNode4);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- 0
            //  was not found in the current tree node
            // +- 2607
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test039() throws Throwable {
        ArrayMultiTreeNode<ArrayMultiTreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Object>>((ArrayMultiTreeNode<Object>) null);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        Collection<? extends TreeNode<ArrayMultiTreeNode<Object>>> collection0 = arrayMultiTreeNode0.subtrees();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        arrayMultiTreeNode0.data = null;
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        Collection<? extends TreeNode<ArrayMultiTreeNode<Object>>> collection1 = arrayMultiTreeNode0.subtrees();
        assertNotNull(collection1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertSame(collection1, collection0);

        TreeNode<ArrayMultiTreeNode<Object>> treeNode0 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean0 = treeNode0.isLeaf();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(boolean0);

        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("", 0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());

        Collection<TreeNode<String>> collection2 = arrayMultiTreeNode1.preOrdered();
        assertNotNull(collection2);
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());

        String string0 = arrayMultiTreeNode1.toString();
        assertNotNull(string0);
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertEquals("\n+- \n", string0);

        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("net.mooctest.ArrayMultiTreeNode");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());

        linkedMultiTreeNode0.setData("");
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        boolean boolean1 = arrayMultiTreeNode2.add((TreeNode<LinkedMultiTreeNode<String>>) null);
        assertFalse(boolean1 == boolean0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(boolean1);

        TreeNode<LinkedMultiTreeNode<String>> treeNode1 = arrayMultiTreeNode2.find(linkedMultiTreeNode0);
        assertNotNull(treeNode1);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());

        boolean boolean2 = treeNode1.hasSubtree(arrayMultiTreeNode2);
        assertTrue(boolean2 == boolean1);
        assertFalse(boolean2 == boolean0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertFalse(boolean2);
    }

    @Test(timeout = 4000)
    public void tree_node_test040() throws Throwable {
        Object object0 = new Object();
        assertNotNull(object0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(object0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("");
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());

        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("bc&=");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode<String> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        TreeNode<String> treeNode1 = treeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        boolean boolean0 = arrayMultiTreeNode1.dropSubtree(treeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean0);

        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<TreeNode<Object>>(arrayMultiTreeNode0, 1);
        assertNotNull(arrayMultiTreeNode2);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode3 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(arrayMultiTreeNode2);
        assertNotNull(arrayMultiTreeNode3);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());

        int int0 = arrayMultiTreeNode3.height();
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertEquals(0, int0);
    }

    @Test(timeout = 4000)
    public void tree_node_test041() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>((String) null, 2);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, int0);

        arrayMultiTreeNode0.clear();
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        Integer integer0 = new Integer(2);
        assertNotNull(integer0);
        assertFalse(integer0.equals((Object) int0));
        assertEquals(2, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertFalse(integer0.equals((Object) int0));
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        boolean boolean0 = linkedMultiTreeNode0.remove((TreeNode<Integer>) null);
        assertFalse(integer0.equals((Object) int0));
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(boolean0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>((Object) null, 2);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());

        Object object0 = arrayMultiTreeNode1.data();
        assertNull(object0);
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode1.root();
        assertNotNull(treeNode0);
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean1 = arrayMultiTreeNode1.contains(treeNode0);
        assertTrue(boolean1 == boolean0);
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertFalse(boolean1);

        LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>((Object) null);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        Collection<? extends TreeNode<Object>> collection0 = linkedMultiTreeNode1.subtrees();
        assertNotNull(collection0);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
    }

    @Test(timeout = 4000)
    public void tree_node_test042() throws Throwable {
        String string0 = "<\"<tZ";
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("<\"<tZ");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        Consumer<Object> consumer0 = (Consumer<Object>) mock(Consumer.class, new ViolatedAssumptionAnswer());
        linkedMultiTreeNode0.forEach(consumer0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        Collection<TreeNode<String>> collection0 = null;
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());

        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
        assertTrue(boolean0);

        // Undeclared exception!
        try {
            arrayMultiTreeNode0.commonAncestor(arrayMultiTreeNode1);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The tree node
            // +-
            // +- <\"<tZ
            //
            // |  +-
            // +- <\"<tZ
            //
            //  is root
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test043() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("F w;");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        Collection<? extends TreeNode<String>> collection0 = linkedMultiTreeNode0.subtrees();
        assertNotNull(collection0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        LinkedList<TreeNode<ArrayMultiTreeNode<String>>> linkedList0 = new LinkedList<TreeNode<ArrayMultiTreeNode<String>>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean0 = TreeNode.areAllNulls((Collection<TreeNode<ArrayMultiTreeNode<String>>>) linkedList0);
        assertEquals(0, linkedList0.size());
        assertTrue(boolean0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(collection0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        int int0 = 0;
        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<Object>>(treeNode0, 0);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());

        LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());

        // Undeclared exception!
        try {
            linkedMultiTreeNode1.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +-
            // +-
            // +- []
            //
            //
            //  is root
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test044() throws Throwable {
        Integer integer0 = new Integer(2);
        assertNotNull(integer0);
        assertEquals(2, (int) integer0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        Collection<TreeNode<Object>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.find(integer0);
        assertNotNull(treeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        // Undeclared exception!
        try {
            treeNode0.commonAncestor(arrayMultiTreeNode0);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- 2
            //  was not found in the current tree node
            // +- 2
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test045() throws Throwable {
        Integer integer0 = new Integer(1304);
        assertNotNull(integer0);
        assertEquals(1304, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 1304);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        arrayMultiTreeNode1.clear();
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        boolean boolean0 = arrayMultiTreeNode0.equals((Object) null);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(boolean0);

        ArrayMultiTreeNode<String> arrayMultiTreeNode2 = new ArrayMultiTreeNode<String>("");
        assertNotNull(arrayMultiTreeNode2);
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());

        ArrayMultiTreeNode<String> arrayMultiTreeNode3 = new ArrayMultiTreeNode<String>("");
        assertNotNull(arrayMultiTreeNode3);
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode2));
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());

        boolean boolean1 = arrayMultiTreeNode2.remove(arrayMultiTreeNode3);
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode3));
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode2));
        assertTrue(boolean1 == boolean0);
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode3);
        assertNotSame(arrayMultiTreeNode3, arrayMultiTreeNode2);
        assertFalse(boolean1);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode4 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode1, 0);
        assertNotNull(arrayMultiTreeNode4);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());

        ArrayMultiTreeNode<ArrayMultiTreeNode<Object>> arrayMultiTreeNode5 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Object>>(arrayMultiTreeNode4);
        assertNotNull(arrayMultiTreeNode5);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isRoot());

        String string0 = arrayMultiTreeNode5.toString();
        assertNotNull(string0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals("\n+- \n+- \n+- \n+- 1304\n\n\n\n", string0);
    }

//    @Test(timeout = 4000)
//    public void tree_node_test046() throws Throwable {
//        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("");
//        assertNotNull(arrayMultiTreeNode0);
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, arrayMultiTreeNode0.level());
//
//        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("");
//        assertNotNull(linkedMultiTreeNode0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
//        assertNotNull(treeNode_TreeNodeIterator0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        TreeNode<String> treeNode0 = treeNode_TreeNodeIterator0.next();
//        assertNotNull(treeNode0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(treeNode0.isRoot());
//        assertEquals(0, treeNode0.level());
//
//        Consumer<Object> consumer0 = (Consumer<Object>) mock(Consumer.class, new ViolatedAssumptionAnswer());
//        treeNode_TreeNodeIterator0.forEachRemaining(consumer0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = treeNode0.iterator();
//        assertNotNull(treeNode_TreeNodeIterator1);
//        assertFalse(treeNode_TreeNodeIterator1.equals((Object) treeNode_TreeNodeIterator0));
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(treeNode0.isRoot());
//        assertEquals(0, treeNode0.level());
//        assertNotSame(treeNode_TreeNodeIterator0, treeNode_TreeNodeIterator1);
//        assertNotSame(treeNode_TreeNodeIterator1, treeNode_TreeNodeIterator0);
//
//        boolean boolean0 = arrayMultiTreeNode0.hasSubtree(treeNode0);
//        assertFalse(treeNode_TreeNodeIterator0.equals((Object) treeNode_TreeNodeIterator1));
//        assertTrue(arrayMultiTreeNode0.isRoot());
//        assertTrue(arrayMultiTreeNode0.isLeaf());
//        assertEquals(0, arrayMultiTreeNode0.level());
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(treeNode0.isRoot());
//        assertEquals(0, treeNode0.level());
//        assertNotSame(treeNode_TreeNodeIterator0, treeNode_TreeNodeIterator1);
//        assertFalse(boolean0);
//
//        Collection<? extends TreeNode<String>> collection0 = linkedMultiTreeNode0.findAll("A<Md;");
//        assertNotNull(collection0);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//
//        TreeNode<String> treeNode1 = linkedMultiTreeNode0.find("");
//        assertNotNull(treeNode1);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertEquals(0, treeNode1.level());
//        assertTrue(treeNode1.isRoot());
//        assertSame(treeNode1, treeNode0);
//
//        Integer integer0 = new Integer((-1));
//        assertNotNull(integer0);
//        assertEquals((-1), (int) integer0);
//
//        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(integer0);
//        assertNotNull(arrayMultiTreeNode1);
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//
//        Collection<? extends TreeNode<Object>> collection1 = arrayMultiTreeNode1.findAll(linkedMultiTreeNode0);
//        assertNotNull(collection1);
//        assertEquals(0, linkedMultiTreeNode0.height());
//        assertTrue(linkedMultiTreeNode0.isRoot());
//        assertEquals(0, linkedMultiTreeNode0.level());
//        assertTrue(linkedMultiTreeNode0.isLeaf());
//        assertTrue(arrayMultiTreeNode1.isRoot());
//        assertEquals(0, arrayMultiTreeNode1.level());
//        assertTrue(arrayMultiTreeNode1.isLeaf());
//
//        ArrayMultiTreeNode<ArrayMultiTreeNode<String>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0, 2147483639);
//    }

    @Test(timeout = 4000)
    public void tree_node_test047() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("[\"tbp;FmN");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.traversePreOrder((TraversalAction<TreeNode<String>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test048() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("KlLjDTWfi,yoAsUm~Z");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());

        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        TreeNode<String> treeNode0 = linkedMultiTreeNode0.find("KlLjDTWfi,yoAsUm~Z");
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        treeNode0.clear();
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        boolean boolean0 = arrayMultiTreeNode0.isLeaf();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(boolean0);

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        TreeNode<Integer> treeNode1 = treeNode_TreeNodeIterator1.next();
        assertNotNull(treeNode1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        Integer integer1 = new Integer(0);
        assertNotNull(integer1);
        assertTrue(integer1.equals((Object) integer0));
        assertEquals(0, (int) integer1);

        Collection<? extends TreeNode<Integer>> collection0 = treeNode1.findAll(integer1);
        assertNotNull(collection0);
        assertTrue(integer0.equals((Object) integer1));
        assertTrue(integer1.equals((Object) integer0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator1.remove();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Failed to remove the tree node. The tree node
            // +- 0
            //  is root
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test049() throws Throwable {
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(integer0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        TreeNode<Object> treeNode0 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        boolean boolean0 = arrayMultiTreeNode0.hasSubtree(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertFalse(boolean0);

        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<TreeNode<Object>>(treeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        ArrayMultiTreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>>(arrayMultiTreeNode1, 0);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());

        TreeNode<ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>> treeNode1 = arrayMultiTreeNode2.root();
        assertNotNull(treeNode1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());

        boolean boolean1 = treeNode1.isDescendantOf(arrayMultiTreeNode2);
        assertTrue(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());
        assertFalse(boolean1);

        String string0 = "net.mooctest.TreeNode$2";
        ArrayMultiTreeNode<String> arrayMultiTreeNode3 = new ArrayMultiTreeNode<String>("net.mooctest.TreeNode$2", 0);
        assertNotNull(arrayMultiTreeNode3);
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());

        TreeNode<String> treeNode2 = arrayMultiTreeNode3.clone();
        assertNotNull(treeNode2);
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());

        // Undeclared exception!
        try {
            arrayMultiTreeNode3.commonAncestor(treeNode2);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- net.mooctest.TreeNode$2
            //  was not found in the current tree node
            // +- net.mooctest.TreeNode$2
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test050() throws Throwable {
        String string0 = "E";
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("E");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // Failed to remove the tree node. The iteration has not been performed yet
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test051() throws Throwable {
        // Undeclared exception!
        try {
            TreeNode.unlinkParent((TreeNode<Integer>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test052() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>((Object) null);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(linkedMultiTreeNode0, 32);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        String string0 = arrayMultiTreeNode0.toString();
        assertNotNull(string0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals("\n+- \n+- null\n\n", string0);

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        Collection<TreeNode<Object>> collection0 = linkedMultiTreeNode0.postOrdered();
        assertNotNull(collection0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("");
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("\n+- \n+- null\n\n");
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());

        boolean boolean0 = linkedMultiTreeNode1.contains(arrayMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertFalse(boolean0);

        ArrayMultiTreeNode<LinkedMultiTreeNode<Object>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<Object>>((LinkedMultiTreeNode<Object>) null);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());

        Collection<? extends TreeNode<Object>> collection1 = linkedMultiTreeNode0.path((TreeNode<Object>) null);
        assertNotNull(collection1);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode3 = null;
        try {
            arrayMultiTreeNode3 = new ArrayMultiTreeNode<TreeNode<Object>>((TreeNode<Object>) null, (-1));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test053() throws Throwable {
        String string0 = "Gb?7Y\\";
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>("Gb?7Y");
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        int int0 = 1238;
        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<Object>>(arrayMultiTreeNode0, 1238);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        boolean boolean0 = linkedMultiTreeNode0.isDescendantOf(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean0);

        boolean boolean1 = linkedMultiTreeNode0.remove(arrayMultiTreeNode0);
        assertTrue(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean1);

        arrayMultiTreeNode1.clear();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.add(arrayMultiTreeNode0);
            fail("Expecting exception: ClassCastException");

        } catch (ClassCastException e) {
            //
            // net.mooctest.ArrayMultiTreeNode cannot be cast to net.mooctest.LinkedMultiTreeNode
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test054() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("_`");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("_`", 1);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        linkedMultiTreeNode0.parent = (TreeNode<String>) arrayMultiTreeNode0;
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.parent.level());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());

        boolean boolean0 = linkedMultiTreeNode0.parent.isRoot();
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.parent.level());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());
        assertTrue(boolean0);

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1, linkedMultiTreeNode0.level());

        Collection<? extends TreeNode<String>> collection0 = arrayMultiTreeNode0.path((TreeNode<String>) null);
        assertNotNull(collection0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<String> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(1, treeNode0.level());
        assertFalse(treeNode0.isRoot());

        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Failed to remove the tree node. The starting node can't be removed
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test055() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("net.mooctest.ArrayMultiTreeNode");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("net.mooctest.ArrayMultiTreeNode");
        assertNotNull(linkedMultiTreeNode1);
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        linkedMultiTreeNode0.parent = (TreeNode<String>) linkedMultiTreeNode1;
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());
        assertEquals(0, linkedMultiTreeNode0.parent.level());

        TreeNode<String> treeNode0 = linkedMultiTreeNode0.parent.find(" #uu>+V");
        assertNull(treeNode0);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());
        assertEquals(0, linkedMultiTreeNode0.parent.level());
        assertNotSame(linkedMultiTreeNode0, linkedMultiTreeNode1);
        assertNotSame(linkedMultiTreeNode1, linkedMultiTreeNode0);

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        String string0 = linkedMultiTreeNode0.data();
        assertNotNull(string0);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertNotSame(linkedMultiTreeNode0, linkedMultiTreeNode1);
        assertEquals("net.mooctest.ArrayMultiTreeNode", string0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>((Object) null, 0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());

        LinkedList<TreeNode<Object>> linkedList0 = new LinkedList<TreeNode<Object>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean0 = arrayMultiTreeNode1.containsAll(linkedList0);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertEquals(0, linkedList0.size());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void tree_node_test056() throws Throwable {
        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>((ArrayMultiTreeNode<Integer>) null);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        int int0 = (-1337);
        Integer integer0 = new Integer((-1337));
        assertNotNull(integer0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals((-1337), (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<ArrayMultiTreeNode<Integer>> treeNode0 = linkedMultiTreeNode0.find(arrayMultiTreeNode0);
        assertNull(treeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        linkedMultiTreeNode0.parent = null;
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        boolean boolean0 = linkedMultiTreeNode0.contains((TreeNode<ArrayMultiTreeNode<Integer>>) null);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertFalse(boolean0);

        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>((ArrayMultiTreeNode<Integer>) null);
        assertNotNull(linkedMultiTreeNode1);
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        linkedMultiTreeNode0.parent = (TreeNode<ArrayMultiTreeNode<Integer>>) linkedMultiTreeNode1;
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.parent.level());
        assertTrue(linkedMultiTreeNode0.parent.isRoot());

        Collection<? extends TreeNode<ArrayMultiTreeNode<Integer>>> collection0 = linkedMultiTreeNode0.findAll((ArrayMultiTreeNode<Integer>) null);
        assertNotNull(collection0);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertEquals(1, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertNotSame(linkedMultiTreeNode0, linkedMultiTreeNode1);

        LinkedMultiTreeNode<Object> linkedMultiTreeNode2 = new LinkedMultiTreeNode<Object>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode2);
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());

        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("PrTcK.%{oV@");
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        ArrayMultiTreeNode<String> arrayMultiTreeNode2 = null;
        try {
            arrayMultiTreeNode2 = new ArrayMultiTreeNode<String>("Current node %1$s is root", (-1337));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test057() throws Throwable {
        ArrayMultiTreeNode<MultiTreeNode<MultiTreeNode<TreeNode<Object>>>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<MultiTreeNode<MultiTreeNode<TreeNode<Object>>>>((MultiTreeNode<MultiTreeNode<TreeNode<Object>>>) null, 10);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<MultiTreeNode<MultiTreeNode<TreeNode<Object>>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<MultiTreeNode<TreeNode<Object>>>>((MultiTreeNode<MultiTreeNode<TreeNode<Object>>>) null);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());

        boolean boolean0 = arrayMultiTreeNode0.remove(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
        assertFalse(boolean0);

        Collection<? extends TreeNode<MultiTreeNode<MultiTreeNode<TreeNode<Object>>>>> collection0 = arrayMultiTreeNode0.subtrees();
        assertNotNull(collection0);
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
    }

    @Test(timeout = 4000)
    public void tree_node_test058() throws Throwable {
        Integer integer0 = new Integer(695);
        assertNotNull(integer0);
        assertEquals(695, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        Integer integer1 = new Integer(695);
        assertNotNull(integer1);
        assertTrue(integer1.equals((Object) integer0));
        assertEquals(695, (int) integer1);

        TreeNode<Integer> treeNode0 = linkedMultiTreeNode0.find(integer1);
        assertNotNull(treeNode0);
        assertTrue(integer0.equals((Object) integer1));
        assertTrue(integer1.equals((Object) integer0));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.commonAncestor(treeNode0);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- 695
            //  was not found in the current tree node
            // +- 695
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test059() throws Throwable {
        Object object0 = null;
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>((Object) null);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode<Object> treeNode0 = linkedMultiTreeNode0.parent();
        assertNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        boolean boolean0 = TreeNode.isAnyNotNull((Collection<String>) null);
        assertFalse(boolean0);

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.commonAncestor((TreeNode<Object>) null);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node is null
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test060() throws Throwable {
        Integer integer0 = new Integer(2);
        assertNotNull(integer0);
        assertEquals(2, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        int int0 = linkedMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, int0);

        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertFalse(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        assertFalse(linkedList0.contains(2));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = arrayMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator1);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(treeNode_TreeNodeIterator1.equals((Object) treeNode_TreeNodeIterator0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());

        boolean boolean0 = TreeNode.areAllNulls((Collection<Object>) linkedList0);
        assertFalse(linkedList0.contains(2));
        assertEquals(0, linkedList0.size());
        assertTrue(boolean0);

        boolean boolean1 = linkedMultiTreeNode0.contains(arrayMultiTreeNode1);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertFalse(boolean1);

        TreeNode<ArrayMultiTreeNode<Integer>> treeNode0 = linkedMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertFalse(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Integer>(integer0, 277);
        assertNotNull(arrayMultiTreeNode2);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());

        boolean boolean2 = arrayMultiTreeNode2.contains(arrayMultiTreeNode0);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertFalse(boolean2 == boolean0);
        assertTrue(boolean2 == boolean1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode0);
        assertFalse(boolean2);

        boolean boolean3 = arrayMultiTreeNode0.add(arrayMultiTreeNode2);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertFalse(arrayMultiTreeNode2.equals((Object) arrayMultiTreeNode0));
        assertFalse(boolean3 == boolean2);
        assertTrue(boolean3 == boolean0);
        assertFalse(boolean3 == boolean1);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(1, arrayMultiTreeNode2.level());
        assertFalse(arrayMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
        assertNotSame(arrayMultiTreeNode2, arrayMultiTreeNode0);
        assertTrue(boolean3);

        boolean boolean4 = linkedMultiTreeNode0.hasSubtree(treeNode0);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertTrue(boolean4 == boolean1);
        assertFalse(boolean4 == boolean0);
        assertTrue(boolean4 == boolean2);
        assertFalse(boolean4 == boolean3);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);
        assertFalse(boolean4);

        ArrayMultiTreeNode<String> arrayMultiTreeNode3 = new ArrayMultiTreeNode<String>("an.g^A8LC/3:Q!F", 0);
        assertNotNull(arrayMultiTreeNode3);
        assertEquals(0, arrayMultiTreeNode3.level());
        assertTrue(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());

        ArrayMultiTreeNode<String> arrayMultiTreeNode4 = new ArrayMultiTreeNode<String>("an.g^A8LC/3:Q!F");
        assertNotNull(arrayMultiTreeNode4);
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode3));
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());

        arrayMultiTreeNode3.parent = (TreeNode<String>) arrayMultiTreeNode4;
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertTrue(arrayMultiTreeNode3.parent.isRoot());
        assertEquals(0, arrayMultiTreeNode3.parent.level());
        assertEquals(1, arrayMultiTreeNode3.level());
        assertFalse(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());

        TreeNode<String> treeNode1 = arrayMultiTreeNode3.clone();
        assertNotNull(treeNode1);
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode4));
        assertFalse(treeNode1.isRoot());
        assertEquals(1, treeNode1.level());
        assertEquals(1, arrayMultiTreeNode3.level());
        assertFalse(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertNotSame(arrayMultiTreeNode3, arrayMultiTreeNode4);

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator2 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator2);
        assertFalse(integer0.equals((Object) int0));
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode2));
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode2);

        Collection<? extends TreeNode<String>> collection0 = arrayMultiTreeNode3.parent.path(arrayMultiTreeNode4);
        assertNotNull(collection0);
        assertFalse(arrayMultiTreeNode4.equals((Object) arrayMultiTreeNode3));
        assertFalse(arrayMultiTreeNode3.parent.equals((Object) treeNode1));
        assertFalse(arrayMultiTreeNode3.equals((Object) arrayMultiTreeNode4));
        assertTrue(arrayMultiTreeNode4.isLeaf());
        assertTrue(arrayMultiTreeNode4.isRoot());
        assertEquals(0, arrayMultiTreeNode4.level());
        assertTrue(arrayMultiTreeNode3.parent.isRoot());
        assertEquals(0, arrayMultiTreeNode3.parent.level());
        assertEquals(1, arrayMultiTreeNode3.level());
        assertFalse(arrayMultiTreeNode3.isRoot());
        assertTrue(arrayMultiTreeNode3.isLeaf());
        assertNotSame(arrayMultiTreeNode4, arrayMultiTreeNode3);
        assertNotSame(arrayMultiTreeNode3.parent, treeNode1);
        assertNotSame(arrayMultiTreeNode3, arrayMultiTreeNode4);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode5 = new ArrayMultiTreeNode<Object>(linkedList0, 1321);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertNotNull(arrayMultiTreeNode5);
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, linkedList0.size());

        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode6 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode5);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertNotNull(arrayMultiTreeNode6);
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertTrue(arrayMultiTreeNode6.isLeaf());
        assertTrue(arrayMultiTreeNode6.isRoot());
        assertEquals(0, arrayMultiTreeNode6.level());
        assertEquals(0, linkedList0.size());

        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode7 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode5);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertNotNull(arrayMultiTreeNode7);
        assertFalse(arrayMultiTreeNode7.equals((Object) arrayMultiTreeNode6));
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, linkedList0.size());
        assertTrue(arrayMultiTreeNode7.isLeaf());
        assertTrue(arrayMultiTreeNode7.isRoot());
        assertEquals(0, arrayMultiTreeNode7.level());

        boolean boolean5 = arrayMultiTreeNode6.contains(arrayMultiTreeNode7);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertFalse(arrayMultiTreeNode6.equals((Object) arrayMultiTreeNode7));
        assertFalse(arrayMultiTreeNode7.equals((Object) arrayMultiTreeNode6));
        assertTrue(boolean5 == boolean4);
        assertFalse(boolean5 == boolean3);
        assertFalse(boolean5 == boolean0);
        assertTrue(boolean5 == boolean2);
        assertTrue(boolean5 == boolean1);
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertTrue(arrayMultiTreeNode6.isLeaf());
        assertTrue(arrayMultiTreeNode6.isRoot());
        assertEquals(0, arrayMultiTreeNode6.level());
        assertEquals(0, linkedList0.size());
        assertTrue(arrayMultiTreeNode7.isLeaf());
        assertTrue(arrayMultiTreeNode7.isRoot());
        assertEquals(0, arrayMultiTreeNode7.level());
        assertNotSame(arrayMultiTreeNode6, arrayMultiTreeNode7);
        assertNotSame(arrayMultiTreeNode7, arrayMultiTreeNode6);
        assertFalse(boolean5);

        ArrayMultiTreeNode<ArrayMultiTreeNode<Object>> arrayMultiTreeNode8 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Object>>(arrayMultiTreeNode5, 1321);
        assertFalse(linkedList0.contains("an.g^A8LC/3:Q!F"));
        assertNotNull(arrayMultiTreeNode8);
        assertTrue(arrayMultiTreeNode5.isRoot());
        assertEquals(0, arrayMultiTreeNode5.level());
        assertTrue(arrayMultiTreeNode5.isLeaf());
        assertEquals(0, linkedList0.size());
        assertTrue(arrayMultiTreeNode8.isLeaf());
        assertTrue(arrayMultiTreeNode8.isRoot());
        assertEquals(0, arrayMultiTreeNode8.level());

        // Undeclared exception!
        try {
            arrayMultiTreeNode8.traversePostOrder((TraversalAction<TreeNode<ArrayMultiTreeNode<Object>>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test061() throws Throwable {
        ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>((TreeNode<ArrayMultiTreeNode<String>>) null, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        Object object0 = arrayMultiTreeNode0.data();
        assertNull(object0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>((Object) null);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        Collection<TreeNode<Object>> collection0 = linkedMultiTreeNode0.postOrdered();
        assertNotNull(collection0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        TraversalAction<TreeNode<Object>> traversalAction0 = TreeNode.populateAction(collection0);
        assertNotNull(traversalAction0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        TreeNode<TreeNode<ArrayMultiTreeNode<String>>> treeNode0 = arrayMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        TreeNode<Object> treeNode1 = linkedMultiTreeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        Collection<? extends TreeNode<Object>> collection1 = linkedMultiTreeNode0.path(treeNode1);
        assertNotNull(collection1);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());

        // Undeclared exception!
        try {
            arrayMultiTreeNode0.commonAncestor(treeNode0);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- null
            //  was not found in the current tree node
            // +- null
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test062() throws Throwable {
        String string0 = "TovplS[#hbm]1";
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("TovplS[#hbm]1");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        long long0 = linkedMultiTreeNode0.size();
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(1L, long0);

        TreeNode<String> treeNode0 = null;
        boolean boolean0 = linkedMultiTreeNode0.remove((TreeNode<String>) null);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean0);

        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());

        Collection<? extends TreeNode<Integer>> collection0 = linkedMultiTreeNode1.subtrees();
        assertNotNull(collection0);
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());

        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        Collection<? extends TreeNode<Integer>> collection1 = linkedMultiTreeNode1.findAll(integer0);
        assertNotNull(collection1);
        assertFalse(collection1.equals((Object) collection0));
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());

        Collection<TreeNode<Integer>> collection2 = linkedMultiTreeNode1.preOrdered();
        assertNotNull(collection2);
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());

        linkedMultiTreeNode0.parent = null;
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        ArrayMultiTreeNode<ArrayMultiTreeNode<Object>> arrayMultiTreeNode1 = null;
        try {
            arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Object>>(arrayMultiTreeNode0, (-171));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test063() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>((Object) null);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        Collection<? extends TreeNode<Object>> collection0 = linkedMultiTreeNode0.findAll((Object) null);
        assertNotNull(collection0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("8]<J");
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        TreeNode<String> treeNode0 = arrayMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        LinkedList<TreeNode<String>> linkedList0 = new LinkedList<TreeNode<String>>();
        assertFalse(linkedList0.contains(treeNode0));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        TraversalAction<TreeNode<String>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<String>>) linkedList0);
        assertFalse(linkedList0.contains(treeNode0));
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList0.size());

        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = null;
        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>((TreeNode<ArrayMultiTreeNode<String>>) null);
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        // Undeclared exception!
        try {
            linkedMultiTreeNode1.traversePostOrder((TraversalAction<TreeNode<TreeNode<ArrayMultiTreeNode<String>>>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test064() throws Throwable {
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        linkedMultiTreeNode0.setData(integer0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        Spliterator<TreeNode<Integer>> spliterator0 = linkedMultiTreeNode0.spliterator();
        assertNotNull(spliterator0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        boolean boolean0 = linkedMultiTreeNode0.dropSubtree((TreeNode<Integer>) null);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(boolean0);

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("(v ");
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());

        Collection<TreeNode<Integer>> collection0 = linkedMultiTreeNode0.postOrdered();
        assertNotNull(collection0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());

        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean1 = linkedMultiTreeNode0.contains((TreeNode<Integer>) null);
        assertTrue(boolean1 == boolean0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(boolean1);

        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode0);
        assertNotNull(linkedMultiTreeNode2);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertTrue(linkedMultiTreeNode2.isRoot());

        TreeNode<String> treeNode1 = arrayMultiTreeNode0.root();
        assertNotNull(treeNode1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, treeNode1.level());

        ArrayMultiTreeNode<LinkedMultiTreeNode<Object>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<LinkedMultiTreeNode<Object>>((LinkedMultiTreeNode<Object>) null, 0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator1 = arrayMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());

        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode3 = new LinkedMultiTreeNode<TreeNode<Object>>((TreeNode<Object>) null);
        assertNotNull(linkedMultiTreeNode3);
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(linkedMultiTreeNode3);
        assertNotNull(arrayMultiTreeNode2);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());

        TreeNode<MultiTreeNode<TreeNode<Object>>> treeNode2 = arrayMultiTreeNode2.clone();
        assertNotNull(treeNode2);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());

        boolean boolean2 = treeNode2.remove(arrayMultiTreeNode2);
        assertTrue(boolean2 == boolean0);
        assertTrue(boolean2 == boolean1);
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(treeNode2.isRoot());
        assertEquals(0, treeNode2.level());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertFalse(boolean2);
    }

    @Test(timeout = 4000)
    public void tree_node_test065() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("");
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<MultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<MultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        boolean boolean0 = arrayMultiTreeNode0.remove((TreeNode<String>) null);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(boolean0);

        TreeNode<MultiTreeNode<String>> treeNode0 = linkedMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        MultiTreeNode<String> multiTreeNode0 = treeNode0.data();
        assertNotNull(multiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, multiTreeNode0.level());
        assertTrue(multiTreeNode0.isRoot());
    }

    @Test(timeout = 4000)
    public void tree_node_test066() throws Throwable {
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>("", 32);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>("");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        LinkedList<Integer> linkedList0 = new LinkedList<Integer>();
        assertFalse(linkedList0.contains(32));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean0 = TreeNode.isAnyNotNull((Collection<Integer>) linkedList0);
        assertFalse(linkedList0.contains(32));
        assertEquals(0, linkedList0.size());
        assertFalse(boolean0);

        boolean boolean1 = arrayMultiTreeNode0.add(linkedMultiTreeNode0);
        assertFalse(boolean1 == boolean0);
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertTrue(boolean1);

        int int0 = arrayMultiTreeNode0.height();
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(1, int0);

        LinkedMultiTreeNode<TreeNode<String>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<String>>((TreeNode<String>) null);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        TreeNode<TreeNode<String>> treeNode0 = linkedMultiTreeNode1.find((TreeNode<String>) null);
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        Spliterator<TreeNode<TreeNode<String>>> spliterator0 = linkedMultiTreeNode1.spliterator();
        assertNotNull(spliterator0);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        int int1 = linkedMultiTreeNode1.level();
        assertFalse(int1 == int0);
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, int1);

        boolean boolean2 = linkedMultiTreeNode0.dropSubtree(arrayMultiTreeNode0);
        assertFalse(boolean2 == boolean1);
        assertTrue(boolean2 == boolean0);
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean2);

        int int2 = linkedMultiTreeNode0.hashCode();
        assertFalse(int2 == int1);
        assertFalse(int2 == int0);
        assertEquals(1, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());

        Collection<TreeNode<Object>> collection0 = arrayMultiTreeNode0.postOrdered();
        assertNotNull(collection0);
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        TraversalAction<TreeNode<Object>> traversalAction0 = TreeNode.populateAction(collection0);
        assertNotNull(traversalAction0);
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());

        Integer integer0 = new Integer(32);
        assertNotNull(integer0);
        assertFalse(integer0.equals((Object) int1));
        assertFalse(integer0.equals((Object) int0));
        assertEquals(32, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(integer0.equals((Object) int1));
        assertFalse(integer0.equals((Object) int0));
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode2);
        assertFalse(integer0.equals((Object) int1));
        assertFalse(integer0.equals((Object) int0));
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        boolean boolean3 = linkedMultiTreeNode2.isLeaf();
        assertFalse(boolean3 == boolean2);
        assertFalse(boolean3 == boolean0);
        assertTrue(boolean3 == boolean1);
        assertFalse(integer0.equals((Object) int1));
        assertFalse(integer0.equals((Object) int0));
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(boolean3);

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.add(arrayMultiTreeNode0);
            fail("Expecting exception: ClassCastException");

        } catch (ClassCastException e) {
            //
            // net.mooctest.ArrayMultiTreeNode cannot be cast to net.mooctest.LinkedMultiTreeNode
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test067() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("QhiDy_");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("fX&G\"9c:Th +W@");
        assertNotNull(linkedMultiTreeNode1);
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());

        boolean boolean0 = linkedMultiTreeNode1.remove(linkedMultiTreeNode0);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertNotSame(linkedMultiTreeNode0, linkedMultiTreeNode1);
        assertNotSame(linkedMultiTreeNode1, linkedMultiTreeNode0);
        assertFalse(boolean0);

        boolean boolean1 = linkedMultiTreeNode1.hasSubtree(linkedMultiTreeNode0);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertTrue(boolean1 == boolean0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertNotSame(linkedMultiTreeNode0, linkedMultiTreeNode1);
        assertNotSame(linkedMultiTreeNode1, linkedMultiTreeNode0);
        assertFalse(boolean1);

        boolean boolean2 = linkedMultiTreeNode0.dropSubtree(linkedMultiTreeNode1);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertTrue(boolean2 == boolean0);
        assertTrue(boolean2 == boolean1);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertNotSame(linkedMultiTreeNode0, linkedMultiTreeNode1);
        assertNotSame(linkedMultiTreeNode1, linkedMultiTreeNode0);
        assertFalse(boolean2);

        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        TreeNode<Integer> treeNode0 = arrayMultiTreeNode0.find(integer0);
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        TreeNode.linkParent(treeNode0, (TreeNode<Integer>) arrayMultiTreeNode0);
        assertFalse(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertFalse(treeNode0.isRoot());
    }

    @Test(timeout = 4000)
    public void tree_node_test068() throws Throwable {
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>((Integer) null);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        TreeNode<Integer> treeNode0 = arrayMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        boolean boolean0 = linkedMultiTreeNode0.isRoot();
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(boolean0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(treeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());

        ArrayMultiTreeNode<Object> arrayMultiTreeNode2 = null;
        try {
            arrayMultiTreeNode2 = new ArrayMultiTreeNode<Object>((Object) null, (-1));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test069() throws Throwable {
        LinkedList<TreeNode<LinkedMultiTreeNode<MultiTreeNode<TreeNode<Object>>>>> linkedList0 = new LinkedList<TreeNode<LinkedMultiTreeNode<MultiTreeNode<TreeNode<Object>>>>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        TraversalAction<TreeNode<LinkedMultiTreeNode<MultiTreeNode<TreeNode<Object>>>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<LinkedMultiTreeNode<MultiTreeNode<TreeNode<Object>>>>>) linkedList0);
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList0.size());

        Object object0 = new Object();
        assertNotNull(object0);

        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(object0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        int int0 = linkedMultiTreeNode0.level();
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, int0);

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("Branching factor can not be negative");
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());

        // Undeclared exception!
        try {
            linkedMultiTreeNode1.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +- Branching factor can not be negative
            //  is root
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test070() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("net.mooctest.LinkedMultiTreeNode$1");
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedList<Integer> linkedList0 = new LinkedList<Integer>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean0 = TreeNode.areAllNulls((Collection<Integer>) linkedList0);
        assertEquals(0, linkedList0.size());
        assertTrue(boolean0);

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int0);
    }

    @Test(timeout = 4000)
    public void tree_node_test071() throws Throwable {
        LinkedList<TreeNode<ArrayMultiTreeNode<String>>> linkedList0 = new LinkedList<TreeNode<ArrayMultiTreeNode<String>>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean0 = TreeNode.isAnyNotNull((Collection<TreeNode<ArrayMultiTreeNode<String>>>) linkedList0);
        assertEquals(0, linkedList0.size());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void tree_node_test072() throws Throwable {
        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<TreeNode<Object>>((TreeNode<Object>) null);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        TreeNode.unlinkParent((TreeNode<Object>) linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
    }

    @Test(timeout = 4000)
    public void tree_node_test073() throws Throwable {
        LinkedMultiTreeNode<LinkedMultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<LinkedMultiTreeNode<Integer>>((LinkedMultiTreeNode<Integer>) null);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());

        LinkedMultiTreeNode<LinkedMultiTreeNode<Integer>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<LinkedMultiTreeNode<Integer>>((LinkedMultiTreeNode<Integer>) null);
        assertNotNull(linkedMultiTreeNode1);
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());

        boolean boolean0 = linkedMultiTreeNode0.dropSubtree(linkedMultiTreeNode1);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode0));
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertNotSame(linkedMultiTreeNode0, linkedMultiTreeNode1);
        assertNotSame(linkedMultiTreeNode1, linkedMultiTreeNode0);
        assertFalse(boolean0);

        LinkedList<TreeNode<LinkedMultiTreeNode<Integer>>> linkedList0 = new LinkedList<TreeNode<LinkedMultiTreeNode<Integer>>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean1 = linkedMultiTreeNode0.containsAll(linkedList0);
        assertFalse(linkedMultiTreeNode0.equals((Object) linkedMultiTreeNode1));
        assertTrue(boolean1 == boolean0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedList0.size());
        assertNotSame(linkedMultiTreeNode0, linkedMultiTreeNode1);
        assertFalse(boolean1);
    }

    @Test(timeout = 4000)
    public void tree_node_test074() throws Throwable {
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        TreeNode<Object> treeNode0 = linkedMultiTreeNode0.parent();
        assertNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());

        boolean boolean0 = linkedMultiTreeNode0.contains((TreeNode<Object>) null);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertFalse(boolean0);

        String string0 = linkedMultiTreeNode0.toString();
        assertNotNull(string0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals("\n+- 0\n", string0);

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("\n+- 0\n");
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        // Undeclared exception!
        try {
            linkedMultiTreeNode1.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +-
            // +- 0
            //
            //  is root
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test075() throws Throwable {
        Integer integer0 = new Integer(2147483639);
        assertNotNull(integer0);
        assertEquals(2147483639, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode.linkParent((TreeNode<Integer>) linkedMultiTreeNode0, (TreeNode<Integer>) linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());

        LinkedMultiTreeNode<Object> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Object>((Object) null);
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        Object object0 = new Object();
        assertNotNull(object0);

        TreeNode<Object> treeNode0 = linkedMultiTreeNode1.find(object0);
        assertNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        boolean boolean0 = linkedMultiTreeNode1.hasSubtree((TreeNode<Object>) null);
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void tree_node_test076() throws Throwable {
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>((Integer) null);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<LinkedMultiTreeNode<Integer>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<LinkedMultiTreeNode<Integer>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<TreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<Integer>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        TreeNode<TreeNode<Integer>> treeNode0 = arrayMultiTreeNode1.root();
        assertNotNull(treeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        boolean boolean0 = arrayMultiTreeNode1.isAncestorOf(treeNode0);
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertFalse(boolean0);

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>((String) null);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());

        Collection<? extends TreeNode<String>> collection0 = linkedMultiTreeNode1.subtrees();
        assertNotNull(collection0);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
    }

    @Test(timeout = 4000)
    public void tree_node_test077() throws Throwable {
        Integer integer0 = new Integer((-1));
        assertNotNull(integer0);
        assertEquals((-1), (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>((MultiTreeNode<TreeNode<Object>>) null);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());

        int int0 = arrayMultiTreeNode1.height();
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertEquals(0, int0);
    }

    @Test(timeout = 4000)
    public void tree_node_test078() throws Throwable {
        int int0 = (-2202);
        Integer integer0 = new Integer((-2202));
        assertNotNull(integer0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals((-2202), (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        boolean boolean0 = arrayMultiTreeNode0.isLeaf();
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(boolean0);

        LinkedMultiTreeNode<MultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        ArrayMultiTreeNode<MultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        TreeNode<MultiTreeNode<Integer>> treeNode0 = arrayMultiTreeNode1.find(arrayMultiTreeNode0);
        assertNotNull(treeNode0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        Collection<? extends TreeNode<MultiTreeNode<Integer>>> collection0 = linkedMultiTreeNode0.subtrees();
        assertNotNull(collection0);
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        long long0 = treeNode0.size();
        assertTrue(integer0.equals((Object) int0));
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(1L, long0);

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.commonAncestor(arrayMultiTreeNode1);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +-
            // +- -2202
            //
            //  was not found in the current tree node
            // +-
            // +- -2202
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test079() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        boolean boolean0 = arrayMultiTreeNode0.isLeaf();
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(boolean0);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = null;
        try {
            arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode0, (-1779));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test080() throws Throwable {
        Integer integer0 = new Integer((-406));
        assertNotNull(integer0);
        assertEquals((-406), (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.add(arrayMultiTreeNode0);
            fail("Expecting exception: ClassCastException");

        } catch (ClassCastException e) {
            //
            // net.mooctest.ArrayMultiTreeNode cannot be cast to net.mooctest.LinkedMultiTreeNode
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test081() throws Throwable {
        ArrayMultiTreeNode<ArrayMultiTreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Object>>((ArrayMultiTreeNode<Object>) null);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        LinkedMultiTreeNode<ArrayMultiTreeNode<Object>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Object>>((ArrayMultiTreeNode<Object>) null);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("|CC\"1|J2]$");
        assertNotNull(linkedMultiTreeNode1);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        TreeNode<String> treeNode0 = linkedMultiTreeNode1.root();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        // Undeclared exception!
        try {
            linkedMultiTreeNode1.commonAncestor(treeNode0);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- |CC\"1|J2]$
            //  was not found in the current tree node
            // +- |CC\"1|J2]$
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test082() throws Throwable {
        Integer integer0 = new Integer(32);
        assertNotNull(integer0);
        assertEquals(32, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode.linkParent((TreeNode<Integer>) linkedMultiTreeNode0, (TreeNode<Integer>) linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
    }

    @Test(timeout = 4000)
    public void tree_node_test083() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("5XM3o");
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode0, 578);
        assertNotNull(arrayMultiTreeNode1);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());

        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.next();
            fail("Expecting exception: NoSuchElementException");

        } catch (NoSuchElementException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test084() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>(";RQu#jz4,fSj!jFP");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode<String> treeNode0 = treeNode_TreeNodeIterator0.next();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());
    }

    @Test(timeout = 4000)
    public void tree_node_test085() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("Y");
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        Spliterator<TreeNode<String>> spliterator0 = arrayMultiTreeNode0.spliterator();
        assertNotNull(spliterator0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        arrayMultiTreeNode0.clear();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
    }

    @Test(timeout = 4000)
    public void tree_node_test086() throws Throwable {
        Integer integer0 = new Integer(1);
        assertNotNull(integer0);
        assertEquals(1, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode<Integer> treeNode0 = linkedMultiTreeNode0.clone();
        assertNotNull(treeNode0);
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode0.level());

        // Undeclared exception!
        try {
            treeNode0.commonAncestor(linkedMultiTreeNode0);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- 1
            //  was not found in the current tree node
            // +- 1
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test087() throws Throwable {
        Integer integer0 = new Integer(0);
        assertNotNull(integer0);
        assertEquals(0, (int) integer0);

        LinkedMultiTreeNode<Integer> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Integer>(integer0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.commonAncestor((TreeNode<Integer>) null);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node is null
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test088() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("':Yg`/KQ(87C}y");
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        // Undeclared exception!
        try {
            linkedMultiTreeNode0.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +- ':Yg`/KQ(87C}y
            //  is root
            //
            verifyException("net.mooctest.LinkedMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test089() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("b_\"ru0hd.e*0J;");
        assertNotNull(linkedMultiTreeNode0);
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isLeaf());
    }

    @Test(timeout = 4000)
    public void tree_node_test090() throws Throwable {
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>((Integer) null);
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());

        long long0 = arrayMultiTreeNode0.size();
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertEquals(1L, long0);

        Integer integer0 = new Integer(2);
        assertNotNull(integer0);
        assertEquals(2, (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Integer>((Integer) null);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertEquals(0, arrayMultiTreeNode1.level());

        boolean boolean0 = arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        assertFalse(arrayMultiTreeNode0.equals((Object) arrayMultiTreeNode1));
        assertFalse(arrayMultiTreeNode1.equals((Object) arrayMultiTreeNode0));
        assertFalse(arrayMultiTreeNode0.isLeaf());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertFalse(arrayMultiTreeNode1.isRoot());
        assertEquals(1, arrayMultiTreeNode1.level());
        assertNotSame(arrayMultiTreeNode0, arrayMultiTreeNode1);
        assertNotSame(arrayMultiTreeNode1, arrayMultiTreeNode0);
        assertTrue(boolean0);

        // Undeclared exception!
        try {
            arrayMultiTreeNode1.commonAncestor(arrayMultiTreeNode0);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +- null
            // |  +- null
            //  was not found in the current tree node
            // +- null
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test091() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("SY~Z{W", 1080);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());

        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = linkedMultiTreeNode0.root();
        assertNotNull(treeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());

        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = treeNode0.clone();
        assertNotNull(treeNode1);
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);

        boolean boolean0 = linkedMultiTreeNode0.add(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertTrue(boolean0);

        boolean boolean1 = treeNode0.isAncestorOf(treeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(boolean1 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean1);

        boolean boolean2 = linkedMultiTreeNode0.isAncestorOf(treeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(boolean2 == boolean1);
        assertFalse(boolean2 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertFalse(boolean2);

        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode1);
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        int int0 = arrayMultiTreeNode0.height();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int0);

        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        assertFalse(linkedList0.contains(1080));
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean3 = linkedMultiTreeNode1.hasSubtree((TreeNode<TreeNode<ArrayMultiTreeNode<String>>>) null);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertFalse(boolean3 == boolean0);
        assertTrue(boolean3 == boolean1);
        assertTrue(boolean3 == boolean2);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean3);

        LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        TraversalAction<TreeNode<ArrayMultiTreeNode<Integer>>> traversalAction0 = TreeNode.populateAction((Collection<TreeNode<ArrayMultiTreeNode<Integer>>>) linkedList1);
        assertNotNull(traversalAction0);
        assertEquals(0, linkedList1.size());

        LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode2);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());

        boolean boolean4 = linkedMultiTreeNode2.isLeaf();
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(boolean4 == boolean0);
        assertFalse(boolean4 == boolean1);
        assertFalse(boolean4 == boolean2);
        assertFalse(boolean4 == boolean3);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertTrue(boolean4);

        LinkedList<TreeNode<ArrayMultiTreeNode<String>>> linkedList2 = new LinkedList<TreeNode<ArrayMultiTreeNode<String>>>();
        assertFalse(linkedList2.contains(treeNode0));
        assertNotNull(linkedList2);
        assertEquals(0, linkedList2.size());

        boolean boolean5 = linkedMultiTreeNode0.removeAll(linkedList2);
        assertFalse(linkedList2.contains(treeNode0));
        assertTrue(boolean5 == boolean1);
        assertTrue(boolean5 == boolean2);
        assertFalse(boolean5 == boolean0);
        assertTrue(boolean5 == boolean3);
        assertFalse(boolean5 == boolean4);
        assertEquals(0, linkedList2.size());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(boolean5);

        LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode3 = new LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        assertNotNull(linkedMultiTreeNode3);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());

        boolean boolean6 = linkedMultiTreeNode3.equals(treeNode1);
        assertFalse(boolean6 == boolean4);
        assertFalse(boolean6 == boolean0);
        assertTrue(boolean6 == boolean2);
        assertTrue(boolean6 == boolean3);
        assertTrue(boolean6 == boolean5);
        assertTrue(boolean6 == boolean1);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertTrue(treeNode1.equals((Object) treeNode0));
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode3.isLeaf());
        assertEquals(0, linkedMultiTreeNode3.height());
        assertTrue(linkedMultiTreeNode3.isRoot());
        assertEquals(0, linkedMultiTreeNode3.level());
        assertFalse(linkedMultiTreeNode0.isLeaf());
        assertFalse(linkedMultiTreeNode0.isRoot());
        assertFalse(treeNode0.isRoot());
        assertEquals(0, treeNode1.level());
        assertTrue(treeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertNotSame(treeNode1, treeNode0);
        assertFalse(boolean6);

        boolean boolean7 = treeNode0.dropSubtree(linkedMultiTreeNode0);
        assertTrue(treeNode0.equals((Object) treeNode1));
        assertFalse(boolean7 == boolean1);
        assertFalse(boolean7 == boolean2);
        assertTrue(boolean7 == boolean4);
        assertFalse(boolean7 == boolean5);
        assertFalse(boolean7 == boolean6);
        assertFalse(boolean7 == boolean3);
        assertTrue(boolean7 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, treeNode0.level());
        assertTrue(treeNode0.isRoot());
        assertNotSame(treeNode0, treeNode1);
        assertTrue(boolean7);

        LinkedList<TreeNode<String>> linkedList3 = new LinkedList<TreeNode<String>>();
        assertNotNull(linkedList3);
        assertEquals(0, linkedList3.size());

        boolean boolean8 = linkedList3.add((TreeNode<String>) arrayMultiTreeNode0);
        assertFalse(boolean8 == boolean2);
        assertFalse(boolean8 == boolean6);
        assertTrue(boolean8 == boolean7);
        assertTrue(boolean8 == boolean0);
        assertTrue(boolean8 == boolean4);
        assertFalse(boolean8 == boolean5);
        assertFalse(boolean8 == boolean1);
        assertFalse(boolean8 == boolean3);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(1, linkedList3.size());
        assertTrue(boolean8);

        TraversalAction<TreeNode<String>> traversalAction1 = TreeNode.populateAction((Collection<TreeNode<String>>) linkedList3);
        assertNotNull(traversalAction1);
        assertEquals(1, linkedList3.size());

        int int1 = arrayMultiTreeNode0.height();
        assertTrue(int1 == int0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertEquals(0, int1);

        Collection<TreeNode<String>> collection0 = arrayMultiTreeNode0.preOrdered();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
    }

    @Test(timeout = 4000)
    public void tree_node_test092() throws Throwable {
        LinkedList<String> linkedList0 = new LinkedList<String>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        boolean boolean0 = linkedList0.add("6n7g=!('<l/P@M");
        assertTrue(linkedList0.contains("6n7g=!('<l/P@M"));
        assertEquals(1, linkedList0.size());
        assertTrue(boolean0);

        boolean boolean1 = TreeNode.areAllNulls((Collection<String>) linkedList0);
        assertTrue(linkedList0.contains("6n7g=!('<l/P@M"));
        assertFalse(boolean1 == boolean0);
        assertEquals(1, linkedList0.size());
        assertFalse(boolean1);

        Integer integer0 = new Integer((-1460));
        assertNotNull(integer0);
        assertEquals((-1460), (int) integer0);

        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        assertNotNull(arrayMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());

        LinkedMultiTreeNode<MultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<MultiTreeNode<Integer>>(arrayMultiTreeNode0);
        assertNotNull(linkedMultiTreeNode0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        LinkedList<TreeNode<MultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<MultiTreeNode<Integer>>>();
        assertNotNull(linkedList1);
        assertEquals(0, linkedList1.size());

        boolean boolean2 = linkedList1.add((TreeNode<MultiTreeNode<Integer>>) linkedMultiTreeNode0);
        assertFalse(boolean2 == boolean1);
        assertTrue(boolean2 == boolean0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(1, linkedList1.size());
        assertTrue(boolean2);

        Collection<TreeNode<MultiTreeNode<Integer>>> collection0 = linkedMultiTreeNode0.postOrdered();
        assertNotNull(collection0);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        boolean boolean3 = linkedMultiTreeNode0.removeAll(linkedList1);
        assertTrue(boolean3 == boolean1);
        assertFalse(boolean3 == boolean0);
        assertFalse(boolean3 == boolean2);
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());
        assertEquals(1, linkedList1.size());
        assertFalse(boolean3);

        linkedMultiTreeNode0.clear();
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(linkedMultiTreeNode0.isLeaf());
        assertEquals(0, linkedMultiTreeNode0.height());
        assertTrue(linkedMultiTreeNode0.isRoot());
        assertEquals(0, linkedMultiTreeNode0.level());

        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("net.mooctest.ArrayMultiTreeNode$1");
        assertNotNull(linkedMultiTreeNode1);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode1.iterator();
        assertNotNull(treeNode_TreeNodeIterator0);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());

        boolean boolean4 = treeNode_TreeNodeIterator0.hasNext();
        assertFalse(boolean4 == boolean3);
        assertTrue(boolean4 == boolean2);
        assertFalse(boolean4 == boolean1);
        assertTrue(boolean4 == boolean0);
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(boolean4);

        LinkedMultiTreeNode<String> linkedMultiTreeNode2 = new LinkedMultiTreeNode<String>("net.mooctest.ArrayMultiTreeNode$1");
        assertNotNull(linkedMultiTreeNode2);
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());

        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode2, 2861);
        assertNotNull(arrayMultiTreeNode1);
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());

        arrayMultiTreeNode1.clear();
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertNotSame(linkedMultiTreeNode2, linkedMultiTreeNode1);

        int int0 = arrayMultiTreeNode1.height();
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertNotSame(linkedMultiTreeNode2, linkedMultiTreeNode1);
        assertEquals(0, int0);

        boolean boolean5 = linkedMultiTreeNode1.isAncestorOf(linkedMultiTreeNode2);
        assertTrue(boolean5 == boolean3);
        assertFalse(boolean5 == boolean0);
        assertTrue(boolean5 == boolean1);
        assertFalse(boolean5 == boolean2);
        assertFalse(boolean5 == boolean4);
        assertFalse(linkedMultiTreeNode1.equals((Object) linkedMultiTreeNode2));
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode1.isRoot());
        assertEquals(0, linkedMultiTreeNode1.level());
        assertEquals(0, linkedMultiTreeNode1.height());
        assertTrue(linkedMultiTreeNode1.isLeaf());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertNotSame(linkedMultiTreeNode1, linkedMultiTreeNode2);
        assertNotSame(linkedMultiTreeNode2, linkedMultiTreeNode1);
        assertFalse(boolean5);

        ArrayMultiTreeNode<Object> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Object>(arrayMultiTreeNode1, 0);
        assertNotNull(arrayMultiTreeNode2);
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());

        arrayMultiTreeNode2.clear();
        assertFalse(linkedMultiTreeNode2.equals((Object) linkedMultiTreeNode1));
        assertTrue(arrayMultiTreeNode2.isRoot());
        assertEquals(0, arrayMultiTreeNode2.level());
        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertTrue(linkedMultiTreeNode2.isRoot());
        assertEquals(0, linkedMultiTreeNode2.level());
        assertEquals(0, linkedMultiTreeNode2.height());
        assertTrue(linkedMultiTreeNode2.isLeaf());
        assertEquals(0, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertTrue(arrayMultiTreeNode1.isRoot());
        assertNotSame(linkedMultiTreeNode2, linkedMultiTreeNode1);
    }

    @Test(timeout = 4000)
    public void tree_node_test093() throws Throwable {
        int int0 = 0;
        Integer integer0 = new Integer(0);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(integer0);
        TreeNode<Object> treeNode0 = linkedMultiTreeNode0.clone();
        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<TreeNode<Object>>(treeNode0, 0);
        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(arrayMultiTreeNode0);
        arrayMultiTreeNode1.hashCode();
        LinkedMultiTreeNode<MultiTreeNode<Object>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<MultiTreeNode<Object>>(linkedMultiTreeNode0);
        linkedMultiTreeNode1.parent();
        // Undeclared exception!
        try {
            linkedMultiTreeNode1.commonAncestor((TreeNode<MultiTreeNode<Object>>) null);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node is null
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test094() throws Throwable {
        Integer integer0 = new Integer(2);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        linkedMultiTreeNode0.height();
        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        arrayMultiTreeNode0.isLeaf();
        linkedMultiTreeNode0.iterator();
        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        arrayMultiTreeNode1.iterator();
        TreeNode.areAllNulls((Collection<Object>) linkedList0);
        linkedMultiTreeNode0.contains(arrayMultiTreeNode1);
        TreeNode<ArrayMultiTreeNode<Integer>> treeNode0 = linkedMultiTreeNode0.clone();
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Integer>(integer0, 277);
        arrayMultiTreeNode2.contains(arrayMultiTreeNode0);
        arrayMultiTreeNode0.add(arrayMultiTreeNode2);
        linkedMultiTreeNode0.hasSubtree(treeNode0);
        ArrayMultiTreeNode<String> arrayMultiTreeNode3 = new ArrayMultiTreeNode<String>("an.g^A8LC/3:Q!F", 0);
        ArrayMultiTreeNode<String> arrayMultiTreeNode4 = new ArrayMultiTreeNode<String>("an.g^A8LC/3:Q!F");
        arrayMultiTreeNode3.parent = (TreeNode<String>) arrayMultiTreeNode4;
        arrayMultiTreeNode4.find("net.mooctest.ArrayMultiTreeNode");
        arrayMultiTreeNode0.path(arrayMultiTreeNode2);
        arrayMultiTreeNode3.clone();
        arrayMultiTreeNode0.iterator();
        arrayMultiTreeNode3.parent.path(arrayMultiTreeNode4);
        int int0 = 1321;
        Collection<TreeNode<String>> collection0 = arrayMultiTreeNode4.preOrdered();
        arrayMultiTreeNode3.removeAll(collection0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode5 = new ArrayMultiTreeNode<Object>(linkedList0, 1321);
        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode6 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode5);
        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode7 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode5);
        arrayMultiTreeNode6.contains(arrayMultiTreeNode7);
        ArrayMultiTreeNode<ArrayMultiTreeNode<String>> arrayMultiTreeNode8 = null;
        try {
            arrayMultiTreeNode8 = new ArrayMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode3, (-2107));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test095() throws Throwable {
        int int0 = 0;
        Integer integer0 = new Integer(0);
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>(integer0);
        TreeNode<Object> treeNode0 = linkedMultiTreeNode0.clone();
        ArrayMultiTreeNode<TreeNode<Object>> arrayMultiTreeNode0 = new ArrayMultiTreeNode<TreeNode<Object>>(treeNode0, 0);
        ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<TreeNode<Object>>>(arrayMultiTreeNode0);
        arrayMultiTreeNode1.hashCode();
        LinkedMultiTreeNode<MultiTreeNode<Object>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<MultiTreeNode<Object>>(linkedMultiTreeNode0);
        linkedMultiTreeNode0.findAll(arrayMultiTreeNode1);
        linkedMultiTreeNode1.parent();
        // Undeclared exception!
        try {
            linkedMultiTreeNode1.commonAncestor((TreeNode<MultiTreeNode<Object>>) null);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node is null
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test096() throws Throwable {
        Integer integer0 = new Integer(2);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        linkedMultiTreeNode0.height();
        ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Integer>>(arrayMultiTreeNode0);
        arrayMultiTreeNode0.isLeaf();
        linkedMultiTreeNode0.iterator();
        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        arrayMultiTreeNode1.iterator();
        TreeNode.areAllNulls((Collection<Object>) linkedList0);
        linkedMultiTreeNode0.contains(arrayMultiTreeNode1);
        TreeNode<ArrayMultiTreeNode<Integer>> treeNode0 = linkedMultiTreeNode0.clone();
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Integer>(integer0, 277);
        arrayMultiTreeNode2.contains(arrayMultiTreeNode0);
        arrayMultiTreeNode0.add(arrayMultiTreeNode2);
        linkedMultiTreeNode0.hasSubtree(treeNode0);
        ArrayMultiTreeNode<String> arrayMultiTreeNode3 = new ArrayMultiTreeNode<String>("an.g^A8LC/3:Q!F", 0);
        ArrayMultiTreeNode<String> arrayMultiTreeNode4 = new ArrayMultiTreeNode<String>("an.g^A8LC/3:Q!F");
        arrayMultiTreeNode3.parent = (TreeNode<String>) arrayMultiTreeNode4;
        arrayMultiTreeNode0.path(arrayMultiTreeNode2);
        TreeNode<String> treeNode1 = arrayMultiTreeNode3.clone();
        arrayMultiTreeNode0.iterator();
        arrayMultiTreeNode3.parent.path(arrayMultiTreeNode4);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode5 = new ArrayMultiTreeNode<Object>(linkedList0, 1321);
        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode6 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode5);
        ArrayMultiTreeNode<MultiTreeNode<Object>> arrayMultiTreeNode7 = new ArrayMultiTreeNode<MultiTreeNode<Object>>(arrayMultiTreeNode5);
        arrayMultiTreeNode6.contains(arrayMultiTreeNode7);
        ArrayMultiTreeNode<ArrayMultiTreeNode<Object>> arrayMultiTreeNode8 = new ArrayMultiTreeNode<ArrayMultiTreeNode<Object>>(arrayMultiTreeNode5, 1321);
        treeNode1.level();
        // Undeclared exception!
        try {
            arrayMultiTreeNode8.traversePostOrder((TraversalAction<TreeNode<ArrayMultiTreeNode<Object>>>) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test097() throws Throwable {
        String string0 = "pd#^qY/QTs cE>&";
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("pd#^qY/QTs cE>&");
        linkedMultiTreeNode0.iterator();
        Integer integer0 = new Integer(0);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0);
        LinkedList<TreeNode<ArrayMultiTreeNode<String>>> linkedList0 = new LinkedList<TreeNode<ArrayMultiTreeNode<String>>>();
        arrayMultiTreeNode0.height();
        TreeNode<String> treeNode0 = linkedMultiTreeNode0.root();
        linkedMultiTreeNode0.isSiblingOf(treeNode0);
        LinkedList<TreeNode<String>> linkedList1 = new LinkedList<TreeNode<String>>();
        treeNode0.removeAll(linkedList1);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(treeNode0, 1827);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        arrayMultiTreeNode1.isAncestorOf(arrayMultiTreeNode2);
        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<Object>>(arrayMultiTreeNode1);
        linkedMultiTreeNode1.iterator();
        ArrayMultiTreeNode<Object> arrayMultiTreeNode3 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode1);
        // Undeclared exception!
        try {
            arrayMultiTreeNode3.commonAncestor(arrayMultiTreeNode1);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The specified tree node
            // +-
            // +- pd#^qY/QTs cE>&
            //
            //  was not found in the current tree node
            // +-
            // +-
            // +-
            // +- pd#^qY/QTs cE>&
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test098() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("KlLjDTWfi,yoAsUm~Z");
        Integer integer0 = new Integer(0);
        linkedMultiTreeNode0.find("KlLjDTWfi,yoAsUm~Z");
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Integer>(integer0, 0);
        arrayMultiTreeNode0.isLeaf();
        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        TreeNode<Integer> treeNode0 = treeNode_TreeNodeIterator0.next();
        Integer integer1 = new Integer(0);
        treeNode0.findAll(integer1);
        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Failed to remove the tree node. The tree node
            // +- 0
            //  is root
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test099() throws Throwable {
        LinkedMultiTreeNode<Object> linkedMultiTreeNode0 = new LinkedMultiTreeNode<Object>((Object) null);
        TreeNode.areAllNulls((Collection<ArrayMultiTreeNode<String>>) null);
        TreeNode<Object> treeNode0 = linkedMultiTreeNode0.root();
        treeNode0.dropSubtree(linkedMultiTreeNode0);
        LinkedList<String> linkedList0 = new LinkedList<String>();
        Consumer<Object> consumer0 = (Consumer<Object>) mock(Consumer.class, new ViolatedAssumptionAnswer());
        linkedList0.forEach(consumer0);
        TreeNode.areAllNulls((Collection<String>) linkedList0);
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = null;
        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>((ArrayMultiTreeNode<String>) null);
        linkedMultiTreeNode1.iterator();
        LinkedList<TreeNode<LinkedMultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<LinkedMultiTreeNode<Integer>>>();
        TreeNode.populateAction((Collection<TreeNode<LinkedMultiTreeNode<Integer>>>) linkedList1);
        ArrayMultiTreeNode<MultiTreeNode<String>> arrayMultiTreeNode1 = new ArrayMultiTreeNode<MultiTreeNode<String>>((MultiTreeNode<String>) null);
        Integer integer0 = new Integer((-468));
        LinkedMultiTreeNode<TreeNode<Object>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<TreeNode<Object>>(linkedMultiTreeNode0);
        treeNode0.find(linkedMultiTreeNode2);
        ArrayMultiTreeNode<Integer> arrayMultiTreeNode2 = new ArrayMultiTreeNode<Integer>(integer0, 42);
        // Undeclared exception!
        try {
            arrayMultiTreeNode2.siblings();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the siblings. The tree node
            // +- -468
            //  is root
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test100() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("", 0);
        arrayMultiTreeNode0.preOrdered();
        arrayMultiTreeNode0.toString();
        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("\n+- \n", 0);
        arrayMultiTreeNode0.isDescendantOf(arrayMultiTreeNode1);
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("net.mooc7e>t.ArrayMultiTreeode");
        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0, 0);
        linkedMultiTreeNode0.findAll("net.mooc7e>t.ArrayMultiTreeode");
        linkedMultiTreeNode0.setData("");
        arrayMultiTreeNode2.height();
        arrayMultiTreeNode0.isLeaf();
        TreeNode<LinkedMultiTreeNode<String>> treeNode0 = arrayMultiTreeNode2.clone();
        treeNode0.hasSubtree(arrayMultiTreeNode2);
        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>((TreeNode<ArrayMultiTreeNode<String>>) null);
        TreeNode<TreeNode<ArrayMultiTreeNode<String>>> treeNode1 = linkedMultiTreeNode1.find((TreeNode<ArrayMultiTreeNode<String>>) null);
        TreeNode<TreeNode<ArrayMultiTreeNode<String>>> treeNode2 = treeNode1.root();
        ArrayMultiTreeNode<TreeNode<TreeNode<ArrayMultiTreeNode<String>>>> arrayMultiTreeNode3 = null;
        try {
            arrayMultiTreeNode3 = new ArrayMultiTreeNode<TreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(treeNode2, (-2083));
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Branching factor can not be negative
            //
            verifyException("net.mooctest.ArrayMultiTreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test101() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("SY~Z{W", 1130);
        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = arrayMultiTreeNode0.iterator();
        LinkedMultiTreeNode<ArrayMultiTreeNode<String>> linkedMultiTreeNode0 = new LinkedMultiTreeNode<ArrayMultiTreeNode<String>>(arrayMultiTreeNode0);
        TreeNode<ArrayMultiTreeNode<String>> treeNode0 = linkedMultiTreeNode0.root();
        TreeNode<ArrayMultiTreeNode<String>> treeNode1 = treeNode0.clone();
        treeNode1.dropSubtree(treeNode0);
        treeNode0.isAncestorOf(treeNode1);
        linkedMultiTreeNode0.isAncestorOf(treeNode0);
        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>(treeNode1);
        LinkedList<Object> linkedList0 = new LinkedList<Object>();
        linkedMultiTreeNode1.hasSubtree((TreeNode<TreeNode<ArrayMultiTreeNode<String>>>) null);
        LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>> linkedList1 = new LinkedList<TreeNode<ArrayMultiTreeNode<Integer>>>();
        TreeNode.populateAction((Collection<TreeNode<ArrayMultiTreeNode<Integer>>>) linkedList1);
        LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode2 = new LinkedMultiTreeNode<LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        linkedMultiTreeNode2.clear();
        linkedMultiTreeNode2.isLeaf();
        LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>> linkedMultiTreeNode3 = new LinkedMultiTreeNode<MultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>>(linkedMultiTreeNode1);
        linkedMultiTreeNode3.equals(treeNode1);
        treeNode0.dropSubtree(linkedMultiTreeNode0);
        LinkedList<TreeNode<String>> linkedList2 = new LinkedList<TreeNode<String>>();
        linkedList2.add((TreeNode<String>) arrayMultiTreeNode0);
        TreeNode.populateAction((Collection<TreeNode<String>>) linkedList2);
        arrayMultiTreeNode0.height();
        arrayMultiTreeNode0.preOrdered();
        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // Failed to remove the tree node. The iteration has not been performed yet
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test102() throws Throwable {
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("", 0);
        arrayMultiTreeNode0.preOrdered();
        assertTrue(arrayMultiTreeNode0.isRoot());

        String string0 = arrayMultiTreeNode0.toString();
        assertEquals("\n+- \n", string0);

        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("\n+- \n", 0);
        boolean boolean0 = arrayMultiTreeNode0.isDescendantOf(arrayMultiTreeNode1);
        assertFalse(boolean0);

        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("\n+- \n");
        ArrayMultiTreeNode<LinkedMultiTreeNode<String>> arrayMultiTreeNode2 = new ArrayMultiTreeNode<LinkedMultiTreeNode<String>>(linkedMultiTreeNode0, 0);
        LinkedList<TreeNode<ArrayMultiTreeNode<String>>> linkedList0 = new LinkedList<TreeNode<ArrayMultiTreeNode<String>>>();
        linkedMultiTreeNode0.setData("");
        arrayMultiTreeNode2.height();
        arrayMultiTreeNode0.isLeaf();
        TreeNode<LinkedMultiTreeNode<String>> treeNode0 = arrayMultiTreeNode2.clone();
        treeNode0.hasSubtree(arrayMultiTreeNode2);
        LinkedList<TreeNode<LinkedMultiTreeNode<String>>> linkedList1 = new LinkedList<TreeNode<LinkedMultiTreeNode<String>>>();
        boolean boolean1 = treeNode0.removeAll(linkedList1);
        LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>> linkedMultiTreeNode1 = new LinkedMultiTreeNode<TreeNode<ArrayMultiTreeNode<String>>>((TreeNode<ArrayMultiTreeNode<String>>) null);
        TreeNode<TreeNode<ArrayMultiTreeNode<String>>> treeNode1 = linkedMultiTreeNode1.find((TreeNode<ArrayMultiTreeNode<String>>) null);
        assertNotNull(treeNode1);

        treeNode1.subtrees();
        treeNode1.root();
        boolean boolean2 = arrayMultiTreeNode2.isSiblingOf(treeNode0);
        assertEquals(0, treeNode0.level());
        assertTrue(boolean2 == boolean1);
        assertFalse(boolean2);
    }

    @Test(timeout = 4000)
    public void tree_node_test103() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("<\"<tZ");
        Consumer<Object> consumer0 = (Consumer<Object>) mock(Consumer.class, new ViolatedAssumptionAnswer());
        linkedMultiTreeNode0.forEach(consumer0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode0 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        ArrayMultiTreeNode<Object> arrayMultiTreeNode1 = new ArrayMultiTreeNode<Object>(linkedMultiTreeNode0);
        arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        // Undeclared exception!
        try {
            arrayMultiTreeNode0.commonAncestor(arrayMultiTreeNode1);
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Unable to find the common ancestor between tree nodes. The tree node
            // +-
            // +- <\"<tZ
            //
            // |  +-
            // +- <\"<tZ
            //
            //  is root
            //
            verifyException("net.mooctest.TreeNode", e);
        }
    }

    @Test(timeout = 4000)
    public void tree_node_test104() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("_`");
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("_`", 1);
        linkedMultiTreeNode0.parent = (TreeNode<String>) arrayMultiTreeNode0;
        linkedMultiTreeNode0.isDescendantOf(arrayMultiTreeNode0);
        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        linkedMultiTreeNode0.parent.path(arrayMultiTreeNode0);
        treeNode_TreeNodeIterator0.next();
        Integer integer0 = new Integer(0);
        LinkedMultiTreeNode<Integer> linkedMultiTreeNode1 = new LinkedMultiTreeNode<Integer>(integer0);
        // Undeclared exception!
        try {
            treeNode_TreeNodeIterator0.remove();
            fail("Expecting exception: RuntimeException");

        } catch (RuntimeException e) {
            //
            // Failed to remove the tree node. The starting node can't be removed
            //
            verifyException("net.mooctest.TreeNode$TreeNodeIterator", e);
        }
    }


    @Test(timeout = 4000)
    public void tree_node_exception_test0() throws Throwable {
        TreeNodeException treeNodeException0 = new TreeNodeException("-@lE8*(aLX5s:");
    }

    @Test(timeout = 4000)
    public void tree_node_exception_test1() throws Throwable {
        MockThrowable mockThrowable0 = new MockThrowable();
        TreeNodeException treeNodeException0 = new TreeNodeException("net.mooctest.TreeNodeException", mockThrowable0);
    }


    @Test(timeout = 4000)
    public void tree_node_test233() {

        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("0");
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        ArrayMultiTreeNode<String> arrayMultiTreeNode1 = new ArrayMultiTreeNode<String>("1");
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());



        ArrayMultiTreeNode<String> arrayMultiTreeNode2 = new ArrayMultiTreeNode<String>("2");
        assertNotNull(arrayMultiTreeNode0);
        assertEquals(0, arrayMultiTreeNode0.level());
        assertTrue(arrayMultiTreeNode0.isLeaf());
        assertTrue(arrayMultiTreeNode0.isRoot());

        arrayMultiTreeNode0.add(arrayMultiTreeNode1);
        assertEquals(1, arrayMultiTreeNode1.level());
        assertTrue(arrayMultiTreeNode1.isLeaf());
        assertFalse(arrayMultiTreeNode1.isRoot());



        arrayMultiTreeNode1.add(arrayMultiTreeNode2);
        assertEquals(2, arrayMultiTreeNode2.level());
        assertFalse(arrayMultiTreeNode1.isLeaf());
        assertFalse(arrayMultiTreeNode1.isRoot());

        assertTrue(arrayMultiTreeNode2.isLeaf());
        assertFalse(arrayMultiTreeNode2.isRoot());

        final String[] str = {"", ""};
        arrayMultiTreeNode0.traversePostOrder(new TraversalAction<TreeNode<String>>() {
            @Override
            public void perform(TreeNode<String> node) {
                str[0] += node.data();
            }

            @Override
            public boolean isCompleted() {
                return false;
            }
        });
        assertEquals("210", str[0]);

        arrayMultiTreeNode0.traversePreOrder(new TraversalAction<TreeNode<String>>() {
            @Override
            public void perform(TreeNode<String> node) {
                str[1] += node.data();
            }

            @Override
            public boolean isCompleted() {
                return false;
            }
        });
        assertEquals("012", str[1]);


        LinkedList<TreeNode<String>> linkedList0 = new LinkedList<TreeNode<String>>();
        assertNotNull(linkedList0);
        assertEquals(0, linkedList0.size());

        linkedList0.add(arrayMultiTreeNode2);

        arrayMultiTreeNode0.removeAll(linkedList0);

        assertTrue(arrayMultiTreeNode1.isLeaf());
    }

    @Test
    public void tree_node_test234() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("_`");
        ArrayMultiTreeNode<String> arrayMultiTreeNode0 = new ArrayMultiTreeNode<String>("_`", 1);
        linkedMultiTreeNode0.parent = (TreeNode<String>) arrayMultiTreeNode0;
        linkedMultiTreeNode0.isDescendantOf(arrayMultiTreeNode0);
        TreeNode.TreeNodeIterator treeNode_TreeNodeIterator0 = linkedMultiTreeNode0.iterator();
        linkedMultiTreeNode0.parent.path(arrayMultiTreeNode0);
        treeNode_TreeNodeIterator0.next();
        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("x");

        linkedMultiTreeNode0.add(linkedMultiTreeNode1);

        assertEquals(1, linkedMultiTreeNode0.height());

        final String[] str = {"", ""};
        linkedMultiTreeNode0.traversePreOrder(new TraversalAction<TreeNode<String>>() {
            @Override
            public void perform(TreeNode<String> node) {
                str[0] += node.data();
            }

            @Override
            public boolean isCompleted() {
                return false;
            }
        });
        assertEquals("_`x", str[0]);

        linkedMultiTreeNode0.traversePostOrder(new TraversalAction<TreeNode<String>>() {
            @Override
            public void perform(TreeNode<String> node) {
                str[1] += node.data();
            }

            @Override
            public boolean isCompleted() {
                return false;
            }
        });
        assertEquals("x_`", str[1]);
    }

    @Test
    public void tree_node_test235() throws Throwable {
        LinkedMultiTreeNode<String> linkedMultiTreeNode0 = new LinkedMultiTreeNode<String>("x");
        LinkedMultiTreeNode<String> linkedMultiTreeNode1 = new LinkedMultiTreeNode<String>("y");
        LinkedMultiTreeNode<String> linkedMultiTreeNode2 = new LinkedMultiTreeNode<String>("z");
        LinkedMultiTreeNode<String> linkedMultiTreeNode3 = new LinkedMultiTreeNode<String>("a");
        LinkedMultiTreeNode<String> linkedMultiTreeNode4 = new LinkedMultiTreeNode<String>("b");
        LinkedMultiTreeNode<String> linkedMultiTreeNode5 = new LinkedMultiTreeNode<String>("c");

        linkedMultiTreeNode0.add(linkedMultiTreeNode1);
        linkedMultiTreeNode0.add(linkedMultiTreeNode2);
        linkedMultiTreeNode0.add(linkedMultiTreeNode3);

        linkedMultiTreeNode2.add(linkedMultiTreeNode4);
        linkedMultiTreeNode2.add(linkedMultiTreeNode5);

        assertTrue(linkedMultiTreeNode0.contains(linkedMultiTreeNode5));
        assertTrue(linkedMultiTreeNode0.contains(linkedMultiTreeNode1));
        assertTrue(linkedMultiTreeNode0.contains(linkedMultiTreeNode2));
        assertTrue(linkedMultiTreeNode0.contains(linkedMultiTreeNode3));
        assertTrue(linkedMultiTreeNode2.contains(linkedMultiTreeNode5));
        linkedMultiTreeNode5.clear();
        linkedMultiTreeNode2.remove(linkedMultiTreeNode5);
        assertFalse(linkedMultiTreeNode2.contains(linkedMultiTreeNode5));
        assertFalse(linkedMultiTreeNode0.contains(linkedMultiTreeNode5));

        linkedMultiTreeNode0.remove(linkedMultiTreeNode2);

        final String[] str = {"", "", ""};
        linkedMultiTreeNode0.traversePreOrder(new TraversalAction<TreeNode<String>>() {
            @Override
            public void perform(TreeNode<String> node) {
                str[0] += node.data();
            }

            @Override
            public boolean isCompleted() {
                return false;
            }
        });
        assertEquals("xya", str[0]);


        linkedMultiTreeNode0.remove(linkedMultiTreeNode3);
        linkedMultiTreeNode0.traversePreOrder(new TraversalAction<TreeNode<String>>() {
            @Override
            public void perform(TreeNode<String> node) {
                str[2] += node.data();
            }

            @Override
            public boolean isCompleted() {
                return false;
            }
        });
        assertEquals("xy", str[2]);


        linkedMultiTreeNode0.clear();

        linkedMultiTreeNode0.traversePreOrder(new TraversalAction<TreeNode<String>>() {
            @Override
            public void perform(TreeNode<String> node) {
                str[1] += node.data();
            }

            @Override
            public boolean isCompleted() {
                return false;
            }
        });
        assertEquals("x", str[1]);
    }




    protected TreeNode<String> root;
    protected TreeNode<String> node1;
    protected TreeNode<String> node2;
    protected TreeNode<String> node3;
    protected TreeNode<String> node4;
    protected TreeNode<String> node5;
    protected TreeNode<String> node6;
    protected TreeNode<String> node7;
    protected TreeNode<String> node8;
    protected TreeNode<String> node9;
    protected TreeNode<String> node10;

    protected static final String ROOT_DATA = "ROOT_DATA";
    protected static final String NODE_DATA_1 = "DATA_1";
    protected static final String NODE_DATA_2 = "DATA_2";
    protected static final String NODE_DATA_3 = "DATA_3";
    protected static final String NODE_DATA_4 = "DATA_4";

    protected static final String ANOTHER_NODE_DATA = "ANOTHER_NODE_DATA";

    protected final TreeNode<String> anotherNode = new LinkedMultiTreeNode(ANOTHER_NODE_DATA);

    @Before
    public void buildTree() {
        // Create tree nodes
        root = new LinkedMultiTreeNode(ROOT_DATA);
        node1 = new LinkedMultiTreeNode(NODE_DATA_1);
        node2 = new LinkedMultiTreeNode(NODE_DATA_2);
        node3 = new LinkedMultiTreeNode(NODE_DATA_3);
        node4 = new LinkedMultiTreeNode(NODE_DATA_4);
        node5 = new LinkedMultiTreeNode(NODE_DATA_1);
        node6 = new LinkedMultiTreeNode(NODE_DATA_4);
        node7 = new LinkedMultiTreeNode(null);
        node8 = new LinkedMultiTreeNode(NODE_DATA_1);
        node9 = new LinkedMultiTreeNode(NODE_DATA_4);
        node10 = new LinkedMultiTreeNode(null);

        // Populate tree
        root.add(node1);
        root.add(node2);
        node2.add(node3);
        node3.add(node4);
        node3.add(node5);
        node5.add(node6);
        node2.add(node7);
        node2.add(node8);
        root.add(node9);
        node9.add(node10);
    }

    @Test
    public void testData() {
        // Test data is correctly populated
        String message = "Data object stored in tree node and data object queried from tree node are different";
        assertEquals(message, ROOT_DATA, root.data());
        assertEquals(message, NODE_DATA_1, node1.data());
        assertEquals(message, NODE_DATA_4, node4.data());
        assertNull(message, node7.data());
    }

    @Test
    public void testSetData() {
        // Test data is correctly set
        String message = "Data object stored in tree node was expected to be equal to the data object queried from " +
                "tree node, but actually was not";
        assertEquals(ROOT_DATA, root.data());
        root.setData(ANOTHER_NODE_DATA);
        assertEquals(message, ANOTHER_NODE_DATA, root.data());
    }

    @Test
    public void testRoot() {
        // Test root tree node is correctly determined
        String message = "Root node was incorrectly determined";
        assertEquals(message, root, root);
        assertEquals(message, root, node1.root());
        assertEquals(message, root, node4.root());
        assertEquals(message, root, node7.root());
        assertEquals(message, root, node10.root());
    }

    @Test
    public void testIsRoot() {
        // Test if root tree node is root tree node
        String messageRootExpected = "The tree node was expected to be root, but actually was not";
        assertTrue(messageRootExpected, root.isRoot());

        // Test if non root tree node is non root tree node
        String messageRootNotExpected = "The tree node was not expected to be root, but actually was";
        assertFalse(messageRootNotExpected, node2.isRoot());
        assertFalse(messageRootNotExpected, node6.isRoot());
    }

    @Test
    public void testParent() {
        // Test if parent tree node is correctly determined
        String message = "Parent node was incorrectly determined";

        assertNull(message, root.parent());
        assertEquals(message, root, node1.parent());
        assertEquals(message, node3, node4.parent());
        assertEquals(message, node5, node6.parent());
        assertEquals(message, node9, node10.parent());

        // Test if non parent tree node is non parent tree node
        assertNotEquals(message, node2, node5.parent());
        assertNotEquals(message, root, node3.parent());
        assertNotEquals(message, node7, root.parent());
    }

    @Test
    public void testSubtrees() {
        // Test if subtrees are correctly determined
        String message = "Subtrees collection was incorrectly determined";

        Collection<TreeNode<String>> mSubtreesLevel1 = new HashSet<>(3);
        mSubtreesLevel1.add(node1);
        mSubtreesLevel1.add(node2);
        mSubtreesLevel1.add(node9);
        assertEquals(message, mSubtreesLevel1, root.subtrees());

        Collection<TreeNode<String>> mSubtreesLevel2 = new HashSet<>(3);
        mSubtreesLevel2.add(node3);
        mSubtreesLevel2.add(node7);
        mSubtreesLevel2.add(node8);
        assertEquals(message, mSubtreesLevel2, node2.subtrees());

        Collection<TreeNode<String>> mSubtreesLevel3 = Collections.singleton(node6);
        assertEquals(message, mSubtreesLevel3, node5.subtrees());

        assertEquals(message, Collections.emptySet(), node6.subtrees());
    }

    @Test
    public void testIsLeaf() {
        // Test if tree node with no subtrees is a leaf
        String messageLeafExpected = "The tree node expected to be a leaf, but actually was not";
        assertTrue(messageLeafExpected, node1.isLeaf());

        // Test if tree node with subtrees is not a leaf
        String messageNotLeafExpected = "The tree node was not expected to be a leaf, but actually was";
        assertFalse(messageNotLeafExpected, root.isLeaf());
    }

    @Test
    public void testFind() {
        // Test if the tree node has the searched data
        String messageTreeNodeFoundExpected = "The tree expected to have the searched data, but actually was not";
        assertEquals(messageTreeNodeFoundExpected, node6, node6.find(NODE_DATA_4));
        assertEquals(messageTreeNodeFoundExpected, node7, node2.find(null));
        assertEquals(messageTreeNodeFoundExpected, node7, node7.find(null));
        assertEquals(messageTreeNodeFoundExpected, node5, node3.find(NODE_DATA_1));
        assertEquals(messageTreeNodeFoundExpected, node4, root.find(NODE_DATA_4));

        // Test if the tree node does not have the searched data
        String messageTreeNodeNotFoundExpected =
                "The tree with the searched data was not expected to be found, but actually was";
        assertNull(messageTreeNodeNotFoundExpected, node6.find("data"));
        assertNull(messageTreeNodeNotFoundExpected, root.find("data"));
    }

    @Test
    public void testFindAll() {
        // Test if the tree has a single tree node with the searched data
        String messageSingletonCollectionFoundExpected =
                "The single tree node was expected to have the searched data, but actually was not";
        assertEquals(messageSingletonCollectionFoundExpected, Collections.singleton(node6), node6.findAll(NODE_DATA_4));
        assertEquals(messageSingletonCollectionFoundExpected, Collections.singleton(node7), node7.findAll(null));
        assertEquals(messageSingletonCollectionFoundExpected, Collections.singleton(node2), root.findAll(NODE_DATA_2));

        // Test if the tree has more than one node with the searched data
        String messageCollectionFoundExpected =
                "The tree nodes was expected to have the searched data, but actually was not";
        Collection<TreeNode<String>> expectedMany = new HashSet<>();
        expectedMany.add(node4);
        expectedMany.add(node6);
        expectedMany.add(node9);
        assertEquals(messageCollectionFoundExpected, expectedMany, root.findAll(NODE_DATA_4));


        // Test if the tree does not have any tree node with the searched data
        String messageEmptyCollectionFoundExpected =
                "Three tree nodes with the searched data was not expected to be found, but actually was";
        assertEquals(messageEmptyCollectionFoundExpected, Collections.emptySet(), node10.findAll("data"));
    }

    @Test
    public void testHasSubtree() {
        // Test if tree node has the specified subtree
        String messageSubtreeExpected =
                "The tree node was expected to have the specified subtree, but actually was not";
        assertTrue(messageSubtreeExpected, root.hasSubtree(node1));
        assertTrue(messageSubtreeExpected, root.hasSubtree(node9));
        assertTrue(messageSubtreeExpected, node2.hasSubtree(node7));
        assertTrue(messageSubtreeExpected, node5.hasSubtree(node6));

        // Test if tree node does not have the specified subtree
        String messageSubtreeNotExpected =
                "The tree node was not expected to have the specified subtree, but actually was";
        assertFalse(messageSubtreeNotExpected, node1.hasSubtree(node10));
        assertFalse(messageSubtreeNotExpected, node5.hasSubtree(null));
        assertFalse(messageSubtreeNotExpected, node2.hasSubtree(root));
        assertFalse(messageSubtreeNotExpected, root.hasSubtree(node7));
    }

    @Test
    public void testDropSubtree() {
        // Test if subtree is dropped
        String messageDropExpected = "The subtree was expected to be dropped, but actually was not";
        String messageDropResultTrueExpected =
                "The subtree drop result was expected to be true, but actually was false";
        assertTrue(messageDropResultTrueExpected, node3.dropSubtree(node5));
        assertFalse(messageDropExpected, node3.contains(node5));
        assertFalse(messageDropExpected, node3.contains(node6));
        assertTrue(messageDropResultTrueExpected, root.dropSubtree(node9));
        assertFalse(messageDropExpected, root.contains(node9));
        assertFalse(messageDropExpected, root.contains(node10));

        // Test if subtree is not dropped
        String messageDropNotExpected = "The subtree was not expected to be dropped, but actually was";
        String messageDropResultFalseExpected =
                "The subtree drop result was expected to be false, but actually was true";
        assertFalse(messageDropResultFalseExpected, node1.dropSubtree(node2));
        assertTrue(messageDropNotExpected, root.contains(node1));
        assertTrue(messageDropNotExpected, root.contains(node2));
        assertFalse(messageDropResultFalseExpected, node2.dropSubtree(null));
        assertTrue(messageDropNotExpected, root.contains(node2));
        assertFalse(messageDropResultFalseExpected, node1.dropSubtree(root));
        assertTrue(messageDropNotExpected, root.contains(node1));

        // Test if there are equal subtrees only first is dropped
        TreeNode<String> mAnotherNode1 = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        TreeNode<String> mAnotherNode2 = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        node1.add(mAnotherNode1);
        node1.add(mAnotherNode2);
        assertTrue(messageDropExpected, node1.remove(mAnotherNode1));
        assertFalse(messageDropNotExpected, node1.contains(mAnotherNode1));
        assertTrue(messageDropNotExpected, node1.contains(mAnotherNode2));
    }

    @Test
    public void testContains() {
        // Test if tree node contains the specified tree node
        String messageContainExpected =
                "The tree node was expected to contain the specified node, but actually was not";

        assertTrue(messageContainExpected, root.contains(node2));
        assertTrue(messageContainExpected, root.contains(node6));
        assertTrue(messageContainExpected, node3.contains(node4));
        assertTrue(messageContainExpected, node2.contains(node5));

        // Test if tree node does not contain the specified tree node
        String messageNotContainExpected =
                "The tree node was not expected to contain the specified tree node, but actually was";

        assertFalse(messageNotContainExpected, root.contains(root));
        assertFalse(messageNotContainExpected, node4.contains(node3));
        assertFalse(messageNotContainExpected, node2.contains(null));
        assertFalse(messageNotContainExpected, node3.contains(root));
        assertFalse(messageNotContainExpected, root.contains(anotherNode));
    }

    @Test
    public void testContainsAll() {
        // Test if tree node contains all of the specified tree nodes
        String messageContainExpected =
                "The tree was expected to contain all of the specified nodes, but actually was not";

        Collection<TreeNode<String>> mTreeNodesContain1 = new ArrayList<>(2);
        mTreeNodesContain1.add(node3);
        mTreeNodesContain1.add(node6);
        assertTrue(messageContainExpected, node2.containsAll(mTreeNodesContain1));

        Collection<TreeNode<String>> mTreeNodesContain2 = new ArrayList<>(6);
        mTreeNodesContain2.add(node8);
        mTreeNodesContain2.add(node7);
        mTreeNodesContain2.add(node1);
        mTreeNodesContain2.add(node9);
        mTreeNodesContain2.add(node10);
        mTreeNodesContain2.add(node6);
        assertTrue(messageContainExpected, root.containsAll(mTreeNodesContain2));

        List<TreeNode<String>> mTreeNodesContain3 = Collections.singletonList(node3);
        assertTrue(messageContainExpected, node2.containsAll(mTreeNodesContain3));

        // Test if tree node does not contain at least one of the specified tree nodes
        String messageContainNotExpected =
                "The tree was not expected to contain all of the specified nodes, but actually was";

        Collection<TreeNode<String>> mTreeNodesNotContain1 = new ArrayList<>(3);
        mTreeNodesNotContain1.add(node5);
        mTreeNodesNotContain1.add(node10);
        mTreeNodesNotContain1.add(anotherNode);
        assertFalse(messageContainNotExpected, node1.containsAll(mTreeNodesNotContain1));
        assertFalse(messageContainNotExpected, root.containsAll(mTreeNodesNotContain1));

        Collection<TreeNode<String>> mTreeNodesNotContain2 = new ArrayList<>(2);
        mTreeNodesNotContain2.add(root);
        mTreeNodesNotContain2.add(node2);
        assertFalse(messageContainNotExpected, root.containsAll(mTreeNodesNotContain2));

        Collection<TreeNode<String>> mTreeNodesNotContain3 = new ArrayList<>(2);
        mTreeNodesNotContain3.add(node6);
        mTreeNodesNotContain3.add(anotherNode);
        assertFalse(messageContainNotExpected, node3.containsAll(mTreeNodesNotContain3));

        assertFalse(messageContainNotExpected, root.containsAll(null));
        assertFalse(messageContainNotExpected, node3.containsAll(Collections.<TreeNode<String>>emptyList()));
    }

    @Test
    public void testAdd() {
        // Test tree node is successfully added
        String messageAddExpected = "The tree node was expected to be added, but actually was not";
        String messageAddResultTrueExpected = "The addition result was expected to be true, but actually was false";
        assertTrue(messageAddResultTrueExpected, node1.add(anotherNode));
        assertTrue(messageAddExpected, node1.contains(anotherNode));

        // Test tree node is not added
        String messageAddResultFalseExpected = "The addition result was expected to be false, but actually was true";
        assertFalse(messageAddResultFalseExpected, node2.add(null));
    }

    @Test
    public void testClear() {
        // Test tree node is successfully cleared
        String messageClearedExpected = "The tree node was expected to be cleared, but actually was not";

        node6.clear();
        assertTrue(messageClearedExpected, node6.isLeaf());

        assertFalse(node3.isLeaf());
        node3.clear();
        assertTrue(node3.isLeaf());
        assertNull(node4.parent());
        assertNull(node5.parent());

        assertFalse(node2.isLeaf());
        node2.clear();
        assertTrue(node2.isLeaf());
        assertNull(node3.parent());
        assertNull(node7.parent());
        assertNull(node8.parent());

        assertFalse(root.isLeaf());
        root.clear();
        assertTrue(root.isLeaf());
        assertNull(node1.parent());
        assertNull(node2.parent());
        assertNull(node9.parent());
    }

    @Test
    public void testRemove() {
        // Test tree node is successfully removed
        String messageRemoveExpected = "The tree node was expected to be removed, but actually was not";
        String messageRemoveResultTrueExpected =
                "The tree node remove result was expected to be true, but actually was false";

        assertTrue(messageRemoveResultTrueExpected, node3.remove(node4));
        assertFalse(messageRemoveExpected, node3.contains(node4));
        assertTrue(messageRemoveResultTrueExpected, root.remove(node9));
        assertFalse(messageRemoveExpected, root.contains(node9));
        assertFalse(messageRemoveExpected, root.contains(node10));

        // Test nonexistent tree node is not removed
        String messageRemoveNotExpected = "The tree node was not expected to be removed, but actually was";
        String messageRemoveResultFalseExpected =
                "The tree node remove result was expected to be false, but actually was true";

        assertFalse(root.contains(anotherNode));
        assertFalse(messageRemoveResultFalseExpected, root.remove(anotherNode));
        assertFalse(messageRemoveNotExpected, root.contains(anotherNode));
        assertFalse(messageRemoveResultFalseExpected, node7.remove(node6));
        assertFalse(messageRemoveResultFalseExpected, node1.remove(null));
        assertFalse(messageRemoveResultFalseExpected, node1.remove(root));

        // Test if there are equal nodes only first is removed
        TreeNode<String> mNodeToRemove1 = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        TreeNode<String> mNodeToRemove2 = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        node1.add(mNodeToRemove1);
        node1.add(mNodeToRemove2);
        assertTrue(messageRemoveResultTrueExpected, root.remove(mNodeToRemove1));
        assertFalse(messageRemoveExpected, root.contains(mNodeToRemove1));
        assertTrue(messageRemoveNotExpected, root.contains(mNodeToRemove2));
        assertTrue(messageRemoveNotExpected, node1.contains(mNodeToRemove2));
    }

    @Test
    public void testRemoveAll() {
        // Test all tree nodes are successfully removed
        String messageRemoveExpected = "The tree node was expected to be removed, but actually was not";
        String messageRemoveResultTrueExpected =
                "The tree node remove result was expected to be true, but actually was false";

        Collection<TreeNode<String>> mNodesToRemove1 = new ArrayList<>(3);
        mNodesToRemove1.add(node6);
        mNodesToRemove1.add(node7);
        mNodesToRemove1.add(node10);
        assertTrue(messageRemoveResultTrueExpected, root.removeAll(mNodesToRemove1));
        assertFalse(messageRemoveExpected, root.contains(node6));
        assertFalse(messageRemoveExpected, root.contains(node7));
        assertFalse(messageRemoveExpected, root.contains(node10));

        Collection<TreeNode<String>> mNodesToRemove2 = Collections.singletonList(node4);
        assertTrue(messageRemoveResultTrueExpected, node2.removeAll(mNodesToRemove2));
        assertFalse(messageRemoveExpected, node2.contains(node4));
        assertFalse(messageRemoveExpected, node3.contains(node4));

        // Test only the tree nodes, which belongs to the current tree are removed
        Collection<TreeNode<String>> mNodesToRemove3 = new ArrayList<>(2);
        mNodesToRemove3.add(node8);
        mNodesToRemove3.add(anotherNode);
        assertTrue(messageRemoveResultTrueExpected, node2.removeAll(mNodesToRemove3));
        assertFalse(messageRemoveResultTrueExpected, node2.contains(node8));
        assertFalse(messageRemoveResultTrueExpected, root.contains(node8));

        // Test nonexistent tree node is not removed
        String messageRemoveResultFalseExpected =
                "The tree node remove result was expected to be false, but actually was true";

        assertFalse(root.contains(node7));
        Collection<TreeNode<String>> mNodesToRemove4 = new ArrayList<>(2);
        mNodesToRemove4.add(node7);
        mNodesToRemove4.add(anotherNode);
        assertFalse(messageRemoveResultFalseExpected, root.removeAll(mNodesToRemove4));
        assertFalse(messageRemoveResultFalseExpected, node1.removeAll(mNodesToRemove4));
        assertFalse(messageRemoveResultFalseExpected, node2.removeAll(null));
        assertFalse(messageRemoveResultFalseExpected, root.removeAll(Collections.<TreeNode<String>>emptyList()));
    }

    @Test
    public void testTraversePreOrder() {
        // Test tree pre order traversal is correct
        String message = "Tree was incorrectly traversed in a pre ordered manner";
        final Collection<TreeNode<String>> mPreOrderedActual = new ArrayList<>(10);
        TraversalAction<TreeNode<String>> action = populateCollectionAction(mPreOrderedActual);
        root.traversePreOrder(action);
        assertEquals(message, preOrderedExpected(), mPreOrderedActual);
    }

    private Collection<TreeNode<String>> preOrderedExpected() {
        // Populate collection with the tree nodes in a pre ordered manner
        Collection<TreeNode<String>> mPreOrderedExpected = new ArrayList<>(10);
        mPreOrderedExpected.add(root);
        mPreOrderedExpected.add(node1);
        mPreOrderedExpected.add(node2);
        mPreOrderedExpected.add(node3);
        mPreOrderedExpected.add(node4);
        mPreOrderedExpected.add(node5);
        mPreOrderedExpected.add(node6);
        mPreOrderedExpected.add(node7);
        mPreOrderedExpected.add(node8);
        mPreOrderedExpected.add(node9);
        mPreOrderedExpected.add(node10);
        return mPreOrderedExpected;
    }

    @Test
    public void testTraversePostOrder() {
        // Test tree post order traversal is correct
        String message = "Tree was incorrectly traversed in a post ordered manner";
        final Collection<TreeNode<String>> mPostOrderedActual = new ArrayList<>(10);
        TraversalAction<TreeNode<String>> action = populateCollectionAction(mPostOrderedActual);
        root.traversePostOrder(action);
        assertEquals(message, postOrderedExpected(), mPostOrderedActual);
    }

    private Collection<TreeNode<String>> postOrderedExpected() {
        // Populate collection with the tree nodes in a post ordered manner
        Collection<TreeNode<String>> mPostOrderedExpected = new ArrayList<>(10);
        mPostOrderedExpected.add(node1);
        mPostOrderedExpected.add(node4);
        mPostOrderedExpected.add(node6);
        mPostOrderedExpected.add(node5);
        mPostOrderedExpected.add(node3);
        mPostOrderedExpected.add(node7);
        mPostOrderedExpected.add(node8);
        mPostOrderedExpected.add(node2);
        mPostOrderedExpected.add(node10);
        mPostOrderedExpected.add(node9);
        mPostOrderedExpected.add(root);
        return mPostOrderedExpected;
    }

    private TraversalAction<TreeNode<String>> populateCollectionAction(final Collection<TreeNode<String>> collection) {
        // Populate input collection while traversing the tree
        return new TraversalAction<TreeNode<String>>() {
            @Override
            public void perform(TreeNode<String> node) {
                collection.add(node);
            }

            @Override
            public boolean isCompleted() {
                return false;
            }
        };
    }

    @Test
    public void testPreOrdered() {
        // Test tree pre ordered collection is correct
        String message = "Tree was incorrectly pre ordered";
        assertEquals(message, preOrderedExpected(), root.preOrdered());
        assertEquals(message, Collections.singleton(node10), node10.preOrdered());
    }

    @Test
    public void testPostOrdered() {
        // Test tree post ordered collection is correct
        String message = "Tree was incorrectly post ordered";
        assertEquals(message, postOrderedExpected(), root.postOrdered());
        assertEquals(message, Collections.singleton(node1), node1.postOrdered());
    }

    @Test
    public void testPath() {
        // Test path is correctly determined
        String message = "The path between nodes was incorrectly determined";

        Collection<TreeNode<String>> mPath1 = new LinkedList<>();
        mPath1.add(root);
        mPath1.add(node2);
        mPath1.add(node3);
        mPath1.add(node5);
        mPath1.add(node6);
        assertEquals(message, mPath1, root.path(node6));

        Collection<TreeNode<String>> mPath2 = new LinkedList<>();
        mPath2.add(node2);
        mPath2.add(node8);
        assertEquals(message, mPath2, node2.path(node8));

        assertEquals(message, Collections.singletonList(node10), node10.path(node9));
        assertEquals(message, Collections.singletonList(node9), node9.path(null));
        assertEquals(message, Collections.singletonList(node2), node2.path(node2));
    }

    @Test(expected = TreeNodeException.class)
    public void testPathToRootException() {
        // Test path to root tree node throws exception
        node3.path(root);
    }

    @Test(expected = TreeNodeException.class)
    public void testPathToNonExistentNodeException() {
        // Test path to non descendant / non existent tree node throws exception
        node2.path(node1);
    }

    @Test
    public void testCommonAncestor() {
        // Test common ancestor tree node was incorrectly determined
        String message = "The common ancestor between nodes was incorrectly determined";
        assertEquals(message, root, node2.commonAncestor(node10));
        assertEquals(message, node2, node6.commonAncestor(node8));
        assertEquals(message, node3, node4.commonAncestor(node5));
        assertEquals(message, root, node1.commonAncestor(node2));
        assertEquals(message, root, node2.commonAncestor(node2));
    }

    @Test(expected = TreeNodeException.class)
    public void testCommonAncestorNullNodeException() {
        // Test common ancestor of the current tree node and null node throws exception
        node1.commonAncestor(null);
    }

    @Test(expected = TreeNodeException.class)
    public void testCommonAncestorNonExistentNodeException() {
        // Test common ancestor of the current tree node and non existent tree node throws exception
        assertFalse(root.contains(anotherNode));
        node2.commonAncestor(anotherNode);
    }

    @Test(expected = TreeNodeException.class)
    public void testCommonAncestorCurrentNodeIsRootException() {
        // Test common ancestor of the root tree node and non root tree node trows exception
        root.commonAncestor(node1);
    }

    @Test(expected = TreeNodeException.class)
    public void testCommonAncestorNodeIsRootException() {
        // Test common ancestor of the non root tree node and the root tree node trows exception
        node2.commonAncestor(root);
    }

    @Test
    public void testIsSiblingOf() {
        // Test the specified tree node is the sibling of the current tree node
        String messageTrue =
                "The specified tree node was expected to be the sibling of the current tree node, " +
                        "but actually was not";
        assertTrue(messageTrue, node1.isSiblingOf(node9));
        assertTrue(messageTrue, node1.isSiblingOf(node2));
        assertTrue(messageTrue, node5.isSiblingOf(node4));

        // Test the specified tree node is not the sibling of the current tree node
        String messageFalse =
                "The specified tree node was not expected to be the sibling of the current tree node, " +
                        "but actually was";
        assertFalse(messageFalse, node2.isSiblingOf(null));
        assertFalse(messageFalse, root.isSiblingOf(node5));
        assertFalse(messageFalse, node4.isSiblingOf(root));
        assertFalse(messageFalse, node5.isSiblingOf(node10));
    }

    @Test
    public void testIsAncestorOf() {
        // Test the specified tree node is the ancestor of the current tree node
        String messageTrue =
                "The specified tree node was expected to be the ancestor of the current tree node, " +
                        "but actually was not";
        assertTrue(messageTrue, root.isAncestorOf(node1));
        assertTrue(messageTrue, root.isAncestorOf(node8));
        assertTrue(messageTrue, node2.isAncestorOf(node6));
        assertTrue(messageTrue, node9.isAncestorOf(node10));

        // Test the specified tree node is not the ancestor of the current tree node
        String messageFalse =
                "The specified tree node was not expected to be the ancestor of the current tree node, " +
                        "but actually was";
        assertFalse(messageFalse, node10.isAncestorOf(node9));
        assertFalse(messageFalse, node9.isAncestorOf(null));
        assertFalse(messageFalse, node2.isAncestorOf(root));
        assertFalse(messageFalse, node1.isAncestorOf(node1));
        assertFalse(messageFalse, node3.isAncestorOf(anotherNode));
    }

    @Test
    public void testIsDescendantOf() {
        // Test the specified tree node is the descendant of the current tree node
        String messageTrue =
                "The specified tree node was expected to be the descendant of the current tree node, " +
                        "but actually was not";
        assertTrue(messageTrue, node6.isDescendantOf(root));
        assertTrue(messageTrue, node3.isDescendantOf(root));
        assertTrue(messageTrue, node5.isDescendantOf(node2));
        assertTrue(messageTrue, node10.isDescendantOf(node9));

        // Test the specified tree node is not the descendant of the current tree node
        String messageFalse =
                "The specified tree node was not expected to be the descendant of the current tree node, " +
                        "but actually was";
        assertFalse(messageFalse, node3.isDescendantOf(node6));
        assertFalse(messageFalse, node2.isDescendantOf(null));
        assertFalse(messageFalse, root.isDescendantOf(node3));
        assertFalse(messageFalse, node2.isDescendantOf(node1));
        assertFalse(messageFalse, node10.isDescendantOf(node10));
    }

    @Test
    public void testSize() {
        // Test the specified tree node size is correctly calculated
        String message = "Tree node size was incorrectly calculated";
        assertSame(message, 1L, node6.size());
        assertSame(message, 2L, node9.size());
        assertSame(message, 4L, node3.size());
        assertSame(message, 11L, root.size());
    }

    @Test
    public void testHeight() {
        // Test the specified tree node height is correctly calculated
        String message = "Tree node height was incorrectly calculated";
        assertSame(message, 0, node6.height());
        assertSame(message, 1, node5.height());
        assertSame(message, 3, node2.height());
        assertSame(message, 2, node3.height());
        assertSame(message, 4, root.height());
    }

    @Test
    public void testLevel() {
        // Test the specified tree node level is correctly calculated
        String message = "Tree node level was incorrectly calculated";
        assertSame(message, 0, root.level());
        assertSame(message, 2, node10.level());
        assertSame(message, 4, node6.level());
        assertSame(message, 3, node4.level());
    }

    @Test
    public void testClone() {
        // Test the tree node is correctly cloned
        String message = "The cloned tree node was expected to be equal to the original one, but actually was not";
        TreeNode<String> mClonedRoot = root.clone();
        assertEquals(message, root, mClonedRoot);
    }

    @Test
    public void testEquals() {
        // Test data equality between the current tree node and the specified tree node
        String messageEqual =
                "The specified tree node was expected to be equal to the current tree node, but actually was not";
        String messageNotEqual =
                "The specified tree node was not expected to be equal to the current tree node, but actually was";

        assertEquals(messageEqual, root, root);
        assertEquals(messageEqual, node1, node1);
        assertEquals(messageEqual, node7, node7);

        assertNotEquals(messageNotEqual, root, node1);
        assertNotEquals(messageNotEqual, root, node7);
        assertNotEquals(messageNotEqual, node9, node10);

        // Test the created tree nodes with the same data are not equal
        TreeNode<String> mAnotherNode1 = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        TreeNode<String> mAnotherNode2 = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        assertNotEquals(messageNotEqual, mAnotherNode1, mAnotherNode2);
    }

    @Test
    public void testIteratorNext() {
        // Test iterator next returns the correct tree node
        String message = "Iterator returned incorrect tree node";
        Iterator<TreeNode<String>> mIterator1 = root.iterator();
        assertEquals(message, root, mIterator1.next());
        assertEquals(message, node1, mIterator1.next());
        assertEquals(message, node2, mIterator1.next());
        assertEquals(message, node3, mIterator1.next());
        assertEquals(message, node4, mIterator1.next());
        assertEquals(message, node5, mIterator1.next());
        assertEquals(message, node6, mIterator1.next());
        assertEquals(message, node7, mIterator1.next());
        assertEquals(message, node8, mIterator1.next());
        assertEquals(message, node9, mIterator1.next());
        assertEquals(message, node10, mIterator1.next());

        // Test iterator works correctly for one node
        TreeNode<String> mNode = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        Iterator<TreeNode<String>> mIterator2 = mNode.iterator();
        assertEquals(message, mNode, mIterator2.next());

        // Test iterator next returns the correct tree node if there are equal subtree nodes
        TreeNode<String> mAnotherNode1 = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        TreeNode<String> mAnotherNode2 = new LinkedMultiTreeNode<>(ANOTHER_NODE_DATA);
        node1.add(mAnotherNode1);
        node1.add(mAnotherNode2);
        Iterator<TreeNode<String>> mIterator3 = node1.iterator();
        assertEquals(message, node1, mIterator3.next());
        assertEquals(message, mAnotherNode1, mIterator3.next());
        assertEquals(message, mAnotherNode2, mIterator3.next());
    }

    @Test
    public void testIteratorHasNext() {
        // Test iterator must have the next tree node
        String messageHasNextResultTrueExpected =
                "The iterator was expected to have the next tree node, but actually was not";
        Iterator<TreeNode<String>> mIterator1 = node3.iterator();
        assertTrue(messageHasNextResultTrueExpected, mIterator1.hasNext());
        mIterator1.next();
        mIterator1.next();
        mIterator1.next();
        assertTrue(messageHasNextResultTrueExpected, mIterator1.hasNext());

        // Test iterator must not have the next tree node
        String messageHasNextResultFalseExpected =
                "The iterator was not expected to have the next tree node, but actually was";
        Iterator<TreeNode<String>> mIterator2 = node9.iterator();
        mIterator2.next();
        mIterator2.next();
        assertFalse(messageHasNextResultFalseExpected, mIterator2.hasNext());

        // Test the iterator common use case
        Iterator<TreeNode<String>> mIterator3 = root.iterator();
        assertTrue(messageHasNextResultFalseExpected, mIterator3.hasNext());
    }

    @Test(expected = NoSuchElementException.class)
    public void testIteratorNextNoSuchElementException() {
        // Test exception is thrown if there are no tree nodes
        Iterator<TreeNode<String>> mIterator = root.iterator();
        while (mIterator.hasNext()) {
            mIterator.next();
        }
        mIterator.next();
    }

    @Test(expected = ConcurrentModificationException.class)
    public void testIteratorNextConcurrentModificationException() {
        // Test exception is thrown if tree is changed during the iteration without iterator
        for (TreeNode<String> mNode : root) {
            if (mNode.equals(node3)) {
                root.remove(node3);
            }
        }
    }

    @Test
    public void testIteratorRemove() {
        // Test iterator removes tree nodes
        String messageRemoveExpected = "The iterator was expected to remove the tree node, but actually was not";
        Iterator<TreeNode<String>> mIterator1 = root.iterator();
        do {
            if (mIterator1.next().equals(node3)) {
                break;
            }
        } while (true);
        mIterator1.remove();
        assertFalse(messageRemoveExpected, node2.hasSubtree(node3));
        assertFalse(messageRemoveExpected, root.contains(node4));
        assertFalse(messageRemoveExpected, root.contains(node5));
        assertFalse(messageRemoveExpected, root.contains(node6));
        assertEquals(node7, mIterator1.next());
        mIterator1.remove();
        assertFalse(messageRemoveExpected, node2.contains(node7));
        assertEquals(node8, mIterator1.next());
        assertEquals(node9, mIterator1.next());
        assertEquals(node10, mIterator1.next());
        mIterator1.remove();
        assertFalse(messageRemoveExpected, node9.contains(node10));
        mIterator1.remove();
        assertFalse(messageRemoveExpected, root.contains(node9));
    }

    @Test(expected = IllegalStateException.class)
    public void testIteratorRemoveIllegalStateException() {
        // Test exception is thrown if the iterator remove was called prior the iteration start
        Iterator<TreeNode<String>> iterator = node1.iterator();
        iterator.remove();
    }

    @Test(expected = TreeNodeException.class)
    public void testIteratorRemoveOnCurrentNodeTreeNodeException() {
        // Test exception is thrown if iterator remove was called on the top tree node
        Iterator<TreeNode<String>> iterator = node2.iterator();
        iterator.next();
        iterator.remove();
    }

    @Test(expected = TreeNodeException.class)
    public void testIteratorRemoveOnRootTreeNodeException() {
        // Test exception is thrown if iterator remove was called on the root tree node
        Iterator<TreeNode<String>> iterator = root.iterator();
        iterator.next();
        iterator.remove();
    }

    @Test(expected = ConcurrentModificationException.class)
    public void testIteratorRemoveConcurrentModificationException() {
        // Test exception is thrown if tree was changed while calling iterator remove
        Iterator<TreeNode<String>> iterator = root.iterator();
        do {
            if (iterator.next().equals(node7)) {
                break;
            }
        } while (true);
        iterator.remove();
        node2.dropSubtree(node8);
        iterator.remove();
    }


    @Before
    public void buildTree2() {
        // Create tree nodes
        root = new LinkedMultiTreeNode(ROOT_DATA);
        node1 = new LinkedMultiTreeNode(NODE_DATA_1);
        node2 = new LinkedMultiTreeNode(NODE_DATA_2);
        node3 = new LinkedMultiTreeNode(NODE_DATA_3);
        node4 = new LinkedMultiTreeNode(NODE_DATA_4);
        node5 = new LinkedMultiTreeNode(NODE_DATA_1);
        node6 = new LinkedMultiTreeNode(NODE_DATA_4);
        node7 = new LinkedMultiTreeNode(null);
        node8 = new LinkedMultiTreeNode(NODE_DATA_1);
        node9 = new LinkedMultiTreeNode(NODE_DATA_4);
        node10 = new LinkedMultiTreeNode(null);

        // Populate tree
        root.add(node1);
        root.add(node2);
        node2.add(node3);
        node3.add(node4);
        node3.add(node5);
        node5.add(node6);
        node2.add(node7);
        node2.add(node8);
        root.add(node9);
        node9.add(node10);
    }



}

