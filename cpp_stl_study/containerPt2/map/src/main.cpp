#include <iostream> 
#include <map>

int main() {

    std::map<std::string, std::string> office = {{"Lea", "Robotics"},
                                                {"Kevack", "Robotics"},
                                                {"Jean", "Platform"},
                                                {"Andertony", "Robotics"}};
    for (auto it: office) {
        std::cout << it.first << " " << it.second << std::endl;
    }
    
    std::cout << std::endl;
    std::cout << "FIND " << std::endl;
    auto findValue = office.find("Jean"); 
    std::cout << findValue->first << " " << findValue->second << std::endl;

    std::cout << std::endl;
    std::cout << "INSERT " << std::endl;
    office.insert(std::make_pair("Flody", "Robot"));
    for (auto it: office) {
        std::cout << it.first << " " << it.second << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Change value" << std::endl;
    office["Kevin"] = "Platform+Robotics";
    for (auto it: office) {
        std::cout << it.first << " " << it.second << std::endl;
    }


    std::cout << std::endl;
    std::cout << "EXTRACT : change key" << std::endl;
    auto nh = office.extract("Jean"); //c++17
    if (!nh.empty()) {
        nh.key() = "Leedo";
        office.insert(std::move(nh));
    }
    for (auto it: office) {
        std::cout << it.first << " " << it.second << std::endl;
    }
}