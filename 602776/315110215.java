import java.io.*;

public class Main {

    static StreamTokenizer reader = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));


    static int N, K;

    public static void main(String[] args) throws IOException {

        reader.nextToken();

        N = (int) reader.nval;

        int countSS = 1;

        int[] arr = new int[N];

        reader.nextToken();

        int eqPos = -1, ssLB = -1;

        arr[0] = (int) reader.nval;

        for (int i = 1; i < N; ++i) {
            reader.nextToken();
            arr[i] = (int) reader.nval;

            if (arr[i] < arr[i - 1]) {
                countSS++;
                ssLB = i;
            }

            if (arr[i] == arr[i - 1]) {
                eqPos = i;
            }
        }

        if (countSS > 2 || countSS == 1 && eqPos == -1) {
            out.println(-1);
            out.close();
            return;
        }
        if (countSS == 1) {
            out.println(eqPos + " " + 1);
            out.println((eqPos + 1) + " " + 1);
            out.close();
        }

        int fsLB = 0;

        while (arr[ssLB] >= arr[fsLB]) {
            fsLB++;
        }

        int ssUB = N - 1;

        while (arr[ssUB] >= arr[ssLB - 1]) {
            ssUB--;
        }

        if (arr[fsLB] >= arr[ssUB]) {
            out.println((fsLB + 1) + " " + (ssLB - fsLB));
            out.println((ssLB + 1) + " " + (ssUB - ssLB + 1));
        } else {
            out.println(-1);
        }

        out.close();


    }
}