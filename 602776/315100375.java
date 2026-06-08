import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n + 1];
        int cnt = 0;

        for (int i = 4; i < n + 1; i += 4) {
            arr[i]++;
        }
        for (int i = 5; i < n + 1; i += 5) {
            arr[i]++;

        }
        for (int i = 6; i < n + 1; i += 6) {
            arr[i]++;
        }
        for (int i = 0; i < n + 1; i++) {
            if (arr[i] == 1) cnt++;
        }
        System.out.print(cnt);
        scanner.close();
    }
}