#include <iostream>
using namespace std;

int main() {
       int *ptr = NULL; 

    if(ptr == NULL) {
        cout << "Pointer is NULL." << endl;
    } else {
        cout << "Pointer address: " << ptr << endl;
    }

    return 0;
}
