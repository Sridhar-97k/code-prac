
public class SingleTon {
private static SingleTon singleinstance = null;
	String str;
	private SingleTon()
{
str="This is a single class variable";
}

public static  SingleTon getInstance()
{
	if(singleinstance==null)
		singleinstance=new SingleTon();
	return singleinstance;
}


}
