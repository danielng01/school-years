import java.util.Random;

public class Airplane{
    private int[][] seats = new int[6][27];
    public void printSeats(){
        for(int i=0;i<27;i++){
            for(int j=0;j<6;j++){
                if(j==3)
                    System.out.print("|__|");
                System.out.print(" "+seats[j][i]);
            }
            System.out.println();
        }
    }
    public void add(int rvalue){
	int added=0;
	for(int i=0;i<27 && added==0;i++){
            for(int j=0;j<6 && added==0;j++){
		if(seats[j][i]==0){
			if(rvalue==1){
				seats[j][i]=1;
				added=1;
			}else if(rvalue==2){
				if(j<5){
					if(seats[j+1][i]==0){
						if(j!=2 && j!=5){
							seats[j][i]=1;
							seats[j+1][i]=1;
							added=1;
						}
					}
				}
			}else if(rvalue==3){
				if(j<4){
					if(seats[j+1][i]==0 && seats[j+2][i]==0){
						if(j==0 || j==3){
							seats[j][i]=1;
							seats[j+1][i]=1;
							seats[j+2][i]=1;
							added=1;						
						}
					}
				}
			}
		}
            }
        }
    }
    public int freeSeats(){
        return 0;    
    }
    public static void main(String args[]){
        //ptint array
        Airplane plane = new Airplane();
        plane.printSeats();
        plane.add(2);
        System.out.println("###################");
        plane.printSeats();
        plane.add(3);
        System.out.println("###################");
        plane.printSeats();
        plane.add(1);
        System.out.println("###################");
        plane.printSeats();
    }
}
