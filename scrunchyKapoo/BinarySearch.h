#ifndef _BINARYSEARCH_H_
#define _BINARYSEARCH_H_

#include <assert.h>

template<typename T>
void BinarySearch( T* collectionToSearch, T& objectToFind,
				   unsigned int lowIndex, unsigned int highIndex, unsigned int& foundIndex )
{
	assert( collectionToSearch );
	assert( objectToFind );

	// Lower part
	if( objectToFind < collectionToSearch[( lowIndex + highIndex ) / 2] )
		BinarySearch( collectionToSearch, objectToFind,
					  lowIndex, ( lowIndex + highIndex ) / 2 - 1, foundIndex );
	// Upper part
	else if( objectToFind > collectionToSearch[( lowIndex + highIndex ) / 2] )
		BinarySearch( collectionToSearch, objectToFind,
					( lowIndex + highIndex ) / 2 + 1, highIndex, foundIndex );

	// Object found at split point
	else if( objectToFind == collectionToSearch[(lowIndex + highIndex) / 2] )
	{ 
		// Found!
		foundIndex = (lowIndex + highIndex) / 2;
		return;
	}

}


#endif 
