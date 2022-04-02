package InclusionExclusion;

import java.util.Scanner;

public class TotalDivisorInclusion {


    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();

        int[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int m = primes.length;

        int ans = 0;

        for (int i = 1; i < (1 << m); i++) {

            int lcm = 1;
            for (int j = 0; j < m; j++) {
                // if jth bit of ith element is set then include it
                if (((i >> j) & 1) == 1) {
                    // cout << primes[j] << " ";
                    lcm *= primes[j];
                }
            }
            // cout << '\n';

            if (Integer.bitCount(i) % 2 == 0) {
                ans -= (n / lcm);
            }
            else {
                ans += (n / lcm);
            }
        }


        System.out.println(ans);


    }
}
