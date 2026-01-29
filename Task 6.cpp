#include <iostream>
using namespace std;

int main() {
    int num = 100;
    void *vptr = &num;

    cout << "Value using void pointer: " << *(int*)vptr << endl;

    return 0;
}
