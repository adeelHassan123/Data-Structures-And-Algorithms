#include <iostream>
#include <string>
using namespace std;

const int MAX = 3;  

class Patient {
public:
    int id;
    string name;

    Patient() {}
    Patient(int id, string name) : id(id), name(name) {}
};

class Queue {
private:
    Patient patients[MAX];  
    int front, rear;        
    int nextId;             
    int count;              

public:
    Queue() : front(0),rear(-1),nextId(1),count(0){}

    void RegisterPatient(string naming) {
        if (isFull()) {
            cout << endl << "======================================" << endl;
            cout << "Queue is full. Cannot register more patients.\n";
            cout << "======================================" << endl;
            return;
        }

        rear = (rear + 1) % MAX;
        patients[rear].id = nextId++;
        patients[rear].name = naming;
        count++;  

        cout << endl << "======================================" << endl;
        cout << "Patient registered: ID = " << patients[rear].id << ", Name: " << patients[rear].name << "\n";
        cout << "======================================" << endl;
    }

    void ServePatient() {
        if (isEmpty()) {
            cout << endl << "======================================" << endl;
            cout << "No patients to serve.\n";
            cout << "======================================" << endl;
            return;
        }

        cout << endl << "======================================" << endl;
        cout << "Serving patient: ID = " << patients[front].id << ", Name: " << patients[front].name << "\n";
        cout << "======================================" << endl;

        front = (front + 1) % MAX;
        count--;  
    }

    void CancelAll() {
        front = 0;
        rear = -1;
        count = 0;
        cout << endl << "======================================" << endl;
        cout << "All appointments canceled.\n";
        cout << "======================================" << endl;
    }

    bool CanDoctorGoHome() {
        return isEmpty();
    }

    void ShowAllPatient() {
        if (isEmpty()) {
            cout << endl << "======================================" << endl;
            cout << "No patients in the queue.\n";
            cout << "======================================" << endl;
            return;
        }

        cout << endl << "======================================" << endl;

        Patient temp[MAX];
        for (int i = 0; i < count; i++) {
        int index = (front + i) % MAX;
        temp[i] = patients[index]; 
        }
        
        bubbleSortByName(temp, count);

        cout << "List of patients:\n";
        for (int i = 0; i < count; i++) {
            int index = (front + i) % MAX;  
            cout << "ID = " << temp[index].id << ", Name: " << temp[index].name << "\n";
        }
        cout << "======================================" << endl;
    }

    void bubbleSortByName(Patient arr[], int n) {
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j].name > arr[j + 1].name) 
            {
                Patient temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == MAX;
    }
};

int main() {
    Queue hospitalQueue;
    int choice;
    string name;

    do {
        cout << endl << "#############################" << endl;
        cout << "1-> Register Patient\n";
        cout << "2-> Serve Patient\n";
        cout << "3-> Cancel All Appointments\n";
        cout << "4-> Can Doctor Go Home?\n";
        cout << "5-> Show All Patients\n";
        cout << "6-> Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 6) {
            switch (choice) {
                case 1:
                    cout << "Enter patient's name: ";
                    cin.ignore();
                    getline(cin, name);
                    hospitalQueue.RegisterPatient(name);
                    break;
                case 2:
                    hospitalQueue.ServePatient();
                    break;
                case 3:
                    hospitalQueue.CancelAll();
                    break;
                case 4:
                    if (hospitalQueue.CanDoctorGoHome())
                        cout << "No patients waiting. Doctor can go home.\n";
                    else
                        cout << "Patients are still waiting. Doctor cannot go home yet.\n";
                    break;
                case 5:
                    hospitalQueue.ShowAllPatient();
                    break;
                case 6:
                    cout << "Exiting...\n";
                    break;
                default:
                    break;
            }
        } else {
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}
