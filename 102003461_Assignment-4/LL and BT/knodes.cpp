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
int max(int a,int b)
{
	if(a > b)
	return a;
	else
	return b;
}
void preOrderTraversal(Node* root)
{
	if(root==NULL)
	return;
	cout<<root->data<<" ";
	preOrderTraversal(root->left);
	preOrderTraversal(root->right);
}
void NodesAtK(Node* root,int k)
{
	if(root==NULL)
	return;
	
	if(k==0)
	cout<<root->data<<" ";

	NodesAtK(root->left,k-1);
	NodesAtK(root->right,k-1);
}
void levelOrder(Node* root)
{
	if(root==NULL)
	return;
	queue<Node*>q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1)
	{
		Node* temp=q.front();
		    q.pop();
		if(temp==NULL)
		{
			cout<<endl;
			q.push(NULL);
			continue;
		}
		   cout<<temp->data<<" ";
		    if(temp->left!=NULL)
		    q.push(temp->left);
		    if(temp->right!=NULL)
		    q.push(temp->right);
		
	}
}
int countNodes(Node* root)
{
	if(root==NULL)
	return 0;
	if(root->left==NULL && root->right==NULL)
	return 1;
	
	return 1+countNodes(root->left)+countNodes(root->right);
}
int maxBinaryTree(Node* root)
{
	if(root==NULL)
	return INT_MIN;
	if(root->left==NULL && root->right==NULL)
	return root->data;
	
	int leftmax=maxBinaryTree(root->left);
	int rightmax=maxBinaryTree(root->right);
	
	int finalAns=max(root->data,max(leftmax,rightmax));
	return finalAns;
}
int maxlevel=0;
void printLeft(Node* root, int level)
{
	if(root==NULL)
	return;
	if(maxlevel<level)
	{
		cout<<root->data<<" ";
		maxlevel=level;
	}
	printLeft(root->left,level+1);
	printLeft(root->right,level+1);
}
void printLeftView(Node* root)
{
	printLeft(root,1);
}
int main()
{
	Node* root=new Node(10);
	 root->left= new Node(20);
	 root->right=new Node(30);
     root->left->left=new Node(118);
     root->left->right=new Node(70);
     root->right->right=new Node(68);
     root->left->right->left=new Node(9);
     root->left->right->right=new Node(15);
      preOrderTraversal(root);
       cout<<endl;
       NodesAtK(root,3);
       cout<<endl;
       levelOrder(root);
       int numNodes=countNodes(root);
       cout<<endl;
       cout<<"number of nodes"<<numNodes;
       cout<<endl;
       int maxBT=maxBinaryTree(root);
       cout<<"max in binary tree  "<<maxBT;
       cout<<endl;
       cout<<"Left View"; 
       cout<<endl;
	   printLeftView(root);
 }
 
