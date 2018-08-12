package lab11;

import java.util.Random;
import java.text.SimpleDateFormat;
import java.util.Date;

public class Polygon {
    public enum Color {
        Yellow("Yellow", 1), Red("Red", 2), White("White", 3), Black("Black", 4), Green("Green", 5);
        // 成员变量
        private String name;
        private int index;

        private Color(String name, int index) {
            this.name = name;
            this.index = index;
        }
        public static String getName(int index) {
            for (Color c : Color.values())
                if (c.getIndex() == index)
                    return c.name;
            return null;
        }
        public String getName() {
            return name;
        }

        public void setName(String name) {
            this.name = name;
        }

        public int getIndex() {
            return index;
        }

        public void setIndex(int index) {
            this.index = index;
        }
    }

    private Color color = Color.Yellow;
    private Boolean filled;
    private String date;

    Polygon() {
        Random rand = new Random();
        color.setName(color.getName(rand.nextInt(5)));
        Date dater = new Date();
        SimpleDateFormat formater = new SimpleDateFormat("yyyy-MM-dd");
        setDate(formater.format(dater.getTime()));
    }

    /**
     * @param date the date to set
     */
    public void setDate(String date) {
        this.date = date;
    }

    /**
     * @return the date
     */
    public String getDate() {
        return date;
    }

    /**
     * @param color the color to set
     */
    public void setColor(Color color) {
        this.color = color;
    }

    /**
     * @return the color
     */
    public Color getColor() {
        return color;
    }

    /**
     * @param filled the filled to set
     */
    public void setFilled(Boolean filled) {
        this.filled = filled;
    }

    /**
     * @return the filled
     */
    public Boolean getFilled() {
        return filled;
    }

    public double getArea() {
        return 0;
    }

    public String toString() {
        return String.format("The %s color polygon created in %s", getColor().getName(), getDate());
    }
}