import java.math.BigDecimal;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        final var scanner = new Scanner(System.in);
        final var a11 = scanner.nextInt();
        final var a12 = scanner.nextInt();
        final var b1 = scanner.nextInt();
        final var a21 = scanner.nextInt();
        final var a22 = scanner.nextInt();
        final var b2 = scanner.nextInt();
        final var det = a11 * a22 - a12 * a21;
        if (det == 0) {
            final var c1 = a11 / (double) a21;
            final var c2 = a12 / (double) a22;
            final var c3 = b1 / (double) b2;
            if (c1 == c2 && c1 != c3) {
                System.out.println("Contradiction");
            }
            if (c1 == c2 && c2 == c3) {
                System.out.println("Ambiguity");
            }
            return;
        }
        final var x = new BigDecimal((double) a22 * b1 - a12 * b2).divide(new BigDecimal(det));
        final var y = new BigDecimal((double) a11 * b2 - a21 * b1).divide(new BigDecimal(det));
        if (x.compareTo(BigDecimal.ZERO) < 0 || y.compareTo(BigDecimal.ZERO) < 0) {
            System.out.println("Not positive");
            return;
        }
        System.out.println("Success\n" + x.multiply(BigDecimal.valueOf(100)) + " " + y.multiply(BigDecimal.valueOf(100)));
    }
}