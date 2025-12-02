#include<iostream>
using namespace std;

class Mystring {
private:
    char str[100];

public:
    Mystring(char s[]) {
        int i = 0;
        while(s[i]!='\0'){
            str[i] = s[i];
            i++;
        }
        str[i] = '\0';
    }

    void display() {
        cout << "String: " << str << endl;
    }

    void toUppercase() {
        for(int i=0; str[i]!='\0'; i++){
            if(str[i]>='a' && str[i]<='z'){
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

    void duplicates() {
        Mystring temp(str);
        temp.toLowercase();  // work on lowercase

        int H[26] = {0};    // frequency array for letters a-z

        for(int i=0; temp.str[i]!='\0'; i++){
            if(temp.str[i]>='a' && temp.str[i]<='z'){  // ignore other chars
                H[temp.str[i]-'a']++;
            }
        }

        cout << "Duplicate letters:\n";
        bool found = false;
        for(int i=0; i<26; i++){
            if(H[i] > 1){
                found = true;
                char letter = i + 'a';
                cout << letter << " occurs " << H[i] << " times!\n";
            }
        }

        if(!found){
            cout << "No duplicate letters found.\n";
        }
    }
};

int main() {
    char input[100];
    cout << "Enter string: ";
    cin.getline(input,100);

    Mystring str1(input);
    str1.display();

    str1.duplicates();

    return 0;
}
