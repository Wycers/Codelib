import java.lang.Math;
import java.util.Scanner;

public class exercise6 {
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex6(Scanner sc) {
        int N = 60; //max number of students
        int[] tag = new int[N];
        String[] name = new String[N];
        int[] score = new int[N];
        int n = sc.nextInt();
        for (int i = 0; i < n; ++i) {
            print(String.format("Enter the name and score of %d student:\n", i + 1));
            name[i] = sc.next();
            score[i] = sc.nextInt();
            tag[i] = i;
        }

        for (int i = 0; i < n - 1; ++i) 
            for (int j = i + 1; j < n; ++j)
                if (score[tag[i]] < score[tag[j]]) {
                    tag[i] = tag[i] ^ tag[j];
                    tag[j] = tag[i] ^ tag[j];
                    tag[i] = tag[i] ^ tag[j]; 
                }
        for (int i = 0; i < n; ++i)
            print(name[tag[i]] + "\n");
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex6(sc);
        sc.close();
    }
}

        
            