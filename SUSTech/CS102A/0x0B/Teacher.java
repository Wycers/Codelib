package lab11;

import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Teacher extends Human {
    private String university, major;
    private int salary;

    private void print(String str) {
        System.out.print(str);
    }

    Teacher() {
        super();
        Scanner sc = new Scanner(System.in);

        print("Enter university:");
        this.setUniversity(sc.next());

        print("Enter major:");
        this.setMajor(sc.next());

        print("Enter salary:");
        this.setSalary(sc.nextInt());

        this.setOccupation("Professor");
    }

    /**
     * @param major the major to set
     */
    public void setMajor(String major) {
        this.major = major;
    }

    /**
     * @param university the university to set
     */
    public void setUniversity(String university) {
        this.university = university;
    }

    /**
     * @param salary the salary to set
     */
    public void setSalary(int salary) {
        this.salary = salary;
    }

    /**
     * @return the university
     */
    public String getUniversity() {
        return university;
    }

    /**
     * @return the salary
     */
    public int getSalary() {
        return salary;
    }

    /**
     * @return the major
     */
    public String getMajor() {
        return major;
    }

    @Override
    public String toString() {
        return String.format("%s %s is %d born on %s work as %s in %s university major in %s salary as %d", this.getLastName(),
                this.getFirstName(), this.getHeight(), this.getBirthday(), this.getOccupation(), this.getUniversity(),
                this.getMajor(), this.getSalary());
    }
}
