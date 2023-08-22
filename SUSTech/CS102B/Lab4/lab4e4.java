/**
 * lab4e2
 */
import java.util.InputMismatchException;
import java.util.Scanner;
public class lab4e4 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int row = 0;
        while (row < 8)
        {
            if (row % 2 == 1)
                System.out.print(" ");
            int col = 0;
            while (col < 8)
            {
                System.out.print("* ");
                ++col;
            }
            System.out.println();
            ++row;
        }
        sc.close();
    }
    
}