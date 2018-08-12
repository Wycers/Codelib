import java.util.Date;
import java.util.GregorianCalendar;
import java.util.Calendar;

public class Mydate {
    private int year, month, day;
    Calendar c = new GregorianCalendar();

    private void refresh() {
        this.year = this.c.get(GregorianCalendar.YEAR);
        this.month = this.c.get(GregorianCalendar.MONTH);
        this.day = this.c.get(GregorianCalendar.DAY_OF_MONTH);
    }

    public void setDate(long a) {
        this.c.setTimeInMillis(a);
        this.refresh();
    }

    public Mydate() {
        this.refresh();
    }

    public Mydate(long a) {
        this.setDate(a);
    }

    public int getYear() {
        return this.year;
    }

    public int getMonth() {
        return this.month;
    }

    public int getDay() {
        return this.day;
    }

}