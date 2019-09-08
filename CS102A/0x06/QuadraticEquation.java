import java.lang.Math;
import java.util.Scanner;

public class QuadraticEquation {
    private static double a, b, c, eps = 1e-10;

    public static void setA(double A) {
        a = A;
    }

    public static void setB(double B) {
        b = B;
    }

    public static void setC(double C) {
        c = C;
    }

    public static double getDiscriminant() {
        return Math.pow(b, 2) - 4.0 * a * c;
    }

    public static int countRoots() {
        double delta = getDiscriminant();
        if (delta > eps)
            return 2;
        if (delta < -eps)
            return 0;
        return 1;
    }

    public static double getRoot1() {
        double delta = getDiscriminant();
        if (countRoots() == 0)
            return 0;
        double tmp = Math.sqrt(delta);
        double r1 = (-1 * b + tmp) / (2 * a);
        return r1;
    }

    public static double getRoot2() {
        double delta = getDiscriminant();
        if (countRoots() == 0)
            return 0;
        double tmp = Math.sqrt(delta);
        double r2 = (-1 * b - tmp) / (2 * a);
        return r2;
    }
}