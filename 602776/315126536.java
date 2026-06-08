import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int[] cord = new int[n];
        for (int i = 0; i < n; i++) {
            cord[i] = scanner.nextInt();
        }

        int[] far = new int[n];
        for (int i = 0; i < n; i++) {
            far[i] = scanner.nextInt();
        }

        int k = scanner.nextInt() -1;

        int left = k - 1;
        int prevLeftExplore = cord[k] - far[k];
        int right = k + 1;
        int prevRightExplore = cord[k] + far[k];
        int cnt = 1;

        while (left > -1 || right < n) {
            if (left > -1 && prevLeftExplore <= cord[left]) {
                cnt++;
                prevLeftExplore = Math.min(prevLeftExplore, cord[left] - far[left]);
                left--;
            } else {
                left = -1;
            }

            if (right < n && prevRightExplore >= cord[right]) {
                cnt++;
                prevRightExplore = Math.max(prevRightExplore, cord[right] + far[right]);
                right++;
            } else {
                right = n;
            }
        }
        System.out.print(cnt);
    }


}