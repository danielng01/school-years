package com.wordpress.danielgeorgiev01.h10.code;

public class Main {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Ball b1 = new Ball(1);
		Box box = new Box(7);
		box.add(b1); 
		Ball b2 = new Ball(2);
		box.add(b2);
		box.add(b2);
		box.remove(b1);

	}

}
