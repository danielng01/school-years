import java.io.*;
import javax.imageio.*;
import java.awt.image.BufferedImage;
import java.util.Arrays.*;
class ImageProcessing{
	public static void main(String[] args) throws Exception{
		System.out.println("image processing program");
		File f=new File(args[0]);
		BufferedImage imgb=ImageIO.read(f);
		int imageW=imgb.getWidth();
		int imageH=imgb.getHeight();
		int imgArr[]=new int[imageW*imageH];
		imgb.getRGB(0,0,imageW,imageH,imgArr,0,imageW);
		int redPixels=0;
		int pixels=0;
		for(int i=0; i<imgArr.length;i++){
			if(imgArr[i] == 0xFFFF0000){
				//System.out.println("r");
				redPixels+=1;
			}
			pixels+=1;
		}
		System.out.println(((float)redPixels)/pixels*100+" %");
		/*String out="";
		for (int i = 0; i < imgArr.length/100; i++) {
			if (i % imageW ==0) out+="\n";
			out+=Integer.toHexString(imgArr[i]).toUpperCase() + " ";
		}
		System.out.println(out);*/
	}
}
