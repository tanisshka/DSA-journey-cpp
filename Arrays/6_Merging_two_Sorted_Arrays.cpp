#include<iostream>

using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;

    public:
    Array(int size=10,int length=10,bool sorted=false){
        this->size=size;
        if(length>size){
            length=size;
        }
        this->length=length;

        A=new int[size];

        if(sorted){
            cout<<"Enter ints in sorted manner"<<endl;
            for(int i=0;i<length;i++){
                cout<<"Enter elemeent "<<i<<" : "<<flush;
                cin>>A[i];
            }
        }else{
            for(int i=0;i<length;i++){
                int val;
                val=rand()%100;

                if(rand()%2){
                    A[i]=-1*val;
                }else{
                    A[i]=val;
                }
            }
        }
    }

    int Get(int index){
        if(index>=0 && index<length){
            return A[index];
        }else{
            cout<<"Invalid index";
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


    Array Merge(Array &B){
        Array C(length+ B.length,length+B.length);
        int i=0;
        int j=0;
        int k=0;
        while(i<length && j<B.length){
            if(A[i]<B.Get(j)){
                C.set(k,A[i]);
                i++;
                k++;
            }
            else if(A[i]>B.Get(j)){
                C.set(k,B.Get(j));
                j++;
                k++;
            }else {
               C.set(k, A[i]);
               i++;
               k++;
               C.set(k, B.Get(j));
               j++;
               k++;
            }
        }

        while(i<length){
            C.set(k,A[i]);
            i++;
            k++;
        }

        while(j<B.length){
            C.set(k,B.Get(j));
            j++;
            k++;
        }
        return C;
    }

    Array Union(Array &B){
        Array C(length+B.length,length+B.length);
        int i=0;
        int j=0;
        int k=0;
        int n=length;
        int m=B.length;

        while(i<n && j<m){
            if(A[i]<B.Get(j)){
                C.set(k++,A[i++]);
            }
            else if(A[i]>B.Get(j)){
                C.set(k++,B.Get(j++));
            }else{
                C.set(k,A[i]);
                i++;
                j++;
                k++;
            }
        }
        while(i<length){
            C.set(k,A[i]);
            i++;
            k++;
        }

        while(j<B.length){
            C.set(k,B.Get(j));
            j++;
            k++;
        }
        C.length=k;
        return C;
        
    }

    Array Intersection(Array &B){
        Array C(length+B.length,length+B.length);
        int i=0;
        int j=0;
        int k=0;
        int n=length;
        int m=B.length;
        while(i<n && j<m){
            if(A[i]<B.Get(j)){
                i++;
            }
            else if(A[i]>B.Get(j)){
                j++;
            }else{
                C.set(k,A[i]);
                i++;
                j++;
                k++;
            }
        }
        C.length=k;
        return C;
    }

    Array Difference(Array &B){
        Array C(length,length);
        int i=0;
        int j=0;
        int k=0;
        int n=length;
        int m=B.length;

        while(i<n && j<m){
            if(A[i]<B.Get(j)){
                C.set(k,A[i]);
                k++;
                i++;
            }else if(A[i]>B.Get(j)){
                j++;
            }else{
                i++;
                j++;
            }
        }

        while(i<n){
            C.set(k,A[i]);
            k++;
            i++;
        }

        C.length=k;
        return C;
    }


     ~Array(){
        delete[] A;
    }

};


int main(){
    Array X(10,5,true);
    Array Y(10,5,true);

    Array Z=X.Difference(Y);
    Z.display();




    return 0;
}