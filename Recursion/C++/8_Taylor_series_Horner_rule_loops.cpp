#include<iostream>

using namespace std;

double Taylor_series_horners_rule(int x,int n){
    double sum=1;
    for(int i=n;i>=1;i--){
        sum=1+((float)x/i)*sum;
    }
    return sum;
}

int main(){
    cout<<Taylor_series_horners_rule(1,10)<<endl;
    return 0;
}