
//############
// Default initialization
//############

/*
Data members are default initialized if no initializer is provided.
For built-in types, default initialization means that the variable is not initialized.
*/

#include <iostream>

using namespace std;

class Internet {
    public:
        void connect() {
            cout << "Connecting to the internet..." << endl; }
        void login(const string&  id, const string& pw){
            cout << "Logging in with id: " << id << " and password: " << pw << endl; }      
};

class refrigerator {
    int temperature{2};
    bool door_open{false};
    bool power_on{true};
    Internet internet;

    void init(const string& id, const string& pw) {
    internet.connect();
    internet.login(id, pw);
    }
public:

/*
    // Default constructor
    refrigerator() {
        init("admin", "admin");
    }

    //Constructor using default login
    refrigerator(int temperature): temperature{temperature} {
        init("admin", "admin");
    }

    // Constructor using default temperature
    refrigerator(const string& id, const string& pw){
        init(id, pw);
    }

    // Constructor with no default values

    refrigerator(int temperature, const string& id, const string& pw): temperature{temperature} {
        init(id, pw);
    }
*/

    //Default Constructor
    refrigerator(): refrigerator(2, "admin", "admin") {}

    // Constructor using default login
    refrigerator(int temperature): refrigerator(temperature, "admin", "admin") {}

    // Constructor using default temperature
    refrigerator(const string& id, const string& pw): refrigerator(2, id, pw) {}

    // Constructor with no default values
    refrigerator(int temperature, const string& id, const string& pw): temperature{temperature} {
        init(id, pw);
    }

    void print() {
        cout << "Temperature: " << temperature << endl;
        cout << boolalpha;
        cout << "Door open: " << door_open << endl;
        cout << "Power on: " << power_on << endl;
    }
};

int main() {
    refrigerator fridge;
    fridge.print();
    return 0;
}