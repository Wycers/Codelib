import java.lang.Math;
import java.util.Scanner;

public class exercise4 {
    private static void print(String str) {
        System.out.print(str);
    }

/** Return true if the sum of any two sides is
* greater than the third side. */
    public static boolean isValid(double a, double b, double c) {
        return a + b > c && a + c > b && b + c > a;
    }
    
    /** Return the area of the triangle. */
    public static double area(double a, double b, double c) {
        double p = (double)(a + b + c) / 2;
        double s = Math.pow(p * (p - a) * (p - b) * (p - c), 0.5);
        return s;
    }
    

    private static void ex4(Scanner sc) {
        print("Enter three sides for a triangle:");
        double a = sc.nextDouble(), b = sc.nextDouble(), c = sc.nextDouble();
        
        if (isValid(a, b, c) == false) 
            print("Input is invalid");
        else
            print(String.format("The area of the triangle is %.3f",area(a, b, c)));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex4(sc);
        sc.close();
    }
}