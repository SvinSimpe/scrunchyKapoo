#include "Actor.h"

unsigned int Actor::sID = 0;

Actor::Actor()
{
	mID = sID++;

	mLocation			= XMFLOAT3( 0.0f, 0.0f, 0.0f );
	mForwardVector		= XMFLOAT3( 0.0f, 0.0f, 0.0f );
	mTransform.scale	= XMFLOAT3( 0.0f, 0.0f, 0.0f );
	mTransform.rotation = XMFLOAT3( 0.0f, 0.0f, 0.0f );

}

Actor::Actor( const Actor& other )
{
	mLocation			= other.mLocation;
	mForwardVector		= other.mForwardVector;
	mTransform.scale	= other.mTransform.scale;
	mTransform.rotation = other.mTransform.rotation;

}

void Actor::operator=( const Actor& other )
{

}

bool Actor::operator<( const Actor& other ) const
{
	return this->mID < other.mID;
}

bool Actor::operator==( const Actor& other ) const
{
	return this->mID == other.mID;
}