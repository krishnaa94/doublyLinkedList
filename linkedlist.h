#include <iostream> 
using namespace std;

//class define
class Node {
    public:
    int data ;
    Node *next;
    Node *prev;

    Node(int data);
};

class linkedList{
    private: 
        Node *head;
        Node *tail;
        int size;
    public:
        linkedList();
        ~linkedList();
        int getsize();    
        //insertion
        void append(int data);
        void prepend(int data);
        void addatpos(int data,int pos);
        //displayfunction
        void displaylist();
        void displaypos(int pos);
        //deletion
        void removefirst();
        void removelast();
        void removePos(int pos);
        //findFunstion
        void finddata(int data); 
};

//------------------------------------------------------ member functions -------------------------------------

//------------------------------------------------------   constructors   -------------------------------------

Node::Node(int data)
{
    this->data = data;
    next = NULL;
    prev = NULL;
}

linkedList::linkedList()
{
    head = NULL;
    tail = NULL;
    size = 0;
    cout<<"list initailised"<<endl;
}

//------------------------------------------------------   constructors   -------------------------------------
linkedList::~linkedList()
{
    Node *temp = head;
    while(temp)
    {
        temp=head->next;
        delete head;
        head=temp;
    }
    cout<<"list deleted";
}

//------------------------------------------------------ get size function -------------------------------------
int linkedList::getsize()
{
    return size;
}

//------------------------------------------------------ insertion functions -------------------------------------

void linkedList::prepend(int data)
{
    Node *n = new Node(data);
    //if list is empty
    if(head == NULL)
    {
        head = n;
        tail = n;
    }
    else 
    {
        n->next = head;
        head->prev = n;
        head = n; 
    }
    size++;
}

void linkedList::append(int data)
{
    Node *n = new Node(data);
    //if list is empty
    if(head == NULL)
    {
        head = n;
        tail = n;
    }
    else 
    {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    size++;
}

void linkedList::addatpos(int data, int pos)
{
    if(pos>size)
    {
        int desire;
        cout<<"linkedlist is to smaller than desired position"<<endl;
        cout<<"Press :\n1 ------> insert at begining \n2 -----> insert at last\n";
        cin>>desire;
        switch(desire)
        {
            case 1  : append(data);     break;
            case 2  : prepend(data);    break;
            default :                   break;
        }
    }
    else if(pos == size)
        append(data);
    else 
    {
        Node *temp = head;
        for(int i = 1; i < pos-1; i++)
            temp = temp->next;

        Node *nexttotemp = temp->next;
        Node *n = new Node(data);
        n->next = nexttotemp;
        n->prev = temp;
        temp->next = n;
        nexttotemp->prev = n;
        size++;
    }
}
//------------------------------------------------------ display functions -------------------------------------

void linkedList::displaylist()
{
    Node *temp = head;
    if(!temp)
    cout<<"List is empty"<<endl;
    while(temp!=NULL)
    {
        cout<<temp->data<<" <--> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void linkedList::displaypos(int pos)
{
    Node *temp = head;
    for (int i = 1; i < pos; i++)
            temp = temp->next;
        
    cout<<"data at "<<pos<<"th position is "<<temp->data<<endl;
}

//------------------------------------------------------ delete data -------------------------------------

 void linkedList::removefirst()
 {
    //no list
    if(head == NULL)
        cout<<"list is empty";
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        size--;
    }
    else 
    {
        head = head->next;
        delete head->prev;
        head-> prev = NULL;
        size--;
    }
 }

void linkedList::removelast()
{
    if(head == NULL)
        cout<<"list is empty";
    else if(head->next == NULL)
    {
        delete head;
        head = NULL;
        tail = NULL;
        size--;
    }
    else 
    {
        tail = tail->prev;
        delete tail->next;
        head-> next = NULL;
        size--;
    }
}

void linkedList::removePos(int pos)
{
    if(pos>size || pos<1)
        cout<<"desired position is more than the size of list"<<endl;
    else if(pos ==1)
        removefirst();
    else if(pos == size)
        removelast(); 
    else 
    {
        Node *temp = head;
        for (int i = 1; i < pos; i++)
            temp = temp->next;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        cout<<"deleteing data --> "<<temp->data<<"from"<<pos<<"position"<<endl;
        delete temp;
        size--;
    } 
}

//------------------------------------------------------   find function   -------------------------------------

void linkedList::finddata(int data)
{
    int pos = 1;
    bool found = false;
    Node *temp = head;
    while(temp)
    {   
        if(data == temp->data)
            {
                cout<<"data --> "<<data<<" is found at "<<pos<<"th postition of list";
            }
        pos++;
        temp=temp->next;
    }

    if(!found)
        cout<<"DATA NOT FOUND";
}
