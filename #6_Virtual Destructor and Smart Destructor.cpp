
/*Using virtual destructors in a polymorphic base classes
https://www.youtube.com/watch?v=ZiNGWHg5Z-o&list=PLE28375D4AC946CC3&index=6
https://stackoverflow.com/questions/5873515/why-should-the-destructor-of-base-classes-be-virtual
https://stackoverflow.com/questions/20895648/difference-in-make-shared-and-normal-shared-ptr-in-c



If a class is to be used in polymoprhic way. Such as in this case where we create yellow dog
and then cast it into Dog* pointer, then the base class has to have virtual destructor to insure
the destructors are invoked appropriately.

If a class has some virtual function, it is most likely it will be used polymorphically which means
it will need virtual destructor

If you dont want to use virtual destructor you could use shared_pointer

Note: All classes in STL have no virtual destructor, so be careful inheriting from them. Use shared pointer
If you are deriving from STL classes

*/

class Dog
{
public:
	virtual ~Dog()  // without keyword virtual, only dog is destroyed
	{
		std::cout << "Dog destoyed" << std::endl;
	}
	virtual void bark();
};

class YellowDog : public Dog
{
public:
	~YellowDog()
	{
		std::cout << "Yellow dog is destroyed." << std::endl;
	}
};

class DogFactory
{
public:
	static Dog* createYellowDog()
	{
		return(new YellowDog());

	}
	//Create other dogs....
};


int main()
{
	Dog* pd = DogFactory::createYellowDog();
	//do something with pd

	delete pd;


	std::cout << std::endl;
	system("pause");
	return 0;
	
	
//------------------------------------------------------------------------------------------------------------
// Second version with shared_ptr as explained in the beginning

class Dog
{
public:
	 ~Dog()  // without keyword virtual, only dog is destroyed
	{
		std::cout << "Dog destoyed" << std::endl;
	}
	 virtual void bark() {};
};

class YellowDog : public Dog
{
public:
	~YellowDog()
	{
		std::cout << "Yellow dog is destroyed." << std::endl;
	}
};

class DogFactory
{
public:
	static std::shared_ptr<Dog> createYellowDog()
	{
		return std::shared_ptr<YellowDog>(new YellowDog());

	}
	//Create other dogs....
};


int main()
{
	std::shared_ptr<Dog> pd = DogFactory::createYellowDog();
	//do something with pd

	
	std::cout << std::endl;
	system("pause");
	return 0;
