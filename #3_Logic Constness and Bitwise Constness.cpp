#include <iostream>
#include <memory>
#include <vector>
#include <string>


// const -- a compile time constaint than an object can not be modified
// const reference parameter example void setAge(const int& a)

class BigArray
{
private:
	std::vector<int> v; 
	//int accessCounter = 0; //will not work however we can use mutable
	mutable int accessCounter = 0;
	int* v2; //another int array

public:
	int getItem(int index) const
	{
		accessCounter++; 
		//second option assuming 'mutable' does not exist. 
		//Then the line int accessCounter = 0; will work 
		const_cast<BigArray*>(this)->accessCounter++;  
		return v[index];
	}

	//will compile with const because the bitwise constness will remain same.
	//We havent changed any of the members directly
	void setV2Item(int index, int x) const
	{
		*(v2 + index) = x; //item at position 'index' to be an x;
	}
};

 //lesson of the day: use mutable members to implement logical constness


int main() {
	
	BigArray b;

	system("pause");
	return 0;
}
