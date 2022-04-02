package SquareRootDecomposition;

import java.util.Scanner;

public class SqrtDecomposition {

    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(), m;

        m = (int) (Math.sqrt(n) + 1);

        int[] a = new int[n], b = new int[m];

        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
            b[i / m] += a[i];
        }

        int q;
        q = scn.nextInt();
        while (q-- > 0) {
            int l, r, ans = 0;
            l = scn.nextInt();
            r = scn.nextInt();

            for (int i = l; i <= r;) {
                if (i % m == 0 && i + m - 1 <= r) {
                    // lies completely inside the [l...r]
                    ans += b[i / m];
                    i += m;
                }
                else {
                    ans += a[i];
                    i++;
                }

            }

            System.out.println(ans);

        }


    }
}
