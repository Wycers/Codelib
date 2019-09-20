package lab12;

import java.util.Scanner;

public class Manager extends AbstractEmployee {
	double bonusRate;
	double salesDone;

	Manager() {
		super();
		Scanner sc = new Scanner(System.in);
		print("please input the sales that has been finished:");
		this.salesDone = sc.nextDouble();
		this.bonusRate = salesDone > 10000 ? 0.15 : 0.1;
	}

	public double calculatePay() {
		return numberOfHoursWorked * hourlyRate + basePay * (1 + bonusRate);
	}

	public boolean checkPromotionEligibility() {
		return this.calculatePay() > 50000 ? true : false;
	}

	/**
	 * @return the bonusRate
	 */
	public double getBonusRate() {
		return bonusRate;
	}

	/**
	 * @param bonusRate the bonusRate to set
	 */
	public void setBonusRate(double bonusRate) {
		this.bonusRate = bonusRate;
	}

	/**
	 * @return the salesDone
	 */
	public double getSalesDone() {
		return salesDone;
	}

	/**
	 * @param salesDone the salesDone to set
	 */
	public void setSalesDone(double salesDone) {
		this.salesDone = salesDone;
	}

	@Override
	public String toString() {
		return super.toString() + "\nPay: " + this.calculatePay() + "\nPromotion: " + this.checkPromotionEligibility();
	}

}
