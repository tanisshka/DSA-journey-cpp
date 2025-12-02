#include<iostream>
using namespace std;

class Mystring{
    private:
    char str[100];

    public:
    // Constructor
    Mystring(char s[]){
        int i=0;
        while(s[i]!='\0'){
            str[i]=s[i];
            i++;
        }
        str[i]='\0';
    }

    void display(){
        cout<<"String: "<<str<<endl;
    }

    // Reverse using a temp array
    void reverse(){
        if(str[0]=='\0'){
            cout<<"String is empty!"<<endl;
            return;
        }

        char rev[100];
        int len=0;
        while(str[len]!='\0') len++;

        int j=0;
        for(int k=len-1; k>=0; k--){
            rev[j++] = str[k];
        }
        rev[j] = '\0';

        cout<<"Reversed string (temp array): "<<rev<<endl;
    }

    int get_length(){
        int i=0;
        while(str[i]!='\0'){
            i++;
        }
        return i;
    }

    void swap(char &a, char &b){   // ✅ char not int
        char temp=a;
        a=b;
        b=temp;
    }

    void reverse_in_place(){
        if(str[0]=='\0'){
            cout<<"String is empty!"<<endl;
            return;
        }
        int i=0;
        int j=get_length()-1;   // ✅ last valid index

        while(i<j){
            swap(str[i],str[j]);
            i++;
            j--;
        }
        cout<<"Reversed string (in place): "<<str<<endl;
    }
};

int main(){
    char input[100];
    cout<<"Enter string: ";
    cin.getline(input,100);

    Mystring str1(input);
    str1.display();           // show original string
    str1.reverse();           // show reversed string (temp array)
    str1.reverse_in_place();  // reverse in place (modifies original)

    return 0;
}
