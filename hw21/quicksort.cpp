#include <iostream>
using namespace std;

int c1 = 0;
int c2 = 0;

//function partitions vector depending on pivot value
int partition(float a[], int first, int last) {
  int pivotvalue = a[first];

  int rightmark = last;
  int leftmark = first+1;

  bool done = false;

  while(not done){
    while(leftmark<=rightmark && a[leftmark]<=pivotvalue){
      leftmark++;
    }
    while(rightmark>=leftmark && a[rightmark]>=pivotvalue){
      rightmark--;
    }
    if(rightmark<leftmark){
      done = true;
    }
    else{
      swap(a[rightmark], a[leftmark]);
    }
  }

  swap(a[rightmark], a[first]);

  return rightmark;
}

//recursive function that quicksorts through a given vector
// has a mistake that makes for a lot of extra (unnecessary) work
void quickSort1(float a[], int first, int last) {
  int splitpoint;
  c1++;

  if (first<last) {
    splitpoint = partition(a,first,last);

    quickSort1(a,first,splitpoint);
    quickSort1(a,splitpoint+1,last);

  }
}

//recursive function that quicksorts through a given vector
// TODO: Find and fix the mistake
void quickSort2(float a[], int first, int last) {
  int splitpoint;
  c2++;

  if (first<last) {
    splitpoint = partition(a,first,last);

    quickSort2(a,first,splitpoint-1);
    quickSort2(a,splitpoint+1,last); // now if splitpoint + 1 == last, it will not be called, saving some unnecessary function calls

  }
}

int main() {
    cout << "Array of length 4 Tests" << endl;
    c1 = 0;
    c2 = 0;
    float A1[] = {4, 2, 1, 3};
    int N1 = sizeof(A1)/sizeof(float);
    quickSort1(A1,0,N1-1);

    for (int i = 0; i < N1; ++i) {
        cout << "A1[" << i << "]: " << A1[i] << ", ";
    }

    cout << "and quicksort1 was called " << c1 << " times." << endl;

    float A2[] = {4, 2, 1, 3};
    int N2 = sizeof(A2)/sizeof(float);
    quickSort2(A2,0,N2-1);

    for (int i = 0; i < N2; ++i) {
        cout << "A2[" << i << "]: " << A2[i] << ", ";
    }

    cout << "and quicksort2 was called " << c2 << " times." << endl;

    cout << endl << "Array of length 5 Tests" << endl;
    c1 = 0;
    c2 = 0;
    float A3[] = {4, 2, 1, 5, 3};
    int N3 = sizeof(A3)/sizeof(float);
    quickSort1(A3,0,N3-1);

    for (int i = 0; i < N3; ++i) {
        cout << "A3[" << i << "]: " << A3[i] << ", ";
    }

    cout << "and quicksort1 was called " << c1 << " times." << endl;

    float A4[] = {4, 2, 1, 5, 3};
    int N4 = sizeof(A4)/sizeof(float);
    quickSort2(A4,0,N4-1);

    for (int i = 0; i < N4; ++i) {
        cout << "A4[" << i << "]: " << A4[i] << ", ";
    }

    cout << "and quicksort2 was called " << c2 << " times." << endl;

    cout << endl << "Array of length 6 Tests" << endl;
    c1 = 0;
    c2 = 0;
    float A5[] = {4, 2, 6, 1, 5, 3};
    int N5 = sizeof(A5)/sizeof(float);
    quickSort1(A5,0,N5-1);

    for (int i = 0; i < N5; ++i) {
        cout << "A5[" << i << "]: " << A5[i] << ", ";
    }

    cout << "and quicksort1 was called " << c1 << " times." << endl;

    float A6[] = {4, 2, 6, 1, 5, 3};
    int N6 = sizeof(A6)/sizeof(float);
    quickSort2(A6,0,N6-1);

    for (int i = 0; i < N6; ++i) {
        cout << "A6[" << i << "]: " << A6[i] << ", ";
    }

    cout << "and quicksort2 was called " << c2 << " times." << endl;

    cout << endl << "Array of length 7 Tests" << endl;
    c1 = 0;
    c2 = 0;
    float A7[] = {4, 7, 2, 6, 1, 5, 3};
    int N7 = sizeof(A7)/sizeof(float);
    quickSort1(A7,0,N7-1);

    for (int i = 0; i < N7; ++i) {
        cout << "A7[" << i << "]: " << A7[i] << ", ";
    }

    cout << "and quicksort1 was called " << c1 << " times." << endl;

    float A8[] = {4, 7, 2, 6, 1, 5, 3};
    int N8 = sizeof(A8)/sizeof(float);
    quickSort2(A8,0,N8-1);

    for (int i = 0; i < N8; ++i) {
        cout << "A8[" << i << "]: " << A8[i] << ", ";
    }
    
    cout << "and quicksort2 was called " << c2 << " times." << endl;

    cout << endl << "Array of length 8 Tests" << endl;
    c1 = 0;
    c2 = 0;
    float A9[] = {4, 7, 12, 2, 6, 1, 5, 3};
    int N9 = sizeof(A9)/sizeof(float);
    quickSort1(A9,0,N9-1);

    for (int i = 0; i < N9; ++i) {
        cout << "A9[" << i << "]: " << A9[i] << ", ";
    }

    cout << "and quicksort1 was called " << c1 << " times." << endl;

    float A10[] = {4, 7, 12, 2, 6, 1, 5, 3};
    int N10 = sizeof(A10)/sizeof(float);
    quickSort2(A10,0,N10-1);

    for (int i = 0; i < N10; ++i) {
        cout << "A10[" << i << "]: " << A10[i] << ", ";
    }
    
    cout << "and quicksort2 was called " << c2 << " times." << endl;

    cout << endl << "Array of length 16 Tests" << endl;
    c1 = 0;
    c2 = 0;
    float A11[] = {4, 7, 12, 2, 8, 11, 13, 6, 1, 5, 3, 10};
    int N11 = sizeof(A11)/sizeof(float);
    quickSort1(A11,0,N11-1);

    for (int i = 0; i < N11; ++i) {
        cout << "A11[" << i << "]: " << A11[i] << ", ";
    }

    cout << "and quicksort1 was called " << c1 << " times." << endl;

    float A12[] = {4, 7, 12, 2, 8, 11, 13, 6, 1, 5, 3, 10};
    int N12 = sizeof(A12)/sizeof(float);
    quickSort2(A12,0,N12-1);

    for (int i = 0; i < N12; ++i) {
        cout << "A12[" << i << "]: " << A12[i] << ", ";
    }
    
    cout << "and quicksort2 was called " << c2 << " times." << endl;

    
}