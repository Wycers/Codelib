package lab11;

import java.util.Scanner;
import lab11.Polygon;

public class Triangle extends Polygon {
    private int side1, side2, side3;

    /**
     * @param side1 the side1 to set
     */
    public void setSide1(int side1) {
        this.side1 = side1 > 0 ? side1 : 1;
    }

    /**
     * @param side2 the side2 to set
     */
    public void setSide2(int side2) {
        this.side2 = side2 > 0 ? side2 : 1;
    }

    /**
     * @param side3 the side3 to set
     */
    public void setSide3(int side3) {
        this.side3 = side3 > 0 ? side3 : 1;
    }

    private void print(String str) {
        System.out.println(str);
    }

    public void judge() {
        if (side1 + side2 <= side3)
            side1 = side2 = side3 = 1;
        if (side3 + side2 <= side1)
            side1 = side2 = side3 = 1;
        if (side1 + side3 <= side2)
            side1 = side2 = side3 = 1;

    }

    Triangle() {
        super();
        Scanner sc = new Scanner(System.in);
        print("Enter side1:");
        setSide1(sc.nextInt());
        print("Enter side2:");
        setSide2(sc.nextInt());
        print("Enter side3:");
        setSide3(sc.nextInt());

        judge();
    }

    /**
     * @return the side1
     */
    public int getSide1() {
        return side1;
    }
    /**
     * @return the side2
     */
    public int getSide2() {
        return side2;
    }
    /**
     * @return the side3
     */
    public int getSide3() {
        return side3;
    }

    @Override
    public double getArea() {
        double a = side1, b = side2, c = side3;
        double s = (double)(a + b + c);
        return Math.sqrt(s * (s - a) * (s - b) * (s - c)); 
    }
    
    @Override
    public String toString() {
        return String.format("Triangle: %s the area is %.1f", super.toString(), getArea());
    }
}