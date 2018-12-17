import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class TestContainerAndBall {
	

	public static int checkBoxOutput(String box, int sx, int sy, int tx, int ty) {
		tx = sx + tx - 1;
		ty = sy + ty - 1;

		String pattern = "(?i).*Container\\s*at\\s*\\(\\s*(\\d+(\\.\\d+)?)\\s*,\\s*(\\d+(\\.\\d+)?)\\s*\\)\\s*to\\s*\\(\\s*(\\d+(\\.\\d+)?)\\s*,\\s*(\\d+(\\.\\d+)?)\\s*\\)\\s*";
		Pattern r = Pattern.compile(pattern);

		Matcher m = r.matcher(box);
		if (m.find()) {
			try {
				if (Integer.parseInt(m.group(1)) != sx)
					return 1;
				if (Integer.parseInt(m.group(3)) != sy)
					return 1;
				if (Integer.parseInt(m.group(5)) != tx)
					return 1;
				if (Integer.parseInt(m.group(7)) != ty)
					return 1;
			} catch (Exception e) {
				return 1;
			}
			return 0;
		}
		return 1;
	}
	public static int checkBox() {
		int res = 0;
		Container box1 = new Container(0, 0, 100, 100);
		res += checkBoxOutput(box1.toString(), 0, 0, 100, 100);

		Container box2 = new Container(1, 2, 3, 4);
		res += checkBoxOutput(box2.toString(), 1, 2, 3, 4);

		return res;
	}
	public static int checkBallOutput(String ball, double x, double y, double spead, double direction) {
		String pattern = "(?i).*Ball\\s*at\\s*\\(\\s*((-?\\d+)(\\.\\d+)?)\\s*,\\s*((-?\\d+)(\\.\\d+)?)\\s*\\)\\s*of\\s*velocity\\s*\\(\\s*((-?\\d+)(\\.\\d+)?)\\s*,\\s*((-?\\d+)(\\.\\d+)?)\\s*\\)\\s*";
		Pattern r = Pattern.compile(pattern);

		double vx =  spead * Math.cos(direction / 180.0 * Math.PI);
		double vy = -spead * Math.sin(direction / 180.0 * Math.PI);

		Matcher m = r.matcher(ball);
		if (m.find()) {
			double eps = 1e-2;
			try {
				if (Math.abs(Double.parseDouble(m.group(1)) - x) > eps)
					return 1;
				if (Math.abs(Double.parseDouble(m.group(4)) - y) > eps)
					return 1;
				if (Math.abs(Double.parseDouble(m.group(7)) - vx) > eps)
					return 1;
				if (Math.abs(Double.parseDouble(m.group(10)) - vy) > eps)
					return 1;
			} catch (Exception e) {
				return 1;
			}
			return 0;
		}
		return 1;
	}
	public static int checkBall() {
		int res = 0;
		Ball ball1 = new Ball(50, 50, 5, 70, 45);
		res += checkBallOutput(ball1.toString(), 50, 50, 70, 45);

		Ball ball2 = new Ball(10, 15, 5, 5, -60);
		res += checkBallOutput(ball2.toString(), 10, 15, 5, -60);
		
		return res;
	}

	public static int checkMove(int sx, int sy, int tx, int ty, int r, int x, int y, int spead, int direction) {
		int res = 0;
		Container box = new Container(sx, sy, tx, ty);
		Ball ball = new Ball((float)x, (float)y, r, spead, direction);
		double vx =  spead * Math.cos(direction / 180.0 * Math.PI);
		double vy = -spead * Math.sin(direction / 180.0 * Math.PI);
		
		tx = sx + tx - 1;
		ty = sy + ty - 1;
		while (true) {
			ball.move();
			x += vx; 
			y += vy;
			boolean collided = false;
			collided |= x <= (sx + r);
			collided |= x >= (tx - r);
			collided |= y <= (sy + r);
			collided |= y >= (ty - r);
			if (box.collidesWith(ball) != collided) {
				return 3;
			}
			if (collided)
				return 0;
		}
	}
	public static void main(String[] args) {
		int score = 100;
		score -= 10 * checkBox();
		score -= 10 * checkBall();

		score -= 5 * checkMove(0, 0, 100, 100, 5, 50, 50, 70, 45);
		score -= 5 * checkMove(0, 0, 80, 80, 5, 0, 0, 10, 45);
		score -= 5 * checkMove(0, 0, 50, 50, 5, 25, 25, 5, 180);
		score -= 5 * checkMove(0, 0, 75, 10, 2, 34, 5, 20, 73);
		System.out.println(score);
	}
}
