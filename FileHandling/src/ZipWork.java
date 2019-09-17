import java.io.*;

import net.lingala.zip4j.exception.ZipException;
public class ZipWork {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File zipFile[]=new File("E:\\New folder\\New folder").listFiles();
		File dest=new File("E:\\New folder\\\\New folder\\dest");
		for ( File newfile : zipFile)
		{
			System.out.println(newfile.getAbsolutePath());
			
			  net.lingala.zip4j.ZipFile file =new net.lingala.zip4j.ZipFile(newfile); try {
			  file.extractAll(dest.getAbsolutePath()); } catch (ZipException
			  e) { // TODO Auto-generated catch block e.printStackTrace(); }
			 
		}
	}
}
}
