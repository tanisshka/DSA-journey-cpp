#include<iostream>
#include<set>
using namespace std;

int main(){
    cout<<"Set:"<<endl;
    cout<<"Set: A set is an associative container that stores unique elements, where all elements are automatically stored in sorted order."<<endl;
    set<int> s;
    s.insert(10);
    s.insert(5);
    s.insert(20);

    s.insert(10);
    s.insert(5);

    for(auto val:s){
        cout<<val<<" ";
    }
    return 0;
}