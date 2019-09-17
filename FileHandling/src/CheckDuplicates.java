import java.io.File;
import java.util.HashMap;
import java.util.Set;
import java.util.TreeSet;

public class CheckDuplicates {
	private String name;
	CheckDuplicates(String name)
	{
		this.name=name;
		}
	String getName(){
		return this.name;
	}
public static void main(String args[])
{
File file=new  File("C:\\Users\\Sridhar\\Downloads\\Video");
HashMap<Long,String> map =new HashMap<Long,String>(); 
File[] files=file.listFiles();

Integer noofduplicates=0;
for (File x : files)
{
	Long filesize= x.length();
	String name =x.getName();
	
	if (map.containsKey(filesize))
	{
				 	noofduplicates++;
	if(x.delete())
	{
		System.out.println(name + " was deleted ");
	}
	}
	else 
	map.put(filesize, name);		
		
	
}

System.out.println("There are "+noofduplicates+" duplicates");
}

}