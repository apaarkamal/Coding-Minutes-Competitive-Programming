package AtcoderDP;

import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

import static java.lang.Math.max;

public class LongestPath {

    static final int N = (int) (1e5 + 1);

    static List<List<Integer>> gr = new ArrayList<>();
    static {
        for(int i = 0 ; i < N; i++){
            gr.add(new ArrayList<>());
        }
    }
    static int[] memo = new int[N];

    static int dp(int cur) {
        int ans = memo[cur];
        if (ans != -1) return ans;
        ans = 0;
        for (int x : gr.get(cur)) {
            ans = max(ans, dp(x) + 1);
        }
        return ans;
    }

    public static void main(String[] args) {


        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int m = scn.nextInt();

        for (int i = 0; i < m; i++) {

            int x = scn.nextInt();
            int y = scn.nextInt();

            gr.get(x).add(y);
        }

        Arrays.fill(memo, -1);

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = max(ans, dp(i));
        }
        System.out.println(ans);
    }
}
