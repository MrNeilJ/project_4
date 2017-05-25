/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the header file for the Game class.  This class
 * is what really creates the layout for the game.  It provides
 * the user with the functionality for the game to run, initiate
 * creature creation, as well as describing each class.
 **************************************************************/

#ifndef PROJECT_3_GAME_HPP
#define PROJECT_3_GAME_HPP

#include <iostream>
#include <memory>
#include "Creature.hpp"
class Game {
private:
	Creature* Opponents[2];
	int currOpp;
	int currAttack;
	int currDefense;
	int currStrengthLoss;
	int turn = 1;

public:
	// Constructor
	Game();
	// Destructor
	~Game();

	// Creature descriptions / member functions
	void classDescriptions(int);
	void setOpponent(int, int);

	// Round controls
	void round();
	void play();
};


#endif //PROJECT_3_GAME_HPP
