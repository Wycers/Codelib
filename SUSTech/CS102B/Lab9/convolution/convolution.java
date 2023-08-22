import java.util.Scanner;
public class convolution {

    public static int[][] a, b, c;
    public static int k;
    public static int cal(int x, int y)
    {
        int res = 0;
        for (int i = -k; i <= k; ++i)
            for (int j = -k; j <= k; ++j)
                res += a[x + i][y + j] * b[k + i][k + j];
        return res;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        if (n < m) 
        {
            System.out.println("N must be greater than or equal to M!");
            return;
        }
        if ((m & 1) == 0)
        {
            System.out.println("Invalid m!");
            return;
        }
        k = (m - 1) >> 1;

        a = new int[n][n];
        b = new int[m][m];
        c = new int[n][n];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                a[i][j] = sc.nextInt();
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < m; ++j)
                b[i][j] = sc.nextInt();

        for (int i = k; i < n - k; ++i)
            for (int j = k; j < n - k; ++j)
                c[i][j] = cal(i, j);
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                System.out.printf("%d%c", c[i][j], j + 1 == n ? '\n' : '\t');
    }
}