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

    void insert(int x){
        if(length==size){
            cout<<"Array is full!";
        }else{
            int i=length-1;
            while(A[i]>x){
                A[i+1]=A[i];
                i--;
            }
            A[i+1]=x;
            length++;
        }
    }
    
    bool isSorted(){
        for(int i=0;i<length-1;i++){
            if(A[i]>A[i+1]){
                return false;
            }
            
        }
        return true;
    }
    
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }

    void negative_on_one_side(){
        int i=0;
        int j=length-1;
        while(i<j){
            while(i < length && A[i]<0) i++;
            while(j >= 0 && A[j]>=0) j--;
            if(i<j){
                swap(A[i],A[j]);
            }
        }
    }

    ~Array(){
        delete[] A;
        cout<<"The destructor was called!";
    }
};


int main(){
    Array arr1(10);
    arr1.create_Array();
    arr1.display_Array();
    cout<<"Sorted: "<<arr1.isSorted()<<endl;
    arr1.negative_on_one_side();
    arr1.display_Array();

    return 0;

}