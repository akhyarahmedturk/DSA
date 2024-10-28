#include<iostream>
using namespace std;

template< class T>
class MyCircularDeque {
    T *ptr;
    int capacity,size,rear,front;
    void resize(){
    	T *temp=new T[capacity*2];
    	int i=0;
    	while(size!=0){
    		temp[i++]=ptr[front];
    		front=(front-1+capacity)%capacity;
    		size--;
		}
		front=0;
		size=rear=i;
		delete ptr;
		ptr=temp;
		capacity*=2;
	}
public:
    MyCircularDeque(int k) {
        capacity=k;
        size=0;
        front=0;
        rear=0;
        ptr=new T[capacity];
    }
    bool insertFront(T value) {
        if(size==capacity) resize();
        if(size!=capacity){
            front=(front-1+capacity)%capacity;
            ptr[front]=value;
            size++;
            return true;
        }
        return false;
    }
    bool insertLast(T value) {
        if(size==capacity) resize();
        if(size!=capacity){
            ptr[rear]=value;
            rear=(rear+1)%capacity;
            size++;
            return true;
        }
        return false;
    }
    bool deleteFront() {
        if(size!=0){
            front=(front+1)%capacity;
            size--;
            return true;
        }
        return false;
    }
    bool deleteLast() {
        if(size!=0){
            rear=(rear-1+capacity)%capacity;
            size--;
            return true;
        }
        return false;
    }
    T getFront() {
        if(size==0) return -1;
        return ptr[front];
    }
    T getRear() {
        if(size==0) return -1;
        return ptr[(rear-1+capacity)%capacity];
    }
    bool isEmpty() {
        return size==0;
    }
    bool isFull() {
        return size==capacity;
    }
};
int main(){
    MyCircularDeque<int> q(2);
    MyCircularDeque<int> myCircularDeque(3);
    cout<<"myCircularDeque.insertLast(1) : "<<myCircularDeque.insertLast(1)<<endl;  // return True
    cout<<"myCircularDeque.insertLast(2) : "<<myCircularDeque.insertLast(2)<<endl;  // return True
    cout<<"myCircularDeque.insertFront(3) : "<<myCircularDeque.insertFront(3)<<endl; // return True
    cout<<"myCircularDeque.insertFront(4) : "<<myCircularDeque.insertFront(4)<<endl; // return False, the queue is full.
    cout<<"myCircularDeque.getRear() : "<<myCircularDeque.getRear()<<endl;      // return 2
    cout<<"myCircularDeque.isFull() : "<<myCircularDeque.isFull()<<endl;       // return True
    cout<<"myCircularDeque.deleteLast() : "<<myCircularDeque.deleteLast()<<endl;   // return True
    cout<<"myCircularDeque.insertFront(4) : "<<myCircularDeque.insertFront(4)<<endl; // return True
    cout<<"myCircularDeque.getFront() : "<<myCircularDeque.getFront()<<endl;     // return 4
    return 0;
}