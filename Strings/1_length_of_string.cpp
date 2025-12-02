#include<iostream>
using namespace std;

class Mystring{
    private:
    string str;

    public:
    Mystring(string str=""){
        this->str=str;
    }

    int getLength(){
        return str.length();
    }

    void display(){
        cout<<"String: "<<str<<endl;
    }
};

int main(){

    string input;
    cout<<" Enter string: "<<endl;
    getline(cin,input);

    Mystring str1(input);
    str1.display();
    cout<<"Length: "<<str1.getLength();
    return 0;
}