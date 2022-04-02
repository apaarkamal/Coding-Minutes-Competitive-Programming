package LinearRecurrenceAndMatrixExponentiation;

public class FastMultiplication {

    static int multiply(int a, int b, int c) {
        int res = 0;
        while (b > 0) {
            if ((b & 1) == 1) {
                res = res + a;
                res %= c;
            }
            a += a; a %= c;
            b /= 2;
        }
        return res;
    }

    public static void main(String[] args) {

        System.out.println(multiply(20, 20, 1000000007));

    }
}
