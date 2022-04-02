package AtcoderDP;

import java.util.Arrays;
import java.util.Scanner;

public class Permutation {

    static int n, mod = (int) (1e9 + 7);
    static String str;

    static int[][] memo = new int[3005][3005];

    static int dp(int i, int s) {
        if (i == n) return 1;

        int ans = memo[i][s];

        if (ans != -1) return ans;

        ans = 0;
        if (str.charAt(i - 1) == '<') {
            int g = (n - i - s);
            for (int j = 1; j <= g; j++) {
                ans += dp(i + 1, s + j - 1);
            }
        }
        else {
            for (int j = 1; j <= s; j++) {
                ans += dp(i + 1, j - 1);
            }
        }

        return ans;
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        n = scn.nextInt();
        str = scn.next();


//         int ans = 0;
//         for(int[] a: memo){
//             Arrays.fill(a, -1);
//         }
//         for (int i = 1; i <= n; i++) {
//         	ans += dp(1, i - 1);
//         }
//        System.out.println(ans%mod);

        int[][] dp = new int[n + 1][n + 1];
        int ans = 0;


        dp[n][0] = 1;

        for (int i = n - 1; i > 0; i--) {

            for (int j = 1; j <= n; j++) {
                dp[i + 1][j] += dp[i + 1][j - 1];
            }

            for (int s = 0; s <= n; s++) {
                int g = (n - i - s);
                if (g < 0) continue;

                if (str.charAt(i - 1) == '<') {
                    dp[i][s] = dp[i + 1][s + g - 1] -
                            (s == 0 ? 0 : dp[i + 1][s - 1]);
                } else {
                    dp[i][s] = dp[i + 1][s - 1];
                }
                dp[i][s] %= mod;
            }

        }


        for (int i = 1; i <= n; i++) {
            ans += dp[1][i - 1];
            ans %= mod;
        }

        ans += mod;
        ans %= mod;

        System.out.println(ans);

    }
}
