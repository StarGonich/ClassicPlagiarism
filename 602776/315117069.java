import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.stream.Collectors;
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
        final var mineIndexesSet = new HashSet<Integer>();
        final var alreadyDetonated = IntStream.range(0, n).mapToObj(i -> false).collect(Collectors.toList());
        mineIndexesSet.add(k);
        while (!mineIndexesSet.isEmpty()) {
            final var currentIndex = mineIndexesSet.stream().findFirst().orElseThrow();

            final var detonatedIndexes = findInRange(X[currentIndex], D[currentIndex], X, D, alreadyDetonated);
            mineIndexesSet.addAll(detonatedIndexes);
            mineIndexesSet.remove(currentIndex);
        }
        System.out.println(alreadyDetonated.stream().filter(Boolean.TRUE::equals).count());
    }

    private static Set<Integer> findInRange(int x, int d, int[] X, int[] D, List<Boolean> alreadyDetonated) {
        final var startResult = Arrays.binarySearch(X, x - d);
        final var endResult = Arrays.binarySearch(X, x + d);
        final var start = startResult >= 0 ? startResult : -startResult - 1;
        final var end = endResult >= 0 ? Math.min(endResult, X.length - 1) : Math.min(-endResult - 2, X.length - 1);
        var min = start;
        var max = end;
        for (var i = start; i <= end; i++) {
            if (!alreadyDetonated.get(i)) {
                if (X[i] + D[i] > max) {
                    max = i;
                }
                if (X[i] - D[i] < min) {
                    min = i;
                }
            }
        }
        final var result = new HashSet<Integer>();
        if (!alreadyDetonated.get(min)) {
            result.add(min);
        }
        if (!alreadyDetonated.get(max)) {
            result.add(max);
        }
        IntStream.range(start, end + 1).forEach(i -> alreadyDetonated.set(i, true));
        return result;
    }
}