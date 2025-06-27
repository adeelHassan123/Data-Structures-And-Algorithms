// #include <iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node* next;

//     node(int value){
//         data=value;
//         next=NULL;
//     }
// };

// class LinkList{
//     private: 
//     node* head;

//     public: 
//     LinkList(){
//         head=NULL;
//     }

//     void insertAtHead(int value)
//     {
//         node* newNode=new node(value);
//         newNode->next=head;
//         head=newNode;

//     }

// };

// int main(){
//     LinkList list;  
//     list.insertAtHead(10);
//     list.insertAtHead(20);
//     list.insertAtHead(30);

//     return 0;

// }


#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};
class LinkList{
    public:
    void insertathead(Node*& head,int data)
    {
        Node* newNode=new  Node(data);
        newNode->next = head;
        head=newNode;
    }
    void printLL(Node*& head)
    {
        Node* temp=head;
        while(temp!=nullptr)
        {
            cout <<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    void insertatLoc(Node*& head,int data,int loc)
    {
        Node* newNode=new Node(data);
        if(loc==1) insertathead(head,data);
        Node* temp=head;
        int count=1;
        while(temp != nullptr && count < loc - 1)
        {
            temp=temp->next;
            count++;
        }
        if(temp==nullptr) return;
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void deleteNode(Node*& head,int data)    
    {
        if(head==nullptr)
        {
            return;
        }
        Node* temp=head;
        while(temp!=nullptr && temp->data!=data)
        {
            temp=temp->next;
        }
        delete temp;
    }
};
int main()
{
    Node* head=new Node(5);
    LinkList* LL = new LinkList();
    LL->insertathead(head,6);
    LL->insertathead(head,8);
    LL->insertathead(head,9);
    LL->printLL(head);
    LL->insertatLoc(head,7,3);
    LL->printLL(head);
}