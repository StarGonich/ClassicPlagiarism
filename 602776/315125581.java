import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        BigDecimal count = BigDecimal.ZERO;
        for (int i = 0; i < n - 1; i++) {
            int l = Math.max(0, i - 1);
            int r = Math.max(0, n - i - 3);
            BigDecimal ll = BigDecimal.ZERO;
            BigDecimal rr = BigDecimal.ZERO;
            if (l == 0) {
                ll = BigDecimal.ONE;
            } else if (l == 1) {
                ll = BigDecimal.TWO;
            } else {
                ll = (new BigDecimal(2).pow(l).subtract(new BigDecimal(2).pow(l - 1).subtract(BigDecimal.ONE)));
            }
            if (r == 0) {
                rr = BigDecimal.ONE;
            } else if (r == 1) {
                rr = BigDecimal.TWO;
            }
            else {
                rr = (new BigDecimal(2).pow(r).subtract(new BigDecimal(2).pow(r - 1).subtract(BigDecimal.ONE)));
            }
            count = count.add(rr.multiply(ll));
            count = count.remainder(new BigDecimal(1000000007));

        }
        System.out.println(count.toString());
    }

}