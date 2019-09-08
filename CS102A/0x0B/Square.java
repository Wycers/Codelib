package lab11;

import java.util.Scanner;

import lab11.Polygon;

public class Square extends Polygon {
    private int length, height;

    /**
     * @param length the length to set
     */
    public void setLength(int length) {
        this.length = length > 0 ? length : 1;
    }

    /**
     * @param height the height to set
     */
    public void setHeight(int height) {
        this.height = height > 0 ? height : 1;
    }

    /**
     * @return the height
     */
    public int getHeight() {
        return height;
    }

    /**
     * @return the length
     */
    public int getLength() {
        return length;
    }

    private void print(String str) {
        System.out.println(str);
    }

    Square() {
        super();
        Scanner sc = new Scanner(System.in);

        print("Enter the length:");
        setLength(sc.nextInt());

        print("Enter the height:");
        setHeight(sc.nextInt());
    }

    @Override
    public double getArea() {
        return (double)height * length;
    }

    @Override
    public String toString() {
        return String.format("Square: %s the area is %.1f", super.toString(), getArea());
    }
}