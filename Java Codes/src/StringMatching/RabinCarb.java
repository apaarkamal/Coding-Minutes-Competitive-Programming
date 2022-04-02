package StringMatching;

public class RabinCarb {

    static final int p = 31, mod = (int) (1e9 + 7);

    static long poly_hash(String s) {
        long hash = 0;
        long p_power = 1;

        for (int i = 0; i < s.length(); i++) {
            hash += (long) (s.charAt(i) - 'a' + 1) * p_power;
            p_power *= p;

            hash %= mod;
            p_power %= mod;
        }

        return hash;
    }


    static int powr(int a, int b) {
        // (a^b)%mod
        int res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res *= a;
            b /= 2;
            a *= a;

            a %= mod;
            res %= mod;
        }
        return res;
    }

    static int inv(int x) {
        return powr(x, mod - 2);
    }

    public static void main(String[] args) {


        String text = "ababbabbaba";
        String pattern = "aba";

        long pat_hash = poly_hash(pattern);

        int n = text.length(), m = pattern.length();

        long text_hash = poly_hash(text.substring(0, m));

        if (pat_hash == text_hash) {
            System.out.println(0);
        }


        for (int i = 1; i + m <= n; i++) {
            // remove last character
            text_hash = (text_hash - (text.charAt(i - 1) - 'a' + 1) + mod) % mod;

            text_hash = (text_hash * inv(p)) % mod;

            text_hash = (text_hash + (long) (text.charAt(i + m - 1) - 'a' + 1) * powr(p, m - 1)) % mod;


            if (text_hash == pat_hash) {
                System.out.println(i);
            }
        }


    }
}
