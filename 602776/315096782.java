import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(pupupu(n));
    }
    public static int pupupu(int n){
        int k = 0;
        for (int i = 1; i <= n; i++){
            if ((i%5==0 && i%6!=0 && i%4!=0)||(i%5!=0 && i%6==0 && i%4!=0) || (i%5!=0 && i%6!=0 && i%4==0)){
                k++;
            }
        }
        return k;
    }
}