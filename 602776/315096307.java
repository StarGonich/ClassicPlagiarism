import java.util.Scanner;

public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] array = new int[n+1];
        for (int i = 4; i < n+1; i+=4) {
            array[i]++;
        }
        for (int i = 5; i < n+1; i+=5) {
            array[i]++;
        }
        for (int i = 6; i < n+1; i+=6) {
            array[i]++;
        }
        int answer = 0; //легендарный bruteforce
        for (int i = 0; i < n + 1; i++) {
            if (array[i] == 1){
                answer++;
            }
        }
        System.out.println(answer);
    }


}