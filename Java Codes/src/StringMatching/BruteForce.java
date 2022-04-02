package StringMatching;

public class BruteForce {

    public static void main(String[] args) {
        String text = "ababaababbbbabaaa";
        String pat = "aa";

        int m = pat.length(), n = text.length();

        for (int i = 0; i + m <= n; i++) {
            if (text.substring(i, i+m).equals(pat)) {
                System.out.println(i);
            }
        }

    }
}
