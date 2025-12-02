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

    //Works only on sorted arrays 
    void finding_duplicates(){
        if(length==0){
            cout<<"Array is empty!No duplicates!";
            return;
        }
        int last_duplicate=0;
        for(int i=0;i<length-1;i++){
            if(A[i]==A[i+1] && A[i]!=last_duplicate){
                cout<<"Duplicate element: "<<A[i]<<endl;
                last_duplicate=A[i];
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
    arr.finding_duplicates();
    return 0;
}