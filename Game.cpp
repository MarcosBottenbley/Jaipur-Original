#include "Game.h"		//includes Card.h, Token.h, Player.h vector and stack
#include "Market.h"
#include "Deck.h"
#include <iostream>
#include <cstdlib>		//for random numbers only
#include <ctime>

using std::vector;
using std::stack;		//TODO: necessary?
using std::string;
using std::cout;
using std::endl;

/* Constructor */
Game::Game() {
	std::srand(std::time(0));
}

Game::Game(int rndSeed) {
	std::srand(rndSeed);
}

/* Class Methods */
void Game::startGame() {
	player1 = new Human("Player1");		//for now, the names can be hard coded
	player2 = new Human("Player2");
	market = new Market(this);
	deck = new Deck(this);
}

void Game::startRound() {
	dealCards();
	setupBank();
}

//void Game::initPlayers() {
	//might be necessary later when we add AI players

//}

/**
 * Shuffles cards and deals them to players, puts cards in market, and
 * sets up the deck.
 */
void Game::dealCards() {
	deck->deal();
}

/**
 * Sets up all the tokens in the bank.
 */
void Game::setupBank() {
	bank = new Bank();
}

/**
 * Shuffles the Tokens in tempArr and pushes them into bankVector. Same
 * shuffling algorithm as for the Cards in dealCards().
 * @param bv vector from bank used to store the tokens
 * @param item type of item being traded
 * @param tempArr array holding the values to be put in random order
 * @param numTokens number of values to be put into the vector
 */
/*void Game::tokenShuffle(vector<Token*> &bv, string item, int tempArr[], int numTokens) {
	int currRand;

	for (int i = numTokens; i > 0; i--) {
		currRand = rand() % i;
		bv.push_back(new Token(item, tempArr[currRand]));
		tempArr[currRand] = tempArr[i - 1];
	}
}*/
//this functionality is in the Bank class right now

void Game::fillMarket() {

}

//TODO: remove for final game (?)
void Game::printDeck() {
	deck->printDeck();
}

void Game::printPlayers() {
    player1->printStats();
    cout << endl;
    player2->printStats();
}

/*Card* Game::getCard(int index) {
	return market[index];
}

Card* Game::takeCard(int index) {
	Card* tempCard = market[index];
	market[index] = deck.top();
	deck.pop();
	return tempCard;
}

Card* Game::swapCard(int index, Card* card) {
	Card* tempCard = market[index];
	market[index] = card;
	return tempCard;
}*/
//these methods are currently in Market

vector<Card*> Game::takeCamels() {
	vector<Card*> camelVector;
	for (int i = 0; i < 5; i++) {
		if (market->getCard(i)->isCamel())
			camelVector.push_back(market->takeCard(i));
	}
	return camelVector;
}

/*vector<Token*> Game::getTokens(string type, int number) {
	vector<Token*> tokenList;
	int vectorNumber;
	if (type == "Diamond")
		vectorNumber = 0;
	else if (type == "Gold")
		vectorNumber = 1;
	else if (type == "Silver")
		vectorNumber = 2;
	else if (type == "Cloth")
		vectorNumber = 3;
	else if (type == "Spice")
		vectorNumber = 4;
	else if (type == "Leather")
		vectorNumber = 5;
	else {
		cout << "Invalid Token type\n";
		vector<Token*> empty;
		return empty;//0 means null
	}

	for (int i = 0; i < number; i++) {
		if (bank[vectorNumber].size() == 0)	//if no more tokens left...
			break;
		tokenList.push_back(bank[vectorNumber].back());
		bank[vectorNumber].pop_back();
	}

	if (number == 3) {			//bonus tokens
		tokenList.push_back(bank[6].back());
		bank[6].pop_back();
	} else if (number == 4) {
		tokenList.push_back(bank[7].back());
		bank[7].pop_back();
	} else if (number >= 5) {
		tokenList.push_back(bank[8].back());
		bank[8].pop_back();
	}

	return tokenList;
}*/
//function moved to the Bank class

void Game::printBoard() {
	cout << "Market:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "[" << (market->getCard(i))->getType() << "] ";
	}
	cout << endl << endl;

	cout << "Bank:" << endl;
	bank->printBank();
}

bool Game::endRound() {		//returns true if a player reaches 2 wins, false otherwise
	//Determine Camel Winner
	/*if (player1->camels > player2->camels)
		player1->score += 5;
	else if (player2->camels > player1->camels)
		player2->score += 5;

	if (player1->score > player2->score)
		player1->wins++;
	else if (player2->score > player1->score)
		player2->wins++;
	else {		//if score tied...
		if (player1->tokens.size() > player2->tokens.size())
			player1->wins++;
		else if (player2->tokens.size() > player1->tokens.size())
			player2->wins++;
		else {
			//result in draw
		}
	}*/
	//need to fix this since camels are in hand now

	player1->clear();
	player2->clear();

	/* Clear Deck */
	/*for (int a = deck.size(); a > 0; a++) {
		delete deck.top();
		deck.pop();
	}*/
	//deck needs its own clear method/destructor

	/* Clear Bank */
	/*for (int i = 0; i < 9; i++) {
		for (int j = bank[i].size(); j > 0; j++) {
			delete bank[i].back();
			bank[i].pop_back();
		}
	}*/
	//now that bank is its own class, we should probably give it
	//a clear function/write a destructor

	if (player1->wins == 2) {
		cout << player1->name << " wins!";
		return true;
	} else if (player2->wins == 2) {
		cout << player2->name << " wins!";
		return true;
	}
	return false;
}

void Game::endGame() {
	player1->clear();
	player2->clear();
	delete player1;
	delete player2;
}
