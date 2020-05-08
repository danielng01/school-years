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
        for(int i=0;i<rvalue;i++)
        {
            seats[i][0]=1;
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
        //za dom pravilno impletirane na add s zaedni mesta za priqteli za ponedelni 8 chasa i na ruby
    }
}
