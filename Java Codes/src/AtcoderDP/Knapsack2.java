package AtcoderDP;

import java.util.Scanner;

import static java.lang.Math.min;

public class Knapsack2 {



    static final int N = 101;
    static long W, n;

    static long[] v = new long[N], w = new long[N];
    static long[][] mW = new  long[N][100001], dp = new long[N][100001];

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        n = scn.nextInt();
        W = scn.nextInt();

        for (int i = 1; i <= n; i++) {
            w[i] = scn.nextLong();
            v[i] = scn.nextLong();
        }

        for (int i = 0; i <= n; i++) {
            for (int val = 0; val < 100001; val++) {
                mW[i][val] = (long) 1e13;
            }
        }

        dp[0][0] = 1;
        mW[0][0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int val = 0; val < 100001; val++) {
                // not taking
                if (dp[i - 1][val] != 0) {
                    dp[i][val] = 1;
                    mW[i][val] = min(mW[i][val], mW[i - 1][val]);
                }
                // taking item
                if (val - v[i] >= 0 && dp[i - 1][(int) (val - v[i])] != 0
                        && mW[i - 1][(int) (val - v[i])] + w[i] <= W) {
                    dp[i][val] = 1;
                    mW[i][val] = min(mW[i][val], mW[i - 1][(int) (val - v[i])] + w[i]);
                }
            }
        }

        int ans = 0;
        for (int val = 0; val < 100001; val++) {
            if (dp[(int) n][val] != 0) ans = val;
        }

        System.out.println(ans);

    }
}
