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
 
bool byName(Person a, Person b) {
    return a.name < b.name;
}

bool byAge(Person a, Person b) {
    return a.age < b.age; 
}

void print_person(vector<Person> &v){
    for(auto it=v.begin(); it<v.end(); it++){
        cout << "[" << it->name << ", " << it->age << "]";
    }
    cout << endl;
}

bool byFirst(pair<int,int> a, pair<int,int> b) {
    return a.first < a.second; 
}

bool bySecond(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second; 
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

int main(){

    // sort, partial_sort
    vector<Person> group {Person("Bob", 18), Person("Alice", 20), Person("Stacy", 5), Person("Brad", 5)};
    
    cout << "Before sort" << endl;
    print_person(group); 
    cout << endl;

    cout << "After partial sort" << endl;
    partial_sort(group.begin(), group.begin()+2, group.end(), byName);
    print_person(group);
    cout << endl;

    cout << "After name sort" << endl;
    sort(group.begin(), group.end(), byName); 
    print_person(group); 
    cout << endl;

    cout << "After age sort" << endl;
    sort(group.begin(), group.end(), byAge); 
    print_person(group); 
    cout << endl;

    // stable_sort 
    cout << endl;
    vector<pair<int, int>> pairs{make_pair(1,5), make_pair(2,3), make_pair(1,3), make_pair(3,5), make_pair(3,2), make_pair(1,2)}; 

    cout << "Before stable sort" << endl;
    print_pair(pairs);
    cout << endl;

    cout << "Stable sort by first" << endl;
    stable_sort(pairs.begin(), pairs.end(), byFirst);
    print_pair(pairs);
    cout << endl;
    
    cout << "Stable sort by second" << endl;
    stable_sort(pairs.begin(), pairs.end(), bySecond);
    print_pair(pairs);
    cout << endl;

    // nth_element
    vector<int> numbers{3,1,2,7,6,5,4}; 

    cout << endl;
    cout << "Before nth-element" << endl;
    print_int(numbers);
    cout << endl;

    cout << "Nth element as 3" << endl;
    nth_element(numbers.begin(), numbers.begin()+3, numbers.end());
    print_int(numbers);

    return 0;
}
 
