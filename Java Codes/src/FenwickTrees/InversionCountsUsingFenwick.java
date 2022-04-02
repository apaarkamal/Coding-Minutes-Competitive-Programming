package FenwickTrees;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class InversionCountsUsingFenwick {
    static class fenwick {
        int[] fn;
        int n;

        fenwick(int n) {
            this.n = n + 1;
            fn = new int[this.n];
        }

        void add(int x, int y) {
            x++; // 1 based index
            while (x < n) {
                fn[x] += y;
                x += (x & (-x));// last set bit
            }
        }

        // void add(int x, int y) {
        // 	for (x++; x < n; x += (x & (-x))) fn[x] += y;
        // }

        int sum(int x) {
            x++; // 1 based index
            int ans = 0;
            while (x  > 0) {
                ans += fn[x];
                x -= (x & (-x));// last set bit
            }
            return ans;
        }

        int sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }


    };

    static class Pair{
        public int first, second;
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        Pair[] a = new Pair[n];

        for (int i = 0; i < n; i++) {
            a[i] = new Pair();
            a[i].first = scn.nextInt();
            a[i].second = i;
        }

        Arrays.sort(a, new Comparator<Pair>() {
            @Override
            public int compare(Pair o1, Pair o2) {
                if(o1.first != o2.first){
                    return o1.first - o2.first;
                }
                return o1.second - o2.second;
            }
        });
        fenwick tree = new fenwick(n);
        int inversion_count = 0;
        int[] b = new int[n];

        for (int i = 0; i < n; i++) {
            int element = a[i].first;
            int index = a[i].second;

            b[index] = tree.sum(index + 1, n - 1);

            inversion_count += b[index];
            tree.add(index, 1);

        }

        System.out.println(inversion_count);





    }
}
