#include<iostream>
using namespace std;
class Node {
public:
    int data;    
    Node* next;
    Node *prev;
};
Node* createNode(int data)
{
  Node *t;
  t=new Node(); 
  t->data=data;   
  t->next=NULL;  
  t->prev=NULL; 
  return(t);
}
int deque(Node **f)
{
  if(*f==NULL)
  {
    cout<<"\n QEmpty:\n";
    return(-1);
  }
  Node *t;
  t=*f;
  *f=t->next;
  int t1=t->data;
  cout<<"\ndeleting:"<<t1<<"\n";
  delete(t);
  return(t1);
}
int dequeR(Node *e)
{
  if(e==NULL)
  {
    cout<<"\n QEmpty:\n";
    return(-1);
  }
  Node *t;
  t=e;
  e=t->prev;
  int t1=t->data;
  cout<<"\n Rear deleting:"<<t1<<"\n";
  delete(t);
  return(t1);
}
Node* enqueue(Node *e,int data)
{
  Node *t,*h;
  t=createNode(data); 
  h=e;
  h->next=t;
  t->prev=h;
  e=t;
  e->next=NULL;
  return (e);
}
Node* enqueueF(Node *f,int data)
{
  Node *t,*h;
  t=createNode(data);
  t->next=f;
  t->prev=NULL;
  f=t;
  cout<<"Node inserted at Head: "<<data;
  return (f);
}
void printQ(Node *h,int dir)
{
    Node *t;
    t=h;
    cout<<"\n------Queue Content----\n";
    while(t!=NULL) 
    {
      
     cout<<"\n "<<t->data; 
      if(dir==1)
     {  t=t->next;
     }
     else
     {
      t=t->prev;
     }
    }
}
int main()
{ 
  int arr[]={10,20,30,40,50,60};
  Node *front,*rear;
  front=createNode(arr[0]);
  rear=front;
  for(int i=1;i<6;i++)
  {
    rear=enqueue(rear,arr[i]);
  }
  front=enqueueF(front,1000);
  rear=enqueue(rear,100);
  printQ(front,1);
  cout<<"\n----Deque----";
  cout<<"\n"<<dequeR(rear);
  cout<<"\n"<<deque(&front);
  cout<<"\n"<<deque(&front);
  cout<<"\n"<<deque(&front);
  cout<<"\n"<<deque(&front);
  cout<<"\n"<<deque(&front);
  cout<<"\n"<<deque(&front);
  cout<<"\n"<<deque(&front);
  
  
  return(0);
}
