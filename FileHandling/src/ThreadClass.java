import java.util.ArrayList;
import java.util.HashSet;
import java.util.SortedSet;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
class RunThis implements Runnable
{
public void run()
{
	System.out.println(Thread.currentThread().getName());
	}

}

public class ThreadClass {
	public static void main(String[] args) {
		HashSet set=new HashSet();
		CheckDuplicates Sridhar=new CheckDuplicates("Sridhar");
		CheckDuplicates Rishabh=new CheckDuplicates("Rishabh");
		CheckDuplicates Ayush=new CheckDuplicates("Ayush");
		set.add(Sridhar);
		set.add(Rishabh);
		set.add(Ayush);
		
	ArrayList<Integer> list =new ArrayList<Integer>();
	list.add(100);
	list.add(100);
	list.add(100);
	set.addAll(list);
	System.out.println(set.toString());
	
	
	}

}


