#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

int main() {

    vector<int> numbers{1,2,3,4,5,6}; 

    auto low = lower_bound(numbers.begin(), numbers.end(), 4); 
    cout << "Lower bound starting at" << low-numbers.begin() << endl;

    auto upper = upper_bound(numbers.begin(), numbers.end(), 5); 
    cout << "Upper bound ending at " << upper-numbers.begin() << endl;

    cout << endl;

    // true/false
    cout << binary_search(numbers.begin(), numbers.end(), 3) << endl;
    
    return 0;
}