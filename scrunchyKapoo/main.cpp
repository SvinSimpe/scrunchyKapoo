#include <iostream>
#include <memory>
#include <vector>
using namespace std;



template< typename T >
constexpr void PrintObjectSize( const T& object )
{
	try
	{
		std::cout << sizeof( object ) << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

class Base
{
	private:
		static unsigned int MakeID()
		{
			static unsigned int sID = 0;
			return sID++;
		
		}

	protected:
		unsigned int mID;

	public:
		
		Base()
		{
			cout << "Constructor" << endl;
			mID = MakeID();

		}

		Base( const Base& rhs )
		{
			// Shallow copy
			cout << "Copy constructor" << endl;
			mID = rhs.mID;

		}

		Base& operator=( const Base& rhs )
		{
			// Deep copy
			cout << "Assignment operator" << endl;
			Base newObject;
			newObject.mID = mID;

			return newObject;
		
		}


		virtual ~Base() {}

		unsigned int GetID() const
		{
			return mID;

		}

};
	
class Derived : public Base
{
	private:
		
	public:
		

		Derived() 
			: Base()
		{}

		Derived( const Derived& rhs )
		{
			// Shallow copy
			cout << "Copy constructor" << endl;
			mID = rhs.mID;

		}
		~Derived()
		{}

		Derived& operator=( const Derived& rhs )
		{
			// Deep copy
			cout << "Assignment operator" << endl;
			Derived newObject;
			mID	= rhs.mID;

			return newObject;
		
		}

};





int main()
{
	Derived* dd = new Derived;
	unique_ptr<Derived> ud = make_unique<Derived>();
	shared_ptr<Derived> sd = make_shared<Derived>();


	unique_ptr<Derived> object1 = make_unique<Derived>();
	unique_ptr<Derived> object2 = make_unique<Derived>();


	cout << object1->GetID() << endl;
	cout << object2->GetID() << endl;

	PrintObjectSize( &object1 );
	PrintObjectSize( &object2 );

	shared_ptr<Derived> object3 = make_shared<Derived>();
	shared_ptr<Derived> object4 = make_shared<Derived>();

	cout << object3->GetID() << endl;
	cout << object4->GetID() << endl;

	PrintObjectSize( &object3 );
	PrintObjectSize( &object4 );


	object3 = object4;

	cout << object3->GetID() << endl;
	cout << object4->GetID() << endl;


	shared_ptr<Derived> object5 = object4;

	cout << object4->GetID() << endl;
	cout << object5->GetID() << endl;


	Derived d;
	Derived c = d;

	d = c;

	vector<unique_ptr<Derived>> container;

	
	system( "PAUSE" );

	return 0;
}