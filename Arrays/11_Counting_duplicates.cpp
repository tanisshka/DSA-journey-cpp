#include<iostream>
using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;

    public:
    Array(int size=10){
        this->size=size;
        A=new int[size];
    }

    void create(){
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

    void display(){
        for(int i=0;i<length;i++){
            cout<<A[i]<<"\t";
        }
        cout<<endl;
    }

    void count_duplicates() {
        for (int i = 0; i < length - 1; i++) {
            if (A[i] == A[i + 1]) {   // found a duplicate
               int j = i + 1;
               while (j < length && A[j] == A[i]) {
                   j++;
                }
                 int count = j - i;   // number of times A[i] appears
                 cout << "Duplicate element " << A[i] 
                       << " count: " << count << endl;
                 i = j - 1;   // skip already counted duplicates
            }
        }
    }

    ~Array(){
        delete[] A;
    }

};

int main(){
    Array arr(10);
    arr.create();
    arr.display();
    arr.count_duplicates();
    return 0;
}