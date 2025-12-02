//Coding problem: Finding a pair woth a sum k
#include<iostream>
using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;

    public:
    //Constructor
    Array(int size=10){
        this->size=size;
        A=new int[size];
    }

    void create_Array(){
        cout<<"Enter length:";
        cin>>length;
        if(length>size){
            cout<<"The length is you entered is out of bounds!Hence, length is set to "<<size<<endl;
            length=size;
        }
        for(int i=0;i<length;i++){
            cout<<"Value:";
            cin>>A[i];
        }
    }

    void display_Array(){
        for(int i=0;i<length;i++){
            cout<<A[i]<<"\t";
        }
        cout<<endl;
    }

    void pair_sum_k(int k){
        if(length==0){
            cout<<"Array is empty!";
            return;
        }
        for(int i=0;i<length-1;i++){
            for(int j=i+1;j<length;j++){
                if(A[i]+A[j]==k){
                    cout<<"Pair of elements that equal to the sum "<<k<<" are "<<A[i]<<" and "<<A[j]<<endl;
                }
            }
        }

    }


    void pair_sum_k_sorted_distinct_array(int k){
        if(length==0){
            cout<<"Array is empty!";
            return;
        }
        int i=0;
        int j=length-1;
        while(i<j){
            if(A[i]+A[j]==k){
                cout << "Pair: " << A[i] << " + " << A[j] << " = " << k << endl;
                i++;
                j--;
            }
            else if(A[i]+A[j]>k){
                j--;
            }
            else{
                i++;
            }
        }
    }

    void pair_sum_k_sorted_with_duplicates(int k) {
    if (length == 0) {
        cout << "Array is empty!" << endl;
        return;
    }

    int i = 0;
    int j = length - 1;

    while (i < j) {
        int sum = A[i] + A[j];

        if (sum == k) {
            int leftVal = A[i], rightVal = A[j];
            int leftCount = 0, rightCount = 0;

            // Count duplicates of A[i]
            while (i <= j && A[i] == leftVal) {
                i++;
                leftCount++;
            }

            // Count duplicates of A[j]
            while (j >= i && A[j] == rightVal) {
                j--;
                rightCount++;
            }

            if (leftVal == rightVal) {
                // Special case: both values are same
                int total = (leftCount * (leftCount - 1)) / 2;
                for (int c = 0; c < total; c++) {
                    cout << "Pair: " << leftVal << " + " << rightVal << " = " << k << endl;
                }
            } else {
                // Print all cross combinations
                for (int l = 0; l < leftCount; l++) {
                    for (int r = 0; r < rightCount; r++) {
                        cout << "Pair: " << leftVal << " + " << rightVal << " = " << k << endl;
                    }
                }
            }
        }
        else if (sum > k) {
            j--;
        }
        else {
            i++;
        }
    }
}


    ~Array(){
        delete[] A;
        cout<<"The destructor was called!";
    }
};

int main(){
    Array arr(10);
    arr.create_Array();
    arr.display_Array();
    arr.pair_sum_k_sorted_distinct_array(10);
    return 0;
}