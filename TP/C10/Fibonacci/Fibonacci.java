import java.math.BigInteger;
class Fibonacci{
	public static void main(String[] args){
		System.out.println("fibonacci program");
		BigInteger asd = new BigInteger("9");//change
		BigInteger deset=new BigInteger("10");
		BigInteger a=new BigInteger("0");
		BigInteger b=new BigInteger("0");
		BigInteger sum=new BigInteger("1");
		int count=0;
		for(int i=0;i<1000000000;i+=1){
			a=b;
			b=sum;
			sum=a.add(b);
			if((sum.mod(deset)).equals(asd))
				count++;
			if(count==9){
				System.out.println(sum);
				break;
			}
			//System.out.println((sum.mod(deset)).equals(asd));
		}
		
	}
}
//9227465.0
//433494437
//308061521170129

