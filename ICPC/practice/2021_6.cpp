#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

class Node{
public:
    int data;
    Node* left, * right;
    Node(int d) :data(d), left(nullptr), right(nullptr){ };
};

Node* tree(vector<int>& in, vector<int>& post, int& post_idx, int start, int end){
    if (start > end) return nullptr;
    else{
        Node* temp = new Node(post[post_idx]);
        for (int i = end;i >= 0;i--){
            if (in[i] == post[post_idx]){
                post_idx--;
                temp->right = tree(in, post, post_idx, i + 1, end);
                temp->left = tree(in, post, post_idx, start, i - 1);
                return temp;
            }
        }
        return temp;
    }
}

void print(Node* root){
    if (!root) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()){
        int size = q.size();
        while (size){
            cout << q.front()->data << " ";
            if (q.front()->left) q.push(q.front()->left);
            if (q.front()->right) q.push(q.front()->right);
            q.pop();
            size--;
        }
        cout << endl;
    }
}

void solve(int sum,Node *root,unordered_set<int> &mp){
    mp.insert(sum);
    if(!root) return;
    solve(sum+root->data,root->right,mp);
    solve(sum+root->data,root->left,mp);
    solve(0,root->right,mp);
    solve(0,root->left,mp);
}

int main(){
    int t;
    cin >> t;
    string dummy;
    getline(cin, dummy);  // Clear the buffer after reading t.

    while (t--){
        vector<int> inorder, postorder, weights;
        string line1, line2, line3;

        getline(cin, line1);
        getline(cin, line2);
        getline(cin, line3);

        istringstream ss1(line1); // OR create a new stream each time.
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        ss1.str(line2);
        ss1.clear();
        while (ss1 >> num)
            postorder.push_back(num);

        ss1.str(line3);
        ss1.clear();
        while (ss1 >> num)
            weights.push_back(num);
        int post_idx = inorder.size() - 1;
        Node* root = tree(inorder, postorder, post_idx, 0, inorder.size() - 1);
        //print(root);
        unordered_set<int> mp;
        if(root){
            solve(0,root,mp);
        }
        for(int i=0;i<weights.size();i++){
            if(mp.find(weights[i])!=mp.end()) cout<<"TRUE"<<endl;
            else  cout<<"FALSE"<<endl;
        }
    }

    return 0;
}