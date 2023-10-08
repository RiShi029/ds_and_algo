#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int d)
    {
        this->data=d;
        this->next=NULL;
    }

};

void insertAtTail(Node* &tail,int d)
{
    Node* temp=new Node(d);
    tail->next=temp;
    tail=temp;
}
void print(Node* &tail)
{
    Node* temp=tail;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverse(Node* &head,Node *curr,Node *prev)
{
    if(curr==NULL)
    {
        head=prev;
        return;
    }

    Node *forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}
// Recursive approach
Node* reverseLinkedList(Node *head) 
{
    Node* curr=head;
    Node* prev=NULL;
    reverse(head,curr,prev);
    return head;
}

// Iterative approach
Node* reverseList(Node* head) {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    Node* prev=NULL;
    Node* curr=head;
    Node* forward=NULL;

    while(curr!=NULL)
    {
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }

    return prev;
}

int main()
{
    Node* node=new Node(1);
    Node* head=node;
    Node* tail=node;
    insertAtTail(tail,2);
    insertAtTail(tail,3);
    insertAtTail(tail,4);
    insertAtTail(tail,5);
    print(head);
    cout<<endl;

    // Node* rev=reverseList(head);
    // print(rev);

    Node* reverse=reverseLinkedList(head);
    print(reverse);

}
