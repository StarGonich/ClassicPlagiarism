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
        var prevStartIndex = k;
        var prevEndIndex = k;
        do {
            final var startIndexResult = Arrays.binarySearch(X, 0, prevStartIndex, start);
            final var endIndexResult = Arrays.binarySearch(X, prevEndIndex, X.length, end);
            final var startIndex = startIndexResult >= 0 ? startIndexResult : -startIndexResult - 1;
            final var endIndex = endIndexResult >= 0 ? Math.min(endIndexResult, X.length - 1) : Math.min(-endIndexResult - 2, X.length - 1);
            var min = start;
            var max = end;
            for (int i = startIndex; i <= prevStartIndex; i++) {
                if (X[i] + D[i] > max) {
                    max = X[i] + D[i];
                }
                if (X[i] - D[i] < min) {
                    min = X[i] - D[i];
                }
            }
            for (int i = prevEndIndex; i <= endIndex; i++) {
                if (X[i] + D[i] > max) {
                    max = X[i] + D[i];
                }
                if (X[i] - D[i] < min) {
                    min = X[i] - D[i];
                }
            }
            System.out.println(
                    "startIndexResult: " + startIndexResult +
                            ", endIndexResult: " + endIndexResult +
                            ", startIndex: " + startIndex +
                            ", endIndex: " + endIndex +
                            ", min: " + min +
                            ", max: " + max +
                            ", prevStart: " + prevStart +
                            ", prevEnd: " + prevEnd +
                            ", prevStartIndex: " + prevStartIndex +
                            ", prevEndIndex: " + prevEndIndex
            );
            prevStart = start;
            prevEnd = end;
            prevStartIndex = startIndex;
            prevEndIndex = endIndex;
            start = min;
            end = max;
        } while (prevStart != start || prevEnd != end);
        final var startFinal = start;
        final var endFinal = end;
        System.out.println(Arrays.stream(X).filter(x -> x >= startFinal && x <= endFinal).count());
    }
}
