#include "Book.h"

Book::Book()
{
	Item();
}

Book::~Book()
{
}

void Book::applyEffect(const Player& i_player)
{
}

void Book::AddSkill(Player& i_player)
{
	i_player.learnSkill();
}
