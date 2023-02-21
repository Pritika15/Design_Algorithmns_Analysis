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
int max(int a, int b)
{
	if(a>b)
	return a;
	else
	return b;
}
void FixBst(Node* &root)
{
	if(root==NULL)
	return;
	FixBst(root->left);
	FixBst(root->right);
	int maxi=INT_MIN;
	 maxi=max(maxi,root->left->data);
	int mini=INT_MAX;
	 mini=min(mini,root->right->data);
	 if(maxi > root->data && mini< root->data)
	 {
	 	swap(maxi,mini);
	 }
	 else if(maxi > root->data)
	 swap(maxi,root->data);
	 else if(mini< root->data)
	 swap(mini,root->data);
}
void INorder(Node* root)
{
	if(root==NULL)
	return;
	INorder(root->left);
	cout<<root->data<<" ";
	
	INorder(root->right);
}
int main()
{
	Node* root= new Node(60);
	root->left= new Node(8);
	root->right= new Node(80);
	root->left->left= new Node(4);
	root->left->right= new Node(10);
	root->right->left= new Node(20);
	root->right->right= new Node(100);
	cout<<"Before Fixing Tree"<<endl;
	INorder(root);
	cout<<endl;
	cout<<"After Fixing Tree"<<endl;
	FixBst(root);
	INorder(root);
	//FixBst
}
