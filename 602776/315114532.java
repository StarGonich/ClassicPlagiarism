import java.util.Scanner;

public class F {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = sc.nextInt();
        }
        int LeftFirst = 0;
        while (LeftFirst < n) {
            if (array[LeftFirst] == LeftFirst + 1) {
                LeftFirst++;
            } else break;
        }
        int RightSecond = n - 1;
        while (RightSecond > 0) {
            if (array[RightSecond] == RightSecond + 1) {
                RightSecond--;
            } else break;
        }
        if (RightSecond < LeftFirst) {
            System.out.println(-1);
            return;
        }
        int RightFirst = LeftFirst + 1;
        int LeftSecond = RightSecond;
        while (array[RightFirst] == array[RightFirst - 1] + 1) {
            RightFirst++;
        }
        RightFirst--;
        while (LeftSecond > 0) {
            if (array[LeftSecond - 1] == array[LeftSecond] - 1) {
                LeftSecond--;
            }else{
                break;
            }
        }
        if (LeftSecond < RightFirst) {
            System.out.println(-1);
        } else {
            int FirstLen = RightFirst - LeftFirst + 1;
            int SecondLen = RightSecond - LeftSecond + 1;
            int L = RightFirst + 1;
            int delta = LeftFirst - LeftSecond;
            boolean flag = true;
            while (L < LeftSecond) {
                if (array[L] != L + 1 - delta) {
                    flag = false;
                    break;
                }
                L++;
            }
            if (flag) {
                System.out.printf("%d %d%n", LeftFirst + 1, FirstLen);
                System.out.printf("%d %d%n", LeftSecond + 1, SecondLen);
            } else {
                System.out.println(-1);
            }
        }
    }
}
