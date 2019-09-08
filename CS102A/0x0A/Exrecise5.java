package manage;

import java.util.ArrayList;
import java.util.Scanner;
import manage.Student;
import manage.Teacher;
public class Exrecise5 {
	public static void print(String s) {
		System.out.println(s);
	}
	private static ArrayList<Teacher> t = new ArrayList<>();
	public static Teacher getNewTeacher() {
		print("Please input teacher's name:");
		Scanner input = new Scanner(System.in);
		String s = input.next();
		Teacher t = new Teacher(s);
		return t;
	}
	public static int getMaxScore() {
		int max = 0;
		for (Teacher teacher:t) 
			for(Student s:teacher.getStudents()) 
				if(s.getScore() > max) 
					max = s.getScore();
		return max;
	}
	public static double getAverageOfScore() {
		double total = 0;
		int num = 0;
		for(Teacher teacher :t) {
			num += teacher.getStudents().size();
			for(Student s:teacher.getStudents()) 
				total += s.getScore();
		}
		return total / num;
	}
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		boolean isContinue = true;
		for (int count = 0; isContinue == true; ++count) {
			t.add(getNewTeacher());
			while (isContinue) {
				print("Please input student's name:");
				t.get(count).addStudent(input.next());
				System.out.println(count);
				print("Continue to add student?Y or N:");
				isContinue = input.next().equals("Y");
			}
			print("Continue to add teacher?Y or N:");
			isContinue = input.next().equals("Y");
		}
		for(Teacher teacher :t) {
			print(String.format("Students of teacher %s\n", teacher.getName()));
			teacher.printAllStudents();
		}
		print("The average score for all students is " + getAverageOfScore());
		print("The largest score for all students is " + getMaxScore());
	}
}
