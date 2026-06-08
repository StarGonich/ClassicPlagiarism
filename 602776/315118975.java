import java.util.Arrays;
import java.util.Scanner;
import java.util.stream.IntStream;

public class Main {

    public static void main(String[] args) {
        final var scanner = new Scanner(System.in);
        final var n = scanner.nextInt();
        final var X = new int[n];
        final var D = new int[n];
        IntStream.range(0, n).forEach(i -> X[i] = scanner.nextInt());
        IntStream.range(0, n).forEach(i -> D[i] = scanner.nextInt());
        final var k = scanner.nextInt() - 1;
        var start = X[k] - D[k];
        var end = X[k] + D[k];
        var prevStart = start;
        var prevEnd = end;
        do {
            final var startIndexResult = Arrays.binarySearch(X, start);
            final var endIndexResult = Arrays.binarySearch(X, end);
            final var startIndex = startIndexResult >= 0 ? startIndexResult : -startIndexResult - 1;
            final var endIndex = endIndexResult >= 0 ? Math.min(endIndexResult, X.length - 1) : Math.min(-endIndexResult - 2, X.length - 1);
            var min = start;
            var max = end;
            for (int i = startIndex; i <= endIndex; i++) {
                if (X[i] + D[i] > max) {
                    max = X[i] + D[i];
                }
                if (X[i] - D[i] < min) {
                    min = X[i] - D[i];
                }
            }
            prevStart = start;
            prevEnd = end;
            start = min;
            end = max;
        } while (prevStart != start && prevEnd != end);
        final var startFinal = start;
        final var endFinal = end;
        System.out.println(Arrays.stream(X).filter(x -> x >= startFinal && x <= endFinal).count());
    }
}