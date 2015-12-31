#include <memory>
#include <vector>
#include <string>
#include <iostream>

/*
	Calling Virtual Function in Constructor or Destructor
*/

class Dog
{
public: 
	Dog() { std::cout << "Dog born." << std::endl; /*bark();*/ } // in constructo it does not work
	virtual void bark() { std::cout << "Im just dog" << std::endl; }
	void seeCat() { bark(); }
	
};

class Yellowdog : public Dog
{
public:
	Yellowdog(){ std::cout << "Yellow Dog born." << std::endl;}
	virtual void bark() { std::cout << "I'm yellow dog" << std::endl; }
};



int main()
{

	Yellowdog d;
	d.seeCat(); 
	/* 
		d.seeCat(); // bark has to be virtual to make the yellow dog honest.
		In general the virtualness is being inherited so the bark in Yellow dog class is also virtual
		However it is good idea to put virtual there as well to make it explicit.
		Yellow dogs bark is invoked - dynamic binding

		If you put bark() in constructor of Dog it will not work since YellowDog is not constructed yet.
		It dangerous to call member function of an object that is not constructed yet unless its a static
		function.

		Lesson: Dont call virtual function in Constructor. Constructor should do as less as possible to put
		the object in a valid state. Same for destructor.

	*/
	
		
	std::cout << std::endl;
	system("pause");
	return 0;
}
