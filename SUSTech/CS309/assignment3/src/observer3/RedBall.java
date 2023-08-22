package observer3;

import java.awt.*;

public class RedBall extends Ball {
    public RedBall(MainPanel panel, int xSpeed, int ySpeed, int ballSize) {
        super(panel, Color.RED, xSpeed, ySpeed, ballSize);
    }

    @Override
    public void update(char keyChar) {
        if (keyChar == 'a' || keyChar == 'd') {
            int temp = getXSpeed();
            setXSpeed(getYSpeed());
            setYSpeed(temp);
        }
    }

    public void update(GreenBall ball) {
        escapeIsShamefulButUseful(ball, 100, 50);
    }
}
