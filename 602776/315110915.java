import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import java.util.Stack;
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
        final var mineIndexesStack = new Stack<Integer>();
        final var alreadyDetonated = IntStream.range(0, n).mapToObj(i -> false).collect(Collectors.toList());
        mineIndexesStack.push(k);
        while (!mineIndexesStack.isEmpty()) {
            final var currentIndex = mineIndexesStack.pop();
            final var detonatedIndexes = findInRange(X[currentIndex], D[currentIndex], X, alreadyDetonated);
            alreadyDetonated.set(currentIndex, true);
            mineIndexesStack.addAll(detonatedIndexes);
        }
        System.out.println(alreadyDetonated.stream().filter(Boolean.TRUE::equals).count());
    }

    private static Set<Integer> findInRange(int x, int d, int[] X, List<Boolean> alreadyDetonated) {
        final var startResult = Arrays.binarySearch(X, x - d);
        final var endResult = Arrays.binarySearch(X, x + d);
        final var start = startResult >= 0 ? startResult : -startResult - 1;
        final var end = endResult >= 0 ? Math.min(endResult + 1, X.length) : Math.min(-endResult - 1, X.length);
        return IntStream.range(start, end)
                .filter(i -> Boolean.FALSE.equals(alreadyDetonated.get(i)))
                .filter(i -> X[i] != x)
                .boxed()
                .collect(Collectors.toSet());
    }
}