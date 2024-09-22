class A {
public:
	A(int x = 0):v(x) {};
	A(const A& a): v(a.v){};

	int v;
};

int main()
{
	A a0;
	A a1 = A(1);
	A a2(2);
	A a3(a0);
	A a4 = a0;
	A a5;
	a5 = a0;
}
