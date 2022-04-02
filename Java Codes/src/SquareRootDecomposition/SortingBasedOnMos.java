package SquareRootDecomposition;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class SortingBasedOnMos {



    static final int N = (int) 2e5;

    static int[] a = new int[N];

    static class query {
        int l, r, ans, id, block;
    }

    static query[] q = new query[N];

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(), m;

        m = (int) (Math.sqrt(n) + 1);

        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
        }

        int queries = scn.nextInt();

        for (int i = 0; i < queries; i++) {
            q[i].l = scn.nextInt();
            q[i].r = scn.nextInt();
            q[i].l--; q[i].r--;
            q[i].id = i;
            q[i].block = q[i].l / m;
        }

        Arrays.sort(q, new Comparator<query>() {
            @Override
            public int compare(query o1, query P) {
                if(o1.block!=P.block){
                    return o1.block - P.block;
                }
                return o1.r  - P.r;
            }
        });

        for (int i = 0; i < queries; i++) {
            System.out.println(q[i].id + " " + q[i].l + " " + q[i].r);
        }
    }
}
