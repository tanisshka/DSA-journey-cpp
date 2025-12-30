#include<iostream>
#include<queue>
using namespace std;

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    while(!q.empty()){
        cout<<q.front()<<endl;
        q.pop();
    }

    cout<<"Size: "<<q.size()<<endl;

    
    cout<<"Priority Queue:"<<endl;
    priority_queue<int> q1; //Max heap
    q1.push(5); //5
    q1.push(3); //3 5
    q1.push(10); //3 5 10
    q1.push(4); // 3 4 5 10

    while(!q1.empty()){
        cout<<q1.top()<<endl;
        q1.pop();
    }

    priority_queue<int,vector<int>,greater<int>> q2; //Min heap
    q2.push(5); //5 
    q2.push(3); //5 3
    q2.push(10); //10 5 3
    q2.push(4); //10 5 4 3

    cout<<endl;
    while(!q2.empty()){
        cout<<q2.top()<<endl;
        q2.pop();
    }
    return 0;
}
