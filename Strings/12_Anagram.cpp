#include <iostream>
using namespace std;

class Mystring {
private:
    char A[100]; 

public:
    // Constructor
    Mystring(char s[] = (char*)"") {
        int i = 0;
        while(s[i] != '\0') {
            A[i] = s[i];
            i++;
        }
        A[i] = '\0';
    }

    // Display the string
    void display() {
        cout << "String: " << A << endl;
    }

    // Convert to lowercase
    void lowercase() {
        for(int i = 0; A[i] != '\0'; i++) {
            if(A[i] >= 'A' && A[i] <= 'Z') {
                A[i] += 32;
            }
        }
    }

    // Get length
    int get_Length() {
        int i = 0;
        while(A[i] != '\0') i++;
        return i;
    }

    // Check palindrome
    int palindrome() {
        if(A[0] == '\0') {
            cout << "String is empty" << endl;
            return -1;
        }
        Mystring temp(A);
        temp.lowercase();

        int i = 0;
        int j = temp.get_Length() - 1;

        while(i < j) {
            if(temp.A[i] != temp.A[j]) {
                return 0; // not palindrome
            }
            i++;
            j--;
        }
        return 1; // palindrome
    }

    // Check equality
    int isEqual(Mystring B) {
        if(A[0] == '\0' || B.A[0] == '\0') {
            cout << "String is empty" << endl;
            return 0;
        }

        Mystring temp1(A);
        Mystring temp2(B.A);

        temp1.lowercase();
        temp2.lowercase();

        int i = 0;
        while(temp1.A[i] != '\0' && temp2.A[i] != '\0') {
            if(temp1.A[i] != temp2.A[i]) {
                return 0; // not equal
            }
            i++;
        }

        if(temp1.A[i] == '\0' && temp2.A[i] == '\0')
            return 1; // equal
        else
            return 0; // lengths differ
    }

    // Getter for string
    const char* getString() {
        return A;
    }

    // Check anagram
    int Anagram(Mystring B) {
        if(A[0] == '\0' || B.A[0] == '\0') {
            cout << "String is empty" << endl;
            return -1;
        }

        Mystring temp1(A);
        Mystring temp2(B.A);

        temp1.lowercase();
        temp2.lowercase();

        // Reject if identical
        if(temp1.isEqual(temp2)) {
            cout << "Both strings are equal, not anagrams" << endl;
            return 0;
        }

        // If lengths differ → not anagrams
        if(temp1.get_Length() != temp2.get_Length()) {
            return 0;
        }

        int H[26] = {0};

        for(int i = 0; temp1.A[i] != '\0'; i++) {
            if(temp1.A[i] >= 'a' && temp1.A[i] <= 'z') {
                H[temp1.A[i] - 'a']++;
            }
        }

        for(int i = 0; temp2.A[i] != '\0'; i++) {
            if(temp2.A[i] >= 'a' && temp2.A[i] <= 'z') {
                H[temp2.A[i] - 'a']--;
            }
        }

        for(int i = 0; i < 26; i++) {
            if(H[i] != 0) {
                return 0; // not anagram
            }
        }
        return 1; // anagram
    }
};

int main() {
    char input1[100];
    cout << "Enter string 1: ";
    cin.getline(input1, 100);

    char input2[100];
    cout << "Enter string 2: ";
    cin.getline(input2, 100);

    Mystring str1(input1);
    str1.display();

    Mystring str2(input2);
    str2.display();

    if(str1.Anagram(str2)) {
        cout << str1.getString() << " and " << str2.getString() << " are anagrams" << endl;
    } else {
        cout << str1.getString() << " and " << str2.getString() << " are not anagrams" << endl;
    }

    return 0;
}
