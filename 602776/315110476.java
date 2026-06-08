import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i <= n; i++) {
            int val = scanner.nextInt();
            arr[i] = val;
        }
        int cif = 0;
        int len = 0;
        int lenOne;
        int lenTwo;
        int[] ansOne = new int[2];
        int[] ansTwo = new int[2];
        List<Integer> listOne = new ArrayList<>();
        List<Integer> listTwo = new ArrayList<>();
        List<Integer> listOneOne = new ArrayList<>();
        List<Integer> listTwoTwo = new ArrayList<>();
        for (int j = 0; j < n + 1; j++) {
            if (arr[j+1] - arr[j] == 1) {
                listOne.add(arr[j]);
                listOneOne.add(j);
                cif++;
            }
            else if (arr[j+1] - arr[j] != 1 && cif != 0){
                break;
            }
        }
        cif++;
        for (int k = cif; k < n + 1; k++) {
            if (arr[cif+1] - arr[cif] == 1) {
                listTwo.add(arr[cif]);
                listTwoTwo.add(cif);
                len++;
            }
        }
        lenOne = listOne.size() + 1;
        lenTwo = listTwo.size() + 1;
        if (listOne.getFirst() - listTwo.get(len) == 1) {
            ansOne[0] = listOneOne.getFirst();
            ansOne[1] = lenOne;
            ansTwo[0] = listTwoTwo.getFirst();
            ansTwo[1] = lenTwo;
            System.out.println(ansOne);
            System.out.println(ansTwo);
        }
        else {
            System.out.print(-1);
        }
        scanner.close();
    }

}