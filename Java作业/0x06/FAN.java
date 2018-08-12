import java.lang.Math;
import java.util.Scanner;

public class FAN {
    static final int SLOW = 1, MEDIUM = 2, FAST = 3;
    private int speed = SLOW;
    private Boolean on = false;
    private double radius = 5.0;
    public String color = "blue";

    public int speed(int... args) {
        if (args.length > 0) {
            int tmp = args[args.length - 1];
            if (1 <= tmp && tmp <= 3)
                this.speed = tmp;
        }
        return this.speed;
    }

    public Boolean status(Boolean... args) {
        if (args.length > 0)
            this.on = args[args.length - 1] == true;
        return this.on;
    }

    public double radius(double... args) {
        if (args.length > 0)
            this.radius = args[args.length - 1];
        return this.radius;
    }

    public String color(String... args) {
        if (args.length > 0)
            this.color = args[args.length - 1];
        return this.color;
    }

    public String ToString() {
        String dSpeed = this.speed() == FAN.SLOW ? "SLOW" : this.speed() == FAN.MEDIUM ? "MEDIUM" : "FAST";
        String dColor = this.color();
        String dRadius = String.format("%.1f", this.radius());
        if (this.status())
            return String.format("Fan speed: %s, color: %s, radius: %s", dSpeed, dColor, dRadius);
        else
            return String.format("Fan color: %s, radius: %s. Fan is off.", dColor, dRadius);
    }
}