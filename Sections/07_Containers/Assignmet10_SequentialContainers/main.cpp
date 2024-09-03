// main.cpp
#include <iostream>
#include <vector>
#include <algorithm>


// #include "url.h"

//.h file
class URL {
    std::string protocol;
    std::string resource;
public:
    URL(const std::string& prot, const std::string& res);
    std::string getURL() const;
    void print() const;

    bool operator==(const URL& rhs) const;
};

class URLHistory {
    std::vector<URL> history;
public:
    URLHistory();
    URLHistory(const URL& url);

    void addURL(const URL& url);
    void printHistory() const;
};


// .cpp file

URL::URL(const std::string& prot, const std::string& res) : protocol(prot), resource(res) {}

void URL::print() const {
    std::cout << protocol << "://" << resource << "\n";
}

std::string URL::getURL() const {
    return protocol + "://" + resource;
}

bool URL::operator==(const URL& rhs) const {
    return protocol == rhs.protocol && resource == rhs.resource;
}


URLHistory::URLHistory() : history() {}

URLHistory::URLHistory(const URL& url) : history(1, url) {}

void URLHistory::addURL(const URL& url) {
    auto it = std::find(history.begin(), history.end(), url);
    if (it != history.end()) {
        history.erase(it);
    }
    history.insert(history.begin(), url);
}

void URLHistory::printHistory() const {
    std::cout << "Printing history" << std::endl;
    for (const URL& url : history) {
        url.print();
    }
}

// main


int main() {
    std::cout << "Hello, World!" << std::endl;
    URL url = URL("http", "example.com/index.html");
	url.print();

    URL url2("http", "example2.com/index.html");

    URLHistory history;
    history.addURL(url);
    history.addURL(url2);

    history.printHistory();

    history.addURL(url);

    history.printHistory();

    return 0;
    
    
}