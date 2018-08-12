import java.lang.Math;
import java.util.Scanner;

public class exercise7 {
    private static void print(String str) {
        System.out.print(str);
    }
    private static void ex7(Scanner sc, int n) {
        Boolean[][] flag = new Boolean[6][6];
        int[][] a = new int[6][6];
        print(String.format("Enter a %d*%d matrix:", n, n));
        for (int i = 0; i < 6; ++i)
            for (int j = 0; j < 6; ++j)
                flag[i][j] = false;

        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j){
                a[i][j] = sc.nextInt();
                flag[i][j] = true;  
            }
        
        int[][] p = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        Boolean qwq = true;
        for (int x = 1, y = 0, d = 0; qwq == true; d = (d + 1) % 4) {
            for (int dx = x + p[d][0], dy = y + p[d][1]; flag[dx][dy] == true; dx = x + p[d][0], dy = y + p[d][1]) {
                x = dx;
                y = dy;
                print(String.format("%d ", a[x][y]));
                flag[x][y] = false;
            }
            qwq = false;
            for (int t = 0; t < 4; ++t) 
                if (flag[x + p[t][0]][y + p[t][1]] == true)
                    qwq = true;
        }
        print("\n");
    }

    public static void main(String[] arg) {
        Scanner sc = new Scanner(System.in);
        ex7(sc, 3);
        ex7(sc, 4);
        sc.close();
    }
}

        
            