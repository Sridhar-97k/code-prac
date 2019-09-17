
public class MainClass {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
SingleTon x = SingleTon.getInstance();
x.str="I am setting str of x's object";
SingleTon y = SingleTon.getInstance();

SingleTon z = SingleTon.getInstance();
System.out.println(z.str);

	}

}
