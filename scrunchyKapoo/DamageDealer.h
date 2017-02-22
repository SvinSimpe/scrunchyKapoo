#ifndef _DAMAGEDEALER_H_
#define _DAMAGEDEALER_H_

#include <typeinfo>

__interface IDamageType
{
	public:
		virtual IDamageType* NewInstance() = 0;
		// GetDisplayName
		virtual const char* GetType() const = 0;
};

class Physical : public IDamageType
{
	public:
		Physical(){}
		virtual IDamageType* NewInstance() override
		{
			return new Physical();

		}
		virtual const char* GetType() const
		{
			return typeid( this ).name();

		}
};

class Burn : public IDamageType
{
	public:
		Burn(){}
		virtual IDamageType* NewInstance() override
		{
			return new Burn();

		}
		virtual const char* GetType() const
		{
			return typeid( this ).name();

		}
};

class Frost : public IDamageType
{
	public:
		Frost(){}
		virtual IDamageType* NewInstance() override
		{
			return new Frost();

		}
		
		// Fudge
		virtual const char* GetType() const
		{
			return typeid( this ).name();

		}
};




class  DamageDealer
{
	protected:
		IDamageType*	mDamageType;
		float			mDamage;
		float			mDamageDuration;

	public:
		DamageDealer()
		{
			mDamageType		= nullptr;
			mDamage			= 0.0f;
			mDamageDuration	= 0.0f;
		}

		DamageDealer( const DamageDealer& other )
		{
			mDamageType = other.mDamageType ? other.mDamageType->NewInstance() : nullptr;
			/*
			if( other.mDamageType )
				mDamageType = other.mDamageType->NewInstance();
			else
				mDamageType = nullptr;
			*/
			mDamage = other.mDamage;
			mDamageDuration = other.mDamageDuration;

		}

		virtual ~DamageDealer()
		{
			if( mDamageType )
				delete mDamageType;

		}

		void SetDamageType( IDamageType* newDamageType )
		{
			if( mDamageType )
				delete mDamageType;
			mDamageType = newDamageType;

		}

		const IDamageType* GetDamageType() const
		{
			return mDamageType;

		}

}; 



#endif // !_DAMAGEDEALER_H_
