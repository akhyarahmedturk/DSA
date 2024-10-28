#include<iostream>
#include<queue>
using namespace std;
int findTheWinner(int n, int k) { // using queue
    queue<int> q;
    for (int i = 1; i <=n; i++) {
        q.push(i);
    }
    while(n>1){
        //cout<<" n "<<n<<" i<(k%n-1+n)%n "<<(k%n-1+n)%n<<endl;
        for(int i=0;i<(k%n-1+n)%n;i++){ // the term "i<(k%n-1+n)%n" will reduce time for example n=k=500 
                                        //simple loop "i<k" will take 500 operations even when n reduces to 2
                                        // while "i<(k%n-1+n)%n" will take only 1 operation only
            q.push(q.front());
            q.pop();           
        }
        q.pop();
        n--;
    }
    return q.front();
}
int main(){
    int n=500,k=500;
    cout<<"Then winner when n="<<n<<" and k="<<k<<" is : "<<findTheWinner(n,k)<<endl;
    n=3; k=2;
    cout<<"Then winner when n="<<n<<" and k="<<k<<" is : "<<findTheWinner(n,k)<<endl;
    n=2 ; k=1;
    cout<<"Then winner when n="<<n<<" and k="<<k<<" is : "<<findTheWinner(n,k)<<endl;
    return 0;
}