#include <iostream>
#include <tuple> 
#include <string>
#include <map>


int main() {

    // PAIR

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
}