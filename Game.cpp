/**************************************************************
 * Author: Neil Johnson
 *
 * Date: 4.14.2017
 *
 * Description: This is the file for the Game class.  This class
 * is what really creates the layout for the game.  It provides
 * the user with the functionality for the game to run, initiate
 * creature creation, as well as describing each class.
 **************************************************************/

#include <time.h>
#include <limits>
#include "Game.hpp"
#include "Vampire.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "Medusa.hpp"
#include "HarryPotter.hpp"
#include "inputCheck.hpp"


/**************************************************************
 *                  Game::classDescriptions()
 *  This is a function that allows us to get a brief description
 *  of each class printed to the console.
 **************************************************************/
void Game::classDescriptions(int userChoice) {
	if (userChoice == 1) {
		std::cout << "Suave, debonair, but vicious and surprisingly resilient!\n" << std::endl;
	}
	else if (userChoice == 2) {
		std::cout << "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso.\n" << std::endl;
	}
	else if (userChoice == 3) {
		std::cout << "They are small (6\' tall), fast and tough. So they are hard to hit and can take\n"
					 "some damage. As for the attack value, you can do a LOT of damage when you can \n"
					 "crawl inside the armor or clothing of your opponent.\n" << std::endl;
	}
	else if (userChoice == 4) {
		std::cout << "Scrawny lady with snakes for hair. They help with fighting. Just don’t look at her!\n" << std::endl;
	}
	else if (userChoice == 5) {
		std::cout << "Why are you reading this? How can you not know who Harry Potter is?\n" << std::endl;
	}


}

/**************************************************************
 *                  Game::Game()
 *  This is the constructor for the game class.  It simply sets
 *  the current opponent object to 0;
 **************************************************************/
Game::Game() {
	currOpp = 0;
	team1Wins = 0;
	team2Wins = 0;
}

/**************************************************************
 *                  Game::setOpponent()
 *  This is a member function that allows the user to set the
 *  value stored in one of the Opponents ptrs to a creature value.
 **************************************************************/
void Game::setOpponent(int currOpp, int userCreature) {
	if (userCreature == 1) {
		Opponents[currOpp] = new Vampire;
	}
	else if (userCreature == 2) {
		Opponents[currOpp] = new Barbarian;
	}
	else if (userCreature == 3) {
		Opponents[currOpp] = new BlueMen;
	}
	else if (userCreature == 4) {
		Opponents[currOpp] = new Medusa;
	}
	else if (userCreature == 5) {
		Opponents[currOpp] = new HarryPotter;
	}
}

/**************************************************************
 *                  Game::round()
 *  This is a function that creates s single round of the matches
 *  allowing the user to go through on attack sequence and mark the
 *  damage to the other user.
 **************************************************************/
