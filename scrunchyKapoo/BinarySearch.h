#ifndef _BINARYSEARCH_H_
#define _BINARYSEARCH_H_

#include <assert.h>

template<typename T>
void BinarySearch( T* collectionToSearch, T& objectToFind,
				   unsigned int lowIndex, unsigned int highIndex, unsigned int& foundIndex )
{
	assert( collectionToSearch );
	assert( objectToFind );

	unsigned int midIndex = ( lowIndex + highIndex ) / 2;

	// Lower part
	if( objectToFind < collectionToSearch[( lowIndex + highIndex ) / 2] )
		BinarySearch( collectionToSearch, objectToFind,
					  lowIndex, midIndex - 1, foundIndex );
	// Upper part
	else if( objectToFind > collectionToSearch[( lowIndex + highIndex ) / 2] )
		BinarySearch( collectionToSearch, objectToFind,
					  midIndex + 1, highIndex, foundIndex );

	// Object found at split point
	else if( objectToFind == collectionToSearch[midIndex] )
	{ 
		// Found!
		foundIndex = midIndex;
		return;
	}

}


#endif 
