package manage;

public class Student {
	private String name;
	private int score;
	private String studentNumber;
	private int count = 0;
	Student(String s){
		this.setName(s);
		this.setStudentNumber("stu" + count);
		this.setScore((int)(Math.random()*100) +1);
		this.count++;
	}
	Student(){
		this.setName("UnKnown");
		this.setStudentNumber("stu"+count);
		this.setScore((int)(Math.random()*100) +1);
		this.count++;
	}
	public String toString() {
		return this.studentNumber + "[name=" + this.getName() + ",score=" + this.getScore()+"]";
	}
	public String getStudentNumber() {
		return this.studentNumber;
	}
	public void setStudentNumber(String studentNumber) {
		this.studentNumber = studentNumber;
	}
	public int getScore() {
		return this.score;
	}
	public void setScore(int score) {
		this.score = score;
	}
	public String getName() {
		return this.name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public int getCount() {
		return count;
	}
}
