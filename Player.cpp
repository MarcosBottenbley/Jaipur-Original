/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Player.h"
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <string>

using std::string;
using std::endl;
using std::cerr;
using std::cin;

Player::Player() {
    name = "Player";
    score = 0;
    wins = 0;
}

Player::Player(string pname){
    name = pname;
    score = 0;
    wins = 0;
}

Player::~Player()
{}

void Player:: printStats()
{
    std::cout<< name << "'s Stats" << endl;

    std::cout << "Hand size: " << hand.handSize();
    std::cout << ", Camels: " << hand.herdSize();
    std::cout << ", Score: " << getScore();
    std::cout << ", Wins: " << wins << std::endl;
    hand.printHand();
}

void Player:: clear()
{
    hand.clear();
	score = 0;
}

void Player:: addCard(Card* card)
{
    hand.addCard(card);
}

Hand* Player::getHand() {
	return &hand;
}

void Player:: addPoints(int points)
{
    score+=points;
}

int Player:: getScore()
{
    return score;
}
