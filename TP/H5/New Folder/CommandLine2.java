import java.util.Collections;
import java.util.Arrays;

public class CommandLine2{
	public static void main (String[] args){
		String[] tempStr = new String[args.length];
		int tempCount = 0;
		boolean sortOrder = true;
		for(int i=0;i<args.length;i++){
			if(System.getProperty(args[i])!=null){
				tempStr[tempCount]=System.getProperty(args[i]);
				tempCount += 1;
			}
		}
		for(int i=0;i<tempCount;i++){
			System.out.println(tempStr[i]);
		}
	}
}
