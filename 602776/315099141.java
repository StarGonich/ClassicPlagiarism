import java.io.*;
import java.util.HashSet;

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
        FastReader fastReader = new FastReader();
        long N = fastReader.nextLong();

        if (N<4) {
            System.out.println(0);
        }
        else {
            HashSet<Long> setCount = new HashSet<>();
            for (long i = 4; i<=N; i=i+4) {
                setCount.add(i);
            }
            for (long i = 5; i<=N; i=i+5) {
                setCount.add(i);
            }
            for (long i = 6; i<=N; i=i+6) {
                setCount.add(i);
            }
            System.out.println(setCount.size());;
        }

    }

}