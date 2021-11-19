#include <algorithm> 
#include <chrono> 
#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <random>
using namespace std;
using namespace std::chrono; 

bool sequentialSearch(vector<int> avector, int item) {
    unsigned int pos = 0;
    bool found = false;

    while (pos < avector.size() && !found) {
      if (avector[pos] == item) {
        found = true;
      } else {
        pos++;
      }
    }
    return found;
}

bool orderedSequentialSearch(vector<int> avector, int item) {
    unsigned int pos = 0;
    bool found = false;
    bool stop = false;
    while (pos < avector.size() && !found && !stop) {
        if (avector[pos] == item) {
            found = true;
        } else {
            if (avector[pos] > item) {
                stop = true;
            } else {
                pos++;
            }
        }
    }

    return found;
}

bool binarySearchI(vector<int> avector, int item) {
    int first = 0;
    int last = avector.size() - 1;
    bool found = false;

    while (first <= last && !found) {
      int midpoint = (first + last) / 2;
      if (avector[midpoint] == item) {
        found = true;
      } else {
        if (item < avector[midpoint]) {
          last = midpoint - 1;
        } else {
          first = midpoint + 1;
        }
    	 }
    }
    return found;
}

bool binarySearchR(vector<int> alist, int item) {
      if (alist.size() == 0) {
              return false;
      } else {
              int midpoint = alist.size() / 2;
              if (alist[midpoint] == item) {
                      return true;
              } else {
                      if (item < alist[midpoint]) {
                              vector<int> lefthalf(alist.begin(), alist.begin() + midpoint);
                              return binarySearchR(lefthalf, item);
                      } else {
                              vector<int> righthalf(
                                      alist.begin() + midpoint + 1, alist.end());
                              return binarySearchR(righthalf, item);
                      }
              }
      }
}

int main() {
    vector<int> v1(501,0);
    vector<int> v2(501,0);
    vector<int> v3(20,0);

    cout << "vectors were defined" << endl;

    for (int i = 1; i <= 500; i++) {
      int num = rand() % 5000;
      v1[i] = num;
      v2[i] = num;

      if (i % 50 == 0) {
        v3[i / 50] = num;
      }
    }

    cout << "vectors given values" << endl;

    sort(v2.begin(), v2.end());

    cout << "v2 was sorted" << endl;

    for (int i = 11; i <= 20; i++) {
      int num = rand() % 5000;
      v3[i] = num;
    }

    cout << "v3 finished giving values" << endl;

    auto start = high_resolution_clock::now();
    auto stop = high_resolution_clock::now(); 
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "start, stop, and duration defined with initial values" << endl;

    int v3_size = v3.size();

    cout << "v3_size is " << v3_size << endl;

    float countFound = 0.;
    float countNotFound = 0.;

    float SequentialTime = 0.;
    float BinaryITime = 0.;
    float BinaryRTime = 0.;

    for (int i = 1; i < v3_size; i++) {
      cout << "for loop iteration " << i << endl;

      int n = v3[i];
      bool found = binarySearchI(v2, n);

      if (found) {
        cout << "Value: " << n << ", found" << endl;
        countFound++;
      } else {
        cout << "Value: " << n << ", NOT found" << endl;
        countNotFound++;
      }

      start = high_resolution_clock::now();
      orderedSequentialSearch(v2, n);
      stop = high_resolution_clock::now(); 
      duration = duration_cast<microseconds>(stop - start); 
      SequentialTime += duration.count();
      cout << "  Sequential time: " << duration.count() << " microseconds" << endl;

      start = high_resolution_clock::now();
      binarySearchI(v2, n);
      stop = high_resolution_clock::now(); 
      duration = duration_cast<microseconds>(stop - start); 
      BinaryITime += duration.count();
      cout << "  Binary Search Iterative time: " << duration.count() << " microseconds" << endl;

      start = high_resolution_clock::now();
      binarySearchR(v2, n);
      stop = high_resolution_clock::now(); 
      duration = duration_cast<microseconds>(stop - start); 
      BinaryRTime += duration.count();
      cout << "  Binary Search Recursive time: " << duration.count() << " microseconds" << endl;
      
  }

  float averageFoundSequential = SequentialTime / countFound;
  float averageNotFoundSequential = SequentialTime / countNotFound;
  
  float averageFoundBinaryI = BinaryITime / countFound;
  float averageNotFoundBinaryI = BinaryITime / countNotFound;

  float averageFoundBinaryR = BinaryRTime / countFound;
  float averageNotFoundBinaryR = BinaryRTime / countNotFound;

  cout << "Average for FOUND items:" << endl;
  cout << "  Sequential time: " << averageFoundSequential << " microseconds" << endl;
  cout << "  Binary Iterative time: " << averageFoundBinaryI << " microseconds" << endl;
  cout << "  Binary Recursive time: " << averageFoundBinaryR << " microseconds" << endl;

  cout << "Average for NOT FOUND items" << endl;
  cout << "  Sequential time: " << averageNotFoundSequential << " microseconds" << endl;
  cout << "  Binary Iterative time: " << averageNotFoundBinaryI << " microseconds" << endl;
  cout << "  Binary Recursive time: " << averageNotFoundBinaryR << " microseconds" << endl;


}