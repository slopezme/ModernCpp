#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <functional>
#include <fstream>
#include <iterator>
#include <sstream>
#include <set>


using namespace std;

template <typename T>
void printVector(const vector<T>& v) {
    for (auto i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}



void fillVector(vector<int>& v) {
    generate_n(back_inserter(v), 10, []() { return rand() % 1000; });
    printVector(v);
}



void findMax(const vector<int>& v) {

}



int main() {
    //1. Function to fill a vector with 10 random integers between 0 and 1000
    vector<int> v;
    generate_n(back_inserter(v), 10, []() { return rand() % 1000; });
    printVector(v);

    //2. Find the maximum element in this vector
    int max = *max_element(v.cbegin(), v.cend());
    cout << "Max element: " << max << endl;   

    //3. Find the index of this maximum element
    auto it = find(v.cbegin(), v.cend(), max);
    cout << "Index of max element: " << distance(v.cbegin(), it) << endl;

    //4. Sum the elements of the vector

    int sum = accumulate(v.cbegin(), v.cend(), 0);
    cout << "Sum of elements: " << sum << endl;

    // 5. Count the number of odd numbers in the vector

    int numberOfOdd = count_if(v.cbegin(), v.cend(), [](int x) { return x % 2 != 0; });
    cout << "Number of odd numbers: " << numberOfOdd << endl;

    // 6. Normalize the vector (divide all the elements by the largest.) Put
    // the normalized elements into a vector of doubles, without setting
    // the size of the output vector first

    vector<double> normalized;
    transform(v.cbegin(), v.cend(), back_inserter(normalized), [max](int x) { return (double)x / max; });
    printVector(normalized);

    //7. Make a sorted copy of the vector. Without using a functor or a
    // lambda (or equivalent), find the first element greater than 455 and
    // the number of elements > 455

    vector<int> sorted(v);
    sort(sorted.begin(), sorted.end());

    auto it2 = find_if(sorted.cbegin(), sorted.cend(), [](int x) { return x > 455; });
    cout << "First element greater than 455: " << *it2 << endl;

    int numberOfElementsGreaterThan455 = sorted.cend() - it2;
    cout << "Number of elements greater than 455: " << numberOfElementsGreaterThan455 << endl;

    // 8. Copy all the odd numbers to a vector of doubles, without setting
    // the size of the output vector first

    vector<double> oddNumbers;
    copy_if(v.cbegin(), v.cend(), back_inserter(oddNumbers), [](int x) { return x % 2 != 0; });

    // 9. Sort the vector in descending order

    sort(v.begin(), v.end(), greater<int>());
    printVector(v);

    // 10. Randomly shuffle all but the first and the last element of the vector

    shuffle(v.begin() + 1, v.end() - 1, default_random_engine());
    printVector(v);

    // 11. Remove all the odd numbers from the vector

    v.erase(remove_if(v.begin(), v.end(), [](int x) { return x % 2 != 0; }), v.end());
    printVector(v);

    // 12. Write the remaining elements to a text file on a single line as a
    // comma separated list, without a trailing comma

    ofstream outFile("output.txt");
    if (!v.empty()) {
        copy(v.begin(), v.end() - 1, ostream_iterator<int>(outFile, ","));
        outFile << v.back();
    }

    // 13) Read the file "words.txt". Display each distinct word once. Ignore 
    // punctuation and capitalization
    // Hint: look into std::istreambuf_iterator

    // 15) Count the total number of words in the file
    // 16) Count the number of lines in the file
    // 17) Count the number of characters in the file
    // Copyright © James Raynard 2023

    //     18) Read "words.txt" and "words2.txt". Display the words which are 
    // common to both files



    ifstream inFile("words.txt");
    ifstream inFile2("words2.txt");

    if (inFile.is_open() && inFile2.is_open()) {
        // Read the entire content of the files into strings
        string text((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
        string text2((istreambuf_iterator<char>(inFile2)), istreambuf_iterator<char>());

        // Transform to lowercase and remove punctuation
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        replace_if(text.begin(), text.end(), [](char c) { return ispunct(c); }, ' ');

        // Convert string to vector of words
        istringstream iss(text);
        vector<string> words{istream_iterator<string>{iss}, istream_iterator<string>{}};

        // Sort the words to find unique ones
        sort(words.begin(), words.end());
        auto last = unique(words.begin(), words.end());
        words.erase(last, words.end());

        // Output unique words
        for (const auto& word : words) {
            cout << word << " ,";
        }
        cout << endl;

        // Output statistics
        cout << "Total number of unique words: " << words.size() << endl;
        cout << "Number of lines: " << count(text.begin(), text.end(), '\n') + 1 << endl;  // +1 to count the last line without \n
        cout << "Number of characters: " << text.size() << endl;

        // Transform and process the second file
        transform(text2.begin(), text2.end(), text2.begin(), ::tolower);
        replace_if(text2.begin(), text2.end(), [](char c) { return ispunct(c); }, ' ');

        istringstream iss2(text2);
        vector<string> words2{istream_iterator<string>{iss2}, istream_iterator<string>{}};

        // Sort the second list of words
        sort(words2.begin(), words2.end());
        words2.erase(unique(words2.begin(), words2.end()), words2.end());

        // Find and output common words
        vector<string> common;
        set_intersection(words.begin(), words.end(), words2.begin(), words2.end(), back_inserter(common));

        cout << "Common words: ";
        for (const auto& word : common) {
            cout << word << " ";
        }
        cout << endl;
    } else {
        cout << "Failed to open one or both files." << endl;
    }


    // 19)Calculate the factorial of 6 (6 x 5 x 4 x ... x 1)

    std::vector<int> numbers(6);
    std::iota(numbers.begin(), numbers.end(), 1);
    int factorial = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());
    std::cout << "Factorial of 6: " << factorial << std::endl;









    










    return 0;
}
