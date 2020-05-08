package com.wordpress.danielgeorgiev01.h10.code;

import java.util.ArrayList;
import java.util.List;

public class BallContainer {
	ArrayList<Ball> listOfBalls = new ArrayList<Ball>();

	public void add(Ball ball){
		if (!listOfBalls.contains(ball)){
			listOfBalls.add(ball);
		}
	}

	public void remove(Ball ball){
		listOfBalls.remove(ball);
	}

	public void clear(){
		listOfBalls.clear();
	}

	public boolean contains(Ball ball){
		return listOfBalls.contains(ball);
	}
}
