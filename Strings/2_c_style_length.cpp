#include <iostream>
using namespace std;

class MyString {
private:
    char str[100];   // fixed-size character array

public:
    // Constructor
    MyString(const char s[]) {
        int i = 0;
        while (s[i] != '\0') {
            str[i] = s[i];
            i++;
        }
        str[i] = '\0'; // null terminate
    }

    // Function to calculate length using while loop
    int getLength() {
        int i = 0;
        while (str[i] != '\0') {
            i++;
        }
        return i;
    }

    // Function to display the string
    void display() {
        cout << "String: " << str << endl;
    }
};

int main() {
    char input[100];
    cout << "Enter a string: ";
    cin.getline(input, 100);   // input with spaces allowed

    MyString myStr(input);

    myStr.display();
    cout << "Length of string: " << myStr.getLength() << endl;

    return 0;
}
