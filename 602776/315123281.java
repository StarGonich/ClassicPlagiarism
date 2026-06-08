import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;

public class I {
    public static void main(String[] args) throws IOException {
        int money = 210;
        int ctr = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int bet;
        boolean flag = true;
        while (flag) {
            if (ctr == 3) {
                bet = money;
            } else {
                bet = Math.floorDiv(money , (int) Math.pow(2, 4 - ctr));
            }
            System.out.printf("%d B%n", bet);
            System.out.flush();
            int WinLose = Integer.parseInt(br.readLine());
            switch (WinLose) {
                case 1: {
                    money += 2 * bet;
                    ctr = 0;
                    break;
                }
                case 0: {
                    ctr++;
                    money -= bet;
                    break;
                }
                case -1:
                    flag = false;
                    break;
            }
            if (money > 1000) break;
        }
    }
}
