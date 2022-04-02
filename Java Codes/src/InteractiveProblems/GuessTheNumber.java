package InteractiveProblems;

import java.io.PrintWriter;
import java.util.Scanner;

public class GuessTheNumber {

    // 0 -> '<'
    // 1 -> '>='

    static PrintWriter out = new PrintWriter(System.out);
    static Scanner scn = new Scanner(System.in);


    static boolean query(int middle) {
        // query
        out.println(middle);
        out.flush();

        String in = scn.next();
        return (in.equals(">="));
    }

    public static void main(String[] args) {


        int left = 1, right = 1000000, ans = 0;

        while (left <= right) {
            int middle = (left + right) / 2;
            if (query(middle)) {
                ans = middle;
                left = middle + 1;
            }
            else {
                right = middle - 1;
            }
        }

        out.println("! " + ans);

    }
}
