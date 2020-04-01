package metrics;

public class Example1 {
    public static void main(String[] args) {
        int a = 0;
        if (a >= 0) {
            System.out.println(">= 0");
            if (a != 0) {
                System.out.println("!= 0");
            }
        } else {
            System.out.println("< 0");
        }
    }
}