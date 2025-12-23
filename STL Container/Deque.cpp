#include<iostream>
#include<deque>
using namespace std;

int main(){
    cout<<"std::deque is a sequence container that allows fast insertion and deletion at both the front and back, while supporting random access."<<endl;
    cout<<"========================================="<<endl;
    cout<<"Initialization:"<<endl;
    deque<int> d1;
    deque<int> d2={1,2,3,4,5};
    deque<int> d3 (3,10);

    cout<<endl;
     cout<<"========================================="<<endl;
     cout<<"Size function:"<<endl;
     cout<<"Size d2: "<<d2.size()<<endl;
     cout<<"Size d3: "<<d3.size()<<endl;

    cout<<endl;
    cout<<"========================================="<<endl;
    cout<<"Empty function: "<<endl;
    if(d1.empty()){
        cout<<"d2 is empty!"<<endl;
    }

    d2.push_back(6);
    d2.push_back(7);
    d2.push_front(0);
    d2.push_front(-1);

    d2.pop_back();
    d2.pop_front();

    for(auto val:d2){
        cout<<val<<" ";
    }

    cout<<"Front: "<<d2.front()<<endl;
    cout<<"Back: "<<d2.back()<<endl;

    cout<<endl;

    return 0;
}