#include <iostream>
#include <algorithm>
#include "url.h"

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

// URLHistory::URLHistory() : history() {}

// URLHistory::URLHistory(const URL& url) : history(1, url) {}

// void URLHistory::addURL(const URL& url) {
//     auto it = std::find(history.begin(), history.end(), url);
//     if (it != history.end()) {
//         history.erase(it);
//     }
//     history.insert(history.begin(), url);
// }

// void URLHistory::printHistory() const {
//     for (const URL& url : history) {
//         url.print();
//     }
// }
