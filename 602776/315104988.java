import java.io.*;

public class Main {

    static StreamTokenizer reader = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));


    static int N, K;

    public static void main(String[] args) throws IOException {

        reader.nextToken();

        N = (int) reader.nval;

        long[] poses = new long[N];

        for (int i = 0; i < N; ++i) {
            reader.nextToken();
            poses[i] = (long) reader.nval;
        }

        long[] diams = new long[N];

        for (int i = 0; i < N; ++i) {
            reader.nextToken();
            diams[i] = (long) reader.nval;
        }

        reader.nextToken();

        K = (int) reader.nval - 1;

        int posLB = K, posUB = K + 1;
        long diamLB = poses[K] - diams[K], diamUB = poses[K] + diams[K];

        while (posLB > 0 || posUB < N) {
            if (posLB > 0 && poses[posLB - 1] >= diamLB) {
                posLB--;
                diamLB = Math.min(diamLB, poses[posLB] - diams[posLB]);
                diamUB = Math.max(diamUB, poses[posLB] + diams[posLB]);
                continue;
            }
            if (posUB < N && poses[posUB] <= diamUB) {
                diamLB = Math.min(diamLB, poses[posUB] - diams[posUB]);
                diamUB = Math.max(diamUB, poses[posUB] + diams[posUB]);
                posUB++;
                continue;
            }
            break;
        }

        out.println(posUB - posLB);
        out.close();




    }
}