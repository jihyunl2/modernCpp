#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 
class Person {
    public:
        Person(string name_, int age_) : name(name_) , age(age_) {};

        string name;
        int age;
};
 
bool older(Person &a, Person &b) {
    return a.age < b.age; 
}

void print_person(vector<Person> &v){
    for(auto it=v.begin(); it<v.end(); it++){
        cout << "[" << it->name << ", " << it->age << "]";
    }
    cout << endl;
}

int main(){

    // min, max
    vector<Person> group {Person("Stacy", 5), Person("Bob", 22), Person("Alice", 20), Person("Brad", 5)};
    
    print_person(group);
    cout << endl;

    auto oldest = max_element(group.begin(), group.end(), older);
    cout << "Oldest person in group is " << oldest->name << endl;

    auto youngest = min_element(group.begin(), group.end(), older);
    cout << "Youngest person in group is " << youngest->name << endl;

    auto old_young = minmax_element(group.begin(), group.end(), older);
    cout << "Oldest and youngest in group is " << old_young.first->name << " and " << old_young.second->name << endl;

    cout << endl;

    // max, min
    int small = min(3,4);
    cout << small << " is smaller" << endl;
    int big = max(3,4);
    cout << big << " is bigger" << endl;

    return 0;
}
 
