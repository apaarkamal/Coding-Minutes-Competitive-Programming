package AtcoderDP;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class IndependentSet {


    static final int N = (int) (1e5 + 1), mod = (int) (1e9 + 7);


    static List<List<Integer>> gr = new ArrayList<>();
    static {
        for(int i = 0 ;i < N; i++){
            gr.add(new ArrayList<>());
        }
    }
    static int[][] memo = new int[N][2];

    static int dp(int cur, int paint, int par) {
        int ans = memo[cur][paint];

        if (ans != -1) return ans;

        ans = 1;
        for (int child : gr.get(cur)) {
            if (child != par) {
                if (paint != 0) {
                    ans *= dp(child, 0, cur) + dp(child, 1, cur);
                } else {
                    ans *= dp(child, 1, cur);
                }
                ans %= mod;
            }
        }

        return ans;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        for (int i = 0; i < n - 1; i++) {
            int x = scanner.nextInt(), y = scanner.nextInt();
            gr.get(x).add(y);
            gr.get(y).add(x);
        }


        for(int i = 0; i < memo.length; i++){
            Arrays.fill(memo[i], -1);
        }

        System.out.println((dp(1, 1, 0) + dp(1, 0, 0)) % mod);

    }
}
