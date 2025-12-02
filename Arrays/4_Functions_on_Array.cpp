#include<iostream>
using namespace std;

class Array{
    private:
    int *A;
    int size;
    int length;

    public:
    //Concstructor
    Array(int size=10){
        this->size=size;
        A=new int[size];
    }

    void create(){
        cout<<"Enter length: ";
        cin>>length;
        if(length>size){
            cout<<"Length is out of bounds!";
            length=size;
        }
        for(int i=0;i<length;i++){
            cout<<"Value at A["<<i<<"] : ";
            cin>>A[i];
        }
    }
    
    void display(){
        for(int i=0;i<length;i++){
            cout<<A[i]<<"\t";
        }
        cout<<endl;
    }


    int get(int index){
        if(index>=0 && index<length){
            return A[index];
        }
        return -1;
    }

    void set(int index,int x){
        if(index>=0 && index<length){
            A[index]=x;
        }else{
            cout<<"Invalid index!"<<endl;
        }
    }

    int maximum(){
        int max=A[0];
        for(int i=1;i<length;i++){
            if(A[i]>max){
                max=A[i];
            }
        }
        return max;
    }

    int minimum(){
        int min=A[0];
        for(int i=1;i<length;i++){
            if(A[i]<min){
                min=A[i];
            }
        }
        return min;
    }

    int sum(){
        int total=0;
        for(int i=0;i<length;i++){
            total+=A[i];
        }
        return total;
    }

    int recursive_sum_Helper(int A[],int n){
        if(n<0){
            return 0;
        }
        else{
            return recursive_sum_Helper(A,n-1)+A[n];
        }
    }

    int recursive_sum(){
        return recursive_sum_Helper(A,length-1);
    }

    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }

    void reverse(){
        for(int i=0;i<length/2;i++){
            swap(A[i],A[length-i-1]);
        }
    }

    void left_shift(){
        int hold=A[0];
        for(int i=1;i<length;i++){
            A[i-1]=A[i];
        }
        A[length-1]=hold;
    }

    void right_shift(){
        int hold=A[length-1];
        for(int i=length-2;i>=0;i--){
            A[i+1]=A[i];
        }
        A[0]=hold;
    }



    ~Array(){
        delete[] A;
        cout<<"Destructor was called!";
    }

};

int main(){
    Array arr(10);
    arr.create();
    arr.display();
    cout<<"Array element at index 4: "<<arr.get(4)<<endl;
    arr.set(4,19);
    arr.display();
    cout<<"Maximum element: "<<arr.maximum()<<endl;
    cout<<"Minimum element: "<<arr.minimum()<<endl;
    cout << "Sum (iterative): " << arr.sum() << endl;
    cout << "Sum (recursive): " << arr.recursive_sum() << endl;
    arr.reverse();
    arr.display();
    arr.left_shift();
    arr.display();
    arr.right_shift();
    arr.display();
    
    return 0;

}