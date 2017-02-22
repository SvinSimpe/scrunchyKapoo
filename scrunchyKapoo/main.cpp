#include <iostream>
#include <memory>
#include <vector>
using namespace std;

#include "BinarySearch.h"
#include "Orc.h"




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


int main()
{	
	Orc orc;
	orc.SetDamageType( new Frost() );
	cout << "Orc damage: " << orc.GetDamageType()->GetType() << endl;




	system( "PAUSE" );

	return 0;
}