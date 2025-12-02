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

    void toUppercase() {
        for(int i=0; str[i]!='\0'; i++){
            if(str[i]>='a' && str[i]<='z' ){
                str[i]-=32;
            }
        }
        cout << "String converted to Uppercase: " << str << endl;
    }

    void toLowercase() {
        for(int i=0; str[i]!='\0'; i++){
            if(str[i]>='A' && str[i]<='Z'){
                str[i]+=32;
            }
        }
        cout << "String converted to Lowercase: " << str << endl;
    }

    // helper: lowercase without printing
    void toLowercaseSilent() {
        for(int i=0; str[i]!='\0'; i++){
            if(str[i]>='A' && str[i]<='Z'){
                str[i]+=32;
            }
        }
    }

    void comparison(Mystring other) {
        if(str[0]=='\0'){
            cout << "String is empty" << endl;
            return;
        }

        // create lowercase copies
        Mystring temp1(str);
        Mystring temp2(other.str);

        temp1.toLowercaseSilent();
        temp2.toLowercaseSilent();

        int i=0;
        while(temp1.str[i]!='\0' && temp2.str[i]!='\0'){
            if(temp1.str[i]!=temp2.str[i]){
                break;
            }
            i++;
        }

        if(temp1.str[i]==temp2.str[i]) {
            cout << str << " is equal to " << other.str << endl;
        }
        else if(temp1.str[i] < temp2.str[i]) {
            cout << str << " comes before " << other.str << " in the dictionary" << endl;
        }
        else {
            cout << other.str << " comes before " << str << " in the dictionary" << endl;
        }
    }
};

int main() {
    char input1[100];
    cout << "Enter string 1: ";
    cin.getline(input1,100);

    char input2[100];
    cout << "Enter string 2: ";
    cin.getline(input2,100);

    Mystring str1(input1);
    str1.display();

    Mystring str2(input2);
    str2.display();

    cout << "\nComparison result: " << endl;
    str1.comparison(str2);

    return 0;
}

