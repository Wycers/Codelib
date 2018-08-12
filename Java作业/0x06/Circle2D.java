import java.lang.Math;
import java.util.Scanner;

public class Circle2D {
    public double x, y, r;
    public Circle2D() {
        this.x = 0;
        this.y = 0;
        this.r = 1;
    }

    public Circle2D(double x, double y, double r) {
        this.x = x;
        this.y = y;
        this.r = r;
    }

    public double getPrimeter() {
        return Math.PI * 2 * this.r;
    }

    public double getArea() {
        return Math.PI * Math.pow(this.r, 2);
    }

    private double sqr(double a) {
        return a * a;
    }

    private double dis(double x1, double y1, double x2, double y2) {
        return Math.pow(sqr(x1 - x2) + sqr(y1 - y2), 0.5);
    }

    public Boolean contains(double x, double y) {
        return dis(this.x, this.y, x, y) - this.r < 1e-10;
    }

    public Boolean contains(Circle2D A) {
        return dis(A.x, A.y, this.x, this.y) + A.r - this.r < 1e-10;
    }

    public Boolean overlaps(Circle2D A) {
        if (this.contains(A))
            return false;
        return dis(A.x, A.y, this.x, this.y) < A.r + this.r;
    }
}
