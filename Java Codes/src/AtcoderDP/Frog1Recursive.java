package AtcoderDP;

import javax.print.attribute.standard.MediaName;
import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.abs;
import static java.util.Collections.min;

public class Frog1Recursive {


    static final int N = (int)1e5;

    static int[] h = new int[N], memo = new int[N];

    static int dp(int n) {
        if (n == 0) return 0;

        int ans = memo[n];

        if (ans != -1) return ans;

        ans = dp(n - 1) + Math.abs(h[n - 1] - h[n]);

        if (n - 2 >= 0) {
            ans = Math.min(ans, dp(n - 2) + abs(h[n - 2] - h[n]));
        }
        return ans;
    }

    public static void main(String[] args) {


        Scanner scn =  new Scanner(System.in);
        int n = scn.nextInt();
        for (int i = 0; i < n; i++) {
            h[i] = scn.nextInt();
        }

        Arrays.fill(memo, -1);
        System.out.println(dp(n - 1));

    }
}
