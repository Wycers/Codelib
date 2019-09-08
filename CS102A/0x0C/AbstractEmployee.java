package lab12;

import java.util.Scanner;

public abstract class AbstractEmployee implements IEmployee {
	double basePay;
	String employeeName;
	double hourlyRate;
	double numberOfHoursWorked;

	public void print(String str) {
		System.out.println(str);
	}

	AbstractEmployee() {
		Scanner sc = new Scanner(System.in);
		print("Please input the name： ");
		this.employeeName = sc.next();
		print("Please input the base Pay: ");
		this.basePay = sc.nextDouble();
		print("Please input the number of hours worked: ");
		this.numberOfHoursWorked = sc.nextDouble();

		print("Please input the hourly rate: ");
		this.hourlyRate = sc.nextDouble();
	}

	/**
	 * @return the basePay
	 */
	public double getBasePay() {
		return basePay;
	}

	/**
	 * @param basePay the basePay to set
	 */
	public void setBasePay(double basePay) {
		this.basePay = basePay;
	}

	/**
	 * @return the hourlyRate
	 */
	public double getHourlyRate() {
		return hourlyRate;
	}

	/**
	 * @param hourlyRate the hourlyRate to set
	 */
	public void setHourlyRate(double hourlyRate) {
		this.hourlyRate = hourlyRate;
	}

	/**
	 * @return the employeeName
	 */
	public String getEmployeeName() {
		return employeeName;
	}

	/**
	 * @param employeeName the employeeName to set
	 */
	public void setEmployeeName(String employeeName) {
		this.employeeName = employeeName;
	}

	/**
	 * @return the numberOfHoursWorked
	 */
	public double getNumberOfHoursWorked() {
		return numberOfHoursWorked;
	}

	/**
	 * @param numberOfHoursWorked the numberOfHoursWorked to set
	 */
	public void setNumberOfHoursWorked(double numberOfHoursWorked) {
		this.numberOfHoursWorked = numberOfHoursWorked;
	}

	@Override
	public String toString() {
		return "Employee Name: " + this.employeeName + "\nBase Pay: " + this.basePay + "\nNumeber of Hours worked: "
				+ this.numberOfHoursWorked + "\nPayment Rate per Hour: " + this.hourlyRate;
	}
}
