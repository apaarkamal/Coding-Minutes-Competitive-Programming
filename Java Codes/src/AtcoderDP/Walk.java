package AtcoderDP;

import java.util.Scanner;

public class Walk {


    static final int mod = (int) (1e9 + 7);
    static final int sz = 51;

    static class Mat {
        int[][] m = new int[sz][sz];

        void eye() {
        for (int i = 0; i < sz; i++)
            m[i][i] = 1;
        }

        Mat multiply (Mat a){
            Mat r = new Mat();
            for (int i = 0; i < sz; i++)
                for (int j = 0; j < sz; j++)
                    for (int k = 0; k < sz; k++)
                        r.m[i][j] = (r.m[i][j] + m[i][k] * a.m[k][j]) % mod;
            return r;
        }
    }

    public static void main(String[] args) {


        Scanner scn = new Scanner(System.in);
        Mat a = new Mat(), res = new Mat();

        int n = scn.nextInt();
        int k = scn.nextInt();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a.m[i][j] = scn.nextInt();
            }
        }

        res.eye();

        while (k > 0) {
            if ((k & 1) == 1) {
                res = res.multiply(a);
            }
            a = a.multiply(a);
            k /= 2;
        }


        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans += res.m[i][j];
                ans %= mod;
            }
        }

        System.out.println(ans);

    }
}
