package com.wordpress.danielgeorgiev01.h11.code;


public class Plane {
	private Human[][] seats = new Human[6][27];
	int c;
	public void add(int rvalue, Human[] h){
		int added=0;
		for(int i=0;i<27 && added==0;i++){
	            for(int j=0;j<6 && added==0;j++){
			if(seats[j][i]==null){
				if(rvalue==1){
					seats[j][i]=h[0];
					c+=1;
					added=1;
				}else if(rvalue==2){
					if(j<5){
						if(seats[j+1][i]==null){
							if(j!=2 && j!=5){
								seats[j][i]=h[0];
								seats[j+1][i]=h[1];
								added=1;
								c+=2;
							}
						}
					}
				}else if(rvalue==3){
					if(j<4){
						if(seats[j+1][i]==null && seats[j+2][i]==null){
							if(j==0 || j==3){
								seats[j][i]=h[0];
								seats[j+1][i]=h[1];
								seats[j+2][i]=h[2];
								c+=3;
								added=1;						
							}
						}
					}
				}
			}
	            }
	        }
	}
	
	public void remove(Human h) {
		boolean done=false;	

		for (int i=0; i<27; i++) {
			for(int j=0; j<6; j++) {
				if(seats[j][i].getName() == h.getName()){
					seats[j][i] = null;
					done = true;
				}
			}		
		}
		if(done == false){
			System.out.println("No human named "+ h.getName() + " was found on the plane!");
		}
	}
	
	public void clear() {
		for (int i=0; i<27; i++) {
			for(int j=0; j<6; j++) {
				seats[j][i] = null;					
				}
		}
	}
	
	public int getCapacity() {
		if(c < 162){
			return (162 - c);
		}else{
			System.out.println("The plane is full...");
			return 0;
		}
	}
	
	public int getMales() {
		int males = 0;
		for (int i=0; i<27; i++) {
			for(int j=0; j<6; j++) {
				if(seats[j][i].getGender() == "Male"){
					males++;					
				}
			}		
		}
		return males;
	}
	
	public int getFemales() {
		int females = 0;
		for (int i=0; i<27; i++) {
			for(int j=0; j<6; j++) {
				if(seats[j][i].getGender() == "Female"){
					females++;					
				}
			}		
		}
		return females;
	}
	public void printSeats(){
		for (int i=0; i<27; i++) {
			for(int j=0; j<6; j++) {
				System.out.print(" # " +seats[j][i].getName() + " # ");
				if(j == 2){
					System.out.print(" || ");
				}
			};
			System.out.println();
		}
	}
}
