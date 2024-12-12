#include<iostream>
using namespace std;
class node {
public:
    int data;
    char status;
    node* next;
    node* prev;
};
node* createNode(int data)
{
    node* t;
    t = new node();
    t->data = data;
    t->status = 'A';
    t->next = NULL;
    t->prev = NULL;
    return(t);
}
node* append(node* e, int data)
{
    node* t, * h;
    t = createNode(data);
    h = e;
    h->next = t;
    t->prev = h;
    e = t;
    e->next = NULL;
    return(e);
}
void printList(node* h, int dir, int col, int status = 0)
{
    node* t;
    t = h;
    cout << "\n------LIST SeatNo(Status)----\n";
    int count = 0;
    while (t != NULL)
    {
        if (count % col == 0)
            cout << "\n";
        if (status == 0)
            cout << "\t " << t->data << "(" << t->status << ")";
        if (status == 1)
            cout << "\t " << t->status;
        count++;
        if (dir == 1)
        {  
            t = t->next;
        }
        else
        {
            t = t->prev;
        }
    }
}
void Book(node* head, int seatNo, int book = 0)
{
    node* h;
    h = head;
    int flag = 0;
    while (h != NULL)
    {
        if ((h->data == seatNo))
        {
            if ((book == 0) && (h->status == 'A'))
            {
                h->status = 'B';
                cout << "\n Seat Reservation Success";
                flag = 1;
                break;
            }
            if ((book == 1) && (h->status == 'B'))
            {
                h->status = 'A';
                flag = 1;
                cout << "\n Booking Cancelled SeatNo:" << h->data;
                break;
            }
            if (flag == 0)
                cout << "\nSeat Booking/Cancellation failed Check status";
        }
        h = h->next;
    }
    if (flag == 0)
        cout << "\nOperation Not Successful";
}

int main()
{
    node* head, * end;
    int tnode = 70;
    int nosCol = 7;
    head = createNode(1);
    end = head;
    for (int i = 2; i <= tnode; i++)
    {
        end = append(end, i);
    }

    int choice = 0, seatNo = 0, book = 0;
    
    while (true) {
        cout << "\nMenu:";
        cout << "\n1. Reserve Seat";
        cout << "\n2. Cancel Reservation";
        cout << "\n3. Show Seat Status";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "\nEnter seat number to reserve: ";
            cin >> seatNo;
            book = 0;  // 0 for booking
            Book(head, seatNo, book);
        }
        else if (choice == 2) {
            cout << "\nEnter seat number to cancel: ";
            cin >> seatNo;
            book = 1;  // 1 for cancelling
            Book(head, seatNo, book);
        }
        else if (choice == 3) {
            printList(head, 1, nosCol);
        }
        else if (choice == 4) {
            cout << "\nExiting program...";
            break;
        }
        else {
            cout << "\nInvalid choice, please try again.";
        }
    }

    return 0;
}
