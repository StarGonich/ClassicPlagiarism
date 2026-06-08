import java.io.*;
import java.math.BigDecimal;
import java.math.RoundingMode;

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
            return in.nval;
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
        int A = fastReader.nextInt();
        int B = fastReader.nextInt();
        int P = fastReader.nextInt();
        int C = fastReader.nextInt();
        int D = fastReader.nextInt();
        int Q = fastReader.nextInt();

        if((P * D - B * Q)==0) {
            System.out.println("Ambiguity");
        } else if ((D*A-B*C)==0) {
            System.out.println("Contradiction");
        } else {
            double x = 0;
            double y = 0;
            if (D==0) {
                x = (double) Q /C;
                y = (P-A*x)/B;
            } else {
                x = (double) (P * D - B * Q) / (D*A-B*C);
                y = (Q-C*x) / D;
            }
            

            if(x<=0 || y<=0) {
                System.out.println("Not positive");
            } else {
                x*=100;
                y*=100;

                BigDecimal xVal = new BigDecimal(x);
                BigDecimal xRo = xVal.setScale(3, RoundingMode.HALF_EVEN);
                BigDecimal yVal = new BigDecimal(y);
                BigDecimal yRo = yVal.setScale(3, RoundingMode.HALF_EVEN);

                System.out.println("Success");
                System.out.print(xRo);
                System.out.print(" ");
                System.out.print(yRo);
            }

        }

    }

}