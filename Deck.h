#include "Card.h"
#include <algorithm>     /* srand, rand */
#include <time.h>



class Deck {
public:
	Deck::Deck()//CONSTRUCTOR INITIALIZES TOP TO 0 AND POPULTES THE ARRAY OF 52 CARDS
	{
		for (int i = 0; i < 13; i++)
			ranks[i] = i + 1;
		for (int i = 0; i < 4; i++)
			suits[i] = i + 1;
	}
	void populate(); //POPULATES THE DECK WITH THE PLAYING CARDS
	Card deal(); //DEALS A CARD FROM THE TOP OF THE DECK
	void shuffle(); //SHUFFLES THE DECK AND SETS THE TOP TO 0
	void debug();
private:
	Card data[52];  //52 Card objects, each with rank and value
	int top; //THE DECK IS EMPTY WHEN Top IS 52. Top PROVIDES THE ARRAY INDEX OF OF THE TOP CARD IN THE STACK.
	int ranks[13];
	int suits[4];
};

void Deck::shuffle()
{
	populate();
	srand(time(NULL));
	random_shuffle(begin(data), end(data));
    top = 0;
	
	//top = 0 + rand() % 51;
}

void Deck::populate()
{
	int z = 0;
	for (int i = 0; i < 13; i++)                                    //52 cards in total, populate from one to 52
	{
		for (int a = 0; a < 4; a++)
		{
			data[z].setValue(ranks[i], suits[a]);
			z++;
		}
	}
}


Card Deck::deal()
{
	return data[top++];
}

void Deck::debug()
{
	for (int i = 0; i < 52; i++)
	{
		cout << i << ": ";
		data[i].display();
		cout << data[i].getValue() << endl;
	}
}
