#include<iostream>
#include<vector>

using namespace std;

int fib(int n,vector<int> &look_up_table){
    if(n<=1){
        look_up_table[n]=n;
        return n;
    }else{
        if(look_up_table[n]!=-1){
            return look_up_table[n];
        }
        else{
            look_up_table[n]=fib(n-1,look_up_table)+fib(n-2,look_up_table);
            return look_up_table[n];
        }
    }
}

int main(){
    int n;
    cout<<"Enter n:";
    cin>>n;

    vector<int> look_up_table (n+1,-1);
    cout<<"Fibonacci "<<n<<": "<<fib(n,look_up_table);
    return 0;
}
