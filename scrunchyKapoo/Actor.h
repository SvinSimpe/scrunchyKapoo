#ifndef _ACTOR_H_
#define _ACTOR_H_

#include <DirectXMath.h>
using namespace DirectX;

struct Transform
{
	XMFLOAT3 scale;
	XMFLOAT3 rotation;
};


class Actor
{
	private:
		static unsigned int sID;
		


	protected:
		unsigned	int mID;
		XMFLOAT3	mLocation;
		XMFLOAT3	mForwardVector;
		Transform	mTransform;

	public:
		Actor();
		Actor( const Actor& other );
		virtual ~Actor(){};

		void operator=( const Actor& other );
		bool operator<( const Actor& other ) const;
		bool operator==( const Actor& other ) const;


	

};

#endif 
