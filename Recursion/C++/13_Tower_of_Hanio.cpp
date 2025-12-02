#include<iostream>

using namespace std;

void Tower_of_Hanoi(int n,char A,char B,char C){
    if(n==1){
        cout<<"Move disk "<<n<<" from "<<A<<" -> "<<C<<endl;
    }else{
        Tower_of_Hanoi(n-1,A,C,B);
        cout<<"Move disk "<<n<<" from "<<A<<" -> "<<C<<endl;
        Tower_of_Hanoi(n-1,B,A,C);
    }
}

int main(){
    int n;
    cout << "Enter number of disks: ";
    cin >> n;

    Tower_of_Hanoi(n, 'A', 'B', 'C');  // A = source, B = auxiliary, C = destination

    cout << "Total moves = " << ( (1 << n) - 1 ) << endl; // 2^n - 1
    return 0;

}


