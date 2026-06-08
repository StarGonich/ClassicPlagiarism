import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int a = scanner.nextInt();
        int cnt = 0;
        for (int i = 4; i <= a; i++) {
            if ((i % 4 == 0 && i % 5 != 0 && i % 6 != 0) || i % 4 != 0 && i % 5 == 0 && i % 6 != 0 ||
                    i % 4 != 0 && i % 5 != 0 && i % 6 == 0) {
                cnt++;
            }
        }
        System.out.print(cnt);
        scanner.close();
    }

}