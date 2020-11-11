package net.mooctest;

import org.evosuite.runtime.ViolatedAssumptionAnswer;
import org.junit.Test;

import java.util.Collection;
import java.util.Map;
import java.util.Set;
import java.util.function.BiFunction;

import static org.evosuite.runtime.EvoAssertions.verifyException;
import static org.evosuite.shaded.org.mockito.Mockito.*;
import static org.junit.Assert.*;

public class    NodeTest {
    @Test(timeout = 4000)
    public void xd() throws Throwable {

        Node node = new Node();

        node.getEdge('1');

    }


    @Test(timeout = 4000)
    public void edge_test0() throws Throwable {
        Node node0 = new Node();
        Edge edge0 = new Edge((String) null, node0);
        String string0 = edge0.getLabel();
        assertNull(string0);
    }

    @Test(timeout = 4000)
    public void edge_test1() throws Throwable {
        Node node0 = new Node();
        Edge edge0 = new Edge("gN,2vH#!\"g0W+/6v?2", node0);
        String string0 = edge0.getLabel();
        assertEquals("gN,2vH#!\"g0W+/6v?2", string0);
    }

    @Test(timeout = 4000)
    public void edge_test2() throws Throwable {
        Node node0 = new Node();
        Edge edge0 = new Edge((String) null, node0);
        edge0.setDest((Node) null);
        Node node1 = edge0.getDest();
        assertNull(node1);
    }

    @Test(timeout = 4000)
    public void edge_test3() throws Throwable {
        Node node0 = new Node();
        Edge edge0 = new Edge("", node0);
        String string0 = edge0.getLabel();
        assertEquals("", string0);
    }

    @Test(timeout = 4000)
    public void edge_test4() throws Throwable {
        Node node0 = new Node();
        Edge edge0 = new Edge("", node0);
        Node node1 = edge0.getDest();
        assertSame(node0, node1);
    }

    @Test(timeout = 4000)
    public void edge_test5() throws Throwable {
        Node node0 = new Node();
        Edge edge0 = new Edge("", node0);
        edge0.setLabel("");
        assertEquals("", edge0.getLabel());
    }


    @Test(timeout = 4000)
    public void edge_bag_test00() throws Throwable {
        Character character0 = new Character('');
        EdgeBag edgeBag0 = new EdgeBag();
        Character character1 = new Character('D');
        Node node0 = new Node();
        Edge edge0 = new Edge("Not implemented", node0);
        edgeBag0.put(character0, edge0);
        edgeBag0.putIfAbsent(character1, (Edge) null);
        assertEquals(2, edgeBag0.size());
    }

