package LinearRecurrenceAndMatrixExponentiation;

public class BinaryExp {

    static int powr(int a, int b) {
        int res = 1;
        while (b > 0) {
            if ((b & 1) == 1) res *= a;
            a *= a;
            b /= 2;
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println(powr(2, 10));
    }
}
