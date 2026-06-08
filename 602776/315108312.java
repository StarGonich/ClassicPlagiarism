import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int cnt = 0;
        cnt += n / 4 + n / 5 + n / 6 - (n / 12 * 2  + n / 20 * 2) + n/60;
        System.out.print(cnt);
        scanner.close();
    }
}