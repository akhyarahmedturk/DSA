#include<iostream>
#include<queue>
#include <windows.h>
using namespace std;

class call{
    int call_id;
    int Arival_time;
    string name;
    public:
    call(int id,int time,string n):call_id(id),Arival_time(time),name(n){}
    void Display(){
        cout<<"Call ID : "<<call_id<<" Customer name : "<<name<<" Arival time : "<<Arival_time/60<<":"<<Arival_time%60;
    }
    int get_time(){ return Arival_time;}
    int get_id(){ return call_id;}
};

class call_center{
    int CSR;
    queue<call> q;
    bool available;
    public:
    call_center(int csr):CSR(csr),available(true){}
    void add_call(call c){
        q.push(c);
        cout<<"A call with detail (";
        c.Display();
        cout<<") added to the queue!"<<endl;
        Sleep(1000);
    }
    void process_calls(){
        int time=2,i=0;
        while(i<CSR && !q.empty()){
            cout<<"Call with call_id : "<<q.front().get_id()<<" is has been assigned to CSR : "<<i+1<<endl;
            Sleep(2000);
            q.pop();
            i++;
        }
        if(!q.empty()){
            cout<<"Currently any CSR is not available remaining call will be dealed once current finished! "<<endl;
            Sleep(4000);
        }
    }
};

int main(){
    call a(1,650,"Ahmed"),b(2,655,"Saleem"),c(3,660,"Asad"),d(4,680,"Taha");
    call_center cc(3);
    cc.add_call(a);
    cc.add_call(b);
    cc.add_call(c);
    cc.add_call(d);
    cc.process_calls();
    cc.process_calls();
    cc.process_calls();
    return 0;
}