public class Mainik {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int cnt = 3;
        for (int i = 8; i <= n; i++) {
            if (i % 4 == 0 && i % 5 != 0 && i % 6 != 0 ||
                    i % 4 != 0 && i % 5 == 0 && i % 6 != 0 ||
                    i % 4 != 0 && i % 5 != 0 && i % 6 == 0) {
                cnt++;
            }
        }
        System.out.print(cnt);
    }
}