    @Test(timeout = 4000)
    public void edge_bag_test01() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = new Character(' ');
        edgeBag0.putIfAbsent(character0, (Edge) null);
        Character character1 = Character.valueOf('y');
        edgeBag0.put(character1, (Edge) null);
        edgeBag0.get('y');
        assertEquals(2, edgeBag0.size());
    }

    @Test(timeout = 4000)
    public void edge_bag_test02() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = new Character('\uDC4E');
        BiFunction<Object, Object, Edge> biFunction0 = (BiFunction<Object, Object, Edge>) mock(BiFunction.class, new ViolatedAssumptionAnswer());
        // Undeclared exception!
        try {
            edgeBag0.compute(character0, biFunction0);
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Illegal input character \uDC4E.
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test03() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = new Character(' ');
        edgeBag0.putIfAbsent(character0, (Edge) null);
        Character character1 = Character.valueOf('y');
        edgeBag0.put(character1, (Edge) null);
        edgeBag0.put(character1, (Edge) null);
        assertEquals(2, edgeBag0.size());
    }

    @Test(timeout = 4000)
    public void edge_bag_test04() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = Character.valueOf('5');
        Edge edge0 = edgeBag0.get((Object) character0);
        assertNull(edge0);
    }

    @Test(timeout = 4000)
    public void edge_bag_test05() throws Throwable {
        Character character0 = new Character('');
        EdgeBag edgeBag0 = new EdgeBag();
        Node node0 = new Node();
        Edge edge0 = new Edge("Not implemented", node0);
        edgeBag0.put(character0, edge0);
        Edge edge1 = edgeBag0.get((Object) character0);
        assertSame(edge1, edge0);
    }

    @Test(timeout = 4000)
    public void edge_bag_test06() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        // Undeclared exception!
        try {
            edgeBag0.put((Character) null, (Edge) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test07() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        // Undeclared exception!
        try {
            edgeBag0.get((Object) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test08() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Collection<Edge> collection0 = edgeBag0.values();
        // Undeclared exception!
        try {
            edgeBag0.get((Object) collection0);
            fail("Expecting exception: ClassCastException");

        } catch (ClassCastException e) {
            //
            // java.util.Arrays$ArrayList cannot be cast to java.lang.Character
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test09() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = Character.valueOf('s');
        Node node0 = new Node();
        Edge edge0 = new Edge("/9M'9Y|ABQM&,8j}Q=V", node0);
        edgeBag0.put(character0, edge0);
        Edge edge1 = edgeBag0.get('s');
        assertEquals("/9M'9Y|ABQM&,8j}Q=V", edge1.getLabel());
    }

    @Test(timeout = 4000)
    public void edge_bag_test10() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        // Undeclared exception!
        try {
            edgeBag0.get('\u008C');
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Illegal input character \u008C.
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test11() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Edge edge0 = edgeBag0.get('|');
        assertNull(edge0);
    }

    @Test(timeout = 4000)
    public void edge_bag_test12() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = Character.valueOf('a');
        Node node0 = new Node();
        Edge edge0 = new Edge("Not implemented", node0);
        edgeBag0.put(character0, edge0);
        edgeBag0.put(character0, edge0);
        assertEquals(1, edgeBag0.size());
    }

    @Test(timeout = 4000)
    public void edge_bag_test13() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        int int0 = edgeBag0.size();
        assertEquals(0, int0);
    }

    @Test(timeout = 4000)
    public void edge_bag_test14() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = Character.valueOf('|');
        edgeBag0.put(character0, (Edge) null);
        int int0 = edgeBag0.size();
        assertEquals(1, int0);
    }

    @Test(timeout = 4000)
    public void edge_bag_test15() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = Character.valueOf('|');
        edgeBag0.put(character0, (Edge) null);
        boolean boolean0 = edgeBag0.isEmpty();
        assertFalse(boolean0);
    }

    @Test(timeout = 4000)
    public void edge_bag_test16() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        boolean boolean0 = edgeBag0.isEmpty();
        assertTrue(boolean0);
    }

    @Test(timeout = 4000)
    public void edge_bag_test17() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = Character.valueOf('|');
        edgeBag0.put(character0, (Edge) null);
        Collection<Edge> collection0 = edgeBag0.values();
        assertNotNull(collection0);
    }

    @Test(timeout = 4000)
    public void edge_bag_test18() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = Character.valueOf('\u0081');
        // Undeclared exception!
        try {
            edgeBag0.get((Object) character0);
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Illegal input character \u0081.
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test19() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = new Character('\u0094');
        // Undeclared exception!
        try {
            edgeBag0.put(character0, (Edge) null);
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Illegal input character \u0094.
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test20() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        // Undeclared exception!
        try {
            edgeBag0.entrySet();
            fail("Expecting exception: UnsupportedOperationException");

        } catch (UnsupportedOperationException e) {
            //
            // Not implemented
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test21() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        // Undeclared exception!
        try {
            edgeBag0.putAll(edgeBag0);
            fail("Expecting exception: UnsupportedOperationException");

        } catch (UnsupportedOperationException e) {
            //
            // Not implemented
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test22() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        // Undeclared exception!
        try {
            edgeBag0.keySet();
            fail("Expecting exception: UnsupportedOperationException");

        } catch (UnsupportedOperationException e) {
            //
            // Not implemented
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test23() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Collection<Edge> collection0 = edgeBag0.values();
        // Undeclared exception!
        try {
            edgeBag0.containsValue(collection0);
            fail("Expecting exception: UnsupportedOperationException");

        } catch (UnsupportedOperationException e) {
            //
            // Not implemented
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test24() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        // Undeclared exception!
        try {
            edgeBag0.clear();
            fail("Expecting exception: UnsupportedOperationException");

        } catch (UnsupportedOperationException e) {
            //
            // Not implemented
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test25() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = new Character(')');
        // Undeclared exception!
        try {
            edgeBag0.remove((Object) character0);
            fail("Expecting exception: UnsupportedOperationException");

        } catch (UnsupportedOperationException e) {
            //
            // Not implemented
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void edge_bag_test26() throws Throwable {
        EdgeBag edgeBag0 = new EdgeBag();
        Character character0 = new Character('\\');
        // Undeclared exception!
        try {
            edgeBag0.containsKey(character0);
            fail("Expecting exception: UnsupportedOperationException");

        } catch (UnsupportedOperationException e) {
            //
            // Not implemented
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test00() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        generalizedSuffixTree0.put("net.mooctest.GeneralizedSuffixTree$Pair", 0);
        GeneralizedSuffixTree.ResultInfo generalizedSuffixTree_ResultInfo0 = generalizedSuffixTree0.searchWithCount("net.mooctest.Node", (-2894));
        assertNotNull(generalizedSuffixTree_ResultInfo0);
        assertEquals(0, generalizedSuffixTree_ResultInfo0.totalResults);
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test01() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        generalizedSuffixTree0.put("net.mooctest.EdgeBag", 1941);
        Collection<Integer> collection0 = generalizedSuffixTree0.search("n", 914);
        assertNotNull(collection0);
        assertTrue(collection0.contains(1941));
        assertFalse(collection0.contains(914));
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test02() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        generalizedSuffixTree0.put("GK6-%w", 0);
        int int0 = generalizedSuffixTree0.computeCount();
        assertEquals(1, int0);
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test03() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        // Undeclared exception!
        try {
            generalizedSuffixTree0.searchWithCount((String) null, 0);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.GeneralizedSuffixTree", e);
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test04() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        // Undeclared exception!
        try {
            generalizedSuffixTree0.search((String) null, (-1));
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.GeneralizedSuffixTree", e);
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test05() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        // Undeclared exception!
        try {
            generalizedSuffixTree0.search((String) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.GeneralizedSuffixTree", e);
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test06() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        generalizedSuffixTree0.put("#0VU:FO", 0);
        generalizedSuffixTree0.put("3U6$oU{t^\"(12j", 816);
        generalizedSuffixTree0.put(", expectep at least ", 2554);
        // Undeclared exception!
        generalizedSuffixTree0.put("net.mooctest.GeneralizedSuffixTree", 2554);
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test07() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        // Undeclared exception!
        try {
            generalizedSuffixTree0.put((String) null, 0);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.GeneralizedSuffixTree", e);
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test08() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        Node node0 = generalizedSuffixTree0.getRoot();
        assertNotNull(node0);

        Edge edge0 = new Edge("fFw|lD&V{g8V)l}jF$", node0);
        assertNotNull(edge0);

        node0.addEdge('O', edge0);
        // Undeclared exception!
        try {
            generalizedSuffixTree0.computeCount();
            fail("Expecting exception: StackOverflowError");

        } catch (StackOverflowError e) {
            //
            // no message in exception (getMessage() returned null)
            //
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test09() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        Node node0 = generalizedSuffixTree0.getRoot();
        assertNotNull(node0);

        node0.addEdge('O', (Edge) null);
        // Undeclared exception!
        try {
            generalizedSuffixTree0.computeCount();
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test10() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        Collection<Integer> collection0 = generalizedSuffixTree0.search("fFw|lD&V{g8V)l}jF$", 16);
        assertNotNull(collection0);
        assertFalse(collection0.contains(16));
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test11() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        generalizedSuffixTree0.put("net.mooctest.EdgeBag", 1941);
        Collection<Integer> collection0 = generalizedSuffixTree0.search("net.mooctest.EdgeBag", (-1));
        assertNotNull(collection0);
        assertTrue(collection0.contains(1941));
        assertFalse(collection0.contains((-1)));
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test12() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        assertNotNull(generalizedSuffixTree0);

        generalizedSuffixTree0.put("", 0);
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test13() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        Node node0 = generalizedSuffixTree0.getRoot();
        node0.setSuffix(node0);
        generalizedSuffixTree0.put("y1R:T:e]1*s#zo 2xn", 16);
        generalizedSuffixTree0.put("y1R:T:e]1*s#zo 2xn", 199);
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test14() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        generalizedSuffixTree0.put(",?expec7ep at least ", 2554);
        try {
            generalizedSuffixTree0.put(",?expec7ep at least ", 0);
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // The input index must not be less than any of the previously inserted ones. Got 0, expected at least 2554
            //
            verifyException("net.mooctest.GeneralizedSuffixTree", e);
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test15() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        generalizedSuffixTree0.put("getResultCount() shouldn't be call6d without calling computeCount( first", 0);
        // Undeclared exception!
        try {
            generalizedSuffixTree0.searchWithCount("getResultCount() shouldn't be call6d without calling computeCount( first", 0);
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // getResultCount() shouldn't be called without calling computeCount() first
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test16() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        Collection<Integer> collection0 = generalizedSuffixTree0.search("");
        assertNotNull(collection0);
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test17() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        int int0 = generalizedSuffixTree0.computeCount();
        assertEquals(0, int0);
    }

    @Test(timeout = 4000)
    public void generalized_suffix_tree_test18() throws Throwable {
        GeneralizedSuffixTree generalizedSuffixTree0 = new GeneralizedSuffixTree();
        Node node0 = generalizedSuffixTree0.getRoot();
        Collection<Integer> collection0 = node0.getData(16);
        GeneralizedSuffixTree.ResultInfo generalizedSuffixTree_ResultInfo0 = new GeneralizedSuffixTree.ResultInfo(collection0, 16);
        assertEquals(16, generalizedSuffixTree_ResultInfo0.totalResults);
    }


    @Test(timeout = 4000)
    public void node_test00() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        Node node1 = new Node();
        node0.setSuffix(node1);
        node0.addRef(1094);
        node0.getEdges();
        Node node2 = new Node();
        node0.setSuffix(node2);
        node0.setSuffix(node2);
        node2.addRef(1053);
        Edge edge0 = new Edge("G2T_~", node0);
        node2.addEdge('V', edge0);
        node1.setSuffix(node0);
        node2.addRef('V');
        node2.getData(1094);
        node1.getEdges();
        node0.getEdge('V');
        node2.getEdges();
        node0.computeAndCacheCount();
        node1.getData();
        node2.getData();
    }

    @Test(timeout = 4000)
    public void node_test01() throws Throwable {
        Node node0 = new Node();
        Node node1 = new Node();
        node0.setSuffix(node1);
        node0.addRef(1094);
        node0.getEdges();
        Node node2 = new Node();
        node0.setSuffix(node2);
        node0.setSuffix(node2);
        node2.addRef(1053);
        Node node3 = new Node();
        Edge edge0 = new Edge("G2T_~", node0);
        edge0.setLabel("");
        node3.addEdge('V', edge0);
        node1.setSuffix(node3);
        node2.getData(1094);
        node1.getEdges();
        node0.getEdge('V');
        node2.getEdges();
        node3.computeAndCacheCount();
        node0.getResultCount();
        node3.getData(1);
    }

    @Test(timeout = 4000)
    public void node_test02() throws Throwable {
        Node node0 = new Node();
        Node node1 = new Node();
        node0.setSuffix(node1);
        node0.addRef(1094);
        node0.getEdges();
        Node node2 = new Node();
        node0.setSuffix(node2);
        node0.setSuffix(node2);
        node2.addRef(1053);
        Node node3 = new Node();
        Edge edge0 = new Edge("G2T_~", node0);
        node3.addEdge('V', edge0);
        node1.setSuffix(node3);
        node2.addRef(0);
        node2.getData(1094);
        node1.getEdges();
        node0.getEdge('V');
        node2.getEdges();
        node3.computeAndCacheCount();
        node3.getData();
        node2.getData();
    }

    @Test(timeout = 4000)
    public void node_test03() throws Throwable {
        Node node0 = new Node();
        node0.addRef(1366);
        node0.computeAndCacheCount();
        Edge edge0 = new Edge("w8=cDkg", node0);
        edge0.setLabel((String) null);
        edge0.setLabel((String) null);
        node0.getData(0);
        edge0.setLabel("");
        // Undeclared exception!
        try {
            node0.addEdge('\u0084', edge0);
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Illegal input character \u0084.
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test04() throws Throwable {
        Node node0 = new Node();
        node0.computeAndCacheCount();
        node0.setSuffix(node0);
        node0.getData();
        node0.computeAndCacheCount();
        node0.getEdge('5');
        node0.addRef(0);
        node0.computeAndCacheCount();
        node0.getData((-1289));
        node0.addRef((-1289));
        Node node1 = node0.getSuffix();
        node1.getResultCount();
        node1.addRef((-696));
        node1.getData(2482);
        node0.setSuffix(node1);
        node0.getData();
        node0.getData();
    }

    @Test(timeout = 4000)
    public void node_test05() throws Throwable {
        Node node0 = new Node();
        Node node1 = new Node();
        node0.setSuffix(node1);
        Edge edge0 = new Edge((String) null, node0);
        edge0.setLabel("G2T_~");
        edge0.setLabel("G2T_~");
        node0.addEdge('V', edge0);
        node0.addRef(1094);
        node0.getEdges();
        node0.setSuffix(node0);
        node1.computeAndCacheCount();
        node1.addRef(0);
        node0.addRef(0);
        node1.getData(1094);
        node1.getEdges();
        node0.getEdge('V');
        node1.addEdge('V', edge0);
        node1.addRef(1);
    }

    @Test(timeout = 4000)
    public void node_test06() throws Throwable {
        Node node0 = new Node();
        node0.computeAndCacheCount();
        Node node1 = new Node();
        node0.setSuffix(node1);
        Node node2 = node0.getSuffix();
        node2.computeAndCacheCount();
        node2.getData(1134);
        node1.getEdge('T');
        node2.addEdge('T', (Edge) null);
        node0.getData(0);
        node2.getResultCount();
        node0.addRef(0);
        node0.getResultCount();
        node2.setSuffix(node0);
        node2.addRef(1134);
        node2.getResultCount();
        node2.getEdges();
        node2.getResultCount();
        node0.getData(3965);
    }

    @Test(timeout = 4000)
    public void node_test07() throws Throwable {
        Node node0 = new Node();
        char char0 = ')';
        char char1 = '\u0084';
        // Undeclared exception!
        try {
            node0.getEdge('\u0084');
            fail("Expecting exception: IllegalArgumentException");

        } catch (IllegalArgumentException e) {
            //
            // Illegal input character \u0084.
            //
            verifyException("net.mooctest.EdgeBag", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test08() throws Throwable {
        Node node0 = new Node();
        char char0 = '$';
        String string0 = "P)";
        char char1 = '!';
        node0.getEdge('!');
        node0.addEdge('<', (Edge) null);
        // Undeclared exception!
        try {
            node0.getData(1);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test09() throws Throwable {
        Node node0 = new Node();
        Node node1 = new Node();
        node1.getData();
        node0.addRef((-1));
        node0.computeAndCacheCount();
        node1.addRef(1);
        node1.addRef((-1));
        node0.getEdge('=');
        node1.addEdge('=', (Edge) null);
        // Undeclared exception!
        try {
            node1.getData((-1));
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test10() throws Throwable {
        Node node0 = new Node();
        node0.getSuffix();
        try {
            node0.getResultCount();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // getResultCount() shouldn't be called without calling computeCount() first
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test11() throws Throwable {
        Node node0 = new Node();
        Node node1 = new Node();
        node0.setSuffix(node1);
        node0.addRef((-2465));
        Node node2 = node0.getSuffix();
        node0.computeAndCacheCount();
        node2.setSuffix(node0);
        Node node3 = new Node();
        Edge edge0 = new Edge((String) null, node3);
        node1.addEdge('b', edge0);
        node2.addRef(1);
        node2.addRef(0);
        node2.computeAndCacheCount();
        node2.getData();
        Node node4 = node0.getSuffix();
        node4.getResultCount();
        node0.addEdge('b', edge0);
        node4.addRef((-1619));
        node2.getData(1);
        Node node5 = node2.getSuffix();
        node5.getResultCount();
        node2.setSuffix(node1);
        node1.getData((-1619));
        node0.addRef(0);
        node4.getSuffix();
    }

    @Test(timeout = 4000)
    public void node_test12() throws Throwable {
        Node node0 = new Node();
        node0.getData();
        Edge edge0 = new Edge((String) null, node0);
        node0.addEdge('\"', edge0);
        Node node1 = new Node();
        node0.getData(0);
        node1.getSuffix();
        try {
            node1.getResultCount();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // getResultCount() shouldn't be called without calling computeCount() first
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test13() throws Throwable {
        Node node0 = new Node();
        char char0 = ')';
        node0.getEdge(')');
        node0.addEdge('1', (Edge) null);
        // Undeclared exception!
        try {
            node0.computeAndCacheCount();
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test14() throws Throwable {
        Node node0 = new Node();
        node0.computeAndCacheCount();
        node0.setSuffix(node0);
        node0.getData();
        node0.computeAndCacheCount();
        node0.getEdge('5');
        node0.addRef(0);
        node0.computeAndCacheCount();
        node0.getData((-1289));
        node0.addRef((-1289));
        Node node1 = node0.getSuffix();
        node1.getData(2482);
        node0.setSuffix(node1);
        node0.getData();
    }

    @Test(timeout = 4000)
    public void node_test15() throws Throwable {
        Node node0 = new Node();
        Node node1 = new Node();
        node1.computeAndCacheCount();
        node0.setSuffix(node1);
        node0.addRef(655);
        Node node2 = node0.getSuffix();
        node0.setSuffix(node2);
        node1.addRef(2595);
        node2.addRef(0);
        node0.addRef(1923);
        node2.addRef(2595);
        node2.getResultCount();
        node0.addRef(1923);
        node0.getEdge('y');
        node0.setSuffix(node1);
    }

//    @Test(timeout = 4000)
//    public void node_test16() throws Throwable {
//        Node node0 = new Node();
//        node0.getData((-4047));
//        node0.getData((-4047));
//        node0.computeAndCacheCount();
//        node0.getResultCount();
//        Edge edge0 = new Edge("", node0);
//        edge0.setDest(node0);
//        edge0.setDest(node0);
//        node0.addEdge('|', edge0);
//        node0.addRef((-1914));
//        node0.getData(1);
//        node0.getData((-4047));
//        node0.getData();
//    }

    @Test(timeout = 4000)
    public void node_test17() throws Throwable {
        Node node0 = new Node();
        node0.getData(0);
        node0.addRef(0);
        node0.getData((-1));
        node0.addRef(0);
        try {
            node0.getResultCount();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // getResultCount() shouldn't be called without calling computeCount() first
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test18() throws Throwable {
        Node node0 = new Node();
        node0.getData();
        Node node1 = new Node();
        node0.setSuffix(node1);
        node1.getEdge('v');
        node0.addEdge('6', (Edge) null);
        node0.setSuffix(node1);
        // Undeclared exception!
        try {
            node0.getData();
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
        }
    }

    @Test(timeout = 4000)
    public void node_test19() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        Map<Character, Edge> map0 = node0.getEdges();
        assertNotNull(map0);
        assertEquals(0, map0.size());
        assertTrue(map0.isEmpty());

        Edge edge0 = node0.getEdge('$');
        assertNull(edge0);

        node0.addEdge('i', (Edge) null);
        // Undeclared exception!
        try {
            node0.computeAndCacheCount();
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.Node", e);
        }
    }

//    @Test(timeout = 4000)
//    public void node_test20() throws Throwable {
//        Node node0 = new Node();
//        assertNotNull(node0);
//
//        Node node1 = new Node();
//        assertFalse(node1.equals((Object) node0));
//        assertNotNull(node1);
//
//        Edge edge0 = new Edge("", node0);
//        assertFalse(node0.equals((Object) node1));
//        assertNotNull(edge0);
//        assertEquals("", edge0.getLabel());
//
//        node0.addEdge('R', edge0);
//        assertFalse(node0.equals((Object) node1));
//        assertNotSame(node0, node1);
//        assertEquals("", edge0.getLabel());
//
//        edge0.setDest(node1);
//        assertFalse(node0.equals((Object) node1));
//        assertFalse(node1.equals((Object) node0));
//        assertNotSame(node0, node1);
//        assertNotSame(node1, node0);
//        assertEquals("", edge0.getLabel());
//
//        node0.setSuffix(node1);
//        assertFalse(node0.equals((Object) node1));
//        assertFalse(node1.equals((Object) node0));
//        assertNotSame(node0, node1);
//        assertNotSame(node1, node0);
//
//        Node node2 = node0.getSuffix();
//        assertFalse(node0.equals((Object) node1));
//        assertFalse(node2.equals((Object) node0));
//        assertNotSame(node0, node2);
//        assertNotSame(node0, node1);
//        assertNotSame(node2, node0);
//        assertSame(node2, node1);
//        assertNotNull(node2);
//
//        edge0.setDest(node0);
//        assertFalse(node0.equals((Object) node2));
//        assertFalse(node0.equals((Object) node1));
//        assertNotSame(node0, node2);
//        assertNotSame(node0, node1);
//        assertEquals("", edge0.getLabel());
//
//        edge0.setLabel("");
//        assertFalse(node0.equals((Object) node2));
//        assertFalse(node0.equals((Object) node1));
//        assertNotSame(node0, node2);
//        assertNotSame(node0, node1);
//        assertEquals("", edge0.getLabel());
//
//        node0.addEdge('R', edge0);
//        assertFalse(node0.equals((Object) node2));
//        assertFalse(node0.equals((Object) node1));
//        assertNotSame(node0, node2);
//        assertNotSame(node0, node1);
//        assertEquals("", edge0.getLabel());
//
//        node2.addEdge('>', edge0);
//        assertFalse(node0.equals((Object) node2));
//        assertFalse(node0.equals((Object) node1));
//        assertFalse(node2.equals((Object) node0));
//        assertNotSame(node0, node2);
//        assertNotSame(node0, node1);
//        assertNotSame(node2, node0);
//        assertSame(node2, node1);
//        assertEquals("", edge0.getLabel());
//
//        node2.getData();
//    }

    @Test(timeout = 4000)
    public void node_test21() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        Edge edge0 = node0.getEdge('q');
        assertNull(edge0);

        node0.addEdge('q', (Edge) null);
        // Undeclared exception!
        try {
            node0.getData();
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
        }
    }

    @Test(timeout = 4000)
    public void node_test22() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        node0.setSuffix(node0);
        int int0 = (-1);
        node0.addRef((-1));
        node0.addRef((-1));
        Edge edge0 = node0.getEdge('\'');
        assertNull(edge0);

        try {
            node0.getResultCount();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // getResultCount() shouldn't be called without calling computeCount() first
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test23() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        Map<Character, Edge> map0 = node0.getEdges();
        assertNotNull(map0);
        assertTrue(map0.isEmpty());
        assertEquals(0, map0.size());

        Collection<Integer> collection0 = node0.getData();
        assertNotNull(collection0);

        Map<Character, Edge> map1 = node0.getEdges();
        assertSame(map1, map0);
        assertNotNull(map1);
        assertTrue(map1.isEmpty());
        assertEquals(0, map1.size());

        Map<Character, Edge> map2 = node0.getEdges();
        assertSame(map2, map1);
        assertSame(map2, map0);
        assertNotNull(map2);
        assertEquals(0, map2.size());
        assertTrue(map2.isEmpty());
    }

    @Test(timeout = 4000)
    public void node_test24() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        Node node1 = new Node();
        assertFalse(node1.equals((Object) node0));
        assertNotNull(node1);

        node0.setSuffix(node1);
        assertFalse(node0.equals((Object) node1));
        assertFalse(node1.equals((Object) node0));
        assertNotSame(node0, node1);
        assertNotSame(node1, node0);

        Collection<Integer> collection0 = node0.getData(1000);
        assertFalse(node0.equals((Object) node1));
        assertFalse(collection0.contains(1000));
        assertNotSame(node0, node1);
        assertNotNull(collection0);
    }

    @Test(timeout = 4000)
    public void node_test25() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        try {
            node0.getResultCount();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // getResultCount() shouldn't be called without calling computeCount() first
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test26() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        Node node1 = new Node();
        assertFalse(node1.equals((Object) node0));
        assertNotNull(node1);

        node0.setSuffix(node1);
        assertFalse(node0.equals((Object) node1));
        assertFalse(node1.equals((Object) node0));
        assertNotSame(node0, node1);
        assertNotSame(node1, node0);

        int int0 = node0.computeAndCacheCount();
        assertFalse(node0.equals((Object) node1));
        assertNotSame(node0, node1);
        assertEquals(0, int0);

        int int1 = node0.getResultCount();
        assertFalse(node0.equals((Object) node1));
        assertTrue(int1 == int0);
        assertNotSame(node0, node1);
        assertEquals(0, int1);

        int int2 = node0.getResultCount();
        assertFalse(node0.equals((Object) node1));
        assertTrue(int2 == int1);
        assertTrue(int2 == int0);
        assertNotSame(node0, node1);
        assertEquals(0, int2);

        node0.addRef(1);
        assertFalse(node0.equals((Object) node1));
        assertNotSame(node0, node1);

        node0.addRef((-1));
        assertFalse(node0.equals((Object) node1));
        assertNotSame(node0, node1);

        Map<Character, Edge> map0 = node0.getEdges();
        assertFalse(node0.equals((Object) node1));
        assertNotSame(node0, node1);
        assertNotNull(map0);
        assertEquals(0, map0.size());
        assertTrue(map0.isEmpty());

        node1.addRef(0);
        assertFalse(node1.equals((Object) node0));
        assertNotSame(node1, node0);
    }

    @Test(timeout = 4000)
    public void node_test27() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        node0.addRef((-1));
        node0.addRef((-1));
        Node node1 = node0.getSuffix();
        assertNull(node1);

        try {
            node0.getResultCount();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // getResultCount() shouldn't be called without calling computeCount() first
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test28() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        node0.addRef(0);
    }

    @Test(timeout = 4000)
    public void node_test29() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        Collection<Integer> collection0 = node0.getData();
        assertNotNull(collection0);

        node0.addRef((-441));
        Collection<Integer> collection1 = node0.getData((-2630));
        assertFalse(collection1.equals((Object) collection0));
        assertTrue(collection1.contains((-441)));
        assertFalse(collection1.contains((-2630)));
        assertNotSame(collection1, collection0);
        assertNotNull(collection1);

        int int0 = node0.computeAndCacheCount();
        assertEquals(1, int0);

        Node node1 = new Node();
        assertFalse(node1.equals((Object) node0));
        assertNotNull(node1);

        node0.setSuffix(node1);
        assertFalse(node0.equals((Object) node1));
        assertFalse(node1.equals((Object) node0));
        assertNotSame(node0, node1);
        assertNotSame(node1, node0);

        Character character0 = new Character(':');
        assertNotNull(character0);
        assertEquals(':', (char) character0);

        int int1 = node0.getResultCount();
        assertFalse(node0.equals((Object) node1));
        assertTrue(int1 == int0);
        assertNotSame(node0, node1);
        assertEquals(1, int1);

        Collection<Integer> collection2 = node0.getData(1);
        assertFalse(node0.equals((Object) node1));
        assertTrue(collection2.equals((Object) collection1));
        assertFalse(collection2.equals((Object) collection0));
        assertTrue(collection2.contains((-441)));
        assertFalse(collection2.contains(1));
        assertNotSame(node0, node1);
        assertNotSame(collection2, collection1);
        assertNotSame(collection2, collection0);
        assertNotNull(collection2);

        try {
            node1.getResultCount();
            fail("Expecting exception: IllegalStateException");

        } catch (IllegalStateException e) {
            //
            // getResultCount() shouldn't be called without calling computeCount() first
            //
            verifyException("net.mooctest.Node", e);
        }
    }

    @Test(timeout = 4000)
    public void node_test30() throws Throwable {
        Node node0 = new Node();
        assertNotNull(node0);

        Collection<Integer> collection0 = node0.getData();
        assertNotNull(collection0);

        int int0 = node0.computeAndCacheCount();
        assertEquals(0, int0);

        Collection<Integer> collection1 = node0.getData();
        assertTrue(collection1.equals((Object) collection0));
        assertFalse(collection1.contains(int0));
        assertNotSame(collection1, collection0);
        assertNotNull(collection1);

        Collection<Integer> collection2 = node0.getData();
        assertTrue(collection2.equals((Object) collection1));
        assertTrue(collection2.equals((Object) collection0));
        assertFalse(collection2.contains(int0));
        assertNotSame(collection2, collection0);
        assertNotSame(collection2, collection1);
        assertNotNull(collection2);

        Collection<Integer> collection3 = node0.getData(0);
        assertTrue(collection3.equals((Object) collection0));
        assertTrue(collection3.equals((Object) collection2));
        assertTrue(collection3.equals((Object) collection1));
        assertFalse(collection3.contains(0));
        assertNotSame(collection3, collection1);
        assertNotSame(collection3, collection0);
        assertNotSame(collection3, collection2);
        assertNotNull(collection3);

        node0.addRef(0);
        node0.addRef(0);
        int int1 = node0.getResultCount();
        assertTrue(int1 == int0);
        assertEquals(0, int1);

        Collection<Integer> collection4 = node0.getData((-1));
        assertFalse(collection4.equals((Object) collection2));
        assertFalse(collection4.equals((Object) collection1));
        assertFalse(collection4.equals((Object) collection0));
        assertFalse(collection4.equals((Object) collection3));
        assertFalse(collection4.contains((-1)));
        assertTrue(collection4.contains(0));
        assertNotSame(collection4, collection2);
        assertNotSame(collection4, collection1);
        assertNotSame(collection4, collection0);
        assertNotSame(collection4, collection3);
        assertNotNull(collection4);
    }

    @Test(timeout = 4000)
    public void node_test31() throws Throwable {
        Node node0 = new Node();
        node0.computeAndCacheCount();
        node0.setSuffix(node0);
        Node node1 = node0.getSuffix();
        node1.computeAndCacheCount();
        node1.getData(1134);
        node0.getEdge('T');
        node0.addEdge('T', (Edge) null);
        node0.getData((-1215));
        node0.getEdge('T');
        node1.addEdge('T', (Edge) null);
        node0.getData(0);
        node1.getResultCount();
        node0.addRef(0);
        node0.getResultCount();
        node1.setSuffix(node0);
        node1.addRef(1134);
        node1.getResultCount();
        node1.getEdges();
        node1.getResultCount();
        // Undeclared exception!
        try {
            node0.getData(3965);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
        }
    }

    @Test(timeout = 4000)
    public void node_test32() throws Throwable {
        Node node0 = new Node();
        Node node1 = new Node();
        node0.setSuffix(node1);
        node0.addRef(1094);
        node0.getEdges();
        Node node2 = new Node();
        node0.setSuffix(node2);
        node0.setSuffix(node2);
        node2.addRef(1053);
        Node node3 = new Node();
        Edge edge0 = new Edge("G2T_~", node0);
        node3.addEdge('V', edge0);
        node1.setSuffix(node3);
        node2.addRef(0);
        node2.getData(1094);
        node1.getEdges();
        node0.getEdge('V');
        node0.addRef(1391);
        node2.getEdges();
        node3.computeAndCacheCount();
        Collection<Integer> collection0 = node3.getData();
        Collection<Integer> collection1 = node2.getData();
        assertTrue(collection1.contains(1391));

        Collection<Integer> collection2 = node3.getData(2);
        assertTrue(collection2.equals((Object) collection0));
        assertTrue(collection2.contains(1391));

        Collection<Integer> collection3 = node2.getData(2);
        assertFalse(collection3.equals((Object) collection1));

        int int0 = node0.getResultCount();
        assertEquals(2, int0);
    }

    @Test(timeout = 4000)
    public void utils_test0() throws Throwable {
        String string0 = Utils.normalize("9");
        assertEquals("9", string0);
    }

    @Test(timeout = 4000)
    public void utils_test1() throws Throwable {
        String string0 = Utils.normalize("`Xtt_[4l$sj.010");
        assertEquals("xtt4lsj010", string0);
    }

    @Test(timeout = 4000)
    public void utils_test2() throws Throwable {
        String string0 = Utils.normalize("qkVpOCHZ`");
        assertEquals("qkvpochz", string0);
    }

    @Test(timeout = 4000)
    public void utils_test3() throws Throwable {
        String string0 = Utils.normalize("");
        assertEquals("", string0);
    }

    @Test(timeout = 4000)
    public void utils_test4() throws Throwable {
        Set<String> set0 = Utils.getSubstrings("");
        assertFalse(set0.contains(""));
    }

    @Test(timeout = 4000)
    public void utils_test5() throws Throwable {
        // Undeclared exception!
        try {
            Utils.normalize((String) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.Utils", e);
        }
    }

    @Test(timeout = 4000)
    public void utils_test6() throws Throwable {
        // Undeclared exception!
        try {
            Utils.getSubstrings((String) null);
            fail("Expecting exception: NullPointerException");

        } catch (NullPointerException e) {
            //
            // no message in exception (getMessage() returned null)
            //
            verifyException("net.mooctest.Utils", e);
        }
    }

    @Test(timeout = 4000)
    public void utils_test7() throws Throwable {
        Set<String> set0 = Utils.getSubstrings("A'(I?Mg{d{wOh3Riqpr");
        assertEquals(189, set0.size());
    }

    @Test(timeout = 4000)
    public void utils_test8() throws Throwable {
        String string0 = Utils.normalize("A'(I?Mg{d{wOh3Riqpr");
        assertEquals("aimgdwoh3riqpr", string0);
    }

    @Test(timeout = 4000)
    public void utils_test9() throws Throwable {
        Utils utils0 = new Utils();
    }
}

