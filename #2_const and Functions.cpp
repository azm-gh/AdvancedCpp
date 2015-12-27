#include <iostream>
#include <memory>
#include <vector>
#include <string>


// const -- a compile time constaint than an object can not be modified
// const reference parameter example void setAge(const int& a)

class Dog
{
	int age;
	std::string name;
public:
	Dog() { age = 3; name = "Rex"; }
	//const parameter
	//if we remove the & reference it is not very useful 
	//since its passed by value and therefore making a copy
	void setAge(const int& a) { age = a; }
	void setAge(int& a) { age = a; } //when this and the above is called ? Homework

	//const return value
	const std::string& getName() { return name; }

	// const function -- this function will not change any of the member variables of our class
	// if we would add eg age++; to the function body the code will not compile. You also cant call eg getName
	// const function can only call another const function
	void printDogName() const { std::cout << name << "const" << std::endl; }  // for const dog
	void printDogName() { std::cout << getName() << "non-const" << std::endl; }	  // for non-const dog	
};


int main() {
	
	Dog d;

	int i = 9;
	d.setAge(i);
	std::cout << i << std::endl;

	const std::string& n = d.getName();
	std::cout << n << std::endl;

	d.printDogName();

	const Dog d2;
	d2.printDogName();
	
	system("pause");
	return 0;
}
