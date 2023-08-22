// First Class
public class hello {
    private static void ex1() {
        System.out.print("HelloWorld");
        System.out.print('\n');
    }
    private static void ex2() {
        System.out.print("3 * 3 / 2 - 2.5 = ");
        System.out.print((double)3 * 3 / 2 - 2.5);
        System.out.print('\n');
    }
    private static void ex3() {
        System.out.printf("%.2f m^2\n", 4.5 * 7.9);
    }
    private static void ex4() {
        double sec = 1 * 3600 + 40 * 60 + 35;
        double tmp = (double)24 * 1.6 / (sec / 3600);
        System.out.printf("%.2f km/h\n", tmp);
    }
    public static void main(String[] avg) {
        ex1();
        ex2();
        ex3();
        ex4();
    }
}
