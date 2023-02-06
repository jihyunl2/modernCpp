#include <iostream>
#include <algorithm>
#include <string>

using namespace std; 

int main() {
    
    char abcde[] = "abcde"; 
    cout << "Next permutation" << endl;
    for (int i=0; i<5; i++) {
        next_permutation(abcde, abcde+5);
        cout << abcde << endl;
    }

    char edcba[5];
    copy(abcde, abcde+5, edcba);

    cout << endl;
    cout << "Prev permutation" << endl;
    for (int i=0; i<5; i++) {
        prev_permutation(abcde, abcde+5);
        cout << abcde << endl;
    }

    cout << endl;
    cout << "Is permutation" << endl;
    cout << is_permutation(abcde, abcde+5, edcba) << endl;
    cout << is_permutation(abcde, abcde+3, edcba) << endl;

    return 0;
}