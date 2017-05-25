/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the member function file for the BlueMen
 * class.  This class allows us to make a Barbarian with basic
 * attacks.  We can call attacks, defense, and describe what
 * kind of attacks they can do.
 **************************************************************/

#include "BlueMen.hpp"


/**************************************************************
 *                  BlueMen::BlueMen()
 *  This is the constructor for the BlueMen class, it is used
 *  to build the class information such as strength, die types
 *  and amount of lives.
 **************************************************************/
BlueMen::BlueMen() {
	setAttack(Dice(2, 10));
	setDefense(Dice(3, 6));
	setArmor(3);
	setStrength(12);
	setLives(1);
	setSpecial(0);

}

/**************************************************************
 *                  BlueMen::attack()
 *  Rolls the dice for the BlueMen and saves the value to the
 *  currAttack value.
 **************************************************************/
void BlueMen::attack() {
	int temp = rollAttack();
	setCurrAttack(temp);
}

/**************************************************************
 *                  BlueMen::Defend()
 *  Rolls the dice for the BlueMen and saves the value to the
 *  currDefense value.
 **************************************************************/
void BlueMen::defend(int damageDone) {
	// Roll the BlueMens defense dice
	int temp = rollDefense();

	// Save that value to a variable for later
	setCurrDefense(temp);

	// Modify their overall health value.
	strengthLoss(damageDone);

	// Check to see if we need to modify their defense die
	if(getStrength() < 4) {
		setDefense(Dice(1,6));
	}
	else if(getStrength() < 8) {
		setDefense(Dice(2,6));
	}
}

/**************************************************************
 *                  BlueMen::attackDescription()
 *  Utilizes the overall damage done, then prints to the console
 *  an explanation of that attack type.
 **************************************************************/
void BlueMen::attackDescription(int attackDamage) {
	if (attackDamage > 0) {
		std::cout << "The Blue Men jumped onto their opponent, pummeling them to the floor" << std::endl;
	}
	else {
		std::cout << "One Blue Man bumped into it's teammate, and began bickering, ignoring their opponent." << std::endl;
	}
}

/**************************************************************
 *                  BlueMen::attackDescription()
 *  Utilizes the overall damage done, then prints to the console
 *  an explanation of that attack type.
 **************************************************************/
void BlueMen::defenseDescription(int) {
	return;
}
