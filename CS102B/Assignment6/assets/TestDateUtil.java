import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.text.ParseException;
import java.util.Calendar;
public class TestDateUtil {

	public static DateUtil dateUtil = new DateUtil();

	public static boolean testYear() {
		if (dateUtil.setYear(1699) == true)
			return false;
		if (dateUtil.setYear(1700) == false)
			return false;
		if (dateUtil.setYear(9999) == false)
			return false;
		if (dateUtil.setYear(10000) == true)
			return false;
		if (dateUtil.setYear(2012) == false)
			return false;
		return true;
	}
	public static boolean testMonth() {
		if (dateUtil.setMonth(0) == true)
			return false;
		if (dateUtil.setMonth(1) == false)
			return false;
		if (dateUtil.setMonth(12) == false)
			return false;
		if (dateUtil.setMonth(13) == true)
			return false;
		if (dateUtil.setMonth(6) == false)
			return false;
		return true;
	}
	public static boolean testDay() {
		if (dateUtil.setDay(0) == true)
			return false;
		if (dateUtil.setDay(1) == false)
			return false;
		if (dateUtil.setDay(28) == false)
			return false;
		if (dateUtil.setDay(32) == true)
			return false;

		if (dateUtil.setYear(2018) && dateUtil.setMonth(2))
		{
			if (dateUtil.setDay(28) == false)
				return false;
			if (dateUtil.setDay(29) == true)
				return false;
		}
		else
			return false;

		if (dateUtil.setYear(1900) && dateUtil.setMonth(2))
		{
			if (dateUtil.setDay(29) == true)
				return false;
			if (dateUtil.setDay(30) == true)
				return false;
		}
		else
			return false;

		if (dateUtil.setYear(2000) && dateUtil.setMonth(2))
		{
			if (dateUtil.setDay(28) == false)
				return false;
			if (dateUtil.setDay(29) == false)
				return false;
			if (dateUtil.setDay(30) == true)
				return false;
		}
		else
			return false;

		return true;
	}
	public static int testStringAndDow(int y, int m, int d) {
		dateUtil.setYear(y);
		dateUtil.setMonth(m);
		dateUtil.setDay(d);

		SimpleDateFormat testString = new SimpleDateFormat("dd MMM yyyy", Locale.US);
		SimpleDateFormat testDow = new SimpleDateFormat("EEEE", Locale.US);
		Date string, dow;
		try {
			string = testString.parse(dateUtil.toString());
		} catch (ParseException e) {
			return 3;
		}

		try {
			dow = testDow.parse(dateUtil.getDayOfWeek());
		} catch(ParseException e) {
			return 2;
		}

		Calendar std = Calendar.getInstance(Locale.US); std.setTime(string);
		if (std.get(Calendar.YEAR) != y || std.get(Calendar.MONTH) + 1 != m || std.get(Calendar.DAY_OF_MONTH) != d)
			return 3;
		Calendar res = Calendar.getInstance(Locale.US); res.setTime(dow);
		if (std.get(Calendar.DAY_OF_WEEK) != res.get(Calendar.DAY_OF_WEEK))
			return 1;
		return 0;
	}
	public static void main(String[] args) {

		int score = 100;
		// test getter and setter 
		if (testYear() == false) {
			score -= 10;
		}
		if (testMonth() == false) {
			score -= 10;
		}
		if (testDay() == false) {
			score -= 10;
		}
		score -= 5 * testStringAndDow(5000, 9, 11);
		score -= 5 * testStringAndDow(2018, 12, 14);
		score -= 5 * testStringAndDow(1999, 4, 30);
		score -= 5 * testStringAndDow(1799, 3, 4);
		System.out.println(score);
	}

}
