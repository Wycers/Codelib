package observer2;


import java.awt.*;

public class GreenBall extends Ball {
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
}