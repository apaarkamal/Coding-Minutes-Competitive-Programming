package AtcoderDP;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class TabulationVsMemorisation {


    static int[] memo;
    static int cnt = 0;
    static int fib(int n) {
        cnt++;
        if (n <= 2) return 1;
        // memoisation part
        if (memo[n] != -1) return memo[n];
        // recursive relation

        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }

    public static void main(String[] args) {


         int n = 20;
         memo = new int[n];
         Arrays.fill(memo, -1);
        System.out.println(fib(n));
        System.out.println(cnt);

        // tabulation
        n = 20;
        int[] fib = new int[n + 1];
        fib[1] = fib[2] = 1;

        for (int i = 3; i <= n; i++) {
            fib[i] = fib[i - 1] + fib[i - 2];
        }

        System.out.println(fib[n]);

    }
}
