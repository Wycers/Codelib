
/**
 * lab4e1
 */
import java.util.InputMismatchException;
import java.util.Scanner;
public class lab4e1 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int amount = 5;
        int passed = 0;
        int failed = 0;
        while (amount > 0) {
            System.out.println("Please input the score of the student:");
            int score = 0;
            try {
                score = sc.nextInt();
            } catch (InputMismatchException e) {
                System.out.println("Please input an integer!");
                sc.next();
            }
            if (score < 0 || score > 100) {
                System.out.println("Please input an valid integer!");
                continue;
            }
            --amount;
            if (score < 60) 
                ++failed;
            else
                ++passed;
        }
        System.out.printf("%d students passed the exam!\n", passed);
        System.out.printf("%d students failed the exam!", failed);
        sc.close();
    }
}
