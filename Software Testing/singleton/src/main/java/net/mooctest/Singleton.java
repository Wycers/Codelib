package net.mooctest;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Singleton {
	private Integer instanceCount = 0;

	private Singleton(int i) {
		instanceCount++;
		if (i == 0) {
			System.out.println("default construction");
		} else {
			System.out.println("alternative construction");
		}
	}

	public void testMe(int i) {
		if (i > 0) {
			System.out.println("positive");
			System.exit(0);
		} else {
			System.out.println("not positive");
			System.exit(1);
		}
	}

	public static Singleton getInstance() {
		return new Singleton(0);
	}

	public String getName() {
		return "Highlander";
	}

	public int getInstanceCount() {
		return instanceCount;
	}

	private void noCaller(String s) {
		Pattern regex = Pattern.compile("\\b[\\w.%-]+@[-.\\w]+\\.[A-Za-z]{2,4}\\b");
		Matcher matcher = regex.matcher(s);
		if (matcher.matches()) {
			System.out.println("match");
		} else {
			System.out.println("not match");
		}
	}

}
