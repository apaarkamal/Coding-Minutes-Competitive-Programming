package SquareRootDecomposition;

import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class DQuerySPOJ {


    static final int N = (int) 2e5;

    static int[] a = new int[N], cnt = new int[N * 10];
    static int distinct;


    static class query {
        int l, r, ans, id, block;
    }
    static query[] q = new query[N];

    static void add(int val) {
        cnt[val]++;
        if (cnt[val] == 1) distinct++;
    }

    static void remove(int val) {
        cnt[val]--;
        if (cnt[val] == 0) distinct--;
    }

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(), m;

        m = (int) (Math.sqrt(n));

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


        int x = 0, y = 0;

        for (int i = 0; i < queries; i++) {

            // adding y
            while (y <= q[i].r) {
                add(a[y]);
                y++;
            }

            // removing y
            while (y > q[i].r + 1) {
                y--;
                remove(a[y]);
            }

            // removing x
            while (x < q[i].l) {
                remove(a[x]);
                x++;
            }

            // adding x
            while (x > q[i].l) {
                x--;
                add(a[x]);
            }

            // distinct indicated the answer
            q[i].ans = distinct;
        }

        Arrays.sort(q, Comparator.comparingInt(a -> a.id));

        for (int i = 0; i < queries; i++) {
            System.out.println(q[i].ans);
        }




    }
}
