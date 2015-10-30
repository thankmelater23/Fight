#include "DarkGDK.h"
using namespace std;

#ifndef player.h
#define player.h

class player
{
public:

	player other;
	int health;
	int stamina;
	int power;
	bool dead;

public:
	void initialize(player &play)
	{
		other = player;

}
}

#endif