#include<iostream>
using namespace std;
class Node {
public:
    int data;    
    char status; 
    Node* next;
    Node *prev;
};
Node* createNode(int data)
{
  Node *t;
  t=new Node();  
  t->data=data;  
  t->status='A'; 
  t->next=NULL; 
  t->prev=NULL;  
  return(t);
}
Node* append(Node *e,int data)
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
void printList(Node *h,int dir,int col,int status=0)
{
    Node *t;
    t=h; 
    cout<<"\n------LIST SeatNo(Status)----\n";
    int count=0;
    while(t!=NULL) 
    {
      
      if(count%col==0)
      cout<<"\n";
      if(status==0)
      cout<<"\t "<<t->data<<"("<<t->status<<")";
      if(status==1)
      cout<<"\t "<<t->status;
      count++;
      if(dir==1)
     {  t=t->next;
     }
     else
     {
      t=t->prev; 
     }
    }
}
void Book(Node *head,int seatNo,int book=0)
{
  Node *h;
  h=head;
  int flag=0;
  while(h!=NULL) 
  {
    if((h->data==seatNo) )
    {
      if((book==0)&&(h->status=='A'))
      { h->status='B';
      cout<<"\n Seat Reservation Success";
      flag=1;
      break;
      }
    if((book==1)&&(h->status=='B'))
        { h->status='A';
          flag=1;
        cout<<"\n Booking Cancelled SeatNo:"<<h->data;
        break;
        }
    if(flag==0)
      cout<<"\nSeat Booking/Cancellation failed Check status";
    }
    h=h->next;
  }
   if(flag==0)
      cout<<"\nOperation Not Successful";
}

int main()
{
  Node *head,*end;
  int tnode=70; 
  int nosCol=7;
  head=createNode(1); 
  end=head;
   for(int i=2;i<=tnode;i++)
  {
    end=append(end,i);
  } 
  Book(head,50); 
  Book(head,57);
  printList(head,1,nosCol);
  Book(head,64,0); 
  printList(head,1,nosCol);
  cout<<"\nAnother call";
  Book(head,64,1);  
  printList(head,1,nosCol);
  return 0;
}
