import java.util.Scanner;

public class TestContainerAndBall {
	public static void main(String[] args) {
		Container box = new Container(0, 0, 100, 100);
		System.out.println(box);
		Scanner scanner = new Scanner(System.in);
		System.out.println("Please input the speed of the ball");
		int speed = scanner.nextInt();
		int direction;
		System.out.println("Please input the direction of the ball");
		while ((direction = scanner.nextInt()) <= -180 && direction > 180) {
			System.out.println("Invalide direction. Please input the direction of the ball");
		}
		Ball ball = new Ball(50, 50, 5, speed, direction);
		System.out.println(ball);
		System.out.println("The ball is moving now.");
		while (true) {
			ball.move();
			if (box.collidesWith(ball)) {
				System.out.println(ball);
				System.out.print("The Ball will be collided with the container. ");
				System.out.println();
				break;
			} else {
				System.out.println(ball);
			}
		}
		scanner.close();
	}
}
