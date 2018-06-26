#pragma once
#pragma once
#include<iostream>
#include<sfml\graphics.hpp>
#include<sfml\window.hpp>
#include<sfml\system.hpp>
#include<math.h>
#include<vector>
#include<cstdlib>

using namespace sf;
class Character
{
public:
	Character();
	~Character();

private:
	int health;
	int armor;
};

