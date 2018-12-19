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
	public static int testStringAndDow(int y, int m, int d, int score) {
		dateUtil.setYear(y);
		dateUtil.setMonth(m);
		dateUtil.setDay(d);

		SimpleDateFormat testString = new SimpleDateFormat("dd MMM yyyy", Locale.US);
		SimpleDateFormat testDow = new SimpleDateFormat("EEEE", Locale.US);
		Date string, dow;
		try {
			string = testString.parse(dateUtil.toString());
		} catch (ParseException e) {
			System.out.printf("Valid output not found while testing weekofday. (%d)\n", -3 * score);
			return 3 * score;
		}

		try {
			dow = testDow.parse(dateUtil.getDayOfWeek());
		} catch(ParseException e) {
			System.out.printf("Valid output not found while testing weekofday. (%d)\n", -2 * score);
			return 2 * score;
		}

		Calendar std = Calendar.getInstance(Locale.US); std.setTime(string);
		if (std.get(Calendar.YEAR) != y || std.get(Calendar.MONTH) + 1 != m || std.get(Calendar.DAY_OF_MONTH) != d) {
			System.out.printf("Cannot set while testing weekofday. (%d)\n", -3 * score);
			return 3 * score;
		}
		Calendar res = Calendar.getInstance(Locale.US); res.setTime(dow);
		if (std.get(Calendar.DAY_OF_WEEK) != res.get(Calendar.DAY_OF_WEEK)) {
			System.out.printf("Wrong answer while testing weekofday. (%d)\n", -1 * score);
			return 1 * score;
		}
		return 0;
	}
	public static void main(String[] args) {

		int score = 100;
		// test getter and setter 
		if (testYear() == false) {
			System.out.println("test year failed. (-10)");
			score -= 10;
		}
		if (testMonth() == false) {
			System.out.println("test year failed. (-10)");
			score -= 10;
		}
		if (testDay() == false) {
			System.out.println("test year failed. (-10)");
			score -= 10;
		}
		score -= testStringAndDow(5000, 9, 11, 5);
		score -= testStringAndDow(2018, 12, 14, 5);
		score -= testStringAndDow(1999, 4, 30, 5);
		score -= testStringAndDow(1799, 3, 4, 5);
		System.out.println(score);
	}

}
