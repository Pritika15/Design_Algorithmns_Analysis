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
int prev=INT_MIN;
bool CheckBST(Node* root)
{
	if(root==NULL)
	return true;
	if(CheckBST(root->left)==false) return false;
	if(root->data <= prev) return false;
	prev=root->data;
	return CheckBST(root->right);
}
int main()
{
	Node* root= new Node(10);
	root->left= new Node(8);
	root->right= new Node(20);
	root->right->left= new Node(13);
	root->right->right= new Node(24);
	
//	Node* root= new Node(20);
//	root->left= new Node(8);
//	root->right= new Node(30);
//	root->right->left= new Node(18);
//	root->right->right= new Node(35);
	
	bool ans=CheckBST(root);
	cout<<ans<<endl;
	
	
	}
