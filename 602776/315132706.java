import java.io.*;

public class Main {

    static StreamTokenizer reader = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));


    static long N;

    public static void main(String[] args) throws IOException {

        double a, b, p, c, d, q;

        reader.nextToken();
        a = reader.nval;

        reader.nextToken();
        b = reader.nval;

        reader.nextToken();
        p = reader.nval;

        reader.nextToken();
        c = reader.nval;

        reader.nextToken();
        d = reader.nval;

        reader.nextToken();
        q = reader.nval;

        if (a == c && b == d) {
            if (p != q) {
                out.println("Contradiction");
            } else {
                out.println("Ambiguity");
            }
            out.close();
            return;
        }

        if ((a == c && a == 0) || (b == d && b == 0)) {
            out.println("Ambiguity");
            out.close();
            return;
        }

        double k, x, y;

        if (c == 0) {
            y = q / d;
            x = (p - b * y) / a;
            if (x > 0 && y > 0) {
                out.println("Success\n" + 100 * x +" " + 100 * y);
            } else {
                out.println("Not positive");
            }
            out.close();
            return;
        }
        if (a == 0) {
            y = p / b;
            x = (q - d * y) / c;
            if (x > 0 && y > 0) {
                out.println("Success\n" + 100 * x +" " + 100 * y);
            } else {
                out.println("Not positive");
            }
            out.close();
            return;
        }
        if (d == 0) {
            x = q / c;
            y = (p - a * x) / b;
            if (x > 0 && y > 0) {
                out.println("Success\n" + 100 * x +" " + 100 * y);
            } else {
                out.println("Not positive");
            }
            out.close();
            return;
        }
        if (b == 0) {
            x = p / a;
            y = (q - c * x) / d;
            if (x > 0 && y > 0) {
                out.println("Success\n" + 100 * x +" " + 100 * y);
            } else {
                out.println("Not positive");
            }
            out.close();
            return;
        }

        k = a / c;
        y = (p - q * k) / (b - d * k);
        x = (p - b * y) / a;
        if (x > 0 && y > 0) {
            out.println("Success\n" + 100 * x +" " + 100 * y);
        } else {
            out.println("Not positive");
        }
        out.close();

    }
}