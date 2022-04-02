package AtcoderDP;

import java.util.Scanner;

import static java.lang.Math.max;

public class Vacation {



static final int N = (int) 1e5;

    static int[][] a = new int[N][3];
    static int[][] dp = new int[N][3];

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                a[i][j] = scn.nextInt();
            }
        }

        dp[0][0] = a[0][0];
        dp[0][1] = a[0][1];
        dp[0][2] = a[0][2];

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int jj = 0; jj < 3; jj++) {
                    if (j != jj) {
                        dp[i][j] = max(dp[i][j], dp[i - 1][jj] + a[i][j]);
                    }
                }
            }
        }


        int max = Integer.MIN_VALUE;
        for(int x: dp[n-1]){
            max = Math.max(max, x);
        }
        System.out.println(max);

    }
}
