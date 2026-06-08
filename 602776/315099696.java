import java.io.*;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.TreeSet;

public class Main {

    static StreamTokenizer reader = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static class Num implements Comparable<Num>{

        long val;
        long add;

        Num(long val, long add) {
            this.val = val;
            this.add = add;
        }

        public void addVal() {
            val += add;
        }

        @Override
        public int compareTo(Num o) {
            return Long.compare(this.val, o.val);
        }

    }

    static long N;

    public static void main(String[] args) throws IOException {

        reader.nextToken();

        N = (long) reader.nval;

        PriorityQueue<Num> q = new PriorityQueue<>();

        int ans = 0;

        q.add(new Num(4, 4));
        q.add(new Num(5, 5));
        q.add(new Num(6, 6));

        while(!q.isEmpty()) {
            Num x = q.poll();
            Num y = q.poll();
            if (y == null) {
                ans++;
                x.addVal();
                if (x.val <= N) {
                    q.add(x);
                }
                continue;
            }
            if (x.val != y.val) {
                ans++;

                q.add(y);
                x.addVal();
                if (x.val <= N) {
                    q.add(x);
                }
            } else {
                Num z = q.poll();
                if (z != null && y.val == z.val) {
                    z.addVal();
                    if (z.val <= N) {
                        q.add(z);
                    }
                } else if (z != null) {
                    q.add(z);
                }
                x.addVal();
                if (x.val <= N) {
                    q.add(x);
                }

                y.addVal();
                if (y.val <= N) {
                    q.add(y);
                }
            }

        }

        out.println(ans);

        out.close();

    }
}