import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TestPointAndLine {

	public static int testPoint(String point, int x, int y) {
		
		String pattern = "(?i).*Point\\s*\\[x=(-?\\d+)\\s*,\\s*y=(-?\\d+)\\]";
 
		// 创建 Pattern 对象
		Pattern r = Pattern.compile(pattern);
	
		// 创建 matcher 对象
		Matcher m = r.matcher(point);
		if (m.find()) {
			if (m.groupCount() != 2)
				return 3;
			if (Integer.parseInt(m.group(1)) != x)
				return 2;
			if (Integer.parseInt(m.group(2)) != y)
				return 2;
		} else {
			return 3;
		}
		return 0;
	}

	public static int testLine(String line, int sx, int sy, int tx, int ty) {
		
		String pattern = "(?i).*The\\s*line\\s*begins\\s*at\\s*Point\\s*\\[x\\s*=\\s*(-?\\d+)\\s*,\\s*y\\s*=\\s*(-?\\d+)\\]\\s*,\\s*terminates\\s*at\\s*Point\\s*\\[x\\s*=\\s*(-?\\d+)\\s*,\\s*y\\s*=\\s*(-?\\d+)\\]\\s*,\\s*and\\s*the\\s*length\\s*is\\s*((-?\\d+)(\\.\\d+)?)";
 
		// 创建 Pattern 对象
		Pattern r = Pattern.compile(pattern);
	
		// 创建 matcher 对象
		Matcher m = r.matcher(line);
		if (m.find()) {
			if (m.groupCount() < 7)
				return 3;
			if (Integer.parseInt(m.group(1)) != sx)
				return 2;
			if (Integer.parseInt(m.group(2)) != sy)
				return 2;
			if (Integer.parseInt(m.group(3)) != tx)
				return 2;
			if (Integer.parseInt(m.group(4)) != ty)
				return 2;
			double res;
			try {
				res = Double.parseDouble(m.group(5));
			} catch (Exception e) {
				return 2;
			}
			double std = Math.sqrt(Math.pow(sx - tx, 2) + Math.pow(sy - ty, 2));
			if (Math.abs(res - std) > 1e-2)
				return 2;
		} else {
			return 3;
		}
		return 0;
	}
	public static void main(String[] args) {
		int score = 100;
		Point point1 = new Point(2, 1);
		score -= 5 * testPoint(point1.toString(), 2, 1);

		Point point2 = new Point(5, 5);
		score -= 5 * testPoint(point2.toString(), 5, 5);

		Point point3 = new Point(new Point(3, 4));
		score -= 5 * testPoint(point3.toString(), 3, 4);

		Line l1 = new Line(0, 0, 3, 4);
		score -= 5 * testLine(l1.toString(), 0, 0, 3, 4);

		Line l2 = new Line(point2, point3);
		score -= 5 * testLine(l2.toString(), 5, 5, 3, 4);
		
		Line l3 = new Line(-3, -4, 0, 0);
		score -= 5 * testLine(l3.toString(), -3, -4, 0, 0);
		System.out.println(score);
	}
}
