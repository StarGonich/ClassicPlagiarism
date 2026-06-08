import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int cnt = 0;
        cnt += (n / 5 - n / 20);
        cnt += (n / 4 - n / 12 - n / 20);
        cnt += (n / 6 - n / 12);
        System.out.print(cnt);
        scanner.close();
    }
}