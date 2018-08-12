import java.lang.Math;
import java.util.Scanner;

public class exercise1 {
    
    private static void print(String str) {
        System.out.print(str);
    }

    public static void main(String[] arg) {
        QuadraticEquation cal = new QuadraticEquation();
        Scanner sc = new Scanner(System.in);
        
        cal.setA(sc.nextDouble());
        cal.setB(sc.nextDouble());
        cal.setC(sc.nextDouble());
        sc.close();
            
        if (cal.countRoots() == 2) 
            print(String.format("The roots are %.5f and %.5f\n", cal.getRoot1(), cal.getRoot2()));
        else if (cal.countRoots() == 1)
            print(String.format("The root is %.5f\n", cal.getRoot1()));
        else
            print("The equation has no real roots.");
    }
}