package observer2;

import java.awt.*;

public class RedBall extends Ball {
    public RedBall(MainPanel panel, Color color, int xSpeed, int ySpeed, int ballSize) {
        super(panel, color, xSpeed, ySpeed, ballSize);
    }

    @Override
    public void update(char keyChar) {
        if (keyChar == 'a' || keyChar == 'd') {
            int temp = getXSpeed();
            setXSpeed(getYSpeed());
            setYSpeed(temp);
        }
    }
}
