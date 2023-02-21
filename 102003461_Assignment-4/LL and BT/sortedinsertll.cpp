#include<bits/stdc++.h>
using namespace std;
class Node{
	
	public:
	int data;
	Node *next;
	Node(int d)
	{
		this->data=d;
		this->next=NULL;
	}
};
void recPrintLL(Node* head)
{
	if(head==NULL)
	return;
	cout<<head->data<<" ";
	recPrintLL(head->next);
}
Node* insertSort(Node* &head,int d)
{
	Node* temp= new Node(d);
	if(head==NULL)
	{
		head=temp;
		return head;
	}
	if(head->data > d)
	{
		temp->next=head;
		head=temp;
		return head;
		
	}
	Node* curr=head;
	while(curr->next!=NULL && curr->next->data < d)
	{		
		curr=curr->next;
	}
	temp->next=curr->next;
	curr->next=temp;
	return head;
}
int middleEle(Node* &head)
{
	if(head==NULL)
	{
		return 0;
	}
	if(head->next==NULL)
	{
		return head->data;
	}
	Node* temp=head;
	int count=1;
	while(temp->next!=NULL)
	{
		count++;
		temp=temp->next;
	}
	cout<<"Count "<<count<<endl;
	int mid;
	if(count%2!=0)
	{
		mid=(count/2)+1;
	}
	else
	{
		mid=(count/2)+1;
	}
	int i=1;
	temp=head;
	while(temp!=NULL && i<mid)
	{
		temp=temp->next;
		i++;
	}
	return temp->data;
}
void MidElement1trav(Node* head)
{
	if(head==NULL)
	return;
	if(head->next==NULL)
	cout<<head->data;
	Node* slow=head;
	Node* fast= head;
	while(fast!=NULL && fast->next!=NULL)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	cout<<slow->data<<endl;
}
int main()
{
	Node* head=new Node(10);
	Node * temp1= new Node(20);
	Node* temp2= new Node(30);
	head->next=temp1;
	temp1->next=temp2;
	recPrintLL(head);
	cout<<endl;
	cout<<"Sort InsertLL"<<endl;
	insertSort(head,25);
	recPrintLL(head);
	cout<<endl;
	cout<<"Sort InsertLL"<<endl;
	insertSort(head,5);
	recPrintLL(head);
	
	cout<<endl;
	cout<<"Middle ele"<<endl;
	cout<<middleEle(head)<<endl;
	cout<<endl;
	cout<<"Sort InsertLL"<<endl;
	insertSort(head,55);
	recPrintLL(head);
	cout<<endl;
	cout<<"Middle ele"<<endl;
	cout<<middleEle(head)<<endl;
	cout<<endl;
	cout<<"Sort InsertLL"<<endl;
	insertSort(head,1);
	recPrintLL(head);
//	cout<<endl;
//	cout<<"Middle ele"<<endl;
//	cout<<middleEle(head)<<endl;
//	cout<<endl;
//	cout<<"Sort InsertLL"<<endl;
//	insertSort(head,23);
//	recPrintLL(head);
//	cout<<endl;
//	cout<<"Middle ele"<<endl;
//	cout<<middleEle(head)<<endl;
	cout<<endl;
	cout<<"Middle ele uisng 1 traversal"<<endl;
	MidElement1trav(head);
}
