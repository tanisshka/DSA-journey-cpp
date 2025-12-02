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

    int valid(){
        for(int i=0;str[i]!='\0';i++){
            if(!(str[i]>='A' && str[i]<='Z') && !(str[i]>='a' && str[i]<='z') && !(str[i]>=48 && str[i]<=57)){
                return 0;
            }
        }
        return 1;
    }
};

int main(){
    char input[100];
    cout<<"Enter string: ";
    cin.getline(input,100);

    MyString str1(input);
    str1.display();
    if(str1.valid()){
        cout<<"Valid string"<<endl;
    }
    else{
        cout<<"Invalid string"<<endl;
    }
    return 0;

}