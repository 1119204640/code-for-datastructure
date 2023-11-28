#include <unistd.h>
#include <iostream>
using namespace std;

int main() {
    int i;
    for (i = 0; i < 2; i++) {
        if (fork() == 0) cout << "A\n";
    }
    cout << "B\n";
}