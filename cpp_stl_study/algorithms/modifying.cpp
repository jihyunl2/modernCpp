#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void print_vect(vector<int> &v){
    for(auto it=v.begin(); it<v.end(); it++){
        cout << "[" << *it << "]";
    }
    cout << endl;
}

int main() {

    vector<int> numbers = {1, 2, 3, 4, 5, 6};
    vector<int> copy_numbers(6);

    print_vect(numbers);

    // copy
    copy(numbers.begin(), numbers.begin()+3, copy_numbers.begin());
    cout << "Copying first 3 numbers " << endl;
    print_vect(copy_numbers);

    copy_if(numbers.begin(), numbers.end(), copy_numbers.begin(), [](int x){return x%2==0;});
    cout << "Copying even numbers " << endl;
    print_vect(copy_numbers);

    // replace
    replace_if(copy_numbers.begin(), copy_numbers.end(), [](int x){return x<3;}, 0); 
    cout << "Replace numbers less than 3 with 0" << endl;
    print_vect(copy_numbers);

    // remove
    auto new_end = remove(numbers.begin(), numbers.end(), 4); 
    cout << "Remove  4" << endl;
    for (auto it = numbers.begin(); it !=new_end; it++) {
        cout << *it << " ";
    }

    cout << endl;

    new_end = remove_if(numbers.begin(), numbers.end(), [](int x){return x%2==0;}); 
    cout << "Remove even numbers" << endl;
    for (auto it = numbers.begin(); it !=new_end; it++) {
        cout << *it << " ";
    }

    cout << endl;

    cout << "Reverse" << endl;
    reverse(numbers.begin(), new_end);
    for (auto it = numbers.begin(); it !=new_end; it++) {
        cout << *it << " ";
    }

    cout << endl;

    return 0;
}