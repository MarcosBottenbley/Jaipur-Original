/**
 * Intermediate Programming Final Project
 * David Miller, Syed Hossain, Marcos Bottenbley, Andrew Zhu
 * dmill118@jhu.edi, shossai8@jhu.edu, mbotten1@jhu.edu, azhu8@jhu.edu
 */

#include "Bank.h"
#include <iostream>
#include <iomanip>

using std::stack;
using std::string;
using std::srand;
using std::time;
using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;

Bank::Bank()
{
	initBank();
}

Bank::Bank(int seed)
{
	srand(seed);
	initBank();
}

Bank::~Bank()
{
	for(int x = 0; x < 9; x++) {
		while(!bank[x].empty()) {
			delete bank[x].top();
			bank[x].pop();
		}
	}
}

void Bank::initBank()
{
	Type t;

	int arr1[5] = {5,5,5,7,7};
	t = "Diamond";
	addTokens(arr1,5,t);

	int arr2[5] = {5,5,5,6,6};
	t = "Gold";
	addTokens(arr2,5,t);

	int arr3[5] = {5,5,5,5,5};
	t = "Silver";
	addTokens(arr3,5,t);

	int arr4[7] = {1,1,2,2,3,3,5};
	t = "Cloth";
	addTokens(arr4,7,t);

	t = "Spice";
	addTokens(arr4,7,t);

	int arr6[9] = {1,1,1,1,1,1,2,3,4};
	t = "Leather";
	addTokens(arr6,9,t);

	//BONUS TOKENS
	int arr7[7] = {3,3,2,2,2,1,1};
	t = "Bonus3";
	addTokens(arr7,7,t);

	int arr8[6] = {6,6,5,5,4,4};
	t = "Bonus4";
	addTokens(arr8,6,t);

	int arr9[5] = {10,10,9,8,8};
	t = "Bonus5";
	addTokens(arr9,5,t);
}

void Bank::addTokens(int *arr, int size, Type t)
{
	if(t.isBonus())
		shuffle(arr,size);
		
	for(int x = 0; x < size; x++) {
		bank[t.getEnum()].push(new Token(t.getString(),arr[x]));
	}
}

void Bank::shuffle(int *arr, int size)
{
	int index;
	int index2;
	int temp;
	for(int x = 0; x < 5000; x++) {
		index = rand()%size;
		index2 = rand()%size;
		temp = arr[index];
		arr[index] = arr[index2];
		arr[index2] = temp;
	}
}

stack<Token*> Bank::getTokens(Type::Enum t, int num)
{
	stack<Token*> tokens;

	for(int x = 0; x < num; x++) {
		if(!bank[t].empty()) {
			tokens.push(bank[t].top());
			bank[t].pop();
		}
	}

	if(num == 3 && !bank[Type::BONUS3].empty()) {
		tokens.push(bank[Type::BONUS3].top());
		bank[Type::BONUS3].pop();
	} else if(num == 4 && !bank[Type::BONUS4].empty()) {
		tokens.push(bank[Type::BONUS4].top());
		bank[Type::BONUS4].pop();
	} else if(num >= 5 && !bank[Type::BONUS5].empty()) {
		tokens.push(bank[Type::BONUS5].top());
		bank[Type::BONUS5].pop();
	}

	return tokens;
}

void Bank::printBank() {
	stack<Token*> tempStack;

	cout << "Bank Tokens:" << endl;
	for (int i = 0; i < 6; i++) {
		if (bank[i].size() != 0)
			cout << setw(10) << left << bank[i].top()->getType();
		for (int j = bank[i].size(); j > 0; j--) {	//print a pile of tokens
			tempStack.push(bank[i].top());
			cout << tempStack.top()->getValue() << " ";
			bank[i].pop();
		}
		if (tempStack.size() != 0)
			cout << endl;

		for (int k = tempStack.size(); k > 0; k--) {	//restore bank
			bank[i].push(tempStack.top());
			tempStack.pop();
		}
	}
}



bool Bank::gameOver() {
	int emptyStacks = 0;
	for (int i = 0; i < 6; i++) {
		if (bank[i].empty())
			emptyStacks++;
	}

	if (emptyStacks >= 3)
		return true;
	return false;
}

