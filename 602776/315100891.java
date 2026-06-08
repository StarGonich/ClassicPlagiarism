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

        int[] test = new int[3];
        test[0] = 4;
        test[1] = 5;
        test[2] = 6;

        int count = 0;

//        for(int i = 1; i <= n; i++) {
//            int cc_dels = 0;
//
//            for(int x : test) {
//                if (i % x == 0) {
//                    cc_dels++;
//                }
//            }
//
//            if (cc_dels == 1) {
//                count++;
//            }
//        }

//        for(int x : test) {
            int i = 1;
            while (4 * i <= n) {
                int cc_dels = 0;

                if (4 * i % 5 != 0 && 4 * i % 6 != 0) {
                    count++;
                }

                if (5 * i <= n) {
                    if (5 * i % 4 != 0 && 5 * i % 6 != 0) {
                        count++;
                    }
                }

                if (6 * i <= n) {
                    if (6 * i % 4 != 0 && 6 * i % 5 != 0) {
                        count++;
                    }
                }

                i++;
            }
//        }

        fr.println(count);
    }
}



















