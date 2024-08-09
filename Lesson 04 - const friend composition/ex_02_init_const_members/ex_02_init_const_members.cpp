// File: ex_02_init_const_members.cpp
// demonstrates how to initialize const members in the constructor
#include <iostream>
using namespace std;

class Item
{
    public:
    Item(int i, double p) : 
        id(i),  // const data member can be initialized 
                // only in the initializer list
        price(p) // not-const data member can be initialized 
                // in the initializer list or in the constructor body
    {
      // id = i; // error: assignment of read-only member 'Item::i'
    }

    void print() const
    {
        cout << "Item id: " << id << ", price: " << price << endl;
    }
    private:
    const int id; // items' id, a constant data member
    double price;   // items' price, a non-constant data member
};

int main()
{
    Item item(1, 10.0);
    item.print();

    return 0;
}