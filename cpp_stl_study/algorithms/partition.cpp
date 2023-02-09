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
 
bool is_underage(Person &a) {
    return a.age < 20; 
} 

bool is_legalage(Person &a) {
    return a.age >= 20; 
} 

void print_person(vector<Person> &v){
    for(auto it=v.begin(); it<v.end(); it++){
        cout << "[" << it->name << ", " << it->age << "]";
    }
    cout << endl;
}

void print_pair(vector<pair<int,int>> &v){
    for(auto it=v.begin(); it<v.end(); it++){
        cout << "[" << it->first << ", " << it->second << "]";
    }
    cout << endl;
}

void print_int(vector<int> &v){
    for(auto it=v.begin(); it<v.end(); it++){
        cout <<  *it << " ";
    }
    cout << endl;
}

bool negative_sum(pair<int,int> &p) {
    return p.first+p.second < 0; 
}


int main(){

    // partition, stable_partition
    vector<Person> group {Person("Stacy", 5), Person("Bob", 22), Person("Alice", 20), Person("Brad", 5)};
    
    cout << "Before partition" << endl;
    print_person(group); 
    cout << endl;

    cout << "After stable partition by age" << endl;
    stable_partition(group.begin(), group.end(), is_legalage);
    print_person(group); 
    cout << endl;

    cout << "After partition by age" << endl;
    partition(group.begin(), group.end(), is_underage);
    print_person(group); 
    cout << endl;

    // partition_point
    cout << endl;
    vector<pair<int, int>> pairs{make_pair(1,3), make_pair(-2,4), make_pair(1,-3), make_pair(3,2), make_pair(-3,2), make_pair(1,5)}; 

    cout << "Before partition point " << endl;
    print_pair(pairs); 
    cout << endl;

    cout << "Negative sum partiton point" << endl;
    partition_point(pairs.begin(), pairs.end(), negative_sum); 
    print_pair(pairs); 
    cout << endl;

    return 0;
}
 
