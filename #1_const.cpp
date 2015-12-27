#include <iostream>
#include <memory>
#include <vector>


// const -- a compile time constaint than an object can not be modified


int main() {
	const int i = 9;
	
	const int *p1 = &i;  //data is const, pointer is not
	//*p1 = 5; -- will not compile since we try to change the i value
	p1++;
	
	int z = 4;
	int* const p2 = &z; //opposite of p1. Pointer is const, data is not

	const int y = 5;
	const int* const p3 = &z;  //data and pointer are both const

	int const *p4 = &i; //same as above const int


	
	//Rule:
	//If const is on the left of the * data is const
	//If const is on the right of the * pointer is const
	int j = 9;
	const int& h = j;
	const_cast<int&>(h) = 6;  //will cast away the constness of i
	std::cout << j << std::endl;
	

	//dont you use cast unless really necessary

	/*
		Why use const:
			- Guard against inadverternt write to the variable.
			- Self documenting
			- Enable compiler to do more optimization, making code tighter
			- Const means the variable can be put in a rom
	*/
	



	system("pause");
	return 0;
}
