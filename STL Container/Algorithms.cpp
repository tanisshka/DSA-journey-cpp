#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

bool comparator(pair<int,int> p1, pair<int,int> p2){
    if(p1.second<p2.second) return true;
    if(p1.second>p2.second) return false;

    if(p1.first<p2.second) return true;
    else return false;
}

int main(){
    int arr[5]={3,5,1,8,2};
    sort(arr,arr+5);

    for(auto val:arr){
        cout<<val<<" ";
    }
    cout<<endl; 

    vector<int> vec={3,5,1,8,2};
    sort(vec.begin(),vec.end());
    for(int val:vec){
        cout<<val<<" ";
    }
    cout<<endl;

    //Sorting in descending order
    sort(arr,arr+5,greater<int>());
        for(auto val:arr){
        cout<<val<<" ";
    }
    cout<<endl;

    vector<pair<int,int>> v={{3,1},{2,1},{7,1},{5,2}};
    sort(v.begin(),v.end());

    for(auto val:v){
        cout<<val.first<<" " <<val.second<<endl;;
    }
    cout<<endl;

    sort(v.begin(),v.end(),comparator);
    for(auto val:v){
        cout<<val.first<<" " <<val.second<<endl;;
    }
    cout<<endl;

    cout<<"Reverse function:"<<endl;
    vector <int> vec2={1,2,3,4,5};
    reverse(vec2.begin(),vec2.end());
    for(auto val:vec2){
        cout<<val<<" ";
    }
    cout<<endl;

    int a=10;
    int b=20;
    cout<<"Max: "<<max(a,b)<<endl;
    cout<<"Min: "<<min(a,b)<<endl;
    swap(a,b);
    cout<<"a: "<<a<<endl;
    cout<<"b: "<<b<<endl;

    int arr1[]={3,5,1,8,2}; //min_element and max_element returns the pointer to smallest and larget value....I f you want to access thevalur you must derefence it
    cout<<"Mininmum element in Array: "<<*(min_element(arr1,arr1+5))<<endl;
    cout<<"Maximum element in Array: "<<*(max_element(arr1,arr1+5))<<endl;

    vector<int> v2={3,5,1,8,2};
    cout<<"Minimun element: "<<*(min_element(v2.begin(),v2.end()))<<endl;
    cout<<"Maximum element: "<<*(max_element(v2.begin(),v2.end()))<<endl;

    //Binary search only works o  sorted list
    sort(v2.begin(), v2.end());
    cout<<binary_search(v2.begin(),v2.end(),8)<<endl; //1 becuase it exists
    cout<<binary_search(v2.begin(),v2.end(),10)<<endl; //0 becuase it does not exist

    int n=15;
    long int n1=15;
    long long int n3=15;

    cout<<__builtin_popcount(n)<<endl;
    cout<<__builtin_popcount(n1)<<endl;
    cout<<__builtin_popcount(n3)<<endl;
    return 0;
}