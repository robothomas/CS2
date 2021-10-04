#include<iostream>
using namespace std;

float convert_to_celsius(float fahrenheit) {
    return (5.f/9.f) * (fahrenheit - 32.f);
}

int main() {
  if (convert_to_celsius(32.) == 0.) 
    cout << "yes" << endl;
  else
    cout << "no" << endl;

  if (convert_to_celsius(-40.) == -40.) 
    cout << "yes" << endl;
  else
    cout << "no" << endl;

}