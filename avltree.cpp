#include<iostream>
#include<queue>
using namespace std;
typedef struct NODE
{
	int data,height,balance;
	struct NODE *left,*right;
	
}Node;
////////////////////////////////////
void LevelOrder(Node*);
void LevelOrderLine(Node*);
Node* RightRotate(Node*);
Node* LeftRotate(Node*);
Node* LeftRightRotate(Node*);
Node* RightLeftRotate(Node*);
Node* CreateNewNode(int);
Node* Insert(Node*,int);
int getHeight(Node*);
////////////////////////////////////
void LevelOrder(Node *root)
{
	if(!root)
	{cout<<"Empty Tree"<<endl;
	return ;}
		else 
		{
			queue<Node*> q;
			q.push(root);
			
			while(q.empty()==false)
			{
				Node* node=q.front();
				q.pop();
				
				cout<<"Data : "<<node->data<<" Address : "<<node<<endl;
				if(node->left)
				q.push(node->left);
				
				if(node->right)
				q.push(node->right);
				
			}
			
		}
		
	return ;
	
}
void LevelOrderLine(Node *root)
{
	if(!root)
	{cout<<"Empty Tree"<<endl;
	return ;}
		else 
		{
			queue<Node*> q;
			q.push(root);
			
			while(q.empty()==false)
			{	int nodes=q.size();
		
				while(nodes--)
				{
				Node* node=q.front();
				q.pop();
				
				cout<<"Data : "<<node->data<<" Address : "<<node<<endl;
				if(node->left)
				q.push(node->left);
				
				if(node->right)
				q.push(node->right);
				
				}
				cout<<endl;
			}
		}
		
	return ;
	
}
Node* Insert(Node* node,int ele)
{
	if(!node)
	{	return CreateNewNode(ele);
	}
	if(ele>node->data)
	{
			node->right=Insert(node->right,ele);
	}
	if(ele<node->data)
	{
			node->left=Insert(node->left,ele);
	}
	if(ele==node->data)
	{
			cout<<"Duplicate data not allowed "<<endl;
	}
	int balance=getHeight(node->left)-getHeight(node->right);
	
	

		if((balance>1)&&(getHeight(node->left->left)>getHeight(node->left->right)))
		{
			node=RightRotate(node);
		}
			
		if((balance>1)&&(getHeight(node->left->right)>getHeight(node->left->left)))
			{
			node=LeftRightRotate(node);
		}
		if((balance<-1)&&(getHeight(node->right->left)>getHeight(node->right->right)))
		{
			node=RightLeftRotate(node);
		}
			
		if((balance<-1)&&(getHeight(node->right->right)>getHeight(node->right->left)))
			{
			node=LeftRotate(node);
		}
	return node;
}

Node* LeftRightRotate(Node *node)
{
	node->left=LeftRotate(node->left);
	return RightRotate(node);
}
Node* RightLeftRotate(Node *node)
{
	node->right=RightRotate(node->right);
	return LeftRotate(node);
}

Node* RightRotate(Node *node)
{
	Node *T1,*left=node->left;
	T1=left->right;
	left->right=node;
	node->left=T1;
	return left;
	
}
Node* LeftRotate(Node *node)
{
	Node *T1,*right=node->right;
	T1=right->left;
	right->left=node;
	node->right=T1;
	return right;
	
}

int getHeight(Node* root)
{
	if(root==NULL)
		return 0;
	int l=getHeight(root->left);
	int r=getHeight(root->right);
	if(l>r)
		return 1+l;
	else return 1+r;
	
}
void InOrder(Node*);
void InOrder(Node *root)
{
	if(root)
	{
	InOrder(root->left);
	cout<<" address "<<root;
	cout<<" data "<<root->data;
	cout<<" left "<<root->left;
	cout<<" right "<<root->right<<endl;
		
	InOrder(root->right);
	
	}
}
Node* CreateNewNode(int ele)
{
	Node* node;
	node=(Node*)malloc(sizeof(Node));
	node->right=node->left=NULL;
	node->data=ele;
	return node;
}

int main()
{
	Node *root =NULL;
	 for(int i=0;i<10;i++)
	{
	root=Insert(root,i);	
	} 
	LevelOrderLine(root);
	cout<<"Height is "<<getHeight(root)<<endl;
	InOrder(root);
	return 0;
}