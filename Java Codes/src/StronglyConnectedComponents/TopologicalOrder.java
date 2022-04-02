package StronglyConnectedComponents;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class TopologicalOrder {

    static final int N = (int) (1e5 + 1);

    static List<List<Integer>> gr = new ArrayList<>();
    static {
        for(int i = 0; i < N; i++){
            gr.add(new ArrayList<>());
        }
    }
    static List<Integer> order = new ArrayList<>();
   static int[] vis = new int[N];

    static void dfs(int cur, int par) {
        vis[cur] = 1;
        for (int x : gr.get(cur)) {
            if (vis[x] == 0) {
                dfs(x, cur);
            }
        }
        // I am here because I came back from the subtree
        order.add(cur);
        return;
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
            if (vis[i] == 0) dfs(i, 0);
        }

        Collections.reverse(order);
        for(int i: order){
            System.out.println(i);
        }
    }
}
