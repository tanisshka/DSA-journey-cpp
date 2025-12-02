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
        A=new int[size];
        if(length>size){
            length=size;
        }
        this->length=length;

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

    int get(int index){
        if(index>=0 && index<length){
            return A[index];
        }else{
            return -1;
        }
    }

    void set(int index,int x){
        if(index>=0 && index<length){
            A[index]=x;
        }else{
            cout<<"Invalid index";
        }
    }

    void display(){
        for (int i = 0; i < length; i++){
            cout << A[i] << " ";
        }
        cout << endl;
    }

    int max(){
        if(length == 0){
            cout << "Array is empty!" << endl;
            return -1; // or throw an exception
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
        if(length == 0){
            cout << "Array is empty!" << endl;
            return -1; // or throw an exception
        }
        int minimum=A[0];
        for(int i=0;i<length;i++){
            if(A[i]<minimum){
                minimum=A[i];
            }
        }
        return minimum;
    }

    //Works only for positve elements
    void missing_elements(){
        if(length == 0){
           cout << "Array is empty! No missing elements." << endl;
            return;
        }
        int h=max();
        int l=min();
        Array H(h+1,h+1);

        for(int i=0;i<length;i++){
            int oldVal=H.get(A[i]);
            if(oldVal!=-1){
                H.set(A[i], oldVal + 1);
            }
        }

        for(int i=l;i<=h;i++){
            if(H.get(i)==0){
                cout<<"Missing element: "<<i<<endl;
            }

        }
    }


    ~Array(){
        delete[] A;
    }

};

int main(){
    Array arr(10,10,true);
    arr.missing_elements();
    return 0;


}