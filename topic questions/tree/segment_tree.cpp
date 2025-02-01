#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

class ST{
    enum TYPE{
        MIN = 1,
        MAX,
        SUM
    };

    int type = MIN;
    vector<int> arr;
    vector<int> tree;
    int n;

    void Build_min(int node, int start, int end){
        if (start == end){// leaf node
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        Build_min(node * 2 + 1, start, mid);//left side
        Build_min(node * 2 + 2, mid + 1, end);//right side

        tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
    void Build_max(int node, int start, int end){
        if (start == end){// leaf node
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        Build_max(node * 2 + 1, start, mid);//left side
        Build_max(node * 2 + 2, mid + 1, end);//right side

        tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
    }
    void Build_sum(int node, int start, int end){
        if (start == end){// leaf node
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        Build_sum(node * 2 + 1, start, mid);//left side
        Build_sum(node * 2 + 2, mid + 1, end);//right side

        tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
    int get_sum(int node, int start, int end, int ts, int te){// ts -> tree start , te-> tree end
        if (start > te || end < ts) return 0; // completely outside the give range of tree  
        if (start <= ts && end >= te) return tree[node];
        int mid = (ts + te) / 2;
        int left_sum = get_sum(node * 2 + 1, start, end, ts, mid);
        int right_sum = get_sum(node * 2 + 2, start, end, mid + 1, te);
        return left_sum + right_sum;
    }
    int get_min(int node, int start, int end, int ts, int te){// ts -> tree start , te-> tree end
        if (start > te || end < ts) return INT_MAX; // completely outside the give range of tree  
        if (start <= ts && end >= te) return tree[node];
        int mid = (ts + te) / 2;
        int left_min = get_min(node * 2 + 1, start, end, ts, mid);
        int right_min = get_min(node * 2 + 2, start, end, mid + 1, te);
        return min(left_min, right_min);
    }
    int get_max(int node, int start, int end, int ts, int te){// ts -> tree start , te-> tree end
        if (start > te || end < ts) return INT_MAX; // completely outside the give range of tree  
        if (start <= ts && end >= te) return tree[node];
        int mid = (ts + te) / 2;
        int left_max = get_max(node * 2 + 1, start, end, ts, mid);
        int right_max = get_max(node * 2 + 2, start, end, mid + 1, te);
        return max(left_max, right_max);
    }
    void update(int node, int& index, int& new_val, int start, int end){
        if (start == end){// leaf node
            arr[index] = new_val;
            tree[node] = new_val;
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid) update(node * 2 + 1, index, new_val, start, mid);//left side
        else update(node * 2 + 2, index, new_val, mid + 1, end);//right side

        if (type == MIN) tree[node] = min(tree[node * 2 + 1], tree[node * 2 + 2]);
        else if (type == MAX) tree[node] = max(tree[node * 2 + 1], tree[node * 2 + 2]);
        else tree[node]=tree[node * 2 + 1] + tree[node * 2 + 2];
    }
public:
    void Build_min(vector<int> ARR){
        type = MIN;
        arr = ARR;
        n = arr.size();
        tree.resize(4 * n + 1);
        Build_min(0, 0, n - 1);
    }
    void Build_max(vector<int> ARR){
        type = MAX;
        arr = ARR;
        n = arr.size();
        tree.resize(4 * n + 1);
        Build_max(0, 0, n - 1);
    }
    void Build_sum(vector<int> ARR){
        type = SUM;
        arr = ARR;
        n = arr.size();
        tree.resize(4 * n + 1);
        Build_sum(0, 0, n - 1);
    }
    int get_sum(int start, int end){
        if (type != SUM){
            cout << "Cannot perform that operation!" << endl;
            return 0;
        }
        if (start > end) return 0;
        return get_sum(0, start, end, 0, n - 1);
    }
    int get_min(int start, int end){
        if (type != MIN){
            cout << "Cannot perform that operation!" << endl;
            return 0;
        }
        if (start > end) return INT_MAX;
        return get_min(0, start, end, 0, n - 1);
    }
    int get_max(int start, int end){
        if (type != MAX){
            cout << "Cannot perform that operation!" << endl;
            return 0;
        }
        if (start > end) return INT_MAX;
        return get_min(0, start, end, 0, n - 1);
    }
    void display(){
        for (int i = 0;i < tree.size();i++){
            cout << tree[i] << " , ";
        }
        cout << endl;
    }
    void update(int index, int new_val){
        if (index < 0 || index >= n) return;
        update(0, index, new_val, 0, n - 1);
    }
};

int main(){
    ST st;
    st.Build_min({ 1,5,10,2,7,15,18 });
    //st.display();
    cout << st.get_min(0, 90) << endl;
    cout << st.get_min(2, 4) << endl;
    cout << st.get_min(3, 6) << endl;
    cout << st.get_min(5, 6) << endl;
    st.update(3, 3);
    cout << st.get_min(0, 90) << endl;
    cout << st.get_min(4, 6) << endl;
    cout << st.get_min(2, 4) << endl;
    cout << st.get_min(5, 2) << endl;
    return 0;
}