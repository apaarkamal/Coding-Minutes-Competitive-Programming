package AtcoderDP;

import java.util.Scanner;

public class Stones {

    public static void main(String[] args) {


        Scanner scn = new Scanner(System.in);
        int n = scn.nextInt();
        int k = scn.nextInt();

        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scn.nextInt();
        }

        int[] dp = new int[k + 1];
        dp[0] = 0;

        for (int i = 1; i <= k; i++) {
            dp[i] = 0;
            for (int j = 0; j < n; j++) {
                if (i - a[j] >= 0 && dp[i - a[j]] == 0) {
                    dp[i] = 1;
                    break;
                }
            }
        }


        String ans = (dp[k] != 0 ? "First" : "Second");

        System.out.println(ans);



    }}
