#include<iostream>
using namespace std;

class Mystring {
private:
    char str[100];

public:
    Mystring(char s[]) {   // constructor
        int i=0;
        while(s[i]!='\0'){
            str[i]=s[i];
            i++;
        }
        str[i]='\0';
    }

    void display() {
        cout << "String: " << str << endl;
    }

    const char* getString() {
        return str;
    }

    void toUppercase() {
        for(int i=0; str[i]!='\0'; i++){
            if(str[i]>='a' && str[i]<='z' ){
                str[i]-=32;
            }
        }
    }

    void toLowercase() {
        for(int i=0; str[i]!='\0'; i++){
            if(str[i]>='A' && str[i]<='Z'){
                str[i]+=32;
            }
        }
    }

    int get_Length(){
        int i=0;
        while(str[i]!='\0') i++;
        return i;
    }

    int palindrome(){
        if(str[0]=='\0'){
            cout<<"String is empty!"<<endl;
            return -1;
        }

        int i=0;
        int j=get_Length()-1;

        Mystring temp(str);
        temp.toLowercase();

        while(i<j){
            if(temp.str[i]!=temp.str[j]){
                return 0;  // not palindrome
            }
            i++;
            j--;   // ✅ fix: decrement j
        }
        return 1;  // palindrome
    }
};

int main(){
    char input[100];
    cout<<"Enter string: ";
    cin.getline(input,100);

    Mystring str1(input);
    str1.display();

    int result = str1.palindrome();

    if(result == 1){
        cout<<str1.getString()<< " is palindrome!"<<endl;
    }
    else if(result == 0){
        cout<<str1.getString()<< " is not palindrome!"<<endl;
    }

    return 0;
}
