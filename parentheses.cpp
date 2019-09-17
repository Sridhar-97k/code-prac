#include<iostream>
#include<string.h>
#include<stack>
using namespace std;
bool balance(string s)
{	
int length=s.length();
	cout<<"The lenght is "<<length<<endl;
	stack<char> mystack;
	char a;
	for(int i =0;i<length;i++)
	{
		a=s[i];
		if((a=='(')||(a=='{')||(a=='['))
		{
			mystack.push(a);
		}
		if((a==')'))
		{
			if(mystack.top()!='(') 
			{
				return false;
			}
			mystack.pop();
				
		}
		if((a==']'))
		{
			if(mystack.top()!='[') 
			{
				return false;
			}
			mystack.pop();
				
		}
		if((a=='}'))
		{
			if(mystack.top()!='{') 
			{
				return false;
			}
			mystack.pop();	
		}
		
	}
	if(!mystack.empty())
		return false;
	return true;
}
int main()
{
string expression="[()]";
cout<<"Expression is "<<expression<<endl;
	cout<<balance(expression)<<endl;;
	return 0;
}
