//###########
//# nested maps
//###########

#include <iostream>
#include <map>

using namespace std;

using level_map = map<int, string>;
// typedef map<int, string> level_map;          // Before C++11

void print(const map<int, level_map>& game_map){
    cout << "Game map:" << endl;
    for (auto level : game_map){
        cout << "Level " << level.first << ":" << endl;
        for (auto element : level.second){
            cout << "  " << element.first << ": " << element.second << endl;
        }
    }
    cout << endl;
}

int main(){
    // map<int, string>  level_one_map = {
    //     {1, "player"},          // Element with key 1
    //     {10, "door"}            // Element with key 10
    // };

    level_map level_one_map = {
        {1, "player"},          // Element with key 1
        {10, "door"}            // Element with key 10
    };
        

// map<int, string> level_two_map = {
//     {5, "player"},       
//     {10, "monster"}
// };

    level_map level_two_map = {
        {5, "player"},       
        {10, "monster"}
    };


// Game map
// map<int, map<int, string>> game_map = {
//     {1, level_one_map},         // Element with key 1
//     {2, level_two_map}          // Element with key 2

map<int, level_map> game_map = {
    {1, level_one_map},         // Element with key 1
    {2, level_two_map}          // Element with key 2
};


print(game_map);

/*
for (auto [l_no, l_map] : game_map){
    cout << "Level " << l_no << "map:" << endl;
    for (auto [position, object] : l_map){
        cout << " Position = " << position << " Object = " << object << endl;
    }
}  
*/

cout << "Inserting a new entity into level 2 \n";
auto level2 = game_map.find(2);                         // Iterator to level 2 element

if (level2 != end(game_map)){
    level2->second.insert({3, "magic sword"});          // Add a new entity to level 2
}

print(game_map);

cout << "Inserting a new level\n";

level_map level_three_map = {                           // Create another level map
    {7, "player"},
    {8, "bomb"}
};

game_map.insert({3, level_three_map});                  // Add the level map to the game map

print(game_map);

cout << "Removing element with key 10 from level 2\n";

auto& lmap = level2->second;                            
auto ten = lmap.find(10);                               // Iterator to element with key 10
if (ten != end(lmap)){
    lmap.erase(ten);   
}                                 // Remove element with key 10

print(game_map);



};


