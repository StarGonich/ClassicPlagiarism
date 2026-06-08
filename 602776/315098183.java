import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int POfA = Math.floorDiv(n, 4);
        int PofB = Math.floorDiv(n, 5);
        int PofC = Math.floorDiv(n, 6);
        int POfAandB = Math.floorDiv(n, 20);
        int POfAandC = Math.floorDiv(n, 12);
        int POfBandC = Math.floorDiv(n, 30);
        int POfAll = Math.floorDiv(n, 120);
        System.out.println(POfA + PofB + PofC - 2 * POfAandC - 2 * POfAandB - 2 * POfBandC + 3 * POfAll);
    }


}