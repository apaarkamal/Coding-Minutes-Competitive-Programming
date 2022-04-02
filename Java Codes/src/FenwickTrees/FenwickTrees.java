package FenwickTrees;

public class FenwickTrees {

    static class fenwick {
        int[] fn;
        int n;

        void init(int n) {
            this.n = n + 1;
            fn = new int[this.n];
        }

        void add(int x, int y) {
            x++; // 1 based index
            while (x < n) {
                fn[x] += y;
                x += (x & (-x));// last set bit
            }
        }

        // void add(int x, int y) {
        // 	for (x++; x < n; x += (x & (-x))) fn[x] += y;
        // }

        int sum(int x) {
            x++; // 1 based index
            int ans = 0;
            while (x  > 0) {
                ans += fn[x];
                x -= (x & (-x));// last set bit
            }
            return ans;
        }

        int sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }

    }

    public static void main(String[] args) {

        int[] v = {1, 2, 3, 4, 5, 6, 7};
        fenwick tree = new fenwick();
        tree.init(v.length);

        for (int i = 0; i < v.length; i++) {
            tree.add(i, v[i]);
        }

        System.out.println(tree.sum(3,5));

        tree.add(4, -3);

        System.out.println(tree.sum(3,5));

    }
}
