#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

// prev starts at 1, current at 0 because the 0th term is 0. This way, the sequence still continues as normal with a 0th term: 0, 1, 1, 2, 3 etc.
int fibR(int n, int prev = 1, int current = 0, int count = 0) {

    if (count == n) {
        return current;
 
    } else {
        // Makes the current term itself plus the previous, and changes prev to whatever current used to be
        int temp = current;
        current = current + prev;
        prev = temp;

        ++count; // keeps track of what term the sequence is on, adding one since the sequence has now moved to the next term

        fibR(n, prev, current, count); // recursive call with the new prev, current, and count values
    }

}

// The true recursive function, not a something that basically mimics a for loop
int fibR2(int n) {
    if (n < 2) return n;
    else return fibR2(n-1) + fibR2(n-2);
}

int fibI(int n) {
    int prev = 1;
    int current = 0;

    for (int i = 0; i < n; i++) {
        int temp = current;
        current = current + prev;
        prev = temp;
    }

    return current;
}

int main() {
    /*
    cout << "0th: " << fibR(0) << endl;
    cout << "1st: " << fibR(1) << endl;
    cout << "2nd: " << fibR(2) << endl;
    cout << "4th: " << fibR(4) << endl;
    cout << "10th: " << fibR(10) << endl;
    cout << "25th: " << fibR(25) << endl;
    cout << "50th: " << fibR(50) << endl;
    */

    /*
    cout << "0th: " << fibI(0) << endl;
    cout << "1st: " << fibI(1) << endl;
    cout << "2nd: " << fibI(2) << endl;
    cout << "4th: " << fibI(4) << endl;
    cout << "10th: " << fibI(10) << endl;
    cout << "25th: " << fibI(25) << endl;
    cout << "50th: " << fibI(50) << endl;
    */

    cout << "What item in the sequence?" << endl;

    int item;
    cin >> item;
    item = abs(item); // makes sure it is positive

    cout << "Which method? (1) Recursive (2) Iterative" << endl;

    int method;
    cin >> method;

    if (method == 1) cout << "Item " << item << " in the Fibonacci sequence is " << fibR(item) << endl; 
    
    if (method == 2) cout << "Item " << item << " in the Fibonacci sequence is " << fibI(item) << endl;

    return 0;
}