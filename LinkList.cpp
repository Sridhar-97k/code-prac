#include<iostream>
#include<malloc.h>
#define null NULL
using namespace std;
typedef struct Node
{
int val;
struct Node *next;

}ListNode;


ListNode* newNode(int);
ListNode* addEnd(ListNode*,int);
void displayList(ListNode*);
ListNode* reverseList(ListNode*);
ListNode* reverseListRec(ListNode*);
ListNode* reverseListRec(ListNode *head){
	ListNode *reverse_list;
	if(head==null||head->next==null)
		return head;
	
	reverse_list=reverseListRec(head->next);
	
	head->next->next=head;
	head->next=null;
	
	return reverse_list;//always returns constant value
}

ListNode* reverseList(ListNode *head)
{
	if((head==null)||(head->next==null))
		return head;//single element
	ListNode *temp,*list_to_do,*reverse_list;
	list_to_do=head->next;
	reverse_list=head;
	reverse_list->next=NULL;
	
	cout<<"revese list"<<endl;
	while(list_to_do)
	{
		
		temp=list_to_do;
		cout<<temp<<endl;
		list_to_do=list_to_do->next;
		temp->next=reverse_list;
		reverse_list=temp;
		
	}
	return reverse_list;
}
ListNode* newNode(int data)
{
	ListNode* node;
	node=(ListNode*)malloc(sizeof(ListNode*));
	node->next=NULL;
	node->val=data;
	return node;
}
ListNode* addEnd(ListNode *head , int val)
{
	ListNode* temp;
	if(head==null)
		return newNode(val);
	else {
		temp=head;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newNode(val);
		
	}
	return head;
	
	
}
void displayList(ListNode* head)
{
	cout<<"\nThe list is "<<endl;
	ListNode* move=head;
	while(move)
	{
		cout<<" "<<move->val<<","<<move<<endl;
	move=move->next;
	}
	return ;
} 

int main()
{
	Node *head=NULL;
	/*head=newNode(10);
	
	head->next=newNode(20);
	
	head->next->next=newNode(40);
	
	head->next->next->next=newNode(80);*/
	head=addEnd(head,10);
	//displayList(head);
	head=addEnd(head,11);
	//displayList(head);
	head=addEnd(head,12);
	//displayList(head);
	displayList(reverseListRec(head));
}