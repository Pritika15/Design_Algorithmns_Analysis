#include<bits/stdc++.h>
using namespace std;
class Node{
	public:
	int data;
	Node* next;
	
	 Node(int d){
		this->data=d;
		this->next=NULL;
	}
};
void printLL(Node* head)
{
	Node* temp=head;
	while(temp!=NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
}
//Node* EvenOddLL(Node* &head)
//{
// Node* es=NULL;
//  Node* ee=NULL;
//  Node* os=NULL;
//  Node* oe=NULL;
// //ee,os,oe=NULL;
// for(Node* curr=head;curr!=NULL;curr=curr->next)
// {
// 	int x=curr->data;
// 	if(x%2==0)
// 	{
// 		if(es==NULL)
// 		{
// 			es=curr;
// 			ee=es;
//		 }
//		 else
//		 {
//		 	ee->next=curr;
//		 	ee=ee->next;
//		 }
//	 }
//	 else
//	 {
//	 	if(os==NULL)
//	 	{
//	 		os=curr;
//	 		oe=os;
//		 }
//		 else
//		 {
//		 	oe->next=curr;
//		 	oe=oe->next;
//		 }
//	 }
//	 
// }
//if(os==NULL || es==NULL)
//return head;
//
//ee->next=os;
//oe->next=NULL;
//head=es;	
//
//}
void PairwiseSwap(Node* head)
{
	if(head==NULL)
	return;
	Node* curr=head;
	

	for(curr;curr->next!=NULL;curr=curr->next->next)
	{
			
			
				swap(curr->data,curr->next->data);
					
	}
}
int main()
{
//	Node* head= new Node(17);
//	Node* nextt1=new Node(15);
//	Node* nextt2=new Node(8);
//	Node* nextt3=new Node(12);
//	Node* nextt4=new Node(10);
//	Node* nextt5=new Node(5);
//	Node* nextt6=new Node(4);
//	head->next=nextt1;
//	nextt1->next=nextt2;
//	nextt2->next=nextt3;
//	nextt3->next=nextt4;
//	nextt4->next=nextt5;
//	nextt5->next=nextt6;

    Node* head= new Node(1);
	Node* nextt1=new Node(2);
	Node* nextt2=new Node(3);
	Node* nextt3=new Node(4);
	Node* nextt4=new Node(5);
	//Node* nextt5=new Node(6);
	head->next=nextt1;
	nextt1->next=nextt2;
	nextt2->next=nextt3;
	nextt3->next=nextt4;
	//nextt4->next=nextt5;
	printLL(head);
	//EvenOddLL(head);
	PairwiseSwap(head);
	cout<<endl;
	printLL(head);
}
