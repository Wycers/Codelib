package net.mooctest;

import static org.junit.Assert.*;

import org.junit.Test;

import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class AStarTest {

    @Test
    public void testConstructor0() {
        AStar<Integer> aStar = new AStar<Integer>();
        Graph<Integer> graph = new Graph();
        graph = new Graph();
        assertEquals(Graph.TYPE.UNDIRECTED, graph.getType());
    }

    @Test
    public void testConstructor1() {
        Graph<Integer> graph = new Graph();
        graph = new Graph(Graph.TYPE.DIRECTED);
        assertEquals(Graph.TYPE.DIRECTED, graph.getType());
    }

    @Test
    public void testConstructor2() {
        Graph<Integer> graph = new Graph();
        graph = new Graph(Graph.TYPE.DIRECTED);
        graph.hashCode();
        assertEquals(Graph.TYPE.DIRECTED, graph.getType());
        assertEquals("", graph.toString());
        assertTrue(graph.equals(graph));
    }

    @Test
    public void testConstructor3() {
        Graph<Integer> graph = new Graph();
        try {
            graph = new Graph(null, null);
            fail();
        } catch (Exception e) {

        }
    }

    @Test
    public void test12() {
        try {
            new Graph.CostPathPair<Integer>(1, null);
            fail();
        } catch (Exception e) {

        }
//        Graph.CostPathPair<Integer> pair = new Graph.CostPathPair<Integer>(1, null);
//        assertEquals(1, pair.getCost());
    }

    @Test
    public void testEdgeEqual() {
        int n = 5;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(i));
        }
        Graph.Edge<Integer> a = new Graph.Edge<Integer>(0, vertices.get(0), vertices.get(1));
        Graph.Edge<Integer> b = new Graph.Edge<Integer>(1, vertices.get(0), vertices.get(1));
        Graph.Edge<Integer> c = new Graph.Edge<Integer>(1, vertices.get(1), vertices.get(1));
        Graph.Edge<Integer> d = new Graph.Edge<Integer>(1, vertices.get(1), vertices.get(0));
        Graph.Edge<Integer> e = new Graph.Edge<Integer>(1, vertices.get(1), vertices.get(1));

        assertFalse(a.equals(vertices.get(0)));
        assertFalse(a.equals(b));
        assertFalse(b.equals(c));
        assertFalse(c.equals(d));
        assertFalse(d.equals(e));
        assertTrue(e.equals(e));
    }

    public int cmp(List<Graph.Vertex<Integer>> vertices, int i, int j) {
        return vertices.get(i).compareTo(vertices.get(j));
    }

    @Test
    public void testVertexCmp() {
        int n = 5;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(233));
        }
        List<Graph.Edge<Integer>> edges = new ArrayList<Graph.Edge<Integer>>();
        for (int i = 0; i < n - 1; ++i) {
            edges.add(new Graph.Edge<Integer>(i, vertices.get(i), vertices.get(i + 1)));
        }
        Graph.Vertex<Integer> gg = new Graph.Vertex<Integer>(222);
        assertEquals(-1, gg.compareTo(vertices.get(0)));

        vertices.get(0).setWeight(0);
        vertices.get(1).setWeight(1);
        assertEquals(-1, cmp(vertices, 0, 1));
        assertEquals(1, cmp(vertices, 1, 0));

        vertices.get(2).setWeight(1);
        vertices.get(2).addEdge(edges.get(0));
        assertEquals(1, cmp(vertices, 2, 1));
        assertEquals(-1, cmp(vertices, 1, 2));

        assertEquals("Value=233 weight=1\n" +
                "\t[ 233(0) ] -> [ 233(1) ] = 0\n", vertices.get(2).toString());
    }

    @Test
    public void testEdgeConstructor() {
        int n = 5;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(i));
        }
        try {
            Graph.Edge<Integer> a = new Graph.Edge<Integer>(-1, null, null);
            fail();
        } catch (Exception e) {

        }

        try {
            Graph.Edge<Integer> a = new Graph.Edge<Integer>(-1, vertices.get(0), null);
            fail();
        } catch (Exception e) {

        }
        Graph.Edge<Integer> a = new Graph.Edge<Integer>(-1, vertices.get(0), vertices.get(1));
        Graph.Edge<Integer> b = new Graph.Edge<>(a);
        assertEquals(a, b);

        a.setCost(100);
        assertEquals(100, a.getCost());
        assertEquals(0, a.hashCode());
    }

    @Test
    public void testEdgeCmp() {
        int n = 5;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(i));
        }
        Graph.Edge<Integer> a = new Graph.Edge<Integer>(-1, vertices.get(0), vertices.get(1));
        Graph.Edge<Integer> b = new Graph.Edge<Integer>(0, vertices.get(0), vertices.get(1));
        Graph.Edge<Integer> c = new Graph.Edge<Integer>(1, vertices.get(1), vertices.get(1));
        Graph.Edge<Integer> d = new Graph.Edge<Integer>(1, vertices.get(1), vertices.get(0));
        Graph.Edge<Integer> e = new Graph.Edge<Integer>(1, vertices.get(2), vertices.get(1));
        Graph.Edge<Integer> f = new Graph.Edge<Integer>(1, vertices.get(1), vertices.get(1));

        assertEquals(-1, a.compareTo(b));
        assertEquals(1, c.compareTo(b));
        assertEquals(0, a.compareTo(a));

        e.getFromVertex().setWeight(232);
        d.getFromVertex().setWeight(233);
        assertEquals(1, e.compareTo(d));

        f.getFromVertex().setWeight(233);
        d.getToVertex().setWeight(234);
        f.getToVertex().setWeight(233);
        assertEquals(1, f.compareTo(d));

        String res = "";
        for (int i = 0; i < n; ++i) {
            res += vertices.get(i).toString();
        }
        assertEquals("Value=0 weight=234\n" +
                "Value=1 weight=233\n" +
                "Value=2 weight=232\n" +
                "Value=3 weight=0\n" +
                "Value=4 weight=0\n", res);

        res = "";
        res += a.toString();
        res += b.toString();
        res += c.toString();
        res += d.toString();
        res += e.toString();
        res += f.toString();

        assertEquals("[ 0(234) ] -> [ 1(233) ] = -1\n" +
                "[ 0(234) ] -> [ 1(233) ] = 0\n" +
                "[ 1(233) ] -> [ 1(233) ] = 1\n" +
                "[ 1(233) ] -> [ 0(234) ] = 1\n" +
                "[ 2(232) ] -> [ 1(233) ] = 1\n" +
                "[ 1(233) ] -> [ 1(233) ] = 1\n", res);

    }

    @Test
    public void test13() {
        Graph<Integer> graph = new Graph();
        graph = new Graph(Graph.TYPE.DIRECTED);

        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        Graph.Vertex<Integer> a = new Graph.Vertex<Integer>(1);
        Graph.Vertex<Integer> b = new Graph.Vertex<Integer>(2);
        Graph.Vertex<Integer> c = new Graph.Vertex<Integer>(3);
        vertices.add(a);
        vertices.add(b);
        vertices.add(c);

        Graph.Vertex<Integer> d = new Graph.Vertex<Integer>(c);
        assertEquals(new Integer(3), d.getValue());
        assertEquals(0, d.getWeight());

        d.setWeight(233);
        assertEquals(233, d.getWeight());
        assertEquals(7316, d.hashCode());
        assertFalse(d.equals(null));
        assertFalse(d.equals(a));

        a.setWeight(233);
        d.addEdge(new Graph.Edge<Integer>(1, d, c));
        assertFalse(d.equals(a));

        b.setWeight(233);
        b.addEdge(new Graph.Edge<Integer>(1, c, d));
        assertFalse(d.equals(b));

        c.setWeight(233);
        c.addEdge(new Graph.Edge<Integer>(2, d, c));
        assertFalse(d.equals(b));


        a.addEdge(new Graph.Edge<Integer>(1, a, c));
        a.addEdge(new Graph.Edge<Integer>(1, a, b));

        assertEquals(0, d.compareTo(a) + a.compareTo(d));
        assertEquals(0, d.compareTo(b) + b.compareTo(d));
        assertEquals(0, d.compareTo(c) + c.compareTo(d));
        assertEquals(0, d.compareTo(d) + d.compareTo(d));

        assertEquals(0, c.compareTo(a) + a.compareTo(c));
        assertEquals(0, c.compareTo(b) + b.compareTo(c));
        assertEquals(0, c.compareTo(c) + c.compareTo(c));

        assertEquals(0, b.compareTo(a) + a.compareTo(b));
        assertEquals(0, b.compareTo(b) + b.compareTo(b));

        assertEquals(0, a.compareTo(a) + a.compareTo(a));


        assertFalse(d.pathTo(a));
        d.addEdge(new Graph.Edge<Integer>(1, d, a));
        d.addEdge(new Graph.Edge<Integer>(1, d, c));
        assertTrue(d.pathTo(a));

        List<Graph.Edge<Integer>> edges = new ArrayList<Graph.Edge<Integer>>();
        edges.add(new Graph.Edge<Integer>(3, a, c));
        edges.add(new Graph.Edge<Integer>(1, a, b));
        edges.add(new Graph.Edge<Integer>(1, b, c));

    }


    @org.junit.Test
    public void test0() {
        net.mooctest.AStar<java.lang.Integer> aStar = new net.mooctest.AStar<java.lang.Integer>();
        net.mooctest.Graph<java.lang.Integer> graph = new net.mooctest.Graph();
        graph = new net.mooctest.Graph();
        org.junit.Assert.assertEquals(net.mooctest.Graph.TYPE.UNDIRECTED, graph.getType());
    }

    @org.junit.Test
    public void test1() {
        net.mooctest.Graph<java.lang.Integer> graph = new net.mooctest.Graph();
        graph = new net.mooctest.Graph(net.mooctest.Graph.TYPE.DIRECTED);
        org.junit.Assert.assertEquals(net.mooctest.Graph.TYPE.DIRECTED, graph.getType());
    }

    @Test
    public void testGraphConstructor() {

        int n = 5;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(233));
            assertEquals(null, vertices.get(i).getEdge(vertices.get(i)));
        }
        List<Graph.Edge<Integer>> edges = new ArrayList<Graph.Edge<Integer>>();
        for (int i = 0; i < n - 1; ++i) {
            edges.add(new Graph.Edge<Integer>(i, vertices.get(i), vertices.get(i + 1)));
        }

        Graph g = new Graph(vertices, edges);
        Graph<Integer> graph = new Graph(g);
        assertEquals(vertices, g.getVertices());
        String test = "";
        for (Graph.Edge<Integer> e: graph.getEdges()) {
            test += e.toString();
        }
        assertEquals("[ 233(0) ] -> [ 233(0) ] = 0\n" +
                "[ 233(0) ] -> [ 233(0) ] = 0\n" +
                "[ 233(0) ] -> [ 233(0) ] = 1\n" +
                "[ 233(0) ] -> [ 233(0) ] = 1\n" +
                "[ 233(0) ] -> [ 233(0) ] = 2\n" +
                "[ 233(0) ] -> [ 233(0) ] = 2\n" +
                "[ 233(0) ] -> [ 233(0) ] = 3\n" +
                "[ 233(0) ] -> [ 233(0) ] = 3\n", test);


        edges.add(new Graph.Edge<Integer>(1, vertices.get(0), new Graph.Vertex<Integer>(233)));
        g = new Graph(Graph.TYPE.DIRECTED, vertices, edges);
        assertEquals(Graph.TYPE.DIRECTED, g.getType());
        assertEquals(vertices, g.getVertices());
        assertEquals("Value=233 weight=0\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 0\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 0\n" +
                "Value=233 weight=0\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 0\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 1\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 1\n" +
                "Value=233 weight=0\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 1\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 2\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 2\n" +
                "Value=233 weight=0\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 2\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 3\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 3\n" +
                "Value=233 weight=0\n" +
                "\t[ 233(0) ] -> [ 233(0) ] = 3\n", g.toString());
    }
    @Test
    public void testGraphConstructorg() {

        int n = 5;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(233));
        }
        List<Graph.Edge<Integer>> edges = new ArrayList<Graph.Edge<Integer>>();
        for (int i = 0; i < n - 1; ++i) {
            edges.add(new Graph.Edge<Integer>(i, vertices.get(i), vertices.get(i + 1)));
        }

        List<Graph.Vertex<Integer>> testVertices = new ArrayList<Graph.Vertex<Integer>>();
        List<Graph.Edge<Integer>> testEdges = new ArrayList<Graph.Edge<Integer>>();

        testVertices.add(vertices.get(0));
        testVertices.add(vertices.get(1));
        testEdges.add(new Graph.Edge<>(0, vertices.get(2), vertices.get(1)));
        Graph g = new Graph(testVertices, testEdges);

        testEdges = new ArrayList<Graph.Edge<Integer>>();
        testEdges.add(new Graph.Edge<>(0, vertices.get(1), vertices.get(2)));
        g = new Graph(testVertices, testEdges);

        testEdges = new ArrayList<Graph.Edge<Integer>>();
        testEdges.add(new Graph.Edge<>(0, vertices.get(1), vertices.get(1)));
        g = new Graph(testVertices, testEdges);

        testEdges = new ArrayList<Graph.Edge<Integer>>();
        testEdges.add(new Graph.Edge<>(0, vertices.get(2), vertices.get(2)));
        g = new Graph(testVertices, testEdges);
    }

    @Test
    public void testAStar() {
        int n = 5;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(233));
        }
        List<Graph.Edge<Integer>> edges = new ArrayList<Graph.Edge<Integer>>();
        for (int i = 0; i < n - 1; ++i) {
            edges.add(new Graph.Edge<Integer>(i, vertices.get(i), vertices.get(i + 1)));
        }
        edges.add(new Graph.Edge<Integer>(1, vertices.get(2), vertices.get(4)));

        Graph g = new Graph(vertices, edges);

        AStar a = new AStar();
        List<Graph.Edge<Integer>> res = a.aStar(g, vertices.get(0), vertices.get(1));
        String test = "";
        for (Graph.Edge<Integer> e: res) {
            test += e.toString();
        }
        assertEquals("[ 233(0) ] -> [ 233(0) ] = 0\n", test);
    }

    @Test
    public void testAStarRandom() {

        Graph<Integer> graph = new Graph();

        Random nmd = new Random(233);
        int n = 100;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(nmd.nextInt(50)));
        }
        List<Graph.Edge<Integer>> edges = new ArrayList<Graph.Edge<Integer>>();
        for (int i = 0; i < n * n; ++i) {
            edges.add(new Graph.Edge<Integer>(nmd.nextInt(100), vertices.get(nmd.nextInt(100)), vertices.get(nmd.nextInt(100))));
        }
        Graph g = new Graph(vertices, edges);
        AStar a = new AStar();
        List<Graph.Edge<Integer>> res = a.aStar(g, vertices.get(0), vertices.get(1));

        String test = "";
        for (Graph.Edge<Integer> e: res) {
            test += e.toString();
        }
        assertEquals("[ 22(0) ] -> [ 9(0) ] = 1\n" +
                "[ 9(0) ] -> [ 11(0) ] = 1\n" +
                "[ 11(0) ] -> [ 45(0) ] = 1\n" +
                "[ 45(0) ] -> [ 18(0) ] = 0\n" +
                "[ 18(0) ] -> [ 11(0) ] = 1\n" +
                "[ 11(0) ] -> [ 12(0) ] = 1\n", test);

    }


    @Test
    public void testCostPathPair() {
        int n = 100;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(i));
        }
        List<Graph.Edge<Integer>> edges = new ArrayList<Graph.Edge<Integer>>();
        List<Graph.Edge<Integer>> edges2 = new ArrayList<Graph.Edge<Integer>>();
        Graph.CostPathPair<Integer> cpp = new Graph.CostPathPair<Integer>(1, edges);
        Graph.CostPathPair<Integer> cpp2 = new Graph.CostPathPair<Integer>(1, edges2);
        assertTrue(cpp.equals(cpp2));

        edges2.add(new Graph.Edge<Integer>(1, vertices.get(5), vertices.get(0)));

        for (int i = 0; i < n - 1; ++i) {
            edges.add(new Graph.Edge<Integer>(i, vertices.get(i), vertices.get(i + 1)));
            edges2.add(new Graph.Edge<Integer>(i, vertices.get(i), vertices.get(i + 1)));
        }

        assertFalse(cpp.equals(cpp2));
        assertFalse(cpp2.equals(cpp));
    }

    @Test
    public void testCostPathPair2() {
        int n = 100;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(i));
        }
        List<Graph.Edge<Integer>> edges = new ArrayList<Graph.Edge<Integer>>();
        for (int i = 0; i < n - 1; ++i) {
            edges.add(new Graph.Edge<Integer>(i, vertices.get(i), vertices.get(i + 1)));
        }

        Graph.CostPathPair<Integer> cpp = new Graph.CostPathPair<Integer>(1, edges);
        Graph.CostPathPair<Integer> cpp2 = new Graph.CostPathPair<Integer>(1, edges);

        assertEquals(1, cpp.getCost());
        cpp.setCost(200);
        assertEquals(200, cpp.getCost());

        assertEquals(edges, cpp.getPath());
        assertEquals(0, cpp.hashCode());
        assertEquals("Cost = 200\n" +
                "\t[ 0(0) ] -> [ 1(0) ] = 0\n" +
                "\t[ 1(0) ] -> [ 2(0) ] = 1\n" +
                "\t[ 2(0) ] -> [ 3(0) ] = 2\n" +
                "\t[ 3(0) ] -> [ 4(0) ] = 3\n" +
                "\t[ 4(0) ] -> [ 5(0) ] = 4\n" +
                "\t[ 5(0) ] -> [ 6(0) ] = 5\n" +
                "\t[ 6(0) ] -> [ 7(0) ] = 6\n" +
                "\t[ 7(0) ] -> [ 8(0) ] = 7\n" +
                "\t[ 8(0) ] -> [ 9(0) ] = 8\n" +
                "\t[ 9(0) ] -> [ 10(0) ] = 9\n" +
                "\t[ 10(0) ] -> [ 11(0) ] = 10\n" +
                "\t[ 11(0) ] -> [ 12(0) ] = 11\n" +
                "\t[ 12(0) ] -> [ 13(0) ] = 12\n" +
                "\t[ 13(0) ] -> [ 14(0) ] = 13\n" +
                "\t[ 14(0) ] -> [ 15(0) ] = 14\n" +
                "\t[ 15(0) ] -> [ 16(0) ] = 15\n" +
                "\t[ 16(0) ] -> [ 17(0) ] = 16\n" +
                "\t[ 17(0) ] -> [ 18(0) ] = 17\n" +
                "\t[ 18(0) ] -> [ 19(0) ] = 18\n" +
                "\t[ 19(0) ] -> [ 20(0) ] = 19\n" +
                "\t[ 20(0) ] -> [ 21(0) ] = 20\n" +
                "\t[ 21(0) ] -> [ 22(0) ] = 21\n" +
                "\t[ 22(0) ] -> [ 23(0) ] = 22\n" +
                "\t[ 23(0) ] -> [ 24(0) ] = 23\n" +
                "\t[ 24(0) ] -> [ 25(0) ] = 24\n" +
                "\t[ 25(0) ] -> [ 26(0) ] = 25\n" +
                "\t[ 26(0) ] -> [ 27(0) ] = 26\n" +
                "\t[ 27(0) ] -> [ 28(0) ] = 27\n" +
                "\t[ 28(0) ] -> [ 29(0) ] = 28\n" +
                "\t[ 29(0) ] -> [ 30(0) ] = 29\n" +
                "\t[ 30(0) ] -> [ 31(0) ] = 30\n" +
                "\t[ 31(0) ] -> [ 32(0) ] = 31\n" +
                "\t[ 32(0) ] -> [ 33(0) ] = 32\n" +
                "\t[ 33(0) ] -> [ 34(0) ] = 33\n" +
                "\t[ 34(0) ] -> [ 35(0) ] = 34\n" +
                "\t[ 35(0) ] -> [ 36(0) ] = 35\n" +
                "\t[ 36(0) ] -> [ 37(0) ] = 36\n" +
                "\t[ 37(0) ] -> [ 38(0) ] = 37\n" +
                "\t[ 38(0) ] -> [ 39(0) ] = 38\n" +
                "\t[ 39(0) ] -> [ 40(0) ] = 39\n" +
                "\t[ 40(0) ] -> [ 41(0) ] = 40\n" +
                "\t[ 41(0) ] -> [ 42(0) ] = 41\n" +
                "\t[ 42(0) ] -> [ 43(0) ] = 42\n" +
                "\t[ 43(0) ] -> [ 44(0) ] = 43\n" +
                "\t[ 44(0) ] -> [ 45(0) ] = 44\n" +
                "\t[ 45(0) ] -> [ 46(0) ] = 45\n" +
                "\t[ 46(0) ] -> [ 47(0) ] = 46\n" +
                "\t[ 47(0) ] -> [ 48(0) ] = 47\n" +
                "\t[ 48(0) ] -> [ 49(0) ] = 48\n" +
                "\t[ 49(0) ] -> [ 50(0) ] = 49\n" +
                "\t[ 50(0) ] -> [ 51(0) ] = 50\n" +
                "\t[ 51(0) ] -> [ 52(0) ] = 51\n" +
                "\t[ 52(0) ] -> [ 53(0) ] = 52\n" +
                "\t[ 53(0) ] -> [ 54(0) ] = 53\n" +
                "\t[ 54(0) ] -> [ 55(0) ] = 54\n" +
                "\t[ 55(0) ] -> [ 56(0) ] = 55\n" +
                "\t[ 56(0) ] -> [ 57(0) ] = 56\n" +
                "\t[ 57(0) ] -> [ 58(0) ] = 57\n" +
                "\t[ 58(0) ] -> [ 59(0) ] = 58\n" +
                "\t[ 59(0) ] -> [ 60(0) ] = 59\n" +
                "\t[ 60(0) ] -> [ 61(0) ] = 60\n" +
                "\t[ 61(0) ] -> [ 62(0) ] = 61\n" +
                "\t[ 62(0) ] -> [ 63(0) ] = 62\n" +
                "\t[ 63(0) ] -> [ 64(0) ] = 63\n" +
                "\t[ 64(0) ] -> [ 65(0) ] = 64\n" +
                "\t[ 65(0) ] -> [ 66(0) ] = 65\n" +
                "\t[ 66(0) ] -> [ 67(0) ] = 66\n" +
                "\t[ 67(0) ] -> [ 68(0) ] = 67\n" +
                "\t[ 68(0) ] -> [ 69(0) ] = 68\n" +
                "\t[ 69(0) ] -> [ 70(0) ] = 69\n" +
                "\t[ 70(0) ] -> [ 71(0) ] = 70\n" +
                "\t[ 71(0) ] -> [ 72(0) ] = 71\n" +
                "\t[ 72(0) ] -> [ 73(0) ] = 72\n" +
                "\t[ 73(0) ] -> [ 74(0) ] = 73\n" +
                "\t[ 74(0) ] -> [ 75(0) ] = 74\n" +
                "\t[ 75(0) ] -> [ 76(0) ] = 75\n" +
                "\t[ 76(0) ] -> [ 77(0) ] = 76\n" +
                "\t[ 77(0) ] -> [ 78(0) ] = 77\n" +
                "\t[ 78(0) ] -> [ 79(0) ] = 78\n" +
                "\t[ 79(0) ] -> [ 80(0) ] = 79\n" +
                "\t[ 80(0) ] -> [ 81(0) ] = 80\n" +
                "\t[ 81(0) ] -> [ 82(0) ] = 81\n" +
                "\t[ 82(0) ] -> [ 83(0) ] = 82\n" +
                "\t[ 83(0) ] -> [ 84(0) ] = 83\n" +
                "\t[ 84(0) ] -> [ 85(0) ] = 84\n" +
                "\t[ 85(0) ] -> [ 86(0) ] = 85\n" +
                "\t[ 86(0) ] -> [ 87(0) ] = 86\n" +
                "\t[ 87(0) ] -> [ 88(0) ] = 87\n" +
                "\t[ 88(0) ] -> [ 89(0) ] = 88\n" +
                "\t[ 89(0) ] -> [ 90(0) ] = 89\n" +
                "\t[ 90(0) ] -> [ 91(0) ] = 90\n" +
                "\t[ 91(0) ] -> [ 92(0) ] = 91\n" +
                "\t[ 92(0) ] -> [ 93(0) ] = 92\n" +
                "\t[ 93(0) ] -> [ 94(0) ] = 93\n" +
                "\t[ 94(0) ] -> [ 95(0) ] = 94\n" +
                "\t[ 95(0) ] -> [ 96(0) ] = 95\n" +
                "\t[ 96(0) ] -> [ 97(0) ] = 96\n" +
                "\t[ 97(0) ] -> [ 98(0) ] = 97\n" +
                "\t[ 98(0) ] -> [ 99(0) ] = 98\n", cpp.toString());

        assertFalse(cpp.equals(null));
        assertFalse(cpp.equals(cpp2));
        assertTrue(cpp.equals(cpp));
    }

    @Test
    public void testCostVertex() {
        try {
            Graph.CostVertexPair<Integer> cvp = new Graph.CostVertexPair<Integer>(1, null);
            fail();
        } catch(Exception e) {

        }

        int n = 5;
        List<Graph.Vertex<Integer>> vertices = new ArrayList<Graph.Vertex<Integer>>();
        for (int i = 0; i < n; ++i) {
            vertices.add(new Graph.Vertex<Integer>(233));
        }
        Graph.CostVertexPair<Integer> cvp = new Graph.CostVertexPair<Integer>(1, vertices.get(0));

        assertEquals(1, cvp.getCost());
        cvp.setCost(100);
        assertEquals(100, cvp.getCost());
        assertEquals(vertices.get(0), cvp.getVertex());
    }
}