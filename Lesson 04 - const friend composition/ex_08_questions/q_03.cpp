class C {
public:
    C(int x) {}
};

int main() {
    C obj1;     // Error: no default constructor
    C obj2(5);  // OK: uses the parameterized constructor
    C obj3 = obj2;
    obj2 = obj3;
}