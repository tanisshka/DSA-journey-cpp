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

    void min_max_single_scan(){
        if(length==0){
            cout<<"Array is empty!";
            return;
        }

        int min=A[0];
        int max=A[0];
        for(int i=1;i<length;i++){
            if(A[i]<min){
                min=A[i];
            }
            else if(A[i]>max){
                max=A[i];
            }
        }
        cout<<"Max element: "<<max<<endl;
        cout<<"Min element: "<<min<<endl;
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
    arr.min_max_single_scan();
    return 0;

}