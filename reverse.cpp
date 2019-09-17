#include<iostream>
using namespace std;
typedef struct  NODE
{
	struct NODE *next;
	int data;
}Node;

Node* CreateNewNode(int);
void DisplayList(Node*);
Node* mergeLists(Node*,Node*);
Node* Reverse(Node*);

Node* Reverse(Node* head)
{
	int i=0;
	Node *current=head,*prev=NULL,*next=NULL;
	if(head==NULL||head->next==NULL)
		return head;
	
	while(current!=NULL)
		
		{
		next=current->next;
		current->next=prev;
		prev=current;
		head=current;
		current=next;
		
		}
	
	cout<<" Reversal done "<<endl;
	return head;
}
void DisplayList(Node *head)
{	
	Node *move=head;
	cout<<"The list is"<<endl;
	
	while(move)
	{
		//cout<<" "<<move->data<<" "<<" Address: "<<move;
		cout<<" "<<move->data<<endl;
		move=move->next;
	}
	return ;
}

Node* CreateNewNode(int val)
{
	Node* head;
	
	head=(Node*)malloc(sizeof(Node));
	head->data=val;
	head->next=NULL;
	return head;
}
Node* Insert(Node* head,int val)
{
	Node *temp,*move=head;
	
	if(!head)
	{
		return CreateNewNode(val);
	}
	else 
	{
			while(move->next!=NULL)
			{
				
				move=move->next;
				
			}	
		move->next=CreateNewNode(val);
	}
	return head;
}


int main()
{
	Node *head=NULL;
	for(int i =1 ;i <= 6;i++)
		head=Insert(head,i);
	DisplayList(head);
	head=Reverse(head);
	DisplayList(head);	 
	return 0;
}