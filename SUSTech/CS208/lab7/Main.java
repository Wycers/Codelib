import java.io.*;
import java.util.*;
 
public class Main {
    static class InputReader {
        private StreamTokenizer tokenizer;
 
        public InputReader(InputStream stream) {
            BufferedReader reader = new BufferedReader(new InputStreamReader(stream));
            tokenizer = new StreamTokenizer(reader);
        }
 
        private double next() throws IOException {
            if (tokenizer != null) {
                tokenizer.nextToken();
            }
            return tokenizer.nval;
        }
 
        private int nextInt() throws IOException {
            return (int) next();
        }
 
        private double nextDouble() throws IOException {
            return next();
        }
 
    }
 
    public static class Node {
        int x;
        int y;
        int z;
        int th;
 
        public Node() {
        }
 
        public Node(int x) {
            this.x = x;
 
        }
 
        public Node(int x, int y) {
            this.x = x;
            this.y = y;
        }
 
        public Node(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
 
        public String toString() {
            if (d == 1)
                return (this.x + "");
            else if (d == 2)
                return (this.x + " " + this.y);
            else
                return (this.x + " " + this.y + " " + this.z);
        }
 
    }
 
    public static class Pair {
        int index1;
        int index2;
        double dis;
 
        public Pair() {
        }
 
        public Pair(int index1, int index2, double dis) {
            if (nodes[index1].x < nodes[index2].x
                    || (nodes[index1].x == nodes[index2].x && nodes[index1].y < nodes[index2].y)
                    || (nodes[index1].x == nodes[index2].x && nodes[index1].y == nodes[index2].y
                            && nodes[index1].z < nodes[index2].z)) {
                this.index1 = index1;
                this.index2 = index2;
            } else {
                this.index1 = index2;
                this.index2 = index1;
            }
            this.dis = dis;
        }
 
        public void modify() {
            if (!(nodes[index1].x < nodes[index2].x
                    || (nodes[index1].x == nodes[index2].x && nodes[index1].y < nodes[index2].y)
                    || (nodes[index1].x == nodes[index2].x && nodes[index1].y == nodes[index2].y
                            && nodes[index1].z < nodes[index2].z))) {
                int tmp = this.index1;
                this.index1 = this.index2;
                this.index2 = tmp;
            }
        }
    }
 
    public static class MyCompare implements Comparator<Node> {
        public int compare(Node o1, Node o2) {
            if (o1.x > o2.x)
                return 1;
            else if (o1.x < o2.x)
                return -1;
            else {
                if (o1.y > o2.y)
                    return 1;
                else if (o1.y < o2.y)
                    return -1;
                else
                    return 0;
            }
        }
    }
 
    public static int N;
    public static int d;
    public static int ans1;
    public static int ans2;
    public static Node[] nodes;
    public static Node[] tmpnodes;
 
    public static void main(String[] args) throws IOException {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        N = in.nextInt();
        d = in.nextInt();
        nodes = new Node[N];
        if (d == 1) {
            for (int i = 0; i < N; i++) {
                nodes[i] = (new Node(in.nextInt()));
            }
            Arrays.sort(nodes, new MyCompare());
            int tmpdis = Integer.MAX_VALUE;
            for (int i = 0; i < N - 1; i++) {
                if (nodes[i + 1].x - nodes[i].x < tmpdis) {
                    tmpdis = nodes[i + 1].x - nodes[i].x;
                    ans1 = i;
                    ans2 = i + 1;
                }
            }
            out.println(nodes[ans1].toString());
            out.println(nodes[ans2].toString());
        } else if (d == 2) {
            for (int i = 0; i < N; i++) {
                nodes[i] = new Node(in.nextInt(), in.nextInt());
            }
            Arrays.sort(nodes, new MyCompare());
            for (int i = 0; i < N; i++) {
                nodes[i].th = i;
            }
            Pair ans = ClosestPairRec(0, N - 1);
            out.println(nodes[ans.index1].toString());
            out.println(nodes[ans.index2].toString());
        } else {
            for (int i = 0; i < N; i++) {
                nodes[i] = new Node(in.nextInt(), in.nextInt(), in.nextInt());
            }
            Arrays.sort(nodes, new MyCompare());
            for (int i = 0; i < N; i++) {
                nodes[i].th = i;
            }
            Pair ans = ClosestPairRec(0, N - 1);
            out.println(nodes[ans.index1].toString());
            out.println(nodes[ans.index2].toString());
        }
        out.close();
    }
 
