import java.util.*;
class Parentheses
{

public boolean isBalanced(String expression)
{
	
	Stack<Character> stck=new Stack<Character>();
	char s[]=expression.toCharArray();
	char a;
	Integer length=expression.length();
	for(int i=0;i<length;i++)
	{
		a=s[i];
		if((a=='(')||(a=='{')||(a=='['))
		{
			stck.push(a);
		}
		if((a==')'))
		{
			if(stck.pop()!='(') 
			{
				return false;
			}	
		}
		if((a==']'))
		{
			if(stck.pop()!='[') 
			{
				return false;
			}
		}
		if((a=='}'))
		{
			if(stck.pop()!='{') 
			{
				return false;
			}
		}
		
	}
	if(!stck.isEmpty())
		{
			return false;
		}
		return true;
}
public static void main(String args[])
{
Parentheses p =new Parentheses();
String expression="[]";
System.out.println(p.isBalanced(expression));
System.exit(0);
}

}