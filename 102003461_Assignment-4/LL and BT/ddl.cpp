#include<bits/stdc++.h>
using namespace std;
class DoubleNode{
	public:
	int data;
	DoubleNode* next;
	DoubleNode* prev;
	DoubleNode(int d)
	{
		this->data=d;
		this->next=NULL;
		this->prev=NULL;
	}
	
};
void printDDL(DoubleNode* head)
{
	if(head==NULL)
	return;
	DoubleNode*temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
DoubleNode* insertAtHead(DoubleNode* &head, int d)
{
    DoubleNode* newnode= new DoubleNode(d);
	newnode->next=head;
	head=newnode;
	newnode->next->prev=head;
	
}
DoubleNode* insertAtTail(DoubleNode* &head, int d)
{
	DoubleNode* newnode= new DoubleNode(d);
	if(head==NULL)
	{
		head=newnode;
	}
	DoubleNode* temp= head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;	
}
DoubleNode* ReverseDDl(DoubleNode* &head)
{
	if(head==NULL || head->next==NULL)
	return head;
	DoubleNode* curr=head;
	DoubleNode* prevNode=NULL;
	while(curr!=NULL)
	{
		prevNode=curr->prev;
		
		curr->prev=curr->next;
		curr->next=prevNode;
		curr=curr->prev;
	}
	head=prevNode->prev;
	return head;
}
DoubleNode* DeleteHead(DoubleNode* &head)
{
	if(head==NULL)
	return NULL;
	
	DoubleNode* temp=head->next;
	temp->prev=NULL;
	delete head;
	head=temp;
	
}
DoubleNode* DeleteLastNode(DoubleNode* &head)
{
	if(head==NULL)
	return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
	DoubleNode* curr=head;
	while(curr->next->next!=NULL)
	{
		curr=curr->next;
	}
	DoubleNode* temp=curr->next;
	curr->next=NULL;
	delete temp;
}
int main()
{
	DoubleNode* head= new DoubleNode(10);
	DoubleNode* temp1=new DoubleNode(20);
	DoubleNode* temp2=new DoubleNode(30);
	head->next=temp1;
	temp1->next=temp2;
	temp2->prev=temp1;
	temp1->prev=head;
	cout<<"PrintLL"<<endl;
	printDDL(head);
	cout<<endl;
	cout<<"insert at head"<<endl;
	insertAtHead(head,5);
	printDDL(head);
	cout<<endl;
	cout<<"insert at tail"<<endl;
	insertAtTail(head,15);
	printDDL(head);
	cout<<endl;
	cout<<"insert at tail"<<endl;
	insertAtTail(head,815);
	printDDL(head);
	cout<<endl;
	cout<<"insert at head"<<endl;
	insertAtHead(head,75);
	printDDL(head);
	cout<<endl;
	cout<<"reverse"<<endl;
	ReverseDDl(head);
	printDDL(head);
	cout<<endl;
	cout<<"delete head"<<endl;
	DeleteHead(head);
	printDDL(head);
	cout<<endl;
	cout<<"delete head"<<endl;
	DeleteHead(head);
	printDDL(head);
	cout<<endl;
	cout<<"delete tail"<<endl;
	DeleteLastNode(head);
	printDDL(head);
	cout<<endl;
	cout<<"delete tail"<<endl;
	DeleteLastNode(head);
	printDDL(head);
}
