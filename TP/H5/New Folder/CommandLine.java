import java.util.Collections;
import java.util.Arrays;
public class CommandLine{
	public static void main(String[] args){ 
		String[] arr = new String[args.length];
		for(int i = 0; i < args.length; i++) {
                	arr[i] = new String();
             	}
		System.out.println(arr[0]);
		int count=0;
		String Order="up";
		for (int i = 0; i< args.length; i++){
			//if(args[i]=="down" || args[i]=="up"){
			//	Order = args[i];
			//	continue;
			//}
			String property = System.getProperty(args[i]);
			if(property==null){
				arr[count]="error";
			}
			else{
				arr[count]=property;
				count += 1;
			}
		}
		//arr[i]="dasdasd";
		for (int i =0; i<count;i++){
			System.out.println(arr[i]);
		
		}
		Arrays.sort(arr);
		//if(arr[0]==""){
		//	System.out.println("dsadsada");
		//}
		for (int i =0; i<count;i++){
			System.out.println(arr[i]);
		
		}
	}

}
