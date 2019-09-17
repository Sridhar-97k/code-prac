
public class MyClass implements Runnable {
	@Override
	public void run() {
			System.out.println(Thread.currentThread().getName());
	}
}