    public static Pair ClosestPairRec(int left, int right) {
        if (right - left == 2) {
            double tmp1 = caldisbynode(nodes[left], nodes[left + 1]);
            double tmp2 = caldisbynode(nodes[left], nodes[right]);
            double tmp3 = caldisbynode(nodes[left + 1], nodes[right]);
            if (tmp1 < tmp2 && tmp1 < tmp3)
                return (new Pair(left, left + 1, tmp1));
            else if (tmp2 < tmp1 && tmp2 < tmp3)
                return (new Pair(left, right, tmp2));
            else
                return (new Pair(left + 1, right, tmp3));
        } else if (right - left == 1)
            return (new Pair(left, right, caldisbynode(nodes[left], nodes[right])));
        else {
            Pair minpair = new Pair();
            int mid = (left + right) / 2;
            Pair pair1 = ClosestPairRec(left, mid);
            Pair pair2 = ClosestPairRec(mid + 1, right);
            if (pair1.dis <= pair2.dis)
                minpair = pair1;
            else
                minpair = pair2;
            tmpnodes = new Node[right - left + 1];
            int tmpindex = 0;
            for (int i = left; i <= right; i++) {
                if (Math.pow(nodes[mid].x - nodes[i].x, 2) < minpair.dis) {
                    tmpnodes[tmpindex++] = nodes[i];
                }
            }
            sorty(0, tmpindex - 1);
            for (int i = 0; i < tmpindex; i++) {
                if (tmpnodes[i].x <= nodes[mid].x) {
                    for (int tmp1 = i + 1; tmp1 < tmpindex; tmp1++) {
                        if (Math.pow(tmpnodes[tmp1].y - tmpnodes[i].y, 2) < minpair.dis) {
                            if (tmpnodes[tmp1].x > nodes[mid].x) {
                                double distmp = caldisbynode(tmpnodes[i], tmpnodes[tmp1]);
                                if (distmp < minpair.dis) {
                                    minpair.index1 = tmpnodes[i].th;
                                    minpair.index2 = tmpnodes[tmp1].th;
                                    minpair.dis = distmp;
                                    minpair.modify();
                                }
                            } else
                                continue;
                        } else
                            break;
                    }
                    for (int tmp2 = i - 1; tmp2 >= 0; tmp2--) {
                        if (Math.pow(tmpnodes[tmp2].y - tmpnodes[i].y, 2) < minpair.dis) {
                            if (tmpnodes[tmp2].x > nodes[mid].x) {
                                double distmp = caldisbynode(tmpnodes[i], tmpnodes[tmp2]);
                                if (distmp < minpair.dis) {
                                    minpair.index1 = tmpnodes[i].th;
                                    minpair.index2 = tmpnodes[tmp2].th;
                                    minpair.dis = distmp;
                                    minpair.modify();
                                }
                            } else
                                continue;
                        } else
                            break;
                    }
                }
            }
            return minpair;
        }
    }
 
    public static double caldisbynode(Node left, Node right) {
        if (d == 2)
            return Math.pow(left.x - right.x, 2) + Math.pow(left.y - right.y, 2);
        else
            return Math.pow(left.x - right.x, 2) + Math.pow(left.y - right.y, 2) + Math.pow(left.z - right.z, 2);
    }
 
    public static void sorty(int leftmp, int rightmp) {
        if (leftmp >= rightmp) // ** */
            return;
        int i = leftmp;
        int j = rightmp;
        int key = tmpnodes[leftmp].y;
        while (i < j) {
            while (i < j && tmpnodes[j].y >= key) {
                j--;
            }
            while (i < j && tmpnodes[i].y <= key) {
                i++;
            }
            if (i < j) {
                swap(i, j);
            }
        }
        swap(leftmp, i);
        sorty(leftmp, i - 1);
        sorty(i + 1, rightmp);
    }
 
    public static void swap(int a, int b) {
        Node tmp = tmpnodes[a];
        tmpnodes[a] = tmpnodes[b];
        tmpnodes[b] = tmp;
    }
}