package DFSTreesAndBackEdges;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class DfsTreesAndBackEdges {

    final static int N = (int) (1e5 + 1);

    static List<List<Integer>> gr;
    static {
        for(int i = 0; i < N; i++){
            gr.add(new ArrayList<>());
        }
    }
    static int[] vis = new int[N];
    static boolean cycle = false;

    static void dfs(int cur, int par) {
        vis[cur] = 1;
        for (int x : gr.get(cur)) {
            if (vis[x] == 0) {
                dfs(x, cur);
            }
            else if (x != par) {
                cycle = true;
            }
        }
    }

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt(), m = scn.nextInt();

        for (int i = 0; i < m; i++) {
            int x = scn.nextInt(), y = scn.nextInt();
            gr.get(x).add(y);
            gr.get(y).add(x);

        }

        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) {
                dfs(i, 0);
            }
        }

        if (cycle) {
            System.out.println("Yes cycle found");
        }
        else {
            System.out.println("Not found");
        }


    }
}
