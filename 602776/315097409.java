import java.io.*;
import java.util.Set;
import java.util.TreeSet;

public class Main {

    static StreamTokenizer reader = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static long N;

    public static void main(String[] args) throws IOException {

        reader.nextToken();

        N = (long) reader.nval;

        long[] nums = new long[3];

        nums[0] = 4;
        nums[1] = 5;
        nums[2] = 6;

        int ans = 0;

        while (nums[0] <= N || nums[1] <= N || nums[2] <= N) {
            if (nums[0] <= N && nums[0] < nums[1] && nums[0] < nums[2]) {
                ans++;
                nums[0] += 4;
                continue;
            }
            if (nums[1] <= N && nums[1] < nums[0] && nums[1] < nums[2]) {
                ans++;
                nums[1] += 5;
                continue;
            }
            if (nums[2] <= N && nums[2] < nums[0] && nums[2] < nums[1]) {
                ans++;
                nums[2] += 6;
                continue;
            }
            if (nums[0] == nums[1]) {
                nums[0] += 4;
                nums[1] += 5;
            }
            if (nums[1] == nums[2]) {
                nums[1] += 5;
                nums[2] += 6;
            }
            if (nums[0] == nums[2]) {
                nums[0] += 4;
                nums[2] += 6;
            }
        }

        out.println(ans);

        out.close();

    }
}