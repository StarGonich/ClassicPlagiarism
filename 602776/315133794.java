import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.TreeSet;

public class Main {

    static class FastReader {
        StreamTokenizer in;
        PrintWriter out;

        public FastReader() {
            in = new StreamTokenizer((new BufferedReader(new InputStreamReader(System.in))));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        }

        public void println(Object o) {
            out.println(o);
            out.flush();
        }

        public void print(Object o) {
            out.print(o);
            out.flush();
        }

        public int nextInt() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (int) in.nval;
        }

        public double nextDouble() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return in.nval;
        }

        public long nextLong() {
            try {
                in.nextToken();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return (long) in.nval;
        }
    }

    public static void main(String[] args) {

        FastReader fastReader = new FastReader();

        HashMap<Integer, Integer> coordSet = new HashMap<>();
        ArrayList<Integer> distSet = new ArrayList<>();

        int n = fastReader.nextInt();
        for (int i = 0; i < n; i++) {
            coordSet.put(i,fastReader.nextInt());
        }

        for (int i = 0; i < n; i++) {
            distSet.add(fastReader.nextInt());
        }

        int k = fastReader.nextInt()-1;

        int count = 1;
        int maxDist = coordSet.get(k) + distSet.get(k);
        int minDist = coordSet.get(k) - distSet.get(k);
        coordSet.remove(k);

        HashSet<Integer> hashSet = new HashSet<>();
        while(!coordSet.isEmpty()) {
            TreeSet<Integer> treeSet = new TreeSet<>(coordSet.keySet());
            if(minDist>coordSet.get(treeSet.getLast()) || maxDist<coordSet.get((treeSet.getFirst()))) {
                break;
            }
            for (int ks : coordSet.keySet()) {
                if(coordSet.get(ks)>=minDist && coordSet.get(ks)<=maxDist) {
                    if(minDist > 0 && (minDist < coordSet.get(ks) - distSet.get(ks))) {
                        minDist = coordSet.get(ks) - distSet.get(ks);
                    }
                    if(maxDist < 1000000000 && (maxDist < coordSet.get(ks) + distSet.get(ks))) {
                        maxDist = coordSet.get(ks) + distSet.get(ks);
                    }
                    count++;
                    hashSet.add(ks);
                }

            }
            for(int m : hashSet) {

                coordSet.remove(m);
            }
        }

        System.out.println(count);
    }
}