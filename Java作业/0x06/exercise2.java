import java.lang.Math;
import java.util.Scanner;
import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Calendar;

public class exercise2 {
    private static void print(String str) {
        System.out.print(str);
    }

    public static void main(String[] arg) {
        Calendar c = new GregorianCalendar();
        int y = c.get(GregorianCalendar.YEAR);
        int m = c.get(GregorianCalendar.MONTH);
        int d = c.get(GregorianCalendar.DAY_OF_MONTH);
        print(String.format("The current year, month, day in format Mth/Day/Year: %d/%d/%d.\n", m, d, y));

        c.setTimeInMillis(1234567898765L);
        y = c.get(GregorianCalendar.YEAR);
        m = c.get(GregorianCalendar.MONTH);
        d = c.get(GregorianCalendar.DAY_OF_MONTH);
        print(String.format(
                "Elapsed time since January 1, 1970 set to 1234567898765L in format Mth/Day/Year: %d/%d/%d.", m, d, y));
    }
}