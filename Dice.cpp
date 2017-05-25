/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the creature member file for the abstract
 * class Creature.  This defines the layout of all of the other
 * monster classes to allow for easy development.  Sets some
 * basic member names that can be modified by the other classes.
 **************************************************************/

#include <cstdlib>
#include "Dice.hpp"

/**************************************************************
 *                  Dice::Dice()
 *  Basic constructor call for the Dice class, it creates a dice
 *  object with a generic number of sides.
 **************************************************************/
Dice::Dice() {
	sides 	= 6;
	numDie 	= 1;
}

/**************************************************************
 *                  Dice::Dice()
 *  Basic constructor call for the Dice class, it creates a dice
 *  object with a user inputted number of dice and sides.
 **************************************************************/
Dice::Dice(int totalDie, int n) {
	sides 	= n;
	numDie 	= totalDie;
}

/**************************************************************
 *                  Dice::roll()
 *  Rolls the die and returns the total for each number of rolls
 **************************************************************/
int Dice::roll() {
	int total = 0;
	for (int i = 0; i < numDie; i++) {
		total += ((rand() % sides)+ 1);
	}
	return total;
}
