package TheoremsInNumberTheory;

public class ModuloArithmetics {

    final static int P = 1000000007, N = 10000;

    static int[] fact = new int[N];

    static int addm(int x, int y) {
        return (x + y) % P;
    }

    static int subm(int x, int y) {
        return ((x - y) % P + P) % P;
    }

    static int mulm(int x, int y) {
        return (x * y) % P;
    }

    static int powrm(int x, int y) {
        int res = 1;
        while (y > 0) {
            if ((y & 1) == 1){
                res = mulm(res, x);
            }
            y /= 2;
            x = mulm(x, x);
        }
        return res;
    }

    static int inv(int x) {
        return powrm(x, P - 2);
    }

    static int divm(int x, int y) {
        return mulm(x, inv(y));
    }

    static void calculate_factorials() {
        fact[0] = 1;
        for (int i = 1; i < N; i++) {
            fact[i] = mulm(fact[i - 1], i);
        }
    }

    static int ncr(int n, int r) {
        return mulm(mulm(fact[n], inv(fact[r])), inv(fact[n - r]));
    }

    public static void main(String[] args) {


        System.out.println(addm(3, 5));
        System.out.println(subm(3, 5));
        System.out.println(mulm(324, 234));
        System.out.println(divm(56, 2));
        calculate_factorials();
        System.out.println(fact[5]);
        System.out.println(ncr(5,2));
        System.out.println(ncr(5778,123));


    }
}
