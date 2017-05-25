/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the  member function file for the Medusa
 * class.  This class allows us to make a Medusa with basic
 * attacks.  We can call attacks, defense, and describe what
 * kind of attacks they can do.
 **************************************************************/

#include <iostream>
#include "Medusa.hpp"

/**************************************************************
 *                  Medusa::Medusa
 *  This is the constructor function for the Medusa class.
 *  It builds the object properly,
 **************************************************************/
Medusa::Medusa() {
	setAttack(Dice(2, 6));
	setDefense(Dice(1, 6));
	setArmor(3);
	setStrength(8);
	setLives(1);
	setSpecial(0);

}

/**************************************************************
 *                  Medusa::attack()
 *  Rolls for the attack for the Medusa Class.  In addition if
 *  it rolls a 12 then we utilize the glare function.
 **************************************************************/
void Medusa::attack() {
	int temp = rollAttack();

	// Use glare instead
	if (temp == 12) {
		temp = 300;
		setCurrAttack(temp);
	}
	// Use standard attack
	else {
		setCurrAttack(temp);
	}
}

/**************************************************************
 *                  Medusa::defend()
 *  Rolls the Medusa defense dice, storing that value in the
 *  currDefense variable, it runs the strengthLoss function with
 *  the saved value.
 **************************************************************/
void Medusa::defend(int damageDone) {
	// Roll the Medusas defense dice
	int temp = rollDefense();

	// Save that value to a variable for later
	setCurrDefense(temp);

	// Modify their overall health value.
	strengthLoss(damageDone);
}


/**************************************************************
 *                  Medusa::attackDescription()
 *  This prints to the console various explanations of the types
 *  of attacks the the Medusa class can produce.
 **************************************************************/
void Medusa::attackDescription(int attackDamage) {
	if (attackDamage > 200) {
		std::cout << "Medusa locked eyes with her opponent, and used her glare ability" << std::endl;
	}
	else if (attackDamage > 0) {
		std::cout << "Medusa used her snakes to bite her opponent." << std::endl;
	}
	else {
		std::cout << "Medusa commanded her snakes to strike, but they didn't listen." << std::endl;
	}
}

/**************************************************************
 *                  Medusa::defenseDescription()
 *  This prints to the console various explanations of the types
 *  of defense the the Medusa class can produce.
 **************************************************************/
void Medusa::defenseDescription(int special) {
	return;
}


