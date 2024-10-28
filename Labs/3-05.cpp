#include<iostream>
#include<queue>
using namespace std;

class DataStream {
    queue<int> q;
    int value;
    int k;
public:
    DataStream(int val, int x) {
        value=val;
        k=x;
    }
    bool consec(int num) {
        bool result=true;
        q.push(num);
        int size=q.size();
        if(size<k) return false;
        while(size!=k){
            q.push(q.front());
            q.pop();
            size--;
        }
        while(size!=0){
            if(q.front()!=value) result=false;
            q.push(q.front());
            q.pop();
            size--;
        }
        return result;
    }
};

int main(){
    DataStream dataStream(4, 3); //value = 4, k = 3 
    cout<<"dataStream.consec(4) : "<<dataStream.consec(4)<<endl; // Only 1 , so returns False. 
    cout<<"dataStream.consec(4) : "<<dataStream.consec(4)<<endl; // Only 2 integers are parsed.
                        // Since 2 is less than k, returns False. 
    cout<<"dataStream.consec(4) : "<<dataStream.consec(4)<<endl; // The 3 integers, so returns True. 
    cout<<"dataStream.consec(3) : "<<dataStream.consec(3)<<endl; // The last k integers[4,4,3].
                        // Since 3 is not equal to value, it returns False.
    return 0;
}