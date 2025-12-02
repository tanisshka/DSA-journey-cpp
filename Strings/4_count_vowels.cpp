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

    void vowel_consonant_call(){
        int vcount=0;
        int ccount=0;
        for(int i=0;str[i]!='\0';i++){
            if(str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u'
               || str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U'){
                   vcount++;
               }
            else if((str[i]>='A' && str[i]<='Z') || (str[i]>='a' && str[i]<='z')){
                ccount++;
            }    
        }
        cout<<"Vowel count: "<<vcount<<endl;
        cout<<"Consonant count: "<<ccount<<endl;
    }
};

int main(){
    char input[100];
    cout<<"Enter string: "<<endl;
    cin.getline(input,100);

    MyString str1(input);
    str1.display();
    str1.vowel_consonant_call();
    return 0;

}