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
	public static void main(String[] args) {
		int score = 100;
		score -= 5 * checkBox();

		System.out.println(score);
		// System.out.println(box);
		// System.out.println("Please input the speed of the ball");
		// int speed = scanner.nextInt();
		// int direction;
		// System.out.println("Please input the direction of the ball");
		// while ((direction = scanner.nextInt()) <= -180 && direction > 180) {
		// 	System.out.println("Invalide direction. Please input the direction of the ball");
		// }
		// Ball ball = new Ball(50, 50, 5, speed, direction);
		// System.out.println(ball);
		// System.out.println("The ball is moving now.");
		// while (true) {
		// 	ball.move();
		// 	if (box.collidesWith(ball)) {
		// 		System.out.println(ball);
		// 		System.out.print("The Ball will be collided with the container. ");
		// 		System.out.println();
		// 		break;
		// 	} else {
		// 		System.out.println(ball);
		// 	}
		// }
	}
}
