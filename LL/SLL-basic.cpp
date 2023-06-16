#include<iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    
    Node(int newdata)
    {
        this->data = newdata;
        this->next = NULL;
    }
    
};

void PrintList(Node* head)
{
    if(head==NULL)
    {
        cout<<"==> List is empty\n";
        return;
    }

    Node* temp = head;

    while(temp!=NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

void InsertNodeFront(int givedata, Node* &head)
{
    Node* newnode = new Node(givedata);

    newnode->next = head;

    head = newnode;
}

void InsertNodeEnd(int givedata, Node* &head)
{
    Node* newnode = new Node(givedata);


    if (head==NULL)
    {
        head = newnode;
        return;
    }

    Node* temp = head;

    while(temp->next!=NULL)
    {
        // cout<<temp->data<<endl;
        temp = temp->next;
    }

    temp->next = newnode;
    // newnode->next = NULL;
}

void InsertNodePosition(int givedata,int position,Node* &head)
{
    position = position-2;

    if(head==NULL)
    {
        cout<<"Use something else\n";
        return;
    }

    Node* temp = head;
    int i = 0;

    while(position && temp->next != NULL)
    {
        temp = temp->next;

        i++;
        position--;
    }

    if(i!=position)
    {
        cout<<"==> Position is out of LL"<<endl;
        return;
    }

    Node* newnode = new Node(givedata);

    if(temp->next == NULL)
    {
        temp->next = newnode;
        return;
    }

    else if(temp->next != NULL)
    {
        Node* tempnext = temp->next;

        temp->next = newnode;
        newnode->next = tempnext;
    }
}

int main()
{
    Node* head = NULL;

    // InsertNodeFront(3,head);
    // InsertNodeFront(2,head);
    // InsertNodeFront(1,head);

    InsertNodeEnd(3,head);
    InsertNodeEnd(2,head);
    InsertNodeEnd(1,head);

    // delete(head);


    InsertNodePosition(69,1,head);


    PrintList(head);
}