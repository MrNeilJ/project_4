/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the header member function file for the Vampire
 * class.  This class allows us to make a Vampire with basic
 * attacks.  We can call attacks, defense, and describe what
 * kind of attacks they can do.
 **************************************************************/

#ifndef PROJECT_3_VAMPIRE_HPP
#define PROJECT_3_VAMPIRE_HPP


#include "Creature.hpp"

class Vampire : public Creature{
private:

public:
	Vampire();

	void attack();

	void defend(int);

	void attackDescription(int);
	void defenseDescription(int);
};



#endif //PROJECT_3_VAMPIRE_HPP
