// File: ex_03_primes.cpp
// checks and prints prime numbers in a range using threads
// the threads use a shared counter to balance the work

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <atomic> // for atomic

using namespace std;

// checks if a number is prime using lambda expression
auto is_prime = [](int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
};

int main() {
    // create a vector of threads
    vector<thread> threads;

    // launch 10 threads, each thread checks and prints prime numbers in a range
    cout << "--- main: launching 10 threads...\n";
    atomic<int> counter(2); // shared counter to balance the work
    int last_number = 1000;
    for (int id = 0; id < 10; ++id) {
        // function (lambda expression) executed by each thread
        // captures the thread id, the last number in the range to check
        // and the reference to a shared counter to balance the work
        threads.push_back(thread([id, last_number, &counter]() {
            while (true) {
                // get the next number to check
                // atomic fetch_add returns the value before the increment
                // the operation is atomic, so no two threads can get the same number
                int number = counter.fetch_add(1);
                if (number > last_number) break;
                if (is_prime(number)) {
                    string msg = "# " + to_string(id) + ": " + 
                        to_string(number) + " is prime\n";
                    cout << msg;
                }
            }
        }));
    }
    cout << "--- main: all threads launched\n";

    // wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }
    cout << "--- main: all threads finished\n";

    return 0;
}
