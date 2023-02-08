#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

 
class Person {
    public:
        Person(string name_, int age_) : name(name_) , age(age_) {};

        bool operator== (Person const &obj) {
            return (name == obj.name && age == obj.age); 
        }

        string name;
        int age;

};
 
bool is_underage(Person &a) {
    return a.age < 20; 
} 

bool is_legalage(Person &a) {
    return a.age >= 20; 
}

void aging(Person &a) {
    a.age += 1;
}

void print_person(vector<Person> &v){
    for(auto it=v.begin(); it<v.end(); it++){
        cout << "[" << it->name << ", " << it->age << "]";
    }
    cout << endl;
}


int main(){

    // all_of, any_of, none_of
    vector<Person> group {Person("Stacy", 25), Person("Bob", 2), Person("Alice", 1), Person("Brad", 5)};
    
    print_person(group);
    cout << endl;

    if (all_of(group.begin(), group.end(), is_underage)) {
        cout << "Everyone in group is underage" << endl;
    } else if (any_of(group.begin(), group.end(), is_underage)){
        cout << "At least one person in group is underage" << endl;
    } else {
        if (none_of(group.begin(), group.end(), is_underage)) {
            cout << "No one in group is underage " << endl;
        } else {
            cout << "Error" << endl;
        }
    }

    cout << endl;

    // count, count_if
    if (any_of(group.begin(), group.end(), is_underage)) {
        cout << "Number of underage people in group: " << count_if(group.begin(), group.end(), is_underage) << endl;
    } else {
        cout << "None" << endl;
    }

    cout << endl;

    if (count(group.begin(), group.end(), Person("Alice", 1))){
        cout << "Person exists in group" << endl;
    } else {
        cout << "Person doesn't exist" << endl;
    }

    cout << endl;

    // for_each
    for_each(group.begin(), group.end(), aging);
    print_person(group);
    cout << endl;

    // find, find_if
    auto child = find(group.begin(), group.end(), Person("Alice", 2)); 
    if (child == group.end()) {
        cout << "Alice 10 not found" << endl;
    } else {
        cout << child->name  << " found" << endl;
    }

    auto child2 = find_if(group.begin(), group.end(), is_underage);
    cout << "First underage person is " << child2->name << endl;

    cout << endl;

    // find_end : last common sub group element 
    vector<Person> group2 {Person("Bob", 3), Person("Alice", 2)};

    auto common_last = find_end(group.begin(), group.end(), group2.begin(), group2.end());
    cout << "Last common occurence " << common_last->name << endl;

    cout << endl;

    // search, search_n
    auto common_start = search(group.begin(), group.end(), group2.begin(), group2.end()); 
    cout << "Group2 is present at index " << common_start-group.begin() << endl;

    int count_bob = 1; 
    auto search_n_ = search_n(group.begin(), group.end(), count_bob, Person("Bob", 3));
    if (search_n_ != group.end()) {
        cout << "Bob is present " << count_bob << " time(s) in group" << endl; 
    } else {
        cout << "Bob is not present in group" << endl; 
    }

    return 0;
}
 
