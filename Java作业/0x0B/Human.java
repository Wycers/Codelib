package lab11;

import java.util.Scanner;

public class Human {
    private String firstName, lastName, birthday, occupation;
    private int height;

    private void print(String str) {
        System.out.println(str);
    }

    Human() {
        Scanner sc = new Scanner(System.in);

        print("Please input the first name:");
        this.setFirstName(sc.next());

        print("Please input the last name:");
        this.setLastName(sc.next());

        print("Please input height:");
        this.setHeight(sc.nextInt());

        print("Enter date of birth in DD/MM/Year:");
        this.setBirthday(sc.next());

        this.setOccupation("no-work-yet");
    }

    public String getFirstName() {
        return this.firstName;
    }

    public String getLastName() {
        return this.lastName;
    }

    public String getBirthday() {
        return this.birthday;
    }

    public String getOccupation() {
        return this.occupation;
    }

    public int getHeight() {
        return this.height;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void setBirthday(String birthday) {
        this.birthday = birthday;
    }

    public void setOccupation(String occupation) {
        this.occupation = occupation;
    }

    public void setHeight(int height) {
        this.height = height;
    }

    public String toString() {
        return String.format("%s %s is %d born on %s", this.getLastName(), this.getFirstName(), this.getHeight(),
                this.getBirthday());
    }

}