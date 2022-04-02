package AtcoderDP;

import java.util.Scanner;

public class Coins {


    final static int N = 3001;

    static double[] p = new double[N];
    static double[][] memo = new double[N][N];
    static int n;


    static double dp(int i, int h, int t) {
        if (i == n) return 1.00;
        double ans = memo[i][h];
        if (ans != -1.00) return ans;
        ans = 0.00;
        if (h != 0) {
            ans += dp(i + 1, h - 1, t) * p[i];
        }
        if (t != 0) {
            ans += dp(i + 1, h, t - 1) * (1.00 - p[i]);
        }
        return ans;
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        n = scn.nextInt();
        for (int i = 0; i < n; i++) {
            p[i] = scn.nextInt();
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                memo[i][j] = -1.00;
            }
        }

        double ans = 0;
        for (int i = (n / 2 + 1); i <= n; i++) {
            ans += dp(0, i, n - i);
        }
        System.out.println(ans);
    }
}
