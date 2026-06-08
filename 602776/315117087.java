import java.io.*;
import java.util.Collection;
import java.util.Collections;
import java.util.HashSet;
import java.util.TreeSet;

public class Main {

    static class FastReader {
        StreamTokenizer in;
        PrintWriter out;

        public FastReader() {
            in = new StreamTokenizer((new BufferedReader(new InputStreamReader(System.in))));
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

        public double nextDouble() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (double) in.nval;
        }

        public long nextLong() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (long) in.nval;
        }
    }

    public static void main(String[] args) {

        // 4 5 6 8 10 12 15 18

        FastReader fastReader = new FastReader();
        long N = fastReader.nextLong();

        if (N<4) {
            System.out.println(0);
        }
        else {
            TreeSet<Long> set = new TreeSet<>();
            TreeSet<Long> treeCount = new TreeSet<>();
            for (long i = 4; i<=N; i=i+4) {
                treeCount.add(i);
            }
            for (long i = 5; i<=N; i=i+5) {
                if (treeCount.contains(i)) {
                    treeCount.remove(i);
                    set.add(i);
                } else {
                    treeCount.add(i);

                }
            }
            for (long i = 6; i<=N; i=i+6) {
                if (treeCount.contains(i) || set.contains(i)) {
                    treeCount.remove(i);
                    set.add(i);
                }
                else {
                    treeCount.add(i);

                }
            }

            System.out.println(treeCount.size());;
        }

    }

}