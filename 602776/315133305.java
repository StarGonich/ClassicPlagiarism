import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        // находим фигню
        int last = 0;
        int i = 0;
        while (i < n && arr[i] >= arr[last]) {
            last = i;
            i++;
        }

        if (i == n) {
            System.out.print(-1);
            return;
        }

        // понимаем, куда вставить
        int insertIndex = i - 1;
        while (insertIndex > -1 && arr[insertIndex] > arr[i]) {
            insertIndex--;
        }
        insertIndex++;
        int secondLen = i - insertIndex;
        int valueMax = arr[insertIndex];

        int start = i;
        while (i < n && arr[i] <= valueMax) {
            i++;
        }
        int firstLen = i - start;

        if (i != n) {
            if (arr[last] > arr[i]) {
                System.out.print(-1);
                return;
            } else {
                last = i;
                int next = i + 1;
                while (next < n && arr[last] <= arr[next]) {
                    last = next;
                    next++;
                }
            }
        }

        if (last != n - 1) {
            System.out.print(-1);
            return;
        }
        System.out.println((insertIndex + 1) + " " + secondLen);
        System.out.print((start + 1) + " " + firstLen);
    }


}