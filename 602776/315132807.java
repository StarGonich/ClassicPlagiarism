import java.util.Scanner;

public class Main {
    private static boolean isFirstStrategyEnabled = true;
    private static int lastSecondStrategyMinBet = 0;

    public static void main(String[] args) {
        var balance = 210;
        var gamesAfterLastLose = 1;
        try {
            for (var i = 0; i < 100; i++) {
                final var bet = calculateBet(balance, gamesAfterLastLose);
                balance -= bet;
                final var result = getResponse(bet);
                if (result) {
                    gamesAfterLastLose = 1;
                    balance += 2 * bet;
                } else {
                    gamesAfterLastLose++;
                }
                if (balance > 1000) {
                    return;
                }
            }
        } catch (IllegalArgumentException e) {
            // Ignore
        }
    }

    private static boolean getResponse(int bet) {
        System.out.println(bet + " R");
        System.out.flush();
        final var scanner = new Scanner(System.in);
        final var n = scanner.nextInt();
        if (n == 0) {
            return false;
        }
        if (n == 1) {
            return true;
        }
        throw new IllegalStateException();
    }

    private static int calculateBet(int balance, int gamesAfterLastLose) {
        if (balance >= 260) {
            isFirstStrategyEnabled = false;
        }
        if (isFirstStrategyEnabled) {
            return switch (gamesAfterLastLose) {
                case 1 -> 10;
                case 2 -> 20;
                case 3 -> 60;
                case 4 -> 120;
                default -> 0;
            };
        } else {
            if (gamesAfterLastLose == 1) {
                lastSecondStrategyMinBet = balance / 26;
            }
            return switch (gamesAfterLastLose) {
                case 1 -> lastSecondStrategyMinBet;
                case 2 -> 3 * lastSecondStrategyMinBet;
                case 3 -> 7 * lastSecondStrategyMinBet;
                case 4 -> 15 * lastSecondStrategyMinBet;
                default -> 0;
            };
        }
    }
}
