import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int s = 0;
        int h = 1;
        if (n > 2 && n < 5){
            s = n + 1;
        } else if( n >= 5){
            s = 5;
            h=2;
            for (int i = 1; i <= n - 4; i++){
                s+=h;
                h++;
            }
        }
        System.out.println(s);
    }
}