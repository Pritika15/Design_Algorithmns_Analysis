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
Node* reverseinK(Node* head,int k)
{
//	if(head==NULL)
//	return NULL;
//	if(head->next==NULL)
//	return head;
	Node*curr=head;
	Node* prev=NULL;
	Node* next=NULL;
	int count=0;
	while(curr!=NULL && count<k)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
		count++;
	}
	if(next!=NULL)
	{
		Node* rem_head=reverseinK(next,k);
		head->next=rem_head;
	}
	return prev;
}
int main()
{
	Node* head=new Node(1);
	Node * temp1= new Node(2);
	Node* temp2= new Node(3);
	Node* temp3= new Node(4);
	Node* temp4= new Node(5);

	head->next=temp1;
	temp1->next=temp2;
	temp2->next=temp3;
	temp3->next=temp4;
	
	recPrintLL(head);
	cout<<endl;
	cout<<"Reverse in group of k"<<endl;
	Node* newHead=reverseinK(head,3);
	recPrintLL(newHead);
}
