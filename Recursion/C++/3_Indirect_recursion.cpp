#include<iostream>

using namespace std;

static int i=0;

int funA(int n);
int funB(int n);

int main(){
    funA(20);
    return 0;
}

int funA(int n){
    if(n>0){
        i++;
        cout<<"Activation record call "<<i<<": "<<n<<endl;
        funB(n-1);
    }
    return 0;
}

int funB(int n){
    if(n>1){
        i++;
        cout<<"Activation record call "<<i<<": "<<n<<endl;
        funA(n/2);
    }
    return 0;
}
