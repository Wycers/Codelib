import java.util.Scanner;
import java.util.Timer;
import java.util.TimerTask;
public class GuessingGame {
	public void print(String s) {
		System.out.println(s);
	}
	private int magicNumber;
	private enum Status{CONTINUE, WON, LOST, STOP};
	private Status gameStatus = Status.CONTINUE;
	private String timeup = "----------------Time is up---------------";
	private String finishgame = "---------------Game is Finish---------------";
	public void guess() {
		magicNumber = (int)Math.ceil((100 * Math.random()));
		Scanner in = new Scanner(System.in);
		int uplimit = 100;
		int lowlimit = 0;
		while(gameStatus == Status.CONTINUE){
			System.out.printf("----You turn:(%d to %d)----\n",lowlimit,uplimit);
			int myGuess = in.nextInt();
			if(myGuess == magicNumber) { 
				gameStatus = Status.WON;
				break;
				}
			else if(myGuess < magicNumber) {
				print("your number is too small");
				lowlimit = myGuess + 1;
				}
			else if(myGuess > magicNumber) {
				print("your number is too large");
				uplimit = myGuess - 1;
			}
			int cGuess = lowlimit + (int)((uplimit - lowlimit)*Math.random());
			if(cGuess == magicNumber) 
				gameStatus = Status.LOST;
			else if (cGuess > magicNumber) {
				System.out.printf("*****The computer guess %d (%d to %d),the number is too large*****\n",cGuess,lowlimit,uplimit);
				uplimit = cGuess - 1;
			}
			else if (cGuess < magicNumber) {
				System.out.printf("*****The computer guess %d (%d to %d),the number is too small*****\n",cGuess,lowlimit,uplimit);
				lowlimit = cGuess + 1;
			}
		}
		
		switch(gameStatus) {
			case LOST : 
				print(finishgame);
				print("you lose the game");
				System.exit(0);
				break;
			case WON : 
				print(finishgame);
				print("you win the game");
				System.exit(0);
				break;
			default:
				break;
		}
	}
	public void timeControl() {
		Timer timer = new Timer();
		timer.schedule(new TimerTask() {
			@Override
			public void run() {
				if (gameStatus.equals(Status.CONTINUE)) {
					gameStatus = Status.STOP;
					print(timeup);
					print("no winner");
					System.exit(0);
				}
			}
		}, 15000);
	}
}
