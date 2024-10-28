#include<iostream>
#include<vector>
using namespace std;
template< class T>
class DE_Queue{
    T* ptr;
    int c_size;
    int front;
    int rear;
    int capacity;
    void resize(){
        capacity*=2;
        T *temp= new T[capacity];
        for(int i=0;i<c_size;i++){
            temp[i]=ptr[front];
            front=(front+1)%capacity;
        }
        front=0;
        rear=c_size;
        delete ptr;
        ptr=temp;
    }
public:
    DE_Queue(int s=4) :c_size(0),front(0),rear(0),capacity(s){
        ptr= new T[capacity];
    }
    void enqueue_r(T val){
        if(isfull()){
            resize();
        }
        ptr[rear]=val;
        rear=(rear+1)% capacity;
        c_size++;
    }
    void enqueue_f(T val){
        if(isfull()){
            resize();
        }
        front=(front-1+capacity)%capacity;
        ptr[front]=val;
        c_size++;
    }
    void dequeue_r(){
        if(!isempty()){
            rear=(rear-1+capacity)% capacity;
            c_size--;
        }
    }
    void dequeue_f(){
        if(!isempty()){
            front=(front+1)% capacity;
            c_size--;
        }
    }
    T Front(){
        if(!isempty())
            return ptr[front];
    }
    T Rear(){
        if(!isempty())
            return ptr[(rear-1+capacity)%capacity];
    }
    bool isempty(){
        return (c_size==0);
    }
    bool isfull(){
        return (c_size==capacity);
    }
};
int main(){
    DE_Queue<int> q(2);
    q.enqueue_r(5);
    q.enqueue_r(9);
    q.enqueue_r(90);
    cout<<q.Rear()<<endl;
    cout<<q.Front()<<endl;
    q.enqueue_f(3);
    cout<<q.Rear()<<endl;
    cout<<q.Front()<<endl;
    q.dequeue_f();
    cout<<q.Rear()<<endl;
    cout<<q.Front()<<endl;
    return 0;
}