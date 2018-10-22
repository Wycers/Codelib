import java.io.*;
import java.math.*;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 * Author: Wavator
 */
public class D_ {
    public static void main(String[] args){
        InputStream inputStream = System.in;//new FileInputStream("C:\\Users\\wavator\\Downloads\\test.in");
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        Task solver = new Task();
        solver.solve(in, out);
        out.close();
    }

    static class Task {

        static int[] kmpnext(String word, int len) {
            int[] next = new int[len];
            next[0] = 0;
            int j = 0;
            for(int i = 1; i < len; i++) {
                while(j > 0 && word.charAt(i) != word.charAt(j)) {
                    j = next[j-1];
                }
                if(word.charAt(j) == word.charAt(i)) {
                    j++;
                }
                next[i] = j;
            }
            return next;
        }

        static boolean kmpcheak(String word, int sublen, int[] next) {
            int j = 0;
            int sum = 0;
            for(int i = sublen; i < word.length(); i++) {
                boolean flag = false;
                while(j>0 && word.charAt(j) != word.charAt(i) ) {
                    j = next[j-1];
                }
                if(word.charAt(j) == word.charAt(i)) {
                    if(j == sublen-1 && sum == 0) {
                        j=0;
                        sum++;
                        if(i >word.length()-sublen-1 ) {
                            return false;
                        }
                        else {
                            i = word.length()-sublen-1;
                        }
                        
                    }


                    else if(j==sublen-1  && i == word.length()-1){
                        return true;
                    }

                    else {
                        j++;
                    }
                }
            }
            return false;
        }
        static int kmpcount(String word, int[] next) {
            int sublen = Math.min(next[word.length()-1],word.length()/3);
            while(sublen !=0 && kmpcheak(word,sublen,next)==false ) {
                sublen--;
                if(sublen == 0) {
                    return 0;
                }
            }
            return sublen;
        }
        public void solve(InputReader in, PrintWriter out) {

            while (in.hasNext()) {
                int cases = in.nextInt();
                for(int kd = 0; kd < cases; kd++) {
                    int len = in.nextInt();
                    String word = in.next();
                    int[] next = kmpnext(word,len);
                    System.out.println(kmpcount(word,next));
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
        
//         public boolean hasNext() {
//             try {
//                 return reader.ready();
//             } catch(IOException e) {
//                 throw new RuntimeException(e);
//             }
//         }
        public boolean hasNext() {
            try {
                String string = reader.readLine();
                if (string == null) {
                    return false;
                }
                tokenizer = new StringTokenizer(string);
                return tokenizer.hasMoreTokens();
            } catch(IOException e) {
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