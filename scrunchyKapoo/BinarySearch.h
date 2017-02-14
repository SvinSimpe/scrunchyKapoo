#ifndef _BINARYSEARCH_H_
#define _BINARYSEARCH_H_

#include <assert.h>

template<typename T>
unsigned int BinarySearch( T* collectionToSearch, T& objectToFind,
				   unsigned int lowIndex, unsigned int highIndex )
{
	assert( collectionToSearch );
	assert( objectToFind );

	if( highIndex < lowIndex )
		return -1;

	unsigned int midIndex = ( lowIndex + highIndex ) / 2;

	if( objectToFind == collectionToSearch[midIndex] )
		return midIndex;

	// Lower part
	else if( objectToFind < collectionToSearch[midIndex] )
		return BinarySearch( collectionToSearch, objectToFind,
					  lowIndex, midIndex - 1 );
	// Upper part
	else if( objectToFind > collectionToSearch[midIndex] )
		return BinarySearch( collectionToSearch, objectToFind,
					  midIndex + 1, highIndex );

}
#endif 
