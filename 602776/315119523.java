import java.io.*;
import java.util.Arrays;

public class Main {

    static StreamTokenizer reader = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
    static int N, K;

    static long[] down, up;

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

        if (N == 1) {
            out.println(0);
            out.close();
            return;
        }

        long[] down = new long[N];
        long[] up = new long[N];

        down[0] = 0;
        down[1] = 0;

        up[N - 1] = 0;
        up[N - 2] = 0;

        for (int i = 2; i < N; ++i) {
            for (int j = 0; j < i - 1; ++j) {
                down[i] += down[j] + 1;
                down[i] %= MOD;
                up[N - i - 1] += up[N - j - 1] + 1;
                up[N - i - 1] %= MOD;
            }
        }

        long ans = 0;

        for (int i = 1; i < N; ++i) {
            ans += down[i - 1] * up[i] + 1 + down[i - 1] + up[i];
            ans %= MOD;
        }

        out.println(ans);
        out.close();

    }
}