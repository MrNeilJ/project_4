/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the header  member function file for the Potter
 * class.  This class allows us to make a Potter with basic
 * attacks.  We can call attacks, defense, and describe what
 * kind of attacks they can do.
 **************************************************************/

#ifndef PROJECT_3_HARRYPOTTER_HPP
#define PROJECT_3_HARRYPOTTER_HPP


#include "Creature.hpp"

class HarryPotter : public Creature {
private:

public:
	// Constructor function
	HarryPotter();

	// Attack / defense functions
	void attack();
	void defend(int);

	// Attack / defense descriptions
	void attackDescription(int);
	void defenseDescription(int);

};


#endif //PROJECT_3_HARRYPOTTER_HPP
