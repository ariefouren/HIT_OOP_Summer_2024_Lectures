class A {
    public:
    explicit A(int i) {x=i;}
    explicit operator int() {return x;}
    int x;
};

void main()
{
    A a1(5); int i = 3; // Line 10
    A a2 = i;           // Line 11
    i = a1;             // Line 12
    i = (int) a1;       // Line 13
    a1 = (A)i;          // Line 14
}
