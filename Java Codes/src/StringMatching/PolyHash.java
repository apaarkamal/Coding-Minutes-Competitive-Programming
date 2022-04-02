package StringMatching;

public class PolyHash {

    static long poly_hash(String s) {
        long hash = 0, p = 31, mod = (int) (1e9 + 7);
        long p_power = 1;

        for (int i = 0; i < s.length(); i++) {
            hash += (long) (s.charAt(i) - 'a' + 1) * p_power;
            p_power *= p;

            hash %= mod;
            p_power %= mod;
        }

        return hash;
    }

    public static void main(String[] args) {

        String s = "abaasdasdasfasasfaba";

        System.out.println(poly_hash(s));



    }
}
