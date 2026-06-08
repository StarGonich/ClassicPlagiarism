import java.io.*;
import java.util.Arrays;

public class Main {

    static StreamTokenizer reader = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static int N, K;

    final static long MOD = 1000000007;

    public static void main(String[] args) throws IOException {

        reader.nextToken();

        N = (int) reader.nval;

        if (N == 1) {
            out.println(0);
            out.close();
            return;
        }

        long[] dp = new long[N];

        dp[0] = 0;
        dp[1] = 0;


        long ans = 0;

        int i;

        for (i = 1; i < N - i - 1; ++i) {
            for (int j = 2; j < i - 1; ++j) {
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
            dp[i] += i - 1;
            dp[N - i - 1] = dp[i];
            ans += dp[i];

        }

        for (; i < N - 1; ++i) {
            for (int j = 2; j < i - 1; ++j) {
                dp[i] += dp[j];
                dp[i] %= MOD;
            }
            dp[i] += i - 1;
            ans += (dp[i] + dp[i] * dp[i + 1]);
            ans += (dp[i] * dp[i + 1]) + dp[i] + dp[i + 1];
            ans %= MOD;
        }

        ans += N - 1;

        out.println(ans);
        out.close();

    }
}