package com.wordpress.danielgeorgiev01.h11.code;


public class Main {
	public static void main(String[] args) {

		Plane AirPlane = new Plane();

		int newPeople = 0;
		int peshoNumber=0;
		while(AirPlane.getCapacity() != 0){
			newPeople = (int)((Math.random()*10)%3)+1;
			Human[] people = new Human[newPeople];

			for (int i = 0; i < newPeople; i++) {
				people[i] = new Human();
				int gender = (int)((Math.random()*10)%1)+0;
				if(gender == 0){
					people[i].setGender("Male");
				}else{
					people[i].setGender("Female");
				}
				String name = "Chovek"+Integer.toString(peshoNumber);
				people[i].setName(name);
				peshoNumber++;
			}
			AirPlane.add(newPeople, people);
		};

		AirPlane.printSeats();

	}

}
