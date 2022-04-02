package LinearRecurrenceAndMatrixExponentiation;

import java.io.File;

public class MatrixExp {

    final static int mod = 1000000007;
    final static int sz = 2;

    static class Mat {
        int[][] m = new int[sz][sz];

        void identity() {
            for (int i = 0; i < sz; i++) {
                m[i][i] = 1;
            }
        }
        Mat multiply(Mat a) {
            Mat res = new Mat();
            for (int i = 0; i < sz; i++) {
                for (int j = 0; j < sz; j++) {
                    for (int k = 0; k < sz; k++) {
                        res.m[i][j] += m[i][k] * a.m[k][j];
                        res.m[i][j] %= mod;
                    }
                }
            }
            return res;
        }
    }

    static int Fib(int n) {
        Mat res = new Mat();
        res.identity();
        Mat T = new Mat();
        T.m[0][0] = T.m[0][1] = T.m[1][0] = 1;

        if (n <= 2) return 1;
        n -= 2;

        // log(n)
        while (n > 0) {
            if ((n & 1) == 1) {res = res.multiply(T);}
            T = T.multiply(T);
            n /= 2;
        }

        return (res.m[0][0] + res.m[0][1]) % mod;
    }

    public static void main(String[] args) {
        System.out.println(Fib(10));
    }
}
