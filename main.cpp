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
#include "inputCheck.hpp"
#include "menuMaker.hpp"
#include "Queue.hpp"

#include "Game.hpp"

int main() {

	srand(time(NULL));
	Game gameTime;

	std::cout << "*****************************************" << std::endl;
	std::cout << "*         MONSTER BATTLE ROYALE         *" << std::endl;
	std::cout << "*****************************************" << std::endl;
	std::cout << "Welcome to the Monster Battle Royale Tournament." << std::endl;
	std::cout << "Here we will be having two teams go head to head" << std::endl;
	std::cout << "to see who is truly the strongest in the land." << std::endl;


	// See if the user would like to actually begin the game after reading the rules
	std::cout << "Are you ready for the challenge?(Y/N): ";
	char readyStatus;
	std::cin >> readyStatus;

	// If no, then exit the game otherwise continue the game
	if (toupper(readyStatus) != 'Y') {
		std::cout << "Why are you such a little chicken? They are not THAT tough." << std::endl;
		exit(1);
	}

	int replay = 1;
	while (replay == 1) {


	// Begin building the of the game sets
	std::cout << "Time to build the teams! Fist off, how many players would you like each team to have?" << std::endl;
	std::cout << "Please make sure the value is greater than 0 and less than 20." << std::endl;


	// Loop through asking the user for a number of players until the follow the rules set above
	int playerCount;
	do {
		std::cout << "\nUser Choice: ";
		playerCount = getInt();

		if (playerCount < 0 || playerCount > 20) {
			std::cout << "That number does not match the requirements, try again" << std::endl;
		}
	} while (playerCount < 0 || playerCount > 20);

	/**************************************************
	 * TEAM DEVELOPMENT
	 **************************************************/

	// Build the two teams
	for (int j = 0; j < 2; j++) {
		std::cout << "Time to build the Team " << j + 1 << " for the tournament.\n" << std::endl;
		menuMaker autoBuild("Would you like to build the team yourself? Or have it autobuilt for you?",
							"I will build the teams myself!",
							"I'm lazy, build them for me");

		int autoBuildChoice = -1;

		do {
			autoBuild.prompt();
			autoBuildChoice = autoBuild.getResponse();

			if (autoBuildChoice != 1 && autoBuildChoice != 2) {
				std::cout << "Did not comprehend this answer, try again." << std::endl;
			}
		} while (autoBuildChoice != 1 && autoBuildChoice != 2);


		// If the user decided to Automatically build this Roster...
		if (autoBuildChoice == 2) {
			// Build that sets roster automatically
			gameTime.autoBuildRoster(j, playerCount);
		}
			// Otherwise, let the user build the roster one by one
		else {
			// Loop through asking the user if they would like to name each player.
			std::cout << "Perfect, now for the most important question, would you like to name your characters?(Y/N)"
					  << std::endl;
			char nameCharacters;
			do {
				std::cout << "User choice: ";
				nameCharacters = getchar();

				if (toupper(nameCharacters) != 'Y' || toupper(nameCharacters) != 'N') {
					std::cout << "I did not understand that response, please try again" << std::endl;
				}
			} while (toupper(nameCharacters) != 'N' && toupper(nameCharacters) != 'Y');


			// Add each player to the current player roster
			for (int i = 0; i < playerCount; i++) {
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
				// If the user chose to name the character...
				if (toupper(nameCharacters) == 'Y') {
					std::cout << "What would you like to name this character?" << std::endl;
					std::string charName = getString();
					gameTime.addPlayerToRoster(j, monsterChoice, charName);
				} else {
					// Once the play has chosen their character, add that character to the roster
					gameTime.addPlayerToRoster(j, monsterChoice);
				}
			}
		}
	}
	/*************************************
	 * BATTLE TIME
	 *************************************/
	//Allow the user to fight the two teams over and over if they want.

		gameTime.play();

		menuMaker playAgain("\nWould you like to play again?", "Yes", "Quit");

		do {
			playAgain.prompt();
			replay = playAgain.getResponse();
		} while (replay < 1 && replay > 2);

		if (replay == 1) {
			gameTime.clearGame();
		}

	}
	while (replay == 1);


	return 0;
}

/*
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

 */