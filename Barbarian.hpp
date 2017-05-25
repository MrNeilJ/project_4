//
// Created by Neil on 5/2/2017.
//

#ifndef PROJECT_3_BARBARIAN_HPP
#define PROJECT_3_BARBARIAN_HPP

#include "Creature.hpp"

class Barbarian : public Creature {
private:

public:
	// Constructor
	Barbarian();

	// Attack and Defend Member Functions
	void attack();
	void defend(int);

	// Allows us to see what kind of attack had been used.
	void attackDescription(int);
	void defenseDescription(int);
};
#endif //PROJECT_3_BARBARIAN_HPP
