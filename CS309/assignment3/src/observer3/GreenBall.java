package observer3;


import java.awt.*;
import java.util.ArrayList;
import java.util.List;

public class GreenBall extends Ball {
    private List<Ball> observers = new ArrayList<Ball>();
    public void registerObserver(Ball ball) {
        observers.add(ball);
    }

    @Override
    public void move() {
        super.move();
        notifyObservers();
    }

    public void notifyObservers() {
        for (Ball observer : observers) {
            observer.update(this);
        }
    }

    public GreenBall(MainPanel panel, Color color, int xSpeed, int ySpeed, int ballSize) {
        super(panel, color, xSpeed, ySpeed, ballSize);
    }

    @Override
    public void update(char keyChar) {
        switch (keyChar) {
            case 'a':
                setXSpeed(Math.abs(getXSpeed()) * -1);
                break;
            case 'd':
                setXSpeed(Math.abs(getXSpeed()));
                break;
            case 'w':
                setYSpeed(Math.abs(getYSpeed()) * -1);
                break;
            case 's':
                setYSpeed(Math.abs(getYSpeed()));
                break;
        }
    }

    @Override
    public void update(GreenBall ball) {

    }
}