
//###########
//# Emplacement
//###########

/*
C++11 Introduced emplacement
    - Another way to add elements to a container

member functions like push_back() and insert() requiere an existing object
    - The container copies the existing object into the new element
    - If there is no existing object, we need to create a temporary object

With emplacement,  the container creates the object in the new element, instead of copying it
    - This avoids a copy constructor call



*/


//###########
//# Draw back of insert
//###########

/*
insert() copies its argument into the newly-created element
    - If we want to insert a new object, we have to create a temporary variable

    vector<refrigerator> vec;

    refrigerator fridge(2, false, true);            // Create a new refrigerator
    vec.insert(begin(vec), fridge);                 // Add an element to a copy fridge into it
    ...                                             // fridge is no longer needed

    -// Add an element, create temporary object and copy it
    vec.insert(end(vec), refrigerator(2, false, true));

*/

//###########
//# emplace()
//###########

/*
C++11 has emplace()
    - We pass the constructor arguments
    - These arguments are forwarded to the objects constructor
    - The new object is created directly in the container element

    vec.emplace(begin(vec), 2, false, true);         // Add an element and create it in place


*/


//###########
//# emplace() and push()
//###########

/*
For containers that support push_back(), there is a emplace_back()
- This adds an element at the back of the container and created a new object in it

    vec.push_back(refrigerator(4, true, true));      // Add an element, create temporary object and copy it
    vec.emplace_back(5, false, true);                 // Add an element and create it in place

There is also emplace_front(), for containers that support push_front()

emplace() for container adapters instead of push()

*/

//###########
//# emplacement with std::map
//###########

/*
- Emplacement works differently with containers that have unique keys
    - for std::set and std::map, emplace() creates a temporary object
    - It then checks if there is an element with the same key

C++17 provided an improved version of emplace() for maps
    - trye_emplace() checks for duplicates bofore creating the new element object
    - If there already is an element with the same key, nothing happens


*/

//###########
//# try_emplace()
//###########

/*
try_emplace() performs "piece-wise" construction of the map's std::pair
    - The "first" and "second" members are initilized using their constructors
- the first argument to try_emplace() is the new element's key
- The remaining arguments are the arguments to the value's consctructor
- the returned value is the same as insert()

    auto[iter, success] = fridges.try_emplace("Not in use"s,5, false, false);

    if (success){
        ...
    } 

*/


#include <iostream>
#include <vector>

using namespace std;

class refrigerator{
    // Data members
    int temperature;
    bool door_open;
    bool power_on;

    public:
        // Constructor
        refrigerator(int temp, bool open, bool power) : temperature(temp), door_open(open), power_on(power){
            cout << "Refrigerator created\n";
        }

        void print() {
            cout << "Temperature: " << temperature ;
            cout <<  boolalpha << " Door open: " << door_open;
            cout << " Power on: " << power_on << endl;
        }
};

void  example1() {
    vector<refrigerator> vec;

    refrigerator fridge(2, false, true);            // Create a new refrigerator
    vec.insert(begin(vec), fridge);                 // Add an element to a copy fridge into it

    vec.insert(end(vec), refrigerator(3, false, true));    // Add an element, create temporary object and copy it
    vec.emplace(end(vec), 2, false, false);           // Add an element and create it in place

    cout << "Vector elements:\n";

    for (auto& r : vec){
        r.print();
        cout << "\n";
    }



    vec.push_back(refrigerator(4, true, true));      // Add an element, create temporary object and copy it
    vec.emplace_back(5, false, true);                 // Add an element and create it in place

    cout << "Vector elements after push and emplace back:\n";
    for (auto& r : vec){
        r.print();
        cout << "\n";
    }

}

#include <map>
void example2(){
    map<string, refrigerator> fridges;

    refrigerator meat_fridge(2, false, true);
    fridges.insert_or_assign("Meat fridge"s, meat_fridge);      // Add an element, create temporary object and copy it

    fridges.insert_or_assign("Dairy fridge"s, refrigerator(3, false, true));    // Add an element, create temporary object and copy it

    auto [iter, success] = fridges.try_emplace("Not in use"s,5, false, false);

    if (success){
        cout << "Inserted the new element\n";
    } 
    else {
        auto [name , fridge] = *iter;               // Get the existing element
        cout << "Insert failed: ";
        cout << "existing element with name " << name ;
        fridge.print();
    }



}

int main(){
    cout << "Example 1\n";
    example1();

    cout << "\nExample 2\n";
    example2();

    return 0;
}

//###########
//# pros and cons of emplacement
//###########

/*
Emploacement is the only way to insert objects which cannot be copied

Emplacement will cause a temporary object to be created if
    - the container does not allow duplicates (std::set and std::map)
    - the implementation uses assignment rather than copying
    - A type conversion is requiered

Compilers can often optimize away the copy in insert()
Move semantics can avoid copying temporary objects

*/