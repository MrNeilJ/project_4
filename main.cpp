/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the main application for the monster
 * battle royale program.  This will guide the user into making
 * choices as to which monstesrs they would like have fight one
 * another.  In addition to this it will run the game functions
 * that will print out the results of every round.
 **************************************************************/

#include <iostream>
#include <time.h>
#include "menuMaker.hpp"

#include "Game.hpp"

int main() {

	srand(time(NULL));
	Game gameTime;

	std::cout << "*****************************************" << std::endl;
	std::cout << "*         MONSTER BATTLE ROYALE         *" << std::endl;
	std::cout << "*****************************************" << std::endl;
	std::cout << "Welcome to Monster Battle Royale! Here you will" << std::endl;
	std::cout << "be battling it out between monsters of all different" << std::endl;
	std::cout << "shapes and sizes.  The rules are simple, get your" << std::endl;
	std::cout << "opponents health to zero.  Winner take all!\n" << std::endl;

	int replay = 1;

	while (replay == 1) {
		for (int i = 0; i < 2; i++) {
			std::cout << "PLAYER " << i + 1 << " SELECTION:" << std::endl;
			std::cout << "--------------------------------" << std::endl;
			menuMaker monsterSelect("Pick your Creature!",
									"Vampire",
									"Barbarian",
									"Blue Men",
									"Medusa",
									"Harry Potter",
									"Quit");

			menuMaker monsterConfirmation("Is this the character you'd like to play as?",
										  "Yes",
										  "No");

			int monsterChoice = -1;
			int monsterConfirm = -1;

			do {
				monsterSelect.prompt();
				monsterChoice = monsterSelect.getResponse();

				if (monsterChoice == 1) {
					std::cout << "VAMPIRE:" << std::endl;
					std::cout << "--------------------------------" << std::endl;
				} else if (monsterChoice == 2) {
					std::cout << "BARBARIAN:" << std::endl;
					std::cout << "--------------------------------" << std::endl;
				} else if (monsterChoice == 3) {
					std::cout << "BLUE MEN:" << std::endl;
					std::cout << "--------------------------------" << std::endl;
				} else if (monsterChoice == 4) {
					std::cout << "MEDUSA:" << std::endl;
					std::cout << "--------------------------------" << std::endl;
				} else if (monsterChoice == 5) {
					std::cout << "HARRY POTTER:" << std::endl;
					std::cout << "--------------------------------" << std::endl;
				} else if (monsterChoice == 6) {
					std::cout << "I see the fear is strong in you, goodbye" << std::endl;
				} else {
					std::cout << "Incorrect response, try again\n" << std::endl;
				}

				if (monsterChoice > 0 && monsterChoice < 6) {
					gameTime.classDescriptions(monsterChoice);
					monsterConfirmation.prompt();
					monsterConfirm = monsterConfirmation.getResponse();
				}

			} while ((monsterChoice == 6) || (monsterConfirm > 1 && monsterConfirm < 3));

			gameTime.setOpponent(i, monsterChoice);
		}

	gameTime.play();

	menuMaker playAgain("Would you like to play again?", "Yes", "Quit");

	do {
		playAgain.prompt();
		replay = playAgain.getResponse();
	} while (replay < 1 && replay > 2);
}
	return 0;
}