package AtcoderDP;

import java.util.Scanner;

public class Deque1 {



    final static int N = 3001;

    static int n;
    static long[] a = new long[N];
    static long sum = 0;
    static long[][][] memo = new long[N][N][2];

    static long dp(int i, int j, int turn) {
        if (i > j) return 0;
        // if (i == j) {
        // 	if (turn == 0) return a[i];
        // 	else return 0;
        // }
        long ans = memo[i][j][turn];
        if (ans != 1e18) return ans;
        if (turn == 0) {
            ans = Math.max(a[i] + dp(i + 1, j, 1 - turn),
                    a[j] + dp(i, j - 1, 1 - turn));
        }
        else {
            ans = Math.min(dp(i + 1, j, 1 - turn), dp(i, j - 1, 1 - turn));
        }
        return ans;
    }

    public static void main(String[] args) {



        Scanner scn = new Scanner(System.in);
        n = scn.nextInt();
        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
            sum += a[i];
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                memo[i][j][0] = memo[i][j][1] = (long)1e18;
            }
        }

        long max_x = dp(0, n - 1, 0);

        long min_y = sum - max_x;

        System.out.println(max_x - min_y);

    }
}
