package AtcoderDP;

import java.util.Scanner;

import static java.lang.Math.abs;
import static java.lang.Math.min;

public class Frog1Tabulation {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] h = new int[n];

        for (int i = 0; i < n; i++) {
           h[i] = scn.nextInt();
        }

        int[] dp = new int[n];

        dp[0] = 0;
        dp[1] = dp[0] + abs(h[1] - h[0]);

        for (int i = 2; i < n; i++) {
            dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i]), dp[i - 2]
                    + abs(h[i - 2] - h[i]));
        }

        System.out.println(dp[n-1]);


    }
}
