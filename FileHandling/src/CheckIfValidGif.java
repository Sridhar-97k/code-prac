import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Scanner;
import java.nio.file.*;
import java.nio.file.attribute.BasicFileAttributes;
public class CheckIfValidGif {

	static boolean checkIfCapitalLetterExists(String string)
	{

		StringBuffer buffer=new StringBuffer(string);
		Character ch;
		for ( int i =0; i < buffer.length();i++)
		{
			ch=buffer.charAt(i);
			if(Character.isUpperCase(ch))
			{
				return true;

			}
		}
		return false;
	}
	public static void main(String args[])
	{
		String path="C:\\Users\\Sridhar\\PycharmProjects\\Lewd\\gifs\\gifs";

		File[] files=new File(path).listFiles();
		for ( File x : files)
		{
			//System.out.println(x.getAbsolutePath());
			getGifsFromFile(x);
		}

	}

	static void getGifsFromFile(File file)
	{
		File opfile=new File(file.getParent()+"/"+file.getName()+" completedgifs.txt");
		
		FileOutputStream outputStream=null;
		try {
			opfile.createNewFile();
			System.out.println(opfile.getAbsolutePath());
			outputStream = new FileOutputStream(opfile);
		} catch (Exception e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		OutputStreamWriter outputStreamWriter=new OutputStreamWriter(outputStream);
		ArrayList<String> validgifs=new ArrayList<String>();
		Scanner s1=null;
		try {
			s1 = new Scanner(file);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		String line;
		Integer x = 0;
		while(s1.hasNext())
		{
			line=s1.next().trim();
			//System.out.println(line);

			if(checkIfCapitalLetterExists(line))
			{	try {
				outputStreamWriter.write(line+"\n");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			}
			x++;
		}
		try {
			outputStreamWriter.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

}
