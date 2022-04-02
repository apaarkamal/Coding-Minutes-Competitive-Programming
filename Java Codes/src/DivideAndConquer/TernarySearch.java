package DivideAndConquer;

public class TernarySearch {

    static double f(double x) {
        return - (x * x) + 3.45621278 * x;
    }

    public static void main(String[] args){

        double left = -100, right = 100;

        while (right - left > 0.00000000001) {

            double mid1 = (2 * left + right) / 3;
            double mid2 = (left + 2 * right) / 3;

            if (f(mid1) < f(mid2)) {
                left = mid1;
            }
            else {
                right = mid2;
            }

        }

        System.out.println(left + " " + right);

    }
}
