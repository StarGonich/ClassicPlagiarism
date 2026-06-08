import java.io.*;
import java.util.HashSet;
import java.util.Set;

public class z1 {
    static class FastReader {
        StreamTokenizer in;
        PrintWriter out;

        public FastReader() {
            in = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        }

        public void println(Object o) {
            out.println(o);
            out.flush();
        }

        public void print(Object o) {
            out.print(o);
            out.flush();
        }

        public int nextInt() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return (int) in.nval;
        }

        public long nextLong() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return (long) in.nval;
        }

        public double nextDouble() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }

            return (double) in.nval;
        }
    }

    public static Set<Integer> getDivs(int n) {
        Set<Integer> s = new HashSet<>();
        for(int i = 1; i <= Math.ceil(Math.sqrt(n)); i++) {
            if (n % i == 0) {
                s.add(n / i);
                s.add(i);
            }
        }

        return s;
    }

    public static void main(String[] args) {
        FastReader fr = new FastReader();

        int n = fr.nextInt();

        Set<Integer> test = new HashSet<>();
        test.add(4);
        test.add(5);
        test.add(6);

        int count = 0;

        for(int i = 1; i <= n; i++) {
//            Set<Integer> temp = getDivs(i);

            int cc_dels = 0;

            for(int x : test) {
//                System.out.println(x);
                if (i % x == 0) {
                    cc_dels++;
                }
            }

            if (cc_dels == 1) {
                count++;
            }
        }

        fr.println(count);
    }
}



















