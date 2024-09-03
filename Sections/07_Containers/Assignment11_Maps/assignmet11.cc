/* You will write a program that:
Reads words entered by the user
Stores the value and length of each word in a suitable std::pair
Stores the pair object in a container
Prints out all the elements of the container


Questions for this assignment

Implement this program, using std::vector to store the data.
What do you notice about the output?
Implement this program, using std::map to store the data.
What do you notice about the output?
Explain your results.
Run your programs again, but this time enter some duplicate words.
Explain your results.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

int main() {
    std::vector<std::pair<std::string, int>> words;
    std::map<std::string, int> words_map;
    std::string word;

    std::cout << "Enter words: ";
    while (std::cin >> word) {
        words.push_back(std::make_pair(word, word.size()));
        words_map.insert(std::make_pair(word, word.size()));
    }

    std::cout << "Words Vector: " << std::endl;
    for (const auto& word : words) {
        std::cout << word.first << " " << word.second << std::endl;
    }

    std::cout << "Words Map: " << std::endl;
    for (const auto& word : words_map) {
        std::cout << word.first << " " << word.second << std::endl;
    }

    return 0;
}