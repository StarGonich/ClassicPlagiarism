import java.util.Scanner;

public class D {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] mines = new int[n];
        for (int i = 0; i < n; i++) {
            mines[i] = sc.nextInt();
        }
        int[] minesExplosionDistance = new int[n];
        for (int i = 0; i < n; i++) {
            minesExplosionDistance[i] = sc.nextInt();
        }
        int k = sc.nextInt() - 1;
        int minDist = mines[k] - minesExplosionDistance[k];
        int maxDist = mines[k] + minesExplosionDistance[k];
        int L = k - 1, R = k + 1;
        boolean minesExploding = true;
        int ctr = 1;
        int last = 0;
        while (minesExploding){
            while (R < n){
                if (mines[R] <= maxDist){
                    minDist = Math.min(minDist, mines[R] - minesExplosionDistance[R]);
                    maxDist = Math.max(maxDist,mines[R] + minesExplosionDistance[R]);
                    ctr++;
                    R++;
                }else{
                    break;
                }
            }
            while (L >= 0){
                if (mines[L] >= minDist){
                    minDist = Math.min(minDist, mines[L] - minesExplosionDistance[L]);
                    maxDist = Math.max(maxDist,mines[L] + minesExplosionDistance[L]);
                    ctr++;
                    L--;
                }else{
                    break;
                }
            }
            if (last == R-L){
                minesExploding = false;
            }else{
                last = R-L;
            }
        }
        System.out.println(ctr);
    }
}
