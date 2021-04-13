#include"linkedlist.h"

linkedList mylist;

void clear();
void addition(int option);
void deletion(int option);
void display(int option);
void find();

int main()
{
    mylist.append(1);
    // mylist.append(2);
    // mylist.append(3);
    // mylist.append(4);
    // mylist.append(5);

    while(1)
    {
        clear();
        int operation;

        cout<<string(119,'#')<<endl;
        cout<<string(45,'#')<<"    DOUBLY LINKED LIST    "<<string(45,'#')<<endl;
        cout<<string(119,'#')<<endl;

        cout<<string(3,'\n');
        cout<<"CHOSSE OPERATION:"<<endl;
        cout<<"\t\t 1 ---------- INSERTION IN LIST"<<endl;
        cout<<"\t\t 2 ---------- DELETION FROM LIST"<<endl;
        cout<<"\t\t 3 ---------- DISPLAY THE LIST"<<endl;
        cout<<"\t\t 4 ---------- FIND DATA IN LIST"<<endl;
        cout<<"\t\t 5 ---------- SHOW SIZE OF LIST"<<endl;
        cout<<"\t\t 6 ---------- EXIT PROGRAM"<<endl;
        cin>>operation;

        switch (operation)
        {
            int option;
        case 1: cout<<string(3,'\n');
                cout<<string(50,'#')<<"    INSERTION IN LINKED LIST    "<<string(50,'#')<<endl;
                cout<<string(3,'\n');
                cout<<"CHOSSE OPERATION:"<<endl;
                cout<<"\t\t 1 ---------- INSERTION IN BEGGINING OF LIST"<<endl;
                cout<<"\t\t 2 ---------- INSERTION IN ENDING OF LIST"<<endl;
                cout<<"\t\t 3 ---------- INSERTION IN BETWEEN OF LIST"<<endl;
                cin>>option;
                addition(option);
            break;
        case 2: cout<<string(3,'\n');
                cout<<string(50,'#')<<"    DELETION IN LINKED LIST    "<<string(50,'#')<<endl;
                cout<<string(3,'\n');
                cout<<"CHOSSE OPERATION:"<<endl;
                cout<<"\t\t 1 ---------- DELETION FROM BEGGINING OF LIST"<<endl;
                cout<<"\t\t 2 ---------- DELETION FROM ENDING OF LIST"<<endl;
                cout<<"\t\t 3 ---------- DELETION FROM IN BETWEEN OF LIST"<<endl;
                cin>>option;
                deletion(option);
            break;
        case 3: cout<<string(3,'\n');
                cout<<string(50,'#')<<"   DISPLAY LINKED LIST    "<<string(50,'#')<<endl;
                cout<<string(3,'\n');
                cout<<"CHOSSE OPERATION:"<<endl;
                cout<<"\t\t 1 ---------- DISPLAY WHOLE LIST"<<endl;
                cout<<"\t\t 2 ---------- DISPLAY DATA AT CERTAIN POSITION"<<endl;
                cin>>option;
                display(option);
            break;
        case 4: cout<<string(3,'\n');
                cout<<string(50,'#')<<"   FIND DATA IN LINKED LIST    "<<string(50,'#')<<endl;
                cout<<string(3,'\n');
                find();
            break;
        case 5: cout<<string(3,'\n');
                cout<<string(50,'#')<<"   SHOW SIZE OF LIST    "<<string(50,'#')<<endl;
                cout<<string(3,'\n');
                cout<<" SIZE IS "<<mylist.getsize();
            break;
        case 6: return 0;
            break;
        
        default: cout<<"wrong Operation choosen, try again";
            break;
        }
    }

    return 0;
}

void clear()
{
    cout<<string(10,'\n');
}

void addition(int option)
{
    int data;
    switch (option)
    {
    case 1: cout<<string(3,'\n');
            cout<<string(50,'#')<<"    INSERTION IN BEGGINING OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter data to be inserted"<<endl;
            cin>>data;
            mylist.prepend(data);
        break;
    case 2: cout<<string(3,'\n');
            cout<<string(50,'#')<<"    INSERTION IN ENDING OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter data to be inserted"<<endl;
            cin>>data;
            mylist.append(data);
        break;
    case 3: int pos;
            cout<<string(3,'\n');
            cout<<string(50,'#')<<"    INSERTION IN BETWEEN OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter data to be inserted and position of data to be inserted"<<endl;
            cin>>data>>pos;
            mylist.addatpos(data,pos);
        break;
    default: cout<<"WRONG OPTION";
        break;
    }
}

void deletion(int option)
{
    switch (option)
    {
    case 1: cout<<string(3,'\n');
            cout<<string(50,'#')<<"   DELETION FROM BEGGINING OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            mylist.removefirst();
        break;
    case 2: cout<<string(3,'\n');
            cout<<string(50,'#')<<"    DELETION FROM ENDING OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            mylist.removelast();
        break;
    case 3: int pos;
            cout<<string(3,'\n');
            cout<<string(50,'#')<<"    DELETION FROM IN BETWEEN OF LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter position from where data to be removed"<<endl;
            cin>>pos;
            mylist.removePos(pos);
        break;
    default: cout<<"WRONG OPTION";
        break;
    }
}
void display(int option)
{
    switch (option)
    {
    case 1: cout<<string(3,'\n');
            cout<<string(50,'#')<<"   DISPLAY WHOLE LIST  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            mylist.displaylist();
        break;
    case 2: int pos;
            cout<<string(3,'\n');
            cout<<string(50,'#')<<"   DISPLAY DATA AT CERTAIN POSITION  "<<string(50,'#')<<endl;
            cout<<string(3,'\n');
            cout<<"Enter position to display"<<endl;
            cin>>pos;
            mylist.displaypos(pos);
        break;
    default: cout<<"WRONG OPTION";
        break;
    }
}
void find()
{
    int data;
    cout<<"Enter data to be found"<<endl;
    cin>>data;
    mylist.finddata(data);
}