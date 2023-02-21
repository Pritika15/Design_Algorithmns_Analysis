#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* left;
	Node* right;
	Node(int d)
	{
		this->data=d;
		this->left=NULL;
		this->right=NULL;
	}
};
void Preorder(Node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	Preorder(root->left);
	Preorder(root->right);
}
Node* getSucc(Node* curr)
{
	curr=curr->right;
	while(curr!=NULL && curr->left!=NULL)
	{
		curr=curr->left;
	}
	return curr;
}
Node* Nodedelete(Node* &root,int x)
{
	if(root==NULL)
	return root;
	
	if(root->data > x)
	root->left=Nodedelete(root->left,x);
	
	else if(root->data < x)
	root->right=Nodedelete(root->right,x);
	
	else
	{
		if(root->left==NULL)
		{
			Node* temp=root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL)
		{
			Node* temp=root->left;
			delete root;
			return temp;
		}
		else
		{
			Node* successor=getSucc(root);
			root->data=successor->data;
			root->right=Nodedelete(root->right,successor->data);
			
		}
		
	}
	
return root;	
}
int main()
{
	Node* root= new Node(50);
	root->left=new Node(30);
	root->right=new Node(70);
	root->left->left=new Node(10);
	root->left->right=new Node(40);
	root->right->left=new Node(60);
	root->right->right=new Node(80);
	root->right->left->left=new Node(55);
	cout<<"intitally:"<<endl;
	Preorder(root);
	cout<<endl;
	cout<<"after deletion:"<<endl;
	Node* newRoot=Nodedelete(root,50);
	
	Preorder(newRoot);
}
