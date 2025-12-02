#include<iostream>

using namespace std;

int pow(int m,int n){
    if(n==0){
        return 1;
    }
    else{
        if(n%2==0){
            return pow(m*m,n/2);
        }
        else{
            return pow(m*m,n/2)*m;
        }
    }
}

int main(){
    cout<<pow(2,5)<<endl;
    return 0;

}