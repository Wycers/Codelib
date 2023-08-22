/**
 * A2Q4
 */
public class A2Q4 {

    public static void main(String[] args) {
        int N = 10;
        int n = N, head = 0, tail = 0;
        while (n != 0) {
            --n;
            double result = Math.random();
            if (result > 0.5) {
                System.out.println("Tails");
                ++tail;
            }
            else {
                System.out.println("Heads");
                ++head;
            }
        }
        System.out.printf("The percentage of heads is %f, and the percentage of tails is %f", (double)head / N, (double)tail / N);
    }
}