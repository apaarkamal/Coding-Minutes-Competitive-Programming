package AtcoderDP;

import java.util.Scanner;

public class Sushi {


    static int n;


    static final int N = 301;

    static double[][][] memo = new double[N][N][N];

    static double dp(int zero, int one, int two, int three) {
        // cout << zero << " " << one << " " << two << " " << three << '\n';

        if (one + two + three == 0)
            return 0.0;

        double ans = memo[one][two][three];
        if (ans != -1.00) return ans;
        ans = n;
        if (one != 0)  ans += one * dp(zero + 1, one - 1, two, three);
        if (two != 0) ans += two * dp(zero, one + 1, two - 1, three);
        if (three != 0) ans += three * dp(zero, one, two + 1, three - 1);
        ans /= (double) (n - zero);
        return ans;
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        n = scn.nextInt();
        int[] a = new int[n];

        int[] cnt = new int[4];


        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
            cnt[a[i]]++;
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    memo[i][j][k] = -1.00;
                }
            }
        }


        double ans = dp(cnt[0], cnt[1], cnt[2], cnt[3]);
        System.out.println(ans);

    }
}
