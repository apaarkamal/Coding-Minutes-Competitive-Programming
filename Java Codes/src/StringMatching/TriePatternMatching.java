package StringMatching;

import java.util.Scanner;

public class TriePatternMatching {



    static class Node {
        Node[] nxt = new Node[26];
        boolean is_end;
        Node() {
            for (int i = 0; i < 26; i++)
                nxt[i] = null;
            is_end = false;
        }
    }

    static Node root;

    static void insert_trie(String s) {
        Node cur = root;
        for (int i = 0; i < s.length(); i++) {
            int imap = s.charAt(i) - 'a';
            // new node
            if (cur.nxt[imap] == null) {
                cur.nxt[imap] = new Node();
            }
            // goto that node
            cur = cur.nxt[imap];
        }
        // cur -> last node
        cur.is_end = true;
    }

    // O(|s|)
    static boolean search_trie(String s) {
        Node cur = root;
        for (int i = 0; i < s.length(); i++) {
            int imap = s.charAt(i) - 'a';
            if (cur.nxt[imap] == null)
                return false;
            cur = cur.nxt[imap];
        }
        return cur.is_end;
    }

    public static void main(String[] args) {

        root = new Node();

        String text = "ababba";
        String pat = "aba";

        int n = text.length();

        for (int i = 0; i < n; i++) {
            insert_trie(text.substring(i));
        }

        if (search_trie(pat)) {
            System.out.println("Found");
        }
        else {
            System.out.println("Not Found");
        }









    }
}
