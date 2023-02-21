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
void Insert(Node* &root,int x)
{
	if(root==NULL)
	{
	   Node* temp=new Node(x);
	   root=temp;
	   return;
	}
	if(root->data < x)
	{
		root->right=(root->right,x);
	}
	else
	root->left=(root->left,x);
	
}
int main()
{
	Node* root= new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(13);
	root->right->right=new Node(18);
	cout<<"before insertion"<<endl;
	Preorder(root);
	cout<<endl;
	Insert(root,20);
	cout<<"after insertion"<<endl;
	Preorder(root);
	
}
