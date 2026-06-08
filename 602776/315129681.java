import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Long> k = new ArrayList<>();
        List<Long> f = new ArrayList<>();
        k.add(0L);
        k.add(1L);
        k.add(2L);
        k.add(5L);
        f.add(1L);
        f.add(2L);
        int m = 1000000007;
        for (int i = 5; i <= n; i++){
            f.add((f.get(i-4) + (f.get(i-5)))%m);
            k.add((k.get(i-2) + k.get(i-3) + f.get(i-3))%m);
        }
        System.out.println(k.get(n-1));
    }
}
