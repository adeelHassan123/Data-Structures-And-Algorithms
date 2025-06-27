#include <iostream>
#include <chrono>

using namespace std;

class node {
public:
    int data;
    node* next;
    node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

class LinkList {
public:
    void insertAtHead(node*& head, int data) {
        node* new_node = new node(data);
        new_node->next = head;
        head = new_node;
    }

    void insertAtLocation(node*& head, int location, int data) {
        if (head == nullptr || location == 1) {
            insertAtHead(head, data);
            return;
        }
        node* temp = head;
        for (int i = 1; i < location - 1 && temp->next != nullptr; i++) {
            temp = temp->next;
        }
        node* new_node = new node(data);
        new_node->next = temp->next;
        temp->next = new_node;
    }

    void insertAtTail(node*& head, int data) {
        node* new_node = new node(data);
        if (head == nullptr) {
            head = new_node;
            return;
        }
        node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = new_node;
    }

    void deleteFromBeginning(node*& head) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteFromEnd(node*& head) {
        if (head == nullptr) {
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        if (head->next == nullptr) {
            node* temp = head;
            head = head->next;
            delete temp;
        }

        node* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
    }

    int search(node* head, int value) {
        node* temp = head;
        int index = 1;
        while (temp != nullptr) {
            if (temp->data == value) {
                return index;
            }
            temp = temp->next;
            index++;
        }
        return -1;
    }

    void printLinkList(node*& head) {
        node* temp = head;
        cout << "===================================" << endl;
        while (temp != nullptr) {
            cout << temp->data << " " << endl;
            temp = temp->next;
        }
        cout << "===================================" << endl;
    }

};


int main() {

    while(1)
    {

    node* n1=new node(0);
    node* head=n1;

    int n;
    cout<<"Enter value of n: "<<endl;
    cin>>n;


    LinkList list;

    for(int i=0;i<n;i++)
    {
        list.insertAtTail(head,i+1);
    }
    
    auto total_start = chrono::high_resolution_clock::now();
    
    auto start = chrono::high_resolution_clock::now();
    list.insertAtHead(head,99);
    auto end = chrono::high_resolution_clock::now();
    cout << "Insertion at beginning: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    list.insertAtTail(head,99);
    end = chrono::high_resolution_clock::now();
    cout << "Insertion at end: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    int pos = list.search(head,20);
    end = chrono::high_resolution_clock::now();
    cout << "Search for element: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    list.deleteFromBeginning(head);
    end = chrono::high_resolution_clock::now();
    cout << "Deletion from beginning: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;

    start = chrono::high_resolution_clock::now();
    list.deleteFromEnd(head);
    end = chrono::high_resolution_clock::now();
    cout << "Deletion from end: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
    
    auto total_end = chrono::high_resolution_clock::now();
    cout << "Total time for all operations: " << chrono::duration_cast<chrono::nanoseconds>(total_end - total_start).count() << " ns" << endl;

    cout<<endl<<endl;
    }
    return 0;
    // LinkList* L1 = new LinkList;
    // int numLists, choice, data, location, value;

    // cout << "How many linked lists do you want to create? ";
    // cin >> numLists;

    // LinkList** lists = new LinkList * [numLists];
    // node** heads = new node * [numLists];

    // for (int i = 0; i < numLists; i++) {
    //     lists[i] = new LinkList();
    //     heads[i] = nullptr;
    // }

    // bool running = true;
    // while (running) {
    //     displayMenu();
    //     cin >> choice;
    //     switch (choice) {
    //     case 1:
    //         // Insert at Head
    //         cout << "Enter the list number (1 to " << numLists << "): ";
    //         cin >> location;
    //         cout << "Enter data: ";
    //         cin >> data;
    //         lists[location - 1]->insertAtHead(heads[location - 1], data);
    //         break;

    //     case 2:
    //         // Insert at Tail
    //         cout << "Enter the list number (1 to " << numLists << "): ";
    //         cin >> location;
    //         cout << "Enter data: ";
    //         cin >> data;
    //         lists[location - 1]->insertAtTail(heads[location - 1], data);
    //         break;

    //     case 3:
    //         // Insert at Location
    //         cout << "Enter the list number (1 to " << numLists << "): ";
    //         cin >> location;
    //         cout << "Enter the position: ";
    //         int pos;
    //         cin >> pos;
    //         cout << "Enter data: ";
    //         cin >> data;
    //         lists[location - 1]->insertAtLocation(heads[location - 1], pos, data);
    //         break;

    //     case 4:
    //         // Delete from Beginning
    //         cout << "Enter the list number (1 to " << numLists << "): ";
    //         cin >> location;
    //         {
    //             auto start = chrono::high_resolution_clock::now();
    //             lists[location - 1]->deleteFromBeginning(heads[location - 1]);
    //             auto end = chrono::high_resolution_clock::now();
    //             cout << "Time taken for deletion from beginning: " 
    //                  << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
    //         }
    //         break;

    //     case 5:
    //         // Delete from End
    //         cout << "Enter the list number (1 to " << numLists << "): ";
    //         cin >> location;
    //         {
    //             auto start = chrono::high_resolution_clock::now();
    //             lists[location - 1]->deleteFromEnd(heads[location - 1]);
    //             auto end = chrono::high_resolution_clock::now();
    //             cout << "Time taken for deletion from end: " 
    //                  << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
    //         }
    //         break;

    //     case 6:
    //         // Search by Value
    //         cout << "Enter the list number (1 to " << numLists << "): ";
    //         cin >> location;
    //         cout << "Enter the value to search: ";
    //         cin >> value;
    //         {
    //             auto start = chrono::high_resolution_clock::now();
    //             int result = lists[location - 1]->search(heads[location - 1], value);
    //             auto end = chrono::high_resolution_clock::now();
    //             cout << "Time taken for search: " 
    //                  << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
    //             if (result != -1)
    //                 cout << "Value found at position " << result << endl;
    //             else
    //                 cout << "Value not found in the list" << endl;
    //         }
    //         break;

    //     case 7:
    //         // Print List
    //         cout << "Enter the list number (1 to " << numLists << "): ";
    //         cin >> location;
    //         lists[location - 1]->printLinkList(heads[location - 1]);
    //         break;

    //     case 8:
    //         // Concatenate Two Lists
    //         int list1, list2;
    //         cout << "Enter the first list number (1 to " << numLists << "): ";
    //         cin >> list1;
    //         cout << "Enter the second list number (1 to " << numLists << "): ";
    //         cin >> list2;
    //         heads[list1 - 1] = lists[list1 - 1]->concatenate(heads[list1 - 1], heads[list2 - 1]);
    //         cout << "Concatenated Link List: " << endl;
    //         lists[list1 - 1]->printLinkList(heads[list1 - 1]);
    //         break;

    //     case 9:
    //         // Exit
    //         running = false;
    //         break;

    //     default:
    //         cout << "Invalid choice. Please try again." << endl;
    //     }
    // }

    // for (int i = 0; i < numLists; i++) {
    //     delete lists[i];
    // }
    // delete[] lists;
    // delete[] heads;

    // return 0;
}
