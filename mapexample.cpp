#include<iostream>
#include<map>
using namespace std;
int main()
{
std::map<std::string,int> i;
i.insert(std::make_pair("key1",1));
i.insert(std::make_pair("key2",2));
i.insert(std::make_pair("key3",3));
i.insert(std::make_pair("key4",4));

std::map<std::string,int>::iterator iter = i.end();
while(iter!=i.begin())
{
	cout<<"The value is "<<(*iter).first<<" "<<(*iter).second<<endl; 
	iter--;
}
return 0;
}