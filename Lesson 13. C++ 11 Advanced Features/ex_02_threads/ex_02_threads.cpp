#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <string>
#include <random>        // for random number generation
using namespace std;


int main() {
    // create a vector of threads
    vector<thread> threads;

    // create 10 threads 
    // each thread prints its id, 
    // counts down from 10 to 0
    // prints "Liftoff!" and terminates

    cout << "--- main: launching 10 threads...\n";
    for (int id = 0; id < 10; ++id) {
        // the thread constructor takes as argument
        // a function to execute in the new thread
        // the function is a lambda expression 
        // that captures the id by value
        threads.push_back(thread([id]() {
            string msg;
            for(int i = 10; i > 0; --i) {
                msg = "#" + to_string(id) + "(" + to_string(i) + ") ";
                cout << msg;                
            }
            msg = "#" + to_string(id) + " Liftoff! \n";
            cout << msg;
        }));
    }
    cout << "\n--- main: all threads launched...\n";

    // wait for all threads to finish
    for (auto& t : threads) {
        // the t.join() method blocks the calling thread
        // until the thread t has finished executing
        t.join();
    }
    cout << "\n --- main: all threads have finished ---" << endl;

    return 0;
}

    