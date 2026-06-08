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

        double mainDet = a * d - b * c;
        double xDet = p * d - q * b;
        double yDet = a * q - p * c;

        if (mainDet == 0) {
            if (a != 0) {
                double coeff = c / a;
                c = 0;
                d -= b * coeff;
                q -= p * coeff;
                if (d == 0 && q != 0) {
                    System.out.print("Contradiction");
                    return;
                }
            } else if (c != 0) {
                double coeff = a / c;
                a = 0;
                b -= d * coeff;
                p -= q * coeff;
                if (b == 0 && p != 0) {
                    System.out.print("Contradiction");
                    return;
                }
            }
            System.out.println("Ambiguity");
            return;
        }

        double x = xDet / mainDet;
        double y = yDet / mainDet;

        if (x < 0 || y < 0) {
            System.out.print("Not positive");
            return;
        }

        System.out.println("Success");
        System.out.print(x * 100 + " " + y * 100);
    }
}