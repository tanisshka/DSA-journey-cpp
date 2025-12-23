#include<iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.emplace_back(4);
    int size=vec.size();
    int capacity=vec.capacity();

    for(auto v : vec){
        cout<<v<<" ";
    }

    cout<<"Front: "<<vec.front()<<endl;
    cout<<"Back: "<<vec.back()<<endl;

    cout<<"Size: "<<size<<endl;
    cout<<"Capacity: "<<capacity<<endl;

    cout<<"=================================================="<<endl;
    cout<<"Erase Function:"<<endl;
    vector <int> vec1={10,20,30,40,50};
    cout<<"Erase a single element:"<<endl;
    vec1.erase(vec1.begin()+2);
    for(auto v : vec1){
        cout<<v<<" ";
    }

    cout<<endl;
    vector<int> vec2={1,2,3,4,5,6};
    cout<<"Erase a range of elements"<<endl;
    vec2.erase(vec2.begin()+1,vec2.begin()+4);
    for(auto v:vec2){
        cout<<v<<" ";
    }

    cout<<"=================================================="<<endl;
    cout<<"Insert Function:"<<endl;
    cout<<"Insert a single element."<<endl;
    vector<int> vec3={1,2,4,5};
    vec3.insert(vec3.begin()+2,3);
    for(auto v:vec3){
        cout<<v<<" ";
    }

    cout<<endl;
    cout<<"Insert multiple copies of the same value:"<<endl;
    vector<int> vec4={1,2,3};
    vec4.insert(vec4.begin()+2,3,10);
    for(auto v:vec4){
        cout<<v<<" ";
    }
    
    cout<<endl;
    cout<<"Insert using Intializer list"<<endl;
    vector <int> vec5={1,5};
    vec5.insert(vec5.begin()+1,{2,3,4});
    for(auto v:vec5){
        cout<<v<<" ";
    }

    cout<<"=================================================="<<endl;
    cout<<"Clear function:"<<endl;
    vector <int> vec6={1,2,3,4,5,6};
    cout<<"Size before clear: "<<vec6.size()<<endl;
    cout<<"Capacity before clear: "<<vec6.capacity()<<endl;
    vec6.clear();
    for(auto v:vec6){
        cout<<v<<" ";
    }
    cout<<"Size after clear: "<<vec6.size()<<endl;
    cout<<"Capacity after clear: "<<vec6.capacity()<<endl;

    cout<<"=================================================="<<endl;
    cout<<"Empty function:"<<endl;
    vector<int> vec7;
    if(vec7.empty()){
        cout<<"Vector is empty"<<endl;
    }else{
        cout<<"Vector is not empty"<<endl;
    }

    cout<<"=================================================="<<endl;
    cout<<"Iterators(vectors):"<<endl;
    vector<int> vec8={1,2,3,4,5,6};
    for(auto it=vec8.begin();it!=vec8.end();it++){
        cout<<*(it)<<" ";
    }

    cout<<endl;
    cout<<"Iterating vector in reverse:"<<endl;
    for(auto it=vec8.rbegin();it!=vec8.rend();it++){
        cout<<*(it)<<" ";
    }
    return 0;
}