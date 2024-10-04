#include <iostream>
using namespace std;

// Creating a Node
class Node {
public:
    int process_id;
    float execution_time;
    float remaining_time;

    // Pointer to point to the next Node
    Node* next;

    // Constructor
    Node(int id) {
        process_id = id;
        execution_time = 0;
        remaining_time = 0;
        next = nullptr;
    }
};

// Creation of circular linked list
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    void insertNode(int id) {
        // allocating memory for new nodes
        Node* newNode = new Node(id);

        // if new Node is the only node in list it becomes head
        if (head == nullptr) {
            head = newNode;

            // the next points to itself to make the list circular
            newNode->next = head;
        }
        else {
            Node* last = head;

            // if the list is not empty then it traverses till the last Node
            while (last->next != head) {
                last = last->next;
            }

            // inserting node at last
            last->next = newNode;

            // the next points to head if the list is circular
            newNode->next = head;
        }
    }

    void remainingTime(int process_id, float time) {
        // if list is empty then return
        Node* current = head;
        if (head == nullptr) {
            return;
        }

        // loop to check if process id is found then update the remaining time
        do {
            if (current->process_id == process_id) {
                current->remaining_time = time;
                return;
            }

            // move to the next node
            current = current->next;

            // loop continues till the head is again reached
        } while (current != head);
    }

    // function to calculate CPU's time
    void CPU_time(float fixed_time) {
        // checks if list is empty so there are no processes to schedule
        if (head == nullptr) {
            cout << "There are no processes to schedule!" << endl;
            return;
        }
        // starting from the head of the list
        Node* current = head;

        bool completed = true;

        // displaying all the processes
        cout << "Current Processes: ";
        displayProcesses();

        // a variable to keep track of no of cycles
        int cycle = 1;

        // a loop that continues until all the processes are completed
        while (true) {
            cout << "Cycle " << cycle << ":" << endl;

            // to check if there is any process that still has time to complete
            bool completion = true;


            do {
                // a condition that checks if the remaining time is zero or not
                if (current->remaining_time > 0) {
                    // At least one process is still running
                    completion = false;
                    float time;

                    // Determine how much time to run
                    if (current->remaining_time < fixed_time) {
                        time = current->remaining_time;
                    }
                    else {
                        time = fixed_time;
                    }

                    // formula to calculate remaining time
                    current->remaining_time -= time;

                    cout << "Cycle: P" << current->process_id << " (Remaining: " << current->remaining_time << ")\n";

                    // Not all processes are completed yet
                    completed = false;
                }
                current = current->next;
            } while (current != head);

           // Remove completed processes
            Node* prev = nullptr;
            current = head;

do {
    if (current->remaining_time <= 0) {
        cout << "Process ID " << current->process_id << " has completed!" << endl;
        Node* remove = current;

        if (prev == nullptr) {
            // Only one node in the list
            if (head->next == head) {
                head = nullptr;
            }
            else {
                Node* tail = head;
                while (tail->next != head) {
                    tail = tail->next;
                }
                // Update head to the next node
                head = current->next;
                tail->next = head;
            }
        }
        else {
            prev->next = current->next;
        }

        current = current->next;

        // Free memory for the removed node
        delete remove;

        // Skip the next iteration 
        continue; 
    }
    else {
        // updating nodes
        prev = current;
        current = current->next;
    }
} while (current != head);

            // Only display processes if the head is not null
            if (head != nullptr) {
                cout << "Current Processes: ";
                displayProcesses();
            }
            else {
                cout << "All processes have completed!" << endl;

                // Exiting the loop if all processes are completed
                break;
            }

            // incrementing the no of cycles
            cycle++;
        }
    }

    void displayProcesses() {
        if (head == nullptr) {
            cout << "No processes available." << endl;
            return;
        }
        Node* current = head;
        do {
            cout << "(P" << current->process_id << ", " << current->remaining_time << ") ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }

    bool process_completed() {
        if (head == nullptr) {
            return true;
        }

        Node* current = head;
        do {
            if (current->remaining_time > 0) {
                return false;
            }
            current = current->next;
        } while (current != head);

        return true;
    }
};

int main() {
    CircularLinkedList cLinkedList;

    // Inserting nodes for processes
    cLinkedList.insertNode(1);
    cLinkedList.insertNode(2);
    cLinkedList.insertNode(3);

    // remaining time for each process
    cLinkedList.remainingTime(1, 10);
    cLinkedList.remainingTime(2, 15);
    cLinkedList.remainingTime(3, 25);

    // Taking input of fixed time
    float fixed_time;
    cout << "Enter the fixed time: ";
    cin >> fixed_time;

    // Starting scheduling
    cLinkedList.CPU_time(fixed_time);
    return 0;
}
