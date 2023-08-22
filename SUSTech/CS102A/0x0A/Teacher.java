package manage;

import java.util.ArrayList;

public class Teacher {
	public void print(String s) {
		System.out.println(s);
	}
	private String name;
	private ArrayList<Student> students = new ArrayList<>();
	Teacher(String s){
		setName(s);
	}
	public void addStudent(String name) {
		Student s = new Student(name);
		this.students.add(s);
	}
	public void printAllStudents() {
		for(Student s:this.students) {
			print("[name=" + s.getName() + ",score=" + s.getScore() + ",teacher=" + getName() + "]");
		}
	}
	public String getName() {
		return this.name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public ArrayList<Student> getStudents() {
		return this.students;
	}
	public void setStudents(ArrayList<Student> students) {
		this.students = students;
	}
}
