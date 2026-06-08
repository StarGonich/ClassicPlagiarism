import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int cnt = 0;
        for (int i = 4; i < n + 1; i += 4) {
            if (cntDel(i) == 1) cnt++;
        }
        for (int i = 5; i < n + 1; i += 5) {
            if (cntDel(i) == 1) cnt++;
        }
        for (int i = 6; i < n + 1; i += 6) {
            if (cntDel(i) == 1) cnt++;
        }
        System.out.print(cnt);
        scanner.close();
    }

    public static int cntDel(int num) {
        int cnt = 0;
        if (num % 4 == 0) {
            cnt++;
        }
        if (num % 5 == 0) {
            cnt++;
        }
        if (num % 6 == 0) {
            cnt++;
        }
        return cnt;
    }
}