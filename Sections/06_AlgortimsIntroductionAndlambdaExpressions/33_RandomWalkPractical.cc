//############
// Random Walk Practical
//############

/*
- A "random walk" occurs when a moving physical object changes direction at random
    - Also known as a "drunkard's walk"
    - Brownian motion in physics

- Describes many natural processes
    - Flight path of insects
    - movement of molecules in a gas
    -  Financial markets?

- used in games to make characters move unpredictably

*/

#include <iostream>
#include <random>
#include <thread>
#include <string>

using namespace std;

int main(){
    int x{0};
    int vx{0};
    const int width{40};
    string blank_line(width, ' ');

    mt19937 mt;
    bernoulli_distribution bd;

    while (true){
        if (bd(mt)){
            vx = 1;

            if (x == width)
                vx = -1;
        }
        else{
            vx = -1;

            if (x == 0)
                vx = 1;
        }

        x += vx;
        cout << "\r" << blank_line;
        string position(x, ' ');
        cout << "\r" << position << "." << flush;

        this_thread::sleep_for(100ms);


    }

}


