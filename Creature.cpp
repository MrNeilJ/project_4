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

#include "Creature.hpp"


/********************************************
 * DICE ROLLERS
 ********************************************/
/**************************************************************
 *                  Creature::rollAttack()
 *  Rolls the current classes attack dice and returns the int
 *  value for the roll.
 **************************************************************/
int Creature::rollAttack() {
	return attackDie.roll();
}

/**************************************************************
 *                  Creature::rollDefense()
 *	Rolls the current classes defense dice and returns the int
 *	value for the roll.
 **************************************************************/
int Creature::rollDefense() {
	 return defenseDie.roll();
}


/********************************************
 * SETTERS
 ********************************************/
/**************************************************************
 *                  Creature::setAttack()
 *	Sets the attack Dice value for the current class.
 **************************************************************/
void Creature::setAttack(Dice input) {
	attackDie = input;
}

/**************************************************************
 *                  Creature::setDefense()
 *	Sets the defense Dice value for the current class.
 **************************************************************/
void Creature::setDefense(Dice input) {
	defenseDie = input;
}

/**************************************************************
 *                  Creature::setArmor()
 *	Sets the armor value to whatever is inputted in as the
 *	parameter.
 **************************************************************/
void Creature::setArmor(int input) {
	armor = input;
}

/**************************************************************
 *                  Creature::setStrength()
 *	Sets the strength value to whatever is inputted in as the
 *	parameter.
 **************************************************************/
void Creature::setStrength(int input) {
	strength = input;
}

/**************************************************************
 *                  Creature::setLives()
 *	Sets the lives value in the class to whatever is inputted
 *	in as the parameter
 **************************************************************/
void Creature::setLives(int input) {
	lives = input;
}

/**************************************************************
 *                  Creature::setCurrAttack()
 *	Sets the currAttack value in the class to whatever is inputted
 *	in as the parameter
 **************************************************************/
void Creature::setCurrAttack(int atkDamage) {
	currAttack = atkDamage;
}

/**************************************************************
 *                  Creature::setCurrDefense()
 *	Sets the currDefense value in the class to whatever is inputted
 *	in as the parameter
 **************************************************************/
void Creature::setCurrDefense(int defensePts) {
	currDefense = defensePts;
}

/**************************************************************
 *                  Creature::setDamageReceived()
 *	Sets the damageReceived value in the class to whatever is inputted
 *	in as the parameter
 **************************************************************/
void Creature::setDamageReceived(int userInput) {
	damageReceived = userInput;
}




/********************************************
 * HEALTH MODIFIERS
 ********************************************/
/**************************************************************
 *                  Creature::strengthLoss()
 *	Modifies the value stored in strength, it takes the value
 *	rolled by the opponent, and subtracts their defense roll and
 *	armor and returns saves that damage done into another variable.
 **************************************************************/
void Creature::strengthLoss(int opponentRoll) {
	if ((opponentRoll - currDefense - armor) < 0) {
		strength += 0;
		damageReceived = 0;
	}
	else {
		strength -= (opponentRoll - currDefense - armor);
		damageReceived = (opponentRoll - currDefense - armor);
	}
}


/********************************************
 * GETTERS
 ********************************************/
/**************************************************************
 *                  Creature::getAttack()
 *	Gets the value stored in currAttack.
 **************************************************************/
int Creature::getAttack() {
	return currAttack;
}

/**************************************************************
 *                  Creature::getDefense()
 *	Gets the value stored in currDefense.
 **************************************************************/
int Creature::getDefense() {
	return currDefense;
}

/**************************************************************
 *                  Creature::getLives()
 *	Gets the value stored in lives.
 **************************************************************/
int Creature::getLives() {
	return lives;
}

/**************************************************************
 *                  Creature::getStrength()
 *	Gets the value stored in strength.
 **************************************************************/
int Creature::getStrength() {
	return strength;
}

/**************************************************************
 *                  Creature::getArmor()
 *	Gets the value stored in armor.
 **************************************************************/
int Creature::getArmor() {
	return armor;
}

/**************************************************************
 *                  Creature::getDamageReceived()
 *	Gets the value stored in damageReceived.
 **************************************************************/
int Creature::getDamageReceived() {
	return damageReceived;
}

/**************************************************************
 *                  Creature::setSpecial()
 *	Sets the value stored in special.
 **************************************************************/
void Creature::setSpecial(int userInput) {
	special = userInput;
}

/**************************************************************
 *                  Creature::getSpecial()
 *	Gets the value stored in special.
 **************************************************************/
int Creature::getSpecial() {
	return special;
}






