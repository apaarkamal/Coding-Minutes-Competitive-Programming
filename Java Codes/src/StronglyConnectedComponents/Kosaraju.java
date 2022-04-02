package StronglyConnectedComponents;

import java.util.*;

public class Kosaraju {

    static final int N = (int) (1e5 + 1);

    static List<List<Integer>> gr = new ArrayList<>();
    static List<List<Integer>> grr = new ArrayList<>();
    static List<List<Integer>> components = new ArrayList<>();
    static {
        for(int i = 0; i < N; i++){
            gr.add(new ArrayList<>());
            grr.add(new ArrayList<>());
            components.add(new ArrayList<>());
        }
    }
    static List<Integer> order = new ArrayList<>();
    static int[] vis = new int[N];
    static int[] col = new int[N];




    // topological sorting
    static void dfs1(int cur) {
        vis[cur] = 1;
        for (int x : gr.get(cur)) {
            if (vis[x] == 0) dfs1(x);
        }
        order.add(cur);
    }

    static void dfs2(int cur, int comp) {
        vis[cur] = 1;
        col[cur] = comp;
        components.get(comp).add(cur);
        for (int x : grr.get(cur)) {
            if (vis[x] == 0) dfs2(x, comp);
        }
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

        for (int i = 1; i <= n; i++) {
            if (vis[i] == 0) dfs1(i);
        }

        Collections.reverse(order);
        Arrays.fill(vis, 0);

        int comp = 1;
        for (int x : order) {
            // cout << x << " ";
            if (vis[x] == 0) dfs2(x, comp++);
        }

        for (int i = 1; i <= n; i++) {
            System.out.println(i + " " + col[i]);
        }

        System.out.println( "Total strongly components are -> " + (comp - 1) );

        // complexity O(n+m)

    }
}
