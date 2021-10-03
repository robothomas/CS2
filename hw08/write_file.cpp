#include <fstream>
#include <string.h>
using namespace std;

int main() {
    char greeting[] = "hello everybody!\n";
    int n = strlen(greeting);

    greeting[5] = 0;

    ofstream f("a.txt"); // creating a file stream object
    f.write(greeting, n);
    f.close();

    return 0;
}