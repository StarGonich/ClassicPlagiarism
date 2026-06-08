public class Main2 {

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
            long count = 0;

            for (int i = 0; i <= N; i++) {
                if(i%5==0 && i%4!=0 && i%6!=0){
                    count++;
                } else if (i%4==0 && i%5!=0 && i%6!=0) {
                    count++;
                } else if (i%6==0 && i%5!=0 && i%4!=0) {
                    count++;
                }
            }

            System.out.println(count);
        }

    }

}