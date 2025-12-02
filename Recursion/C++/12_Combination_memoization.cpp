#include<iostream>
#include<vector>

using namespace std;

int C(int n,int r,vector <vector<int>> &look_up_table){
    if(r==0 || r==n){
        look_up_table[n][r]=1;
        return 1;
    }else{
        if(look_up_table[n][r]!=-1){
            return look_up_table[n][r];
        }else{
            look_up_table[n][r]=C(n-1,r-1,look_up_table)+C(n-1,r,look_up_table);
            return look_up_table[n][r];
        }
    }

}


int main(){
    int n,r;
    cout<<"Enter n & r: ";
    cin>>n>>r;

    vector <vector<int>> look_up_table (n+1, vector<int>(r+1,-1));
    cout << "C(" << n << ", " << r << ") = " << C(n, r, look_up_table) << endl;
    return 0;
}