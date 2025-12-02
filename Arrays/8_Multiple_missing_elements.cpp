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

    void missing_elements(){
        int diff=A[0]-0;
        for(int i=0;i<length;i++){
            if(A[i]-i!=diff){
                while(A[i]-i>diff){
                   cout<<"Missing element: "<<i+diff<<endl;
                   diff++;
                }
            }
            
        }
    }

    ~Array(){
        delete[] A;
        cout<<"The destructor was called!";
    }

};

int main(){
    Array arr(11);
    arr.create();
    arr.display();
    arr.missing_elements();
    return 0;
}
