package InteractiveProblems;

import java.io.PrintWriter;
import java.util.Scanner;

public class XorGuessing {

    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) {


        int ans = 0;

        out.print("? ");
        for (int i = 1; i <= 100; i++) {
            out.print(i + " ");

        }
        out.println();
        out.flush();
        Scanner scn = new Scanner(System.in);

        int x = scn.nextInt();

        for (int i = 7; i <= 13; i++) {
            if (((x >> i) & 1) == 1) {
                ans |= (1 << i);
            }
        }


        out.print("? ");
        for (int i = 1; i <= 100; i++) {
            out.print((i << 7)+ " ");

        }
        out.println();
        out.flush();

        x = scn.nextInt();

        for (int i = 0; i <= 6; i++) {
            if (((x >> i) & 1) == 1) {
                ans |= (1 << i);
            }
        }

        out.println("! " + ans);
        out.flush();
    }
}


