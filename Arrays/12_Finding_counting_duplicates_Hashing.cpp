//Coding problem: Finding duplicates and its count using Hashing

#include<iostream>
using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;

    public:
    Array(int size=10,int length=10,bool not_filled=false){
        this->size=size;
        if(length>size){
            length=size;
        }
        this->length=length;
        A=new int[size];

        if(not_filled){
            for(int i=0;i<length;i++){
                cout<<"Value at A["<<i<<"]: ";
                cin>>A[i];
            }
        }else{
            for(int i=0;i<length;i++){
                A[i]=0;
            }
        }
    }

    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int get(int index){
        if(index>=0 && index<length){
            return A[index];
        }else{
            cout<<"Invalid Index!";
            return -1;
        }
    }

    void set(int index,int x){
        if(index>=0 && index<length){
            A[index]=x;
        }else{
            cout<<"Invalid Index";
        }
    }

    int max(){
        if(length==0){
            cout<<"Array is empty!";
            return -1;
        }
        int maximum=A[0];
        for(int i=0;i<length;i++){
            if(A[i]>maximum){
                maximum=A[i];
            }
        }
        return maximum;
    }

    int min(){
        if(length==0){
            cout<<"Array is empty";
            return -1;
        }
        int minimum=A[0];
        for(int i=0;i<length;i++){
            if(A[i]<minimum){
                minimum=A[i];
            }
        }
        return minimum;
    }

    void multiple_missing_values(){
        if(length==0){
            cout<<"Array is empty!No missing values";
            return;
        }
        int l=min();
        int h=max();
        Array H(h+1,h+1);
        for(int i=0;i<length;i++){
            int val=H.get(A[i]);
            if(val!=-1){
                H.set(A[i],val+1);
            }
        }

        for(int i=l;i<(h+1);i++){
            if(H.get(i)>1){
                cout<<"Duplicate element: "<<i<<" appears "<<H.get(i)<<" times"<<endl;
            }
        }
    }

    ~Array(){
        delete[] A;
    }


};

int main(){
    Array arr(10,10,true);
    arr.display();
    arr.multiple_missing_values();
    return 0;

}