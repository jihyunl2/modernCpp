#include <iostream>
#include <unordered_set>

void print_set(const std::unordered_set<int> & unordered) {
    for (auto i : unordered) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

int main() {

    std::unordered_set<int> numbers{1, 10, 9, 8, 3};
    print_set(numbers);
    numbers.insert(10);
    numbers.insert(100);
    print_set(numbers);

    // count
    for(auto num: numbers) {
        std::cout << numbers.count(num) << " "; // 1/0
    }
    std::cout << std::endl;

}