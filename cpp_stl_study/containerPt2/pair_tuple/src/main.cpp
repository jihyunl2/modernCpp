#include <iostream>
#include <tuple> 
#include <string>
#include <map>


int main() {

    // PAIR
    std::cout << "PAIR:" << std::endl;
    std::cout << std::endl;

    // Initialization (1)
    std::pair<int, double> A(1, 3.3); // or A = {1, 3.3}
    // Initialization (2)
    std::pair<int, double> B = std::make_pair(2, 6.6);
    // Initialization (3)
    std::pair<char, std::string> C; 
    C.first = 'F';
    C.second = "loatic"; 

    std::cout << "Initialization" << std::endl;
    std::cout << A.first << " " << A.second << std::endl;
    std::cout << B.first << " " << B.second << std::endl;
    std::cout << C.first << " " << C.second << std::endl;


    std::cout << "Using with map" << std::endl;
    std::map<int, double> map_;
    map_.insert(A);
    map_.insert(std::make_pair(3, 9.9));
    for (auto elem: map_) {
        std::cout << elem.first << " " << elem.second << std::endl; 
    }

    // TUPLE
    std::cout << std::endl;
    std::cout << "TUPLE:" << std::endl;
    std::cout << std::endl;

    std::tuple<std::string, int, int> Day1("Floatic", 6, 17);
    std::tuple<std::string, int, int> Day2 = {"Lea", 3, 13};
    std::tuple<std::string, int, int> Day3 = std::make_tuple("Christmas", 12, 25);

    // Get w/ index
    std::cout << std::get<0>(Day1) << " " << std::get<1>(Day1) << " " << std::get<2>(Day1) << std::endl;
    std::cout << std::get<0>(Day2) << " " << std::get<1>(Day2) << " " << std::get<2>(Day2) << std::endl;
    std::cout << std::get<0>(Day3) << " " << std::get<1>(Day3) << " " << std::get<2>(Day3) << std::endl;

    // Get w/ type
    std::tuple<std::string, int, double> hi("hi", 0, 1.1);
    std::cout << std::get<std::string>(hi) << " " << std::get<int>(hi) << " " << std::get<double>(hi) << std::endl;

    // tie
    std::string name; 
    int month, day;
    std::tie(name, month, day) = Day2;
    std::cout << name << " " << month << " " << day << std::endl;

    auto [hi1, h12, hi3] = Day3;
    std::cout << hi1 << " " << h12 << " " << hi3 << std::endl;

    // dictionary key
    std::map<std::tuple <std::string, int, int> , int> dictionary;
    dictionary.insert(std::make_pair(Day1, 10));
    dictionary.insert(std::make_pair(Day2, 20));
    dictionary.insert(std::make_pair(Day3, 30));
    
    std::cout << "Element Day1 in dictionary is " << dictionary[Day1] << std::endl;
}