package net.mooctest;
public class Triangle {
	protected long lborderA = 0;

	protected long lborderB = 0;

	protected long lborderC = 0;

	// Constructor
	public Triangle(long lborderA, long lborderB, long lborderC) {

		this.lborderA = lborderA;

		this.lborderB = lborderB;

		this.lborderC = lborderC;

	}

	/**
	 * check if it is a triangle
	 * 
	 * @return true for triangle and false not
	 */
	public boolean isTriangle(Triangle triangle) {
		boolean isTriangle = false;

		// check boundary
		if ((triangle.lborderA > 0 && triangle.lborderA <= Long.MAX_VALUE)
				&& (triangle.lborderB > 0 && triangle.lborderB <= Long.MAX_VALUE)
				&& (triangle.lborderC > 0 && triangle.lborderC <= Long.MAX_VALUE)) {

			// check if subtraction of two border larger than the third
			if (diffOfBorders(triangle.lborderA, triangle.lborderB) < triangle.lborderC
					&& diffOfBorders(triangle.lborderB, triangle.lborderC) < triangle.lborderA
					&& diffOfBorders(triangle.lborderC, triangle.lborderA) < triangle.lborderB) {
				isTriangle = true;
			}

		}
		return isTriangle;
	}

	/**
	 * Check the type of triangle
	 * 
	 * Consists of "Illegal", "Regular", "Scalene", "Isosceles"
	 */
	public String getType(Triangle triangle) {
		String strType = "Illegal";

		if (isTriangle(triangle)) {
			// Is Regular
			if (triangle.lborderA == triangle.lborderB
					&& triangle.lborderB == triangle.lborderC) {
				strType = "Regular";
			}
			// If scalene
			else if ((triangle.lborderA != triangle.lborderB)
					&& (triangle.lborderB != triangle.lborderC)
					&& (triangle.lborderA != triangle.lborderC)) {
				strType = "Scalene";
			}
			// if isosceles
			else {
				strType = "Isosceles";
			}
		}

		return strType;
	}

	/**
	 * calculate the diff between borders
	 * 
	 * */
	public long diffOfBorders(long a, long b) {
		return (a > b) ? (a - b) : (b - a);
	}

	/**
	 * get length of borders
	 */
	public long[] getBorders() {
		long[] borders = new long[3];
		borders[0] = this.lborderA;
		borders[1] = this.lborderB;
		borders[2] = this.lborderC;
		return borders;
	}
}