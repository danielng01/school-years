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
        //generating number
        Random randomGenerator = new Random(); 
        int i = 0,j=0;      
        for (; i<162;j++)
        {
            int rvalue = randomGenerator.nextInt(3)+1;
            plane.add(rvalue);
            if(i+rvalue>162)
                continue;
            i+=rvalue;
            
        }

        System.out.println(i);
        System.out.println(j);
    }
}
