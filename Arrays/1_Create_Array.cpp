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


    void Append(int x){
        if(length!=size){
            A[length]=x;
            length++;
        }else{
            cout<<"Array is full!"<<endl;
        }
    }

    void Insert(int index,int x){
        if(index<0 || index>length){
            cout<<"Invalid index"<<endl;
        }
        else{
            if(length!=size){
            for(int i=length;i>index;i--){
                A[i]=A[i-1];
            }
            A[index]=x;
            length++;
            }else{
            cout<<"Array is full! "<<x<<" cannot be inserted!"<<endl;
            }
        }
    }

    int Delete(int index){
        if(index >= 0 && index<length){
            int x=A[index];
            for(int i=index;i<length-1;i++){
                A[i]=A[i+1];
            }
            length--;
            return x;

        }else{
            cout<<"Index is out of bounds!"<<endl;
            return -1;
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
    arr1.Append(7);
    arr1.Insert(4,15);
    arr1.display_Array();
    cout<<"Element deleted:"<<arr1.Delete(4)<<endl;
    arr1.display_Array();

    return 0;

}