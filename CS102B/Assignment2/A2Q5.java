public class A2Q5 {

    public static void main(String[] args) {
        int N = 1000;
        int n = N, head = 0, tail = 0;
        while (n != 0) {
            --n;
            double result = Math.random();
            if (result > 0.5) 
                ++tail;
            else 
                ++head;
        }
        System.out.printf("The percentage of heads is %f, and the percentage of tails is %f", (double)head / N, (double)tail / N);
    }
}