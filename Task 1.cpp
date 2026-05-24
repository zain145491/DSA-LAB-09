#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = NULL; }

    void insertEnd(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertStart(int val) {
        Node* newNode = new Node(val);
        if (head != NULL) {
            newNode->next = head;
            head->prev = newNode;
        }
        head = newNode;
    }
    void deleteNode(int val) {
        if (head == NULL) return;
        Node* temp = head;
        while (temp != NULL && temp->data != val) temp = temp->next;
        if (temp == NULL) return;

        if (temp->prev != NULL) temp->prev->next = temp->next;
        else head = temp->next;

        if (temp->next != NULL) temp->next->prev = temp->prev;

        delete temp;
    }
    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void displayReverse() {
        if (head == NULL) return;
        Node* temp = head;
        while (temp->next != NULL) temp = temp->next;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList list;
    list.insertEnd(10);
    list.insertEnd(20);
    list.insertStart(5);

    cout << "Forward Display:" << endl;
    list.displayForward();

    cout << "Reverse Display:" << endl;
    list.displayReverse();

    list.deleteNode(10);
    cout << "After Deleting 10:" << endl;
    list.displayForward();

    return 0;
}