void Game::round() {

	std::cout << "ROUND " << turn << ":" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Team 1: " << std::endl;
	Roster[0].getFront()->displayStats();

	std::cout << "\nVERSUS\n" << std::endl;

	std::cout << "Team 2: " << std::endl;
	Roster[1].getFront()->displayStats();
	// Loop the round until one of the opponents is dead
	while(Roster[0].getFront()->getLives() != 0 && Roster[1].getFront()->getLives() != 0) {

		// If it is opponent one's turn
		if (currOpp == 0) {
			/* Commented out to lessen the overall text burden for the moment
			std::cout << "OPPONENT 1's TURN TO ATTACK:" << std::endl;
			std::cout << "----------------------------------------" << std::endl;
			*/

			// Modified so that we are using the roster instead
			Roster[0].getFront()->attack();
			Roster[1].getFront()->defend(Roster[0].getFront()->getAttack());
			/*
			Opponents[0]->attack();
			Opponents[1]->defend(Opponents[0]->getAttack());
			*/

			/*
			// Modified so that we are using the roster instead of Opponents
			Roster[0].getFront()->attackDescription(Opponents[1]->getDamageReceived());
			Roster[1].getFront()->defenseDescription(Opponents[1]->getDefense());
			 */

			/*
			Opponents[0]->attackDescription(Opponents[1]->getDamageReceived());
			Opponents[1]->defenseDescription(Opponents[1]->getDefense());
			*/

			/* Commenting this out for now to lessen total blocks of text in application
			// Print the actual results for the round
			std::cout << "ROUND " << turn << " STATS" << std::endl;
			std::cout << "----------------------------------------" << std::endl;
			std::cout << "Opponent 1's Attack Roll:  "   << Opponents[0]->getAttack()  << std::endl;
			std::cout << "Opponent 2's Defense Roll: "   << Opponents[1]->getDefense() << std::endl;
			std::cout << "\nRound Strength Loss:        " << Opponents[1]->getDamageReceived() << std::endl;
			*/

			currOpp = 1;
		} else {
			/* Commented out to lessen overall text burden for the moment
			std::cout << "OPPONENT 2's TURN TO ATTACK:" << std::endl;
			std::cout << "----------------------------------------" << std::endl;
			*/

			// Modified so that we are using the roster instead
			Roster[1].getFront()->attack();
			Roster[0].getFront()->defend(Roster[1].getFront()->getAttack());
			/*
			Opponents[1]->attack();
			Opponents[0]->defend(Opponents[1]->getAttack());
			*/

			/*
			// Modified so that we are using the roster instead of Opponents
			Roster[1].getFront()->attackDescription(Opponents[0]->getDamageReceived());
			Roster[0].getFront()->defenseDescription(Opponents[0]->getDefense());
			 */

			/*
			Opponents[1]->attackDescription(Opponents[0]->getDamageReceived());
			Opponents[0]->defenseDescription(Opponents[0]->getSpecial());
			*/

			/* Commenting this out for not to lessen total blocks of text in the application
			// Print the actual results for the round
			std::cout << "ROUND " << turn << " STATS" << std::endl;
			std::cout << "----------------------------------------" << std::endl;
			std::cout << "Opponent 2's Attack Roll:  "   << Opponents[1]->getAttack()  << std::endl;
			std::cout << "Opponent 1's Defense Roll: "   << Opponents[0]->getDefense() << std::endl;
			std::cout << "\nRound Strength Loss:       " << Opponents[0]->getDamageReceived() << std::endl;
			*/

			currOpp = 0;
		}
		/* Commenting this out to lessen total blocks of text in the application (easier to read)
		std::cout << "\nRemaining Strength:" << std::endl;
		std::cout << "Opponent 1: " << Opponents[0]->getStrength() << std::endl;
		std::cout << "Opponent 2: " << Opponents[1]->getStrength() << "\n" << std::endl;
		*/

		if (Roster[0].getFront()->getStrength() < 1) {
			Roster[0].getFront()->setLives(Roster[0].getFront()->getLives() - 1);
		} else if (Roster[1].getFront()->getStrength() < 1) {
			Roster[1].getFront()->setLives(Roster[1].getFront()->getLives() - 1);
		}

	}
	std::cout << "\nROUND " << turn << " RESULTS" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	if (Roster[0].getFront()->getLives() == 0) {
		std::cout << "Team 2's creature, " << Roster[1].getFront()->getName() << ", was victorious!" << std::endl;
		Roster[1].getFront()->heal();

		std::cout << "Team 2 Wins +1" << std::endl;

		// Update the wins category for each team
		team2Wins += 1;

		// Print out the updated rounds
		std::cout << "\nTeam 1 Wins: " << team1Wins << std::endl;
		std::cout << "Team 2 Wins: " << team2Wins << "\n" << std::endl;

		// Adjust the teams accordingly (remove and move the current front items to reflect the round)
		LoserPit.addHead(Roster[0].removeFront());
		Roster[1].moveFront();
	}
	else {
		std::cout << "Team 1's creature, " << Roster[0].getFront()->getName() << ", was victorious!" << std::endl;
		Roster[0].getFront()->heal();
		std::cout << "Team 1 Wins +1"  << std::endl;

		// Update the wins category for each team
		team1Wins += 1;


		// Print out the updated rounds
		std::cout << "\nTeam 1 Wins: " << team1Wins << std::endl;
		std::cout << "Team 2 Wins: " << team2Wins << "\n" << std::endl;

		// Adjust the teams accordingly (remove and move the current front items to reflect the round)
		LoserPit.addHead(Roster[1].removeFront());
		Roster[0].moveFront();
	}

	turn++;

}

