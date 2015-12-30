#include <iostream>
#include <memory>
#include <vector>
#include <string>

/*
	Prevent exceptions from leaving destructors
	https://www.youtube.com/watch?v=LQMYwvM8RF8&index=7&list=PLE28375D4AC946CC3
*/

class Dog
{
public:
	std::string m_name;
	Dog(std::string name)
	{
		m_name = name; 
		std::cout << name << " is born." << std::endl;
	}
	~Dog()
	{
		std::cout << m_name << " is destroyed.\n" << std::endl;
		//throw 20;
	}
	//void preparetoDestr() { ....; throw 20} -- solution 2.
	void bark()
	{
		std::cout << "Bark!\n";
	}
};


int main()
{
	try {
		Dog dog1("Henry");
		Dog dog2("Bob");
		//throw 20;
		dog1.bark();
		dog2.bark();
		//dog1.prepareToDestr();
		//dog2.prepareToDestr();
	
	}
	catch (int e)
	{
		std::cout << e << " is caught" << std::endl;
	}

	/*
		1. Scenario - throw inside main function
		output:
		Henry is born
		Bob is born
		Bob is destroyed - its stack so FIFO
		Henry is destroyed
		20 is caugh

		Point: Before the exception is caught by the catch block, the stack unwind and
		all the local variables inside the try block needs to be destroyed

		2. Scenario - throw inside destructor
		Two exceptions pending, one from Bob, one from Henry. C++ does not like to have more than 
		one exception at the same time, so it will crash.

		Solution 1:
		~Dog()
		{
			try
			{
				//enclose all exception prone code
			}
			catch (MYEXCEPTION e)
			{
				//Catch exception
			}
		}

		YOu could also add another catch block with elipsis. This will prevent
		any other unknown exception leaking out of a destructor
		catch(...){  ..not very useful since you dont get any error
		}

		Solution 2: Move the exception-prone code to a different function, not in a destructor.



	*/
	
	std::cout << std::endl;
	system("pause");
	return 0;
}
