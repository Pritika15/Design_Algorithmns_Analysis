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
void PrintNthFronEnd(Node* head,int x)
{  
	int len=0;
	Node* curr=head;
	for(curr;curr!=NULL;curr=curr->next)
	{
		len++;
	}
	//cout<<"Len"<<len<<endl;
	if(len<x)
	return;
	
	curr=head;
	int count=1;
	while(count<len-x+1)
	{
		curr=curr->next;
		count++;
	}
	cout<<curr->data<<endl;

}
void PrintNthFromLastFast(Node* head, int x)
{
	Node*first=head;
	int count=1;
	while(count<=x)
	{
		first=first->next;
		count++;
	}
	Node* second=head;
	while(first!=NULL)
	{
		first=first->next;
		second=second->next;
	}
	cout<<second->data<<endl;
}
Node* removeDuplicate(Node* head)
{
    
	//Node* prev=head;
	Node* curr=head;
	while(curr->next!=NULL && curr!=NULL)
	{
		if(curr->data==curr->next->data)
		{
			Node* a=curr->next;
			curr->next=curr->next->next;
			delete a;
		}
		else
		{
			
			curr=curr->next;
			
		}
	}
	return head;
}
int main()
{
	Node* head=new Node(10);
	Node * temp1= new Node(20);
	Node* temp2= new Node(20);
	Node* temp3= new Node(30);
	Node* temp4= new Node(30);
	Node* temp5= new Node(30);
	head->next=temp1;
	temp1->next=temp2;
	temp2->next=temp3;
	temp3->next=temp4;
	temp4->next=temp5;
	recPrintLL(head);
	cout<<endl;
//	PrintNthFronEnd(head,6);
//	PrintNthFronEnd(head,5);
//	PrintNthFronEnd(head,3);
//	PrintNthFronEnd(head,8);
//	PrintNthFromLastFast(head,2);
//	PrintNthFromLastFast(head,1);
//	PrintNthFromLastFast(head,4);
//	PrintNthFromLastFast(head,6);
//	PrintNthFromLastFast(head,8);
//	cout<<endl;
	cout<<"remove duplicate"<<endl;
	removeDuplicate(head);
	recPrintLL(head);
}
