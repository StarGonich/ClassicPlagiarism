import java.util.Scanner;

public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int p = sc.nextInt();
        int c = sc.nextInt();
        int d = sc.nextInt();
        int q = sc.nextInt();
        int det = a * d - b * c;
        if ((a == c && b == d && p != q) || (a != c && b == d && p == q) || (a == c && b != c && p == q)) {
            System.out.println("Contradiction");
        } else if (det == 0) {
            System.out.println("Ambiguity");
        } else {
            double x = (double) (p * d - q * b) * 100 / det;
            double y = (double) (a * q - p * c) * 100 / det;
            if (x <= 0 || y <= 0) {
                System.out.println("Not positive");
            } else {
                System.out.println("Success");
                System.out.printf("%f %f", x, y);
            }
        }
    }
}
