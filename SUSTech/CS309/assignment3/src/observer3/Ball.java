package observer3;

import java.awt.*;

public abstract class Ball {
    private MainPanel panel;
    private Color color;
    private int x, y;
    private int xSpeed, ySpeed;
    private int ballSize;
    private boolean visible;

    public Ball(MainPanel panel, Color color, int xSpeed, int ySpeed, int ballSize) {
        this.panel = panel;
        this.panel.registerObserver(this);

        this.color = color;
        this.xSpeed = xSpeed;
        this.ySpeed = ySpeed;
        this.ballSize = ballSize;

        this.visible = true;
        this.x = (int) (Math.random() * 600);
        this.y = (int) (Math.random() * 600);
    }

    public void setColor(Color newColor) {
        this.color = newColor;
    }

    public Color getColor() {
        return this.color;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public int getYSpeed() {
        return ySpeed;
    }

    public void setYSpeed(int ySpeed) {
        this.ySpeed = ySpeed;
    }

    public int getXSpeed() {
        return xSpeed;
    }

    public void setXSpeed(int xSpeed) {
        this.xSpeed = xSpeed;
    }

    public int getBallSize() {
        return ballSize;
    }

    public boolean isVisible() {
        return visible;
    }

    public void setVisible(boolean visible) {
        this.visible = visible;
    }

    public void draw(Graphics g) {
        Thread.currentThread();
        if (isVisible()) {
            g.setColor(this.getColor());
            g.fillOval(this.getX(), this.getY(), this.getBallSize(), this.getBallSize());
        }
    }

    public void move() {
        int newX = this.getX() + this.getXSpeed();
        int newY = this.getY() + this.getYSpeed();

        this.setX(newX);
        this.setY(newY);

        if (newX <= 0) {
            this.setXSpeed(Math.abs(getXSpeed()));
        } else if (newX >= 600 - this.getBallSize()) {
            this.setXSpeed(-1 * Math.abs(getXSpeed()));
        }

        if (newY <= 0) {
            this.setYSpeed(Math.abs(getYSpeed()));
        } else if (newY > 600 - this.getBallSize()) {
            this.setYSpeed(-1 * Math.abs(getYSpeed()));
        }
    }

    public boolean isIntersect(Ball b) {
        int diffX = this.getX() - b.getX();
        int diffY = this.getY() - b.getY();
        double dis = (this.getBallSize() + b.getBallSize()) / 2.0;

        return (diffX * diffX) + (diffY * diffY) < dis * dis;
    }

    public static int getSign(double x) {
        if (x < -1e-8)
            return -1;
        if (x > 1e-8)
            return 1;
        return 0;
    }

    public void escapeIsShamefulButUseful(GreenBall ball, double range, int step) {
        System.out.println(ball.getX() + " " + ball.getY());
        double dx = getX() + 0.5 * getBallSize() - ball.getX() - 0.5 * ball.getBallSize();
        double dy = getY() + 0.5 * getBallSize() - ball.getY() - 0.5 * ball.getBallSize();
        double distance = Math.sqrt(dx * dx + dy * dy);
        if (distance < range) {
            int sx = getSign(dx), sy = getSign(dy);
            int tx = getX() + sy * step, ty = getY() + sx * step;
            System.out.println(sx + " " + sy);
            tx = Math.max(tx, 0);
            tx = Math.min(tx, 600 - this.getBallSize());
            ty = Math.max(ty, 0);
            ty = Math.max(ty, 600 - this.getBallSize());
            setX(tx);
            setY(ty);
        }

    }
    public abstract void update(char keyChar);
    public abstract void update(GreenBall ball);
}

