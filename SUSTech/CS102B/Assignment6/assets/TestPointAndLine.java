import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TestPointAndLine {

	public static int testPoint(String point, int x, int y, int score) {
		
		String pattern = "(?i).*Point\\s*\\[x=(-?\\d+)\\s*,\\s*y=(-?\\d+)\\]";
 
		// 创建 Pattern 对象
		Pattern r = Pattern.compile(pattern);
	
		// 创建 matcher 对象
		Matcher m = r.matcher(point);
		if (m.find()) {
			if (m.groupCount() != 2) {
				System.out.printf("Invalid output while test point. (%d)\n", -3 * score);
				return 3 * score;
			}
			if (Integer.parseInt(m.group(1)) != x) {
				System.out.printf("Wrong output while test point. (%d)\n", -2 * score);
				return 2 * score;
			}
			if (Integer.parseInt(m.group(2)) != y) {
				System.out.printf("Wrong output while test point. (%d)\n", -2 * score);
				return 2 * score;
			}
		} else {
			System.out.printf("Invalid output while test point. (%d)\n", -3 * score);
			return 3 * score;
		}
		return 0 * score;
	}

	public static int testLine(String line, int sx, int sy, int tx, int ty, int score) {
		
		String pattern = "(?i).*The\\s*line\\s*begins\\s*at\\s*Point\\s*\\[x\\s*=\\s*(-?\\d+)\\s*,\\s*y\\s*=\\s*(-?\\d+)\\]\\s*,\\s*terminates\\s*at\\s*Point\\s*\\[x\\s*=\\s*(-?\\d+)\\s*,\\s*y\\s*=\\s*(-?\\d+)\\]\\s*,\\s*and\\s*the\\s*length\\s*is\\s*((-?\\d+)(\\.\\d+)?)";
 
		// 创建 Pattern 对象
		Pattern r = Pattern.compile(pattern);
	
		// 创建 matcher 对象
		Matcher m = r.matcher(line);
		if (m.find()) {
			if (m.groupCount() < 7) {
				System.out.printf("Invalid output while testing line. (%d)\n", -3 * score);
				return 3 * score;
			}
			if (Integer.parseInt(m.group(1)) != sx) {
				System.out.printf("Wrong output while testing line. (%d)\n", -2 * score);
				return 2 * score;
			}
			if (Integer.parseInt(m.group(2)) != sy) {
				System.out.printf("Wrong output while testing line. (%d)\n", -2 * score);
				return 2 * score;
			} 
			if (Integer.parseInt(m.group(3)) != tx) {
				System.out.printf("Wrong output while testing line. (%d)\n", -2 * score);
				return 2 * score;
			}
			if (Integer.parseInt(m.group(4)) != ty) {
				System.out.printf("Wrong output while testing line. (%d)\n", -2 * score);
				return 2 * score;
			}
			double res;
			try {
				res = Double.parseDouble(m.group(5));
			} catch (Exception e) {
				System.out.printf("Wrong output while testing line. (%d)\n", -2 * score);
				return 2 * score;
			}
			double std = Math.sqrt(Math.pow(sx - tx, 2) + Math.pow(sy - ty, 2));
			if (Math.abs(res - std) > 1e-2) {
				System.out.printf("Wrong output while testing line. (%d)\n", -2 * score);
				return 2 * score;
			}
		} else {
			System.out.printf("Invalid output while testing line. (%d)\n", -3 * score);
			System.out.printf("Got %s\n", line);
			return 3 * score;
		}
		return 0 * score;
	}
	public static void main(String[] args) {
		int score = 100;
		Point point1 = new Point(2, 1);
		score -= testPoint(point1.toString(), 2, 1, 5);

		Point point2 = new Point(5, 5);
		score -= testPoint(point2.toString(), 5, 5, 5);

		Point point3 = new Point(new Point(3, 4));
		score -= testPoint(point3.toString(), 3, 4, 5);

		Line l1 = new Line(0, 0, 3, 4);
		score -= testLine(l1.toString(), 0, 0, 3, 4, 5);

		Line l2 = new Line(point2, point3);
		score -= testLine(l2.toString(), 5, 5, 3, 4, 5);
		
		Line l3 = new Line(-3, -4, 0, 0);
		score -= testLine(l3.toString(), -3, -4, 0, 0, 5);
		System.out.println(score);
	}
}
