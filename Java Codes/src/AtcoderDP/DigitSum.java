package AtcoderDP;

import java.util.Scanner;

public class DigitSum {




    final static int N = 10000;

    static String k;
    static int d, apaar = (int)(1e9 + 7);
    static int[][][] memo = new int[N][2][100];

    static int dp(int i, int last, int mod) {
        if (i == k.length()) {
            return 1;
        }

        int ans = memo[i][last][mod];
        if (ans != -1) return ans;

        ans = 0;

        int till = last == 1 ? (k.charAt(i) - '0') : 9;

        for (int digits = 0; digits <= till; digits++) {
            ans += dp(i + 1, last == 1 && (digits == till) ? 1 : 0, (mod + digits) % d);
            ans %= apaar;
        }

        return ans;
    }

    public static void main(String[] args) {


        Scanner scn = new Scanner(System.in);
        k = scn.next(); d = scn.nextInt();


        for(int i = 0 ; i < N;i++){
            for(int j = 0; j < 2; j++){
                for(int k = 0; k <100; k++){
                    memo[i][j][k] = -1;
                }
            }
        }


        System.out.println((dp(0, 1, 0) - 1 + apaar) % apaar);

    }
}
