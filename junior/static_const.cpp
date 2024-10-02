#include <iostream>
using namespace std;


void staticVariable() {
    static int sv = 0;
    cout << sv << " ";
    sv++;
}

int main() {
    for (int i = 0; i < 10; i++) {
        staticVariable();
    }

    return 0;
}