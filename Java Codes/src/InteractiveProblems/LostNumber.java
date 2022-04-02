package InteractiveProblems;

import java.io.PrintWriter;
import java.util.Scanner;

public class LostNumber {

    static PrintWriter out = new PrintWriter(System.out);
    static Scanner scn = new Scanner(System.in);


    public static int[] swap(int data[], int left, int right)
    {

        // Swap the data
        int temp = data[left];
        data[left] = data[right];
        data[right] = temp;

        // Return the updated array
        return data;
    }

    // Function to reverse the sub-array
    // starting from left to the right
    // both inclusive
    public static int[] reverse(int data[], int left, int right)
    {

        // Reverse the sub-array
        while (left < right) {
            int temp = data[left];
            data[left++] = data[right];
            data[right--] = temp;
        }

        // Return the updated array
        return data;
    }

    // Function to find the next permutation
    // of the given integer array
    public static boolean findNextPermutation(int data[])
    {

        // If the given dataset is empty
        // or contains only one element
        // next_permutation is not possible
        if (data.length <= 1)
            return false;

        int last = data.length - 2;

        // find the longest non-increasing suffix
        // and find the pivot
        while (last >= 0) {
            if (data[last] < data[last + 1]) {
                break;
            }
            last--;
        }

        // If there is no increasing pair
        // there is no higher order permutation
        if (last < 0)
            return false;

        int nextGreater = data.length - 1;

        // Find the rightmost successor to the pivot
        for (int i = data.length - 1; i > last; i--) {
            if (data[i] > data[last]) {
                nextGreater = i;
                break;
            }
        }

        // Swap the successor and the pivot
        data = swap(data, nextGreater, last);

        // Reverse the suffix
        data = reverse(data, last + 1, data.length - 1);

        // Return true as the next_permutation is done
        return true;
    }


    static int query(int x, int y) {
        out.println("? " + x + " " + y);
        out.flush();
        return scn.nextInt();
    }

    public static void main(String[] args) {

        int a = query(1, 2);
        int b = query(2, 3);
        int c = query(3, 4);
        int d = query(4, 5);


        int[] v = {4 , 8, 15, 16, 23, 42};

        do {
            if (v[0]*v[1] == a && v[1]*v[2] == b && v[2]*v[3] == c && v[3]*v[4] == d) {
                out.print("! ");
                for (int x : v) out.print(x + " ");
                out.println();

            }
        } while (findNextPermutation(v));


    }
}
