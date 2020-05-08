import java.util.Arrays;
import java.util.Collections;

public class Homework1{
	public static void main (String[] args){
		String[] arr = new String[args.length];
		int count = 0;
		int sortOrder = 0;
		for(int i=0;i<args.length;i++){
			if(System.getProperty(args[i])==null){
				arr[i]="error";
				continue;
			}else{
				arr[i]=System.getProperty(args[i]);
			}
		}
		if(args.length!=0){
			if(args[(args.length)-1].equals("down")){
				sortOrder = 1;
			}
		}
		if(sortOrder==1){
			Arrays.sort(arr, Collections.reverseOrder());
		}else{
			Arrays.sort(arr);
		}
		for(int i=0;i<args.length;i++){
			if(arr[i].equals("error")){
				continue;
			}else{
				System.out.println(arr[i]);
			}
		}
	}
}
