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

    int natural_number_missing(){
        int n=length;
        int sum=(n)*(n+1)/2;
        int actual=0;
        for(int i=0;i<n;i++){
            actual+=A[i];
        }
        return actual-sum;
    }

    int single_missing_element(){
        int diff=A[0]-0;
        for(int i=0;i<length;i++){
            if(A[i]-i!=diff){
                return i+diff;
            }
        }
        return 0;
    }




    ~Array(){
        delete[] A;
        cout<<"The destructor was called!";
    }

};

int main(){
    Array arr(13);
    arr.create_Array();
    arr.display_Array();
    cout<<"Missing element: "<<arr.single_missing_element()<<endl;
    return 0;

}