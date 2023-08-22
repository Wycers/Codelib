import java.lang.Math;
import java.util.Scanner;

public class exercise4 {
    
    
    private static void print(String str) {
        System.out.print(str);
    }

    private static void ex4(Scanner sc) {
        print("Enter wind speed:");
        double v = Math.abs(sc.nextDouble());
        String str;
        if (v <= 2)
            str = "calm";
        else if (v <= 70)
            str = "normal";
        else 
            str = "storm"; 
        int scale = (int)Math.round(Math.pow(v / 0.835, (double)2 / 3));
        print(String.format("the wind with speed %.2f is \"%s\", its scale is %d\n", v, str, scale));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex4(sc);
        sc.close();
    }
}

        
            