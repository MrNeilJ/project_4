/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the header  member function file for the Medusa
 * class.  This class allows us to make a Medusa with basic
 * attacks.  We can call attacks, defense, and describe what
 * kind of attacks they can do.
 **************************************************************/

#ifndef PROJECT_3_MEDUSA_HPP
#define PROJECT_3_MEDUSA_HPP


#include "Creature.hpp"

class Medusa : public Creature{
private:

public:
	// Constructor
	Medusa();

	// Attack / Defend
	void attack();
	void defend(int);

	// Attack / Defend descriptions
	void attackDescription(int);
	void defenseDescription(int);

};


#endif //PROJECT_3_MEDUSA_HPP
