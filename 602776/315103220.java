import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final var n = new Scanner(System.in).nextInt();
        System.out.println(n / 4 + n / 5 + n / 6 - 2 * (n / 20) - 2 * (n / 12) - 2 * (n / 30) + 3 * (n / 60));
    }
}