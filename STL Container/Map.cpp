#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
   map<string,int> m;
   
   m["tv"]=100;
   m["laptop"]=100;
   m["headphones"]=50;
   m["tablet"]=120;
   m["watch"]=40;
   m["Watch"]=40;

   m.insert({"camera",25});
   m.emplace("airpods",45);
   for(auto p: m){
    cout<<p.first<<": "<<p.second<<endl;
   }

   cout<<"Count: "<<m.count("laptop")<<endl; //Count returns the numner of laptop keys in the map
   //If you to access value of some key then:
   cout<<"Value of airpods: "<<m["airpods"]<<endl;

   cout<<endl;
   cout<<"Erase Function:"<<endl;
   cout<<"Erase by key:"<<endl;
   m.erase("laptop");

   cout<<endl;
   for(auto p:m){
    cout<<p.first<<": "<<p.second<<endl;
   }


   cout<<"Erase by iterator:"<<endl;
   auto it=m.begin();
   advance(it,1);
   m.erase(it);

   cout<<endl;
   for(auto p:m){
    cout<<p.first<<" "<<p.second<<endl;
   }

   cout<<endl;
   cout<<"Erase by range:"<<endl;
   m.erase(m.begin(),m.end());

   if(m.empty()){
    cout<<"Map is empty"<<endl;
   }else{
    cout<<"Map is not empty"<<endl;
   }

   map<string,int> m1={{"John",23},{"Maya",28},{"Joe",30},{"Nancy",26}};

   cout<<endl;
   cout<<"Name"<<" "<<"Age"<<endl;
   for(auto p:m1){
    cout<<p.first<<": "<<p.second<<endl;
   }

   cout<<endl;
   cout<<"Find function:"<<endl;
   //find a key -> if key is found it returns its iterator  
   //           -> if key is not found it returns the end iterator

   if(m1.find("Joe")!=m1.end()){
    cout<<"FOUND JOE"<<endl;
   }else{
    cout<<"NOT FOUND JOE"<<endl;
   }

   if(m1.find("Mike")!=m1.end()){
    cout<<"FOUND MIKE"<<endl;
   }else{
    cout<<"NOT FOUND MIKE"<<endl;
   }


   cout<<"Multimap:"<<endl;
   cout<<"Multipmap: A multimap is an associative container that stores elements as key–value pairs, where multiple elements can have the same key, and all elements are automatically stored in sorted order of keys."<<endl;
   multimap<string,int> mp;
   mp.emplace("tv",100);
   mp.emplace("tv",100);
   mp.emplace("tv",100);
   mp.emplace("tv",100);
   mp.emplace("tv",100);

   for(auto p:mp){
    cout<<p.first<<": "<<p.second<<endl;
   }

   mp.erase("tv"); //Deletes all occurences os tv
   if(mp.empty()){
    cout<<"Multimap is empty"<<endl;
   }

   mp.emplace("tv",100);
   mp.emplace("tv",100);
   mp.emplace("tv",100);

   //find () returns first match of the key
   mp.erase(mp.find("tv"));

    for(auto p:mp){
    cout<<p.first<<": "<<p.second<<endl;
   }

   unordered_map<int,string> ump;
   ump[1]="Banana";
   ump[2]="Apple";
   ump.insert({3,"Mango"});
   ump.emplace(4,"Papaya");
   
   for(auto p:ump){
    cout<<p.first<<": "<<p.second<<endl;
   }

    return 0;
}