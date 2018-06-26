
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

#include "Character.h"
#include "Entity.h"

using namespace sf;

class Enemy : public Entity
{
public:
	

	enum Type
	{
		Zombie,
		Worm,
	};

public:
	explicit Enemy(Type type);

private:
	Type MyType;
};

