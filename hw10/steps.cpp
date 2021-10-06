#include<iostream>
using namespace std;

int func(int arg) {
    arg = arg +2;
    return arg;
}

int funcp(int *argp) {
    *argp = (*argp) + 2;
    return *argp;
}

int main() {
    int i = 17;
    double f = -4.2;

    int *ip = &i;
    double *fp = &f;

    cout << "Initial values: i is " << i << ", *ip is " << *ip << ", f is " << f << ", *fp is" << *fp << endl;

    i *= 3;
    *fp *= 1.5;

    cout << "After multiplying: i is " << i << ", *ip is " << *ip << ", f is " << f << ", *fp is" << *fp << endl;

    double f2 = 2.5;
    fp = &f2;
    i = i * *ip;

    cout << "After doing deref multiplying: i is " << i << ", *ip is " << *ip << ", f is " << f << ", *fp is " << *fp << ", and f2 is " << f2 << endl; 

    cerr << "func(i) returns " << func(i) << endl;
    cout << "After func(i): i is " << i << " and *ip is " << *ip << endl;

    cerr << "func(*ip) returns " << func(*ip) << endl;
    cout << "After func(*ip): i is " << i << "and *ip is " << *ip << endl;

    cerr << "funcp(ip) returns " << funcp(ip) << endl;
    cout << "After func(ip), i is " << i << "and *ip is " << *ip << endl;

    cerr << "funcp(&i) is " << funcp(&i) << endl;
    cout << "After funcp(&i), i is " << i << "and *ip is " << *ip << endl;

}