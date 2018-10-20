import java.util.Scanner;

public class A2Q2 {
    public static void main(String[] args) {
        java.util.Random random = new java.util.Random();
        Scanner sc = new Scanner(System.in);
        int magicNum = random.nextInt(10);

        System.out.println("Please input an integer in {0, 1, 2, ..., 9}");
        int now = -1;
        while (now != magicNum) {
            try {
                now = sc.nextInt();
                if (now > magicNum)
                    System.out.println("Please input an integer smaller than " + now);
                else if (now < magicNum)
                    System.out.println("Please input an integer larger than " + now);
            } catch (Exception e) {
                sc.next();
                System.out.println("Please input an integer");
            }
        }
        System.out.println("Congratulations");
        sc.close();
    }
}