import java.lang.Math;
import java.util.Scanner;

public class exercise4 {
    
    private static void print(String str) {
        System.out.print(str);
    }

    public static void main(String[] arg) {
        Circle2D c1 = new Circle2D(2, 2, 5.5);
        print(String.format("Circle1 area: %.3f\n", c1.getArea()));
        print(String.format("Circle1 area: %.3f\n", c1.getPrimeter()));

        print("Does circle1 contains the point (3, 3)? ");
        print(c1.contains(3, 3) ? "true" : "false");
        print("\n");

        Circle2D c2 = new Circle2D(4, 5, 10.5);
        print("Does circle1 contains the circle centered at (4, 5) and radius 10.5? ");
        print(c1.contains(c2) ? "true" : "false");
        print("\n");

        print("Does circle1 overlaps the circle centered at (3, 5) and radius 2.3? ");
        print(c1.overlaps(new Circle2D(3, 5, 2.3)) ? "true" : "false");
    }
}