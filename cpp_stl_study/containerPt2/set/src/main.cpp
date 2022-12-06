#include <set>
#include <tuple>
#include <iostream>

int main() {

    // math (unordered/sorted, unique)
    std::set<int> numbers1{1,2,3,4};
    std::set<int> numbers2{4,3,2,1};
    std::set<int> numbers3{1,1,2,2,3,4};

    std::cout << (numbers1 == numbers2) << std::endl;
    std::cout << (numbers1 == numbers3) << std::endl;
    for (auto i : numbers2) {
        std::cout << i << " "; 
    }
    std::cout << std::endl;
    std::cout << "Set size of numbers3: " << numbers3.size() << std::endl;

    std::set<std::string, std::greater<std::string>> strings{"cat", "dog", "apple", "bug"};
    for (auto i : strings) {
        std::cout << i << " "; 
    }
    std::cout << std::endl;

    using Date = std::tuple<std::string, int, int>; 

    std::set<Date> dates;
    Date Day1("Floatic", 6, 17);
    Date Day2 = {"Lea", 3, 13};
    Date Day3 = std::make_tuple("Christmas", 12, 25);

    dates.insert(Day1);
    dates.insert(Day2);
    dates.insert(Day3);

    std::cout << "Set size: " << dates.size() << std::endl;

    for (auto day : dates) {
        std::cout << std::get<0>(day) << " " << std::get<1>(day) << " " << std::get<2>(day) << std::endl;
    } 


    std::cout << "Find and Erase" << std::endl;
    Date Day4("Rip", 12, 6); 
    std::array<Date, 2> toErase = {Day4, Day2}; 

    for (auto it : toErase){
        auto findIt = dates.find(it);
        if (findIt == dates.end()) {
            std::cout << "Not found" << std::endl;
        } else {
            dates.erase(findIt);
        }
    }
    std::cout << "Set size: " << dates.size() << std::endl;

}