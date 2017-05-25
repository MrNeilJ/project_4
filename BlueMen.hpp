//
// Created by Neil on 5/2/2017.
//

#ifndef PROJECT_3_BLUEMEN_HPP
#define PROJECT_3_BLUEMEN_HPP


#include "Creature.hpp"

class BlueMen : public Creature {
private:

public:
	// Constructor
	BlueMen();

	// Attack / Defense Functions
	void attack();
	void defend(int);

	// Attack / Defense Descriptions
	void attackDescription(int);
	void defenseDescription(int);

};


#endif //PROJECT_3_BLUEMEN_HPP
