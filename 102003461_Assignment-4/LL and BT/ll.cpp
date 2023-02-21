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
//void printLL(Node* head)
//{
//	Node* temp=head;
//	while(temp!=NULL)
//	{
//		cout<<temp->data<<" ";
//		temp=temp->next;
//	}
//}
void recPrintLL(Node* head)
{
	if(head==NULL)
	return;
	cout<<head->data<<" ";
	recPrintLL(head->next);
}
Node* InsertAtHead(int d,Node* &head)
{
	if(head==NULL)
	{
		Node* Nodenew= new Node(d);
		head=Nodenew;
	}
	Node* Nodenew= new Node(d);
	Nodenew->next=head;
	head=Nodenew;
}
Node* InsertAtEnd(int d, Node* &head)
{
	if(head==NULL)
	{
		Node* temp= new Node(d);
		head=temp;
	}
	Node* temp= new Node(d);
	Node* traversalNode=head;
	while(traversalNode->next!=NULL)
	{
		traversalNode=traversalNode->next;
	}
	traversalNode->next=temp;
}
Node* DeleteHeadNode(Node* &head)
{
	Node* temp= head;
	head=temp->next;
	delete temp;
}
Node* DeleteLastNode(Node* &head)
{
	if(head==NULL)
	return NULL;
	if(head->next==NULL)
	{
		delete head;
		return NULL;
	}
	Node*temp= head;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	
	delete temp->next;
	temp->next=NULL;
}
Node* InsertAtPos(int d,int pos, Node* head)
{
	Node* temp=head;
	int count=1;
	while(temp!=NULL && pos-count>1)
	{
		temp=temp->next;
		count++;
	}
	if(pos-count>1)
	{
		return head;
	}
	Node * newNode= new Node(d);
	Node* Savetemp=temp->next;
	temp->next= newNode;
	newNode->next=Savetemp;
	
}
int search(Node* head, int x)
{
	if(head==NULL)
	return -1;
	Node* temp=head;
	int count=1;
	while(temp!=NULL)
	{
		if(temp->data==x)
		{
			return count;
			break;
		}
		temp=temp->next;
		count++;
	}
	return -1;
}
int main()
{
	Node* head= new Node(10);
	Node* temp1= new Node(20);
	Node* temp2= new Node(30);
	head->next=temp1;
	temp1->next=temp2;
	//printLL(head);
	cout<<"Print"<<endl;
	recPrintLL(head);
	cout<<endl;
	cout<<"insert at head"<<endl;
	InsertAtHead(5,head);
	
	recPrintLL(head);
	cout<<endl;
	cout<<"insert at tail"<<endl;
	InsertAtEnd(40,head);
	recPrintLL(head);
	cout<<endl;
	cout<<"delete head"<<endl;
	DeleteHeadNode(head);
	recPrintLL(head);
//	cout<<endl;
//	DeleteHeadNode(head);
//	recPrintLL(head);
//	cout<<endl;
//	DeleteHeadNode(head);
//	recPrintLL(head);
//	cout<<endl;
//	DeleteHeadNode(head);
//	recPrintLL(head);
//	cout<<endl;
//	DeleteHeadNode(head);
//	recPrintLL(head);
cout<<endl;
cout<<"delete tail"<<endl;
DeleteLastNode(head);
recPrintLL(head);
cout<<endl;
cout<<"Insert at Pos"<<endl;
InsertAtPos(50,2,head);
recPrintLL(head);
cout<<endl;
cout<<"Insert at Pos"<<endl;
InsertAtPos(50,5,head);
recPrintLL(head);
cout<<endl;
cout<<"Insert at Pos"<<endl;
InsertAtPos(50,9,head);
recPrintLL(head);
cout<<endl;
cout<<"Insert at Pos"<<endl;
InsertAtPos(80,3,head);
recPrintLL(head);
cout<<endl;
cout<<"Search"<<endl;
cout<<search(head,40);
cout<<endl;
cout<<"Search"<<endl;
cout<<search(head,50);
}
