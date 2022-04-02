package AtcoderDP;

import java.util.Scanner;

import static java.lang.Math.max;

public class Flowers {

    static class segmentTree {
        int[] st;
        int n;
        void init(int _n) {
            n = _n;
            st = new int[4 * _n];
        }
        void build(int l, int r, int node) {
            if (l == r) {
                return;
            }
            int mid = (l + r) / 2;
            build(l, mid, node * 2 + 1);
            build(mid + 1, r, node * 2 + 2);
            st[node] = max(st[2 * node + 1], st[2 * node + 2]);
        }

        void update(int l, int r, int indup, int val, int node) {
            if (l == r) {
                st[node] = val;
                return;
            }
            else {
                int mid = (l + r) / 2;
                if (indup >= l && indup <= mid) {
                    update(l, mid, indup, val, node * 2 + 1);
                }
                else {
                    update(mid + 1, r, indup, val, node * 2 + 2);
                }
                st[node] = max(st[2 * node + 1], st[2 * node + 2]);
            }
        }

        int query(int si, int se, int l, int r, int node) {
            if (se < l || si > r || l > r) {
                return 0;
            }
            if (si >= l && se <= r) {
                return st[node];
            }
            int mid = (si + se) / 2;
            int q1 = query(si, mid, l, r, node * 2 + 1);
            int q2 = query(mid + 1, se, l, r, node * 2 + 2);
            return max(q1, q2);
        }
        void build(int n) {
            init(n);
            build(0, n - 1, 0);
        }
        int query(int l, int r) {
            return query(0, n - 1, l, r, 0);
        }
        void update(int index, int val) {
            update(0, n - 1, index, val, 0);
        }
    }

    public static void main(String[] args) {


        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int[] h = new int[n], a = new int[n], dp = new int[n], idx = new int[n];

        for (int i = 0; i < n; i++) {
            h[i] = scn.nextInt();
            h[i]--;
            idx[h[i]] = i;
        }
        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
        }

        segmentTree tree = new segmentTree();
        tree.init(n);

        for (int hh = 0; hh < n; hh++) {
            int index = idx[hh];
            dp[index] = tree.query(0, index - 1) + a[index];
            tree.update(index, dp[index]);
        }

        // for (int i = 0; i < n; i++) {
        // 	cout << dp[i] << '\n';
        // }

        System.out.println(tree.query(0, n - 1));

    }
}
