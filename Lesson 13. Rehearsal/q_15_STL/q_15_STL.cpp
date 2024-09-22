#include <vector>
#include <iostream>
using namespace std;

int main(){
	vector<int> first(7, 100);
	vector<int>::iterator it;
	int myints[] = { 1776,8,4 };
	first.push_front(myints[0]);
	first.push_front(myints[1]);
	first.push_back(myints[2]);
	it = first.begin() + 1;
	cout << first.size() << " " << *it << '\n';
	return 0;
}
