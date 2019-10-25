package net.mooctest;

import static org.junit.Assert.*;

import org.junit.Test;

public class SuffixArrayTest {

    @Test
    public void test() {
        SuffixArray suffixArray = new SuffixArray();
        String str = "ababaabc";
        int N = str.length();

        int[] sa = new int[N];
        int[] lcp = new int[N];

        suffixArray.createSuffixArray(str, sa, lcp);
        suffixArray.printV(sa, ",");

        int[] a = {1, 2, 3};
        int[] b = {1, 2, 2};
        suffixArray.sleq(a, 0, b, 0);
        suffixArray.sleq(b, 0, a, 0);
    }

    @Test
    public void testCreateSuffixArraySlow() {
        SuffixArray suffixArray = new SuffixArray();
        String str = "ababaabc";
        int N = str.length();

        int[] sa = new int[N];
        int[] lcp = new int[N];

        suffixArray.createSuffixArraySlow(str, sa, lcp);

        int[] _sa = new int[N + 1];
        try {
            suffixArray.createSuffixArraySlow(str, _sa, lcp);
            fail("Expecting IllegalArgumentException");
        } catch (IllegalArgumentException e) {

        }
        int[] _lcp = new int[N - 1];
        try {
            suffixArray.createSuffixArraySlow(str, sa, _lcp);
            fail("Expecting IllegalArgumentException");
        } catch (IllegalArgumentException e) {

        }
    }

    @Test
    public void test2() {
        SuffixArray suffixArray = new SuffixArray();
        String str = "abababaaaaaaaa";
        int N = str.length();

        int[] sa = new int[N];
        int[] lcp = new int[N];

        suffixArray.createSuffixArray(str, sa, lcp);
    }

    @Test
    public void testIsSorted() {
        SuffixArray suffixArray = new SuffixArray();
        int[] s = {1, 2, 3};
        int[] sa = {0, 1, 2};
        suffixArray.isSorted(sa, s, 3);


        int[] t = {3, 2, 1};
        int[] sb = {0, 1, 2};
        suffixArray.isSorted(sb, t, 3);
    }

    @Test
    public void testPermutation() {
        SuffixArray suffixArray = new SuffixArray();
        suffixArray.isPermutation(new int[]{1, 1}, 2);
        suffixArray.isPermutation(new int[]{0, 1}, 2);
    }

    @Test
    public void testComputeLCP() {
        SuffixArray suffixArray = new SuffixArray();
        suffixArray.computeLCP("", "");
        suffixArray.computeLCP("x", "");
        suffixArray.computeLCP("x", "x");
        suffixArray.computeLCP("x", "y");
    }
}
