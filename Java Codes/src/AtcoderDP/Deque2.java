package AtcoderDP;

import java.util.Scanner;

import static java.lang.Math.max;

public class Deque2 {


    static final int N = 3001;

    static int n;
    static long[] a = new long[N];
    static long[][] memo = new long[N][N];

    static long dp(int i, int j) {
        if (i == j) return a[i];
        long ans = memo[i][j];
        if (ans != -1e18) return ans;
        ans = max(a[i] - dp(i + 1, j), a[j] - dp(i, j - 1));
        return ans;
    }

    public static void main(String[] args) {


        Scanner scn = new Scanner(System.in);
        n = scn.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                memo[i][j] = (long) -1e18;
            }
        }

        System.out.println(dp(0, n - 1));

    }
}
