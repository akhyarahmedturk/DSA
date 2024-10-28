#include<iostream>
#include<queue>
using namespace std;

class ProductOfNumbers {
    queue<int> q;
public:
    ProductOfNumbers() {}
    void add(int num) {
        q.push(num);
    }
    int getProduct(int k) {
        int num=1,size=q.size();
        while(size!=k){
            q.push(q.front());
            q.pop();
            size--;
        }
        while(k!=0){
            num*=q.front();
            q.push(q.front());
            q.pop();
            k--;
        }
        return num;
    }
};

int main(){
    ProductOfNumbers productOfNumbers;
    productOfNumbers.add(3);        // [3]
    productOfNumbers.add(0);        // [3,0]
    productOfNumbers.add(2);        // [3,0,2]
    productOfNumbers.add(5);        // [3,0,2,5]
    productOfNumbers.add(4);        // [3,0,2,5,4]
    cout<<"Added 5 numbers to the stream , stream : [3,0,2,5,4]"<<endl;
    cout<<"productOfNumbers.getProduct(2) : "<<productOfNumbers.getProduct(2)<<endl; // return 20. 
    cout<<"productOfNumbers.getProduct(3) : "<<productOfNumbers.getProduct(3)<<endl; // return 40. 
    cout<<"productOfNumbers.getProduct(4) : "<<productOfNumbers.getProduct(4)<<endl; // return 0. 
    productOfNumbers.add(8);        // [3,0,2,5,4,8]
    cout<<"Added 1 numbers to the stream , stream : [3,0,2,5,4,8]"<<endl;
    cout<<"productOfNumbers.getProduct(2) :"<<productOfNumbers.getProduct(2)<<endl; // return 32.  
    return 0;
}