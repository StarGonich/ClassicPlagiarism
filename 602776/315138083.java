import java.util.Scanner;

public class H {
    public static void main(String[] args) {
        long answer = 0;
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ctrChet = Math.floorDiv(n, 2);
        int ctrNechet = Math.ceilDiv(n, 2);
        for (int i = 1; i < n; i++) {
            if (i == 1) {
                answer += (long) (Math.pow(2, ctrChet - 1) + Math.pow(2, ctrNechet - 2)) -1 ;
            } else if (i == n - 1) {
                if (n % 2 == 0) {
                    answer += (long) (Math.pow(2, ctrNechet - 1) + Math.pow(2, ctrChet - 2)) -1;
                } else {
                    answer += (long) (Math.pow(2, ctrChet - 1) + Math.pow(2, ctrNechet - 2)) -1;
                }
            } else {
                answer += (long) (Math.pow(2, ctrChet - 2) + Math.pow(2, ctrNechet - 2)) -1 ;
            }

        }
        System.out.println(answer % (long) (Math.pow(10, 9) + 7));
    }


}
