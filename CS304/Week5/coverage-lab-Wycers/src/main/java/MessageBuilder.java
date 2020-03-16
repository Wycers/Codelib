public class MessageBuilder {
    private static String course = "cs";

    public String getMessage(String name) {
        StringBuilder result = new StringBuilder();

        if (name == null || name.trim().length() == 0) {
            result.append("Please provide a name!");
        } else if (name.length() <= 4) {
            result.append("Hello " + name);
        } else if (name.equals(course.toLowerCase())) {
            result.append("Hello World");
        } else {
            result.append("Too long: " + name);
        }
        if (!name.equals(name)) {
            result.append("Bye");
        }
        return result.toString();
    }
}
