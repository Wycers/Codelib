import java.lang.Math;
import java.util.Scanner;

public class exercise3 {
    
    
    private static void print(String str) {
        System.out.print(str);
    }

    private static int cube(int x){
        return x * x * x;
    }
    private static void ex3(Scanner sc) {
        int cnt = 0;
        for (int i = 1; i <= 9; ++i)
            for (int j = 0; j < 10; ++j)
                for (int k = 0; k < 10; ++k)
                    if (cube(i) + cube(j) + cube(k) == i * 100 + j * 10 + k) {
                        ++cnt;
                        print(String.format("%d ", i * 100 + j * 10 + k));
                    }
        print("\n");
        print(String.format("水仙花数一共有%d个", cnt));
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex3(sc);
        sc.close();
    }
}

        
            