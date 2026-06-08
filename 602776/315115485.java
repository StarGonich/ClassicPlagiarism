import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = 0;
        if (n % 2 == 0) {
            s = n - 1 + n / 2;
        } else {
            s = n - 1 + (n + 1) / 2;
        }
        System.out.println(s);
    }
}