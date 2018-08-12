package lab11;

import java.util.Scanner;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Saler extends Human {
    private String company, dateOfHire;
    private int salary;

    private void print(String str) {
        System.out.println(str);
    }

    Saler() {
        super();
        Scanner sc = new Scanner(System.in);
        print("Please input the company:");
        this.setCompany(sc.next());

        print("Enter salary:");
        this.setSalary(sc.nextInt());

        this.setOccupation("Saler");

        Date dater = new Date();
        SimpleDateFormat formater = new SimpleDateFormat("yyyy-MM-dd");
        this.setDateOfHire(formater.format(dater.getTime()));

    }

    /**
     * @param company the company to set
     */
    public void setCompany(String company) {
        this.company = company;
    }

    public void setSalary(int salary) {
        this.salary = salary;
    }

    public void setDateOfHire(String dateOfHire) {
        this.dateOfHire = dateOfHire;
    }

    public String getDateOfHire() {
        return this.dateOfHire;
    }

    public int getSalary() {
        return this.salary;
    }

    public String getCompany() {
        return this.company;
    }

    @Override
    public String toString() {
        return String.format("%s %s is %d born on %s work as %s in %s salary as %d hired on %s", this.getLastName(),
                this.getFirstName(), this.getHeight(), this.getBirthday(), this.getOccupation(), this.getCompany(),
                this.getSalary(), this.getDateOfHire());
    }
}
