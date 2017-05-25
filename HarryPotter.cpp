/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the member function file for the Potter
 * class.  This class allows us to make a Potter with basic
 * attacks.  We can call attacks, defense, and describe what
 * kind of attacks they can do.
 **************************************************************/
#include "HarryPotter.hpp"

/**************************************************************
 *                  HarryPotter::HarryPotter()
 *  This is the constructor function for the Harry Potter class.
 *  It builds the object properly,
 **************************************************************/
HarryPotter::HarryPotter() {
	setAttack(Dice(2, 6));
	setDefense(Dice(2, 6));
	setArmor(0);
	setStrength(12);
	setLives(2);
	setSpecial(0);
}

/**************************************************************
 *                  HarryPotter::attack()
 *  Rolls the Potters attack dice, storing that value in the
 *  currAttack variable.
 **************************************************************/
void HarryPotter::attack() {
	int temp = rollAttack();
	setCurrAttack(temp);
}

/**************************************************************
 *                  HarryPotter::defend()
 *  Rolls the Potters defense dice, storing that value in the
 *  currDefense variable. In addition to this, if the Potters
 *  strength is at 0, it will activate the Hogwarts specieal
 *  setting its health up to 20 and lives down to 1.
 **************************************************************/
void HarryPotter::defend(int damageDone) {
	// Roll the Potters defense dice
	int temp = rollDefense();

	// Save that value to a variable for later
	setCurrDefense(temp);

	// Modify their overall health value.
	strengthLoss(damageDone);

	if (getStrength() < 1) {
		if (getLives() == 2) {
			// Utilize the Hogwarts special move (health at 20, lives back down to 1)
			setStrength(20);
			setLives(1);
			setSpecial(1);
		}

	}

}


/**************************************************************
 *                  HarryPotter::attackDescription()
 *  Sends to the console a description of the type of attack
 *  that the Potter is going to use.
 **************************************************************/
void HarryPotter::attackDescription(int attackDamage) {
	if (attackDamage > 0) {
		std::cout << "Harry raised his wand and shouted \"Expectopetronum!\"" << std::endl;
	}
	else {
		std::cout << "Harry raised his wand, but couldn't remember what spell he wanted to use..." << std::endl;
	}

}

/**************************************************************
 *                  HarryPotter::defenseDescription()
 *  Sends to the console a description of the type of defense
 *  that the Potter is going to use. Also notifies us if the
 *  utilize their special ability.
 **************************************************************/
void HarryPotter::defenseDescription(int) {
	if (getSpecial() == 1) {
		std::cout << "Using his final breath, Harry called upon the staff of Hogwarts to strengthen him." << std::endl;
		setSpecial(0);
	}
}

