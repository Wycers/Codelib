import java.lang.Math;
import java.util.Scanner;

public class exercise3 {

    private static void print(String str) {
        System.out.print(str);
    }

    public static void main(String[] arg) {
        FAN fan1 = new FAN();
        fan1.status(true);
        fan1.speed(FAN.FAST);
        fan1.color("yellow");
        fan1.radius(10.0);

        FAN fan2 = new FAN();

        fan2.status(false);
        fan2.radius(5.0);

        print(fan1.ToString());
        print("\n");
        print(fan2.ToString());
    }
}