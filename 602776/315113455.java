import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double a = scanner.nextDouble();
        double b = scanner.nextDouble();
        double p = scanner.nextDouble();
        double c = scanner.nextDouble();
        double d = scanner.nextDouble();
        double q = scanner.nextDouble();

        double oprMain = a * d - (c * b);

        if (a == c && b == d && p != q || a != c && b == d && p == q || a == c && b != d && p == q) {
            System.out.print("Contradiction");
            return;
        }

        if (oprMain == 0) {
            System.out.print("Ambiguity");
            return;
        }
        double opr1 = p * d - (q * b);
        double opr2 = a * q - (c * p);
        double x = opr1 / oprMain;
        double y = opr2 / oprMain;

        if (x < 0 || y < 0) {
            System.out.print("Not positive");
            return;
        }

        System.out.println("Success");
        System.out.print(x * 100);
        System.out.print(" " + y * 100);
        scanner.close();
    }
}