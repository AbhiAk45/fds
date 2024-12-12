#include<iostream>
using namespace std;
class Node {
public:
    int data;
    int carry;
    Node* next;
    Node *prev;
};
Node* createNode(int data)
{
  Node *t;    
  t=new Node();    
  t->data=data;
  t->carry=0;
  t->next=NULL;
  t->prev=NULL;
  return(t);
}
Node* append(Node *e,int data,int dir=1)
{
  Node *t,*h;
 t=createNode(data);
 if(dir==1)
 {
  h=e;
  h->next=t;
  t->prev=h;
  e=t;
  e->next=NULL;
  return (e);
 }
 else
 {
 	cout<<"appending to head:"<<t->data<<"\n";
 	while(e->prev)
 	e=e->prev;
 	
 	e->prev=t;
 	t->next=e;
 	h=t;
 	return(h);
 	
 }
}

void printList(Node *h,int dir=1)
{
    Node *t;
    t=h;
    if(dir==1) 
    cout<<"\n------LIST DATA ----";
    while(t!=NULL)
    {
      cout<<t->data;
      if(dir==1)
     {  t=t->next;
     }
     else
     {
      t=t->prev;
     }
    }
}
Node * getEndNode(Node *h1)
{
	Node *t=h1;
	
	while(t->next!=NULL)
	t=t->next;
	
	return(t);	
}
int bin2Decimal(Node *h)
{ int data=0;
  int base=1; //2^0
  Node *t=getEndNode(h);
  while(t!=NULL)
  {
  	data=data + (t->data*base);
    cout<<"\nB:"<<data;
    base=base*2;
    t=t->prev;
  }
  return(data);
}
Node * createBinList(int d)
{
	Node *head1, *end1;
	int bit;
	bit=d%2;
	cout<<bit<<"\n";
	d=d/2;
	head1=createNode(bit);
	cout<<"Head :"<<head1<<"\nData :"<<head1->data<<"\n";
	end1=head1;
	while(d>0)
	{
	bit=d%2;
	head1=append(head1,bit,0); 
	d=d/2;
	cout<<bit<<"\n";
	}
	return(head1);
}



Node * addBinList(Node *h1, Node *h2){
		int d1=bin2Decimal(h1);
		int d2=bin2Decimal(h2);
		cout<<"D1:"<<d1+d2;
		h1=createBinList(d1+d2);
	
	return(h1);
}
	


using namespace std;
int main(){
	Node *head1, *end1;
	Node *head2, *end2;
	Node *h3;
	int n1,n2,n3;
	cout<<"Enter Two nos:";
	cin>>n1>>n2;
	head1=createBinList(n1);
	head2=createBinList(n2);
	cout<<"DATA:"<<head1->data;
	h3=addBinList(head1,head2);
	cout<<"\nHead1 data:";
	printList(head1,1);
	cout<<"\nHead2 data:";
	printList(head2,1);
	cout<<"\nAddition:";
	printList(h3,1);
	
	return(0);
}
