#include<iostream>
using namespace std;

class MyString{
    private:
    char str[100];

    public:
    MyString(char s[]){
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

    void count_word(){
        int word=0;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]==' ' && str[i-1]!=' '){
                word++;
            }
        }

        if(str[0]!='\0'){
                word++;
        }
        cout<<"Word count: "<<word<<endl;
    }
};

int main(){
    char input[100];
    cout<<"Enter string: ";
    cin.getline(input,100);

    MyString str1(input);
    str1.display();
    str1.count_word();
    return 0;
}