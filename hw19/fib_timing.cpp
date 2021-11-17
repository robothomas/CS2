#include <algorithm> 
#include <chrono> 
#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
using namespace std::chrono; 

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

    // 5 R

    auto start = high_resolution_clock::now();
    fibR(5); // function running
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start); 

    cout << "fibR(5) takes " << duration.count() << " microseconds" << endl;

    // 5 I

    start = high_resolution_clock::now();
    fibI(5); // function running
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 

    cout << "fibI(5) takes " << duration.count() << " microseconds" << endl;

    // 10 R

    start = high_resolution_clock::now();
    fibR(10); // function running
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 

    cout << "fibI(10) takes " << duration.count() << " microseconds" << endl;

    // 10 I

    start = high_resolution_clock::now();
    fibI(10); // function running
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 

    cout << "fibI(10) takes " << duration.count() << " microseconds" << endl;

    // 25 R

    start = high_resolution_clock::now();
    fibR(25); // function running
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 

    cout << "fibR(25) takes " << duration.count() << " microseconds" << endl;

    // 25 I

    start = high_resolution_clock::now();
    fibI(25); // function running
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 

    cout << "fibI(25) takes " << duration.count() << " microseconds" << endl;

    // 50 R

    start = high_resolution_clock::now();
    fibR(50); // function running
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 

    cout << "fibR(50) takes " << duration.count() << " microseconds" << endl;

    // 50 I

    start = high_resolution_clock::now();
    fibI(50); // function running
    stop = high_resolution_clock::now(); 
    duration = duration_cast<microseconds>(stop - start); 

    cout << "fibI(50) takes " << duration.count() << " microseconds" << endl;

    return 0;
}