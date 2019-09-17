#include<iostream>
using namespace std;
typedef struct  NODE
{
	struct NODE *next;
	int data;
}Node;

Node* CreateNewNode(int);
void DisplayList(Node*);
Node* ReverseKElements(Node*,int);
Node* PairWiseElements(Node*,int);

Node* PairWiseElements(Node* head ,int skip)
{
	Node *end=head,*prev=NULL,*curr=head,*next,*move;
	
	if(end->next==NULL)/////////////termination case
		return end;
	
	else {
		for(int i=0;i<skip&&(end->next!=NULL);i++)///////finding out the length of sublist
	{
		end=end->next;
	}
	
	while(curr!=end)
	{
		next=curr->next;
		curr->next=prev;
		head=curr;	
		prev=curr;
		curr=next;
	}
	move=PairWiseElements(end ,skip);
	move1=move;
	while(move-next!=NULL)
		move=move->next;
	move->next=head;
	
	}
	
	
	
}

Node* ReverseKElements( Node *head,int k)
{

Node* end=head,*curr=head,*prev=NULL,*next;
for(int i=0;i<k&&(end->next);i++)
	end=end->next;//traversing until end of section to be reversed

while(curr!=end)
{
		next=curr->next;
		curr->next=prev;
		head=curr;
		cout<<"Now head is "<<head->data<<endl;
		prev=curr;
		curr=next;
}
cout<<"Curr points to "<<curr->data<<endl;
curr=head;
while(curr->next!=NULL)
{
curr=curr->next;
}

curr->next=end;

return head;
}

void DisplayList(Node *head)
{
	Node *move=head;
	cout<<"The list is"<<endl;
	
	while(move)
	{
		cout<<move->data<<" "<<" Address: "<<move<<endl;
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
	for(int i =1 ;i <= 5;i++)
		head=Insert(head,i);
	DisplayList(head);
	
	head=PairWiseElements(head,3);
	DisplayList(head);
return 0;
}