/**************************************************************
 *                  Game::play()
 *  This is a member function that causes the game to loop indefinitely
 *  until one of the players health is under 0 and lives are at 0.
 **************************************************************/
void Game::play() {
	while(Roster[0].getFront() != nullptr && Roster[1].getFront() != nullptr) {
		round();
	}

	std::cout << "GAME COMPLETE" << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	std::cout << "Team 1 Wins: " << team1Wins << std::endl;
	std::cout << "Team 2 Wins: " << team2Wins << std::endl;

	std::cout << "\nCongratulations Team ";
	if (team1Wins > team2Wins) {
		std::cout << "1 on the victory!";
	}
	else {
		std::cout <<"2 on the victory!";
	}
	std::cout << " Your trophy will be available in the next room!" << std::endl;

	std::cout << "\nWould you like to see the losers pit?(Y/N): ";
	char seePit;
	do {
		std::cin >> seePit;

		if (toupper(seePit) == 'Y') {
			LoserPit.displayList();
		}
		else if (toupper(seePit) == 'N') {
			std::cout << "Good choice, they are losers." << std::endl;
		}
		else {
			std::cout << "Did not comprehend response, try again" << std::endl;
		}
	} while (toupper(seePit) != 'Y' && toupper(seePit) != 'N');


}


/**************************************************************
 *                  Game::~Game()
 *  Destructor that allows us to free the memory of dynamically
 *  allocated pointers.
 **************************************************************/
Game::~Game() {
	delete Opponents[0];
	delete Opponents[1];
	*Opponents = nullptr;
}


/**************************************************************
 *                  Game::setOpponent()
 *  This is a member function that allows the user to set the
 *  value stored in one of the Opponents ptrs to a creature value.
 **************************************************************/
void Game::addPlayerToRoster(int currOpp, int userCreature) {
	if (userCreature == 1) {
		Roster[currOpp].addBack(new Vampire());
	}
	else if (userCreature == 2) {
		Roster[currOpp].addBack(new Barbarian());
	}
	else if (userCreature == 3) {
		Roster[currOpp].addBack(new BlueMen());
	}
	else if (userCreature == 4) {
		Roster[currOpp].addBack(new Medusa());
	}
	else if (userCreature == 5) {
		Roster[currOpp].addBack(new HarryPotter());
	}
}

void Game::addPlayerToRoster(int currOpp, int userCreature, std::string name) {
	if (userCreature == 1) {
		Roster[currOpp].addBack(new Vampire(name));
	}
	else if (userCreature == 2) {
		Roster[currOpp].addBack(new Barbarian(name));
	}
	else if (userCreature == 3) {
		Roster[currOpp].addBack(new BlueMen(name));
	}
	else if (userCreature == 4) {
		Roster[currOpp].addBack(new Medusa(name));
	}
	else if (userCreature == 5) {
		Roster[currOpp].addBack(new HarryPotter(name));
	}
}

void Game::autoBuildRoster(int currPlayer, int playerSize) {
	srand(time(NULL));
	int randRoll;
	for (int i = 0; i < playerSize; i++) {
		// Roll a random number between 1 and 6
		randRoll = (rand()%5) + 1;

		// Add that randomized creature to the roster
		addPlayerToRoster(currPlayer, randRoll);
	}
}

void Game::clearGame() {
	Roster[0].clearSet();
	Roster[1].clearSet();
	LoserPit.clearSet();
	team1Wins = 0;
	team2Wins = 0;
	turn = 0;

}
