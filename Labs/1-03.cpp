#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

class MedianFinder{
    vector<int> arr;
    public:
    MedianFinder(){}
    void addNum(int num){
        arr.push_back(num);
    }
    double findMedian(){
        if(arr.size()%2==0){
            return (arr[arr.size()/2]+arr[(arr.size()-2)/2])/2.0;
        }
        else{
            return arr[(arr.size()-1)/2];
        }
    }
};

int main(){
    MedianFinder M;
    M.addNum(3);
    M.addNum(4);
    M.addNum(5);
    M.addNum(8);
    cout<<"Median = "<<M.findMedian()<<endl;
    M.addNum(6);
    M.addNum(13);
    cout<<"Median = "<<M.findMedian()<<endl;
    return 0;
}