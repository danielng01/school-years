package com.wordpress.danielgeorgiev01.h10.code;

public class Main {

	public static void main(String[] args) {
		Ball b1 = new Ball(1);
		Box box = new Box(7);
		System.out.println(box.size()); // prints 7
		System.out.println(box.getCapacity()); // prints 7
		box.add(b1); 
		System.out.println(box.size()); // prints 7
		System.out.println(box.getCapacity()); // prints 6
		System.out.println(box.contains(b1)); // prints true
		Ball b2 = new Ball(2);
		box.add(b2);
		box.add(b2); // do nothing
		System.out.println(box.getCapacity()); // prints 5
		System.out.println(box.contains(b2)); // prints true
		box.remove(b1);
		System.out.println(box.getCapacity()); // prints 6
		System.out.println(box.contains(b1)); // prints false
	}

}
