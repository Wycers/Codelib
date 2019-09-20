package course10;
import java.util.Calendar; 
import java.util.*;
public class myTime {
	private int hour;
	private int minute;
	private int second;
	Calendar c = Calendar.getInstance();
	myTime(){
		hour = c.get(Calendar.HOUR_OF_DAY); 
		minute = c.get(Calendar.MINUTE); 
		second = c.get(Calendar.SECOND); 
	}
	myTime(int hour,int minute,int second){
		if(0 <= hour && hour <= 23) this.hour = hour;
		else this.hour = 0;
		if(0 <= minute && minute <= 59) this.minute = minute;
		else this.minute = 0;
		if(0 <= second && second <= 59) this.second = second;
		else this.second = 0;
	}
	public int getHour() {
		return this.hour;
	}
	public int getMinute() {
		return this.minute;
	}
	public int getSecond() {
		return this.second;
	}
	public String toString() {
		return String.format("%02d:%02d:%02d",hour,minute,second);
	}
	public myTime timeDifference() {
		int diffsec = c.get(Calendar.SECOND) - second;
		int diffmin = c.get(Calendar.MINUTE) - minute;
		int diffhour = c.get(Calendar.HOUR_OF_DAY) - hour;
		if(diffsec < 0) {
			diffsec += 60;
			diffmin--;
		}
		if(diffmin < 0) {
			diffmin += 60;
			diffhour--;
		}
		if(diffhour < 0) 
			diffhour += 24;
		return new myTime(diffhour,diffmin,diffsec);
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		myTime time1 = new myTime(input.nextInt(),input.nextInt(),input.nextInt());
		myTime time2 = new myTime();
		System.out.println("current time "+time2);
		System.out.println("input time "+time1);
		System.out.println("difference "+time1.timeDifference());
	}
}
