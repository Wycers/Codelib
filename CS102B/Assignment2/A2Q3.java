import java.util.Scanner;

public class A2Q3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Please tell me whether you live in an apartment, house or dormitory?");
        try {
            int n = sc.nextInt();
            if (n < 1 || n > 3) 
                throw new Exception();
            System.out.printf("You live in %s\n", n == 1 ? "an apartment": n == 2? "a house": "a dormitory");

            System.out.println("Please tell me the number of hours you're home during the average day?");
            int m = sc.nextInt();
            if (m < 0 || m > 24) 
                throw new Exception();
            System.out.printf("We recommend you raise a/an %s\n", 
                n == 1 ? 
                    (m >= 10 ? "cat" : "hamster"): 
                n == 3 ? 
                    (m >= 6 ? "fish": "ant farm"): 
                m >= 18 ? "pot-bellied pig": 
                m < 10 ? "snake": "dog"
            );
        } catch (Exception e) {
            System.out.println("invalid input!");
        }
    }
}