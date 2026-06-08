import java.io.*;

public class Main2 {

    static class FastReader {
        StreamTokenizer in;
        PrintWriter out;

        public FastReader() {
            in = new StreamTokenizer((new BufferedReader(new InputStreamReader(System.in))));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        }

        public int nextInt() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (int) in.nval;
        }
    }

    public static void main(String[] args) {

        FastReader fastReader = new FastReader();
        int N = fastReader.nextInt();

        if (N<4) {
            System.out.println(0);
        }
        else {
            long count = 0;

            for (long i = 4; i<=N; i=i+4) {
                if (i % 5 != 0 && i % 6 != 0) {
                    count++;
                }
            }
            for (long i = 5; i<=N; i=i+5) {
                if (i % 4 != 0 && i % 6 != 0) {
                    count++;
                }
            }
            for (long i = 6; i<=N; i=i+6) {
                if (i % 4 != 0 && i % 5 != 0) {
                    count++;
                }
            }

            System.out.println(count);
        }

    }

}