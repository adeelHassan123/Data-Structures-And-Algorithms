// #include<iostream>
// using namespace std;

// class node{
//     public:
//     int data;
//     node* next;
//     public: 
//     node(int data)
//     {
//         this->data=data;
//         this->next=nullptr;
//     }
// };

// class LinkList{ 
//     public:
//     void insertAtHead(node* &head,int data)
//     {
//         node* new_node=new node(data);
//         new_node->next=head;
//         head=new_node;
//     }

//     void insertAtLocation(node* &head,int location,int data)
//     {
       

//         if(head->next==NULL)
//         {
//             insertatTail(head,data);
//         }
//          node* new_node=new node(data);
//         node* temp=head;
//         for(int i=1;i<location-1;i++)
//         {
//             temp=temp->next;
//         }
//         new_node->next=temp->next;
//         temp->next=new_node;

//     }
//     void insertatTail(node* &head,int data)
//     {
//         node* new_node=new node(data);
//         node* temp=head;
//         while(temp->next!=NULL)
//         {
//             temp=temp->next;
//         }
//         temp->next=new_node;    
//     }

//     void deleteNode(node* & head,int location)
//     {
//         if (head == NULL) {
//         cout << "List is empty, nothing to delete." << endl;
//         return;
//         }
//         if (location == 1) {
//         node* temp = head;
//         head = head->next;
//         delete temp;
//         return;
//         }
        
//         node* temp = head;
//         for (int i = 1; i < location - 1; i++) {
//         if (temp->next == NULL) {
//             cout << "Position out of bounds." << endl;
//             return;
//         }
//         temp = temp->next;
//         }

//     node* nodeToDelete = temp->next;
//     if (nodeToDelete == NULL) {
//         cout << "Position out of bounds." << endl;
//         return;
//     }

//     temp->next = nodeToDelete->next;
//     delete nodeToDelete; 

//     }

//     int count_node(node* head)
//     {
//         node* temp=head;
//         int count=0;
//         while(temp!=NULL)
//         {
//             count++;
//         }
//         return count;

//     }

//     void printLinkList(node* &head)
//     {
//         node* temp=head;
//         cout<<"==================================="<<endl;
//         while(temp!=NULL)
//         {
//             cout<<temp->data<<" "<< endl;
//             temp=temp->next;
//         }
//         cout<<"==================================="<<endl;
//     } 
// };

// int main()
// {
//     LinkList* L1=new LinkList;

//     node* n1=new node(03);
//     node* L1_head=n1;

//     for(int i=1;i<=20;i++)
//     {
//         L1->insertatTail(L1_head,i);
//     }
    
//     cout<< " Link List number 1 : " <<endl;
//     L1->printLinkList(L1_head);

   
//     L1->deleteNode(L1_head,16);
    

//     cout<< " Link List number 1 After deleting: " <<endl;
//     L1->printLinkList(L1_head);


// }

#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    public: 
    node(int data)
    {
        this->data=data;
        this->next=nullptr;
    }
};

class LinkList{ 
    public:
    void insertAtHead(node* &head, int data)
    {
        node* new_node = new node(data);
        new_node->next = head;
        head = new_node;
    }


    void insertAtLocation(node* &head, int location, int data)
    {
        if(head->next == NULL)
        {
            insertAtTail(head, data);
            return;
        }
        node* new_node = new node(data);
        node* temp = head;
        for(int i = 1; i < location - 1; i++)
        {
            temp = temp->next;
        }
        new_node->next = temp->next;
        temp->next = new_node;
    }


    void insertAtTail(node* &head, int data)
    {
        node* new_node = new node(data);
        node* temp = head;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;    
    }


    void deleteNode(node* & head, int location)
    {
        if (head == NULL) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        if (location == 1) {
            node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        node* temp = head;
        for (int i = 1; i < location - 1; i++) {
            if (temp->next == NULL) {
                cout << "Position out of bounds." << endl;
                return;
            }
            temp = temp->next;
        }

        node* nodeToDelete = temp->next;
        if (nodeToDelete == NULL) {
            cout << "Position out of bounds." << endl;
            return;
        }

        temp->next = nodeToDelete->next;
        delete nodeToDelete; 
    }

    
    int countNode(node* head)
    {
        node* temp = head;
        int count = 0;
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }

    void printLinkList(node* &head)
    {
        node* temp = head;
        cout << "===================================" << endl;
        while(temp != NULL)
        {
            cout << temp->data << " " << endl;
            temp = temp->next;
        }
        cout << "===================================" << endl;
    }

    node* concatenate(node* &list1, node* &list2)
    {
        if(list1 == NULL) return list2;
        if(list2 == NULL) return list1; 

        node* temp = list1;
        while(temp->next != NULL) 
        {
            temp = temp->next;
        }
        temp->next = list2;
        return list1;
    }
};

void displayMenu()
{
    cout << "\n---- Menu ----" << endl;
    cout << "1. Insert at Head" << endl;
    cout << "2. Insert at Tail" << endl;
    cout << "3. Insert at Location" << endl;
    cout << "4. Delete Node" << endl;
    cout << "5. Print List" << endl;
    cout << "6. Concatenate Two Lists" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    LinkList* L1 = new LinkList;
    int numLists, choice, data, location;
    
    cout << "How many linked lists do you want to create? ";
    cin >> numLists;

    LinkList** lists = new LinkList*[numLists]; 
    node** heads = new node*[numLists]; 
    
    for(int i = 0; i < numLists; i++) {
        lists[i] = new LinkList();
        heads[i] = NULL;
    }

    bool running = true;
    while(running)
    {
        displayMenu();
        cin >> choice;
        switch(choice)
        {
            case 1:
                // Insert at Head
                cout << "Enter the list number (1 to " << numLists << "): ";
                cin >> location;
                cout << "Enter data: ";
                cin >> data;
                lists[location-1]->insertAtHead(heads[location-1], data);
                break;
            
            case 2:
                // Insert at Tail
                cout << "Enter the list number (1 to " << numLists << "): ";
                cin >> location;
                cout << "Enter data: ";
                cin >> data;
                lists[location-1]->insertAtTail(heads[location-1], data);
                break;

            case 3:
                // Insert at Location
                cout << "Enter the list number (1 to " << numLists << "): ";
                cin >> location;
                cout << "Enter the position: ";
                int pos;
                cin >> pos;
                cout << "Enter data: ";
                cin >> data;
                lists[location-1]->insertAtLocation(heads[location-1], pos, data);
                break;

            case 4:
                // Delete Node
                cout << "Enter the list number (1 to " << numLists << "): ";
                cin >> location;
                cout << "Enter the position to delete: ";
                cin >> pos;
                lists[location-1]->deleteNode(heads[location-1], pos);
                break;

            case 5:
                // Print List
                cout << "Enter the list number (1 to " << numLists << "): ";
                cin >> location;
                lists[location-1]->printLinkList(heads[location-1]);
                break;

            case 6:
                // Concatenate Two Lists
                int list1, list2;
                cout << "Enter the first list number (1 to " << numLists << "): ";
                cin >> list1;
                cout << "Enter the second list number (1 to " << numLists << "): ";
                cin >> list2;
                heads[list1-1] = lists[list1-1]->concatenate(heads[list1-1], heads[list2-1]);
                cout << "Concatenated Link List: " << endl;
                lists[list1-1]->printLinkList(heads[list1-1]);
                break;

            case 7:
                // Exit
                running = false;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }


    for(int i = 0; i < numLists; i++) {
        delete lists[i];
    }
    delete[] lists;
    delete[] heads;

    return 0;
}
