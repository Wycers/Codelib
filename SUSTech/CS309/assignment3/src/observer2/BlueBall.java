package observer2;


import java.awt.*;

public class BlueBall extends Ball {
    public BlueBall(MainPanel panel, int xSpeed, int ySpeed, int ballSize) {
        super(panel, Color.blue, xSpeed, ySpeed, ballSize);
    }

    @Override
    public void update(char keyChar) {
        setXSpeed(-1 * getXSpeed());
        setYSpeed(-1 * getYSpeed());
    }
}
