/*
Abstract class is a class which contains atleast one pure virtual function.

Object of abstract class cannot be created.

It is used for:
 
	1. To Define a common interface.
	2. to achieve runtime Polymorphism.
	3. To enforce imlementaion in derived class.
	4. To implemet specific behaviour.

Common Interview Questions:

	1. Can we instantiate an abstract class?
	2. Can an abstract class have constructors?
	3. Can an abstract class have data members?
	4. Difference between abstract class and interface.

Key Points: 
	1. Cannot instantiate an abstract class.
	2. Can contain constructors.
	3. Can have data members.
	4. Can have normal member functions.
	5. Must contain at least one pure virtual function.
*/

/*NOTE: For runtime polymorphism, all three conditions are required:
✅ The function must be virtual.
✅ You must call it through a base class pointer or reference.
✅ The pointer/reference must actually refer to a derived object.
*/

#include <iostream>

using namespace std;
class AbstractClass{
	
	public:
	virtual void Print() = 0;

	virtual ~AbstractClass() = default; //makes a destructor virtual and asks the compiler to create a default version of it. Safe cleanup: Stops memory leaks when deleting a child object using a pointer to the parent class.

	
};

class Derived : public AbstractClass{

	public:
	void Print() override
	{
		cout<<"Derived Class function overriden";
	}
};

int main()
{
	Derived d ;
	d.Print();
	//Above doesn't do not do dynamic dispatch as at compile time itself compilet knows that d is derived class object.

	AbstractClass* obj = &d; //Now at compilet time compiler only know the type of pointer, it needs dynmaic dispatch to resolve the function call at runtime.
	obj->Print();
	return 0;
}
