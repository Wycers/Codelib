package lab11;

import java.util.*;
import lab11.Square;

public class exercise2 {
    ArrayList<Object> arrayList = new ArrayList<Object>();
    private static void print(String str) {
        System.out.println(str);
    }
    public static void main(String args[]) {
        int n, m;
        Scanner sc = new Scanner(System.in);
        
        print("Please input how many polygons we prepare to create:");
        n = sc.nextInt();
        print("Please input how many polygons we must be created:");
        m = sc.nextInt();
        
        
        Object[] array = new Object[n];
        for (int i = 0; i < n; ++i) {
            print("Please input polygon type: 1 or 2:");
            int temp = sc.nextInt();
            if (temp == 1)
                array[i] = new Square();
            else if (temp == 2)
                array[i] = new Triangle();
            else   
                array[i] = new Polygon();
        }
        
        if (m > n) {
            ArrayList<Object> arraylist = new ArrayList<Object>(Arrays.asList(array));
            print("List has been created");
            for (int i = 0; i < m - n; ++i) {
                print("Please input polygon type: 1 or 2:");
                int temp = sc.nextInt();
                Object woHenPi;
                if (temp == 1)
                    woHenPi = new Square();
                else if (temp == 2)
                    woHenPi = new Triangle();
                else   
                    woHenPi = new Polygon();
                arraylist.add(woHenPi);
            }
            for (Object p : arraylist) 
                print(p.toString());
        }
        else for (int i = 0; i < n; ++i)
                print(array[i].toString());
    }
}