import java.io.*;
import java.util.Arrays;

public class Main {

    static StreamTokenizer reader = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static int N, K;

    final static long MOD = 1000000007;


    static long findLowAns(int i, long[] dp) {
        long ans = 0;
        i -= 2;
        while (i >= 0) {
            if (dp[i] == -1) {
                dp[i] = findLowAns(i, dp);
            }
            ans += 1 + dp[i];
            --i;
        }
        return ans;

    }

    static long findUpAns(int i, long[] dp) {
        long ans = 0;
        i += 2;
        while (i < N) {
            if (dp[i] == -1) {
                dp[i] = findUpAns(i, dp);
            }
            ans += 1 + dp[i];
            ++i;
        }
        return ans;

    }

    public static void main(String[] args) throws IOException {

        reader.nextToken();

        N = (int) reader.nval;

        long[] dp = new long[N];

        Arrays.fill(dp, -1);

        long ans = 0;

        for (int i = 1; i < N; ++i) {
            ans += 1 + (findLowAns(i - 1, Arrays.copyOf(dp, N)) + findUpAns(i, Arrays.copyOf(dp, N))) % MOD;
        }

        out.println(ans);
        out.close();

    }
}