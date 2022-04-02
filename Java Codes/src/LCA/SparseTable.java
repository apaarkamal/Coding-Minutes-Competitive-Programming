package LCA;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class SparseTable {

    static final int N = (int) 1e5;
    static final int M = 20;



    static List<List<Integer>> gr;
    static {
        gr = new ArrayList<>();
        for(int i = 0; i < N; i++){
            gr.add(new ArrayList<>());
        }
    }

    static int[] dep = new int[N];
    static int[][] Par = new int[N][M];




    // O(N*M)
    static void dfs(int cur, int par) {
        dep[cur] = dep[par] + 1;

        Par[cur][0] = par;
        for (int j = 1; j < M; j++) {
            Par[cur][j] = Par[Par[cur][j - 1]][j - 1];
        }

        for (int x : gr.get(cur)) {
            if (x != par) {
                dfs(x, cur);
            }
        }
    }

    // O(M) = logN
    static int LCA(int u, int v) {
        if (u == v) return u;
        if (dep[u] < dep[v]) {
            int a = u;
            u = v;
            v = a;
        }
        int diff = dep[u] - dep[v];
        for (int j = M - 1; j >= 0; j--) {
            if (((diff >> j) & 1) == 1) {
                // jth bit of diff is set
                u = Par[u][j];
            }
        }
        // u and v are on the same level
        for (int j = M - 1; j >= 0; j--) {
            if (Par[u][j] != Par[v][j]) {
                u = Par[u][j];
                v = Par[v][j];
            }
        }

        // Par[v][0]
        return Par[u][0];
    }

    // O(1)
    static int LengthFromUtoV(int u, int v) {
        int lca = LCA(u, v);
        return dep[u] + dep[v] - 2 * dep[lca];
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

    }
}
