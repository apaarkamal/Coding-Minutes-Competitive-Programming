package AtcoderDP;

import java.util.Arrays;
import java.util.Scanner;

import static java.lang.Math.max;

public class Knapsack1 {


    static final int N = 101;
    static int W, n;

    static int[] v = new int[N], w = new int[N];
    static int[][] memo = new int[N][100001];



    // it returns the maximum value total value
    static int knapsack(int index, int weight) {
        if (index >= n) return 0;

        // memoissatioon part
        int ans = memo[index][weight];
        if (ans != -1)
            return ans;

        // do not take the item
        ans = knapsack(index + 1, weight);
        // take the item at index
        if (w[index] + weight <= W) {
            ans = max(ans, v[index] + knapsack(index + 1, w[index] + weight));
        }
        return ans;
    }

    public static void main(String[] args) {



        Scanner scn = new Scanner(System.in);

        n = scn.nextInt();
        W = scn.nextInt();

        for (int i = 1; i <= n; i++) {
            w[i] = scn.nextInt();
            v[i] = scn.nextInt();
        }
        for(int[] a: memo) {
            Arrays.fill(a, -1);
        }

        int ans = knapsack(0, 0);

        System.out.println(ans);
    }
}
