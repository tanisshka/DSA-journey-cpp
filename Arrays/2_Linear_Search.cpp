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
            cout<<"Length entered is out of bounds!";
            length=size;
        }
        for(int i=0;i<length;i++){
            cout<<"Value: ";
            cin>>A[i];
        }

    }

    void display(){
        for(int i=0;i<length;i++){
            cout<<A[i]<<"\t";
        }
        cout<<endl;
    }

    int Linear_Search(int key){
        for(int i=0;i<length;i++){
            if(key==A[i]){
                return i;
            }
        }
        return -1;
    }

    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }

    //Improvised Linear search
    int Linear_Search_Transposition(int key){
        for(int i=0;i<length;i++){
            if(key==A[i]){
                swap(A[i],A[i-1]);
                return i-1;
            }
        }
        return -1;
    }


    int Linear_Search_Move_to_Front(int key){
        for(int i=0;i<length;i++){
            if(key==A[i]){
                swap(A[i],A[0]);
                return 0;
            }
        }
        return -1;
    }


    ~Array(){
        delete[] A;
        cout<<"Array destroyed!";
    }
};

int main(){
    Array arr1(10);
    arr1.create();
    arr1.display();
    // int pos=arr1.Linear_Search_Transposition(5);
    // arr1.display();
    

    int pos=arr1.Linear_Search_Move_to_Front(5);
    arr1.display();
    cout<<"Position: "<<pos<<endl;
    return 0;

}