#include<iostream>
using namespace std;
typedef struct NODE
{
int data;
struct NODE *next;

}Node;
//////////////////////////
Node* CreateNewNode(int);
void DisplayList(Node*);
Node* mergeLists(Node*,Node*);
//////////////////////////
void DisplayList(Node *head)
{
	Node *move=head;
	cout<<"The list is"<<endl;
	
	while(move)
	{
		cout<<move->data<<" "<<endl;
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
	Node *temp=CreateNewNode(val),*move=head;
	
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
Node* mergeLists(Node *head1,Node *head2)
{
	Node *move1=head1,*move2=head2,*temp;
	Node *move;
	while(move1&&move2)
	{
		if((move1->data)>(move2->data))
		{
			
			move=Insert(move,move2->data);
	cout<<move2->data<<" inserted "<<endl;
	move2=move2->next;
		}
		else if((move1->data)<(move2->data))
		{
		move=Insert(move,move1->data);
		cout<<move1->data<<" inserted "<<endl;
		move1=move1->next;
			
		}
		else if((move1->data)==(move2->data))
		{
		move=Insert(move,move2->data);
		cout<<move2->data<<" inserted "<<endl;
		move2=move2->next;	
		move1=move1->next;	
		}
	}
	while(move1)
	{
		move=Insert(move,move1->data);
		move1=move1->next;
	}
	while(move2)
	{
		move=Insert(move,move2->data);
		move2=move2->next;
	}
	return move;
}
int main()
{
			Node *head1,*head2;
			head1=CreateNewNode(1);
			head1->next=CreateNewNode(3);
			head1->next->next=CreateNewNode(5);	
			head1->next->next->next=CreateNewNode(7);
			
			
			head2=CreateNewNode(2);
			head2->next=CreateNewNode(4);
			head2->next->next=CreateNewNode(6);	
			head2->next->next->next=CreateNewNode(8);
			DisplayList(head1);
			DisplayList(head2);
			
			///
	Node *merge=mergeLists(head1,head2);
	DisplayList(merge);
	
}