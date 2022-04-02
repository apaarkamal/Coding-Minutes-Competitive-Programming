package AtcoderDP;

import java.util.Scanner;

public class Grid1 {

    public static void main(String[] args) {

        Scanner scn =  new Scanner(System.in);
        int n = scn.nextInt(), m = scn.nextInt(), mod = (int) (1e9 + 7);
        String[] s = new String[n];
        for (int i = 0; i < n; i++) {
            s[i] = scn.next();
        }

        int[][] dp = new int[n][m];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 && j == 0) dp[i][j] = 1;
                else if (i == 0) dp[i][j] = dp[i][j - 1];
                else if (j == 0) dp[i][j] = dp[i - 1][j];
                else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    dp[i][j] %= mod;
                }
                if (s[i].charAt(j) == '#') dp[i][j] = 0;
            }
        }

        System.out.println(dp[n - 1][m - 1]);


    }
}
