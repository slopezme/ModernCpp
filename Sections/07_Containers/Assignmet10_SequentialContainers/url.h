#ifndef URL_H
#define URL_H

#include <string>
#include <vector>

class URL {
    std::string protocol;
    std::string resource;
public:
    URL(const std::string& prot, const std::string& res);
    std::string getURL() const;
    void print() const;

    bool operator==(const URL& rhs) const;
};

// class URLHistory {
//     std::vector<URL> history;
// public:
//     URLHistory();
//     URLHistory(const URL& url);

//     void addURL(const URL& url);
//     void printHistory() const;
// };

#endif // URL_H
