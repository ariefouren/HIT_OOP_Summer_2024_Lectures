#include <iostream>
using namespace std;

class Animal{
	int itsWeight;
public:
	Animal(int w = 0):itsWeight(w) {}
	~Animal() {}
    operator int() const { return itsWeight; }
	int GetWeight() const { return itsWeight; }
    void SetWeight(int w) { itsWeight = w; }
	void Display() const { cout << itsWeight; }
};
template <class T> class Array{
public:
	Array(int size = 10) :itsSize(size) {
		pType = new T[size];
		for (int i = 0; i < size; i++) pType[i] = T();
	}
	~Array() { delete[] pType; }
	T& operator[](int offSet) { return pType[offSet]; }
	const T& operator[](int offSet) const{return pType[offSet];	}
	int GetSize() const { return itsSize; }
	template <class T> friend ostream& operator<<(ostream&, Array<T>&);
private:
	T* pType;
	int  itsSize;
};
template <class T> ostream& operator<<(ostream& output, Array<T>& theArray){
	cout << "[";
    for (int i = 0; i < theArray.GetSize(); i++){
        cout << theArray[i];
        if (i < theArray.GetSize() - 1) cout << ", ";
    }
    cout << "]";
	return output;
}
int main(){
	Array<int> iArray(3);
	for (int i = 0; i < iArray.GetSize(); i++)
		iArray[i] = i;
	cout << iArray;

	Array<Animal> aArray(3);
	for (int i = 0; i < aArray.GetSize(); i++)
		aArray[i].SetWeight(i * 10);
	cout << aArray;
	return 0;
}
