/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the member function file for the Vampire
 * class.  This class allows us to make a Vampire with basic
 * attacks.  We can call attacks, defense, and describe what
 * kind of attacks they can do.
 **************************************************************/

#include "Vampire.hpp"

/**************************************************************
 *                  Vampire::Vampire
 *  This is the constructor function for the Vampire class.
 *  It builds the object properly,
 **************************************************************/
Vampire::Vampire() {
	setAttack(Dice(2, 6));
	setDefense(Dice(2, 6));
	setArmor(0);
	setStrength(12);
	setLives(1);

}

/**************************************************************
 *                  Vampire::attack
 *  This is the main attack feature, it does a standard roll of
 *  the dice.
 **************************************************************/
void Vampire::attack() {
	int temp = rollAttack();
	setCurrAttack(temp);
}

/**************************************************************
 *                  Vampire::defend
 *  This is the main defend feature, it does a standard roll of
 *  the dice. In addition it will then also check to see if a
 *  special roll was created, if so, it will negate all damage
 *  applied to it.
 **************************************************************/
void Vampire::defend(int damageDone) {
	// Check to see if the vampires special will activate
	setSpecial(rand() % 2);

	if (getSpecial()) {
		setCurrDefense(500);
		strengthLoss(0);
		// Save the value so we know how much damage was done in the last attack
		setDamageReceived(0);
	}
	else {
		// Roll the Vampires defense dice
		int temp = rollDefense();

		// Save that value to a variable for later
		setCurrDefense(temp);

		// Modify their overall health value.
		strengthLoss(damageDone);
	}

}


/**************************************************************
 *                  Vampire::attackDescription()
 *  This prints to the console the types of attacks that
 *  the vampire class can produce
 **************************************************************/
void Vampire::attackDescription(int attackDamage) {
	if (attackDamage > 0) {
		std::cout << "The Vampire bit their opponent, sucking their blood." << std::endl;
	}
	else {
		std::cout << "The Vampire smelled garlic on the opponent, causing him to wince" << std::endl;
	}

}

/**************************************************************
 *                  Vampire::defenseDescription()
 *  This prints to the console the types of defensive manuevers that
 *  the vampire class can produce.  This includes the charm feature.
 **************************************************************/
void Vampire::defenseDescription(int specialInput) {
	if (getSpecial()) {
		std::cout << "But the Vampire locked eyes with them, and used his charm to subdue them." << std::endl;
		setSpecial(0);
	}
	else{
		return;
	}
}

