package LCA;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class TwoPointers {


    static final int N = (int) 1e5;

    static List<List<Integer>> gr;
    static {
        gr = new ArrayList<>();
        for(int i = 0; i < N; i++){
            gr.add(new ArrayList<>());
        }
    }

    static int[] dep = new int[N], Par = new int[N];

    static void dfs(int cur, int par) {
        Par[cur] = par;
        dep[cur] = dep[par] + 1;
        for (int x : gr.get(cur)) {
            if (x != par) {
                dfs(x, cur);
            }
        }
    }

    static int LCA(int u, int v) {
        if (u == v) return u;

        if (dep[u] < dep[v]) {
            int a = u;
            u = v;
            v = a;
        }
        // depth of u is more than depth of v

        int diff = dep[u] - dep[v];

        // depth of both nodes same
        while (diff-- > 0) {
            u = Par[u];
        }

        // until they are equal nodes keep climbing
        while (u != v) {
            u = Par[u];
            v = Par[v];
        }

        return u;
    }

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();


        for (int i = 1; i < n; i++) {
            int x =scanner.nextInt(), y=scanner.nextInt();
            gr.get(x).add(y);
            gr.get(y).add(x);
        }

        dfs(1, 0);
        System.out.println(LCA(9, 12));

    }
}
