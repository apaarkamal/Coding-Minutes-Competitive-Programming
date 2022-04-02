package AtcoderDP;

import java.util.Arrays;
import java.util.Scanner;

public class LCS {



static final int N = 3000;

    static StringBuilder s, t, res;
    static int n, m;
    static int[][] memo = new int[N][N];

    static int give_lcs(int i, int j) {
        if (i == n || j == m) return 0;

        int ans = memo[i][j];

        if (ans != -1) return ans;

        if (s.charAt(i) == t.charAt(j)) {
            ans = give_lcs(i + 1, j + 1) + 1;
        }
        else ans = Math.max(give_lcs(i + 1, j), give_lcs(i, j + 1));

        return ans;
    }

    static void trace_back(int i, int j) {
        if (i == n || j == m) return;

        if (s.charAt(i) == t.charAt(j)) {
            res.append(s.charAt(i));
            trace_back(i + 1, j + 1);
        }
        else {
            if (give_lcs(i + 1, j) == give_lcs(i, j)) {
                trace_back(i + 1, j);
            }
            else {
                trace_back(i, j + 1);
            }
        }
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        s = new StringBuilder(scn.next());
        t = new StringBuilder(scn.next());
        n = s.length();
        m = t.length();

        for(int[] a: memo) {
            Arrays.fill(a, -1);
        }

        int l = give_lcs(0, 0);

        trace_back(0, 0);

        System.out.println(res);

    }
}
