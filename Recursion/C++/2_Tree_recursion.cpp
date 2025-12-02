#include<iostream>

using namespace std;

int Tree_recursion(int n){
    if(n>0){
        cout<<n<<endl;
        Tree_recursion(n-1);
        Tree_recursion(n-1);
    }
    return 0;
}

int main(){
    Tree_recursion(3);
    return 0;
}
