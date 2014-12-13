#include "Trade.h"

Trade::Trade(Market &m, Hand &h, bool *pc, bool *mc, int c):
 Move(m,h), camels(c)
{
	pIndexes = getIndexes(pc, 7);
	mIndexes = getIndexes(mc, 5);
}

Trade::~Trade()
{}

int Trade::makeMove()
{
	InvalidMoveEx ime;

	int size = mIndexes.size();
	int size2 = pIndexes.size();

	if(size != size2+camels)
		throw ime;
	else if(size > 5 || size < 2)
		throw ime;

	Card * temp = 0;

	for(int x = size2-1; x >= 0; x--) {
		temp = hand.removeCard(pIndexes[x]);		//remove backmost hand card
		temp = market.swapCard(mIndexes[x+camels], temp);	//put in market and take out market card
		hand.addCard(temp);			//add market card to player's hand

	}

	for(int i = 0; i < camels; i++) {
		temp = hand.getCamel();
		temp = market.swapCard(mIndexes[i], temp);
		hand.addCard(temp);
	}

	return 0;
}
