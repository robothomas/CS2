#include <iostream>
using namespace std;

int find_word(char message[], char query[]) {
    for (int i = 0; message[i] != 0; i++) {
        // checks if first letter in current index of message is the same as beginning of the query
        if (message[i] == query[0]) {
            // checks following characters to see if they match the query until the query hits a null byte or it breaks
            for (int j = 1; query[j] != 0; j++) {
                // if the next character is the null byte of the query, return the initial spot
                if (query[j + 1] == 0) {
                    return i; 
                } 

                // checks if the following characters are incorrect, in which case it boots out of this loop
                if (message[i + j] != query[j]) {
                    break;
                }
            }
        }
    }

    cout << "ERROR - for loop did not work!";
    return 0;
}

int main() {
    if (find_word("hello is a short greeting", "short") == 11) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
}