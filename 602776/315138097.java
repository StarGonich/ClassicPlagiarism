import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        final var scanner = new Scanner(System.in);
        final var n = scanner.nextInt();
        final var N = IntStream.range(0, n)
                .map(x -> scanner.nextInt())
                .toArray();
        var p1 = -1;
        var p2 = -1;
        var l1 = -1;
        var l2 = -1;
        if (N[0] != 1) {
            p1 = 0;
        } else {
            for (var i = 0; i < n - 1; i++) {
                if (N[i] != N[i + 1] - 1) {
                    p1 = i + 1;
                    break;
                }
            }
        }
        if (N[N.length - 1] != n) {
            p2 = N.length - 1;
        } else {
            for (var i = n - 1; i >= 1; i--) {
                if (N[i] != N[i - 1] + 1) {
                    p2 = i - 1;
                    break;
                }
            }
        }
        if (p1 >= p2) {
            System.out.println(-1);
            return;
        }
        for (var i = p1 + 1; i < p2; i++) {
            if (N[i] != N[i - 1] + 1) {
                l1 = i - p1;
                break;
            }
        }
        for (var i = p2 - 1; i >= p1 + l1 - 1; i--) {
            if (N[i] != N[i + 1] - 1) {
                l2 = p2 - i;
                break;
            }
        }
        System.out.println((p1 + 1) + " " + l1 + "\n" + (p2 - l2 + 2) + " " + l2);
    }
}
