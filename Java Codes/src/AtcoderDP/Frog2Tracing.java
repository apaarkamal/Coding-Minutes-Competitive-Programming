package AtcoderDP;

import java.util.Scanner;

import static java.lang.Math.abs;

public class Frog2Tracing {


    static final int N = (int) 1e5;
    static int n, k;
    static int[] h = new int[N];
    static int[] dp = new int[N];

    static void go(int i) {
        System.out.println(i+1);
        for (int kk = 1; kk <= k && i - kk >= 0; kk++) {
            if (dp[i] == dp[i - kk] + abs(h[i] - h[i - kk])) {
                go(i - kk);
                return;
            }
        }
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);

        n = scn.nextInt();
        k = scn.nextInt();

        for (int i = 0; i < n; i++) {
            h[i] = scn.nextInt();
        }


        dp[0] = 0;
        dp[1] = dp[0] + abs(h[1] - h[0]);

        for (int i = 2; i < n; i++) {
            dp[i] = Integer.MAX_VALUE;
            for (int kk = 1; kk <= k && i - kk >= 0; kk++) {
                dp[i] = Math.min(dp[i], dp[i - kk] + abs(h[i] - h[i - kk]));
            }
        }

        System.out.println(dp[n-1]);

        // for (int i = 0; i < n; i++) {
//        System.out.println(dp[i]);
        // }

        //trace back
        // go(n - 1);


    }
}
