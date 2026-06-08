
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
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

        int k = scanner.nextInt();
        Queue<Integer> toView = new LinkedList<>();
        HashSet<Integer> viewed = new HashSet<>();
        toView.add(k);
        int cnt = 0;
        while (!toView.isEmpty()) {
            int index = toView.poll();
            if (viewed.contains(index)) {
                continue;
            }
            cnt++;
            viewed.add(index);

            int left = index - 1;
            int right = index + 1;
            while (left > -1 && cord[left] >= cord[index] - far[index]) {
                toView.add(left);
                left--;
            }

            while (right < n && cord[right] <= cord[index] + far[index]) {
                toView.add(right);
                right++;
            }
        }
        System.out.print(cnt);
    }


}