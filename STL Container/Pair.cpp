#include<iostream>
#include<vector>
using namespace std;

int main(){
    pair <int,int> p={1,2};
    cout<<p.first<<endl;
    cout<<p.second<<endl;

    cout<<endl;
    pair <string,int> p1={"Tanishka", 20};
    cout<<p1.first<<endl;
    cout<<p1.second<<endl;

    //pair of pair
    cout<<endl;
    cout<<"Nested Pairs:";
    pair <int, pair<string,int>> p3={1,{"John",34}};
    cout<<p3.first<<endl;
    cout<<p3.second.first<<endl;
    cout<<p3.second.second<<endl;

    cout<<endl;
    cout<<"Comparison operators"<<endl;
    pair <int,int> a={1,5};
    pair <int,int> b={2,1};
    cout<<(a<b); //true -> 1 < 2

    cout<<endl;
    pair <int,int> c={2,3};
    pair <int,int> d={2,5};
    cout<<(a<b); //trun -> 3 < 5

    cout<<endl;
    cout<<"Pair with STL containers"<<endl;
    cout<<"Vector of pairs:"<<endl;
    vector <pair<int,int>> vec={{1,2},{2,3},{3,4}};
    for(auto v:vec){
        cout<<v.first<<" "<<v.second<<endl;
    }

    cout<<endl;
    cout<<endl;
    //To insert something in vector we can use piush_back or emplace_back method
    //In this context, emplace_back(5,6) constructs the pair<int,int> directly inside the vector, while push_back({4,5}) creates a temporary pair and then inserts it.
    vec.push_back({4,5});
    vec.emplace_back(5,6);

    for(auto v:vec){
        cout<<v.first<<" "<<v.second<<endl;
    }
    return 0;
}
