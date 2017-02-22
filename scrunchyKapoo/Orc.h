#ifndef _ORC_H_
#define _ORC_H_

#include "DamageDealer.h"
#include "Actor.h"

class Orc :  public Actor, public DamageDealer
{
	private:

	public:
		Orc()
			: Actor(), DamageDealer()
		{}

		~Orc()
		{

		}

};
#endif // !_ORC_H_
