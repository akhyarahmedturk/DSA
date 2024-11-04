#include<iostream>

using namespace std;

class Node{ // Node structure for the binary tree
public:
    int ID;
    string name;
    string dept;
    Node* left;
    Node* right;
    Node(int id, string n, string d) :ID(id), name(n), dept(d){ // Constructor to initialize node
        left = nullptr;
        right = nullptr;
    }
};

class Employee{
private:
    Node* root;
    Node* insert(Node* root, int id, string& n, string& dep){
        if (!root) return new Node(id, n, dep);
        if (id == root->ID){
            cout << "Cannot insert an employee with Duplicate ID." << endl;
            return root;
        }
        if (id > root->ID){
            root->right = insert(root->right, id, n, dep);
        }
        else{
            root->left = insert(root->left, id, n, dep);
        }
        return root;
    }
    void inOrderTraversal(Node* temp){
        if (temp->left) inOrderTraversal(temp->left);
        cout << "ID: " << temp->ID << "\nName: " << temp->name << "\nDepartment: " << temp->dept << endl;
        if (temp->right) inOrderTraversal(temp->right);
    }
    Node* deleteNode(Node* root, int key){
        Node* temp = root;
        if (key > root->ID){
            if (root->right)
                root->right = deleteNode(root->right, key);
        }
        else if (key < root->ID){
            if (root->left)
                root->left = deleteNode(root->left, key);
        }
        else{
            if (root->left && root->right){
                temp = Find_successor(root->right);
                root->ID = temp->ID;
                root->right = deleteNode(root->right, temp->ID);
                return root;
            }
            else if (root->left)  root = root->left;
            else if (root->right) root = root->right;
            else   root = nullptr;
            delete temp;
        }
        return root;
    }
    Node* Find_successor(Node* root){
        while (root->left) root = root->left;
        return root;
    }
public:
    Employee() :root(nullptr){ }
    void insert(int id, string n, string dep){
        root = insert(root, id, n, dep);
    }
    pair<string, string> search(int id){
        Node* temp = root;
        while (temp && temp->ID != id){
            if (id > temp->ID) temp = temp->right;
            else temp = temp->left;
        }
        if (temp){
            return { temp->name,temp->dept };
        }
        else{
            cout << "Employee with ID: " << id << " not found." << endl;
            return { "","" };
        }
    }
    void inOrderTraversal(){
        cout << "Displaying all Empoyees data" << endl;
        inOrderTraversal(root);
    }
    void deleteNode(int id){
        if (!root) return;
        root = deleteNode(root, id);
    }
    pair<string, string> find_min(){
        Node* temp = root;
        if (!temp) return { "","" };
        while (temp->left){
            temp = temp->left;
        }
        return { temp->name,temp->dept };
    }
    pair<string, string> find_max(){
        Node* temp = root;
        if (!temp) return { "","" };
        while (temp->right){
            temp = temp->right;
        }
        return { temp->name,temp->dept };
    }
};

int main(){
    Employee E;
    E.insert(1, "akhyar", "CS");
    //E.insert(78, "akhyar", "CS");
    E.insert(5, "rehan", "CS");
    E.insert(2, "ahmed", "CS");
    E.insert(2, "ahmed", "CS");
    E.deleteNode(6);
    E.deleteNode(1);
    E.inOrderTraversal();
    pair<string, string> temp = E.search(2);
    cout << "Search id: " << 2 << " name: " << temp.first << " department: " << temp.second << endl;
    // temp = E.find_max();
    // cout << "Max id data: " << " name: " << temp.first << " department: " << temp.second << endl;
    // temp = E.find_min();
    // cout << "Min id data: " << " name: " << temp.first << " department: " << temp.second << endl;
    return 0;
}