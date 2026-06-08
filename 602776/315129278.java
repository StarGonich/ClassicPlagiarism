import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<BigInteger> k = new ArrayList<>();
        List<BigInteger> f = new ArrayList<>();
        k.add(BigInteger.ZERO);
        k.add(BigInteger.ONE);
        k.add(BigInteger.TWO);
        k.add(BigInteger.valueOf(5));
        f.add(BigInteger.ONE);
        f.add(BigInteger.TWO);
        BigInteger m = BigInteger.valueOf(1000000007);
        for (int i = 5; i <= n; i++){
            f.add(f.get(i-4).add(f.get(i-5)).mod(m));
            k.add(k.get(i-2).add(k.get(i-3)).add(f.get(i-3)).mod(m));
        }
        System.out.println(k.get(n-1));
    }
}
