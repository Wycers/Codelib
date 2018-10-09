/**
 * lab4e2
 */
import java.util.InputMismatchException;
import java.util.Scanner;
public class lab4e3 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        System.out.println("Please input the score:");
        int score = 0;
        try {
            score = sc.nextInt();
        } catch (InputMismatchException e) {
            System.out.println("Please input an integer!");
            sc.close();
            return;
        }
        if (score < 0 || score > 100) {
            System.out.println("Please input an valid integer!");
            sc.close();
            return;
        }
        System.out.printf("The student got %c", score >= 90 ? 'A' : score >= 60 ? 'B' : 'C');
        sc.close();
    }
    
}