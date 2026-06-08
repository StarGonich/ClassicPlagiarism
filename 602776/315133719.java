import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long p = sc.nextLong();
        long c = sc.nextLong();
        long d = sc.nextLong();
        long q = sc.nextLong();
        long det = (a * d - b * c);
        if (a == c && b == d && p != q || a != c && b == d && p == q || a == c && b != d && p == q ) {
            System.out.println("Contradiction");
        } else if (det == 0) {
            System.out.println("Ambiguity");
        } else {
            double x = (p * d - q * b) * 100.0 / det;
            double y = (a * q - p * c) * 100.0 / det;
            if (x <= 0 || y <= 0) {
                System.out.println("Not positive");
            } else {
                System.out.println("Success");
                System.out.printf("%f %f", x, y);
            }
        }
    }
}
