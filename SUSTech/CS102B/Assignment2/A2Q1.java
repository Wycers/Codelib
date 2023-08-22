public class A2Q1 {

    public static void main(String[] args) {
        if (args.length == 0) {
            System.out.println("Missing argument n!");
            return;
        }
        try {
            int n = Integer.parseInt(args[0]);
            double pi = 0.0;
            while (n > 0) {
                double f = n % 2 == 1 ? 1: -1;
                pi = pi + f * (4.0 / (2.0 * n - 1.0));
                --n;
            }
            System.out.printf("The estimation of Pi is %f",pi);
        } catch (Exception e) {
            System.out.println("Argument n should be integer!");
        }
    }
}