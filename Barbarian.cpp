/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the member function file for the Barbarian
 * class.  This class allows us to make a Barbarian with basic
 * attacks.  We can call attacks, defense, and describe what
 * kind of attacks they can do.
 **************************************************************/

#include <iostream>
#include "Barbarian.hpp"

/**************************************************************
 *                  Barbarian::Barbarian()
 *  This is the constructor for the barbarian class, it is used
 *  to build the class information such as strength, die types
 *  and amount of lives.
 **************************************************************/
Barbarian::Barbarian() {
	setAttack(Dice(2, 6));
	setDefense(Dice(2, 6));
	setArmor(0);
	setStrength(12);
	setLives(1);
	setSpecial(0);

}

/**************************************************************
 *                  Barbarian::attack()
 *  Rolls the barbarians attack dice, storing that value in the
 *  currAttack variable.
 **************************************************************/
void Barbarian::attack() {
	int temp = rollAttack();
	setCurrAttack(temp);
}

/**************************************************************
 *                  Barbarian::defend()
 *  Rolls the barbarians defense dice, storing that value in the
 *  currDefense variable, it runs the strengthLoss function with
 *  the saved value.
 **************************************************************/
void Barbarian::defend(int damageDone) {
	// Roll the Barbs defense dice
	int temp = rollDefense();

	// Save that value to a variable for later
	setCurrDefense(temp);

	// Modify their overall health value.
	strengthLoss(damageDone);

}

/**************************************************************
 *                  Barbarian::attackDescription()
 *  Returns to the console an explanation of the kind of attack
 *  that the class type used.
 **************************************************************/
void Barbarian::attackDescription(int attackDamage) {
	if (attackDamage > 0) {
		std::cout << "The Barbarian swung their axe valiantly." << std::endl;
	}
	else {
		std::cout << "The Barbarian couldn't muster up the strength to raise their axe..." << std::endl;
	}

}

/**************************************************************
 *                  Barbarian::defenseDescription()
 *  Returns to the console an explanation of the kind of defense
 *  that the class type used.
 **************************************************************/
void Barbarian::defenseDescription(int) {
	return;
}


