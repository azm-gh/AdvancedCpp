#include <iostream>
#include <memory>
#include <vector>
#include <string>


//Advanced C++: Compiler Generated Functions
//https://www.youtube.com/watch?v=KMSYmY74AEs&index=4&list=PLE28375D4AC946CC3

/*
	Compiler silently writes 4 functions if they are not explicitly declared:
	1) Copy constructor
	2) Copy Assignment operator
	3) Destructor
	4) Default constuctor (only if there is no constructor declared).

	All the compiler generated functions are public and inline.
	They are generated only if they are needed.



class dog {};

 Equivalent to 

class dog
{
public:
	dog(const dog& rhs) { ... };	// Member by member initialization

	dog& operator=(const dog& rhs) { ... }; // Member by member copying

	dog() {...} // 1. Call base class default constructor.
				// 2. Call data member's default constructor.

	~dog() {...}; // 1. Call base class default destructor.
				  // 2. Call data member's default destructor.
};
*/


//Example 1

class dog
{
public:
	std::string m_name;

	dog(std::string name = "Bob")		//default constructor
	{
		m_name = name;
		std::cout << name << "Is born." << std::endl;
	}
	
	~dog()
	{
		std::cout << m_name << " is destroyed.\n" << std::endl;
	}
};


//Example 2

class Collar
{
public:
	//Collar() = default;
	Collar(/*std::string color*/)  //if we remove the default parameter for constructor it will compile. Unless Collar() = default; is used.
	{
		std::cout << "Collas ir born\n";
	}
};

class dog_sec
{
	Collar m_collar;
	//std::string& m_name; //is constructed but not initialized. All references need to be initialized. Will Not compile.
};

int main() {
	
	{
		dog dog1("Henry");
		dog dog2;
		dog2 = dog1;  // copy assignment operator by compiler, If string& m_name, code will not compile
	}
	{
		dog_sec dog3;  //will not compile since no default constructor is defined(if removed:std::string color)
	}			       // it will work.	


	/*
		Output:

		Henry is born
		Bob is born
		Henry is destroyed
		Henry is destroyed
		---------------------------------------------------
		In this example above the compiler generates for you:
		1. Copy constructor  -- not used in our main function, therefore is not generated
		2. Copy assignment operator -- used and created by compiler
		3. Destructor -- no need to genetate since its defined
		4. Default constructor -- noi as well, we have default contructor
		*Default constructor is a constructor which can work without any parameter.
		 It does not have to be empty!
	*/

	/*
	C++11 Update - this allow me to use compiler generated constructor even if I defined one
	class dog
	{
	public:
		dog() = default;
		dog(string name) { ... };
	};

	
	*/

	system("pause");
	return 0;
}
