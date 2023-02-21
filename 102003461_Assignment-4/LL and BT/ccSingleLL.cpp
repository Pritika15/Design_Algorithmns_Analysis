#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	Node(int d)
	{
		this->data=d;
		this->next=NULL;
	}
};
void printCCL(Node* head)
{
	if(head==NULL)
	return;
	Node* p =head;
	do{
		cout<<p->data<<" ";
		p=p->next;
	}
	while(p!=head);
}
Node* InsertAtBegin(Node* &head,int d)
{
	Node* newnode= new Node(d);
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
	}
	Node* temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=head;
	head=newnode;
	return head;
}
Node* insertATEnd(Node* &head, int x)
{
	Node* newnode= new Node(x);
	if(head==NULL)
	{
		head=newnode;
		newnode->next=head;
	}
	Node* temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->next=head;
}
Node* deleteHead(Node* &head)
{
	if(head==NULL)
	return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
    Node*temp=head;
	Node* curr=head;
	while(curr->next!=head)
	{
		curr=curr->next;
	}
	curr->next=head->next;
	delete temp;
	head=curr->next;
	return head;
}
Node* DeleteKthNode(Node* &head,int pos)
{
	if(head==NULL)
	return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
	if(pos==1)
	{
		Node* temp=head;
		while(temp->next!=head)
		{
			temp=temp->next;
		}
		temp->next=head->next;
		Node* curr=head;
		delete curr;
		head=temp->next;
	}
	else
	{
		int count=1;
		Node*temp=head;
		while(temp->next->next!=head && pos-count>1)
		{
			temp=temp->next;
			count++;
		}
		Node* t=temp->next;
		temp->next=t->next;
		delete t;
		
	}
}
int main()
{
	Node* head=new Node(10);
	Node* temp1= new Node(5);
	Node* temp2= new Node(20);
	Node* temp3= new Node(5);
	head->next=temp1;
	temp1->next=temp2;
	temp2->next=temp3;
	temp3->next=head;
	printCCL(head);
	cout<<endl;
	cout<<"Insert at begin"<<endl;
	InsertAtBegin(head,6);
	printCCL(head);
	cout<<endl;
	cout<<"Insert at end"<<endl;
	insertATEnd(head,7);
	printCCL(head);
	cout<<endl;
	cout<<"Insert at end"<<endl;
	insertATEnd(head,17);
	printCCL(head);
	cout<<endl;
	cout<<"delete head"<<endl;
	deleteHead(head);
	printCCL(head);
	cout<<endl;
	cout<<"delete K node"<<endl;
	DeleteKthNode(head,1);
	printCCL(head);
	cout<<endl;
	cout<<"delete K node"<<endl;
	DeleteKthNode(head,3);
	printCCL(head);
	cout<<endl;
	cout<<"delete K node"<<endl;
	DeleteKthNode(head,4);
	printCCL(head);
	cout<<endl;
	cout<<"delete K node"<<endl;
	DeleteKthNode(head,2);
	printCCL(head);
}
