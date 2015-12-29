
#include <iostream>
#include <memory>
#include <vector>
#include <string>


//Advanced C++: Compiler Generated Functions
//https://www.youtube.com/watch?v=EL30-a2gblQ&list=PLE28375D4AC946CC3&index=5

/*
Compiler silently writes 4 functions if they are not explicitly declared:
1) Copy constructor
2) Copy Assignment operator
3) Destructor
4) Default constuctor (only if there is no constructor declared).
All the compiler generated functions are public and inline.
They are generated only if they are needed.
*/

class OpenFile
{
public:
	//default constructor will not be generated
	OpenFile(std::string filename) 
	{
		std::cout << "Open a file " << filename << std::endl;
	}
	OpenFile(OpenFile& rhs) = delete;
	//lets define public interface
	void destroyMe() 
	{ 
		delete this; 
	}

private:
	//OpenFile(OpenFile& rhs); -- non C++11 solution is to make the code private
	OpenFile& operator=(const OpenFile& rhs); //disiable copy assignment operator or any function
	void WriteLine(std::string str);
	// Good idea to define destructor private ? Nope, unless its stored on the heap, See in main

	~OpenFile() 
	{
		std::cout << "OpenFile destructed" << std::endl; 
	} 
}; 
	 

int main()
{
	//OpenFile f(std::string("Bo_file")); 
	//f.destroyMe();

	//vs

	//This is needed if no default constructor is used
	OpenFile* f = new OpenFile(std::string("Bo_file"));
	f->destroyMe();
	
	//--------------------------------------------------------------------------------------------
	
	//copy constructor -- compiler generated. Both are now writing to a same file = Messy.
	// therefore I want to disallow the default copy constructor
	//OpenFile f2(f); will not compile if OpenFile(OpenFile& rhs) = delete; is used C++11

	

	//Conclusion: Class like open file which has a private destructor can only be stored on the heap.
	//Useful in embedded programming where the stack size is small.

	/*
		Summary of disallwoing Functions:
		1) C++11: f() = delete;
		2) C++03: Declare the function to be private and not define it
		3) Private des
	*/

	system("pause");
	return 0;
}
