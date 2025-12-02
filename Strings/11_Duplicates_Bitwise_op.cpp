#include<iostream>
using namespace std;

class Mystring{
private:
    char A[100];

public:
    Mystring(char s[]){
        int i=0;
        while(s[i]!='\0'){
            A[i]=s[i];
            i++;
        }
        A[i]='\0';
    }

    void display(){
        cout<<"String: "<<A<<endl;
    }

    void lowercase(){
        for(int i=0; A[i]!='\0'; i++){
            if(A[i]>='A' && A[i]<='Z'){   // FIXED <=
                A[i]+=32;
            }
        }
    }

    void duplicates(){
        int H = 0;   // Single integer for bitmask
        Mystring temp(A);
        temp.lowercase();

        for(int i=0; temp.A[i]!='\0'; i++){
            if(temp.A[i]>='a' && temp.A[i]<='z'){   // FIXED >=
                int x = 1 << (temp.A[i]-'a');

                if((H & x) > 0){
                    cout<<"Duplicate element: "<<temp.A[i]<<endl;
                }
                else{
                    H = H | x;
                }
            }
        }
    }
};

int main(){
    char input[100];
    cout<<"Enter string: ";
    cin.getline(input,100);

    Mystring str(input);
    str.duplicates();   // Call the function to check duplicates
}

// You declared int H[26] = {0}; but used it like a bitmask
// If you want to use bit masking, H should be a single integer, not an array.