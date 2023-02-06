#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std; 

int main() {
    
    vector<int> v1{1, 2, 3, 4, 5};
    vector<int> v2{2, 3, 1, 5, 4};

    cout << "Compare" << endl;
    if (equal(v1.begin(), v1.end(), v2.begin())) {
        cout << "Two vectors are equal" << endl;
    } else {
        cout << "Two vectors are not equal" << endl;
    }

    cout << endl;

    vector<int> v3{1, 2, 3};
    if (equal(v1.begin(), v1.begin()+3, v3.begin())) {
        cout << "Two vectors are equal" << endl;
    } else {
        cout << "Two vectors are not equal" << endl;
    }

    string str1("Frog");
    string str2("Elephant");
    string str3("Cat");

    cout << endl;
    cout << "Lexicographical compare" << endl;
    if (lexicographical_compare(str1.begin(), str1.end(), str2.begin(), str2.end())) {
        cout << str1 << " is lexicographically less than " << str2 << endl;
    } else {
        cout << str2 << " is lexicographically less than " << str1 << endl;
    }

    cout << endl;
    if (lexicographical_compare(str2.begin(), str2.end(), str3.begin(), str3.end())) {
        cout << str2 << " is lexicographically less than " << str3 << endl;
    } else {
        cout << str3 << " is lexicographically less than " << str2 << endl;
    }

    string str5("123"); 
    string str6("345"); 

    cout << endl;
    if (lexicographical_compare(str5.begin(), str5.end(), str6.begin(), str6.end())) {
        cout << str5 << " is lexicographically less than " << str6 << endl;
    } else {
        cout << str6 << " is lexicographically less than " << str5 << endl;
    }

    return 0;
}