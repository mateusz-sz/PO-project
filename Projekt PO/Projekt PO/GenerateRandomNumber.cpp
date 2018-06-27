#include "GenerateRandomNumber.h"



int GenerateRandomNumber::generateRandom(int maxInt) 
{
	int randomNumber = rand();
	float random = (randomNumber % maxInt) + 1;
	int myRandom = random;
	return myRandom;
}