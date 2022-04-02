package AtcoderDP;

import java.util.Scanner;

public class Candies {


    public static void main(String[] args) {


        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(), k = scn.nextInt(), mod = 1000000007;

        int[] a = new int[n + 1];

        for (int i = 1; i <= n; i++) {
            a[i] = scn.nextInt();
        }

        int[][] dp = new int[n + 1][k + 1];

        dp[0][0] = 1;

        // for (int i = 1; i <= n; i++) {
        // 	for (int j = 0; j <= k; j++) {
        // 		// dp[i][j];
        // 		for (int kk = 0; kk <= min(a[i], j); kk++) {
        // 			dp[i][j] += dp[i - 1][j - kk];
        // 		}
        // 	}
        // }

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j <= k; j++) {
                dp[i - 1][j] += dp[i - 1][j - 1];
            }

            for (int j = 0; j <= k; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - a[i] > 0) dp[i][j] -= dp[i - 1][j - a[i] - 1];
                dp[i][j] = ((dp[i][j] % mod) + mod) % mod;
            }
        }


        // for (int i = 0; i <= n; i++) {
        // 	for (int j = 0; j <= k; j++) {
        // 		cout << dp[i][j] << " ";
        // 	} cout << '\n';
        // }

        System.out.println(dp[n][k]);




    }
}
