#ifndef Card_H
#define Card_H

#include <iostream>
#include <string>
using namespace std;


class Card
{
	friend class Deck; ///THIS WILL ALLOW DECK TO ACCESS THE PRIVATE MEMBERS OF THE CARD CLASS.
public:
	Card::Card(){
		names[0] = "ACE";
		names[1] = "TWO";
		names[2] = "THREE";
		names[3] = "FOUR";
		names[4] = "FIVE";
		names[5] = "SIX";
		names[6] = "SEVEN";
		names[7] = "EIGHT";
		names[8] = "NINE";
		names[9] = "TEN";
		names[10] = "JACK";
		names[11] = "QUEEN";
		names[12] = "KING";

			name_S[0] = "Hearts";
			name_S[1] = "Diamonds";
			name_S[2] = "Clubs";
			name_S[3] = "Spades";
	}
	void display(); //DISPLAYS THE RANK AND SUIT OF THE CARD
	int getValue(); //RETURNS THE RANK VALUE OF A CARD 1-ACE, 1 - 9, 10 (JACK, QUEEN, KING)
	void flip(); //FLIPS A CARD. FACEUP BECOME FACE DOWN AND VICE VERSA.
	void setValue(int,int);

private:
	int rank;
	int suit;
	bool isFaceUp;
	string names[13];
	string name_S[4];
};

void Card::display()
{
	
//	cout << rank << " of " << suit << endl;
	for (int i = 0; i < 13; i++)
	{
		if (rank == i+1)
			cout << names[i] << " of ";
	}
	for (int i = 0; i < 4; i++)
	{
		if (suit == i + 1)
			cout << name_S[i] << endl;
	}

}

int Card::getValue()
{
	if (rank >= 10)
		return 10;
	else
	return rank;
}

void Card::flip()
{
	if (isFaceUp == true)
		isFaceUp = false;
	else
		isFaceUp = true;
}

void Card::setValue(int first, int second)
{
	rank = first;
	suit = second;

}


#endif
