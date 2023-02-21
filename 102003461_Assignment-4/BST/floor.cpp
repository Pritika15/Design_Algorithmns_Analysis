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
Node* floor(Node* root,int x)
{
	if(root==NULL)
	return NULL;
	Node* ansNode=NULL;
	
	while(root!=NULL)
	{
		if( root->data == x)
	 {
		ansNode=root;
	 }
	 if(root->data > x)
	 {
		root=root->left;
	 }
	 if(root->data < x)
	 {
		ansNode=root;
		root=root->right;
	 }
	}
	
	return ansNode;
}
int ceil(Node* root,int x)
{
	if(root==NULL)
	return -1;
	
	
	if(root->data==x)
		return root->data;
		
	if(root->data < x)
		{
			return ceil(root->right,x);
		}
	int ceilVal=ceil(root->left,x);
		return(ceilVal>=x)? ceilVal:root->data;

	
}
//void preOrderTraversal(Node* root)
//{
//	if(root==NULL)
//	return;
//	cout<<root->data<<" ";
//	preOrderTraversal(root->left);
//	preOrderTraversal(root->right);
//}
int main()
{
	Node* root=new Node(50);
	root->left=new Node(30);
	root->right=new Node(70);
    root->left->left=new Node(20);
    root->left->right=new Node(40);
    root->right->left=new Node(60);
    root->right->right=new Node(80);
    root->right->left->left=new Node(55);
    root->right->left->right=new Node(65);
//    preOrderTraversal(root);
    cout<<endl;
	Node* ans=floor(root,58);
	cout<<ans->data<<endl;
	cout<<ceil(root,40)<<endl;
	
}
