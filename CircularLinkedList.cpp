#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Function to insert a node at the end of the list
void insert(Node** head, int data) {
    Node* newNode = new Node();
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        *head = newNode;
    } else {
        Node* last = (*head)->prev;
        
        newNode->next = *head;
        newNode->prev = last;
        
        last->next = newNode;
        (*head)->prev = newNode;
    }
}

// Function to delete a node from the list
void deleteNode(Node** head, int key) {
    if (*head == NULL) return;

    Node* temp = *head;
    Node* toDelete = NULL;

    // Traverse to find the node with the given key
    do {
        if (temp->data == key) {
            toDelete = temp;
            break;
        }
        temp = temp->next;
    } while (temp != *head);

    if (toDelete == NULL) return; // Node with the given key not found

    // If only one node exists
    if (toDelete->next == toDelete && toDelete->prev == toDelete) {
        *head = NULL;
        delete toDelete;
        return;
    }

    // If the node to be deleted is the head
    if (toDelete == *head) {
        (*head)->prev->next = (*head)->next;
        (*head)->next->prev = (*head)->prev;
        *head = (*head)->next;
    } else {
        // If the node to delete is in between or at the end
        toDelete->prev->next = toDelete->next;
        toDelete->next->prev = toDelete->prev;
    }
    
    delete toDelete;
}

// Function to display the list in forward direction
void displayForward(Node* head) {
    if (head == NULL) return;

    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Function to display the list in reverse direction
void displayBackward(Node* head) {
    if (head == NULL) return;

    Node* last = head->prev;
    Node* temp = last;
    do {
        cout << temp->data << " ";
        temp = temp->prev;
    } while (temp != last);
    cout << endl;
}

// Main function to test the Circular Doubly Linked List
int main() {
    Node* head = NULL;

    // Insert nodes into the circular doubly linked list
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    cout << "Circular Doubly Linked List (Forward): ";
    displayForward(head);

    cout << "Circular Doubly Linked List (Backward): ";
    displayBackward(head);

    // Delete a node
    deleteNode(&head, 20);
    cout << "After deleting 20 (Forward): ";
    displayForward(head);

    cout << "After deleting 20 (Backward): ";
    displayBackward(head);

    return 0;
}
