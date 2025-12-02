#include<iostream>
using namespace std;

class Mystring{
    private:
    char str[100];

    public:
    Mystring(char s[]){
        int i=0;
        while(s[i]!='\0'){
            str[i]=s[i];
            i++;
        }
        str[i]='\0';
    }

    //function to calculate length of the string 
    int getLength(){
        int i=0;
        while(str[i]!='\0'){
            i++;
        }
        return i;
    }

    void display() {
        cout << "String: " << str << endl;
    }

    //Changing from uppercase to lowercase
    void touppercase() {
        int i = 0;
        while (str[i] != '\0') {
                if (str[i] >= 'a' && str[i] <= 'z') {   // check lowercase
                str[i] -= 32;   // convert to uppercase
            }
            i++;
        }
        cout << "Converted String to uppercase: " << str << endl;  // print full string
    }


    void toLowercase(){
        int i=0;
        while(str[i] != '\0'){
            if(str[i]>='A' && str[i]<='Z'){
                str[i]+=32;
            }
            i++;
        }
        cout << "Converted String to lowercase: " << str << endl; 
    }

};

int main(){
    char input[100];
    cout<<"Enter string: ";
    cin.getline(input,100);

    Mystring myStr(input);

    myStr.display();
    myStr.toLowercase();
    myStr.display();
    return 0;
    

}