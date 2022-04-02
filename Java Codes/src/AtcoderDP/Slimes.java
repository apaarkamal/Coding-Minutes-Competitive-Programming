package AtcoderDP;

import java.util.Scanner;

public class Slimes {

    static final int N = 400;

    static int n;
    static long[] a = new long[N], pref = new long[N];
    static long[][] memo = new long[N][N];

    static long sum(int l, int r) {
        return pref[r] - (l == 0 ? 0 : pref[l - 1]);
    }

    static long dp(int l, int r) {
        if (l == r) return 0;
        long ans = memo[l][r];
        if (ans != 0) {
            return ans;
        }

        // ans=0
        ans = (long) 1e18;
        for (int i = l; i < r; i++) {
            ans = Math.min(ans, dp(l, i) + dp(i + 1, r) + sum(l, r));
        }

        return ans;
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        n = scn.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
            pref[i] = a[i];
            if (i != 0) {
                pref[i] += pref[i - 1];
            }
        }

        System.out.println(dp(0, n-1));
    }
}
