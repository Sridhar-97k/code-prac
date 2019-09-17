#include<iostream>
#include<queue>
using namespace std;


int main()
{
	
	queue<int> q;
	
	queue<int>::iterator i;
	q.push(10);
	q.push(11);
	q.push(12);
	q.push(13);
	for(i=q.begin();i!=q.end();++i)
	{
		
		cout<<*i;
		
	}
}