import java.lang.Math;
import java.util.Scanner;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Calendar;

public class exercise5 {
    private static void print(String str) {
        System.out.print(str);
    }

    public static void main(String[] arg) {
        Mydate c1 = new Mydate();
        print(String.format("Data1: %d/%d/%d.", c1.getMonth() + 1, c1.getDay(), c1.getYear()));

        print("\n");

        Mydate c2 = new Mydate(34355555133101L);
        print(String.format("Data2: %d/%d/%d.", c2.getMonth() + 1, c2.getDay(), c2.getYear()));        
    }
}