import java.io.*;
import java.math.*;
import java.util.StringTokenizer;
import java.util.*;

/**
 * Built using CHelper plug-in Actual solution is at the top Author: Wavator
 */
public class F_ {
    public static void main(String[] args) {
        InputStream inputStream = System.in;// new FileInputStream("C:\\Users\\wavator\\Downloads\\test.in");
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static int[] kmpnext(String substr) {
        int[] next = new int[substr.length()];
        next[0] = 0;
        int j = 0;
        for (int i = 1; i < substr.length(); i++) {
            while (j > 0 && substr.charAt(j) != substr.charAt(i)) {
                j = next[j - 1];
            }
            if (substr.charAt(j) == substr.charAt(i)) {
                j++;
            }
            next[i] = j;
        }
        return next;
    }

    static boolean cheakkmp(String substr, String[] words, int[] tempnext) {
        for (int kd = 1; kd < words.length; kd++) {
            boolean flag = false;
            String word = words[kd];
            int j = 0;
            for (int i = 0; i < word.length(); i++) {
                while (j > 0 && word.charAt(i) != substr.charAt(j)) {
                    j = tempnext[j - 1];
                }
                if (word.charAt(i) == substr.charAt(j)) {
                    if (j == substr.length() - 1) {
                        flag = true;
                        break;
                    } else {
                        j++;
                    }
                }
            }
            if (flag == false) {
                return false;
            }
        }
        return true;
    }

    static class Task {

        public void solve(InputReader in, PrintWriter out) {
            while (in.hasNext()) {
                int cases = in.nextInt();
                for (int kd = 0; kd < cases; kd++) {
                    int N = in.nextInt();
                    String[] words = new String[N];
                    int minlen = 201;
                    for (int i = 0; i < N; i++) {
                        words[i] = in.next();
                        minlen = Math.min(minlen, words[i].length());
                    }
                    String[] keylist = new String[200];
                    int keytag = -1;
                    boolean flag = false;
                    for (int sublen = minlen; sublen >= 1; sublen--) {
                        for (int j = 0; j <= words[0].length() - sublen; j++) {
                            String substr = words[0].substring(j, j + sublen);
                            int[] tempnext = kmpnext(substr);
                            if (cheakkmp(substr, words, tempnext) == true) {
                                keylist[++keytag] = substr;
                                flag = true;
                            }
                        }
                        if (flag == true) {
                            break;
                        }
                    }
                    if (flag == false) {
                        System.out.println("Hong");
                        continue;
                    }
                    String res = keylist[0];
                    for (int i = 1; i <= keytag; i++) {
                        if (res.compareTo(keylist[i]) > 0) {
                            res = keylist[i];
                        }
                    }
                    System.out.println(res);
                }
            }
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }

        public char[] nextCharArray() {
            return next().toCharArray();
        }

        public boolean hasNext() {
            try {
                String string = reader.readLine();
                if (string == null) {
                    return false;
                }
                tokenizer = new StringTokenizer(string);
                return tokenizer.hasMoreTokens();
            } catch (IOException e) {
                return false;
            }
        }

        public BigInteger nextBigInteger() {
            return new BigInteger(next());
        }

        public BigDecimal nextBigDecinal() {
            return new BigDecimal(next());
        }
    }
}