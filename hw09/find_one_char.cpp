#include <iostream>
using namespace std;

int find_one_char(char arr[], char c) {
    int i;

    for (i = 0; arr[i] != 0; i++) {
        if (arr[i] == c) {
            return i; // return placement if at the correct character
        }

    }

    return i; // if for loop terminates with null byte, return length of array 
}

int main() {
    int exampleZero = find_one_char("hello", 'e');
    int exampleOne = find_one_char("hello", 'z');

    cout << "Example Zero: char found at " << exampleZero << endl;
    cout << "Example One: char found at " << exampleOne << endl;

    if (exampleZero == 1) 
        cout << "Zero: yes" << endl;
    else
        cout << "Zero: no" << endl;

    if (exampleOne == 5) 
        cout << "One: yes" << endl;
    else
        cout << "One: no" << endl;

}