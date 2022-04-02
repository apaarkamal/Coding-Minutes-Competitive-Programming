package DFSTreesAndBackEdges;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class PrintCycleInGraph {

    final static int N = (int) (1e5 + 1);

    static List<List<Integer>> gr;
    static {
        for(int i = 0; i < N; i++){
            gr.add(new ArrayList<>());
        }
    }
    static int[] vis = new int[N], Par = new int[N];
    static boolean cycle = false;



    static void dfs(int cur, int par) {
        // visited and in call stack
        vis[cur] = 1;
        Par[cur] = par;
        for (int x : gr.get(cur)) {
            if (vis[x] == 0) {
                dfs(x, cur);
            }
            else if (x != par && vis[x] == 1) {
                // backedge
                cycle = true;

                int u = cur, v = x;

                while (u != v) {
                    System.out.print(u + " ");
                    u = Par[u];
                }
                System.out.print(u + " ");
                System.exit(0);
            }
        }
        // visited and not in call stack
        vis[cur] = 2;
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
