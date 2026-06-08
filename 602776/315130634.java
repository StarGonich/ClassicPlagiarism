import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class I {
    public static void main(String[] args) throws IOException {
        int money = 210;
        int ctr = 0;
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int bet;
        int lastBet =  Math.floorDiv(money , (int) Math.pow(2, 5));
        boolean flag = true;
        while (flag) {
            if (ctr == 3) {
                bet = money;
            } else {
                bet = 2 * lastBet;
            }
            System.out.printf("%d B%n", bet);
            System.out.flush();
            int WinLose = Integer.parseInt(br.readLine());
            switch (WinLose) {
                case 1: {
                    money += bet;
                    lastBet = Math.floorDiv(money , (int) Math.pow(2, 5));
                    ctr = 0;
                    break;
                }
                case 0: {
                    ctr++;
                    money -= bet;
                    lastBet = bet;
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
