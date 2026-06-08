    import java.util.Scanner;
     
    public class Main {
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            int n = sc.nextInt();
            num1(n);
        }
        public static void num1(int n){
            int k = 0;
            for (int i = 4; i <= n; i++){
                if ((i%5==i%6!=0 && i%4==0)||(i%5==i%4!=0 && i%6==0) || (i%==i%6!=0 && i%5==0)){
                    k++;
                }
            }
            System.out.println(k);
        }
    }