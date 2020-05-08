public class HelloWorld{
	public static void main(String [] argc){
		int sum=0;
		int[] arr = new int[10];
		for(int i =0, j=0; i<100;i++){
			if(i%2 == 0){
				arr[j] = i;
				j++;
				System.out.println(arr[j-1]);
			}
			if(j==10){
				break;
			}
		}
		//System.out.println(sum);
	}
}
