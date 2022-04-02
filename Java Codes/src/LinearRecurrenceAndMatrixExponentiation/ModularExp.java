package LinearRecurrenceAndMatrixExponentiation;

public class ModularExp {


    static final int mod = 1000000007;

    static long powr(long a, long b) {
        long res = 1;
        while (b > 0) {
            if ((b & 1) ==1 ) {
                res *= a;
                res %= mod;
            }
            a *= a; a %= mod;
            b /= 2;
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(powr(2L, 200L));
    }
}
