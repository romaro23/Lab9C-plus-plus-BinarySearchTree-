#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int _value) : value(_value), left(nullptr), right(nullptr) {}
};
struct BinaryTree {
    Node* head = nullptr;
    void addNode(int _value, Node* current) {
        if (head == nullptr) {
            head = new Node(_value);
            return;
        }
        if (_value > current->value) {
            if (current->right == nullptr) {
                current->right = new Node(_value);
                return;
            }
            addNode(_value, current->right);
        }
        else if (_value < current->value) {
            if (current->left == nullptr) {
                current->left = new Node(_value);
                return;
            }
            addNode(_value, current->left);
        }
    }
    void deleteNode(int _value) {
        Node* current = head;
        Node* prev = nullptr;
        while (current->value != _value) {
            prev = current;
            if (_value > current->value) {
                current = current->right;
            }
            else {
                current = current->left;
            }
        }
        if (current->left == nullptr && current->right == nullptr) {
            if (current == head) {
                head = nullptr;
                return;
            }
            if (prev->left == current) {
                prev->left = nullptr;
            }
            else if (prev->right == current) {
                prev->right = nullptr;
            }
        }
        else if (current->left != nullptr && current->right == nullptr) {
            if (current == head) {
                head = head->left;
                return;
            }
            if (prev->left == current) {
                prev->left = current->left;
            }
            else if (prev->right == current) {
                prev->right = current->left;
            }
        }
        else if (current->right != nullptr && current->left == nullptr) {
            if (current == head) {
                head = head->right;
                return;
            }
            if (prev->left == current) {
                prev->left = current->right;
            }
            else if (prev->right == current) {
                prev->right = current->right;
            }
        }
        else {
            if (current == head) {
                Node* temp = head;
                head = head->right;
                head->left = temp->left;
                return;
            }
            if (prev->left == current) {
                prev->left = minValue(current->right);
                prev->left->right = current->right;
                prev->left->left = current->left;
            }
            else if (prev->right == current) {
                prev->right = minValue(current->right);
                prev->right->right = current->right;
                prev->right->left = current->left;
             
            }
        }
        
    }
    Node* searchByKey(int key) {
        if (head == nullptr) {
            cout << "The tree is empty" << endl;
            return nullptr;
        }
        Node* current = head;
        while (current != nullptr) {
            if (current->value == key) {
                cout << "The key was found: " << current->value << endl;
                return current;
            }
            if (key > current->value) {
                current = current->right;
            }
            else {
                current = current->left;
            }
            cout << current->value << endl;
        }
        if (current == nullptr) {
            cout << "The key was not found" << endl;
            return nullptr;
        }
    }
    Node* minValue(Node* current) {
        Node* prev;
        while (current->left != nullptr) {
            prev = current;
            current = current->left;
            prev->left = nullptr;
        }
        return current;
    }
    void print(Node* node) {
        if (node == NULL) { return; }
        cout << node->value << endl;
        print(node->left);
        print(node->right);
    }
};

   
int main()
{
    BinaryTree tree;
    int option;
    int value;
    while (true) {
        cout << "1. Add an element" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Search an element" << endl;
        cout << "4. Print" << endl;
        cin >> option;
        switch (option) {
        case 1:
            cout << "Enter value" << endl;
            cin >> value;
            tree.addNode(value, tree.head);
            break;
        case 2:
            cout << "Enter value" << endl;
            cin >> value;
            tree.deleteNode(value);
            break;
        case 3:
            cout << "Enter value" << endl;
            cin >> value;
            tree.searchByKey(value);
            break;
        case 4:
            tree.print(tree.head);
            break;
        }
    }
}

