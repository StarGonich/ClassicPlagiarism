
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int errorIndex = -1;
        int cntErrors = 0;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] >= arr[i + 1]) {
                cntErrors++;
                errorIndex = i + 1;
            }
        }
        if (cntErrors == 0 || cntErrors > 1) {
            System.out.print(-1);
            return;
        }

        int i = 0;
        for (; i < n; i++) {
            if (arr[i] > arr[errorIndex]) {
                break;
            }
        }

        int startInsertion = i;
        int lenInsertion = errorIndex - i;

        int start = errorIndex;
        int len = 0;
        while (start < n && arr[start] <= arr[startInsertion]) {
            len++;
            start++;
        }

        System.out.println((startInsertion + 1) + " " + lenInsertion);
        System.out.print((errorIndex + 1) + " " + len);
    }
}