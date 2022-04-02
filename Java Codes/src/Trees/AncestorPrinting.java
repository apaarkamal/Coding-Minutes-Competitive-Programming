package Trees;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class AncestorPrinting {

    final static int N = 100000;

    static List<List<Integer>> gr = new ArrayList<>(N);
    static {
        for(int i = 0; i < N; i++){
            gr.add(new ArrayList<>());
        }
    }
    static int[] Par = new int[N];

    static void dfs(int cur, int par) {
        Par[cur] = par;
        for (int x : gr.get(cur)) {
            if (x != par) {
                // x is child node
                dfs(x, cur);
            }
        }
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        for (int i = 0; i < n - 1; i++) {
            int x = scn.nextInt(), y = scn.nextInt();
            gr.get(x).add(y);
            gr.get(y).add(x);
        }

        dfs(10, 0);

        int x = 6;
        // print all ancestors of 5

        while (x > 0) {
            System.out.println(x);
            x = Par[x];
        }


    }
}
