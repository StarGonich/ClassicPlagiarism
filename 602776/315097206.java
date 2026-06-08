import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        int count = 0;
        for (int i = 1; i <= n; i++) {
            boolean a = i % 4 == 0, b = i % 5 == 0, c = i % 6 == 0;
            if ((a && !b && !c) || (!a && b && !c) || (!a && !b && c)) {
                count++;
            }
        }
        System.out.println(count);
    }

}